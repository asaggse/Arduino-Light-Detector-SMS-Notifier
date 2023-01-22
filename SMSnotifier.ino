#include <GSM.h>
#include <Time.h>

// constants and global variables
const char PINNUMBER[] = "";
const int LDR_PIN = 2;
const int LIGHT_THRESHOLD = 300;
const char REMOTE_NUMBER[] = "+1234567890";
const char SMS_MESSAGE[] = "Light detector triggered at ";
unsigned long last_sms_time = 0;

// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("SMS Messages Sender");

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
  setSyncProvider(RTC.get);
}

void loop() {
  int light_level = analogRead(LDR_PIN);
  if (light_level < LIGHT_THRESHOLD && last_sms_time + 300000 < millis() ) {
    last_sms_time = millis();
    char txtMsg[200];
    sprintf(txtMsg, "%s %02d:%02d:%02d on %02d/%02d/%04d", SMS_MESSAGE, hour(), minute(), second(), day(), month(), year());
    Serial.print("SENDING ");
    Serial.println(txtMsg);

    // send the message
    sms.beginSMS(REMOTE_NUMBER);
    sms.print(txtMsg);
    sms.endSMS();
    Serial.println("\nSMS sent successfully!\n");
  }
}

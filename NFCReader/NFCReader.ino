#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

SoftwareSerial zigBeeSerial(2, 3);

String tagId = "None";
byte nuidPICC[4];

void setup(void)
{
  Serial.begin(115200);
  zigBeeSerial.begin(9600);
  
  Serial.println("System initialized");
  nfc.begin();
}

void loop()
{
  readNFC();
}

void readNFC()
{
  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    tag.print();
    tagId = tag.getUidString();
    
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    
    zigBeeSerial.println(tagId);
  }
}

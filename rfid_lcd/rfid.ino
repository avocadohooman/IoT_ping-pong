#include <deprecated.h>
#include <SPI.h> 
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <LiquidCrystal.h>
#define SS_PIN 53
#define RST_PIN 49

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  // put your setup code here, to run once:
  	Serial.begin(115200);
    while (!Serial)
      ;
    Serial.println("Serial works");
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("RFID reading UID");
	// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);
	lcd.clear();
}

String FindName(String uid)
{
	char	buf1[11];
	char	buf2[11];
	String rasmus = "a2 0f 17 e3 ";
	String gary = "82 50 17 e3 ";
	if (uid.equals(rasmus))
		return ("rjaakonm");
	if (uid.equals(gary))
		return ("gmolin");
	return (uid);
}

void loop() {
  // put your main code here, to run repeatedly:
	lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
	if (mfrc522.PICC_IsNewCardPresent())
	{
		if (mfrc522.PICC_ReadCardSerial())
		{
			Serial.println("Tag UID:");
			String myid = "";
			for (byte i = 0; i < mfrc522.uid.size; i++)
			{
				if (mfrc522.uid.uidByte[i] < 0x10)
					myid.concat("0");
				myid.concat(String(mfrc522.uid.uidByte[i], HEX));
				myid.concat(" ");
			}
			Serial.println(FindName(myid));
			lcd.print(FindName(myid)); // Pyrints Sensor Val: to LCD
			mfrc522.PICC_HaltA();
			delay(2000);
			lcd.clear();
		}
	}
}


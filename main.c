#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#define D8 15
#define D3 0
#define D0 16
#define SS_PIN D8  // Define the slave select pin
#define RST_PIN D3
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
void setup() {
  Serial.begin(115200); // Initialize serial communication
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  Serial.println("Scan RFID card...");
  pinMode(D0,OUTPUT);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("GROUP -13");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("connections done!");
  lcd.setCursor(0, 1);
  lcd.print("code is runing:) ");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
   // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
   
    return;
  }

  // Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  for(int i=0;i<2;i++){
  if (content.substring(1) != "XX XX XX XX") {
    Serial.println("Authorized access");
    // Here you can add code for authorized access
    digitalWrite(D0,HIGH); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("rfid card!!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.println(content);
    digitalWrite(D0,LOW);
    
   }
  
  else {
    Serial.println("Access denied");
  }
  }
  delay(1500); // Delay to allow time for reading card

}

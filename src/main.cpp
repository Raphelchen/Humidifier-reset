#include <Arduino.h>
#include <Wire.h>

#define ADDR_Ax 0b001 //A2, A1, A0
#define ADDR (0b1010 << 3) + ADDR_Ax

void writeI2CByte(uint8_t data_addr, uint8_t data);
byte readI2CByte(byte data_addr);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  byte data;
  for(int j = 0; j < 16; j++){
    for(int i = 0; i < 16; i++){
      data = readI2CByte(j*8 + i);
      if (data <= 15){
        Serial.print("0");
      }
      Serial.print(data, HEX);
      i++;
      data = readI2CByte(j*8 + i);
      if (data <= 15){
        Serial.print("0");
      }
      Serial.print(data, HEX);
      if(i == 15){
        break;
      }
      Serial.print(" ");
    }
    Serial.print("\n");
  }

  Wire.endTransmission();
  delay(100);

  if(digitalRead(2) == HIGH){
    Serial.print("Writing Data\n");
    uint8_t* data_to_send = new uint8_t[8];
    for (int i = 0; i < 512; i++){
      data_to_send[i] = 0xFF;
    } 
    data_to_send[0] = 0x40;
    data_to_send[1] = 0x55;
    data_to_send[2] = 0x51;
    data_to_send[3] = 0x01;
    data_to_send[4] = 0x00;
    data_to_send[5] = 0x55;
    data_to_send[6] = 0x14;
    data_to_send[7] = 0x00;

    Wire.beginTransmission(ADDR);
    Wire.write(0x00);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x10;
    data_to_send[1] = 0x00;
    data_to_send[2] = 0x02;
    data_to_send[3] = 0x2A;
    data_to_send[4] = 0x21;
    data_to_send[5] = 0x08;
    data_to_send[6] = 0x2B;
    data_to_send[7] = 0x2C;

    Wire.beginTransmission(ADDR);
    Wire.write(0x08);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x82;
    data_to_send[1] = 0x02;
    data_to_send[2] = 0xA2;
    data_to_send[3] = 0x0A;
    data_to_send[4] = 0x0A;
    data_to_send[5] = 0xAA;
    data_to_send[6] = 0x0A;
    data_to_send[7] = 0x00;
    
    Wire.beginTransmission(ADDR);
    Wire.write(0x10);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x20;
    data_to_send[1] = 0x2A;
    data_to_send[2] = 0x04;
    data_to_send[3] = 0x14;
    data_to_send[4] = 0x41;
    data_to_send[5] = 0x07;
    data_to_send[6] = 0x13;
    data_to_send[7] = 0x11;

    Wire.beginTransmission(ADDR);
    Wire.write(0x18);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x93;
    data_to_send[1] = 0x51;
    data_to_send[2] = 0x96;
    data_to_send[3] = 0x06;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x20);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x28);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x30);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x38);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0x7F;
    data_to_send[5] = 0x51;
    data_to_send[6] = 0x96;
    data_to_send[7] = 0x06;

    Wire.beginTransmission(ADDR);
    Wire.write(0x40);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x65;
    data_to_send[1] = 0x00;
    data_to_send[2] = 0x36;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xE6;
    data_to_send[5] = 0x00;
    data_to_send[6] = 0x38;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x48);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0x29;
    data_to_send[1] = 0x00;
    data_to_send[2] = 0x00;
    data_to_send[3] = 0x00;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x50);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x58);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x60);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x68);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x70);
    Wire.write(data_to_send, 8);
    Wire.endTransmission();

    delay(50);

    data_to_send[0] = 0xFF;
    data_to_send[1] = 0xFF;
    data_to_send[2] = 0xFF;
    data_to_send[3] = 0xFF;
    data_to_send[4] = 0xFF;
    data_to_send[5] = 0xFF;
    data_to_send[6] = 0xFF;
    data_to_send[7] = 0xFF;

    Wire.beginTransmission(ADDR);
    Wire.write(0x78);
    Wire.write(data_to_send, 8);
    uint8_t result = Wire.endTransmission();
    
    Serial.println(result);

    delete(data_to_send);
    delay(100);

    Wire.begin();
    for(int j = 0; j < 16; j++){
      for(int i = 0; i < 16; i++){
        data = readI2CByte(j*8 + i);
        if (data <= 15){
          Serial.print("0");
        }
        Serial.print(data, HEX);
        i++;
        data = readI2CByte(j*8 + i);
        if (data <= 15){
          Serial.print("0");
        }
        Serial.print(data, HEX);
        if(i == 15){
          break;
        }
        Serial.print(" ");
      }
      Serial.print("\n");
    }

    Wire.endTransmission();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

void writeI2CByte(uint8_t data_addr, uint8_t data){
  Wire.beginTransmission(ADDR);
  Wire.write(data_addr);
  Wire.write(data);
  Wire.endTransmission();
}

byte readI2CByte(byte data_addr){
  byte data = NULL;
  Wire.beginTransmission(ADDR);
  Wire.write(data_addr);
  Wire.endTransmission();
  Wire.requestFrom(ADDR, 1); //retrieve 1 returned byte
  delay(1);
  if(Wire.available()){
    data = Wire.read();
  }
  return data;
}
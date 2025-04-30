#include <Arduino.h>
#include <Wire.h>

#define ADDR_Ax 0b001 //A2, A1, A0
#define ADDR (0b1010 << 3) + ADDR_Ax

int set_to_write = 0;

void writeI2CByte(uint8_t data_addr, uint8_t data);
byte readI2CByte(byte data_addr);
void write_dataset_1();
void write_dataset_2();
void write_dataset_3();
void write_dataset_4();


void setup() {
  //start I2C interface
  Wire.begin();
  pinMode(2, OUTPUT);
  delay(200);
  digitalWrite(2,1);
  delay(200);
  digitalWrite(2,0);
  delay(200);
  digitalWrite(2,1);
  delay(200);
  digitalWrite(2,0);
  delay(200);
  digitalWrite(2,1);
  delay(200);
  digitalWrite(2,0);
}

void loop() {
  byte data;
  //wait for connection
  data = readI2CByte(0xF0);
  if(data == 0xFF){
    digitalWrite(2, 1);
    // read current content at 0x44 to determine current set written on chip
    delay(1000);
    data = readI2CByte(0x44);
    if (data == 0x7F){
      set_to_write = 2;
    }else if (data == 0xF8){
      set_to_write = 3;
    }else if (data == 0x02){
      set_to_write = 4;
    }else{
      set_to_write = 1;
    }
    delay(200);
    // write appropriate set
    switch (set_to_write){
    case 1:
      write_dataset_1();
      delay(100);
      write_dataset_1();
      break;
    case 2:
      write_dataset_2();
      delay(100);
      write_dataset_2();
      break;
    case 3:
      write_dataset_3();
      delay(100);
      write_dataset_3();
      break;
    case 4:
      write_dataset_4();
      delay(100);
      write_dataset_4();
      break;

    default:
      write_dataset_1();
      delay(100);
      write_dataset_1();
      break;
    }
    //delay(1000);
    digitalWrite(2, 0);
    delay(10000);
  } else {
    delay(1000);
  }
}

void write_dataset_1(){
  //create variable for the date to be written
  uint8_t *data_to_send = new uint8_t[8];
  //set variable to 1's
  for (int i = 0; i < 8; i++)
  {
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x30);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

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

  Wire.beginTransmission(ADDR);
  Wire.write(0x60);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x68);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x70);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x78);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x80);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x88);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x90);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x98);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA8);
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
  data_to_send[7] = 0x01;

  Wire.beginTransmission(ADDR);
  Wire.write(0xB0);
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
  Wire.write(0xB8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  delete (data_to_send);
  delay(100);
}

void write_dataset_2(){
  //create variable for the date to be written
  uint8_t *data_to_send = new uint8_t[8];
  //set variable to 1's
  for (int i = 0; i < 8; i++)
  {
    data_to_send[i] = 0xFF;
  }

  data_to_send[0] = 0x01;
  data_to_send[1] = 0x02;
  data_to_send[2] = 0x03;
  data_to_send[3] = 0x04;
  data_to_send[4] = 0x4B;
  data_to_send[5] = 0xAC;
  data_to_send[6] = 0x81;
  data_to_send[7] = 0x38;
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xFA;
  data_to_send[1] = 0xD3;
  data_to_send[2] = 0x59;
  data_to_send[3] = 0x7D;
  data_to_send[4] = 0x62;
  data_to_send[5] = 0xB4;
  data_to_send[6] = 0x11;
  data_to_send[7] = 0xA5;
  Wire.beginTransmission(ADDR);
  Wire.write(0x08);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x0A;
  data_to_send[1] = 0x1F;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0xFF;
  data_to_send[5] = 0xFF;
  data_to_send[6] = 0xFF;
  data_to_send[7] = 0xFF;
  Wire.beginTransmission(ADDR);
  Wire.write(0x10);
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
  Wire.write(0x18);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x0B;
  data_to_send[1] = 0xCE;
  data_to_send[2] = 0xE7;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x30);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x38);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xFF;
  data_to_send[1] = 0xFF;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0xF8;
  data_to_send[5] = 0xCD;
  data_to_send[6] = 0xE7;
  data_to_send[7] = 0x06;
  Wire.beginTransmission(ADDR);
  Wire.write(0x40);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x65;
  data_to_send[1] = 0x00;
  data_to_send[2] = 0x27;
  data_to_send[3] = 0x01;
  data_to_send[4] = 0xE9;
  data_to_send[5] = 0x00;
  data_to_send[6] = 0x09;
  data_to_send[7] = 0x01;
  Wire.beginTransmission(ADDR);
  Wire.write(0x48);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x2B;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x60);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x68);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x70);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x78);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x80);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x88);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x90);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x98);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA8);
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
  data_to_send[7] = 0x01;

  Wire.beginTransmission(ADDR);
  Wire.write(0xB0);
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
  Wire.write(0xB8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  delete (data_to_send);
  delay(100);
}

void write_dataset_3(){
  //create variable for the date to be written
  uint8_t *data_to_send = new uint8_t[8];
  //set variable to 1's
  for (int i = 0; i < 8; i++)
  {
    data_to_send[i] = 0xFF;
  }

  data_to_send[0] = 0x01;
  data_to_send[1] = 0x02;
  data_to_send[2] = 0x03;
  data_to_send[3] = 0x04;
  data_to_send[4] = 0x1A;
  data_to_send[5] = 0x1B;
  data_to_send[6] = 0x39;
  data_to_send[7] = 0x82;
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x29;
  data_to_send[1] = 0xD4;
  data_to_send[2] = 0xF5;
  data_to_send[3] = 0x26;
  data_to_send[4] = 0xC5;
  data_to_send[5] = 0x30;
  data_to_send[6] = 0xF6;
  data_to_send[7] = 0xC0;
  Wire.beginTransmission(ADDR);
  Wire.write(0x08);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x09;
  data_to_send[1] = 0xB3;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0xFF;
  data_to_send[5] = 0xFF;
  data_to_send[6] = 0xFF;
  data_to_send[7] = 0xFF;
  Wire.beginTransmission(ADDR);
  Wire.write(0x10);
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
  Wire.write(0x18);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xB8;
  data_to_send[1] = 0x74;
  data_to_send[2] = 0x04;
  data_to_send[3] = 0x2F;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x30);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x38);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xFF;
  data_to_send[1] = 0xFF;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0x02;
  data_to_send[5] = 0x62;
  data_to_send[6] = 0x03;
  data_to_send[7] = 0x07;
  Wire.beginTransmission(ADDR);
  Wire.write(0x40);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x65;
  data_to_send[1] = 0x00;
  data_to_send[2] = 0x16;
  data_to_send[3] = 0x01;
  data_to_send[4] = 0xE4;
  data_to_send[5] = 0x00;
  data_to_send[6] = 0x02;
  data_to_send[7] = 0x01;
  Wire.beginTransmission(ADDR);
  Wire.write(0x48);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x2A;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x60);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x68);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x70);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x78);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x80);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x88);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x90);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x98);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA8);
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
  data_to_send[7] = 0x01;

  Wire.beginTransmission(ADDR);
  Wire.write(0xB0);
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
  Wire.write(0xB8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  delete (data_to_send);
  delay(100);
}

void write_dataset_4(){
  //create variable for the date to be written
  uint8_t *data_to_send = new uint8_t[8];
  //set variable to 1's
  for (int i = 0; i < 8; i++)
  {
    data_to_send[i] = 0xFF;
  }

  data_to_send[0] = 0x01;
  data_to_send[1] = 0x02;
  data_to_send[2] = 0x03;
  data_to_send[3] = 0x04;
  data_to_send[4] = 0x4B;
  data_to_send[5] = 0xAC;
  data_to_send[6] = 0x81;
  data_to_send[7] = 0x38;
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xDA;
  data_to_send[1] = 0x8B;
  data_to_send[2] = 0x6D;
  data_to_send[3] = 0x87;
  data_to_send[4] = 0x62;
  data_to_send[5] = 0xB4;
  data_to_send[6] = 0x11;
  data_to_send[7] = 0x8B;
  Wire.beginTransmission(ADDR);
  Wire.write(0x08);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x0E;
  data_to_send[1] = 0xBB;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0xFF;
  data_to_send[5] = 0xFF;
  data_to_send[6] = 0xFF;
  data_to_send[7] = 0xFF;
  Wire.beginTransmission(ADDR);
  Wire.write(0x10);
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
  Wire.write(0x18);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xFF;
  data_to_send[1] = 0x76;
  data_to_send[2] = 0x04;
  data_to_send[3] = 0x2F;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x30);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x38);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0xFF;
  data_to_send[1] = 0xFF;
  data_to_send[2] = 0xFF;
  data_to_send[3] = 0xFF;
  data_to_send[4] = 0x09;
  data_to_send[5] = 0x2A;
  data_to_send[6] = 0xD8;
  data_to_send[7] = 0x06;
  Wire.beginTransmission(ADDR);
  Wire.write(0x40);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x65;
  data_to_send[1] = 0x00;
  data_to_send[2] = 0x29;
  data_to_send[3] = 0x01;
  data_to_send[4] = 0xE5;
  data_to_send[5] = 0x00;
  data_to_send[6] = 0x10;
  data_to_send[7] = 0x01;
  Wire.beginTransmission(ADDR);
  Wire.write(0x48);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  data_to_send[0] = 0x2A;
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

  Wire.beginTransmission(ADDR);
  Wire.write(0x60);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x68);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x70);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x78);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x80);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x88);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x90);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0x98);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xA8);
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
  data_to_send[7] = 0x01;
  Wire.beginTransmission(ADDR);
  Wire.write(0xB0);
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
  Wire.write(0xB8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xC8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xD8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xE8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF0);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(ADDR);
  Wire.write(0xF8);
  Wire.write(data_to_send, 8);
  Wire.endTransmission();
  delay(50);

  delete (data_to_send);
  delay(100);
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
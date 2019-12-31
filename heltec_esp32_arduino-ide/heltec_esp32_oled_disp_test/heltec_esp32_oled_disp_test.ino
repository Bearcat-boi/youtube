// Copyright 2019 Edward Lynch.
// Licensed under the MIT License.

#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

const uint8_t stripe[] = {
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001
};

void setup() {
  u8g2.begin();
  u8g2_set_default_settings();
  u8g2.drawStr(0, 0, "setup complete");
  u8g2.sendBuffer();
  delay(1000);
}

void loop() {

  //draw splash screen
  u8g2.clearBuffer();
  for (int indx = 0; indx < 128; indx += 8) {
    for (int indy = 0; indy < 64; indy += 8) {
      u8g2.drawBitmap( indx, indy, 1, 8, stripe); //tile bitmap
    }
    u8g2.sendBuffer();
    delay(10);
  }
  u8g2.drawBox(10, 10, 108, 44);
  u8g2.sendBuffer();
  delay(10);
  u8g2.setFont(u8g2_font_9x18B_mf); // fairly small font
  u8g2.setDrawColor(0); //inverted
  const char str_doing[]   = "Doing";
  const char str_science[] = "Science";
  u8g2.drawStr(((128 - ((sizeof(str_doing) - 1) * 9)) / 2), 13, str_doing);
  u8g2.drawStr(((128 - ((sizeof(str_science) - 1) * 9)) / 2), 33, str_science);
  u8g2.sendBuffer();
  u8g2_set_default_settings();
  delay(2000);

  //draw random circles
  u8g2.clearBuffer();
  for (int ind = 0; ind < 20; ind++) {
    unsigned char x0  = random(127);
    unsigned char y0  = random(63);
    unsigned char rad = random(5, 24);
    u8g2.drawCircle(x0, y0, rad);
    u8g2.sendBuffer();
    delay(100);
  }

  //draw random rectangles
  u8g2.clearBuffer();
  for (int ind = 0; ind < 20; ind++) {
    unsigned char x = random(127);
    unsigned char y = random(63);
    unsigned char w = random(5, 24);
    unsigned char h = random(5, 24);
    u8g2.drawFrame(x, y, w, h);
    u8g2.sendBuffer();
    delay(100);
  }

  //draw random triangles
  u8g2.clearBuffer();
  for (int ind = 0; ind < 20; ind++) {
    unsigned char x0 = random(20, 127 - 20);
    unsigned char y0 = random(20, 63 - 20);
    unsigned char x1 = random(x0 - 20, x0 + 20);
    unsigned char y1 = random(y0 - 20, y0 + 20);
    unsigned char x2 = random(x0 - 20, x0 + 20);
    unsigned char y2 = random(y0 - 20, y0 + 20);
    u8g2.drawLine(x0, y0, x1, y1);
    u8g2.drawLine(x1, y1, x2, y2);
    u8g2.drawLine(x0, y0, x2, y2);
    u8g2.sendBuffer();
    delay(100);
  }

  //draw random pixels
  u8g2.clearBuffer();
  for (int ind1 = 0; ind1 < 20; ind1++) {
    for (int ind2 = 0; ind2 < 64; ind2++) {
      unsigned char x = random(127);
      unsigned char y = random(63);
      u8g2.drawPixel(x, y);
    }
    u8g2.sendBuffer();
    delay(10);
  }
}

void u8g2_set_default_settings() {
  u8g2.setFont(u8g2_font_6x12_mf); // fairly small font
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1); // normal, not inverted
  u8g2.setFontPosTop(); // x,y is at top of font
  u8g2.setFontDirection(0); // not rotated
}

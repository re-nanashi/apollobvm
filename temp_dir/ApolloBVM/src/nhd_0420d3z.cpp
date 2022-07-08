#include "Arduino.h"
#include "nhd_0420d3z.h"


NhdDisplay::NhdDisplay(byte pin):
  _row(0),
  _col(0) {
  _serial_ptr = new LiquidCrystal_I2C(pin, 20, 4);
}

void NhdDisplay::begin(int baud) {
  // Init Serial connection. 
  _serial_ptr->init();
  _serial_ptr->backlight();
}

void NhdDisplay::print(String st) {
  _serial_ptr->print(st);
}

void NhdDisplay::print(int val) {
  _serial_ptr->print(String(val));
}

// Not Needed
void NhdDisplay::println(String st) {
  //_serial_ptr->println(st);
}

// Not Needed
void NhdDisplay::setBacklight(byte brightness) {
}

void NhdDisplay::clearDisplay() {
  // Send command to clear screen.
  _serial_ptr->clear();
}

void NhdDisplay::setCursor(byte cursor_position, byte line) {
  // Send command to move cursor_position.
  _serial_ptr->setCursor(cursor_position, line);
}

void NhdDisplay::underlineOn() {
  // Send command to turn underline on.
  _serial_ptr->cursor();
}

void NhdDisplay::underlineOff() {
  // Send command to turn underline off.
  _serial_ptr->noCursor();
}

void NhdDisplay::blinkingOn() {
  // Send command to turn blinking on.
  _serial_ptr->blink();
}

void NhdDisplay::blinkingOff() {
  // Send command to turn blinking off.
  _serial_ptr->noBlink();
}

// Not Needed
void NhdDisplay::moveCursorRight() {
}

// Not Needed
void NhdDisplay::moveCursorLeft() {
}

//!!!NOTE: PROBLEM
// How to backspace?
// Not needed
void NhdDisplay::backspace() {
}

void NhdDisplay::remove() {
    _serial_ptr->print(" ");
}

String NhdDisplay::zeroPad(int in) {
  // This helper function ensures integers have 2 decimal places.
  
  // Make a temp char array to hold the 2 digits.
  char digit[2];

  // Pad with a 0 if integer is 1 digit.
  sprintf(digit, "%02d", in);

  return String(digit);
}

#include <Arduino.h>
#include <DipSwitch.h>
#include <ToggleButton.h>
#include <ShiftRegister.h>
#include <SevenSegment.h>

DipSwitch byteInput;
ToggleButton hexToggle;
ShiftRegister displayRegister;
SevenSegment twoDigitDisplay;

bool hexMode = true;

void setup()
{
  Serial.begin(9600);

  byteInput.init();
  hexToggle.init();
  displayRegister.init();
}

void loop()
{
  hexMode = hexToggle.toggle_read();
  Serial.println(byteInput.read_byte());

  if (hexMode) {
    displayRegister.write_word(twoDigitDisplay.get_hex(byteInput.read_byte()));
  } else {
    displayRegister.write_word(twoDigitDisplay.get_number(byteInput.read_byte()));
  }
}
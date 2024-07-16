const int DIN_PIN = 3;
const int CLK_PIN = 9;
const int CS_PIN = 46;

// MAX7219 registers
#define MAX7219_REG_NOOP        0x00
#define MAX7219_REG_DIGIT0      0x01
#define MAX7219_REG_DIGIT1      0x02
#define MAX7219_REG_DIGIT2      0x03
#define MAX7219_REG_DIGIT3      0x04
#define MAX7219_REG_DIGIT4      0x05
#define MAX7219_REG_DIGIT5      0x06
#define MAX7219_REG_DIGIT6      0x07
#define MAX7219_REG_DIGIT7      0x08
#define MAX7219_REG_DECODEMODE  0x09
#define MAX7219_REG_INTENSITY   0x0A
#define MAX7219_REG_SCANLIMIT   0x0B
#define MAX7219_REG_SHUTDOWN    0x0C
#define MAX7219_REG_DISPLAYTEST 0x0F

void sendCommand(byte reg, byte data) {
  digitalWrite(CS_PIN, LOW);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, reg);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, data);
  digitalWrite(CS_PIN, HIGH);
}

void setup() {
  // Set pin modes
  pinMode(DIN_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);

  // Initialize the MAX7219
  digitalWrite(CS_PIN, HIGH);
  sendCommand(MAX7219_REG_SHUTDOWN, 0x01);      // Wake up from shutdown mode
  sendCommand(MAX7219_REG_SCANLIMIT, 0x07);     // Set scan limit to 8 digits
  sendCommand(MAX7219_REG_DECODEMODE, 0x00);    // No decode mode for LED matrix
  sendCommand(MAX7219_REG_INTENSITY, 0x08);     // Set brightness level (0-15)
  sendCommand(MAX7219_REG_DISPLAYTEST, 0x00);   // Disable display test
  clearDisplay();
}

void loop() {
  // Cycle through mouth patterns
  displaySmile();
  delay(500);
  displayNatural();
  delay(500);
  displaySad();
  delay(500);
  displayNatural();
  delay(500);
  displaySad();
  delay(500);
  displayNatural();
  delay(500);
  displaySad();
  delay(500);
  displayNatural();
  delay(500);
  displaySad();
  delay(500);
  displaySmile();
  delay(500);
};


void clearDisplay() {
  for (int i = 0; i < 8; i++) {
    sendCommand(MAX7219_REG_DIGIT0 + i, 0x00);
  }
}

void displayPattern(byte pattern[8]) {
  for (int i = 0; i < 8; i++) {
    sendCommand(MAX7219_REG_DIGIT0 + i, pattern[i]);
  }
}

void displaySmile() {
  byte smile[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000001, // Top part of the smile
    0b10000001, // Middle part of the smile
    0b01000010, // Lower part of the smile
    0b00111100, // Bottom part of the smile
    0b00000000
  };
  displayPattern(smile);
}

void displaySad() {
  byte Sad[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000, // Top part of the smile
    0b11111111, // Middle part of the smile
    0b01111110, // Lower part of the smile
    0b00000000, // Bottom part of the smile
    0b00000000
  };
  displayPattern(Sad);
}
void displayNatural() {
  byte Natural[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100, // Top part of the smile
    0b11000011, // Middle part of the smile
    0b01000010, // Lower part of the smile
    0b00111100, // Bottom part of the smile
    0b00000000
  };
  displayPattern(Natural);
}

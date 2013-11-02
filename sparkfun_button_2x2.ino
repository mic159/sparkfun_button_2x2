/* Sparkfun Button Pad 2x2 code.
 *
 * It lights up the buttons when you press them.
 *
 * Required Library:
 * Keypad - https://github.com/Nullkraft/Keypad.git
 *
 * For wiring and more information see the README.md
 */
#include <Keypad.h>

#define _R 4
#define _G 7
#define _B 8

#define L1 3
#define L2 5
#define L3 6
#define L4 9

struct Color {
  Color(): red(0), green(0), blue(0) {}
  Color(byte r, byte g, byte b): red(r), green(g), blue(b) {}
  byte red;
  byte green;
  byte blue;
};

const uint8_t ROWS=1;
const uint8_t COLS=4;
char keys[ROWS][COLS] = {{1, 2, 3, 4}};
byte rowPins[ROWS] = {A0};
byte colPins[COLS] = {A1, A2, A3, A4};

Color led[4];
uint8_t button_state[4] = {0,0,0,0};
Keypad buttons = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Color color_states[] = {
  Color(0  , 0  , 0  ),
  Color(255, 0  , 0  ),
  Color(0  , 255, 0  ),
  Color(0  , 0  , 255),
  Color(255, 255, 0  ),
  Color(0  , 255, 255),
  Color(0  , 255, 255),
};
uint8_t num_color_states = sizeof(color_states) / sizeof(color_states[0]);

void setup() {
  pinMode(_R, OUTPUT);
  pinMode(_G, OUTPUT);
  pinMode(_B, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++)
    writeLeds();
  readButtons();
}

void readButtons() {
  char key = buttons.getKey();
  if (key && key <= 4) {
    button_state[key-1] = (button_state[key-1] + 1) % num_color_states;
    led[key-1] = color_states[button_state[key-1]];
  }
}

void writeLeds() {
  digitalWrite(_R, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_B, LOW);
  analogWrite(L1, 255-led[0].red);
  analogWrite(L2, 255-led[1].red);
  analogWrite(L3, 255-led[2].red);
  analogWrite(L4, 255-led[3].red);
  digitalWrite(_R, HIGH);
  // reds are on now, wait a bit
  delayMicroseconds(300);
  digitalWrite(_R, LOW);
  analogWrite(L1, 255-led[0].green);
  analogWrite(L2, 255-led[1].green);
  analogWrite(L3, 255-led[2].green);
  analogWrite(L4, 255-led[3].green);
  digitalWrite(_G, HIGH);
  // green are on now, wait a bit
  delayMicroseconds(300);
  digitalWrite(_G, LOW);
  analogWrite(L1, 255-led[0].blue);
  analogWrite(L2, 255-led[1].blue);
  analogWrite(L3, 255-led[2].blue);
  analogWrite(L4, 255-led[3].blue);
  digitalWrite(_B, HIGH);
  // blue are on now, wait a bit
  delayMicroseconds(300);
  digitalWrite(_B, LOW);
}

Sparkfun Button Pad 2x2
=======================

This is sample code to drive the Sparkfun Button Pad 2x2 from an Arduino.

It lights up the LEDs different colors each time you press it.

Hardware
========

You will need:
 - Button Pad
   - Button Pad 2x2 (silicone pad): [Sparkfun](https://www.sparkfun.com/products/7836) || [Little Bird](http://littlebirdelectronics.com/products/button-pad-2x2-led-compatible)
   - Button Pad 2x2 PDB: [Sparkfun](https://www.sparkfun.com/products/9277) || [Little Bird](http://littlebirdelectronics.com/products/button-pad-2x2-breakout-pcb)
   - RGB LEDs (Common Cathode): [Sparkfun](https://www.sparkfun.com/products/9853) || [Little Bird](http://littlebirdelectronics.com/products/5mm-triple-output-led-rgb-common-cathode-20-pcs-pack)
   - Diodes 1N4148: [DX](http://dx.com/p/in4004-1n4148-bat85-schottky-signal-diodes-3-x-20-pcs-152549)
   - Top bezel: [Sparkfun](https://www.sparkfun.com/products/8746) || [Little Bird](http://littlebirdelectronics.com/products/button-pad-2x2-top-bezel)
   - Right angle pin headers: [Little Bird](http://littlebirdelectronics.com/products/break-away-headers-right-angle)
 - On the breadboard
   - 100 Ohm Resistors x4: [DX](http://dx.com/p/diy-1-4w-resistance-metal-film-resistors-2500-pcs-152924)
   - Arduino (I used a Nano): [DX](http://dx.com/p/arduino-nano-v3-0-81877)
 - Wires: [DX](http://dx.com/p/arduino-dupont-4-pin-male-to-female-extension-wire-cable-40cm-10-piece-pack-140523)
   - What you get for this depends on your use case, but I used these to plug into my breadboard.

Theory
======

To drive the LEDs we are going to use PWM/AnalogWrite to drive the common pin on each LED, then cycle through each color one at a time.
You need to put the resistors where it will not be supplying current for more than one LED at a time, so we put it on the common pins of each LED.


For reading the buttons, I used the [Keypad](https://github.com/Nullkraft/Keypad.git) library. It handles all the debouncing and pin IO for you, which is handy.

Wiring
======

| PCB Label     | Arduino Pin |
| ------------- | ----------- |
| SWITCH        | A0          |
| SWT-GND1      | A1          |
| SWT-GND2      | A2          |
| SWT-GND3      | A3          |
| SWT-GND4      | A4          |
| LED-GND1      |  3          |
| LED-GND2      |  5          |
| LED-GND3      |  6          |
| LED-GND4      |  9          |
| RED           |  4          |
| GREEN         |  7          |
| BLUE          |  8          |

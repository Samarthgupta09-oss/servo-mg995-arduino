servo-mg995-arduino
A small Arduino/PlatformIO project that sweeps an MG995 servo back and forth and prints the angle over Serial. This README covers using CLion, IDE version recommendations, build/run steps, libraries, dependencies, connected components (including an OLED note), author, and software/hardware requirements.

Quick checklist
Project root: platformio.ini
Main code: src/main.cpp
Libraries: PlatformIO-managed + Arduino built-ins (see Libraries section)
Using CLion
Install CLion (see "Version of IDE" below).
Install the PlatformIO plugin for CLion (or use the PlatformIO Core CLI from a terminal).
Open the project folder (servo-mg995-arduino) in CLion.
Use the PlatformIO configuration in platformio.ini to build and upload.
Version of IDE
Recommended: CLion 2021.3 or newer.
Ensure the PlatformIO plugin (or PlatformIO Core/CLI) is installed and updated.
Code
Main file: src/main.cpp — contains the servo sweep loop and Serial debugging prints.
Behavior: sweeps servo from 0 to 170 (by 10) then down to 0; delays for 500 ms between steps.
Libraries
Uses the Arduino built-in Servo library (included in many Arduino cores).
If using PlatformIO, add any library dependencies to platformio.ini or install via the PlatformIO Library Manager.
Dependencies
PlatformIO (recommended) — used to build and upload sketches without the Arduino IDE.
Board-specific Arduino core (configured in platformio.ini).
No extra external libraries are required for the provided code beyond Servo (part of the core in most platforms).
Components (hardware)
MG995 Servo Motor (or compatible metal-geared servo)
Operating voltage: typically 4.8–6.6 V. Check the datasheet for stall current and torque.
Use a separate power supply for the servo when possible (see Wiring & Power notes).
Microcontroller board (e.g., Arduino Uno, Nano, or an ESP32/ESP8266 depending on platformio.ini).
Optional: OLED display (e.g., SSD1306 128x64 I2C) — not required by the provided code but commonly used in the project family.
If you add an OLED: install the Adafruit SSD1306 and Adafruit GFX libraries (or equivalent) and wire via I2C (SDA/SCL).
Wiring & power notes
MG995 pins: GND, VCC (V+), Signal
Connect signal to the pin defined in src/main.cpp (currently D10).
Connect grounds: microcontroller GND and servo power supply GND must be common.
DO NOT power the servo from the microcontroller 5V regulator if the servo will draw high current — use a dedicated 5–6V supply with sufficient current capacity (2A+ recommended for MG995 under load).
OLED (if used): connect SDA to microcontroller SDA, SCL to SCL, VCC to 3.3V/5V depending on module, and GND to common ground.
Build & upload (PlatformIO CLI)
Build the project:
platformio run
Upload to the default configured board:
platformio run --target upload
Monitor Serial (set baud to 9600 as in src/main.cpp):
platformio device monitor --baud 9600
If you prefer CLion with PlatformIO integration, use the plugin UI to run these tasks.

Troubleshooting
Servo jitter or unexpected movement: check power supply (insufficient current), decoupling capacitors, and common ground.
Servo not moving: verify signal pin (D10) matches wiring and myServo.attach(10).
Upload failures: confirm board selection in platformio.ini, check USB cable, and ensure no other program holds the serial port.
Author
Author: Your Name (replace with your real name or handle)
Software & Hardware Requirements
Software:
CLion 2021.3+ (optional) or PlatformIO Core (pio) CLI
PlatformIO plugin for CLion (optional)
Python 3.x (required by PlatformIO Core)
Hardware:
Microcontroller board supported by PlatformIO (e.g., Arduino Uno/Nano/Pro Micro, ESP32)
MG995 servo motor
Power supply capable of providing stable 5–6V at sufficient current (2A+ recommended)
Wiring/jumper cables, breadboard (optional)
Optional: SSD1306 I2C OLED module
Notes & next steps
If you'd like, I can add an example OLED integration (displaying the current angle) and update src/main.cpp and platformio.ini with the required library entries and wiring instructions.
This README was generated automatically. Edit the Author and any board-specific settings in platformio.ini to match your hardware.

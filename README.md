# Robot-Mouth-Using-LED-Matrix
This project demonstrates how to simulate a robot mouth on an 8x8 LED matrix controlled by a MAX7219 driver using an ESP32-S3. The code includes functions to display different mouth patterns: smiling, natural, and sad, cycling between them.

**Components**
- LED Matrix 8x8
- ESP32-S3

**Patterns**

- Smiling Mouth Pattern

Hex Code: 0x00, 0x00, 0x00, 0x81, 0x81, 0x42, 0x3C, 0x00

Represents a smiling mouth on the LED matrix.


- Sad Mouth Pattern

Hex Code: 0x00, 0x00, 0x00, 0x00, 0xFF, 0x7E, 0x00, 0x00

Represents a sad mouth on the LED matrix.


- Natural Mouth Pattern

Hex Code: 0x00, 0x00, 0x00, 0x3C, 0xC3, 0x42, 0x3C, 0x00

Represents a neutral mouth on the LED matrix.


![image](https://github.com/user-attachments/assets/0d7814b0-ceb1-4e61-a441-d9f7c0e889c3)

![image](https://github.com/user-attachments/assets/87e938bd-6549-40ab-9d04-b64e72ceedfa)

![image](https://github.com/user-attachments/assets/3ed8ee5f-d3c1-44fb-b755-b5ec957ae42b)


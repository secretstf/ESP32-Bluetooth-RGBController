# ESP32-Bluetooth-RGBController
Project Exploration -- App to control the colour of an RGB LED







## Day-to-Day Documentation
### Day 1
I spent most of the day today working on how to use the Arduino IDE to work with the ESP32. (*My main goal was to complete something similar to this [Arduino RGB LED Tutorial](https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e)*).

The circuit didn't take too long. I followed the images on the tutorial, but my pinouts were:
- Red Pin -- D0
- Green Pin -- D1
- Blue Pin -- D2

Figuring out how to actually setup the Arduino IDE to connect and send instructions to the ESP32 was the difficult part. First, I followed what the manafacturer (hiLetGo) of implemented microcontroller suggested for about an hour. But, the setup seemed very vague, so ... I went to Google to find an easier way 👍.

Eventually, I stumbled upon [this](https://arduino-esp8266.readthedocs.io/en/latest/installing.html) and OMG it was so much simpler. I followed the instructions they listed at the top but changed some of the default values to match the manafacturer's implementation ([found here](https://hiletgo.com/ProductDetail/1906570.html)).
- Changes
    - Board &rarr; NodeMCU 1.0 (ESP-12E Module)
    - CPU Frequency &rarr; 80 MHz
    - Upload Speed &rarr; 921600
    - Port &rarr; COM9 (varies from computer to computer)

Once that was done and I got the blink sample to work, I finally could finish the Arduino tutorial, but I wanted to try my own way from here. I implemented the [RGB Cycler]() that, as the name implies, cycles the colours of the RGB LED from ⚪&rarr;🔴&rarr;⚪&rarr;🟢&rarr;⚪&rarr;🔵.

To make it easier for me to reference back to the basics in the future and to record my progress, I made this GitHub 😀.

From here, my next objective to control the colour of the LED using a user input.

**Today, I learned how to write the readme.MD, setup the ESP32 for coding using ArduinoIDE, and reviewed some Arduino coding.**

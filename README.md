# ESP32-Bluetooth-RGBController
Project Exploration -- App to control the colour of an RGB LED

*The project will be updated to include comments and images to help replication in the future*

Projects:
1. [RGB Cycler](/RGB_Cycler)<br />An arduino code file that helps cycle through the three main colours (red, green, blue) starting at zero brightness to full brightness. 
2. [RGB Setter](/RGB_Setter)<br />An arduino code file that lets the user set the colour for the RBG LED using RGB or Hex colour code
3. [Bluetooth Test Code](/FirstBluetoothTest)<br /> A sample code that setups bluetooth for the ESP32 microcontroller and prints out the output from the serial monitor on another bluetooth device (primarily my phone)


## Objectives
- [x] Setup ESP32 💻 for coding
- [x] Control RGB LED using ESP32 
- [x] Control LED using user input ⌨️
- [x] Setup ESP32 bluetooth
- [ ] Develop simple controller app for Android and *maybe* iPhone 📱
- [ ] Make connection between phone and ESP32
- [ ] Use color wheel input from phone to change the colour of the LED connected to the ESP32



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

Once that was done and I got the blink sample to work, I finally could finish the Arduino tutorial, but I wanted to try my own way from here. I implemented the [RGB Cycler](/RGB_Cycler) that, as the name implies, cycles the colours of the RGB LED from ⚪&rarr;🔴&rarr;⚪&rarr;🟢&rarr;⚪&rarr;🔵.

To make it easier for me to reference back to the basics in the future and to record my progress, I made this GitHub repository 😀.

From here, my next objective to control the colour of the LED using a user input.

**Today, I learned how to write the readme.MD, setup the ESP32 for coding using ArduinoIDE, and reviewed some Arduino coding.**
### Day 2
It's been awhile! Now that I am more free, back to the project 😁.

I spent some time trying to better my RGB cycler. Obviously most people don't want to just have one set pattern or colour. So, I propose a temporary/partial solution, a RGB setter!!

One clarification is that my setup is the same from Day 1 (I was too lazy to remove it from the breadboard 😅). And another key note is that Google is **AMAZING**.

Seeing as there were several key steps, I've subdivided each step for easier access later on.

**Setting RGB colour:**
 Using the code from [RGB Cycler](/RGB_Cycler), I made code to allow me to set the specific colours by manually adjusting RGB. Using the wisdom from my various coding teachers and experiences, I put it in a nice function for later use.

**User Input:**
 Getting input from user was not hard. The hard part was getting a constant input so I wouldn't have to reset the system each time I wanted a new colour. After googling a bit, I found that you could user Serial.available in a while loop to stall for a new input from the user. I used this to establish three stalls, one for each colour. 

**Hex Colour Addition:** 
Now, I can input RGB, but I may want to allow for hex colour selection for the weird (just kidding 🤥) users. To begin with the process, I added another input from the user to select between setting a hex or RGB colour. Luckily getting a hex input is only one input, so only one input from user needed. But, it is SO SO much harder to implement it for the RGB LED. I found a way to convert hexadecimal inputs into integers (ex. "10" &rarr; 16) using strtol. 

> "Trust the user to always mess something up" -*HS Computer Science Teacher*

**Input Validation:** 
Taking inspiration from the above quote, I decided to take some precautions. 

Order of business
1. rgbSetter can only set valid values ✅ 
2. Hex Colour input is actually valid before trying to convert it ✅

🎉 That wraps up the [RGB Setter](/RGB_Setter) project 🎉

I had some more time to kill, so I decided to tackle the bluetooth portion of the project. I found a cool library (BluetoothSerial) that helped ease the use of bluetooth on the ESP32. In addition, I found some sample code associated with the library. I used it, but forgot that I actually needed a way to see the serial on another bluetooth device. This was solved by [Bluetooth Serial](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en_US&gl=US) app (on the superior Android OS😜). I wish I could credit the original article authour 😢 but TYSM to Evandro Copercini for creating the code sample. I've uploaded the [test code](/FirstBluetoothTest) in this repository also for future reference.

Okay, now for a small rant, WTH is up with the RGB LED!!!!!! It's so difficult to get a good colour on it. I couldn't notice one difference between displaying UNC Blue ![#4b9cd3](/Images/UNC_Blue.png) and light blue ![#add8e6](/Images/Light_Blue.png). What's worse is that I couldn't find a good solution to my issue 😡. Anyways, I'll try to find the solution later.

From here, my next objective is to control the LED using the serial input on my phone.

**Today, I learned how to activate the bluetooth feature on the ESP32, set the RGB colour for the LED, and how difficult it is to show accurate true to life colour on an RGB LED.**

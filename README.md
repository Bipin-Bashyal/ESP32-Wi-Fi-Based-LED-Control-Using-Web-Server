# ESP32-Wi-Fi-Based-LED-Control-Using-Web-Server
Development Timeline (Dev Log)
Day 1 – Planning & Research

Decided to use ESP32 instead of Arduino because it has built-in Wi-Fi

Studied how ESP32 can act as a web server

Learned about:

1.WiFi.h

2.HTTP requests

3.WiFiServer and WiFiClient

Day 2 – Hardware Setup

1.Connected an external LED to the ESP32

Used:

1.GPIO pin 4

2.Current-limiting resistor

3.Verified LED works using a simple digitalWrite() test sketch

Day 3 – Wi-Fi Connection

1.Wrote code to connect ESP32 to a Wi-Fi network

2.Printed IP address on Serial Monitor

3.Confirmed ESP32 connects successfully

Challenges faced:

1.Incorrect Wi-Fi password caused connection failure

2.Fixed by double-checking SSID and password

Day 4 – Web Server & LED Control

1.Created an HTTP server on port 80

Parsed browser requests like:

1./LED=ON

2./LED=OFF

3.Controlled LED state using HTTP URLs

4.Designed a simple HTML page with buttons

Day 5 – Testing & Debugging

Tested on:

1.Laptop browser

2.Mobile browser

Verified:

1. Real-time LED response

2. Stable Wi-Fi connection

3. Cleaned up Serial output

4. Recorded a working demo video

How the Project Works

1. ESP32 connects to Wi-Fi

2. ESP32 starts a web server

3. User enters ESP32 IP address in browser

4. Buttons send HTTP requests

5. ESP32 reads the request

6. LED turns ON or OFF accordingly

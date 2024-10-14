# Set up steps for HiLetgo ESP8266 NodeMCU CP2102 ESP-12E Development Board:

1. **Download the Arduino IDE**: Get the latest version from the official Arduino website.
2. **Install the IDE**: Follow the installation steps on your operating system.
3. **Set up your Arduino IDE**:
    - Go to `File -> Preferences` and copy the URL below to get the ESP board manager extensions:  
      `https://arduino.esp8266.com/stable/package_esp8266com_index.json`
4. **Install the ESP8266 board**:
    - Go to `Tools -> Board -> Board Manager`, then type "esp8266", download the Community ESP8266 package, and install it.
5. **Set up your chip configuration**:
    - Go to `Tools -> Board -> NodeMCU 1.0 (ESP-12E Module)`
    - Set other options:  
      - `Tools -> Flash Size -> 4M (3M SPIFFS)`  
      - `Tools -> CPU Frequency -> 80 Mhz`  
      - `Tools -> Upload Speed -> 921600`  
      - `Tools -> Port -> (select the appropriate port)`

# Connect to the ESP8266 webserver
1. Download & Run the provided example on your development board
2. Open your devices Wi-Fi settings and look for the ssid
    - `ESP8266_SoftAP` used in the example
3. Connect using the password
    - `12345678` used in the example
4. Visit `192.168.4.1` through a web browser, or make GET/POST requests directly

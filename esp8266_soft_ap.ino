#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESP8266_SoftAP";
const char *password = "12345678";

ESP8266WebServer server(80); // Create a web server on port 80

// Handles HTTP GET requests to '/'
void handleGetRoot() {
  Serial.println("GET Request recieved!");

  String message = "<h1>Hello from ESP8266!</h1>";
  message += "<form action=\"/\" method=\"POST\">";
  message += "<input type=\"text\" name=\"name\" value=\"Mason\">";
  message += "<button type=\"submit\">Submit</button>";
  message += "</form>";

  server.send(200, "text/html", message);
}

// Handles HTTP post requests to '/'
void handlePostRoot() {
  String message = "<h1>POST data received</h1>";

  if (!server.hasArg("name")) {
    // Headers do not contain expected info
    server.send(400);
  }

  String name = server.arg("name");
  message += "<p>Hello, " + name + "!</p>";
  Serial.println("Hello " +name);

  // Send the response to the client
  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(921600);

  // Set up the Soft AP
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Define routes for various HTTP requests
  server.on("/", HTTP_GET, handleGetRoot);
  server.on("/", HTTP_POST, handlePostRoot);

  // Start the server
  server.begin();
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}

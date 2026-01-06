#include <WiFi.h>

const char* ssid = "Elido Technology 4G";
const char* password = "CLB439AD81";

const int ledPin = 4;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Client connected");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Control LED based on request
    if (request.indexOf("/LED=OFF") != -1) {
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("/LED=ON") != -1) {
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<html><body style='text-align:center;'>");
    client.println("<h2>ESP32 External LED Control</h2>");
    client.println("<a href=\"/LED=ON\"><button style='font-size:30px;'>Turn OFF</button></a>");
    client.println("&nbsp;");
    client.println("<a href=\"/LED=OFF\"><button style='font-size:30px;'>Turn ON</button></a>");
    client.println("</body></html>");

    client.stop();
    Serial.println("Client disconnected");
  }
}

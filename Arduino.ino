#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

// Informations de connexion Wi-Fi
const char* ssid = "PoleDeVinci_IFT";
const char* password = "*c.r4UV@VfPn_0";

// Démarrer le serveur WebSocket sur le port 81
WebSocketsServer webSocket = WebSocketsServer(81);

// Pins de la LED RGB
#define RED1 5
#define GRN1 7
#define BLU1 6

void setup() {
   Serial.begin(115200);
   pinMode(RED1, OUTPUT);
   pinMode(GRN1, OUTPUT);
   pinMode(BLU1, OUTPUT);

   // Connexion au Wi-Fi
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
   }
   Serial.println("Connected to WiFi");
   Serial.print("ESP32 IP address: ");
   Serial.println(WiFi.localIP());

   // Démarrer le serveur WebSocket
   webSocket.begin();
   webSocket.onEvent(webSocketEvent);  // Attacher la fonction de gestion des événements
   Serial.println("WebSocket server started");
}

void loop() {
   // Gestion des connexions WebSocket
   webSocket.loop();
}

// Fonction pour gérer les événements WebSocket
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
   if (type == WStype_TEXT) {
      String message = String((char*)payload);
      Serial.printf("Received color code: %s\n", message.c_str());
      
      // Si le message commence par '#' et contient 7 caractères (#RRGGBB)
      if (message.startsWith("#") && message.length() == 7) {
         int r = strtol(message.substring(1, 3).c_str(), NULL, 16); // Extraire le rouge
         int g = strtol(message.substring(3, 5).c_str(), NULL, 16); // Extraire le vert
         int b = strtol(message.substring(5, 7).c_str(), NULL, 16); // Extraire le bleu

         analogWrite(RED1, r);
         analogWrite(GRN1, g);
         analogWrite(BLU1, b);

         Serial.printf("Set RGB to R:%d, G:%d, B:%d\n", r, g, b);
         webSocket.sendTXT(num, "Color updated");
      } else {
         webSocket.sendTXT(num, "Invalid color code. Use #RRGGBB format.");
      }
   }
}

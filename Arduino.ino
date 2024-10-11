#include <WiFi.h>
#include <WebSocketsServer.h>
#include <math.h>

// Informations de connexion Wi-Fi
const char* ssid = "PoleDeVinci_IFT";
const char* password = "*c.r4UV@VfPn_0";

// Démarrer le serveur WebSocket sur le port 81
WebSocketsServer webSocket = WebSocketsServer(81);

// Pins de la LED RGB
#define RED1 5
#define GRN1 7
#define BLU1 6

// Pin de la LED simple
#define LED_PIN 8

// Pin du capteur de température (doit être une pin compatible avec les lectures ADC)
#define TEMP_PIN 2 // Utilisez une broche compatible comme GPIO2

// Fonction pour calculer la température
double Thermister(int RawADC) {
    if (RawADC <= 0) {
        Serial.println("Error: RawADC is 0 or negative. Check sensor connection.");
        return NAN; // Retourne NaN si la valeur lue est incorrecte
    }

    double Temp;
    Temp = log(((10240000 / RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
    Temp = Temp - 273.15; // Convertir de Kelvin à Celsius
    Temp = (Temp - 32) * 5.0 / 9.0;
    return Temp;
}

void setup() {
    Serial.begin(115200);
    
    pinMode(RED1, OUTPUT);
    pinMode(GRN1, OUTPUT);
    pinMode(BLU1, OUTPUT);
    pinMode(LED_PIN, OUTPUT); // Configurer la pin 8 pour la LED

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
    webSocket.onEvent(webSocketEvent);
    Serial.println("WebSocket server started");
}

void loop() {
    // Lire la température depuis le capteur
    int sensorValue = analogRead(TEMP_PIN);
    Serial.println("Raw sensor value: " + String(sensorValue)); // Vérification de la valeur brute

    double temperature = Thermister(sensorValue);

    // Vérifier que la lecture de la température est valide
    if (!isnan(temperature)) {
        String tempString = String(temperature, 2); // Formater la température avec 2 décimales
        webSocket.broadcastTXT("Temperature:" + tempString);
        Serial.println("Temperature: " + tempString + " °C");
    } else {
        Serial.println("Error: Invalid temperature value.");
    }

    // Gestion des connexions WebSocket
    webSocket.loop();

    // Attendre une seconde avant la prochaine lecture
    delay(1000);
}

// Fonction pour gérer les événements WebSocket
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    if (type == WStype_TEXT) {
        String message = String((char*)payload);
        Serial.printf("Received message: %s\n", message.c_str());

        // Contrôler la LED simple via WebSocket
        if (message == "ON") {
            digitalWrite(LED_PIN, HIGH);  // Allumer la LED
            Serial.println("LED ON");
        } else if (message == "OFF") {
            digitalWrite(LED_PIN, LOW);   // Éteindre la LED
            Serial.println("LED OFF");
        }

        // Si le message est un code couleur #RRGGBB
        if (message.startsWith("#") && message.length() == 7) {
            int r = strtol(message.substring(1, 3).c_str(), NULL, 16);
            int g = strtol(message.substring(3, 5).c_str(), NULL, 16);
            int b = strtol(message.substring(5, 7).c_str(), NULL, 16);

            // Appliquer la couleur aux LEDs RGB
            analogWrite(RED1, r);
            analogWrite(GRN1, g);
            analogWrite(BLU1, b);

            Serial.printf("Set RGB to R:%d, G:%d, B:%d\n", r, g, b);
        }
    }
}

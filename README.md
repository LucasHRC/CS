# Objectif

Créer une interface utilisateur pour un micro-contrôleur ESP32/8266, permettant de suivre en temps réel les données de température via un capteur. L'interface affiche les températures minimales, maximales et actuelles à l'aide de jauges interactives et d'un graphique de suivi en temps réel. Les données sont envoyées depuis l'ESP32/8266 toutes les 5 secondes via WebSocket.

---

## Contenu à rendre :

- **Figma** : incluant un sitemap et un moodboard pour le design de l'interface.
- **GitHub** :
    - Code Arduino (pour le capteur de température et la communication WebSocket avec l'ESP32).
    - Code du site (HTML, CSS, JavaScript) pour l'affichage des jauges et du graphique de température.
    - `README.md` : document détaillant le projet, les croquis et la documentation Figma.
- **Vidéo** : démonstration filmée de l'interface en action avec les relevés de températures en direct.

---

## Ressources utilisées :

- **Polices** : [Google Fonts](https://fonts.google.com/)
- **Palette de couleurs** : [Coolors](https://coolors.co/)
- **Figma pour la conception** : [Lien vers Figma](https://www.figma.com/files/team/1422910346717224462/recents-and-sharing/recently-viewed?fuid=1422910344360649849)
- **Portfolio Inspiration** : [Marc Teyssier](https://marcteyssier.com/)

---

## Fonctionnalités de l'interface :

### 1. Affichage en temps réel des températures :

- **Températures suivies** :
    - Température minimale
    - Température maximale
    - Température actuelle
- **Affichage graphique** : un graphique en temps réel (via Chart.js) pour suivre l'évolution de la température.
- **Mise à jour automatique** : Les jauges et le graphique se mettent à jour toutes les 5 secondes, en fonction des données envoyées par l'ESP32.

### 2. LED interactives :

- Trois "LEDs" simulées sur l'interface changent de couleur en fonction du drapeau sélectionné.

### 3. Connexion WebSocket avec l'ESP32 :

- **Communication en temps réel** entre l'ESP32 et le site web via WebSocket.
- **Envoi des données** toutes les 5 secondes (températures minimale, maximale, et actuelle).
- **Wi-Fi** : L'ESP32 envoie les données après connexion à un réseau Wi-Fi configuré.

---

## Hébergement et configuration WebSocket :

- **Hébergement** : Hébergement du site avec un serveur WebSocket pour gérer la communication avec l'ESP32 en temps réel.
- **Librairie WebSocket pour Arduino** : [Arduino WebSocket](https://github.com/Links2004/arduinoWebSockets) pour gérer l'envoi des données du capteur de température au site web.

---

## Code Arduino (ESP32) :

- Le micro-contrôleur ESP32 est programmé pour :
    - Mesurer les températures minimales, maximales, et actuelles via un capteur.
    - Envoyer ces valeurs toutes les 5 secondes au site web à l'aide d'un serveur WebSocket.
    - Gérer la connexion Wi-Fi pour la communication en temps réel.
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
- **Graphique interactif** :
    - Affichage en temps réel des données de température sur un graphique animé et dégradé.
    - Le graphique conserve l'historique des valeurs reçues et adapte son échelle au fur et à mesure de l'ajout de nouvelles données.
- **Jauges modernes** :
    - Représentation visuelle intuitive des températures avec des jauges inspirées des tableaux de bord.
- **Réglages et calibration du capteur de température** :
    - Ajustements pour calibrer les valeurs de température selon les besoins.
- **Connexion Wi-Fi pour l'ESP32** :
    - Permet de recevoir les données du capteur en direct sur le site grâce à une connexion WebSocket.
- **Bouton STOP** :
    - Permet de réinitialiser la lecture des températures et de redémarrer le système pour une nouvelle session de suivi.

---

### 2. Sketching :

- **Liste des fonctionnalités par écran** :
    - **Écran principal** : affichage des trois jauges pour les températures (minimale, maximale, actuelle) et le graphique de suivi.
    - **Écran de réglages** : calibration et ajustements du capteur pour un suivi précis.
    - **Écran de connexion Wi-Fi** : configuration réseau pour l'ESP32, permettant une connexion simple et rapide.
- **Croquis rapide de chaque écran** pour visualiser la disposition des jauges, du graphique et des boutons.

---

### 3. Figma :

- **Palette de couleurs** pour une interface épurée et moderne.
- **Polices et icônes** adaptées pour un affichage clair des données.
- **Inspiration pour le design des jauges** : un look moderne, inspiré des dashboards de données pour une meilleure compréhension visuelle.
- **Versions desktop et mobile** de l'interface avec mise en page responsive pour s'adapter aux différents types d'écrans.

---

## Hébergement et configuration WebSocket :

- **Hébergement** : Hébergement du site avec un serveur WebSocket pour gérer la communication avec l'ESP32 en temps réel.
- **Librairie WebSocket pour Arduino** : [Arduino WebSocket](https://github.com/Links2004/arduinoWebSockets) pour gérer l'envoi des données du capteur de température au site web.

---

## Code Arduino (ESP32) :

- Le micro-contrôleur ESP32 est programmé pour :
    - Mesurer les températures minimales, maximales, et actuelles via un capteur.
    - Envoyer ces valeurs toutes les secondes au site web à l'aide d'un serveur WebSocket.
    - Gérer la connexion Wi-Fi pour la communication en temps réel.

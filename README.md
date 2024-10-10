# Objectif :

Réaliser une interface utilisateur pour le micro-contrôleur avec suivi en temps réel des données de température via un capteur.

---

## A rendre :

- **Figma** avec sitemap, moodboard
- **Github** avec :
    - Code Arduino (pour capteur de température)
    - Code du site (HTML, CSS et JavaScript pour l'affichage des jauges de température)
    - `readme.md` avec croquis papier et documentation Figma
- **Vidéo** de la démo filmée montrant l'interface en action avec la lecture des températures en direct

---

## Ressources :

- **Polices** : [Google Fonts](https://fonts.google.com/)
- **Palettes de couleurs** : [Coolors](https://coolors.co/)
- **Figma** : [Lien vers Figma](https://www.figma.com/files/team/1422910346717224462/recents-and-sharing/recently-viewed?fuid=1422910344360649849)
- **Inspirations UI** : [Load More](https://loadmo.re/)
- **Inspiration Portfolio** : [Marc Teyssier](https://marcteyssier.com/)
- **Commandes CSS** : [Tailwind CSS](https://tailwindcss.com/)

---

## Plan de réalisation :

### 1) Sitemap :

- Suivi de la température en direct via trois jauges :
    - Température minimale
    - Température maximale
    - Température actuelle
- Réglages et calibration du capteur de température
- Connexion Wi-Fi pour l'ESP32, permettant de recevoir les données du capteur en direct sur le site
- Bouton STOP pour réinitialiser la lecture des températures et redémarrer le système

---

### 2) Sketching :

- Liste des fonctionnalités par écran :
    - Écran principal : affichage des trois jauges pour les températures (minimale, maximale, actuelle)
    - Écran de réglages : calibration et ajustements du capteur
    - Écran de connexion Wi-Fi : configuration réseau pour l'ESP32
- Croquis rapide de chaque écran pour visualiser la disposition des jauges et des boutons

---

### 3) Figma :

- Palette de couleurs
- Polices et icônes
- Inspiration pour le design des jauges (look moderne, inspiré des dashboards de données)
---

## Hébergement du site et WebSocket :

### Hébergement :

- Héberger un site web et un serveur WebSocket pour la communication en temps réel avec le micro-contrôleur ESP32.

### Utiliser la librairie Arduino WebSocket :

- [Librairie WebSocket Arduino](https://github.com/Links2004/arduinoWebSockets) pour gérer la communication entre le site et le capteur de température.

---

### Sur le site :

- Afficher les températures minimales, maximales, et actuelles via des jauges interactives.
- Les jauges se mettront à jour en temps réel en fonction des données reçues depuis l'ESP32.
- Ajouter un bouton pour réinitialiser les valeurs minimales et maximales.

---

### Sur l’ESP32/8266 :

- Créer le serveur WebSocket pour envoyer les données de température toutes les 5 secondes.
- Gérer la connexion Wi-Fi pour permettre au site de recevoir les données en temps réel.
- Programmer l'envoi des valeurs minimales, maximales et actuelles du capteur de température.

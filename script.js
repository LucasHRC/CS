let connection;

window.onload = () => {
    const ip = prompt("Entrez l'adresse IP de votre ESP32:", "10.1.224.101");
    connection = new WebSocket('ws://' + ip + ':81/');

    connection.onopen = () => {
        console.log("Connecté au serveur WebSocket");
    };

    connection.onerror = error => {
        console.error("Erreur WebSocket", error);
    };

    connection.onmessage = event => {
        console.log("Message reçu du serveur:", event.data);

        // Affichage de la température reçue
        if (event.data.startsWith("Temperature:")) {
            const temp = parseFloat(event.data.split(":")[1]);
            document.getElementById("temperature").innerText = temp + " °C";

            // Mise à jour du graphique avec la nouvelle température
            updateChart(temp);
        }
    };
};

function sendColor() {
    const colorInput = document.getElementById("color").value;
    if (connection.readyState === WebSocket.OPEN) {
        if (/^#[0-9A-F]{6}$/i.test(colorInput)) {
            connection.send(colorInput);
        } else {
            alert("Veuillez entrer un code couleur valide au format #RRGGBB");
        }
    } else {
        alert("WebSocket non connecté");
    }
}

function turnOn() {
    if (connection.readyState === WebSocket.OPEN) {
        connection.send("ON");
    } else {
        alert("WebSocket non connecté");
    }
}

function turnOff() {
    if (connection.readyState === WebSocket.OPEN) {
        connection.send("OFF");
    } else {
        alert("WebSocket non connecté");
    }
}

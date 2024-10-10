// Récupération des éléments HTML pour les LEDs
const led1 = document.getElementById('led1');
const led2 = document.getElementById('led2');
const led3 = document.getElementById('led3');
const flagSelector = document.getElementById('flagSelector');

// Drapeaux tricolores avec leurs couleurs
const flags = {
    fr: ['#0055A4', '#FFFFFF', '#EF4135'],  // France
    it: ['#009639', '#FFFFFF', '#CE2B37'],  // Italie
    de: ['#000000', '#DD0000', '#FFCE00'],  // Allemagne
};

// Changer les couleurs des LEDs selon le drapeau sélectionné
flagSelector.addEventListener('change', function() {
    const selectedFlag = this.value;
    const colors = flags[selectedFlag];

    led1.style.backgroundColor = colors[0];
    led2.style.backgroundColor = colors[1];
    led3.style.backgroundColor = colors[2];
});

// Simuler la réception des données de température
function updateTemperature(min, max, current) {
    document.getElementById('tempMin').textContent = `${min}°C`;
    document.getElementById('tempMax').textContent = `${max}°C`;
    document.getElementById('tempCurrent').textContent = `${current}°C`;
}

// Configuration du graphique avec Chart.js
const ctx = document.getElementById('tempChart').getContext('2d');
let tempChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [],  // Les temps (secondes)
        datasets: [{
            label: 'Température Actuelle (°C)',
            backgroundColor: 'rgba(255, 99, 132, 0.2)',
            borderColor: 'rgba(255, 99, 132, 1)',
            borderWidth: 1,
            data: []  // Les valeurs de température
        }]
    },
    options: {
        responsive: true,
        maintainAspectRatio: false,  // Empêche de maintenir le ratio aspect d'origine
        scales: {
            x: {
                title: {
                    display: true,
                    text: 'Temps (s)'
                }
            },
            y: {
                beginAtZero: true,
                title: {
                    display: true,
                    text: 'Température (°C)'
                }
            }
        }
    }
});

// Ajouter des points de données toutes les 5 secondes
let time = 0;
setInterval(() => {
    const min = Math.floor(Math.random() * 10) + 10; // Température min simulée
    const max = Math.floor(Math.random() * 10) + 25; // Température max simulée
    const current = Math.floor(Math.random() * (max - min)) + min; // Température actuelle simulée

    updateTemperature(min, max, current);

    // Ajouter la température actuelle au graphique
    tempChart.data.labels.push(time);
    tempChart.data.datasets[0].data.push(current);
    tempChart.update();

    time += 5;  // Augmenter le temps de 5 secondes
}, 5000);

// Redimensionner le canvas selon la taille de la fenêtre
function resizeChart() {
    const canvas = document.getElementById('tempChart');
    const maxWidth = 800;  // Largeur maximale du graphique
    const maxHeight = 400;  // Hauteur maximale du graphique

    const width = Math.min(window.innerWidth * 0.8, maxWidth);  // Largeur max 80% ou 800px
    const height = Math.min(window.innerHeight * 0.5, maxHeight);  // Hauteur max 50% ou 400px

    canvas.style.width = `${width}px`;
    canvas.style.height = `${height}px`;
    tempChart.resize();  // Redimensionne le graphique
}

// Appeler la fonction de redimensionnement au chargement et lors des redimensionnements
window.addEventListener('resize', resizeChart);
window.addEventListener('load', resizeChart);

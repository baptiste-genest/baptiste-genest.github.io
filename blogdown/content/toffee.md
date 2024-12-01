---
title: "Toffee"
---
<div style="text-align:center">

A random Toffee picture to brighten your day.

<img id="randomImage" alt="Image aléatoire" style="height: 500px; object-fit: contain; border: 5px solid #ccc; border-radius: 10px;">



<button id="loadImageButton">ANOTHER ONE</button>

<script>

    // Sélection d'une image aléatoire
    function loadRandomImage() {
        const randomIndex = Math.floor(Math.random() * 25)+1;
        const randomImagePath = "../toffee/toffee_" + randomIndex+".jpg";
        // Affichage de l'image
        document.getElementById('randomImage').src = randomImagePath;
    }
    loadRandomImage();
    document.getElementById('loadImageButton').addEventListener('click', loadRandomImage);
</script>

</script>

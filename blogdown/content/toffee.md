---
title: "Toffee"
---
<div style="text-align:center">

A random Toffee picture to brighten your day.

<img id="randomImage" alt="Image aléatoire" style="height: 500px; object-fit: contain; border: 5px solid #ccc; border-radius: 10px;">



<button id="loadImageButton">ANOTHER ONE</button>

<script>

    const array = Array.from(Array(25).keys());
    const shuffledArray = array.sort((a, b) => 0.5 - Math.random());
    //console.log(shuffledArray);
    var id = 0;
    // Sélection d'une image aléatoire
    function loadRandomImage() {
        const randomIndex = shuffledArray[id++]+1;//Math.floor(Math.random() * 25)+1;
        id %= 25;
        //console.log(randomIndex-1,id);
        const randomImagePath = "../toffee/toffee_" + randomIndex+".jpg";
        // Affichage de l'image
        document.getElementById('randomImage').src = randomImagePath;
    }
    loadRandomImage();
    document.getElementById('loadImageButton').addEventListener('click', loadRandomImage);
</script>

</script>

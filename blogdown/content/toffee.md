---
title: "Toffee"
---
<div style="text-align:center">

A random Toffee picture to brighten your day.

<img id="randomImage" alt="Image aléatoire" style="height: 500px; object-fit: contain; border: 5px solid #ccc; border-radius: 10px;">



<button id="loadImageButton">ANOTHER ONE</button>

<script>let nb_imgs = 47;

const shuffledArray = Array.from(
    { length: nb_imgs },
    (_, i) => i + 1
);

function shuffle(arr) {
    for (let i = arr.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [arr[i], arr[j]] = [arr[j], arr[i]];
    }
}

shuffle(shuffledArray);

let id = 0;

function loadRandomImage() {
    if (id >= nb_imgs) {
        id = 0;
    }

    const randomIndex = shuffledArray[id++];
    document.getElementById('randomImage').src =
        `../toffee/toffee_${randomIndex}.jpg`;
}

loadRandomImage();

document
    .getElementById('loadImageButton')
    .addEventListener('click', loadRandomImage);
    
</script>

</script>

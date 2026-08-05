---
title: "😻 Toffee 😻"
---
<div style="text-align:center">

<style>
body { max-width: 1150px; }
.toffee-row { display: flex; flex-wrap: wrap; justify-content: center; align-items: center; gap: 2rem; }
.toffee-col { min-width: 0; }
.toffee-col img { max-width: 100%; }
.toffee-col-pic { flex: 1 1 300px; max-width: 540px; }
.toffee-col-3d { flex: 2 1 400px; max-width: 1000px; }
</style>

<div class="toffee-row">
<div class="toffee-col toffee-col-pic">

A random Toffee picture to brighten your day.

<div style="height: 500px; display: flex; align-items: center; justify-content: center;">
<img id="randomImage" alt="Image aléatoire" style="max-width: 100%; max-height: 100%; width: auto; height: auto; border: 5px solid #ccc; border-radius: 10px;">
</div>



<button id="loadImageButton">ANOTHER ONE</button>

</div>
<div class="toffee-col toffee-col-3d">

<div id="toffee3d" data-base="/toffee3d/" style="width: 100%; aspect-ratio: 3 / 2; margin: 0 auto; position: relative; overflow: hidden; touch-action: none;">
<div id="toffee3d-status" style="position: absolute; inset: 0; display: flex; align-items: center; justify-content: center; font-style: italic; color: #888;">Loading Toffee…</div>
</div>

## Toffee in 3D

<script type="module" src="/toffee3d/viewer.js"></script>

</div>
</div>

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

</div>

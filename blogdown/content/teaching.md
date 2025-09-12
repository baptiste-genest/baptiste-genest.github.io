---
title: "Teaching"

---

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Formulaire de retour</title>
<style>
  textarea {
    width: 100%; /* Définir la largeur à 100% */
  }
</style>
<script src="https://smtpjs.com/v3/smtp.js"></script>
<script src="../encryption/encrypt.js"></script>
</head>

<br>
<br>

- 2025 : 
  - [LIFAPI](https://perso.univ-lyon1.fr/elodie.desseree/LIFAPI/TP.html) (automne) : chargé de TP
  - [LIFAPC](https://perso.liris.cnrs.fr/vincent.nivoliers/lifapc/) (printemps) : chargé de TD 
    - Annale corrigée 1er contrôle : [sujet](https://perso.liris.cnrs.fr/vincent.nivoliers/lifapc/Supports/Annales/2019_rec_for.pdf) [vidéo de la correction](https://youtu.be/wBoQUa_ymMo) [fiche recap](./fiche_sommes.pdf)


<form id="feedbackForm">
  
  <label for="feedback"> <b> Si je suis votre chargé de TD/TP : </b> vous pouvez m'envoyer un message anonymement (si vous n'avez pas compris quelque chose, me faire un retour, des points d'améliorations, etc... n'hésitez pas, c'est là pour ça !) </label><br>
  <textarea id="feedback" name="feedback" rows="8" cols="50"></textarea><br>
  <label for="password"> <b>Mot de passe :</b></label><br>
  <input type="password" id="password" name="password" rows="1" cols="10" required ></textarea><br>
  <button type="submit">Envoyer</button>
</form>

<script>


document.getElementById("feedbackForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Empêcher le formulaire de se soumettre normalement
  let password = document.getElementById("password").value;
  let feedback = document.getElementById("feedback").value;
  if (hashCode(password) == -868335013){
  Email.send({
    SecureToken : attemptDecodeToken(password),
    To : 'baptistegenest@gmail.com',
    From : "baptistegenest@gmail.com",
    Subject : "Feedback cours",
    Body :  "Texte tampon pour rallonger le message, vous êtes sacrément beau gosse vous : \n"+feedback,
}).then(
  message => alert(message)
);


  // Message de confirmation pour l'utilisateur
  alert("Merci pour votre retour !");

  // Réinitialiser le formulaire
  document.getElementById("feedbackForm").reset();
}else {
 alert("mauvais mot de passe");
}

});
</script>


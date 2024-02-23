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
</head>

<br>
<br>
<center>
Nothing <b>yet !</b>
</center>

<form id="feedbackForm">
  
  <label for="feedback"> <b> Si je suis votre chargé de TD/TP : </b> vous pouvez m'envoyer un message anonymement (si vous n'avez pas compris quelque chose, me faire un retour, des points d'améliorations, etc... n'hésitez pas, c'est là pour ça !) </label><br>
  <textarea id="feedback" name="feedback" rows="8" cols="50"></textarea><br>
  <label for="password"> <b>Mot de passe :</b></label><br>
  <input type="password" id="password" name="password" rows="1" cols="10" required ></textarea><br>
  <button type="submit">Envoyer</button>
</form>

<script>


function hashCode(str) {
    let hash = 0;
    for (let i = 0, len = str.length; i < len; i++) {
        let chr = str.charCodeAt(i);
        hash = (hash << 5) - hash + chr;
        hash |= 0; // Convert to 32bit integer
    }
    return hash;
}

document.getElementById("feedbackForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Empêcher le formulaire de se soumettre normalement
  let password = document.getElementById("password").value;
  let feedback = document.getElementById("feedback").value;
  if (hashCode(password) == -868335013){
  Email.send({
    SecureToken : "4ce2a60f-646a-4078-b0aa-2cb1dc96c5e0",
    To : 'baptiste.genest@etu.univ-lyon1.fr',
    From : "baptiste.genest@etu.univ-lyon1.fr",
    Subject : "Feedback cours",
    Body :  feedback,
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


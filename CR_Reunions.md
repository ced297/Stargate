
-----------
22/11/2017
ODJ : Debut dev front et back
--

Front:
1) Pc Angular SII hs: impossible de démarrer le PC fix prévu pour faire de l'Angular 
2) Exploration du code généré par swagger-editor
Back:
1) Utilisation de swagger-editor
2) Génération du code serveur
3) Exploration du code généré

-----------
08/11/2017
ODJ : Definition IHM et interfaces
--

1) Définition des différents Lots:
  - LOT1 : IHM simple qui permet d'allumer/éteindre les leds choisies dans l couleur (mixe RVB sur 255).
  - LOT2 : IHM style DHD pour activer des séquences.
  - LOT3 : IHM de programmation de séquence et d'hambiances.
  - LOT suivants : Rendre tout ça encore plus sexy et y ajouter d'autres fonctionnalitées.
2) Revue de l'IHM du LOT 1: 
cf: IHM_LOT1

3) Revue du swagger avec définition des ressurces et url d'accès: cf swagger

-----------
25/10/2017
ODJ : Mise en place environnements dont le socle Angular SII 
--

1) installation du PC sii (ca a pris pas mal de temps au final)
2) socle angular SII avec tous les trucs qui vont avec (npm ...)
3) lancement du front => tout est OK
4) dépot sur git (https://github.com/N3mo4Br3st/stargate-front)
5) on a aussi posé les bases de l'archi et notamment la première IHM:
  - une liste déroulante pour choisir le ruban de led que l'on veux utiliser (il y en a 3 : chevrons/glyphes/central) =>alimentée par (get) /stargate/bandeau/
  - une liste déroulante pour choisir la led à traiter (ou toutes) => alimentée par (get) /stargate/bandeau/<n°du bandeau>
  - 3 barres de sélections pour la couleur (RVB) => alimentée soit par (get) /stargate/bandeau/<n°du bandeau>/led/<n°led> soit toutes les valeurs à 0 si "toutes" est sélectionné dans la liste de leds
  - (optionnel) un bouton de raz des couleur
  - un bouton d'envoi => fait soit:
     * un (Post) /stargate/bandeau/<n°du bandeau> {R=[0-255],V=[0-255],B=[0-255]} si "toutes" est sélectionné dans la liste de leds
     * un (Post) /stargate/bandeau/<n°du bandeau>/led/<n°led> {R=[0-255],V=[0-255],B=[0-255]} si une led est sélectionné dans la liste de leds

les noms ne sont pas encore définitif

-----------
11/10/2017
ODJ : Préparation du back et ébauche de définition des Api:
--

Vu le peu de personnes ce midi nous avons un peu discuté des premières Api qui seront mises à dispo :
1. test(boolean alumer) qui alumera ou éteindra toutes les led de la porte
2. chevron( enum glyphe, boolean raz) qui ajoutera le glyphe à la séquence d'ouverture et raz qui forcera le début d'une nouvelle séquence
3. conf(??) pour choisir la couleurs des leds des rubants

En suite nous avons passé pas mal de temps sur la mise en place de l'environnement back : formatage de la carte SD + installation Raspbian + installation du serveur web Nginx + test du serveur web

prochaine étape faire un squelette du back et exposer les Api REST et les mocker.
Voilà pour les infos du jour.

-----------

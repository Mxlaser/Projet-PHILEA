# Interface de Contrôle - Projet Philae (C++ Builder)

Ce projet est une application Windows développée en C++ (framework VCL avec Embarcadero C++ Builder). Elle permet de contrôler un système matériel simulant les instruments de l'atterrisseur Philae (ROMAP et MUPUS) et de visualiser en temps réel le retour de deux caméras IP.

## Fonctionnalités principales

* **Communication Série (RS232) :** Connexion à un port COM pour envoyer des trames de commande spécifiques au matériel.
* **Contrôle des instruments :**
  * **MUPUS :** Déploiement, lacher du marteau, activation de l'aimant, rangement, verrouillage et configuration du temps de vibration.
  * **ROMAP :** Déploiement, rangement et demande d'état.
* **Séquence Automatisée :** Une machine d'état intégrée permet d'exécuter une routine complète d'actions minutées de manière autonome (déploiement, actions, rangement).
* **Retour Vidéo Double :** Récupération de deux flux vidéo RTSP de caméras IP. Le flux est transcodé à la volée via VLC et lu via un client TCP natif pour extraire et afficher les images JPEG en temps réel dans l'interface.

## Prérequis

Pour compiler et faire fonctionner ce projet, vous aurez besoin de :

* **Embarcadero C++ Builder** (Le projet utilise les composants VCL).
* **VLC Media Player :** Doit être installé sur la machine cible pour assurer le transcodage vidéo en arrière-plan (l'exécutable `vlc` doit être accessible).
* **Fichier de configuration :** Le programme nécessite un fichier nommé `PHILEA2023.config` à la racine de l'exécutable contenant les paramètres suivants dans l'ordre :
  1. Mot-clé ignoré (ex: `COM:`) suivi du port COM (ex: `COM3`)
  2. Mot-clé ignoré (ex: `IP1:`) suivi de l'IP de la caméra 1
  3. Mot-clé ignoré (ex: `IP2:`) suivi de l'IP de la caméra 2
  4. Mot-clé ignoré suivi du port caméra 1
  5. Mot-clé ignoré suivi du port caméra 2
  6. Mot-clé ignoré suivi du délai (tempo) pour la machine d'état

## Structure du code

* `Unit1.cpp / .h` : Logique de l'interface graphique (GUI) et machine d'état.
* `PortCom.cpp / .h` & `PortComDI` : Gestion de la communication série RS232.
* `TrameVideo.cpp / .h` : Interfaçage avec VLC et traitement du flux MJPEG.
* `SNClientTCP.cpp / .h` : Implémentation bas niveau des sockets TCP pour le flux vidéo HTTP.

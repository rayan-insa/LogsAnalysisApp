# TP4-POO2 Analog

## Description

Analog est une application conçue pour analyser les logs d'un serveur web, générer des graphiques représentant les liens entre les pages web visitées et filtrer les résultats en fonction de certains critères, tels que l'heure de consultation des pages ou les types de fichiers consultés.

## Prérequis

Avant d'utiliser l'application Analog, assurez-vous d'avoir installé les éléments suivants :
- Un compilateur C++ prenant en charge le standard C++11
- Les bibliothèques standard C++ (iostream, vector, algorithm, etc.)

## Installation

Pour compiler l'application Analog, suivez les étapes ci-dessous :
2. Accédez au répertoire contenant les fichiers source de l'application.
3. Exécutez la commande `make` dans votre terminal pour compiler l'application.

## Utilisation

Une fois l'application compilée, vous pouvez l'exécuter en utilisant la commande suivante dans votre terminal :

./analog [options] chemin_vers_le_fichier_log


### Options disponibles :

- `-g nom_fichier.dot` : Génère un fichier .dot représentant le graphe des liens entre les pages web consultées.
- `-t heure` : Filtre les résultats pour inclure uniquement les pages consultées à l'heure spécifiée (0 <= heure <= 24).
- `-e` : Exclut les pages au format image (jpg, png, gif, etc.) des résultats.
  
Vous pouvez combiner ces options pour affiner votre analyse. 

## Auteurs

Ce projet a été développé par :
- Cavagna Justine
- Chikhi Djalil
- Hanader Rayan
- Thabet Yasmine

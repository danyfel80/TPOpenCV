# TP OpenCV - Filtrage gaussien des images
Dans ce TP vous allez utiliser  les technologies de gestion de code ainsi que la librairie OpenCV pour le traitement d'images :
* Git
* CMake
* OpenCV

L'objectif principal sera de construire un logiciel qui vous permettra d'appliquer un filtre gaussien à une image configuré par l'utilisateur. L'utilisateur pourra également,  sauvegarder l'image filtrée dans un fichier PNG.

À la fin de ce TP l'application devrait ressembler à l'image ci-dessous:

![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot1.png)

1. Téléchargement du code de base avec git
   1. Pour commencer, vous allez télécharger le code de base du dépôt github avec Eclipse. Pour cela ouvrez la perspective git dans Eclipse (Window->Perspective->Open Perspective->Other… Choisissez Git).
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot2.png)
   
   2. Cliquez sur l’icône Clone Repository comme dans l’image suivante :
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot3.png)
   
   3. Remplissez le formulaire comme ci-dessous et puis cliquez sur Finish.
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot4.png)
   
   4. Les fichiers téléchargés seront stockés dans le chemin ~/git/TPOpenCV/ Ici vous trouverez un dossier src avec le code source et une image de test running.png.

2. Création du projet avec CMake
   1. Ouvrez un terminal et entrez : cmake-gui
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot5.png)
      
      Note: Si cmake-gui n'est pas installé, créez un dossier `build` à l'intérieur du dossier `TPOpenCV` et dans ce dossier adaptez et lancez la commande `cmake -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE ../src`. Maintenant vous pouvez continuer à la section 3.
   
   2. Précisez le répertoire où se trouve le code source (~/git/TPOpenCV/src).
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot6.png)
   
   3. Précisez le répertoire pour stocker le code compilé (~/git/TPOpenCV/build).
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot7.png)
   
   4. Cliquez sur le bouton Configure pour commencer la configuration. Indiquez comme générateur « Eclipse CDT4 – Unix Makefiles ».
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot8.png)
   
      Dans cette étape CMake va lire le fichier CMakeLists.txt qui se trouve dans le répertoire src et présentera la configuration trouvée par défaut dans ce fichier. À la fin de cette étape vous aurez des champs en rouge pour que vous puissiez compléter la configuration.
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot9.png)
   
      Comme vous pouvez le remarquer, dans les champs en rouge on vous demande d’indiquer le chemin du fichier exécutable d’Eclipse, ainsi que la version. Aussi, CMake a détecté automatiquement le répertoire des librairies OpenCV.
   
   5. Indiquez le répertoire du fichier exécutable Eclipse qui se trouve dans [demandez au professeur] avec la version 4.3 (Kepler) et puis cliquez sur Configure à nouveau.
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot10.png)
   
   6. Les champs rouges deviendront blancs. Maintenant vous pouvez générer le projet Eclipse. Cliquez sur le bouton Generate.
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot11.png)
   
   Après la génération vous trouverez dans le répertoire ~/git/TPOpenCV/build les fichiers générés par CMake que vous utiliserez dans Eclipse.

3. Importation du projet sur Eclipse
   1. Le projet généré par CMake peut être importé maintenant directement sur Eclipse. Pour cela, sur Eclipse revenez sur la perspective C/C++.
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot12.png)
      
      Puis importez le projet avec File->Import…
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot13.png)
   
   2. Sélectionnez le Wizard C/C++->Existing Code as Makefile Project et cliquez sur Next
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot14.png)
   
   3. Donnez un nom au projet. Puis indiquez le chemin des fichiers du projet (répertoire build) et sélectionnez le compilateur à utiliser (Linux GCC pour Linux). Finalement, cliquez Finish pour finaliser l’importation du projet.
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot15.png)
   
   À la fin vous aurez le projet sous l'IDE Eclipse avec les fichiers de code source main.cpp, Gaussian.h et Gaussian.cpp.
   
   ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot16.png)
   
   4. Essayez de construire le projet avec Eclipse et de l’exécuter sur un terminal avec la commande ~/git/TPOpenCV/build/imageBlur ~/git/TPOpenCV/running.png
   
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot17.png)
      
      ![alt text](https://raw.githubusercontent.com/danyfel80/TPOpenCV/master/img/screenshot18.png)
   
   Si vous regardez le code dans le main.cpp, les paramètres passés sont utilisés pour créer une image dans l’instance filtrer de type Gaussian.
   
   5. Explorez le code dans les fichiers main.cpp, Gaussian.h et Gaussian.cpp

4. Ajout de fonctionnalités
   1. Vous allez rajouter un trackbar au-dessous de l’image présentée qui permettra à l’utilisateur de choisir le niveau de floutage du filtre Gaussian.
   2. Quand l’utilisateur change la valeur du trackbar une fenêtre montrera le résultat du filtre Gaussian.
   3. Quand l’utilisateur clique sur l’image résultat, elle sera sauvegardée sur un fichier png. Ajoutez un MouseCallback à l’image résultat pour implémenter cette fonctionnalité.
      Utilisez imwrite pour sauvegarder l’image résultat dans le fichier outputFilePath.

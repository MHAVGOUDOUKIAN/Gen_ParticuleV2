# Gen_ParticuleV2

  Un système simple de particules
  
    Doit impérativement être utilisée avec la librairie graphique SFML

## Quelques indications

  Fichier ParticuleGenerator.hpp:
  
    Contient la classe principale permettant de générer des particules à l'écran.
    C'est une version qui peut encore être optimisée.

    Créer et utiliser un générateur de particules dans un programme:
         1 - Déclarer le générateur puis l'initialiser avec une position
         2 - Appeler la méthode update(deltaTime) à chaque frame pour mettre à jour le générateur et ses particules
         3 - Appeler la méthode draw() pour afficher les particules que contient le générateur

    NB: Le générateur doit se trouver dans une boucle pour fonctionner correctement; il prend en compte le temps écoulé
    entre chaque frame
    
  Fichier Particule.cpp/.hpp:
  
     Dans ce fichier se trouve toutes les particules que le générateur va pouvoir générer
     Pour ce faire il suffit de choisir la particule que va devoir utiliser le générateur
     lors de sa déclaration grâce à la généricité : ParticuleGenerateur< ma_Particule > mon_Generateur;

     Chaque type de particule est en fait une instance d'une classe qui: 
         - dérive d'une classe virtuelle pure 'Particule'
         - décrit les caractéristiques et le comportement des particules

     La construction actuelle du générateur ne permet pas aux particules d'interagir avec l'environnement
     extérieur (autres objets, souris, écran, etc..); elles restent fidèles au comportement de base décrit
     dans leur classe d'origine.

     Pour créer une nouvelle classe de particules, il faut au minimum la faire dériver de 'Particule' et redéfinir
     les cinq méthodes virtuelles pures de celle-ci en fonction du comportement de la particule : 
         - update(), launch(), draw(), processPhysics() et processCollision().
     Vous pouvez ensuite directement utiliser cette nouvelle classe de particule dans le générateur;

## Controles 
|**Touche** | **Action**|
| ------ | ------ |
|**Clic Gauche**| Générer des particules|
|**Clic Droit** | Changer le type de particules (5 disponibles)|
|**Echap**| Quitter le programme |

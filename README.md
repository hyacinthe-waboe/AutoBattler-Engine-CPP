# ⚔️ Auto-Battler Engine (C++)

## 📖 À propos du projet
Ce projet a été développé dans le cadre du module d'algorithmique avancée de ma 3ème année de Licence MIASHS à l'Université Toulouse - Jean Jaurès. 
Il s'agit d'un simulateur de combats autonomes (Auto-Battler) développé entièrement en C++. L'objectif principal de ce projet était de concevoir une architecture logicielle modulaire et de maîtriser les concepts complexes de la gestion mémoire.

## ⚙️ Concepts techniques abordés
- **Programmation Orientée Objet (POO) Avancée :** Utilisation de l'héritage, du polymorphisme et des classes abstraites pour définir les différentes entités du jeu (personnages, classes, etc.).
- **Design Pattern :** Implémentation du patron de conception *Factory* pour la génération dynamique des combattants.
- **Gestion de la mémoire :** Allocation dynamique sécurisée, manipulation de pointeurs et création de destructeurs personnalisés pour éviter les fuites de mémoire.
- **Automatisation :** Structuration de la compilation via un outil externe.

## 🛠️ Architecture simplifiée
Le code est structuré de manière à séparer la logique du moteur de jeu et les entités. 
Les personnages héritent tous d'une classe de base virtuelle, ce qui permet au système de combat de gérer n'importe quel type de combattant de manière générique grâce au polymorphisme.

## 🚀 Installation et Exécution

**1. Prérequis :**
Assurez-vous d'avoir un compilateur C++ (comme g++) et l'utilitaire Make installés sur votre machine.

**2. Compilation :**
Placez-vous dans le dossier racine du projet depuis votre terminal, puis tapez la commande suivante :

```bash 
make
```

**3. Lancement de la simulation :**
Une fois le projet compilé, exécutez le programme avec la commande :
```bash 
./bin/DungeonBattle
```

**4. Nettoyage :**
Pour supprimer les fichiers objets générés lors de la compilation, utilisez :
```bash 
make clean
``` 

## 👨‍💻 Auteur
**Hyacinthe WABOE** - Étudiant en L3 MIASHS (Ingénierie logicielle et Data Science)

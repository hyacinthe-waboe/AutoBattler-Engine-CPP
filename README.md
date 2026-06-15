# Auto-Battler Engine C++

Moteur de combats automatiques développé en C++ dans le cadre de la Licence 3 MIASHS à l'Université Toulouse - Jean Jaurès.

Le programme génère quatre équipes de trois héros, simule deux demi-finales puis une finale, et affiche le déroulement complet du tournoi dans le terminal.

## Fonctionnalités

- génération aléatoire des équipes avec une Factory ;
- six classes jouables : Guerrier, Mage, Archer, Paladin, Assassin et Druide ;
- statistiques propres à chaque classe : points de vie, attaque, défense et vitesse ;
- capacités spécialisées selon le héros ;
- objets aléatoires améliorant l'attaque, la défense ou la vitesse ;
- initiative calculée à partir de la vitesse ;
- récupération des héros entre les combats ;
- tournoi automatisé à quatre joueurs.

## Concepts mis en pratique

- programmation orientée objet ;
- héritage, classes abstraites et polymorphisme ;
- patron de conception Factory ;
- allocation dynamique, pointeurs et destructeurs ;
- séparation entre les interfaces dans `include/` et les implémentations dans `src/`.

## Structure

```text
.
├── include/          # Fichiers d'en-tête des héros et du moteur
├── src/              # Implémentations et point d'entrée
├── Compile.bat       # Compilation et lancement sous Windows
├── Makefile          # Compilation sous Linux/macOS
└── Rapports_Projet.pdf
```

## Lancer le projet

### Windows

Avec `g++` installé et disponible dans le `PATH` :

```powershell
.\Compile.bat
```

### Linux ou macOS

```bash
make run
```

Pour compiler sans lancer le tournoi :

```bash
make
./bin/DungeonBattle
```

Pour supprimer l'exécutable généré :

```bash
make clean
```

## Limites actuelles

- le tournoi se joue uniquement dans le terminal ;
- les équipes et les objets sont générés aléatoirement ;
- aucune sauvegarde de partie n'est prévue ;
- le dépôt ne contient pas encore de tests automatisés.

## Auteur

**Hyacinthe Waboe**

Projet universitaire de Licence 3 MIASHS.

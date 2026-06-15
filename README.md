<h1 align="center">⚔️ Auto-Battler Engine C++</h1>

<p align="center">
  <strong>Des héros, des équipements et un tournoi entièrement automatisé.</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/POO-Polymorphisme-6C63FF?style=for-the-badge" alt="POO">
  <img src="https://img.shields.io/badge/Design_Pattern-Factory-EF8354?style=for-the-badge" alt="Factory">
</p>

## 🎮 Le projet

Ce moteur de combats automatiques a été développé pendant ma **Licence 3 MIASHS** à l'Université Toulouse - Jean Jaurès.

À chaque lancement, le programme crée quatre équipes de trois héros, organise les demi-finales puis la grande finale et raconte tout le tournoi dans le terminal. Les statistiques, les classes et les équipements rendent chaque simulation différente.

## ✨ Ce que le moteur sait faire

- 🎲 générer automatiquement quatre équipes ;
- 🧙 créer six classes : Guerrier, Mage, Archer, Paladin, Assassin et Druide ;
- 📊 attribuer des points de vie, d'attaque, de défense et de vitesse ;
- 💥 appliquer les capacités propres à chaque classe ;
- 🗡️ distribuer aléatoirement des objets améliorant les héros ;
- ⚡ calculer l'initiative à partir de la vitesse ;
- ❤️ soigner les survivants entre les rencontres ;
- 🏆 jouer un tournoi complet jusqu'au champion final.

## 🧠 Ce que j'ai travaillé

| Notion | Mise en pratique |
|---|---|
| **POO** | Classe abstraite commune et spécialisations de héros |
| **Polymorphisme** | Gestion générique des différents combattants |
| **Factory** | Création dynamique et aléatoire des héros |
| **Mémoire** | Pointeurs, allocation dynamique et destructeurs |
| **Organisation** | Interfaces dans `include/`, implémentations dans `src/` |

## 📂 Organisation

```text
.
├── include/          # Fichiers d'en-tête des héros et du moteur
├── src/              # Implémentations et point d'entrée
├── Compile.bat       # Compilation et lancement sous Windows
├── Makefile          # Compilation sous Linux/macOS
└── Rapports_Projet.pdf
```

## 🚀 Lancer le tournoi

### Windows

Avec `g++` disponible dans le `PATH` :

```powershell
.\Compile.bat
```

### Linux ou macOS

```bash
make run
```

Compilation et lancement séparés :

```bash
make
./bin/DungeonBattle
```

Nettoyage :

```bash
make clean
```

## 🚧 Limites actuelles

- le tournoi se joue uniquement dans le terminal ;
- les équipes ne peuvent pas encore être composées manuellement ;
- aucune sauvegarde de partie n'est prévue ;
- le dépôt ne contient pas encore de tests automatisés.

## 👨‍💻 Auteur

**Hyacinthe Waboe**<br>
Projet universitaire de Licence 3 MIASHS.

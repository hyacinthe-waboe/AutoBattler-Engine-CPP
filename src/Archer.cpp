/**
 * @file Archer.cpp
 * @brief Implémentation de l'Archer.
 */

#include "../include/Archer.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Archer::Archer(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 3 pour identifier l'Archer.
 */
int Archer::getClasse() const {
    return 3;
}

/**
 * @brief Calcul les dégâts de l'archer.
 * Règle : Chance : *2 de degats.
 */
int Archer::calculerDegats(const Hero& cible) const {
    
    // 1. Calcul des dégâts de base
    int defCible = cible.getDefense();
    if (defCible == 0) defCible = 1;
    
    int degatsBase = this->attaque - (defCible / 2);
    if (degatsBase < 1) degatsBase = 1;

    int degatsFinal = degatsBase;

    // 2. Gestion du Coup Critique (20% de chance)
    if ((rand() % 100) < 20) {
        degatsFinal = degatsBase * 2;
        cout << "\t" << Color::MAGENTA << "[Archer] " << Color::BLUE << this->nom 
             << Color::MAGENTA << " vise un point vital (Critique) ! "
             << Color::YELLOW << "(Degats: " << degatsBase << " -> " << degatsFinal << ")" << Color::RESET << endl;
    }

    return degatsFinal;
}

/**
 * @brief Gestion de la réception de dégâts avec Esquive.
 * Plus l'archer est rapide, plus il a de chances d'esquiver.
 */
void Archer::perdrePV(int montant) {
    
    // Calcul de chance d'esquive basé sur la vitesse, chance = vitesse (plafonnée à 50% par exemple pour pas être invincible)
    int chanceEsquive = this->vitesse; 
    if (chanceEsquive > 50) chanceEsquive = 50;

    if ((rand() % 100) < chanceEsquive) {
        cout << "\t" << Color::CYAN << "[Archer] " << Color::BLUE << this->nom << Color::CYAN << " esquive l'attaque !" << Color::RESET << endl;

    } else {
        // Si pas d'esquive, comportement normal (appel à la méthode de base via portée Hero::)
        Hero::perdrePV(montant);
    }
}
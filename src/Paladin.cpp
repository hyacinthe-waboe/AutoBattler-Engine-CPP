/**
 * @file Paladin.cpp
 * @brief Implémentation du Paladin.
 */

#include "../include/Paladin.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Paladin::Paladin(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 4 pour identifier le Paladin.
 */
int Paladin::getClasse() const {
    return 4;
}

/**
 * @brief Calcul des dégâts spécifique au Paladin.
 */
int Paladin::calculerDegats(const Hero& cible) const {
    // Attaque normale
    return Hero::calculerDegats(cible);
}
/**
 * @brief Le Paladin réduit les dégâts entrants.
 * Bonus : Il réduit les dégâts de (Defense / 10) + 2.
 */
void Paladin::perdrePV(int montant) {
    // 1. Calcul de la réduction (Armure Divine)
    int reduction = (this->defense / 10) + 2;
    
    int degatsReels = montant - reduction;
    if (degatsReels < 0) degatsReels = 0;
    cout << "\t" << Color::BLUE << "[Paladin] " << this->nom 
         << " utilise Bouclier Divin ! "
         << Color::YELLOW << "(Recu: " << montant << " -> " << degatsReels << ")" << Color::RESET << endl;

    // 2. Application
    this->pv -= degatsReels;
    if (this->pv < 0) this->pv = 0;
}
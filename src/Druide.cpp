/**
 * @file Druide.cpp
 * @brief Implémentation du Druide.
 */

#include "../include/Druide.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Druide::Druide(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 6 pour identifier le Druide.
 */
int Druide::getClasse() const {
    return 6;
}

/**
 * @brief Calcul des dégâts du Druide.
 */
int Druide::calculerDegats(const Hero& cible) const {
    // Dégâts normaux
    return Hero::calculerDegats(cible);
}

/**
 * @brief Régénération Naturelle.
 * Il récupère 5 PV après chaque coup reçu grâce à la nature.
 */
void Druide::perdrePV(int montant) {

    int pvAvantCoup = this->pv;

    Hero::perdrePV(montant);
    
    if (this->pv <= 0) {
        return; // On arrête tout, il est mort.
    }

    int pvApresCoup = this->pv;

    cout << "\t" << Color::CYAN << "[Druide] " << Color::BLUE << this->nom 
         << " encaisse le coup. " 
         << Color::YELLOW << "(PV: " << pvAvantCoup << " -> " << pvApresCoup << ")" << Color::RESET << endl;
    
         // S'il a survécu, la régénération s'active
    int soin = 5;
    if (this->pv + soin > this->pvMax) {
        this->pv = this->pvMax;
    } else {
        this->pv += soin;
    }
    cout << "\t" << Color::GREEN << "[Druide] " << Color::BLUE << this->nom 
    << Color::GREEN << " active sa regeneration. "
    << Color::YELLOW << "(PV: " << pvApresCoup << " -> " << this->pv << ")" << Color::RESET << endl;
}

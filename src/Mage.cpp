/**
 * @file Mage.cpp
 * @brief Implémentation du Mage.
 */

#include "../include/Mage.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Mage::Mage(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 2 pour identifier le Mage.
 */
int Mage::getClasse() const {
    return 2;
}

/**
 * @brief Calcul des dégâts spécifique au Mage.
 * Règle 1 : Ignore 30% de la défense ennemie.
 * Règle 2 : Dégâts variables (utilisation de rand()).
 */
int Mage::calculerDegats(const Hero& cible) const {
    int defReelle = cible.getDefense();
    
    // 1. Mécanique : Ignore 30% de la défense
    int defEffective = defReelle * 0.7;

    cout << "\t" << Color::CYAN << "[Mage] " << Color::BLUE << this->nom 
         << Color::CYAN << " transperce l'armure ! "
         << Color::YELLOW << "(Def. Ennemie: " << defReelle << " -> " << defEffective << ")" << Color::RESET << endl;

    // 2. Calcul avec la défense réduite
    int degats = this->attaque - (defEffective / 2);
    
    // 3. Variation Magique (+/- 20%)
    int variation = (rand() % 41) - 20; 
    int degatsFinal = degats * (100 + variation) / 100;
    if (degatsFinal < 1) degatsFinal = 1;

    return degatsFinal;
}
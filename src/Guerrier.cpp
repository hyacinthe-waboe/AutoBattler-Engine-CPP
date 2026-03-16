/**
 * @file Guerrier.cpp
 * @brief Implémentation du Guerrier.
 */

#include "../include/Guerrier.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Guerrier::Guerrier(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 1 pour identifier le Guerrier.
 */
int Guerrier::getClasse() const {
    return 1;
}

/**
 * @brief Calcul des dégâts spécifique au Guerrier.
 * Règle : +20% de dégâts si PV < 30% des PV Max.
 */
int Guerrier::calculerDegats(const Hero& cible) const {
    
    // 1. Appel de la méthode parent pour la base
    int degatsBase = Hero::calculerDegats(cible);
    int degatsFinal = degatsBase;

    // 2. Condition : PV < 30%
    if (this->pv < (this->pvMax * 0.3)) {
        degatsFinal = (int)(degatsBase * 1.2); 
        
        cout << "\t" << Color::RED << "[Guerrier] " << Color::BLUE << this->nom 
             << Color::RED << " entre en RAGE ! "
             << Color::YELLOW << "(Degats: " << degatsBase << " -> " << degatsFinal << ")" << Color::RESET << endl;
    }

    return degatsFinal;
}

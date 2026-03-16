/**
 * @file Assassin.cpp
 * @brief Implémentation de l'Assassin.
 */

#include "../include/Assassin.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur. Appelle le constructeur de Hero.
 */
Assassin::Assassin(string nom, int pv, int attaque, int defense, int vitesse)
    : Hero(nom, pv, attaque, defense, vitesse) {
}

/**
 * @brief Retourne 5 pour identifier l'Assasin.
 */
int Assassin::getClasse() const {
    return 5;
}

/**
 * @brief Calcul des dégâts de l'Assassin.
 * Règle : Chance : Ignore 50% de la défense + 20% dégâts bonus
 */
int Assassin::calculerDegats(const Hero& cible) const {
    
    // Calcul de base
    int defCible = cible.getDefense();
    if (defCible == 0) defCible = 1;
    
    int degatsBase = this->attaque - (defCible / 2);
    if (degatsBase < 1) degatsBase = 1;
    
    int degatsFinal = degatsBase;

    // Chance de Backstab (30%)
    if ((rand() % 100) < 30) { 
        int bonus = (int)(degatsBase * 0.5); // +50%
        degatsFinal += bonus;
        cout << "\t" << Color::RED << "[Assassin] " << Color::BLUE << this->nom 
             << Color::RED << " attaque sournoise ! " 
             << Color::YELLOW << "(Degats: " << degatsBase << " -> " << degatsFinal << ")" << Color::RESET << endl;
    }

    return degatsFinal;
}
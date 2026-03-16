/**
 * @file Mage.hpp
 * @brief Classe dérivée représentant un Mage.
 */

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Hero.hpp"

/**
 * @class Mage
 * @brief Combattant magique capable de percer la défense adverse.
 */
class Mage : public Hero {
public:
    /**
     * @brief Constructeur de Mage.
     */
    Mage(string nom, int pv, int attaque, int defense, int vitesse);

    int getClasse() const override;

    /**
     * @brief Calcule les dégâts en ignorant une partie de la défense.
     * Ajoute une variation aléatoire aux dégâts.
     */
    int calculerDegats(const Hero& cible) const override;
};

#endif
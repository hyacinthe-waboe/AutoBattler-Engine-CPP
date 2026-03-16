/**
 * @file Assassin.hpp
 * @brief Classe dérivée représentant un Assassin.
 */

#ifndef ASSASSIN_HPP
#define ASSASSIN_HPP

#include "Hero.hpp"

/**
 * @class Assassin
 * @brief Combattant fourbe, spécialiste des dégâts explosifs sous conditions.
 */
class Assassin : public Hero {
public:
    /**
     * @brief Constructeur de l'Assassin.
     */
    Assassin(string nom, int pv, int attaque, int defense, int vitesse);

    int getClasse() const override;

    /**
     * @brief Attaque sournoise.
     * Bonus massif si la cible a 100% de ses PV (Surprise).
     */
    int calculerDegats(const Hero& cible) const override;
};

#endif
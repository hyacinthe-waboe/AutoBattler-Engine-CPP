/**
 * @file Guerrier.hpp
 * @brief Classe dérivée représentant un Guerrier.
 */

#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include "Hero.hpp"

/**
 * @class Guerrier
 * @brief Combattant résistant dont les dégâts augmentent lorsqu'il est blessé.
 * Hérite publiquement de Hero.
 */
class Guerrier : public Hero {
public:
    /**
     * @brief Constructeur de Guerrier.
     */
    Guerrier(string nom, int pv, int attaque, int defense, int vitesse);
    
    int getClasse() const override;

    /**
     * @brief Calcule les dégâts avec le bonus de rage (PV < 30%).
     * Redéfinition de la méthode de Hero.
     */
    int calculerDegats(const Hero& cible) const override;
};

#endif
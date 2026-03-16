/**
 * @file Paladin.hpp
 * @brief Classe dérivée représentant un Paladin (Bonus).
 */

#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "Hero.hpp"

/**
 * @class Paladin
 * @brief Héros défensif (Tank) qui réduit les dégâts reçus.
 */
class Paladin : public Hero {
public:
    /**
     * @brief Constructeur de Paladin.
     */
    Paladin(string nom, int pv, int attaque, int defense, int vitesse);

    int getClasse() const override;

    /**
     * @brief Le Paladin tape normalement (pas de bonus d'attaque particulier).
     */
    int calculerDegats(const Hero& cible) const override;

    /**
     * @brief Spécial : Réduit les dégâts reçus d'un montant fixe grâce à son armure.
     * Redéfinition de la méthode virtuelle.
     */
    void perdrePV(int montant) override;
};

#endif
/**
 * @file Druide.hpp
 * @brief Classe dérivée représentant un Druide.
 */

#ifndef DRUIDE_HPP
#define DRUIDE_HPP

#include "Hero.hpp"

/**
 * @class Druide
 * @brief Combattant de la nature, capable de se régénérer en attaquant.
 */
class Druide : public Hero {
public:
    /**
     * @brief Constructeur du Druide.
     */
    Druide(string nom, int pv, int attaque, int defense, int vitesse);

    int getClasse() const override;

    /**
     * @brief Frappe naturelle.
     * En plus d'infliger des dégâts, le Druide récupère des PV.
     */
    int calculerDegats(const Hero& cible) const override;

    /**
     * @brief Peau d'Ecorce.
     * A chaque coup reçu, le Druide a une chance de se soigner un peu (Regen naturelle).
     */
    void perdrePV(int montant) override;
};

#endif 
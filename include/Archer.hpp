/**
 * @file Archer.hpp
 * @brief Classe dérivée représentant un Archer.
 */

#ifndef ARCHER_HPP
#define ARCHER_HPP

#include "Hero.hpp"

/**
 * @class Archer
 * @brief Combattant rapide, capable de coups critiques et d'esquives.
 */
class Archer : public Hero {
public:
    /**
     * @brief Constructeur de Archer.
     */
    Archer(string nom, int pv, int attaque, int defense, int vitesse);

    int getClasse() const override;

    /**
     * @brief Possibilité de faire un coup critique (dégâts doublés).
     */
    int calculerDegats(const Hero& cible) const override;

    /**
     * @brief Redéfinition pour gérer l'esquive.
     * L'Archer a une chance d'ignorer totalement les dégâts reçus.
     */
    void perdrePV(int montant) override;
};

#endif 
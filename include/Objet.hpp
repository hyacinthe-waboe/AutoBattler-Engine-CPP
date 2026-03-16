/**
 * @file Objet.hpp
 * @brief Définition de la classe Objet (Bonus).
 */

#ifndef OBJET_HPP
#define OBJET_HPP

#include "Utils.hpp"

/**
 * @class Objet
 * @brief Représente un équipement (Anneau, Amulette, Épée...) apportant des bonus.
 */
class Objet {
private:
    string nom;         /**< Nom de l'objet */
    int bonusAttaque;   /**< Bonus ajouté à l'attaque du porteur */
    int bonusDefense;   /**< Bonus ajouté à la défense du porteur */
    int bonusVitesse;   /**< Bonus ajouté à la vitesse du porteur */

public:
    /**
     * @brief Constructeur.
     * @param nom Nom de l'objet.
     * @param atk Bonus d'attaque.
     * @param def Bonus de défense.
     * @param vit Bonus de vitesse.
     */
    Objet(string nom, int atk, int def, int vit);

    /**
     * @brief Destructeur.
     */
    ~Objet();

    /**
     * @brief Affiche les bonus de l'objet.
     */
    void afficherInfos() const;

    // Getters
    string getNom() const;
    int getBonusAttaque() const;
    int getBonusDefense() const;
    int getBonusVitesse() const;
};

#endif
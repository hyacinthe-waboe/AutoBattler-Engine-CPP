/**
 * @file Hero.hpp
 * @brief Définition de la classe abstraite Hero.
 */

#ifndef HERO_HPP
#define HERO_HPP

#include "Utils.hpp"
#include "Objet.hpp"

/**
 * @class Hero
 * @brief Classe de base abstraite représentant un personnage du jeu.
 * Elle contient les attributs communs et définit les méthodes virtuelles
 * que les classes dérivées devront implémenter.
 */
class Hero {
protected:
    // Attributs protégés pour être accessibles par les classes filles (Guerrier, Mage, Archer)
    string nom;     /**< Nom du héros */
    int pv;         /**< Points de vie actuels */
    int pvMax;      /**< Points de vie maximum (utile pour le soin) */
    int attaque;    /**< Valeur d'attaque */
    int defense;    /**< Valeur de défense */
    int vitesse;    /**< Vitesse déterminant l'initiative */
    Objet* equipement;    /**< Le héros possède un pointeur vers un objet */

public:
    /**
     * @brief Constructeur de la classe Hero.
     * @param nom Le nom du héros.
     * @param pv Les points de vie initiaux.
     * @param attaque La valeur d'attaque.
     * @param defense La valeur de défense.
     * @param vitesse La valeur de vitesse.
     */
    Hero(string nom, int pv, int attaque, int defense, int vitesse);

    /**
     * @brief Destructeur virtuel.
     * Essentiel pour que le destructeur des classes dérivées soit appelé
     * lors de la suppression d'un pointeur de type Hero*.
     */
    virtual ~Hero();

    /**
     * @brief Affiche les statistiques du héros.
     */
    void afficherStats() const;

    /**
     * @brief Récupère l'identifiant de la classe du héros.
     * Méthode virtuelle pure (= 0) rendant la classe Hero abstraite.
     * @return Un entier représentant le type de classe.
     */
    virtual int getClasse() const = 0;

    /**
     * @brief Calcule les dégâts infligés à une cible.
     * Méthode virtuelle destinée à être redéfinie par les classes filles.
     * @param cible Le héros qui subit l'attaque.
     * @return Le montant des dégâts.
     */
    virtual int calculerDegats(const Hero& cible) const;

    /**
     * @brief Gestion de la perte de points de vie.
     * Méthode virtuelle.
     * @param montant Le nombre de PV à retirer.
     */
    virtual void perdrePV(int montant);

    /**
     * @brief Vérifie si le héros est toujours en vie.
     * @return Vrai si pv > 0, Faux sinon.
     */
    bool estVivant() const;

    /**
     * @brief Soigne le héros en remettant ses PV au maximum.
     * Correspond à la règle : "Après chaque combat, le héro gagnant regagne ses PV initiaux".
     */
    void soigner();

    /**
     * @brief Equipe un objet au héros.
     * Si le héros avait déjà un objet, l'ancien est supprimé (remplacé).
     * @param o Pointeur vers le nouvel objet.
     */
    void equiper(Objet* o);

    // Accesseurs (Getters) nécessaires pour la mécanique de jeu
    int getVitesse() const;
    int getDefense() const;
    int getAttaque() const;
    string getNom() const;
    int getPV() const;
};

#endif
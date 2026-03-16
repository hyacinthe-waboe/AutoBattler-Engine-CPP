/**
 * @file Joueur.hpp
 * @brief Définition de la classe Joueur.
 */

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Utils.hpp"
#include "Hero.hpp"
#include "HeroFactory.hpp"

/**
 * @class Joueur
 * @brief Gère un joueur et son équipe de héros.
 * Responsable de l'allocation et de la libération de la mémoire de ses héros.
 */
class Joueur {
private:
    string nom;             /**< Nom du joueur */
    vector<Hero*> equipe;   /**< Liste des héros (stockés par pointeurs)  */

public:
    /**
     * @brief Constructeur.
     * @param nom Le nom du joueur.
     */
    Joueur(string nom);

    /**
     * @brief Destructeur.
     * Libère la mémoire de tous les héros de l'équipe (delete).
     */
    ~Joueur();

    /**
     * @brief Ajoute un héros à l'équipe.
     * @param h Pointeur vers le héros à ajouter.
     */
    void ajouterHero(Hero* h);

    /**
     * @brief Remplit l'équipe aléatoirement.
     * Génère jusqu'à nb héros via la Factory.
     * @param nb Nombre de héros à générer.
     */
    void genererEquipeAleatoire(int nb);

    /**
     * @brief Vérifie s'il reste au moins un héros en vie dans l'équipe.
     * Condition de victoire/défaite.
     * @return true si au moins un héros a PV > 0.
     */
    bool aDesHerosVivants() const;

    /**
     * @brief Soigne tous les héros de l'équipe.
     * Règle : "Après chaque combat, le héro gagnant regagne ses PV initiaux".
     * Ici on soigne toute l'équipe pour simplifier la gestion entre les rounds.
     */
    void soignerEquipe();

    /**
     * @brief Affiche l'état de l'équipe.
     */
    void afficherEquipe() const;

    /**
     * @brief Accès à l'équipe (pour le moteur de combat).
     * @return Référence constante vers le vecteur de héros.
     */
    const vector<Hero*>& getEquipe() const;

    /**
     * @brief Accès au nom du joueur.
     */
    string getNom() const;
};

#endif
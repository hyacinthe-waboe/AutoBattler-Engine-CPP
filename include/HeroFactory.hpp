/**
 * @file HeroFactory.hpp
 * @brief Déclaration des fonctions utilitaires pour la création de héros.
 */

#ifndef HEROFACTORY_HPP
#define HEROFACTORY_HPP

#include "Hero.hpp"

/**
 * @brief Génère un héros aléatoire (Guerrier, Mage ou Archer).
 * * Cette fonction choisit aléatoirement un type de classe, génère un nom,
 * et calcule des statistiques aléatoires entre 50 et 100.
 * Elle prend en compte la statistique principale de chaque classe 
 * (Défense pour Guerrier, Attaque pour Mage, Vitesse pour Archer) 
 * en leur attribuant une valeur plus élevée.
 * * @return Un pointeur vers le nouvel objet Hero alloué dynamiquement (Hero*).
 * L'appelant est responsable de la libération de la mémoire (delete).
 */
Hero* genererHeroAleatoire();

#endif
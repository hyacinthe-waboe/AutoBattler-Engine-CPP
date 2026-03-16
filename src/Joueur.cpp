/**
 * @file Joueur.cpp
 * @brief Implémentation de la gestion du joueur.
 */

#include "../include/Joueur.hpp"

/**
 * @brief Constructeur simple.
 */
Joueur::Joueur(string nom) : nom(nom) {
}

/**
 * @brief Destructeur : Nettoyage de la mémoire.
 * Parcourt le vecteur et supprime chaque héros alloué dynamiquement.
 * C'est crucial car les héros sont créés avec 'new'.
 */
Joueur::~Joueur() {
    cout << "Destruction du joueur " << nom << " et de ses heros..." << endl;
    for (size_t i = 0; i < equipe.size(); ++i) {
        delete equipe[i];
    }
    equipe.clear();
}

/**
 * @brief Ajoute un pointeur de héros au vecteur.
 */
void Joueur::ajouterHero(Hero* h) {
    if (equipe.size() < 6) { // Limite de 6 héros
        equipe.push_back(h);
    } else {
        cout << "Equipe pleine ! Impossible d'ajouter " << h->getNom() << endl;
        delete h; 
    }
}

/**
 * @brief Utilise la Factory pour remplir l'équipe.
 */
void Joueur::genererEquipeAleatoire(int nb) {
    for (int i = 0; i < nb; ++i) {
        Hero* h = genererHeroAleatoire();
        ajouterHero(h);
    }
}

/**
 * @brief Vérifie la défaite.
 * Le joueur perd s'il n'a plus de héros vivants.
 */
bool Joueur::aDesHerosVivants() const {
    for (size_t i = 0; i < equipe.size(); ++i) {
        if (equipe[i]->estVivant()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Remet les PV au max pour tout le monde.
 */
void Joueur::soignerEquipe() {
    for (size_t i = 0; i < equipe.size(); ++i) {
        equipe[i]->soigner();
    }
}

/**
 * @brief Affiche la liste des héros.
 */
void Joueur::afficherEquipe() const {
    cout << "Equipe de " << nom << " :" << endl;
    for (size_t i = 0; i < equipe.size(); ++i) {
        cout << " - ";
        equipe[i]->afficherStats();
    }
}

/**
 * @brief Getter pour l'équipe.
 */
const vector<Hero*>& Joueur::getEquipe() const {
    return equipe;
}

/**
 * @brief Getter pour le nom.
 */
string Joueur::getNom() const {
    return nom;
}
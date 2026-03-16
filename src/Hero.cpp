/**
 * @file Hero.cpp
 * @brief Implémentation des méthodes de la classe Hero.
 */

#include "../include/Hero.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Constructeur de Hero.
 * Utilise la liste d'initialisation pour affecter les valeurs.
 * pvMax est initialisé avec la valeur de pv.
 */
Hero::Hero(string nom, int pv, int attaque, int defense, int vitesse)
    : nom(nom), pv(pv), pvMax(pv), attaque(attaque), defense(defense), vitesse(vitesse) {
        this->equipement = nullptr; // Pas d'équipement au départ
}

/**
 * @brief Destructeur de Hero.
 * Nettoyage de la mémoire de l'objet si il existe
 */
Hero::~Hero() {
    
    if (this->equipement != nullptr) {
        delete this->equipement;
        this->equipement = nullptr;
    }
}

/**
 * @brief Affiche les statistiques du héros sur la sortie standard.
 */
void Hero::afficherStats() const {
    cout << nom << " (PV: " << pv << "/" << pvMax 
         << ", Atq: " << getAttaque() 
         << ", Def: " << getDefense() 
         << ", Vit: " << getVitesse() << ")";
    
    //Affichage de l'objet s'il existe
    if (equipement != nullptr) {
        equipement->afficherInfos();
    }
    cout << endl;
}

/**
 * @brief Calcule les dégâts de base.
 * Formule basique : Attaque / (Défense / 2).
 * Cette méthode sera généralement redéfinie par les classes filles.
 */
int Hero::calculerDegats(const Hero& cible) const {
    // On évite la division par zéro
    int def = cible.getDefense();
    if (def == 0) def = 1;
    
    // Formule de base pour calculer les degats
    int degats = this->attaque - (def / 2);
    
    if (degats < 1) degats = 1;
    return degats;
}

/**
 * @brief Equipe un objet.
 * Gère la mémoire de l'ancien objet s'il y en avait un.
 */
void Hero::equiper(Objet* o) {
    if (this->equipement != nullptr) {
        delete this->equipement;
    }
    this->equipement = o;
}

/**
 * @brief Retire des points de vie au héros.
 * Empêche les PV de descendre en dessous de 0.
 */
void Hero::perdrePV(int montant) {
    this->pv -= montant;
    if (this->pv < 0) {
        this->pv = 0;
    }
}

/**
 * @brief Vérifie si le héros est vivant.
 */
bool Hero::estVivant() const {
    return this->pv > 0;
}

/**
 * @brief Restaure les PV au maximum initial.
 */
void Hero::soigner() {
    this->pv = this->pvMax;
}



// Accesseurs

int Hero::getVitesse() const {
    int bonus = (equipement != nullptr) ? equipement->getBonusVitesse() : 0;
    return vitesse + bonus;
}

int Hero::getDefense() const {
    int bonus = (equipement != nullptr) ? equipement->getBonusDefense() : 0;
    return defense + bonus;
}

int Hero::getAttaque() const {
    int bonus = (equipement != nullptr) ? equipement->getBonusAttaque() : 0;
    return attaque + bonus;
}

string Hero::getNom() const { return nom; }
int Hero::getPV() const { return pv; }
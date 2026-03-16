/**
 * @file Objet.cpp
 * @brief Implémentation de la classe Objet.
 */

#include "../include/Objet.hpp"
#include "../include/ConsoleColor.hpp"

Objet::Objet(string nom, int atk, int def, int vit)
    : nom(nom), bonusAttaque(atk), bonusDefense(def), bonusVitesse(vit) {
}

Objet::~Objet() {
}

void Objet::afficherInfos() const {
    cout << Color::YELLOW << " [" << nom << " (+Atk:" << bonusAttaque 
         << ", +Def:" << bonusDefense << ", +Vit:" << bonusVitesse << ")]" << Color::RESET;
}

string Objet::getNom() const { return nom; }
int Objet::getBonusAttaque() const { return bonusAttaque; }
int Objet::getBonusDefense() const { return bonusDefense; }
int Objet::getBonusVitesse() const { return bonusVitesse; }
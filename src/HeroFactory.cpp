/**
 * @file HeroFactory.cpp
 * @brief Implémentation de la génération aléatoire de héros.
 */

#include "../include/HeroFactory.hpp"
#include "../include/Guerrier.hpp"
#include "../include/Mage.hpp"
#include "../include/Archer.hpp"
#include "../include/Paladin.hpp"
#include "../include/Assassin.hpp" 
#include "../include/Druide.hpp"   
#include "../include/Utils.hpp"
#include "../include/Objet.hpp"

/**
 * @brief Génère un entier aléatoire dans un intervalle donné.
 * Helper local pour simplifier le code.
 * @param min Valeur minimale.
 * @param max Valeur maximale.
 * @return Entier aléatoire entre min et max inclus.
 */
int randomRange(int min, int max) {
    return min + (rand() % (max - min + 1));
}

/**
 * @brief Implémentation de la génération de héros.
 * Choisit un type au hasard et génère des stats favorisant la stat principale.
 */
Hero* genererHeroAleatoire() {
    
    // 1. Tirage au sort du type de héros (0 à 5)
    int type = rand() % 6;
    
    // Génération d'un nom générique (ex: "Hero_42")
    static int compteur = 1;
    string nom = "Hero_" + to_string(compteur++);

    // 2. Génération des stats de base [50, 100]
    int pv = randomRange(50, 100);
    int atk = randomRange(50, 80);
    int def = randomRange(50, 80);
    int vit = randomRange(50, 80);

    Hero* nouveauHero = nullptr;

    // 3. Spécialisation et Instanciation selon le type
    switch (type) {
        case 0: // Guerrier
            // Stat principale : Défense
            def = randomRange(80, 100);
            nouveauHero = new Guerrier("Guerrier_" + nom, pv, atk, def, vit);
            break;

        case 1: // Mage
            // Stat principale : Attaque
            atk = randomRange(80, 100);
            nouveauHero = new Mage("Mage_" + nom, pv, atk, def, vit);
            break;

        case 2: // Archer
            // Stat principale : Vitesse
            vit = randomRange(80, 100);
            nouveauHero = new Archer("Archer_" + nom, pv, atk, def, vit);
            break;
        
        case 3: // Paladin (Bonus)
            // Stat principale : Défense et PV (Tank)
            def = randomRange(80, 100);
            pv = randomRange(80, 120); 
            nouveauHero = new Paladin("Paladin_" + nom, pv, atk, def, vit);
            break;

        case 4: // Assassin (Bonus)
            // Stats : Très rapide et fort, mais très fragile (Glass Cannon)
            atk = randomRange(90, 110);
            vit = randomRange(90, 110);
            pv = randomRange(40, 60);
            def = randomRange(20, 40); 
            nouveauHero = new Assassin("Assassin_" + nom, pv, atk, def, vit);
            break;

        case 5: // Druide (Bonus)
            // Stats : Résistant (PV) pour profiter de la régénération
            pv = randomRange(90, 110);
            // Stats équilibrées pour le reste
            nouveauHero = new Druide("Druide_" + nom, pv, atk, def, vit);
            break;
    }

    // 4. Génération aléatoire d'un objet (Bonus)
    if (rand() % 3 == 0) { // 1 chance sur 3 d'avoir un objet
        Objet* loot = nullptr;
        int typeObjet = rand() % 3;
        
        switch (typeObjet) {
            case 0: // Offensif
                loot = new Objet("Epee de Feu", 15, 0, 0);
                break;
            case 1: // Défensif
                loot = new Objet("Bouclier Runique", 0, 15, 0);
                break;
            case 2: // Vitesse
                loot = new Objet("Bottes de Hermes", 0, 0, 15);
                break;
        }
        
        // On équipe l'objet au héros nouvellement créé
        if (nouveauHero != nullptr && loot != nullptr) {
            nouveauHero->equiper(loot);
        }
    }

    return nouveauHero;
}
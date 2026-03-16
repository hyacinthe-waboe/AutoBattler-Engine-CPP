/**
 * @file main.cpp
 * @brief Point d'entrée du programme, gestion des combats et du tournoi.
 */

#include "../include/Utils.hpp"
#include "../include/Hero.hpp"
#include "../include/Joueur.hpp"
#include "../include/ConsoleColor.hpp"

/**
 * @brief Simule un combat singulier entre deux héros.
 * Règle :
 * 1. Le plus rapide commence (probabilité).
 * 2. Attaque tour par tour.
 * 3. S'arrête quand PV <= 0.
 * @param h1 Pointeur vers le premier héros.
 * @param h2 Pointeur vers le second héros.
 * @return 1 si h1 gagne, 2 si h2 gagne.
 */
int combat(Hero* h1, Hero* h2) {
   
    cout << endl;
    cout << Color::YELLOW << "---------------------------------------" << endl;
    cout << "DUEL : " << h1->getNom() << " VS " << h2->getNom() << Color::RESET << endl;
    cout << Color::YELLOW << "---------------------------------------" << Color::RESET << endl;
    cout << endl;

    // Déterminer qui commence via la vitesse
    int initiative1 = h1->getVitesse() * (rand() % 10 + 1);
    int initiative2 = h2->getVitesse() * (rand() % 10 + 1);

    Hero* attaquant = (initiative1 >= initiative2) ? h1 : h2;
    Hero* defenseur = (initiative1 >= initiative2) ? h2 : h1;

    cout << "\t" << Color::CYAN << ">>> " << attaquant->getNom() << " est plus rapide et attaque en premier !\n" << Color::RESET << endl;

    while (h1->estVivant() && h2->estVivant()) {
        
        cout << "\t" << attaquant->getNom() << " prepare son attaque..." << endl; 

        // CALCUL DES DEGATS BRUTS (Action)
        // C'est ici que l'Archer va crier "COUP CRITIQUE" ou le Guerrier "RAGE"
        int degatsBruts = attaquant->calculerDegats(*defenseur);

        // APPLICATION ET DEFENSE (Réaction)
        // On regarde les PV avant le coup
        int pvAvant = defenseur->getPV();

        // Le défenseur prend le coup (C'est ici que le Paladin dit "BLOQUE" ou l'Archer "ESQUIVE" par exemple)
        defenseur->perdrePV(degatsBruts);

        // On regarde les PV après le coup
        int pvApres = defenseur->getPV();

        // RESULTAT FINAL
        // On calcule ce qui a été RÉELLEMENT infligé
        int degatsReels = pvAvant - pvApres;

        cout << "\t" << Color::BLUE << attaquant->getNom() << Color::RESET 
             << " inflige " << Color::RED << degatsReels << " degats" << Color::RESET 
             << " a " << Color::BLUE << defenseur->getNom() << Color::RESET 
             << " (PV restants: " << Color::GREEN << defenseur->getPV() << Color::RESET << ")" << endl;

        cout << endl; 

        if (!defenseur->estVivant()) break;

        // Echange des rôles
        Hero* temp = attaquant;
        attaquant = defenseur;
        defenseur = temp;
    }

    cout << endl;
    if (h1->estVivant()) {
        cout << "\t" << Color::YELLOW << "VAINQUEUR : " << h1->getNom() << Color::RESET << endl;
        cout << Color::YELLOW << "---------------------------------------" << Color::RESET << endl;
        return 1;
    } else {
        cout << "\t" << Color::YELLOW << "VAINQUEUR : " << h2->getNom() << Color::RESET << endl;
        cout << Color::YELLOW << "---------------------------------------" << Color::RESET << endl;
        return 2;
    }
}

/**
 * @brief Gère l'affrontement entre deux équipes.
 * Respecte la signature demandée dans le PDF.
 * @param j1 Le premier joueur.
 * @param j2 Le second joueur.
 * @return int 1 si j1 gagne, 2 si j2 gagne.
 */
int combatEquipes(Joueur& j1, Joueur& j2) {

    cout << "\n\n";
    cout << Color::MAGENTA << "==========================================================" << endl;
    cout << "   GUERRE DES EQUIPES : " << j1.getNom() << " VS " << j2.getNom() << endl;
    cout << "==========================================================" << Color::RESET << endl;
    
    const vector<Hero*>& equipe1 = j1.getEquipe();
    const vector<Hero*>& equipe2 = j2.getEquipe();

    size_t index1 = 0; 
    size_t index2 = 0;

    // Tant que les deux joueurs ont encore des héros disponibles
    while (index1 < equipe1.size() && index2 < equipe2.size()) {
        Hero* combattant1 = equipe1[index1];
        Hero* combattant2 = equipe2[index2];

        // Lancement du duel
        int resultat = combat(combattant1, combattant2);

        if (resultat == 1) {
            // J1 gagne : son héros se soigne
            combattant1->soigner();
            cout << "\t" << Color::GREEN << "[+] " << combattant1->getNom() << " recupere ses PV." << Color::RESET << endl;
            // J2 passe au héros suivant (le précédent est mort)
            index2++;
        } else {
            // J2 gagne : son héros se soigne
            combattant2->soigner();
            cout << "\t" << Color::GREEN << "[+] " << combattant2->getNom() << " recupere ses PV." << Color::RESET << endl;
            // J1 passe au héros suivant
            index1++;
        }
    }

    cout << "\n" << Color::MAGENTA << "--- FIN DE LA RENCONTRE ---" << Color::RESET << endl;
    if (j1.aDesHerosVivants()) {
        cout << Color::YELLOW << "VICTOIRE DE L'EQUIPE " << j1.getNom() << " !!!\n" << Color::RESET << endl;
        // On soigne toute l'équipe gagnante pour le prochain tour du tournoi
        j1.soignerEquipe(); 
        return 1;
    } else {
        cout << Color::YELLOW << "VICTOIRE DE L'EQUIPE " << j2.getNom() << " !!!\n" << Color::RESET << endl;
        j2.soignerEquipe();
        return 2;
    }
}

/**
 * @brief Organise un tournoi à 4 joueurs (Bonus).
 * Simule les demi-finales puis la finale.
 */
void lancerTournoi() {
    cout << Color::RED << "#########################################" << endl;
    cout << "#           GRAND TOURNOI               #" << endl;
    cout << "#########################################" << Color::RESET << endl;

    // 1. Création des 4 participants
    Joueur j1("Joueur A"); j1.genererEquipeAleatoire(3);
    Joueur j2("Joueur B"); j2.genererEquipeAleatoire(3);
    Joueur j3("Joueur C"); j3.genererEquipeAleatoire(3);
    Joueur j4("Joueur D"); j4.genererEquipeAleatoire(3);

    cout << "\n" << Color::CYAN << "--- PRESENTATION DES EQUIPES ---" << Color::RESET << endl;
    j1.afficherEquipe(); cout << endl;
    j2.afficherEquipe(); cout << endl;
    j3.afficherEquipe(); cout << endl;
    j4.afficherEquipe(); cout << endl;

    cout << Color::CYAN << "--------------------------------\n" << Color::RESET;
    cout << "Appuyez sur Entree pour commencer le tournoi (DEMI-FINALE 1)...";
    cin.ignore();

    // DEMI-FINALE 1
    cout << "\n\n" << Color::YELLOW << " >>> DEMI-FINALE 1 <<< " << Color::RESET;
    Joueur* gagnant1 = nullptr;
    if (combatEquipes(j1, j2) == 1) gagnant1 = &j1;
    else gagnant1 = &j2;
    
    cout << Color::CYAN << "--------------------------------\n" << Color::RESET;
    cout << "Appuyez sur Entree pour continuer le tournoi (DEMI-FINALE 2)...";
    cin.ignore();

    // DEMI-FINALE 2
    cout << "\n\n" << Color::YELLOW << " >>> DEMI-FINALE 2 <<< " << Color::RESET;
    Joueur* gagnant2 = nullptr;
    if (combatEquipes(j3, j4) == 1) gagnant2 = &j3;
    else gagnant2 = &j4;

    cout << Color::CYAN << "--------------------------------\n" << Color::RESET;
    cout << "Appuyez sur Entree pour commencer la grande finale..." << endl;
    cin.ignore();

    // FINALE
    cout << "\n\n\n";
    cout << Color::RED << "#########################################" << endl;
    cout << "            LA GRANDE FINALE             " << endl;
    cout << "#########################################" << Color::RESET << endl;
    
    cout << "Opposant les vainqueurs : " << gagnant1->getNom() << " VS " << gagnant2->getNom() << endl;


    Joueur* champion = nullptr;
    if (combatEquipes(*gagnant1, *gagnant2) == 1) champion = gagnant1;
    else champion = gagnant2;

    cout << "\n\n" << Color::MAGENTA << "*************************************************" << endl;
    cout << "   LE GRAND CHAMPION DU TOURNOI EST : " << champion->getNom() << endl;
    cout << "*************************************************" << Color::RESET << endl;
}

/**
 * @brief Fonction principale.
 * Initialise la graine aléatoire et lance le mode tournoi.
 */
int main() {
    // Initialisation de la graine aléatoire
    srand(time(0));
    lancerTournoi();

    return 0;
}
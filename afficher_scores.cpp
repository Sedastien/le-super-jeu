#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include <Mmsystem.h>
#include "IA.h"
#include "afficher_scores.h"

using namespace std;

void afficher_scores(string nom_heros, string nom_allie, bool A_gagne, int nb_attaque, int nb_ame_arme,
                int nb_soigne, int nb_tours, int score_total, int nb_attaque_a, int nb_ame_arme_a, int nb_soigne_a, int nb_aide_h)
{
    PlaySound("musiques\\fin.WAV", NULL, SND_FILENAME | SND_ASYNC );
    cout << endl;

    cout << "                   MERCI D'AVOIR JOUE " << nom_heros << " !" << endl << endl << endl;
    cout << "   VOUS VOUS ETES SOIGNE           : " << nb_soigne << " FOIS " << endl;
    cout << "   VOUS AVEZ AMELIORER VOTRE ARME  : " << nb_ame_arme << " FOIS" << endl;
    cout << "   VOUS AVEZ ATTAQUE               : " << nb_attaque << " FOIS" << endl;
    cout << "   VOUS AVEZ FINI EN               : " << nb_tours << " TOURS" << endl;
    cout << "   VOTRE SCORE TOTAL EST DE        : " << score_total << " POINTS !" << endl << endl;
    cout << "   ------------------------------------------------------ " << endl << endl;
    cout << "                       " << nom_allie << endl << endl;
    cout << "   S'EST SOIGNE                    : " << nb_soigne_a << " FOIS " << endl;
    cout << "   A AMELIORE SON ATTAQUE          : " << nb_ame_arme_a << " FOIS " << endl;
    cout << "   A ATTAQUE                       : " << nb_attaque_a << " FOIS " << endl;
    cout << "   A AIDE " << nom_heros << "      : " << nb_aide_h << " FOIS " << endl << endl;
}

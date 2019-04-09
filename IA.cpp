#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "IA.h"

using namespace std;

int scores_actions[3];
int types_actions[3];

int choix_action(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA,
                  int vie_allie_1, int attaque_allie_1, int attaque_allie_2, int vie_allie_2,
                  int vie_ennemi2, int attaque_ennemi2)
{
    int attaque_adversaire_copie = attaque_adversaire;
    int vie_adversaire_copie = vie_adversaire;
    int attaque_IA_copie = attaque_IA;
    int vie_IA_copie = vie_IA;
    int i, j;
    int meilleure_action_possible_IA(0);
    ///int meilleure_action_possible_adversaire(0);
    int choix_action_actuelle(0);
    int actions_possibles(5);

    ///cout << "**************************************" << endl;

    for(i=0;i<actions_possibles;i++)
    {
        scores_actions[i] = evaluation_action(attaque_adversaire_copie, vie_adversaire_copie,
                                              attaque_IA_copie, vie_IA_copie, i, 1, vie_allie_1, attaque_allie_1,
                                              vie_allie_2, attaque_allie_2, vie_ennemi2, attaque_ennemi2);
        types_actions[i] = i;
        ///cout << "SCORE POUR L'ACTION  " << i << " : " << scores_actions[i] << endl;
    }

        /**cout << "Vie actuelle IA       : " << vie_IA << endl;
        cout << "Attaque actuelle IA   : " << attaque_IA << endl;
        cout << "Vie de l'ADVERSAIRE   : " << vie_adversaire << endl;
        cout << "Attaque de Adversaire : " << attaque_adversaire << endl;

    cout << "**************************************" << endl << endl;*/

    int max = 0;

    for(j=0;j<actions_possibles;j++)
    {
        if(scores_actions[j] > max)
        {
            max = scores_actions[j] ;
            choix_action_actuelle = j ;
        }
    }

    return choix_action_actuelle;
}


/**int choix_action_adversaire(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA)
{

}*/

int evaluation_action(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA, int action, int joueur,
                      int vie_allie_1, int attaque_allie_1, int vie_allie_2, int attaque_allie_2,
                      int vie_ennemi2, int attaque_ennemi2)
{
    int mon_attaque(0);
    int ma_vie(0);
    int attaque_ennemi(0);
    int vie_ennemi(0);
    int score_situation(0);

    if(joueur == 1)
    {
        mon_attaque = attaque_IA;
        ma_vie = vie_IA;
        attaque_ennemi = attaque_adversaire;
        vie_ennemi = vie_adversaire;
    }
    /*else
    {
        mon_attaque = attaque_adversaire;
        ma_vie = vie_adversaire;
    }*/

    switch(action)
    {
        case 0: ///SE SOIGNER
            {
                if(ma_vie <= attaque_ennemi)
                {
                    score_situation++;
                }
                if(ma_vie <= attaque_ennemi+10)
                {
                    score_situation++;
                }
                if(ma_vie+10 <= attaque_ennemi)
                {
                    score_situation++;
                }
                if(ma_vie - attaque_ennemi <= 0)
                {
                    score_situation++;
                }
                if(ma_vie+10 > attaque_ennemi)
                {
                    score_situation++;
                }
                if(ma_vie <= 20)
                {
                    score_situation++;
                }

                break;
            }

        case 1: ///AMELIORER ATTAQUE
            {
                if(mon_attaque+10 >= vie_ennemi+10)
                {
                    score_situation+=2;
                }
                if(mon_attaque+10 >= vie_ennemi)
                {
                    score_situation++;
                }
                if(mon_attaque+10 >= vie_ennemi2)
                {
                    score_situation++;
                }
                if(mon_attaque < 40)
                {
                    score_situation++;
                }
                if(mon_attaque < 70)
                {
                    score_situation++;
                }

                break;
            }

        case 2: ///ATTAQUER
            {
                if(vie_adversaire > 0)
                {
                    if(mon_attaque >= vie_adversaire)
                    {
                        score_situation+=3;
                    }
                    if(mon_attaque+10 >= vie_adversaire)
                    {
                        score_situation++;
                    }
                    if(mon_attaque + attaque_allie_1 + attaque_allie_2 >= vie_adversaire)
                    {
                        score_situation+=4;
                    }
                    if(mon_attaque >= 5)
                    {
                        score_situation++;
                    }
                    if(vie_adversaire > 0)
                    {
                        score_situation++;
                    }
                    if(vie_adversaire > vie_ennemi2)
                    {
                        score_situation++;
                    }
                    if(vie_allie_1 == 0 || vie_allie_2 == 0)
                    {
                        score_situation++;
                    }
                    if(attaque_adversaire > vie_allie_1 || attaque_adversaire > vie_allie_2)
                    {
                        score_situation++;
                    }
                    if(attaque_adversaire > 50 || vie_adversaire > 30)
                    {
                        score_situation++;
                    }

                }

                break;
            }

        case 3: ///DONNER DE LA VIE
            {
                if(vie_allie_1 > 0)
                {
                    if(vie_allie_1 <= attaque_ennemi && ma_vie-10 > attaque_ennemi)
                    {
                        score_situation+=3;
                    }
                    if(vie_allie_1 <= attaque_ennemi && ma_vie-10 == attaque_ennemi)
                    {
                        score_situation++;
                    }
                    if(vie_allie_1 <=attaque_ennemi && ma_vie-10 < attaque_ennemi)
                    {
                        score_situation--;
                    }

                }

                if(vie_allie_2 > 0)
                {
                    if(vie_allie_2 <= attaque_ennemi && ma_vie-10 > attaque_ennemi)
                    {
                        score_situation+=3;
                    }
                    if(vie_allie_2 <= attaque_ennemi && ma_vie-10 == attaque_ennemi)
                    {
                        score_situation++;
                    }
                    if(vie_allie_2 <= attaque_ennemi && ma_vie-10 < attaque_ennemi)
                    {
                        score_situation--;
                    }

                }

                break;
            }

        case 4: /// ATTAQUER ENNEMI 2
            {
                if(vie_ennemi2 > 0)
                {
                    if(mon_attaque >= vie_ennemi2)
                    {
                        score_situation+=2;
                    }
                    if(mon_attaque+10 >= vie_ennemi2)
                    {
                        score_situation++;
                    }
                    if(vie_ennemi2 > mon_attaque)
                    {
                        score_situation++;
                    }
                    if(mon_attaque + attaque_allie_1 + attaque_allie_2 >= vie_ennemi2)
                    {
                        score_situation+=4;
                    }
                    if(mon_attaque >= 5)
                    {
                        score_situation++;
                    }
                    if(vie_adversaire > vie_ennemi2)
                    {
                        score_situation++;
                    }
                    if(attaque_ennemi2 > vie_allie_1 || attaque_ennemi2 > vie_allie_2)
                    {
                        score_situation++;
                    }
                }

                break;
            }

        /*default:
            {
                ///FAUDRA METTRE UN TRUC MAIS JE SAIS PAS QUOI???
            }*/
    }

    return score_situation;
}

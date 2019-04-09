#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "IA.h"
#include "IA_ALLIE.h"

using namespace std;

int vie_IA(0);
int vie_initiale_IA = 100;
int attaque_IA(0);
int vie_allie(0);
int attaque_allie(0);
int vie_adv_1(0);
int vie_adv_2(0);
int vie_adv_3(0);
int attaque_adv_1(0);
int attaque_adv_2(0);
int attaque_adv_3(0);
int scores_situation[10];
int note(0);
bool IA_1_estEnVie;
bool IA_2_estEnVie;
bool IA_3_estEnVie;
int type ;

int selection_action(int ma_vie, int mon_attaque, int vie_ami, int attaque_ami,
int vie_ennemi1, int vie_ennemi2, int vie_ennemi3, int attaque_ennemi1, int attaque_ennemi2, int attaque_ennemi3, int type_IA)
{

    vie_IA = ma_vie;
    type = type_IA;
    attaque_IA = mon_attaque;
    vie_allie = vie_ami;
    attaque_allie = attaque_ami;
    vie_adv_1 = vie_ennemi1;
    vie_adv_2 = vie_ennemi2;
    vie_adv_3 = vie_ennemi3;
    attaque_adv_1 = attaque_ennemi1;
    attaque_adv_2 = attaque_ennemi2;
    attaque_adv_3 = attaque_ennemi3;

/*
    cout << "vie_IA = " << vie_IA << endl;
    cout << "attaque_IA = " << attaque_IA << endl;
    cout << "vie_allie = " << vie_allie << endl;
    cout << "attaque_allie = " << attaque_allie << endl;
    cout << "vie_adv_1 = " << vie_adv_1 << endl;
    cout << "vie_adv_2 = " << vie_adv_2 << endl;
    cout << "vie_adv_3 = " << vie_adv_3 << endl;
    cout << "attaque_adv_1 = " << attaque_adv_1 << endl;
    cout << "attaque_adv_2 = " << attaque_adv_2 << endl;
    cout << "attaque_adv_3 = " << attaque_adv_3 << endl;
*/

    int action(0);
    int a_p(5);
    int Sc_A[5];

    /**for(int i=0;i<=a_p;i++)
    {
        Sc_A[i] = strategie(i);
    }

    for(int j=1;j<=5;j++)
    {
        if(Sc_A[j] < Sc_A[j-1])
        {
            action = j;
        }
    }*/

    action = strategie(0);

    return action;
}

int strategie(int action)
{
    /** POSSIBILITE MIN-MAX
    *
    * POSSIBILITE D'ANTICIPER LES ACIONS DES ADVERSAIRES
    * POSSIBILITE DE SIMULER UNE ACTION
    * POSSIBLE CONSTRUCTION D'UN ARBRE (profondeur 2)
    * (i.e --> Simuler mon action[0], prédire l'action de l'adversaire[1], Anticiper les mesures nécéssaires[2])
    */

    int APA_1(0);
    int APA_2(0);
    int APA_3(0);
    int scr_Sit(0);

    scr_Sit = MinMax(1, 1, action, type);

    return scr_Sit;
}

int simulation(int action, int joueur, int type) ///SIMULE LES ACTIONS ET ANTICIPE LA REPONSE ADVERSE
{
    int APA_1, APA_2, APA_3;

    if(joueur == 1)
    {
        /*cout << "SIMULATION DE L'IA POUR ACTION |" << action << "| : " << endl << endl;
        cout << "-----------------------------------------------------------" << endl;*/

        switch(action) /// IA
        {
        case 0:
            {
                vie_IA += 10;
                //cout << "SIMULATION DE GUERISON (vie_IA += 10)" << endl;
                break;
            }
        case 1:
            {
                attaque_IA += 10;
                //cout << "SIMULATION D'AMELIORATION D'ATTAQUE (attaque_IA += 10)" << endl;
                break;
            }
        case 2:
            {
                if(vie_adv_1 > 0)
                {
                    vie_adv_1 -= attaque_IA;
                    IA_1_estEnVie = true;
                    if(vie_adv_1 <= 0){
                        vie_adv_1 += attaque_IA ;
                    }
                }
                else if(vie_adv_1 <= 0)
                    IA_1_estEnVie = false;
                //cout << "SIMULATION D'ATTAQUE DE <adv_1> (vie_adv_1 -= attaque_IA)" << endl;
                break;
            }
        case 3:
            {
                if(vie_adv_2 > 0)
                {
                    vie_adv_2 -= attaque_IA;
                    IA_2_estEnVie = true;
                    if(vie_adv_2 <= 0){
                        vie_adv_2 += attaque_IA ;
                    }
                }
                else if(vie_adv_2 <= 0)
                    IA_2_estEnVie = false;
                //cout << "SIMULATION D'ATTAQUE DE <adv_2> (vie_adv_2 -= attaque_IA)" << endl;
                break;
            }
        case 4:
            {
                if(vie_adv_3 > 0)
                {
                    vie_adv_3 -= attaque_IA;
                    IA_3_estEnVie = true;
                    if(vie_adv_3 <= 0){
                        vie_adv_3 += attaque_IA ;
                    }
                }
                else if(vie_adv_3 <= 0)
                    IA_3_estEnVie = false;
               // cout << "SIMULATION D'ATTAQUE DE <adv_3> (vie_adv_3 -= attaque_IA)" << endl;
                break;
            }
        case 5:
            {
                vie_IA -= 10;
                vie_allie += 10;
               // cout << "SIMULATION D'AIDE A <Allie> (vie_IA -= 10 && vie_allie += 10)" << endl;
                break;
            }
        }

        //cout << "-----------------------------------------------------------" << endl;

    }

    if(vie_adv_1 > 0)
    {
        APA_1 = choix_action(attaque_allie, vie_allie, attaque_adv_1, vie_adv_1, vie_adv_2, attaque_adv_2, attaque_adv_3, vie_adv_3, vie_IA, attaque_IA);
    }
    if(vie_adv_2 > 0)
    {
        APA_2 = choix_action(attaque_allie, vie_allie, attaque_adv_2, vie_adv_2, vie_adv_1, attaque_adv_1, attaque_adv_3, vie_adv_3, vie_IA, attaque_IA);
    }
    if(vie_adv_3 > 0)
    {
        APA_3 = choix_action(attaque_allie, vie_allie, attaque_adv_3, vie_adv_3, vie_adv_1, attaque_adv_1, attaque_adv_2, vie_adv_2, vie_IA, attaque_IA);
    }

    return evaluer_action(action, APA_1, APA_2, APA_3, type);
}

int evaluer_action(int action, int action_adverse, int action_adverse2, int action_adverse3, int type) ///EVALUE L'ACTION
{
    int Scr_Act(0);

    if(type == 1) ///IA AGGRESSIVE
    {
        switch(action)
        {
        case 1: /// SE SOIGNER
            {
                int somme_attaques_adverses = attaque_adv_1 + attaque_adv_2 + attaque_adv_3 ;
                if(vie_IA <= somme_attaques_adverses && vie_IA < 200)
                    Scr_Act+=5;
                break;
            }
        case 2: ///AMELIORER L'ATTAQUE
            {
                if(attaque_IA < 20)
                    Scr_Act+=2;
                if(attaque_IA+10 >= vie_adv_1
                   || attaque_IA+10 >= vie_adv_2
                   || attaque_IA+10 >= vie_adv_3)
                    Scr_Act += 3;
                if(attaque_IA < 30)
                    Scr_Act++;
                if(attaque_IA < 50)
                    Scr_Act++;
                break;
            }
        case 3: /// ATTAQUER ENNEMI 1
            {
                if(vie_adv_1 > 0){
                Scr_Act+=3; //juste pcq elle est aggrssive
                if(vie_adv_1 < attaque_IA)
                    Scr_Act+=10;
                if(vie_adv_1 - (attaque_IA + attaque_allie) <= 0)
                    Scr_Act+=5;
                }
                break;
            }
        case 4: /// ATTAQUER ENNEMI 2
            {
                if(vie_adv_2 > 0){
                    Scr_Act+=3;
                if(vie_adv_2 < attaque_IA)
                    Scr_Act+=10;
                if(vie_adv_2 - (attaque_IA + attaque_allie) <= 0)
                    Scr_Act+=5;
                }
                break;
            }
        case 5:
            {
                if(vie_adv_3 > 0){
                    Scr_Act+=3;
                if(vie_adv_3 < attaque_IA)
                    Scr_Act+=10;
                if(vie_adv_3 - (attaque_IA + attaque_allie) <= 0)
                    Scr_Act+=5;
                }
                break;
            }
        case 6:
            {
                ///IL S'EN FOUS DE L'AIDER IL VEUX JUSTE ATTAQUER
                break;
            }
            }
        }

    if(type == 2) ///IA PASSIVE
    {
        switch(action)
        {
        case 1: ///SE SOIGNER
            {
                if(vie_IA < 200)
                    Scr_Act+=5;
                break;
            }
        case 2: ///AMELIORER ATTAQUE
            {
                if(attaque_IA < 20)
                    Scr_Act+=2;
                break;
            }
        case 3: /// CASES QUI SUIVENT : ATTAQUER ADV1, ADV2, ADV3
            {
                if(vie_adv_1 > 0){
                if(attaque_IA > vie_adv_1)
                    Scr_Act += 5;
                }
                break;
            }
        case 4:
            {
                if(vie_adv_2 > 0){
                if(attaque_IA > vie_adv_2)
                    Scr_Act += 5;
                }
                break;
            }
        case 5:
            {
                if(vie_adv_3 > 0){
                if(attaque_IA > vie_adv_3)
                    Scr_Act += 5;
                }
                break;
            }
        case 6: ///AIDER ALLIE
            {
                if(vie_allie < (attaque_adv_1 + attaque_adv_2 + attaque_adv_3))
                    Scr_Act += 5;
                break;
            }

        }
    }

    if(type == 3) ///IA STRATEGIQUE
    {
        switch(action)
        {

        case 0: ///SE SOIGNER
            {
                if(vie_IA <= attaque_adv_1){
                    Scr_Act++;}
                    if(action_adverse == 4){
                        Scr_Act++;}
                if(vie_IA <= attaque_adv_2){
                    Scr_Act++;}
                    if(action_adverse2 == 4){
                        Scr_Act++;}
                if(vie_IA <= attaque_adv_3){
                    Scr_Act++;
                    if(action_adverse3 == 4){
                        Scr_Act++;}}
                if(vie_IA <= attaque_adv_1 + attaque_adv_2 + attaque_adv_3){
                    Scr_Act+=3;}
                if(vie_IA < vie_initiale_IA){
                    Scr_Act++;}
                if(action_adverse == 0 || action_adverse2 == 0  || action_adverse3 == 0){
                    Scr_Act++;}
                break;
            }

        case 1: /// AMELIORER SON ATTAQUE
            {
                if(attaque_IA <= attaque_adv_1){
                    Scr_Act++;
                    if(action_adverse == 1 || action_adverse == 2){ /// SI IL AMELIORE SON ATTAQUE OU QU'IL ATTAQUE LE JOUEUR
                        Scr_Act++;}}
                if(attaque_IA <= attaque_adv_2){
                    Scr_Act++;
                    if(action_adverse2 == 1 || action_adverse2 == 2){
                        Scr_Act++;}}
                if(attaque_IA <= attaque_adv_3){
                    Scr_Act++;
                    if(action_adverse3 == 1 || action_adverse3 == 2){
                        Scr_Act++;}}
                if(action_adverse == 1){
                    Scr_Act++;
                    if(action_adverse2 == 1){
                        Scr_Act+=2;
                        if(action_adverse3 == 1){
                            Scr_Act+=3;}}}
                if(attaque_IA <= 5){
                    Scr_Act+=3;}
                if(attaque_IA < 20){
                    Scr_Act+=2;}
                if(attaque_IA < 50){
                    Scr_Act++;}
                if(attaque_IA < 100){
                    Scr_Act++;}

                break;
            }

        case 2: ///ATTAQUER ADV1
            {
                if(vie_adv_1 > 0)
                {
                    if(attaque_IA >= vie_adv_1){
                        Scr_Act+=30;
                        if(vie_IA > (attaque_adv_2 + attaque_adv_3) && (vie_adv_3 > 0 && vie_adv_2 > 0)){
                            Scr_Act+=10;}
                        else if(vie_IA > attaque_adv_2 || vie_IA > attaque_adv_3 && (vie_adv_3 > 0 && vie_adv_2 > 0)){
                            Scr_Act+=5;}
                        else if((attaque_IA >= vie_adv_3) && (vie_adv_3 > 0 && vie_adv_2 > 0)){
                            Scr_Act+= 20 ;
                        }
                            }
                    if(attaque_IA < vie_adv_1){
                        Scr_Act++;}
                    if(action_adverse == 2 || action_adverse == 4){
                        Scr_Act++;}
                    if(action_adverse2 == 2 || action_adverse2 == 4){
                        Scr_Act++;}
                    if(action_adverse3 == 2 || action_adverse3 == 4){
                        Scr_Act++;}
                    if(attaque_IA + attaque_allie > vie_adv_1){
                        Scr_Act+=5;}
                }

                break;
            }

        case 3: ///ATTAQUER ADV2
            {
                if(vie_adv_2 > 0)
                {
                    if(attaque_IA >= vie_adv_2){
                        Scr_Act+=30;
                        if(vie_IA > (attaque_adv_1 + attaque_adv_3) && (vie_adv_1 > 0 && vie_adv_3 > 0)){
                            Scr_Act+=10;}
                        else if(vie_IA > attaque_adv_3 || vie_IA > attaque_adv_1 && (vie_adv_1 > 0 && vie_adv_3 > 3)){
                            Scr_Act+=5;}
                        else if((attaque_IA >= vie_adv_2) && (vie_adv_1 > 0 && vie_adv_3 > 0)){
                            Scr_Act+= 20 ;
                        }
                            }
                    if(attaque_IA < vie_adv_2){
                        Scr_Act++;}
                    if(action_adverse == 2 || action_adverse == 4){
                        Scr_Act++;}
                    if(action_adverse2 == 2 || action_adverse2 == 4){
                        Scr_Act++;}
                    if(action_adverse3 == 2 || action_adverse3 == 4){
                        Scr_Act++;}
                    if(attaque_IA + attaque_allie > vie_adv_2){
                        Scr_Act+=5;}
                }

                break;
            }

        case 4: ///ATTAQUER ADV3
            {
                if(vie_adv_3 > 0)
                {
                    if(attaque_IA >= vie_adv_3){
                        Scr_Act+=30;
                        if(vie_IA > (attaque_adv_1 + attaque_adv_2) && (vie_adv_1 > 0 && vie_adv_2 > 0)){
                            Scr_Act+=10;}
                        else if(vie_IA > attaque_adv_1 || vie_IA > attaque_adv_2 && (vie_adv_1 > 0 && vie_adv_2 > 0)){
                            Scr_Act+=5;}
                        else if((attaque_IA >= vie_adv_3) && (vie_adv_1 > 0 && vie_adv_2 > 0)){
                            Scr_Act+= 20 ;
                        }
                            }

                    if(attaque_IA < vie_adv_3){
                        Scr_Act++;}
                    if(action_adverse == 2 || action_adverse == 4){
                        Scr_Act++;}
                    if(action_adverse2 == 2 || action_adverse2 == 4){
                        Scr_Act++;}
                    if(action_adverse3 == 2 || action_adverse3 == 4){
                        Scr_Act++;}
                    if(attaque_IA + attaque_allie > vie_adv_3){
                        Scr_Act+=5;}
                }

                break;
            }

        case 5: ///DONNER DE LA VIE A ALLIE
            {
                if(vie_allie < attaque_adv_1 + attaque_adv_2 + attaque_adv_3)
                    Scr_Act+=2;
                if(vie_allie < 50 && vie_IA >= 100)
                    Scr_Act++;

                break;
            }

        }
    }

    return Scr_Act;
}

void annuler_action(int action) ///ANNULE LA SIMULATION IA
{
    /**cout << "ANNULATION ACTION |" << action << "|" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "IA ANNULE ";*/
    switch(action)
    {
    case 0:
        {
            vie_IA -= 10;
            ///cout << " SA GUERISON" << endl;
            break;

        }
    case 1:
        {
            attaque_IA -= 10;
            ///cout << " L'AMELIORATION DE SON ATTAQUE" << endl;
            break;
        }
    case 2:
        {
            vie_adv_1 += attaque_IA;
            ///cout << " L'ATTAQUE DE <adv_1>" << endl;
            break;
        }
    case 3:
        {
            vie_adv_2 += attaque_IA;
            ///cout << " L'ATTAQUE DE <adv_2>" << endl;
            break;

        }
    case 4:
        {
            vie_adv_3 += attaque_IA;
            ///cout << " L'ATTAQUE DE <adv_3>" << endl;
            break;

        }
    case 5:
        {
            vie_IA += 10;
            vie_allie -= 10;
            ///cout << " L'AIDE DE L'ALLIE" << endl;
            break;
        }
    }
}


void annuler_action_advrs(int Ac_1, int Ac_2, int Ac_3) ///ANNULE LLES SIMULATIONS ADVERSES
{
    switch(Ac_1) ///ENNEMI_1
    {
    case 0:
        {
            vie_adv_1 -= 10;
            break;
        }
    case 1:
        {
            attaque_adv_1 -=10;
            break;
        }
    case 2:
        {
            vie_allie += attaque_adv_1;
            break;
        }
    case 3:
        {
            if(vie_adv_2 < vie_adv_3)
            {
                vie_adv_2 -= 10;
            }
            else
            {
                vie_adv_3 -= 10;
            }

            break;
        }
    case 4:
        {
            vie_IA += attaque_adv_1;
            break;
        }
    }

    switch(Ac_2) ///ENNEMI_2
    {
    case 0:
        {
            vie_adv_2 -= 10;
            break;
        }
    case 1:
        {
            attaque_adv_2 -=10;
            break;
        }
    case 2:
        {
            vie_allie += attaque_adv_2;
            break;
        }
    case 3:
        {
            if(vie_adv_1 < vie_adv_3)
            {
                vie_adv_1 -= 10;
            }
            else
            {
                vie_adv_3 -= 10;
            }
            break;
        }
    case 4:
        {
            vie_IA += attaque_adv_2;
            break;
        }
    }

    switch(Ac_3) ///ENNEMI_3
    {
    case 0:
        {
            vie_adv_3 -= 10;
            break;
        }
    case 1:
        {
            attaque_adv_3-=10;
            break;
        }
    case 2:
        {
            vie_allie += attaque_adv_3;
            break;
        }
    case 3:
        {
            if(vie_adv_1 < vie_adv_2)
            {
                vie_adv_1 -= 10;
            }
            else
            {
                vie_adv_2 -= 10;
            }
            break;
        }
    case 4:
        {
            vie_IA += attaque_adv_3;
            break;
        }
    }

}


int MinMax(int profondeur, int Joueur, int action, int type) ///CODE PRINCIPALE INTELLIGENCE ARTIFICIELLE BAS NIVEAU
{ ///---------DEBUT---------

    int Max(-10000);
    ///int Min(10000);
    int scr_sit(0);
    int meilleure_action_possible(0);

    if(Joueur == 1)
    {
        for(int i=0;i<6;i++)
        {
            scr_sit = simulation(i, Joueur, type);
            //cout << "SCORE POUR ACTON > |" << i << "| = <" << scr_sit << ">" << endl;
            if(scr_sit > Max)
            {
                meilleure_action_possible = i;
                Max = scr_sit;
            }

            annuler_action(i);
        }
    }

    return meilleure_action_possible;

}///-----------FIN-----------

int gagnantJeu(int joueur) ///FONCTION QUI NE SERT A RIEN POUR L'INSTANT ...
{
    int la_vie_du_joueur(0);

    if(joueur == 1)
        la_vie_du_joueur = vie_IA;
    else
        la_vie_du_joueur = vie_adv_1;

    if(la_vie_du_joueur <= 0){
        return -1;
    }else{
        return 1;
    }
}

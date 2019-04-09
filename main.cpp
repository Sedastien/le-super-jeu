#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <Mmsystem.h>
#include "IA.h"
#include "IA_ALLIE.h"
#include "menu.h"
#include "afficher_scores.h"

using namespace std;

int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("mode con cols=74 lines=48") ;
    system("title LE SUPER JEU (by Sebazar Inc.)") ;

    int setup = 1 ;

    while(setup > 0 && setup < 4)
    {
        system("cls") ;
        setup = afficher_setup() ;

        if(setup == 1) /// MODE JEU NORMAL
        {
            int ch = 0 ;
            chargement(ch) ;
    // ---------- INITIALISATIONS DE BASE ----------- //

            chargement(ch+5) ;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            chargement(ch++) ;

    //------------VARIABLES---------------

            int nbParties = 0 ;
            chargement(ch+1) ;
            int finJeu = 1;
            chargement(ch+2) ;
            int compteurDeTours = 0;
            chargement(ch+3) ;
            int type_IA = 0 ;
            chargement(ch+4) ;
            string nomHeros;
            chargement(ch+5) ;
            string nomAllie;
            chargement(ch+6) ;
            string nomJoueur;
            chargement(ch+7) ;
            string nomEnnemi1;
            chargement(ch+8) ;
            string nomEnnemi2;
            chargement(ch+9) ;
            string nomEnnemi3;
            chargement(ch+10) ;
            string nomArme;
            chargement(ch+11) ;
            string nomArmeAllie ;
            chargement(ch+12) ;
            string nomsEnnemis[3] ;
            chargement(ch+13) ;
            string rejouer ;
            chargement(ch+14) ;

            /**----- CONSTANTES / VARIABLES -----*/

            int attaqueEnnemi1 = 5;
            chargement(ch+15) ;
            int attaqueEnnemi2 = 5;
            chargement(ch+16) ;
            int attaqueEnnemi3 = 5;
            chargement(ch+17) ;
            int vdb_h = 200;
            chargement(ch+18) ;
            int vdb_a = 200;
            chargement(ch+19) ;
            int vdb_e1 = 100;
            chargement(ch+20) ;
            int vdb_e2 = 100;
            chargement(ch+21) ;
            int vdb_e3 = 100;
            chargement(ch+22) ;
            int allie_est_mort = 0;
            chargement(ch+23) ;
            int score_initial = 100;
            chargement(ch+24) ;
            int attaqueHeros = 5;
            chargement(ch+25) ;
            int attaqueAllie = 5;
            chargement(ch+26) ;
            int action;
            chargement(ch+27) ;
            int recuperationVie;
            chargement(ch+28) ;
            int vieTotaleDesEnnemis;
            chargement(ch+29) ;
            /**int choixArme;*/
            int compteurSeSoigner(0);
            chargement(ch+30) ;
            int compteurAmeliorerArme(0);
            chargement(ch+31) ;
            int compteurAttaquer(0);
            chargement(ch+32) ;
            int compteurTotal(0);
            chargement(ch+33) ;
            int compteur_soigne_allie(0);
            chargement(ch+34) ;
            int compteur_attaque_allie(0);
            chargement(ch+35) ;
            int compteur_ame_arme_allie(0);
            chargement(ch+36) ;
            int compteur_aide_allie(0);
            chargement(ch+37) ;
            //int compteur_total_allie(0);
            chargement(ch+38) ;
            bool a_gagne;
            chargement(ch+39) ;
            string niv ;
            chargement(ch+40) ;
            int nv ;
            int attaque_heros_base = 5 ;
            int attaque_allie_base = 5 ;
            chargement(ch+41) ;
            PlaySound("musiques\\madMax.WAV", NULL, SND_FILENAME | SND_ASYNC );
            chargement(ch+67) ;

            /** ------- PERSOSNNALISATIONS -------- */

            do  ///BOUCLE POUR LE JEU
            {

                if(nbParties == 0)
                {
                    afficher_titre() ;
                    string niveaux[4] = {"   [1] => RECRUE", "   [2] => 2ND CLASSE", "   [3] => COMMANDO", "   [4] => VETERAN"} ;
                    afficher_lignes("   BIENVENUE, CHOISISSEZ UN NIVEAU DE DIFFICULTE :", 14, 14) ;
                    afficher_lignes(" ", 14, 14) ;
                    for(int i=0; i<4; i++)
                    {
                        afficher_lignes(niveaux[i], 14, 14) ;
                    }
                    afficher_lignes(" ", 14, 14) ;
                    cout << "   ===> ";
                    try
                    {
                        getline(cin, niv) ;
                        getline(cin, niv) ;
                        if(atoi(niv.c_str()) == 1 || atoi(niv.c_str()) == 2 ||
                                atoi(niv.c_str()) == 3 || atoi(niv.c_str()) == 4)
                        {
                            nv = atoi(niv.c_str()) ;
                        }
                        else
                        {
                            if(typeid(niv) == typeid(int))
                            {
                                nv = atoi(niv.c_str()) ; /// !!! Conversion de STR à INT en C++ !!!
                            }
                            else
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                afficher_lignes(" /!\\ ERREUR DE SAISIE => APPLICATION DES PARAMETRES PAR DEFAUT. /!\\", 14, 12) ;
                                nv = 1 ;
                            }
                        }
                    }
                    catch(std::string& erreur)
                    {
                        SetConsoleTextAttribute(hConsole, 12);
                        afficher_lignes("   /!\\ ERREUR DE SAISIE => APPLICATION DES PARAMETRES PAR DEFAUT. /!\"", 14, 12) ;
                    }
                    SetConsoleTextAttribute(hConsole, 14);

                    /**----------------------*/


    //----------------ALGORITHME-------------------

                    afficher_lignes(" ", 14, 14) ;
                    cout << " *   ENTRER VOTRE PRENOM > ";
                    getline(cin, nomJoueur) ;
                    afficher_lignes(" ", 14, 14) ;
                    cout << " *   ENTRER LE NOM DU HEROS > ";
                    getline(cin, nomHeros);
                    afficher_lignes(" ", 14, 14) ;
                    cout << " *   CHOISISSEZ LE NOM DE VOTRE ARME > ";
                    getline(cin, nomArme);
                    afficher_lignes(" ", 14, 14) ;
                    string choisir_pers_allie = "n" ;
                    cout << " *   PERSONNALISER L'ALLIE ? (o/n) >";
                    getline(cin, choisir_pers_allie) ;

                    if(choisir_pers_allie != "o" && choisir_pers_allie != "n" &&
                       choisir_pers_allie != "O" && choisir_pers_allie != "N")
                    {
                        afficher_lignes(" /!\\ SAISIE INVALIDE => APPLICATION DU PARAMETRE PAR DEFAUT /!\\ ", 14, 12) ;
                    }

                    afficher_lignes(" ", 14, 14) ;
                    string pers_noms_ennemis ;

                    if(choisir_pers_allie == "o" || choisir_pers_allie == "O" )
                    {
                        //system("cls");
                        //afficher_titre();
                        string le_type_IA ;
                        cout << " *   SAISIR LE NOM DE VOTRE ALLIE >";
                        getline(cin, nomAllie) ;
                        afficher_lignes(" ", 14, 14) ;
                        cout << " *   CHOISIR LE NOM DE L'ARME DE VOTRE ALLIE >";
                        getline(cin, nomArmeAllie) ;
                        afficher_lignes(" ", 14, 14) ;
                        afficher_lignes("   [1] -> AGRESSIVE", 14, 12) ;
                        afficher_lignes("   [2] -> PASSIVE", 14, 11) ;
                        afficher_lignes("   [3] -> STRATEGIQUE", 14, 10) ;
                        afficher_lignes(" ", 14, 14) ;
                        cout << " *   SELECTIONNER LE TYPE D'ALLIE QUE VOUS SOUHAITEZ AVOIR (1,2,3) >";
                        try
                        {
                            getline(cin, le_type_IA) ;
                            if(atoi(le_type_IA.c_str()) == 1 || atoi(le_type_IA.c_str()) == 2 ||
                                    atoi(le_type_IA.c_str()) == 3)
                            {
                                type_IA = atoi(le_type_IA.c_str()) ;
                            }else{
                                if(typeid(le_type_IA) == typeid(int))
                                {
                                    type_IA = atoi(le_type_IA.c_str()) ; /// !!! Conversion de STR à INT en C++ !!!
                                }else{
                                    SetConsoleTextAttribute(hConsole, 12);
                                    afficher_lignes(" /!\\ ERREUR DE SAISIE => APPLICATION DES PARAMETRES PAR DEFAUT. /!\\", 14, 12) ;
                                    type_IA = atoi(le_type_IA.c_str()) ;
                                    type_IA = 3 ;
                                }
                            }
                        }
                        catch(std::string& erreur)
                        {
                            SetConsoleTextAttribute(hConsole, 12);
                            afficher_lignes("   /!\\ ERREUR DE SAISIE => APPLICATION DES PARAMETRES PAR DEFAUT. /!\"", 14, 12) ;
                        }
                    }
                    else
                    {
                        nomAllie = "ORDINATEUR" ;
                        nomArmeAllie = "ARME BIDON SANS NOM" ;
                        type_IA = 3 ;
                    }


                    afficher_lignes(" ", 14, 14) ;
                    cout << " *   PERSONNALISER LE NOM DE VOS ENNEMIS ? (o/n) >";
                    getline(cin, pers_noms_ennemis) ;

                    if(pers_noms_ennemis != "o" && pers_noms_ennemis != "O" &&
                       pers_noms_ennemis != "n" && pers_noms_ennemis != "N")
                    {
                        afficher_lignes(" /!\\ ERREUR DE SAISIE => APPLICATION DES PARAMTRES PAR DEFAUT /!\\ ", 14, 12) ;
                    }

                    afficher_lignes(" ", 14, 14) ;
                    string noms_avant_mechants[3] = {"L'horrible ", "L'effroyable ", "L'impitoyable "} ;
                    if(pers_noms_ennemis == "o" || pers_noms_ennemis == "O")
                    {
                        string noms_avant_mechants[3] = {"L'horrible ", "L'effroyable ", "L'impitoyable "} ;
                        //system("cls") ;
                        //afficher_titre() ;
                        for(int i=0; i<3; i++)
                        {
                            cout << " *   SAISIR LE NOM DE L'ENNEMI " << i+1 << " >";
                            getline(cin, nomsEnnemis[i]) ;
                            ///cout << "       [ L'Ennemi " << i+1 << " sera " << nomsEnnemis[i]  << " ]" << endl;
                            afficher_lignes(" ", 14, 14) ;
                        }
                        afficher_lignes(" ", 14, 14) ;

                        nomEnnemi1 = nomsEnnemis[0] ;
                        nomEnnemi2 = nomsEnnemis[1] ;
                        nomEnnemi3 = nomsEnnemis[2] ;
                    }
                    else
                    {
                        nomEnnemi1 = "ASSMODE";
                        nomsEnnemis[0] = "ASSMODE" ;
                        nomEnnemi2 = "SMITH";
                        nomsEnnemis[1] = "SMITH" ;
                        nomEnnemi3 = "PAZUZU";
                        nomsEnnemis[2] = "PAZUZU" ;
                    }
                    afficher_lignes("  APPRETEZ VOUS A AFFRONTER : ", 14, 11) ;
                    afficher_lignes(" ", 14, 14) ;
                    string ligne ;
                    for(int i=0; i<3; i++)
                    {
                        ligne = "   - "+noms_avant_mechants[i]+nomsEnnemis[i] ;
                        afficher_lignes(ligne, 14, 12) ;
                    }
                    afficher_lignes(" ", 14, 14) ;
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << " * ";
                    for(int i=0; i<34; i++)
                    {
                        if(i%2==0)
                        {
                            SetConsoleTextAttribute(hConsole, 14);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, 12);
                        }
                        cout << "\\\\";
                    }
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << " * " << endl << endl;
                    cout << " *   LE SUPER JEU va commencer, ";

                    system("pause");

                }/// if(nbParties == 0)

                switch(nv) ///Selection de la musique selon le niveau choisi et des parametres
                {
                case 1:
                {
                    ///LES ENNEMIS ATTAQUENT JUSTE
                    attaqueEnnemi1 = 10 ;
                    attaqueEnnemi2 = 10 ;
                    attaqueEnnemi3 = 10 ;
                    PlaySound("musiques\\mortal.WAV", NULL, SND_FILENAME | SND_ASYNC );
                    break;
                }
                case 2:
                {
                    vdb_e1 = 200 ;
                    vdb_e2 = 200 ;
                    vdb_e3 = 200 ;

                    attaqueEnnemi1 = 15 ;
                    attaqueEnnemi2 = 15 ;
                    attaqueEnnemi3 = 15 ;

                    PlaySound("musiques\\moyen.WAV", NULL, SND_FILENAME | SND_ASYNC );
                    break;
                }
                case 3:
                {
                    vdb_e1 = 300 ;
                    vdb_e2 = 300 ;
                    vdb_e3 = 300 ;

                    attaqueEnnemi1 = 20 ;
                    attaqueEnnemi2 = 20 ;
                    attaqueEnnemi3 = 20 ;

                    PlaySound("musiques\\difficile.WAV", NULL, SND_FILENAME | SND_ASYNC );
                    break;
                }
                case 4:
                {
                    vdb_e1 = 400 ;
                    vdb_e2 = 400 ;
                    vdb_e3 = 400 ;
                    attaqueEnnemi1 = 30 ;
                    attaqueEnnemi2 = 30 ;
                    attaqueEnnemi3 = 30 ;
                    PlaySound("musiques\\hardcore.WAV", NULL, SND_FILENAME | SND_ASYNC );
                    break;
                }
                }

                /** INITIALISATIONS PRINCIPALES */
                int vieInitialeHeros = vdb_h;
                int vieInitialeAllie = vdb_a;
                int vieInitialeEnnemi1 = vdb_e1;
                int vieInitialeEnnemi2 = vdb_e2;
                int vieInitialeEnnemi3 = vdb_e3;
                if(a_gagne == false)
                {
                    attaqueHeros = attaque_heros_base ;
                    attaqueAllie = attaque_allie_base ;
                }
                /** --------------------------  */

                system("cls") ;

                do /// BOUCLE PRINCIPALE DU JEU
                {
                    //system("cls");

                    compteurDeTours++;
                    if(compteurDeTours == 1)
                    {
                        attaque_heros_base = attaqueHeros ;
                        attaque_allie_base = attaqueAllie ;
                    }

                    afficher_interface(vieInitialeHeros, attaqueHeros, vieInitialeAllie, attaqueAllie,
                                       vieInitialeEnnemi1, vieInitialeEnnemi2, vieInitialeEnnemi3,
                                       attaqueEnnemi1, attaqueEnnemi2, attaqueEnnemi3,
                                       nomHeros, nomAllie, nomEnnemi1, nomEnnemi2, nomEnnemi3, compteurDeTours,
                                       vdb_h, vdb_a, vdb_e1, vdb_e2, vdb_e3, nomArme, nomArmeAllie);



                    if(vieInitialeHeros > 0)
                    {
                        action = selection_action(vieInitialeHeros, attaqueHeros, vieInitialeAllie, attaqueAllie,
                                                  vieInitialeEnnemi1, vieInitialeEnnemi2, vieInitialeEnnemi3,
                                                  attaqueEnnemi1, attaqueEnnemi2, attaqueEnnemi3, type_IA);

                        SetConsoleTextAttribute(hConsole, 9);
                        cout << " QUELLE ACTION FAIRE ? >> ";
                        ///cin >> action;
                        string laAction ;
                        bool vrai = false ;


                        /** CONTROLE SAISIES!! */
                        while(vrai == false)
                        {
                            try
                            {
                                cout << " QUELLE ACTION FAIRE ? >> ";
                                getline(cin, laAction) ;
                                if(atoi(laAction.c_str()) == 1 || atoi(laAction.c_str()) == 2 ||
                                    atoi(laAction.c_str()) == 3 || atoi(laAction.c_str()) == 4
                                   || atoi(laAction.c_str()) == 5 || atoi(laAction.c_str()) == 6)
                                {
                                    action = atoi(laAction.c_str()) ;
                                    vrai = true ;
                                }else{
                                    if(typeid(laAction) == typeid(int))
                                    {
                                        action = atoi(laAction.c_str()) ; /// !!! Conversion de STR à INT en C++ !!!
                                        if(action > 6 || action < 0){
                                            afficher_lignes("   /!\\ ERREUR DE SAISIE /!\"", 14, 12) ;
                                            vrai = false ;
                                        }else{
                                            if(vieInitialeHeros < vdb_h){
                                                switch(action){
                                                default:{
                                                        vrai = true ;
                                                        break ;
                                                    }}
                                            }else{
                                                switch(action){
                                                case 0:{
                                                        afficher_lignes("ATTENTION: Votre vie est deja au maximum !", 14, 12) ; /// plus tard mesg erreur
                                                        vrai = false ;
                                                        break ;
                                                    }default:{
                                                        vrai = true ;
                                                        break ;
                                                    }}
                                            }
                                        }
                                    }else{
                                        SetConsoleTextAttribute(hConsole, 12);
                                        afficher_lignes(" /!\\ ERREUR DE SAISIE /!\\", 14, 12) ;
                                        vrai = false ;
                                    }
                                }
                            }
                            catch(std::string& erreur)
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                afficher_lignes("   /!\\ ERREUR DE SAISIE /!\"", 14, 12) ;
                            }

                        }/// while vrai == false

                        //--------------------------SAISIE JOUEUR----------------------------------------------------------------------------------
                        SetConsoleTextAttribute(hConsole, 14);
                        cout << endl << endl << endl << endl << endl;
                        afficher_lignes(" ************************** - DEROULEMENT - *************************", 14, 14) ;
                        SetConsoleTextAttribute(hConsole, 10);
                        //-------------------------------SE SOIGNER--------------------------------------
                        if (action == 0) //SE SOIGNER
                        {
                            compteurSeSoigner++;

                            recuperationVie = 10;
                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" A DECIDE DE SE SOIGNER", 14, 10) ;
                            afficher_lignes(" "+nomHeros+" RECUPERE 10 hp DE VIE", 14, 10) ;
                            afficher_lignes(" ", 14, 14);

                            vieInitialeHeros = vieInitialeHeros + recuperationVie;

                            if (vieInitialeHeros > 100)
                            {
                                vieInitialeHeros = 100;
                            }
                        }
                        //-------------------------------------------------------------------------------
                        //------------------------AMELIORER SON ATTAQUE----------------------------------
                        if (action == 1)
                        {
                            compteurAmeliorerArme++;

                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" A DECIDE D'AMELIORER SON ATTAQUE", 14, 10) ;
                            afficher_lignes(" "+nomArme+" DE "+nomHeros+" OBTIENT +10 DE DEGATS", 14, 10) ;

                            if (attaqueHeros > 100)
                            {
                                attaqueHeros = 100;
                            }
                            else
                            {
                                attaqueHeros = attaqueHeros + 15;
                            }
                        }
                        //-------------------------------------------------------------------------------
                        //------------------------ATTAQUER ENNEMI 1--------------------------------------
                        if (action == 2)
                        {
                            compteurAttaquer++;

                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" A DECIDE D'ATTAQUER "+nomEnnemi1, 14, 10) ;
                            afficher_lignes(" "+nomHeros+" ATTAQUE AVEC "+nomArme, 14, 10) ;
                            afficher_lignes(" ", 14, 14);

                            if (vieInitialeEnnemi1 < 0)
                            {
                                vieInitialeEnnemi1 = 0;
                            }
                            else
                            {
                                vieInitialeEnnemi1 = vieInitialeEnnemi1 - attaqueHeros;
                            }
                        }
                        //-------------------------------------------------------------------------------
                        //------------------------ATTAQUER ENNEMI 2--------------------------------------
                        if (action == 3)
                        {
                            compteurAttaquer++;

                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" A DECIDE D'ATTAQUER "+nomEnnemi2, 14, 10) ;
                            afficher_lignes(" "+nomHeros+" ATTAQUE AVEC "+nomArme, 14, 10) ;
                            afficher_lignes(" ", 14, 14);

                            if (vieInitialeEnnemi2 < 0)
                            {
                                vieInitialeEnnemi2 = 0;
                            }
                            else
                            {
                                vieInitialeEnnemi2 = vieInitialeEnnemi2 - attaqueHeros;
                            }
                        }
                        //------------------------ATTAQUER ENNEMI 3--------------------------------------
                        if (action == 4)
                        {
                            compteurAttaquer++;

                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" A DECIDE D'ATTAQUER "+nomEnnemi3, 14, 10) ;
                            afficher_lignes(" "+nomHeros+" ATTAQUE AVEC "+nomArme, 14, 10) ;
                            afficher_lignes(" ", 14, 14);

                            if (vieInitialeEnnemi3 < 0)
                            {
                                vieInitialeEnnemi3 = 0;
                            }
                            else
                            {
                                vieInitialeEnnemi3 = vieInitialeEnnemi3 - attaqueHeros;
                            }
                        }
                        // -----------------------DONNER DE LA VIE A ALLIE ---------------------------------
                        if (action == 5)
                        {
                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" ", 14, 14);
                            afficher_lignes(" "+nomHeros+" DONNE 10hp DE SA VIE A "+nomAllie, 14, 10) ;
                            afficher_lignes(" ", 14, 14);

                            vieInitialeAllie += 10;
                            vieInitialeHeros -= 10;

                            if(vieInitialeAllie > 100)
                            {
                                vieInitialeAllie = 100;
                            }
                        }

                        if(action == 99) ///FIN DU JEU
                        {
                            finJeu = 0 ;
                        }
                    }

                    else if(vieInitialeHeros <= 0)
                    {
                        SetConsoleTextAttribute(hConsole, 14);
                        cout << endl << endl << endl << endl << endl;
                        afficher_lignes(" ************************** - DEROULEMENT - *************************", 14, 14) ;
                        system("timeout /t 8 /nobreak > nul") ;
                    }


                    /// ------------------ IA (ou presque) - ALLIEE ----------------------- ///
                    if(vieInitialeAllie > 0)
                    {
                        SetConsoleTextAttribute(hConsole, 6);
                        int solution(0);
                        afficher_lignes(" ", 14, 14) ;
                        afficher_lignes("  // "+nomAllie+" PRENDS PART AU COMBAT \\\\", 14, 6) ;
                        afficher_lignes(" ", 14, 14) ;
                        SetConsoleTextAttribute(hConsole, 11);
                        solution = selection_action(vieInitialeAllie, attaqueAllie, vieInitialeHeros, attaqueHeros,
                                                    vieInitialeEnnemi1, vieInitialeEnnemi2, vieInitialeEnnemi3,
                                                    attaqueEnnemi1, attaqueEnnemi2, attaqueEnnemi3, type_IA);

                        switch(solution)
                        {
                        case 0: ///SE SOIGNER
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE DE SE SOIGNER ET RECUPERE 10hp DE VIE", 14, 11) ;
                            vieInitialeAllie += 10;
                            if(vieInitialeAllie > 100)
                            {
                                vieInitialeAllie = 100;
                            }
                            compteur_soigne_allie++;

                            break;
                        }
                        case 1: ///AMELIORER ATTAQUE
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE D'AMELIORER SON ATTAQUE", 14, 11) ;
                            attaqueAllie += 15;
                            compteur_ame_arme_allie++;
                            break;
                        }
                        case 2: ///ATTAQUER ENNEMI 1
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE D'ATTAQUER "+nomEnnemi1, 14, 11) ;
                            vieInitialeEnnemi1 -= attaqueAllie;
                            compteur_attaque_allie++;
                            break;
                        }
                        case 3: ///ATTAQUER ENNEMI 2
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE D'ATTAQUER "+nomEnnemi2, 14, 11) ;
                            vieInitialeEnnemi2 -= attaqueAllie;
                            compteur_attaque_allie++;
                            break;
                        }
                        case 4: /// ATTAQUER ENNEMI 3
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE D'ATTAQUER "+nomEnnemi3, 14, 11) ;
                            vieInitialeEnnemi3 -= attaqueAllie;
                            compteur_attaque_allie++;
                            break;
                        }
                        case 5: ///AIDER ALLIE
                        {
                            afficher_lignes(" "+nomAllie+" A DECIDE D'AIDER "+nomHeros, 14, 11) ;
                            afficher_lignes(" "+nomHeros+" RECUPERE 10 hp DE VIE DE "+nomAllie, 14, 11) ;
                            vieInitialeHeros += 10;
                            vieInitialeAllie -= 10;
                            compteur_aide_allie++;
                            break;
                        }
                        }

                    }
                    /// ------------------------------------------------------ ///

                    SetConsoleTextAttribute(hConsole, 4);
                    afficher_lignes(" ", 14, 14) ;
                    afficher_lignes("  // LES ENNEMIS RIPOSTENT ! \\\\", 14, 4) ;
                    afficher_lignes(" ", 14, 14) ;

                    /**--------------------------------------INTELLIGENCE ARTIFICIELLE (ou presque) ------------------------------------*/

                    SetConsoleTextAttribute(hConsole, 12);

                    /**---------------- I.A(000x01) -----------------------------*/
                    if (vieInitialeEnnemi1 > 0 && vieInitialeEnnemi1 <= vdb_e1)
                    {
                        int choix ;
                        switch(nv)
                        {
                        case 1:
                        {
                            if(vieInitialeAllie < vieInitialeHeros)
                            {
                                choix = 2 ;
                            }
                            else
                            {
                                choix = 4 ;
                            }
                            break;
                        }
                        default:
                        {
                            choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                 attaqueEnnemi1, vieInitialeEnnemi1, vieInitialeEnnemi2, attaqueEnnemi2,
                                                 attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeAllie, attaqueAllie);
                            break;
                        }
                        }

                        if(action == 0 && choix == 2)
                        {
                            choix = 0;
                        }

                        if(vieInitialeAllie <= 0 && choix == 4)
                        {
                            choix = 2;
                        }

                        switch(choix)
                        {
                        case 0: ///SE SOIGNER
                        {
                            vieInitialeEnnemi1 += 10;
                            afficher_lignes(" "+nomEnnemi1+" SE SOIGNE ET RECUPERE 10hp DE VIE.", 14, 12) ;
                            break;
                        }
                        case 1: ///AMELIORER SON ATTAQUE
                        {
                            attaqueEnnemi1 += 10;
                            afficher_lignes(" "+nomEnnemi1+" AMELIORE SON ATTAQUE.", 14, 12) ;
                            break;
                        }
                        case 2: ///ATTAQUER
                        {
                            if(action != 0)
                            {
                                vieInitialeHeros -= attaqueEnnemi1;
                                afficher_lignes(" "+nomEnnemi1+" ATTAQUE "+nomHeros, 14, 12) ;
                                break;
                            }
                        }
                        case 3: ///DONNER SA VIE
                        {
                            vieInitialeEnnemi1-=10;
                            if(vieInitialeEnnemi2 < vieInitialeEnnemi3)
                            {
                                vieInitialeEnnemi2+=10;
                                afficher_lignes(" "+nomEnnemi1+" DONNE 10hp DE SA VIE A "+nomEnnemi2, 14, 12) ;
                            }
                            else
                            {
                                vieInitialeEnnemi3+=10;
                                afficher_lignes(" "+nomEnnemi1+" DONNE 10hp DE SA VIE A "+nomEnnemi3, 14, 12) ;
                            }

                            break;
                        }
                        case 4: ///ATTAQUER ALLIE JOUEUR
                        {
                            afficher_lignes(" "+nomEnnemi1+" A DECIDE D'ATTAQUER "+nomAllie, 14, 12) ;
                            vieInitialeAllie -= attaqueEnnemi1;

                            break;
                        }
                        }
                    }
                    /**--------------- END-I.A(000x01) --------------------------*/

                    afficher_lignes(" ", 14, 14);

                    /**---------------- I.A(000x02) -----------------------------*/
                    if (vieInitialeEnnemi2 > 0 && vieInitialeEnnemi2 <= vdb_e2)
                    {
                        int choix ;
                        switch(nv)
                        {
                        case 1:
                        {
                            if(vieInitialeAllie < vieInitialeHeros)
                            {
                                choix = 2 ;
                            }
                            else
                            {
                                choix = 4 ;
                            }
                            break;
                        }
                        default:
                        {
                            choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                 attaqueEnnemi1, vieInitialeEnnemi1, vieInitialeEnnemi2, attaqueEnnemi2,
                                                 attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeAllie, attaqueAllie);
                            break;
                        }
                        }

                        if(action == 0 && choix == 2)
                        {
                            choix = 0;
                        }

                        if(vieInitialeAllie <= 0 && choix == 4)
                        {
                            choix = 2;
                        }

                        switch(choix)
                        {
                        case 0: ///SE SOIGNER
                        {
                            vieInitialeEnnemi2 += 10;
                            afficher_lignes(" "+nomEnnemi2+" SE SOIGNE ET RECUPERE 10hp.", 14, 12) ;
                            break;
                        }
                        case 1: ///AMELIORER SON ATTAQUE
                        {
                            attaqueEnnemi2 += 10;
                            afficher_lignes(" "+nomEnnemi2+" AMELIORE SON ATTAQUE.", 14, 12) ;
                            break;
                        }
                        case 2: ///ATTAQUER
                        {
                            if(action != 0)
                            {
                                vieInitialeHeros -= attaqueEnnemi2;
                                afficher_lignes(" "+nomEnnemi2+" ATTAQUE "+nomHeros, 14, 12) ;
                                break;
                            }
                        }
                        case 3: ///DONNER SA VIE
                        {
                            vieInitialeEnnemi2-=10;

                            if(vieInitialeEnnemi1 < vieInitialeEnnemi3)
                            {
                                vieInitialeEnnemi1+=10;
                                afficher_lignes(" "+nomEnnemi2+" DONNE 10hp DE SA VIE A "+nomEnnemi1, 14, 12) ;
                            }
                            else
                            {
                                afficher_lignes(" "+nomEnnemi2+" DONNE 10hp DE SA VIE A "+nomEnnemi3, 14, 12) ;
                                vieInitialeEnnemi3+=10;
                            }

                            break;
                        }
                        case 4: ///ATTAQUER ALLIE JOUEUR
                        {
                            afficher_lignes(" "+nomEnnemi2+" ATTAQUE "+nomAllie, 14, 12) ;
                            vieInitialeAllie -= attaqueEnnemi2;

                            break;
                        }
                        }
                    }
                    /**--------------- END-I.A(000x02) --------------------------*/

                    afficher_lignes(" ", 14, 14) ;

                    /**---------------- I.A(000x03) -----------------------------*/
                    if (vieInitialeEnnemi3 > 0 && vieInitialeEnnemi3 <= vdb_e3)
                    {
                        int choix ;
                        switch(nv)
                        {
                        case 1:
                        {
                            if(vieInitialeAllie < vieInitialeHeros)
                            {
                                choix = 2 ;
                            }
                            else
                            {
                                choix = 4 ;
                            }
                            break;
                        }
                        default:
                        {
                            choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                 attaqueEnnemi1, vieInitialeEnnemi1, vieInitialeEnnemi2, attaqueEnnemi2,
                                                 attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeAllie, attaqueAllie);
                            break;
                        }
                        }

                        if(action == 0 && choix == 2)
                        {
                            choix = 0;
                        }

                        if(vieInitialeAllie <= 0 && choix == 4)
                        {
                            choix = 2;
                        }

                        switch(choix)
                        {
                        case 0: ///SE SOIGNER
                        {
                            vieInitialeEnnemi3 += 10;
                            afficher_lignes(" "+nomEnnemi3+" SE SOIGNE ET RECUPERE 10hp DE VIE", 14, 12) ;
                            break;
                        }
                        case 1: ///AMELIORER SON ATTAQUE
                        {
                            attaqueEnnemi3 += 10;
                            afficher_lignes(" "+nomEnnemi3+" AMELIORE SON ATTAQUE", 14, 12) ;
                            break;
                        }
                        case 2: ///ATTAQUER
                        {
                            if(action != 0)
                            {
                                vieInitialeHeros -= attaqueEnnemi3;
                                afficher_lignes(" "+nomEnnemi3+" ATTAQUE "+nomHeros, 14, 12) ;
                                break;
                            }
                        }
                        case 3: ///DONNER SA VIE
                        {
                            vieInitialeEnnemi3-=10;

                            if(vieInitialeEnnemi2 < vieInitialeEnnemi1)
                            {
                                vieInitialeEnnemi2+=10;
                                afficher_lignes(" "+nomEnnemi3+" DONNE 10hp DE VIE A "+nomEnnemi1, 14, 12) ;
                            }
                            else
                            {
                                vieInitialeEnnemi1+=10;
                                afficher_lignes(" "+nomEnnemi3+" DONNE 10hp DE VIE A "+nomEnnemi2, 14, 12) ;
                            }

                            break;
                        }
                        case 4: ///ATTAQUER ALLIE JOUEUR
                        {
                            afficher_lignes(" "+nomEnnemi3+" A DECIDE D'ATTAQUER "+nomAllie, 14, 12) ;
                            vieInitialeAllie -= attaqueEnnemi3;

                            break;
                        }
                        }
                    }
                    /**--------------- END-I.A(000x03) --------------------------*/

                    /**--------------------------------------INTELLIGENCE ARTIFICIELLE------------------------------------*/




                    if(vieInitialeAllie <= 0 && allie_est_mort == 0)
                    {
                        allie_est_mort++;

                        attaqueHeros += attaqueAllie;
                        SetConsoleTextAttribute(hConsole, 12);
                        afficher_lignes(" "+nomAllie+" EST MORT -> "+nomHeros+" RECUPERE SON ATTAQUE", 14, 14) ;
                    }

                    afficher_lignes(" ", 14, 14) ;
                    SetConsoleTextAttribute(hConsole, 14);
                    afficher_lignes(" ************************** - DEROULEMENT - *************************", 14, 14) ;


                    if (vieInitialeEnnemi1 <= 0)
                    {
                        vieInitialeEnnemi1 = 0;
                    }
                    if (vieInitialeEnnemi2 <= 0)
                    {
                        vieInitialeEnnemi2 = 0;
                    }
                    if (vieInitialeEnnemi3 <= 0)
                    {
                        vieInitialeEnnemi3 = 0;
                    }
                    if(vieInitialeAllie <= 0)
                    {
                        vieInitialeAllie = 0;
                    }

                    if (vieInitialeEnnemi1 > vdb_e1)
                    {
                        vieInitialeEnnemi1 = vdb_e1;
                    }
                    if (vieInitialeEnnemi2 > vdb_e2)
                    {
                        vieInitialeEnnemi2 = vdb_e2;
                    }
                    if (vieInitialeEnnemi3 > vdb_e3)
                    {
                        vieInitialeEnnemi3 = vdb_e3;
                    }

                    vieTotaleDesEnnemis = vieInitialeEnnemi1 + vieInitialeEnnemi2 + vieInitialeEnnemi3;

                    if (vieInitialeHeros <= 0 && vieInitialeAllie <= 0)
                    {
                        system("timeout /t 2 /nobreak > nul") ;
                        system("cls");
                        cout << endl;
                        afficher_fin(false) ;
                        finJeu = 0;
                        a_gagne = false;
                        //system("pause");
                        cout << endl << endl << endl;
                        cout << " ///> RECOMMENCER CE NIVEAU ? (oui/non) >";
                        getline(cin, rejouer) ;
                        getline(cin, rejouer) ;
                    }

                    if (vieTotaleDesEnnemis <= 0)
                    {
                        system("timeout /t 2 /nobreak > nul") ;
                        system("cls");
                        afficher_fin(true) ;
                        finJeu = 0;
                        a_gagne = true;
                        ///system("pause");
                        cout << endl << endl << endl;
                        cout << " /// >BRAVO, VOUS AVEZ FRANCHI LE NIVEAU " << nv << " ! CONTINUER ? (oui/non) >";
                        getline(cin, rejouer) ;
                        getline(cin, rejouer) ;
                    }

                    ///system("pause");

                }
                while(finJeu != 0); ///BOUCLE PRINCIPALE DU JEU


                if(rejouer == "non")
                {
                    finJeu = 0 ;
                }
                else
                {
                    if(a_gagne == true)
                    {
                        if(nv < 4)
                        {
                            nv++ ;
                            nbParties++ ;
                            finJeu = 1 ;
                            compteurDeTours = 0 ;
                        }
                        else
                        {
                            finJeu = 0 ;
                        }
                    }
                    else
                    {
                        nbParties++ ;
                        finJeu = 1 ;
                        compteurDeTours = 0 ;
                    }
                }

            }
            while(finJeu != 0) ;

            if(finJeu == 0)
            {

                afficher_scores(nomHeros, nomAllie, a_gagne, compteurAttaquer, compteurAmeliorerArme, compteurSeSoigner,
                                compteurDeTours, compteurTotal, compteur_attaque_allie, compteur_ame_arme_allie, compteur_soigne_allie,
                                compteur_aide_allie);

                compteurTotal = compteurAmeliorerArme + compteurAttaquer + compteurSeSoigner + compteurDeTours;
                score_initial -= compteurTotal;

                compteurTotal = compteurAmeliorerArme + compteurAttaquer + compteurDeTours + compteurSeSoigner;

                string const fichierScores("C:/users/sébastien/desktop/scoresJoueurs.txt");
                ofstream scoresJoueurs(fichierScores.c_str(), ios::app);
                system("cls");
                cout << endl;

    //----------------------ECRITURE SCORES---------------------

                if(scoresJoueurs)
                {
                    scoresJoueurs << "SCORE DE : " << nomJoueur << " >> " << score_initial << "// AVEC " << nomHeros << " ET " << nomArme << " CONTRE " << nomEnnemi1 << ", " << nomEnnemi2 << " ET " << nomEnnemi3 << endl;
                    scoresJoueurs << endl;
                }
                else
                {
                    cout << "ERREUR : IMPOSSIBLE D'OUVRIR LE FICHIER " << endl;
                }

                cout << endl;
                system("pause");
                /**system("read /p"); --> LINUX*/
            }
        }

        else if(setup == 2) /// MODE SIMULATION
        {

            int vieHeros ;
            int vieAllie ;
            int vieE1 ;
            int vieE2 ;
            int vieE3 ;

            int attaqueDuHeros ;
            int attaqueDeAllie ;
            int attaqueE1 ;
            int attaqueE2 ;
            int attaqueE3 ;

            int action ;
            int nbParties = 0 ;

            //int type_IA = 1;

            int victoires = 0 ;
            int defaites = 0 ;
            //int moyenne = 0 ;
            double pourcentage = 0 ;

            bool finJeu =false ;

            system("cls") ;
            cout << endl << "   - Simulation -" << endl << endl;
            cout << " (avant d'entamer une simulation," << endl;
            cout << "  quelques parametres doivent etre saisis.)" << endl << endl;
            cout << endl << "   - vies -" << endl;
            cout << endl << " 1) Vie du heros       : ";
            cin >> vieHeros ;
            cout << endl << " 2) Vie de l'Allie     : " ;
            cin >> vieAllie ;
            cout << endl << " 3) Vie de l'ennemi 1  : " ;
            cin >> vieE1 ;
            cout << endl << " 4) Vie de l'ennemi 2  : " ;
            cin >> vieE2 ;
            cout << endl << " 5) Vie de l'ennemi 3  : " ;
            cin >> vieE3 ;
            cout << endl << endl << " - Attaques - " << endl;
            cout << endl << " 1) Attaque Heros      : " ;
            cin >> attaqueDuHeros ;
            cout << endl << " 2) Attaque Allie      : " ;
            cin >> attaqueDeAllie ;
            cout << endl << " 3) Attaque Ennemi 1   : " ;
            cin >> attaqueE1 ;
            cout << endl << " 3) Attaque Ennemi 2   : " ;
            cin >> attaqueE2 ;
            cout << endl << " 3) Attaque Ennemi 3   : " ;
            cin >> attaqueE3 ;
            /*cout << endl << endl << "   - Option de l'IA - " << endl ;
            cout << endl << " 1) Type d'IA          :" ;
            cin >> type_IA ;*/

            cout << endl << endl ;

            //------------VARIABLES---------------

            int compteurDeTours = 0;
            string nomHeros;
            string nomAllie;
            string nomJoueur;
            string nomEnnemi1;
            string nomEnnemi2;
            string nomEnnemi3;
            string nomArme;
            string nomArmeAllie ;
            string nomsEnnemis[3] ;
            string rejouer ;

            /**----- CONSTANTES / VARIABLES -----*/

            int attaqueEnnemi1 = attaqueE1;
            int attaqueEnnemi2 = attaqueE2;
            int attaqueEnnemi3 = attaqueE3;
            int attaqueHeros ;
            int attaqueAllie ;
            //int vdb_h = vieHeros;
            //int vdb_a = vieAllie;
            int vdb_e1 = vieE1;
            int vdb_e2 = vieE2;
            int vdb_e3 = vieE3;
            int allie_est_mort = 0;
            //int score_initial = 100;
            int recuperationVie;
            int vieTotaleDesEnnemis;
            /**int choixArme;*/
            int compteurSeSoigner(0);
            int compteurAmeliorerArme(0);
            int compteurAttaquer(0);
            //int compteurTotal(0);
            int compteur_soigne_allie(0);
            int compteur_attaque_allie(0);
            int compteur_ame_arme_allie(0);
            int compteur_aide_allie(0);
            //int compteur_total_allie(0);
            bool a_gagne;
            string niv ;
            int nv ;
            int attaque_heros_base = 5 ;
            int attaque_allie_base = 5 ;


            system("cls") ;

            cout << "   - Lancement de la simulation - " << endl << endl ;

            bool tourJoueur = true ;

        for(int n=1;n<5;n++)
        {
            for(int i=1; i<4; i++)
            {
                for(int j=1; j<4; j++)
                {
                        finJeu = 1 ;

                        int vieInitialeAllie = vieAllie ;
                        int vieInitialeHeros = vieHeros ;
                        int vieInitialeEnnemi1 = vieE1 ;
                        int vieInitialeEnnemi2 = vieE2 ;
                        int vieInitialeEnnemi3 = vieE3 ;

                        attaqueHeros =  attaqueDuHeros ;
                        attaqueAllie = attaqueDeAllie ;
                        attaqueEnnemi1 = attaqueE1 ;
                        attaqueEnnemi2 = attaqueE2 ;
                        attaqueEnnemi3 = attaqueE3 ;

                        do /// BOUCLE PRINCIPALE DU JEU
                        {
                            //system("cls");

                            compteurDeTours++;
                            if(compteurDeTours == 1)
                            {
                                attaque_heros_base = attaqueHeros ;
                                attaque_allie_base = attaqueAllie ;
                            }



                            if(vieInitialeHeros > 0)
                            {
                                action = selection_action(vieInitialeHeros, attaqueHeros, vieInitialeAllie, attaqueAllie,
                                                          vieInitialeEnnemi1, vieInitialeEnnemi2, vieInitialeEnnemi3,
                                                          attaqueEnnemi1, attaqueEnnemi2, attaqueEnnemi3, i);

                                //cout << "Niveau IA Heros : " << i << endl;

                                //cout << " Action du Personnage : " << action << endl ;

                                //--------------------------SAISIE JOUEUR----------------------------------------------------------------------------------
                                //-------------------------------SE SOIGNER--------------------------------------
                                if (action == 0) //SE SOIGNER
                                {
                                    compteurSeSoigner++;

                                    vieInitialeHeros = vieInitialeHeros + recuperationVie;

                                    if (vieInitialeHeros > 100)
                                    {
                                        vieInitialeHeros = 100;
                                    }
                                }
                                //-------------------------------------------------------------------------------
                                //------------------------AMELIORER SON ATTAQUE----------------------------------
                                if (action == 1)
                                {
                                    compteurAmeliorerArme++;

                                    if (attaqueHeros > 100)
                                    {
                                        attaqueHeros = 100;
                                    }
                                    else
                                    {
                                        attaqueHeros = attaqueHeros + 15;
                                    }
                                }
                                //-------------------------------------------------------------------------------
                                //------------------------ATTAQUER ENNEMI 1--------------------------------------
                                if (action == 2)
                                {
                                    compteurAttaquer++;

                                    if (vieInitialeEnnemi1 < 0)
                                    {
                                        vieInitialeEnnemi1 = 0;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi1 = vieInitialeEnnemi1 - attaqueHeros;
                                    }
                                }
                                //-------------------------------------------------------------------------------
                                //------------------------ATTAQUER ENNEMI 2--------------------------------------
                                if (action == 3)
                                {
                                    compteurAttaquer++;

                                    if (vieInitialeEnnemi2 < 0)
                                    {
                                        vieInitialeEnnemi2 = 0;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi2 = vieInitialeEnnemi2 - attaqueHeros;
                                    }
                                }
                                //------------------------ATTAQUER ENNEMI 3--------------------------------------
                                if (action == 4)
                                {
                                    compteurAttaquer++;

                                    if (vieInitialeEnnemi3 < 0)
                                    {
                                        vieInitialeEnnemi3 = 0;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi3 = vieInitialeEnnemi3 - attaqueHeros;
                                    }
                                }
                                // -----------------------DONNER DE LA VIE A ALLIE ---------------------------------
                                if (action == 5)
                                {
                                    vieInitialeAllie += 10;
                                    vieInitialeHeros -= 10;

                                    if(vieInitialeAllie > 100)
                                    {
                                        vieInitialeAllie = 100;
                                    }
                                }

                                if(action == 99) ///FIN DU JEU
                                {
                                    finJeu = 0 ;
                                }
                            }


                            /// ------------------ IA (ou presque) - ALLIEE ----------------------- ///
                            if(vieInitialeAllie > 0)
                            {
                                int solution(0);
                                solution = selection_action(vieInitialeAllie, attaqueAllie, vieInitialeHeros, attaqueHeros,
                                                            vieInitialeEnnemi1, vieInitialeEnnemi2, vieInitialeEnnemi3,
                                                            attaqueEnnemi1, attaqueEnnemi2, attaqueEnnemi3, j);

                                //cout << "Type IA Allie : " << j << endl;
                                //cout << " Action de l'Allie :" << solution << endl;

                                switch(solution)
                                {
                                case 0: ///SE SOIGNER
                                {
                                    vieInitialeAllie += 10;
                                    if(vieInitialeAllie > 100)
                                    {
                                        vieInitialeAllie = 100;
                                    }
                                    compteur_soigne_allie++;

                                    break;
                                }
                                case 1: ///AMELIORER ATTAQUE
                                {
                                    attaqueAllie += 15;
                                    compteur_ame_arme_allie++;
                                    break;
                                }
                                case 2: ///ATTAQUER ENNEMI 1
                                {
                                    vieInitialeEnnemi1 -= attaqueAllie;
                                    compteur_attaque_allie++;
                                    break;
                                }
                                case 3: ///ATTAQUER ENNEMI 2
                                {
                                    vieInitialeEnnemi2 -= attaqueAllie;
                                    compteur_attaque_allie++;
                                    break;
                                }
                                case 4: /// ATTAQUER ENNEMI 3
                                {
                                    vieInitialeEnnemi3 -= attaqueAllie;
                                    compteur_attaque_allie++;
                                    break;
                                }
                                case 5: ///AIDER ALLIE
                                {
                                    vieInitialeHeros += 10;
                                    vieInitialeAllie -= 10;
                                    compteur_aide_allie++;
                                    break;
                                }
                                }

                            }
                            /// ------------------------------------------------------ //

                            /**--------------------------------------INTELLIGENCE ARTIFICIELLE (ou presque) ------------------------------------*/


                            /**---------------- I.A(000x01) -----------------------------*/
                            if (vieInitialeEnnemi1 > 0 && vieInitialeEnnemi1 <= vdb_e1)
                            {
                                int choix ;

                                switch(n)
                                {
                                case 1:
                                {
                                    if(vieInitialeAllie < vieInitialeHeros)
                                    {
                                        choix = 2 ;
                                    }
                                    else
                                    {
                                        choix = 4 ;
                                    }
                                    break;
                                }
                                default:
                                {
                                choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                    attaqueEnnemi1, vieInitialeEnnemi1, vieInitialeEnnemi2, attaqueEnnemi2,
                                                    attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeAllie, attaqueAllie);
                                    break;
                                }
                                }


                                if(action == 0 && choix == 2)
                                {
                                    choix = 0;
                                }

                                if(vieInitialeAllie <= 0 && choix == 4)
                                {
                                    choix = 2;
                                }

                                //cout << " Action de Ennemi 1 : " << choix << endl;

                                switch(choix)
                                {
                                case 0: ///SE SOIGNER
                                {
                                    vieInitialeEnnemi1 += 10;
                                    break;
                                }
                                case 1: ///AMELIORER SON ATTAQUE
                                {
                                    attaqueEnnemi1 += 10;
                                    break;
                                }
                                case 2: ///ATTAQUER
                                {
                                    if(action != 0)
                                    {
                                        vieInitialeHeros -= attaqueEnnemi1;
                                        break;
                                    }
                                }
                                case 3: ///DONNER SA VIE
                                {
                                    vieInitialeEnnemi1-=10;
                                    if(vieInitialeEnnemi2 < vieInitialeEnnemi3)
                                    {
                                        vieInitialeEnnemi2+=10;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi3+=10;
                                    }

                                    break;
                                }
                                case 4: ///ATTAQUER ALLIE JOUEUR
                                {
                                    vieInitialeAllie -= attaqueEnnemi1;

                                    break;
                                }
                                }
                            }
                            /**--------------- END-I.A(000x01) --------------------------*/

                            /**---------------- I.A(000x02) -----------------------------*/
                            if (vieInitialeEnnemi2 > 0 && vieInitialeEnnemi2 <= vdb_e2)
                            {
                                int choix ;


                                switch(n)
                                {
                                case 1:
                                {
                                    if(vieInitialeAllie < vieInitialeHeros)
                                    {
                                        choix = 2 ;
                                    }
                                    else
                                    {
                                        choix = 4 ;
                                    }
                                    break;
                                }
                                default:
                                {
                                choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                    attaqueEnnemi2, vieInitialeEnnemi2, vieInitialeEnnemi1, attaqueEnnemi1,
                                                    attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeAllie, attaqueAllie);
                                    break;
                                }
                                }


                                if(action == 0 && choix == 2)
                                {
                                    choix = 0;
                                }

                                if(vieInitialeAllie <= 0 && choix == 4)
                                {
                                    choix = 2;
                                }

                                //cout << " Action de Ennemi 2 : " << choix << endl;

                                switch(choix)
                                {
                                case 0: ///SE SOIGNER
                                {
                                    vieInitialeEnnemi2 += 10;
                                    break;
                                }
                                case 1: ///AMELIORER SON ATTAQUE
                                {
                                    attaqueEnnemi2 += 10;
                                    break;
                                }
                                case 2: ///ATTAQUER
                                {
                                    if(action != 0)
                                    {
                                        vieInitialeHeros -= attaqueEnnemi2;
                                        break;
                                    }
                                }
                                case 3: ///DONNER SA VIE
                                {
                                    vieInitialeEnnemi2-=10;

                                    if(vieInitialeEnnemi1 < vieInitialeEnnemi3)
                                    {
                                        vieInitialeEnnemi1+=10;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi3+=10;
                                    }

                                    break;
                                }
                                case 4: ///ATTAQUER ALLIE JOUEUR
                                {
                                    vieInitialeAllie -= attaqueEnnemi2;

                                    break;
                                }
                                }
                            }
                            /**--------------- END-I.A(000x02) --------------------------*/

                            /**---------------- I.A(000x03) -----------------------------*/
                            if (vieInitialeEnnemi3 > 0 && vieInitialeEnnemi3 <= vdb_e3)
                            {
                                int choix ;

                                switch(n)
                                {
                                case 1:
                                {
                                    if(vieInitialeAllie < vieInitialeHeros)
                                    {
                                        choix = 2 ;
                                    }
                                    else
                                    {
                                        choix = 4 ;
                                    }
                                    break;
                                }
                                default:
                                {
                                choix = choix_action(attaqueHeros, vieInitialeHeros,
                                                    attaqueEnnemi3, vieInitialeEnnemi3, vieInitialeEnnemi2, attaqueEnnemi2,
                                                    attaqueEnnemi1, vieInitialeEnnemi1, vieInitialeAllie, attaqueAllie);
                                    break;
                                }
                                }


                                if(action == 0 && choix == 2)
                                {
                                    choix = 0;
                                }

                                if(vieInitialeAllie <= 0 && choix == 4)
                                {
                                    choix = 2;
                                }

                                //cout << " Action de l'ennemi 3 : " << choix << endl;

                                switch(choix)
                                {
                                case 0: ///SE SOIGNER
                                {
                                    vieInitialeEnnemi3 += 10;
                                    break;
                                }
                                case 1: ///AMELIORER SON ATTAQUE
                                {
                                    attaqueEnnemi3 += 10;
                                    break;
                                }
                                case 2: ///ATTAQUER
                                {
                                    if(action != 0)
                                    {
                                        vieInitialeHeros -= attaqueEnnemi3;
                                        break;
                                    }
                                }
                                case 3: ///DONNER SA VIE
                                {
                                    vieInitialeEnnemi3-=10;

                                    if(vieInitialeEnnemi2 < vieInitialeEnnemi1)
                                    {
                                        vieInitialeEnnemi2+=10;
                                    }
                                    else
                                    {
                                        vieInitialeEnnemi1+=10;
                                    }

                                    break;
                                }
                                case 4: ///ATTAQUER ALLIE JOUEUR
                                {
                                    vieInitialeAllie -= attaqueEnnemi3;

                                    break;
                                }
                                }
                            }
                            /**--------------- END-I.A(000x03) --------------------------*/

                            /**--------------------------------------INTELLIGENCE ARTIFICIELLE------------------------------------*/




                            if(vieInitialeAllie <= 0 && allie_est_mort == 0)
                            {
                                allie_est_mort++;

                                attaqueHeros += attaqueAllie;
                            }


                            if (vieInitialeEnnemi1 <= 0)
                            {
                                vieInitialeEnnemi1 = 0;
                            }
                            if (vieInitialeEnnemi2 <= 0)
                            {
                                vieInitialeEnnemi2 = 0;
                            }
                            if (vieInitialeEnnemi3 <= 0)
                            {
                                vieInitialeEnnemi3 = 0;
                            }
                            if(vieInitialeAllie <= 0)
                            {
                                vieInitialeAllie = 0;
                            }

                            if (vieInitialeEnnemi1 > vdb_e1)
                            {
                                vieInitialeEnnemi1 = vdb_e1;
                            }
                            if (vieInitialeEnnemi2 > vdb_e2)
                            {
                                vieInitialeEnnemi2 = vdb_e2;
                            }
                            if (vieInitialeEnnemi3 > vdb_e3)
                            {
                                vieInitialeEnnemi3 = vdb_e3;
                            }

                            vieTotaleDesEnnemis = vieInitialeEnnemi1 + vieInitialeEnnemi2 + vieInitialeEnnemi3;

                            if (vieInitialeHeros <= 0 && vieInitialeAllie <= 0)
                            {
                                finJeu = 0;
                                a_gagne = false;
                                defaites++ ;
                                nbParties++ ;
                            }

                            if (vieTotaleDesEnnemis <= 0)
                            {
                                finJeu = 0;
                                a_gagne = true;
                                victoires++ ;
                                nbParties++ ;
                            }

                        }
                        while(finJeu != 0); ///BOUCLE PRINCIPALE DU JEU

                    //system("cls") ;
                    //system("pause") ;
                }
            }
        }

            /// -- Calcul de fin --

            if(victoires != 0 && defaites != 0){
                pourcentage = ((victoires / defaites) * 100) / 2 ;
            }else if(victoires == 0 || defaites == 0){
                if(victoires == 0){
                    victoires = 1 ;
                    pourcentage = ((victoires / defaites) * 100) / 2 ;
                    victoires = 0 ;
                }else{
                    defaites = 1 ;
                    pourcentage = ((victoires / defaites) * 100) / 2 ;
                    defaites =  0;
                }
                pourcentage = ((victoires / defaites) * 100) / 2 ;
            }
            system("cls") ;

            cout << endl << " Rapport de la simulation" << endl;
            cout << " ------------------------" << endl << endl;
            cout << " Nombre de victoires : " << victoires << endl;
            cout << " Nombre de defaites  : " << defaites << endl << endl;
            cout << " Selon la simulation et les calculs de l'ordinateur, " << endl;
            cout << " vous avez " << pourcentage << "% de chances de remporter cette partie." << endl << endl;
            cout << endl << " - Fin de la simulation - " << endl << endl;
            system("pause") ;

        }


        else if(setup == 3) ///MODE ONLINE ?
        {
            /// EN DEVELOPPEMENT

            /**
                TELECHARGER SFML ET APPLIQUER
                METTRE EN PLACE CLIENT/SERVEUR
                ETC ...
            */
        }

        else if(setup == 4) /// PEUT ETRE UN MODE ADMIN ?
        {
            /**
                POUR MODIFIER LA TAILLE DE LA FENETRE
                    (REDUIRE LARGEUR + REDUIRE LONGUEUR)
                *

            */
        }
    }
}






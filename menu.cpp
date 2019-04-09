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
#include "IA_ALLIE.h"
#include "menu.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void afficher_interface(int vieInitialeHeros, int attaqueHeros, int vieInitialeAllie, int attaqueAllie,
                        int vieInitialeEnnemi1, int vieInitialeEnnemi2, int vieInitialeEnnemi3,
                        int attaqueEnnemi1, int attaqueEnnemi2, int attaqueEnnemi3,
                        std::string nomHeros, std::string nomAllie, std::string nomEnnemi1, std::string nomEnnemi2, std::string nomEnnemi3,
                        int tours, int vdb_h, int vdb_a, int vdb_e1, int vdb_e2, int vdb_e3, std::string nomArme, std::string nomArmeAllie)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl;
    if (tours < 1)
    {
        //SetConsoleTextAttribute(hConsole, 11);
        cout << " AINSI DEBUTENT LES AVENTURES DE " << nomHeros << " ET DE " << nomAllie << endl;
        cout << endl;
    }

//-------------------MENU--------------------


    cout << endl;

    SetConsoleTextAttribute(hConsole, 7);
    cout << " * " ;
    for(int i=0; i<34; i++)
    {
        if(i%2==0)
        {
            SetConsoleTextAttribute(hConsole, 7);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 8);
        }
        cout << "//";
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << " *" << endl << endl;

    SetConsoleTextAttribute(hConsole, 7);
    cout << " ETAT DE " << nomHeros;
    cout << " (";
    if(vieInitialeHeros > (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3 + 30))
    {
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << vieInitialeHeros;
    }
    else if(vieInitialeHeros == (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3 + 30))
    {
        SetConsoleTextAttribute(hConsole, 14) ;
        cout << vieInitialeHeros;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 12) ;
        cout << vieInitialeHeros ;
    }

    SetConsoleTextAttribute(hConsole, 7) ;
    cout << "/" << vdb_h << ")" << " ATTAQUE AVEC " << nomArme;

    if (vieInitialeHeros < 30)
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << " [CONSEIL] ";
        SetConsoleTextAttribute(hConsole, 8);
        cout << " SOIGNEZ VOUS" << endl;
    }
    else
    {
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 7) ;
    cout << " QUI CAUSE MAINTENANT ";
    if(attaqueHeros == 5)
    {
        SetConsoleTextAttribute(hConsole, 12) ;
        cout << attaqueHeros ;
    }
    else if(attaqueHeros >= 20 && attaqueHeros < 50)
    {
        SetConsoleTextAttribute(hConsole, 14) ;
        cout << attaqueHeros ;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << attaqueHeros ;
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << "hp DE DEGATS" ;
    if (attaqueHeros <= 10)
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << " [CONSEIL:";
        SetConsoleTextAttribute(hConsole, 8);
        cout << " AMELIOREZ VOTRE ARME";
        SetConsoleTextAttribute(hConsole, 14) ;
        cout << "]" << endl;
    }
    else if ((attaqueHeros >= 90 && vieInitialeHeros > 100) &&
             (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3) < vieInitialeHeros - (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3))
    {
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << " [CONSEIL: ";
        SetConsoleTextAttribute(hConsole, 8) ;
        cout << " TUEZ-LES";
        SetConsoleTextAttribute(hConsole, 12) ;
        cout << " TOUS.";
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << "]" << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << "  [OK]" << endl << endl;
    }

    if(vieInitialeAllie > 0)
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << endl << " ETAT DE " << nomAllie << " : (";
        if(vieInitialeAllie > (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3 + 30))
        {
            SetConsoleTextAttribute(hConsole, 10) ;
            cout << vieInitialeAllie ;
        }
        else if(vieInitialeAllie <= (attaqueEnnemi1 + attaqueEnnemi2 + attaqueEnnemi3))
        {
            SetConsoleTextAttribute(hConsole, 14) ;
            cout << vieInitialeAllie ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12) ;
            cout << vieInitialeAllie ;
        }

        SetConsoleTextAttribute(hConsole, 7) ;
        cout << "/" << vdb_a << ")";
        if(vieInitialeAllie < (attaqueEnnemi1+attaqueEnnemi2+attaqueEnnemi3))
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "  [ATTENTION]" << endl;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "  [OK]" << endl;
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << " ATTAQUE AVEC " << nomArmeAllie << " QUI CAUSE ";

        if(attaqueAllie == 5)
        {
            SetConsoleTextAttribute(hConsole, 12) ;
            cout << attaqueAllie ;
        }
        else if(attaqueAllie >= 20 && attaqueAllie <= 35)
        {
            SetConsoleTextAttribute(hConsole, 14) ;
            cout << attaqueAllie ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 10) ;
            cout << attaqueAllie ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "hp DE DEGATS" << endl ;

    }
    else
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << nomAllie << " EST ";
        SetConsoleTextAttribute(hConsole, 12) ;
        cout << "MORT.";
        SetConsoleTextAttribute(hConsole, 7) ;
        cout << " (PAR VOTRE FAUTE)." << endl;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << endl << " * " ;
    for(int i=0; i<34; i++)
    {
        if(i%2==0)
        {
            SetConsoleTextAttribute(hConsole, 7);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 8);
        }
        cout << "\\\\";
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << " *" << endl;

    cout << endl ;
    SetConsoleTextAttribute(hConsole, 7);
    cout << " ----------------------------";
    SetConsoleTextAttribute(hConsole, 11);
    cout << " [TOUR NUMERO " << tours << "]";
    SetConsoleTextAttribute(hConsole, 7);
    cout << " ----------------------------";
    cout << endl;
    SetConsoleTextAttribute(hConsole, 9);
    cout << endl << " ACTIONS POSSIBLES : " << endl;
    cout << endl;

    if(vieInitialeHeros < 200)
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << " [0] - RECUPERER DE LA ";
        SetConsoleTextAttribute(hConsole, 10) ;
        cout << "VIE" << endl;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << " [1] - AMELIORER ";
    SetConsoleTextAttribute(hConsole, 14);
    cout << nomArme << endl;
    SetConsoleTextAttribute(hConsole, 7);

    if(vieInitialeEnnemi1 == 0)
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout << "       " << nomEnnemi1 << " EST ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "MORT" << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << " [2] - ATTAQUER ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << nomEnnemi1;

        for(int i=0; i<16-nomEnnemi1.size(); i++) /** Ce code sert a maintenir le meme nb d'espaces qu'importe le nom saisi. */
        {
            cout << " ";
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << " (";

        /** le code ci dessous colore la vie en fonction de plusieurs parametres */

        if(vieInitialeEnnemi1 > attaqueAllie + attaqueHeros + 20)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << vieInitialeEnnemi1 ;
        }
        else if(vieInitialeEnnemi1 <= attaqueAllie + attaqueHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << vieInitialeEnnemi1 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << vieInitialeEnnemi1 ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "/" << vdb_e1 << ")";

        if(vieInitialeEnnemi1 >= 100)  ///pour maintenir le meme ecart quel que soit la vie
        {
            cout << "  " ;
        }
        else if(vieInitialeEnnemi1 < 100 && vieInitialeEnnemi1 >= 10)
        {
            cout << "   " ;
        }
        else
        {
            cout << "    " ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "| ATTAQUE A : ";
        if(attaqueEnnemi1 < vieInitialeAllie || attaqueEnnemi1 < vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << attaqueEnnemi1 ;
        }
        else if(attaqueEnnemi1 >= vieInitialeAllie || attaqueEnnemi1 >= vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << attaqueEnnemi1 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << attaqueEnnemi1 ;
        }

        cout << endl;

    }

    if(vieInitialeEnnemi2 == 0)
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout << "       " << nomEnnemi2 << " EST ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "MORT" << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << " [3] - ATTAQUER ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << nomEnnemi2;

        for(int i=0; i<16-nomEnnemi2.size(); i++) /** Ce code sert a maintenir le meme nb d'espaces qu'importe le nom saisi. */
        {
            cout << " ";
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << " (";

        /** le code ci dessous colore la vie en fonction de plusieurs parametres */

        if(vieInitialeEnnemi2 > attaqueAllie + attaqueHeros + 20)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << vieInitialeEnnemi2 ;
        }
        else if(vieInitialeEnnemi2 <= attaqueAllie + attaqueHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << vieInitialeEnnemi2 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << vieInitialeEnnemi2 ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "/" << vdb_e1 << ")";

        if(vieInitialeEnnemi2 >= 100)  ///pour maintenir le meme ecart quel que soit la vie
        {
            cout << "  " ;
        }
        else if(vieInitialeEnnemi2 < 100 && vieInitialeEnnemi2 >= 10)
        {
            cout << "   " ;
        }
        else
        {
            cout << "    " ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "| ATTAQUE A : ";
        if(attaqueEnnemi2 < vieInitialeAllie || attaqueEnnemi2 < vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << attaqueEnnemi2 ;
        }
        else if(attaqueEnnemi2 >= vieInitialeAllie || attaqueEnnemi2 >= vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << attaqueEnnemi2 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << attaqueEnnemi2 ;
        }

        cout << endl;
    }

    if(vieInitialeEnnemi3 == 0)
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout << "       " << nomEnnemi3 << " EST ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "MORT" << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << " [4] - ATTAQUER ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << nomEnnemi3;

        for(int i=0; i<16-nomEnnemi3.size(); i++) /** Ce code sert a maintenir le meme nb d'espaces qu'importe le nom saisi. */
        {
            cout << " ";
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << " (";

        /** le code ci dessous colore la vie en fonction de plusieurs parametres */

        if(vieInitialeEnnemi3 > attaqueAllie + attaqueHeros + 20)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << vieInitialeEnnemi3 ;
        }
        else if(vieInitialeEnnemi3 <= attaqueAllie + attaqueHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << vieInitialeEnnemi3 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << vieInitialeEnnemi3 ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "/" << vdb_e1 << ")";

        if(vieInitialeEnnemi3 >= 100)  ///pour maintenir le meme ecart quel que soit la vie
        {
            cout << "  " ;
        }
        else if(vieInitialeEnnemi3 < 100 && vieInitialeEnnemi3 >= 10)
        {
            cout << "   " ;
        }
        else
        {
            cout << "    " ;
        }

        SetConsoleTextAttribute(hConsole, 7);
        cout << "| ATTAQUE A : ";
        if(attaqueEnnemi3 < vieInitialeAllie || attaqueEnnemi3 < vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << attaqueEnnemi3 ;
        }
        else if(attaqueEnnemi3 >= vieInitialeAllie || attaqueEnnemi3 >= vieInitialeHeros)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << attaqueEnnemi3 ;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << attaqueEnnemi3 ;
        }

        cout << endl;
    }

    if(vieInitialeAllie > 0)
    {
        SetConsoleTextAttribute(hConsole, 7);
        cout << " [5] - DONNER DE LA";
        SetConsoleTextAttribute(hConsole, 10);
        cout << " VIE " ;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "A " << nomAllie << endl;
    }
    else
    {
        cout << " " << endl;
    }
    SetConsoleTextAttribute(hConsole, 8);
    cout << " [99] - QUITTER" << endl;
    cout << endl;

    //system("pause");
    //system("timeout /t 5 /nobreak > nul");
}



void afficher_titre()
{
    cout << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
        cout << "//";
    }
    SetConsoleTextAttribute(hConsole, 14);
    cout << " * " << endl << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "               _     _____   ____  _   _ ____  _____ ____" << endl;
    cout << "              | |   | ____| / ___|| | | |  _ \\| ____|  _ \\" << endl;
    cout << "              | |   |  _|   \\__  \\| | | | |_) |  _| | |_) |" << endl;
    cout << "              | |___| |___   ___) | |_| |  __/| |___|  _ <" << endl;
    cout << "              |_____|_____| |____/_\\___/|_|   |_____|_| \\_\\" << endl;
    cout << "                             | | ____| | | |" << endl;
    cout << "                          _  | |  _| | | | |" << endl;
    cout << "                         | |_| | |___| |_| |" << endl;
    cout << "                          \\___/|_____|\\___/" << endl << endl << endl;
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
    //SetConsoleTextAttribute(hConsole, 9);
    cout << " *" << endl;

    afficher_lignes(" ", 14, 14) ;
}

void afficher_lignes(std::string mot, int couleur1/** couleur des etoiles */, int couleur2/** couleur de 'mot' */)
{
    SetConsoleTextAttribute(hConsole, couleur1);
    cout << " *";
    SetConsoleTextAttribute(hConsole, couleur2);
    cout << mot ;
    SetConsoleTextAttribute(hConsole, couleur1);
    for(int i=0; i<70-mot.size(); i++)
    {
        cout << " ";
    }
    cout << "*";
    cout << endl;
}



void chargement(int progression)
{
    cout << endl << endl;
    cout << "INITIALISATION ..." ;
    SetConsoleTextAttribute(hConsole, 14) ;
    for(int i=0; i<18; i++)
    {
        cout << endl;
    }
    cout << " [" ;
    SetConsoleTextAttribute(hConsole, 12) ;
    for(int i=0; i<=progression; i++)
    {
        cout << "/";
    }
    for(int i=0; i<68-progression; i++)
    {
        cout << " " ;
    }
    SetConsoleTextAttribute(hConsole, 14) ;
    cout << "]" << endl;

    if(progression >= 65)
    {
        system("timeout /t 1 /nobreak > nul") ;
    }

    system("cls") ;
}


void afficher_barre()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
        cout << "//";
    }
    SetConsoleTextAttribute(hConsole, 14);
    cout << " * " ;
    SetConsoleTextAttribute(hConsole, 12);
}


void afficher_fin(bool aGagne)
{
    if(aGagne)
    {
        for(int i=0;i<10;i++){
            cout << endl;
        }
        afficher_barre() ;
        SetConsoleTextAttribute(hConsole, 10) ;
        afficher_lignes(" ", 14, 10) ;
        afficher_lignes("               _______                       _________ _      ", 14, 10);
        afficher_lignes("     |\\     /|(  ___  )|\\     /|    |\\     /|\\__   __/( (    /|", 14, 10);
        afficher_lignes("     ( \\   / )| (   ) || )   ( |    | )   ( |   ) (   |  \\  ( |", 14, 10);
        afficher_lignes("      \\ (_) / | |   | || |   | |    | | _ | |   | |   |   \\ | |", 14, 10);
        afficher_lignes("       \\   /  | |   | || |   | |    | |( )| |   | |   | (\\ \\) |", 14, 10);
        afficher_lignes("        ) (   | |   | || |   | |    | || || |   | |   | | \\   |", 14, 10);
        afficher_lignes("        | |   | (___) || (___) |    | () () |___) (___| )  \\  |", 14, 10);
        afficher_lignes("        \\_/   (_______)(_______)    (_______)\\_______/|/    )_)", 14, 10);
        afficher_lignes(" ", 14, 10) ;
        afficher_barre() ;
    }
    else
    {
        for(int i=0;i<10;i++){
            cout << endl;
        }
        afficher_barre() ;
        afficher_lignes(" ", 14, 10) ;
        SetConsoleTextAttribute(hConsole, 12) ;
        afficher_lignes("    __     ______  _    _   _      ____   ____   _____ ______   _", 14, 12) ;
        afficher_lignes("    \\ \\   / / __ \\| |  | | | |    / __ \\ / __ \\ / ____|  ____| | |", 14, 12) ;
        afficher_lignes("     \\ \\_/ / |  | | |  | | | |   | |  | | |  | | (___ | |__    | |", 14, 12) ;
        afficher_lignes("      \\   /| |  | | |  | | | |   | |  | | |  | |\\___ \\|  __|   | |", 14, 12) ;
        afficher_lignes("       | | | |__| | |__| | | |___| |__| | |__| |____) | |____  |_|", 14, 12) ;
        afficher_lignes("       |_|  \\____/ \\____/  |______\\____/ \\____/|_____/|______| (_)", 14, 12) ;
        afficher_lignes(" ", 14, 10) ;
        afficher_barre() ;
    }
}


int afficher_setup()
{
    SetConsoleTextAttribute(hConsole, 7) ;
    int opt = 0 ;
    while(opt < 1 || opt > 3){
        cout << endl << " Game Setup" << endl;
        cout << " ----------" << endl;
        cout << endl ;
        cout << " 1) Lancer le jeu" << endl;
        cout << " 2) Lancer une simulation" << endl ;
        cout << " 3) mode en ligne (en developpement ...)" << endl;
        cout << " 3) Quitter" << endl << endl;
        cout << endl << " Saisir votre choix : ";
        cin >> opt ;
    }
    return opt ;
}

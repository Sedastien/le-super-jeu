#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void afficher_interface(int vieInitialeHeros, int attaqueHeros, int vieInitialeAllie, int attaqueAllie,
                        int vieInitialeEnnemi1, int vieInitialeEnnemi2, int vieInitialeEnnemi3,
                        int attaqueEnnemi1, int attaqueEnnemi2, int attaqueEnnemi3,
                        std::string nomHeros, std::string nomAllie, std::string nomEnnemi1, std::string nomEnnemi2, std::string nomEnnemi3,
                        int tours, int vdb_h, int vdb_a, int vdb_e1, int vdb_e2, int vdb_e3, std::string nomArme, std::string nomArmeAllie);

void afficher_titre() ;

void afficher_lignes(std::string mot, int couleur1, int couleur2) ;

void chargement(int progression) ;

void afficher_barre() ;

void afficher_fin(bool a_gagne) ;

int afficher_setup() ;

#endif // MENU_H_INCLUDED

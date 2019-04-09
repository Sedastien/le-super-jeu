#ifndef IA_ALLIE_H_INCLUDED
#define IA_ALLIE_H_INCLUDED

int selection_action(int ma_vie, int mon_attaque, int vie_ami, int attaque_ami,
                     int vie_ennemi1, int vie_ennemi2, int vie_ennemi3,
                     int attaque_ennemi1, int attaque_ennemi2, int attaque_ennemi3, int type_IA);

int strategie(int action);

int simulation(int action, int joueur, int type);

int evaluer_action(int action, int action_adverse1, int action_adverse2, int action_adverse3, int type_IA);

int MinMax(int profondeur, int joueur, int action, int type);

void annuler_action(int action);

void annuler_action_advrs(int Ac_1, int Ac_2, int Ac_3);

int gagnantJeu(int joueur);

#endif // IA_ALLIE_H_INCLUDED

#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

int choix_action(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA,
                 int vie_allie_1, int attaque_allie_1, int attaque_allie_2, int vie_allie_2,
                 int vie_ennemi2, int attaque_ennemi2);

///int choix_action_adversaire(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA);

int evaluation_action(int attaque_adversaire, int vie_adversaire, int attaque_IA, int vie_IA, int action, int joueur,
                      int vie_allie_1, int attaque_allie_1, int vie_allie_2, int attaque_allie_2,
                      int vie_ennemi2, int attaque_ennemi2);

#endif // IA_H_INCLUDED

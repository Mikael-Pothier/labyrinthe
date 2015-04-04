#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include <iostream>

using namespace std;
int main()
{
	CJeu jeu;
	jeu.AfficherEtat(cout);
	CMenu::Afficher(cout);
	CCommande c;
	system("color 0A");
	while (!jeu.Fini() && 
		(c = CMenu::LireCommande(cin), c != CMenu::QUITTER))
	{
		jeu.Executer(c);
		jeu.AfficherEtat(cout);
		CMenu::Afficher(cout);
	}
	if (jeu.PartieGagne())
		cout << "Vous avez atteint l'objectif!";
	else
		cout << "Vous etes mort de faim!";
	system("pause");
	return 0;
}
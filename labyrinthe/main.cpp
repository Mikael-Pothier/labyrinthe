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
	system("color 0A"); //pour faire fancy
	while (!jeu.Fini() && 
		(c = CMenu::LireCommande(cin), c != CMenu::QUITTER))
	{
		jeu.Executer(c);
		jeu.AfficherEtat(cout);
		CMenu::Afficher(cout);
	}
	jeu.AfficherResultats(cout);
	system("pause");
	return 0;
}
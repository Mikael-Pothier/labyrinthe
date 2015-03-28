#include "Jeu.h"
#include "Menu.h"

#include <iostream>

using namespace std;
int main()
{
	CJeu jeu;

	jeu.ReadMap("Map.txt");
	CPosition posdepart = jeu.TrouverPosDepart();
	jeu.PlacerPersonnage(posdepart);

	jeu.AfficherEtat(cout);
	CMenu::Afficher(cout);
	CCommande c;

	while (!jeu.Fini() && 
		(c = CMenu::LireCommande(cin), c != CMenu::QUITTER))
	{
		jeu.Executer(c);
		jeu.AfficherEtat(cout);
		CMenu::Afficher(cout);
	}
	return 0;
}
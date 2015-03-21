#include "Menu.h"
#include "Commande.h"
const CCommande
CMenu::AVANCER = CCommande('W'),
CMenu::GAUCHE  = CCommande('A'),
CMenu::DROITE  = CCommande('D'),
CMenu::RECULER = CCommande('S'),
CMenu::QUITTER = CCommande(27);//caractère Échap (ESC)

#include <iostream>
void CMenu::Afficher()
{
	using std::cout;
	using std::endl;
	cout << "Avancer: " << AVANCER << "; "
		 << "Gauche: "  << GAUCHE  << "; "
		 << "Droite: "  << DROITE  << "; "
		 << "Reculer: " << RECULER << "; "
		 << "Quitter: " << "ESC" << endl;
}
CCommande CMenu::LireCommande(istream& is)
{
	CCommande c = QUITTER;
	is >> c; 
	return c;
}
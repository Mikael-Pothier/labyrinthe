#include "Menu.h"
#include "Commande.h"
const Commande
Menu::AVANCER = Commande('W'),
Menu::GAUCHE  = Commande('A'),
Menu::DROITE  = Commande('D'),
Menu::RECULER = Commande('S'),
Menu::QUITTER = Commande(27);//caractère Échap (ESC)

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
Commande CMenu::LireCommande(const istream& is)
{
	commande c = QUITTER;
	is >> c; 
	return c;
}
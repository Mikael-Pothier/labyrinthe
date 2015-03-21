#include "Menu.h"
#include "Commande.h"
const CCommande
CMenu::AVANCER = CCommande('W'),
CMenu::GAUCHE  = CCommande('A'),
CMenu::DROITE  = CCommande('D'),
CMenu::RECULER = CCommande('S'),
CMenu::QUITTER = CCommande(27);//caractère Échap (ESC)

#include <iostream>
void CMenu::Afficher(ostream& os)
{
	os << "Avancer: " << AVANCER << "; "
	   << "Gauche: "  << GAUCHE  << "; "		 
	   << "Droite: "  << DROITE  << "; "
	   << "Reculer: " << RECULER << "; "
	   << "Quitter: " << "ESC" << os.end;
}
CCommande CMenu::LireCommande(istream& is)
{
	CCommande c = QUITTER;
	is >> c; 
	return c;
}
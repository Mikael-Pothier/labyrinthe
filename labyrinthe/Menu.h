#pragma once
#include "Commande.h"

class CMenu
{
public:
	static const CCommande AVANCER, GAUCHE, DROITE, RECULER, QUITTER;
	static void Afficher(ostream& os);
	static CCommande LireCommande(istream& is);
};
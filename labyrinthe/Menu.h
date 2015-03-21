#pragma once
#include "Commande.h"

class CMenu
{
public:
	static const Commande AVANCER, GAUCHE, DROITE, RECULER, QUITTER;
	static void Afficher();
	static Commande LireCommande();
};
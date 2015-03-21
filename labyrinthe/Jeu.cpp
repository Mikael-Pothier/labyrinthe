#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"
#include "Espace.h"

#include<iostream>
using std::ostream;

bool CJeu::Fini()
{
	return perso_.GetPosition() == objectif_;
}

void CJeu::AfficherEtat(ostream & os) const
{
	for (int i = CEspace::Y_MIN; i < CEspace::Y_MAX; ++i)
	{
		for (int j = CEspace::X_MIN; j < CEspace::X_MAX; ++j)
		{
			const CPosition pos(j, i);
			if (pos == perso_.GetPosition())
			{
				os << perso_;
			}
			else
				os << ' ';
		}
	}
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		perso_.Marcher();
	}
	else if (c == CMenu::DROITE)
	{
		
	}
	else if (c == CMenu::GAUCHE)
	{
	}
	else if (c == CMenu::RECULER)
	{
	}
}
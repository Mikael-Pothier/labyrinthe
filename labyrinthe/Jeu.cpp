#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"
#include "Espace.h"

#include<iostream>
using std::ostream;

const CPosition
CJeu::POS_PERSO_DEFAUT = CPosition(1, 1),
CJeu::POS_ITEMS_DEFAUT = CPosition(5, 5),
CJeu::POS_OBJECTIF_DEFAUT = CPosition(10, 10);

bool CJeu::Fini()
{
	return perso_.GetPosition() == objectif_;
}

void CJeu::AfficherEtat(ostream & os) const
{
	system("cls");
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
		perso_.Droite();
	}
	else if (c == CMenu::GAUCHE)
	{
		perso_.Gauche();
	}
	else if (c == CMenu::RECULER)
	{
	}
}
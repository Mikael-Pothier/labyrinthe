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

const char CJeu::VIDE = ' ';
const string CJeu::ESPACE_JEU_DEFAUT = "Map.txt";

CJeu::CJeu() throw() : perso_(POS_PERSO_DEFAUT),
					   espace_jeu_(ESPACE_JEU_DEFAUT),
					   objectif_(CEspace::EtablirPosition(CEspace::FIN))
{
	CEspace::CreerEspace(espace_jeu_);
	perso_.SetPosition(CEspace::EtablirPosition(CEspace::DEPART));
	CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
}

bool CJeu::Gagne()
{
	return perso_.GetPosition() == objectif_;
}

bool CJeu::Perd()
{
	return perso_.EstMort();
}

bool CJeu::Fini()
{
	return Perd() || Gagne();
}

void CJeu::AfficherEtat(ostream & os) const
{
	system("cls");
	for (int i = CEspace::Y_MIN; i < CEspace::Max_Y(); ++i)
	{
		for (int j = CEspace::X_MIN; j < CEspace::Max_X(); ++j)
		{
			const CPosition pos(j, i);

			if (pos == perso_.GetPosition())
				os << perso_;
			if (CEspace::EstVisible(pos))
				CEspace::Afficher(os, pos);
			else
				os << VIDE;
		}
		os << '\n';
	}
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		perso_.Avancer();
		CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
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
		perso_.Reculer();
		CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
	}
}
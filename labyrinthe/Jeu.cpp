#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"
#include "Espace.h"
bool CJeu::Fini()
{
	return false;
}

void CJeu::AfficherEtat(ostream & os) const
{
	for (int i = CEspace::Y_MIN; i < CEspace::Y_MAX; ++i)
	{
		for (int j = CEspace::X_MIN; j < CEspace::X_MAX; ++j)
		{
			//const CPosition pos(j, i);
		}
	}
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		
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
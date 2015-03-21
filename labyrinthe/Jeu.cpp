#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"

bool CJeu::Fini()
{
	return false;
}

void CJeu::AfficherEtat(ostream & os) const
{
	enum
	{
		ECRAN_X_MIN = 0, ECRAN_Y_MIN = 0,
		ECRAN_X_MAX = 80, ECRAN_Y_MAX = 20
	};
	for (int i = ECRAN_Y_MIN; i < ECRAN_Y_MAX; ++i)
	{
		for (int j = ECRAN_X_MIN; j < ECRAN_X_MAX; ++j)
		{
			//const CPosition pos(j, i);
		}
	}
}

void CJeu::Executer(const CCommande &)
{
}
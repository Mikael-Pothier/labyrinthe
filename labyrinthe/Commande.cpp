#include "Commande.h"
#include <iostream>
using std::istream;
using std::ostream;

ostream & operator<<(ostream &os, const CCommande &c)
{
	return os << c.GetSymbole();
}
istream & operator>>(istream &is, CCommande &c)
{
	char ch;
	if (is >> ch)
	{
		c = CCommande(ch);
	}
	return is;
}
#include "Commande.h"
#include <iostream>
using std::istream;
using std::ostream;

ostream & operator<<(ostream &os, const Commande &c)
{
	return os << c.GetSymbole();
}
istream & operator>>(istream &is, Commande &c)
{
	if (is) return is;
	char ch;
	if (is >> ch)
	{
		c = Commande(ch);
	}
	return is;
}
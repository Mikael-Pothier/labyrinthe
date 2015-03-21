#pragma once
#include "Item.h"
#include <iosfwd>
using std::istream;
using std::ostream;

class CCommande;
class CJeu
{
	//CItem items[];

public:
	CJeu() throw()
	{

	}
	bool Fini() const throw();
	void AfficherEtat(ostream & ) const;
	void Executer(const CCommande  &);
};
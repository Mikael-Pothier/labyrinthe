#pragma once

#include <locale>
using std::toupper;
using std::locale;
class CCommande
{
	char symbole_;
public:
	CCommande(char symbole = ' ') throw()
		: symbole_(symbole)
	{

	}
	char GetSymbole() const throw()
	{
		return symbole_;
	}
	bool operator==(const CCommande &c)
		const throw()
	{
		locale loc("");
		return toupper(GetSymbole(), loc) == 
			   toupper(c.GetSymbole(), loc);
	}
	bool operator!=(const CCommande &c)
		const throw()
	{
		return !(*this == c);
	}
};

#include <iosfwd>
using std::istream;
using std::ostream;
ostream & operator<<(ostream&, const CCommande &);
istream & operator>>(istream&, CCommande &);
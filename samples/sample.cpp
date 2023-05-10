#include "Polynoms.h"

using namespace std;

int main()
{
	Polynom pol;
	pol._Set();
	//pol.Printpolynom();
	//pol.Printpolynom();
	Polynom pol2;
	pol2._Set();
	//pol2._Set();
	//pol2.Printpolynom();
	double a = 3;
	Polynom res;
	res = pol * pol2;
	res.Printpolynom();
	return 0;
}
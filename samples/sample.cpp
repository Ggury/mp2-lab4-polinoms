<<<<<<< HEAD
#include "Polynoms.h"
=======
#include "..\include\Polynom.h"
>>>>>>> 1b05400d159f326dc4c95dabc8871702c3fe6b3c

using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
	char operation;
	Polynom pol;
	cout << "first monom" << endl;
	pol._Set();
	cout << endl<<"Input operation:";
	cin >> operation;
	cout << endl;
	if (operation == '+')
	{
		cout << "second polynom:" << endl;
		Polynom pol2;
		pol2._Set();
		Polynom res = pol + pol2;
		cout << "Result" << endl;
		res.Printpolynom();
	}
	else if (operation == '-')
	{
		cout << "second polynom:" << endl;
		Polynom pol2;
		pol2._Set();
		Polynom res = pol - pol2;
		cout << "Result" << endl;
		res.Printpolynom();
	}
	else if (operation == '*')
	{
		cout << "Do you want to multiply on value or on the other polynom? " << endl << "1: value" << endl << "2:polynom" << endl;
		int a;
		cin >> a;
		if (a == 1)
		{
			cout << "Value:";
			int val;
			cin >> val;
			cout << endl;
			Polynom res = pol * val;
			res.Printpolynom();
		}
		if (a == 2)
		{
			cout << "Polynom:" << endl;;
			Polynom pol2;
			pol2._Set();
			Polynom res = pol * pol2;
			res.Printpolynom();
		}
	}
	//Polynom pol2;
	//pol2._Set();
	//double a = 3;
	//Polynom res;
	//res = pol * pol2;
	//res.Printpolynom();
>>>>>>> 1b05400d159f326dc4c95dabc8871702c3fe6b3c
	return 0;
}
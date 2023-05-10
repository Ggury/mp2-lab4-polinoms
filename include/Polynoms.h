#pragma once
#include "List.h"



using namespace std;


class Polynom {
private:
	List monoms;
public:
	Polynom() :monoms(){};


	void _Push(double mod, size_t deg);
	void _AddMonom();
	void _Setmonom(Node hed);

	void _Set();

	void Printpolynom();


	Polynom operator +(const Polynom& pol);

	Polynom operator *(const double md);

	const Polynom& operator =(const Polynom& pol);

	Polynom operator *(const Polynom& pol);

	//friend std::ostream& operator <<(std::ostream os, const Polynom&);

};

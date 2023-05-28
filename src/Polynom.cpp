#include "..\include\Polynom.h"

void Polynom::_Push(double mod, size_t deg)
{
	if (deg > 999 || deg < 0)
	{
		throw std::out_of_range("wrong input degrees");
	}
	Node* hd = monoms.Head;

	while (hd != NULL)
	{
		cout << "a" << endl;
		if (hd->data.degree == deg)
		{
			hd->data.modif += mod;
			return;
		}
		hd = hd->next;
	}
	monom mon(mod, deg);
	monoms.push(mon);
}

void Polynom::_AddMonom()
{
	double coefficent;
	int deg = 0;
	int tmp = 0;
	cout << "input monom:" << "coefficient:";
	cin >> coefficent;
	cout << " x^";
	cin >> tmp;
	if (tmp > 9) throw std::out_of_range("wrong input (Received degree greater than 9)");
	deg += 100 * tmp;
	cout << "y^";
	cin >> tmp;
	if (tmp > 9) throw std::out_of_range("wrong input (Received degree greater than 9)");
	deg += 10 * tmp;
	cout << "z^";
	cin >> tmp;
	if (tmp > 9) throw std::out_of_range("wrong input (Received degree greater than 9)");
	deg += tmp;
	_Push(coefficent, deg);
}

void Polynom::_Setmonom(Node hed)
{
	double coefficent;
	int deg = 0;
	int tmp = 0;
	cout << "input monom:" << "coefficient:";
	cin >> coefficent;
	cout << " x^";
	cin >> tmp;
	deg += 100 * tmp;
	cout << "y^";
	cin >> tmp;
	deg += 10 * tmp;
	cout << "z^";
	cin >> tmp;
	deg += tmp;
	hed.data.degree = deg;
	hed.data.modif = coefficent;
}

void Polynom::_Set() {
	int a;
	cout << "Input number of monoms:";
	cin >> a;
	cout << endl;
	//_Setmonom(*monoms.Head);
	//double coefficent;
	//int deg = 0;
	//int tmp = 0;
	//cout << "input monom:" << "coefficient:";
	//cin >> coefficent;
	//cout << " x^";
	//cin >> tmp;
	//deg += 100 * tmp;
	//cout << "y^";
	//cin >> tmp;
	//deg += 10 * tmp;
	//cout << "z^";
	//cin >> tmp;
	//deg += tmp;
	//this->monoms.Head->data.degree = deg;
	//this->monoms.Head->data.modif = coefficent;
	for (int i = 0; i < a; i++)
	{
		_AddMonom();
	}
	Printpolynom();
}

void Polynom::Printpolynom() {
	Node* hd = monoms.Head;

	if (hd->data.modif != 0)
	{
		while (hd != NULL)
		{
			cout << "(" << hd->data << ")+";

			hd = hd->next;
		}
		cout << "0" << endl;

	}
}

Polynom Polynom::operator+(const Polynom& pol)
{
	Polynom res;
	res.monoms.Head = NULL;
	Node* tmp1 = monoms.Head;
	Node* tmp2 = pol.monoms.Head;
	//while (tmp1)
	//{
	//	while (tmp2)
	//	{
	//			if (tmp1->data.degree == tmp2->data.degree)
	//			{
	//				res._Push(tmp1->data.modif + tmp2->data.modif, tmp1->data.degree);
	//				tmp1 = tmp1->next;
	//				tmp2 = tmp2->next;
	//				continue;
	//			}
	//			if (tmp2->data.degree > tmp1->data.degree)
	//			{
	//				res._Push(tmp2->data.modif, tmp2->data.degree);
	//				tmp2 = tmp2->next;
	//				continue;
	//			}
	//			if (tmp2->data.degree < tmp1->data.degree)
	//			{
	//				res._Push(tmp1->data.modif, tmp1->data.degree);
	//				tmp1 = tmp1->next;
	//				continue;
	//			}
	//	}
	//}
	while (tmp1 || tmp2)
	{
		if (tmp1 == nullptr)
		{
			res._Push(tmp2->data.modif, tmp2->data.degree);
			tmp2 = tmp2->next;
			continue;
		}
		if (tmp2 == nullptr)
		{
			res._Push(tmp1->data.modif, tmp1->data.degree);
			tmp1 = tmp1->next;
			continue;
		}
		if (tmp1->data.degree == tmp2->data.degree)
		{
			res._Push(tmp1->data.modif + tmp2->data.modif, tmp1->data.degree);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			continue;
		}
		if (tmp2->data.degree > tmp1->data.degree)
		{
			res._Push(tmp2->data.modif, tmp2->data.degree);
			tmp2 = tmp2->next;
			continue;
		}
		if (tmp2->data.degree < tmp1->data.degree)
		{
			res._Push(tmp1->data.modif, tmp1->data.degree);
			tmp1 = tmp1->next;
			continue;
		}
	}

	//while (tmp1)
	//{
	//	res._Push(tmp1->data.modif, tmp1->data.degree);
	//	tmp1 = tmp1->next;
	//}
	//while (tmp2)
	//{
	//	res._Push(tmp2->data.modif, tmp2->data.degree);
	//	tmp2 = tmp2->next;
	//}
	return res;
}

Polynom Polynom::operator*(const double md)
{
	Polynom res;
	res.monoms.Head = NULL;
	Node* tmp = monoms.Head;
	while (tmp)
	{
		res._Push(tmp->data.modif * md, tmp->data.degree);
		tmp = tmp->next;
	}
	return res;
}

const Polynom& Polynom::operator=(const Polynom& pol)
{
	this->monoms = pol.monoms;
	return *this;
}

Polynom Polynom::operator*(const Polynom& pol)
{
	Polynom res;
	res.monoms.Head = NULL;
	Node* tmp1 = monoms.Head;
	while (tmp1)
	{
		if (pol.monoms.Head == NULL) { return res; }
		Polynom tmp3;
		tmp3.monoms.Head = NULL;
		Node* tmp2 = pol.monoms.Head;
		while (tmp2)
		{
			int deg1 = tmp1->data.degree;
			int deg2 = tmp2->data.degree;
			int xd1 = deg1 / 100;
			int yd1 = (deg1 % 100) / 10;
			int zd1 = deg1 % 10;
			int xd2 = deg2 / 100;
			int yd2 = (deg2 % 100) / 10;
			int zd2 = deg2 % 10;
			if ((xd1 + xd2 > 9) || (yd1 + yd2 > 9) || (zd1 + zd2 > 9)) throw std::out_of_range("Wrong input(Received degrees greater than 9)");
			tmp3._Push(tmp1->data.modif * tmp2->data.modif, tmp1->data.degree + tmp2->data.degree);
			tmp2 = tmp2->next;
		}

		res = res + tmp3;
		tmp1 = tmp1->next;
	}


	return res;
}

Polynom Polynom::operator-(const Polynom& pol)
{
	Polynom pol1 = *this;
	Polynom pol2 = pol;
	Polynom r1 = pol2 * -1;
	Polynom res = pol1 + r1;
	return res;
}
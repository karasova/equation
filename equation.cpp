#include "rational.h"
#include "equation.h"
#include <iostream>
#include <locale.h>

using namespace std;

ostream& operator <<(ostream& out, const Rational& r) {
	out << r.numer << "/" << r.denom;
	return out;
}

void dis(Rational a, Rational b, Rational c) {
	setlocale(LC_ALL, "Russian");
	cout << "���������: " << a << "x^2" << b << "x" << c << "= 0" << endl;
	Rational res, x1, x2;
	res = b * b - (a * 4)* c;
	res = res.sqt();
	if (res > 0) {
		x1 = ((-b) - res) / (a * 2);
		cout << "������ ������ = " << x1 << endl;
		x2 = ((-b) + res) / (a * 2);
		cout << "������ ������ = " << x2 << endl;
	}
	if (res == 0) {
		x1 = (-b) / (a * 2);
		cout << "������ ��������� = " << x1 << endl;
	}
	if (res < 0)
		cout << "������ ��������� �� ����� ������������ ������" << endl;
}


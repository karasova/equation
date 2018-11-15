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
	cout << "Уравнение: " << a << "x^2" << b << "x" << c << "= 0" << endl;
	Rational res, x1, x2;
	res = b * b - (a * 4)* c;
	res = res.sqt();
	if (res > 0) {
		x1 = ((-b) - res) / (a * 2);
		cout << "Первый корень = " << x1 << endl;
		x2 = ((-b) + res) / (a * 2);
		cout << "Второй корень = " << x2 << endl;
	}
	if (res == 0) {
		x1 = (-b) / (a * 2);
		cout << "Корень уравнения = " << x1 << endl;
	}
	if (res < 0)
		cout << "Данное уравнение не имеет рациональных корней" << endl;
}


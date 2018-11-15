#include <iostream>
#include "rational.h"
#include <locale.h>
#include "equation.h"


using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Решение квадратного уравнения." << endl;
	Rational a(1, 2), b(-1, 6), c(-2, 3);

	
	dis(a, b, c);
	system("pause");
	return 0;
}
#include <iostream>
#include "rational.h"
#include <math.h>

using namespace std;

Rational::Rational() {
	numer = 0;
	denom = 1;
}

Rational::Rational(int number) {
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d) {
	numer = n;
	denom = d;
}

Rational&Rational::operator += (const Rational& r) {
	numer = (numer*r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	one();
	return *this;
}

void Rational::simplify() {
	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i < abs(denom) && i<=abs(numer); i++) {
		if (numer%i == 0 && denom %i == 0) {
			numer /= i;
			denom /= i;
			i--;
		}
	}
}

Rational Rational::operator +(const Rational& r) const {
	Rational res(*this);
	return res += r;
}

Rational Rational::operator -() const {
	Rational r(-numer, denom);
	return r;
}

Rational Rational::operator -(const Rational& r) const {
	Rational res(*this);
	return res += (-r);
}

Rational&Rational:: operator -= (const Rational& r) {
	return (*this += (-r));
}

Rational& Rational::operator ++() {
	numer += denom;
	return *this;
}

Rational Rational::operator++(int) {
	Rational r(*this);
	numer += denom;
	return r;
}

bool Rational::operator ==(const Rational& r) const {
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const {
	return !(*this == r);
}

Rational::operator int() const {
	return numer / denom;
}

Rational::operator double() const {
	return ((double)numer) / denom;
}

Rational&Rational::operator *= (const Rational& r) {
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	one();
	return *this;
}

Rational Rational::operator * (const Rational& r) const{
	Rational res(*this);
	return res *= r;
}

Rational&Rational::operator /= (const Rational& r) {
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	one();
	return *this;
}

Rational Rational::operator / (const Rational& r) const {
	Rational res(*this);
	return res /= r;
}

Rational&Rational::operator *= (const int& a) {
	numer *= a;
	simplify();
	one();
	return *this;
}

Rational Rational::operator * (const int& a) const {
	Rational res(*this);
	return res *= a;
}

Rational&Rational:: sqt() {
	numer = (double)numer;
	denom = (double)denom;
	numer = round(sqrt(numer));
	denom = round(sqrt(denom));
	numer = (int)numer;
	denom = (double)denom;
	simplify();
	one();
	return *this;
}

bool Rational::operator > (const int& a) const {
	return (numer > a*denom);
}

bool Rational::operator < (const int& a) const {
	return (numer < a*denom);
}

bool Rational::operator >= (const int& a) const {
	return (numer >= a*denom);
}

bool Rational::operator <= (const int& a) const {
	return (numer <= a*denom);
}

bool Rational::operator ==(const int& a) const {
	return (numer == a) && (denom == 1);
}

void Rational::one() {
	if (abs(denom) == abs(numer)) {
		numer = numer / denom;
		denom = 1;
	}	
}

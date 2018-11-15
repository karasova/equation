#pragma once

class Rational {
	void simplify();
	void one();

public:
	int numer;
	int denom;
	Rational();
	Rational(int number);
	Rational(int n, int d);
	Rational& operator += (const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational operator -() const;
	Rational& operator -= (const Rational& r);
	Rational& operator ++();
	Rational operator ++(int);
	bool operator ==(const Rational&r) const;
	bool operator != (const Rational&r) const;
	operator int() const;
	operator double() const;
	Rational& operator *= (const Rational& r);
	Rational operator * (const Rational& r) const;
	Rational& operator /= (const Rational& r);
	Rational operator / (const Rational& r) const;
	Rational operator -(const Rational& r) const;
	Rational operator * (const int& a) const;
	Rational& operator *= (const int& a);
	Rational& sqt();
	bool operator > (const int& a) const;
	bool operator < (const int& r) const;
	bool operator >= (const int& r) const;
	bool operator <= (const int& r) const;
	bool operator ==(const int& a) const;
	//friend istream& operator >>(istream& in, Rational& r);
	//friend ostream& operator <<(ostream& out, const Rational& r);
};


#include "fcpp.hh"
#include <math.h>
#include <iostream>

// Datentyp für komplexe Zahlen
typedef struct cdouble
{
	double real;
	double imag;
	cdouble operator+(cdouble other);
	cdouble operator-(cdouble other);
	cdouble operator*(cdouble other);
} cdouble;

cdouble construct(double real, double imag)
{
	cdouble out;
	out.real = real;
	out.imag = imag;
	return out;
}

double absvalSquared(cdouble a)
{
	return a.real * a.real + a.imag * a.imag;
}

cdouble cdouble::operator+(cdouble other)
{
	cdouble out;
	out.real = real + other.real;
	out.imag = imag + other.imag;
	return out;
}

cdouble cdouble::operator-(cdouble other)
{
	cdouble out;
	out.real = real - other.real;
	out.imag = imag - other.imag;
	return out;
}

cdouble cdouble::operator*(cdouble other)
{
	cdouble out;
	out.real = real * other.real - imag * other.imag;
	out.imag = real * other.imag + imag * other.real;
	return out;
}

int main()
{
	cdouble a = {1,0.5};
	cdouble b = construct(-2,-1);
	print(absvalSquared(a*b));

	return 0;
}
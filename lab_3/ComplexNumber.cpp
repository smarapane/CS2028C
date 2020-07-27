#include "ComplexNumber.h"
#include <iostream>
#include <cmath>
using namespace std;
ComplexNums::ComplexNums() {
	real = 0.0;
	imag = 0.0;
	usePolar = false;
}

ComplexNums::ComplexNums(double a, double b) {
	real = a;
	imag = b;
	usePolar = false;
}

ComplexNums::ComplexNums(double r, double theta, bool setPolar) {
	real = r * cos(theta);
	imag = r * sin(theta);
	usePolar = setPolar;
}

ComplexNums ComplexNums::operator+(ComplexNums rhs) {
	ComplexNums temp(rhs.getReal() + getReal(), rhs.getImag() + getImag());
	if (this->getPolar() == true)
	{
		temp.convertToPolar();
		temp.setPolar(true);
	}
	return temp;
}

ComplexNums ComplexNums::operator-(ComplexNums rhs) {
	ComplexNums temp(getReal() - rhs.getReal(), getImag() - rhs.getImag());
	if (this->getPolar() == true)
	{
		temp.convertToPolar();
		temp.setPolar(true);
	}
	return temp;
}

ComplexNums ComplexNums::operator*(double rhs) {
	ComplexNums temp(getReal() * rhs, getImag() * rhs);
	if (this->getPolar() == true)
	{
		temp.convertToPolar();
		temp.setPolar(true);
	}
	return temp;
}

ComplexNums ComplexNums::operator/(double rhs) {
	ComplexNums temp(getReal() / rhs, getImag() / rhs);
	if (this->getPolar() == true)
	{
		temp.convertToPolar();
		temp.setPolar(true);
	}
	return temp;
}

bool ComplexNums::operator==(ComplexNums rhs) {
	return getReal() == rhs.getReal() && getImag() == rhs.getImag();
}
void ComplexNums::print() {
	if (usePolar)
		cout << getR() << " * ( cos(" << getTheta() << ") + i * sin(" << getTheta() << "))" << endl;
	else
		cout << getReal() << " + i * " << getImag() << endl;
}

void ComplexNums::convertToCartesian() {
  real = r * cos(theta);
	imag = r * sin(theta);
}

void ComplexNums::convertToPolar() {
  r = sqrt(pow(real,2) + pow(imag,2));
  theta = atan(imag / real);
}
#pragma once
#include <cmath>
class ComplexNums {
public:
	ComplexNums();
	ComplexNums(double a, double b);
	ComplexNums(double r, double theta, bool polar);
	void print();
	double getReal() { return real; }
	double getImag() { return imag; }
	double getR() { return r; }
	double getTheta() { return theta; }
	void setReal(double a) { real = a; convertToPolar(); }
	void setImag(double b) { imag = b; convertToPolar(); }
	void setR(double c) { r = c; convertToCartesian(); }
	void setTheta(double d) { theta = d; convertToCartesian(); }
	void setPolar(bool polar) { usePolar = polar; }
	bool getPolar(void) { return usePolar; }
	ComplexNums operator+(ComplexNums rhs);
	ComplexNums operator-(ComplexNums rhs);
	ComplexNums operator*(double rhs);
	ComplexNums operator/(double rhs);
	bool operator==(ComplexNums rhs);
private:
	double real, imag, r, theta;
	bool usePolar, resetPolar;
  void convertToCartesian();
  void convertToPolar();
};
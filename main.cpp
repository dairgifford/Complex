/* Programmer: Alisdair Gifford
Last Edited: 04/14/2024
*/
#include <iostream>
#include "Complex.h"
#include <string>
#include <math.h>

using namespace std;


int main() {
    Complex test1(1.0,2.0), test2(3.0,4.0);
    
    cout << "test1 is: ";
    test1.printValues();
    cout << endl;
    cout << "test2 is: ";
    test2.printValues();
    cout << endl;
    
    test1.swap(test2);
    cout << "test1 after swap of test1 and test2 is: ";
    test1.printValues();
    cout << endl;
    cout << "test2 after swap of test1 and test2 is: ";
    test2.printValues();
    cout << endl;
    
    Complex test3 = test1 * test2;
    cout << "test1 * test 2 is: ";
    test3.printValues();
    
    return 1;
}
Complex::Complex() {
	real = 0;
	imaginary = 0;

	name = new string("__DEFAULT__");
}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	//(*this).real = real; //equivalent to line above
	this->imaginary = imaginary;
	
	
	name = new string("__CUSTOM__");
}

Complex::Complex(const Complex& complex2) {
	this->real = complex2.real;
	this->imaginary = complex2.imaginary;
	this->name = new string(*complex2.name);
}

Complex::~Complex() {
	if (name != nullptr) {
		delete name;
		this->name = nullptr;
	}
}

void Complex::printValues() {
	string imaginarySign = "+";
	if (imaginary < 0) {
		imaginarySign = "-";
	}
	cout << real;
	
	if (imaginary != 0) {
		cout << imaginarySign << abs(imaginary) << "i";
	}
}

void Complex::assignValues(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}


void Complex::swap(Complex& b) { // question 5a/5b
    double tempreal = this->real;
    double tempimaginary = this->imaginary;
    
    this->real = b.real;
    this->imaginary = b.imaginary;
    
    b.real = tempreal;
    b.imaginary = tempimaginary;
}


Complex Complex::operator=(const Complex& complex2) {
	Complex temp;
	temp.real = complex2.real;
	temp.imaginary = complex2.imaginary;
	delete temp.name;	
	temp.name = new string(*complex2.name);

	return temp;
}


Complex Complex::operator*(const Complex& complex2){ // question 4a/4b
    Complex temp;
	temp.real = (this->real * this->imaginary) - (this->imaginary * complex2.imaginary);
	temp.imaginary = (this->real * complex2.imaginary) + (this->imaginary * complex2.real) ;

	return temp;
}

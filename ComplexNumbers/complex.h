// Coded by Kyle Graham
// Program 1
// CSS 342
// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;
namespace KG_COMPLEX
{
	class Complex
	{
	public:
		//default constructor, takes in 0, 1, or 2 variables, set to 0.0 and 
		//0.0 as default
		Complex(double real = 0.0, double imaginary = 0.0)
			: m_real(real), m_imaginary(imaginary) {}
		friend ostream& operator<<(ostream& sout, const Complex &complexNumber);
		friend istream& operator>>(istream& sin, Complex& complexNumber);
//assumption made, added comments for inline methods
// ----------------------------------------------------------------------------
//	double getReal()
//	description:    returns the real portion of a complex number
// ----------------------------------------------------------------------------
		double getReal() const {return m_real;}
// ----------------------------------------------------------------------------
//	double getImaginary()
//	description:    returns the imaginary portion of a complex number
// ----------------------------------------------------------------------------
		double getImaginary()const {return m_imaginary;}
// ----------------------------------------------------------------------------
//	Complex conjugate()const
//	description:    returns conjugate of a complex number
// ----------------------------------------------------------------------------
		Complex conjugate()const
			{return Complex(m_real, -m_imaginary);}
		double abs();
		// operators
		Complex operator+(const Complex &complexNumber) const;	
		Complex operator-(const Complex & complexNumber) const;
		//assumption made on how to handle divison by zero in / operator
		//assumed to make the complex equal 0.0 and to cout the attempt
		//at divison by zero
		Complex operator/(const Complex & complexNumber) const;
		Complex operator/(const double d) const;
		Complex operator*(const Complex & complexNumber) const;
		Complex operator*(const double &d) const;
// ----------------------------------------------------------------------------
//	operator +=
//	description:    returns a value with a complex number added on to it
// ----------------------------------------------------------------------------
		Complex& operator+=(const Complex & complexNumber)
			{return (*this = *this + complexNumber);}
// ----------------------------------------------------------------------------
//	operator -=
//	description:    returns a value with a complex number subtracted from it
// ----------------------------------------------------------------------------
		Complex& operator-=(const Complex & complexNumber)
			{return (*this = *this - complexNumber);}
// ----------------------------------------------------------------------------
//	operator *=
//	description:    returns a value with a complex number multiplied to it
// ----------------------------------------------------------------------------
		Complex& operator*=(const Complex & complexNumber)
			{return (*this = *this * complexNumber);}
// ----------------------------------------------------------------------------
//	operator *=(double d)
//	description:    returns a value with a double multiplied to it
// ----------------------------------------------------------------------------
		Complex& operator*=(const double d)
			{return (*this = *this * d);}
// ----------------------------------------------------------------------------
//	operator /=
//	description:    returns a value with a complex number divided from it
// ----------------------------------------------------------------------------
		Complex& operator/=(const Complex & complexNumber)
			{return (*this = *this / complexNumber);}
// ----------------------------------------------------------------------------
//	operator /=(double d)
//	description:    returns a value with a double divided from it
// ----------------------------------------------------------------------------
		Complex& operator/=(const double d)
			{return (*this = *this / d);}
// ----------------------------------------------------------------------------
//	bool operator !=
//	description:    returns true if false
// ----------------------------------------------------------------------------
		bool operator!=(const Complex & complexNumber) const
			{return (m_real != complexNumber.m_real
			|| m_imaginary != complexNumber.m_imaginary);}
// ----------------------------------------------------------------------------
//	bool operator ==
//	description:    returns true if true
// ----------------------------------------------------------------------------
		bool operator==(const Complex & complexNumber) const
			{return (m_real == complexNumber.m_real
			&& m_imaginary == complexNumber.m_imaginary);}
	private:
		// properties
		double m_real;
		double m_imaginary;
	};


	
	
}

#endif
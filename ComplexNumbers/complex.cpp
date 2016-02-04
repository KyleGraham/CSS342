// Coded by Kyle Graham
// Program 1
// CSS 342
// complex.cpp
#include "complex.h"
#include <math.h>
using namespace std;
namespace KG_COMPLEX
{
//-----------------------------------------------------------------------------
//	operator +
//	description:   returns an object that is added by a complex number
//-----------------------------------------------------------------------------
	Complex Complex::operator+(const Complex &complexNumber) const
	{
		return Complex(m_real + complexNumber.m_real,
				m_imaginary + complexNumber.m_imaginary);
	}
//-----------------------------------------------------------------------------
//	operator -
//	description:   returns an object that is subtracted by a complex number
//-----------------------------------------------------------------------------
	Complex Complex::operator-(const Complex & complexNumber) const
	{
		return Complex(m_real - complexNumber.m_real,
				m_imaginary - complexNumber.m_imaginary);
	}
//-----------------------------------------------------------------------------
//	operator /(const Complex & complexNumber)
//	description:   returns an object that is this divided by a complex number
//				   handles division by zero
//-----------------------------------------------------------------------------
	Complex Complex::operator/(const Complex & complexNumber) const
	{
		//assumption made on how to handle divison by zero
		if(complexNumber.m_real == 0.0 && complexNumber.m_imaginary == 0.0)
		{
			cout << "Division by zero" << endl;
			return Complex(0.0, 0.0);
		}
		else
			
		{
		double divisor = complexNumber.m_real * complexNumber.m_real
			+ complexNumber.m_imaginary
			* complexNumber.m_imaginary;
		return Complex(((m_real * complexNumber.m_real)
			+ (m_imaginary * complexNumber.m_imaginary)) / divisor,
			(m_imaginary * complexNumber.m_real
			- m_real * complexNumber.m_imaginary) / divisor);
		}
	}
//-----------------------------------------------------------------------------
//	operator /(const double d)
//	description:   returns an object that is this divided by a double
//				   handles division by zero
//-----------------------------------------------------------------------------
	Complex Complex::operator/(const double d) const
	{
		return Complex((m_real / d), (m_imaginary / d));
	}
//-----------------------------------------------------------------------------
//	operator *
//	description:   returns an object multiplied by another complex number 
//-----------------------------------------------------------------------------
	Complex Complex::operator*(const Complex &complexNumber) const
	{
		return Complex(((m_real * complexNumber.m_real)
			- (m_imaginary * complexNumber.m_imaginary)),
			(m_imaginary * complexNumber.m_real + m_real
				* complexNumber.m_imaginary));
	}
//-----------------------------------------------------------------------------
//	operator * (double)
//	description:   returns an object that is this multiplied by a double
//-----------------------------------------------------------------------------
	Complex Complex::operator*(const double &d) const
	{
		return Complex((m_real * d),(m_imaginary * d));

	}
// ----------------------------------------------------------------------------
//	operator <<
//	description:    prints out the c object to the stream
// ----------------------------------------------------------------------------
	ostream& operator<<(ostream& sout, const Complex &complexNumber)
	{
	   if(complexNumber.m_real != 0.0)
			sout << complexNumber.m_real; 
		if(complexNumber.m_real == 0.0 && complexNumber.m_imaginary == 0.0)
			sout << "0";

		if(complexNumber.m_imaginary != 0.0)
		{
			if(complexNumber.m_imaginary < 0.0)
			{
				if(complexNumber.m_real == 0.0)
				{
					sout << "-";
				}
				else
				{
					sout << " - ";
				}
				if(complexNumber.m_imaginary != -1.0)
					sout << -complexNumber.m_imaginary;
			}
			else
			{
				if(complexNumber.m_real != 0.0)
					sout << " + ";
				if(complexNumber.m_imaginary != 1.0)
					sout << complexNumber.m_imaginary;
			}
			sout << 'i';
		}
	   return sout;
	}

// ----------------------------------------------------------------------------
//  operator >>
//	description:	takes in complex numbers as input
//-----------------------------------------------------------------------------
	istream& operator>>(istream	&sin, Complex &complexNumber)
	{ 
		sin >> complexNumber.m_real >> complexNumber.m_imaginary;
		return sin;

	} 
	double Complex::abs()
	{
		return (sqrt(m_imaginary * m_imaginary + m_real * m_real));
	}

} 


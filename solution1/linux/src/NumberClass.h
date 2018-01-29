/* Summary: this is the head file for a Number class library.
 *          There is one pure virtual base class 'Number' 
 *          and two derived class 'Integer' and 'Fraction'.
 *
 * Operations: there are in total three operations for these two derived class.
 *         1. display: display the Number in its original form.   
 *         2. == :   return true if two Numbers are numerically the same.
 *         3. +  :   add the Number itself with another Number and return a third Number.
 *
 * Author: Hongzhuan Lei
 * Date:  12/13/2017 10:45:30 AM
 *
**/

#ifndef NUMBER_CLASS_HEADER_HL
#define NUMBER_CLASS_HEADER_HL

#include "Numberlib.h"

// build a namespace 'NUM' for this lib.
namespace NUM
{
// create Integer class based on Number
class Integer : public Number
{
public:
	// display function
	virtual void display() const override;
	// == operator
	virtual bool operator==(const Number& num) const override;
	// + operator
	virtual Number& operator+(const Number& num) const override;
	// destructor
	virtual ~Integer() {};

        // set value: 1) for Integer type, set iNumerator as its integer value, and iDenominator is 1.
        // 2) for Fraction type, set iNumerator and iDenominator to its corresponding value.       
        virtual void setValue(int iNumerator, int iDenominator = 1) override;
        // get value: 1) for Integer type, iNumerator return its integer value, and iDenominator always return 1.
        // 2) for Fraction type, return its corresponding numerator and denominator value.
        virtual void getValue(int& iNumerator, int& iDenominator) const override;

private:
	int  m_iValue;  // integer value

};

// create Fraction class based on Number
class Fraction : public Number
{
public:
	// display function
	virtual void display() const override;
	// == operator
	virtual bool operator==(const Number& num) const override;
	// + operator
	virtual Number& operator+(const Number& num) const override;
	// destructor
	virtual ~Fraction() {};

        // set value: 1) for Integer type, set iNumerator as its integer value, and iDenominator is 1.
        // 2) for Fraction type, set iNumerator and iDenominator to its corresponding value.       
        virtual void setValue(int iNumerator, int iDenominator = 1) override;
        // get value: 1) for Integer type, iNumerator return its integer value, and iDenominator always return 1.
        // 2) for Fraction type, return its corresponding numerator and denominator value.
        virtual void getValue(int& iNumerator, int& iDenominator) const override;

private:
	int  m_iNumerator;   // numerator value
	int  m_iDenominator; // denominator value

};
		
}

#endif

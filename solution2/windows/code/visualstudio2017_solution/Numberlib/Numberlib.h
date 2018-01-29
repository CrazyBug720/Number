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

#pragma once

//construct export/import 
#ifdef NUMBERLIB_EXPORTS
#define NUMBERLIB_API __declspec(dllexport)
#else
#define NUMBERLIB_API __declspec(dllimport)
#endif

#include <memory>
// build a namespace 'NUM' for this lib.
namespace NUM
{
// create a pure virtual base class 'Number'
// and support three operations. 
class NUMBERLIB_API Number
{
public:
	// display function
	virtual void display() const = 0;
	// == operator
	virtual bool operator==(const Number& num) const = 0;
	// + operator
	virtual std::unique_ptr<Number> operator+(const Number& num) const = 0;
	// virtual destructor to make sure destruct derived class
	virtual ~Number() {}; // ...........
};

// create Integer class based on Number
class NUMBERLIB_API Integer : public Number
{
public:
	// display function
	virtual void display() const override;
	// == operator
	virtual bool operator==(const Number& num) const override;
	// + operator
	virtual std::unique_ptr<Number> operator+(const Number& num) const override;
	// destructor
	virtual ~Integer() {};

	// set value
	void setValue(int iValue);
	// get value
	int  getValue() const;

private:
	int  m_iValue;  // integer value

};

// create Fraction class based on Number
class NUMBERLIB_API Fraction : public Number
{
public:
	// display function
	virtual void display() const override;
	// == operator
	virtual bool operator==(const Number& num) const override;
	// + operator
	virtual std::unique_ptr<Number> operator+(const Number& num) const override;
	// destructor
	virtual ~Fraction() {};

	// set value
	void setValue(int iNumberator, int iDenominator);
	// get value
	void getValue(int& iNumberator, int& iDenominator) const;

private:
	int  m_iNumerator;   // numerator value
	int  m_iDenominator; // denominator value

};

// create Number objects using factory pattern
class NUMBERLIB_API NumberFactory
{
public:
	// Number type: Integer or Fraction
	enum NumberType
	{
		IntegerType = 0,
		FractionType
	};

	// create Number types using factory pattern
	static std::unique_ptr<Number> creatNumber(NumberType numType);

};
		

}
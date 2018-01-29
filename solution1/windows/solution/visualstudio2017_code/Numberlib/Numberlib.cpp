/* Summary: this is the implemention file for a Number class library.
*          There is one pure virtual base class 'Number'
*          and two derived class 'Integer' and 'Fraction'.
*
* Operations: there are in total three operations for these two derived class.
*         1. display: display the Number in its original form.
*         2. == :   return true if two Numbers are numerically the same.
*         3. +  :   add the Number itself with another Number and return a third Number.
*
* Author: Hongzhuan Lei
* Date:  12/13/2017 10:50:30 AM
*
**/

#include "Numberlib.h"
#include "NumberClass.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////
namespace NUM
{
	//////////////////////////////////////////////////////////////////////////
	// create Number objects based on NumberType
	Number* NumberFactory::creatNumber(NumberFactory::NumberType numType)
	{
		switch (numType)
		{
		case NumberFactory::IntegerType:
			return new Integer;
		case NumberFactory::FractionType:
			return new Fraction;
		default:
			break;
		}
		// throw exceptions
		throw invalid_argument("Invalid Number Type! Only two kinds of number are supported: Integer or Fraction.");
	}
	
}
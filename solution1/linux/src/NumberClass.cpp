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

#include "NumberClass.h"
#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

//////////////////////////////////////////////////////////////////////////
namespace NUM
{
	//////////////////////////////////////////////////////////////////////////
	// display the integer value
	void Integer::display() const
	{
		cout << m_iValue << endl;
	}
	// compare if two Numbers are numerically equal
	bool Integer::operator==(const Number& num) const
	{
		const Integer* pInt = dynamic_cast<const Integer*>(&num);
		if (pInt)
		{
			// compare two integers
			int iNumerator = 0, iDenominator = 0;
			pInt->getValue(iNumerator, iDenominator);
			return iNumerator == m_iValue;
		}
		const Fraction* pFrac = dynamic_cast<const Fraction*>(&num);
		if (pFrac == NULL)
			throw runtime_error("Invalid number type when do the operator '=='.");

		int iNumerator = 0, iDenominator = 0;
		pFrac->getValue(iNumerator, iDenominator);
		// compare integer with fraction
		return ( (iNumerator % iDenominator == 0) &&
			   (m_iValue == iNumerator / iDenominator) );
	}
	// add the Number itself with another Number and return a third Number
	Number& Integer::operator+(const Number& num) const
	{
		const Integer* pInt = dynamic_cast<const Integer*>(&num);
		if (pInt) // two integer '+', return a new integer
		{
			// handle potential overflow/underflow
			int iNumerator = 0, iDenominator = 0;
			pInt->getValue(iNumerator, iDenominator);
			int iTmp = m_iValue + iNumerator;
			if ((m_iValue>0 && iNumerator>INT_MAX - m_iValue)
				|| (m_iValue<0 && iNumerator<INT_MIN - m_iValue))
				throw runtime_error("Operator '+' causes overflow/underflow!");

			// create a new integer, set value and return
			Number* pNum = NumberFactory::creatNumber(NumberFactory::IntegerType);
			Integer* pNewInt = dynamic_cast<Integer*>(pNum);
			if (pNewInt == NULL)
				throw runtime_error("Create 'Number' type failed!");

			pNewInt->setValue(iTmp);
			return *pNum;
		}
		// integer + fraction, return a new fraction
		const Fraction* pFrac = dynamic_cast<const Fraction*>(&num);
		if (pFrac == NULL)
			throw runtime_error("Invalid number type when do the operator '+'.");

		int iNumerator = 0, iDenominator = 0;
		pFrac->getValue(iNumerator, iDenominator);
		// handle potential overflow/underflow
		int iTmp = iDenominator*m_iValue;
		int iTmp2 = iNumerator + iTmp;
		if ((iDenominator != 0 && iTmp / iDenominator != m_iValue)
			|| (iTmp>0 && iNumerator>INT_MAX - iTmp)
			|| (iTmp<0 && iNumerator<INT_MIN - iTmp) )
			throw runtime_error("Operator '+' causes overflow/underflow!");

		Number* pNum = NumberFactory::creatNumber(NumberFactory::FractionType);
		Fraction* pNewFrac = dynamic_cast<Fraction*>(pNum);
		if (pNewFrac == NULL)
			throw runtime_error("Create 'Number' type failed!");

		pNewFrac->setValue(iTmp2, iDenominator);
		return *pNum;
	}
		
	void Integer::setValue(int iNumerator, int iDenominator /* = 1 */)
	{
		m_iValue = iNumerator;
	}
	void  Integer::getValue(int& iNumerator, int& iDenominator) const
	{
		iNumerator = m_iValue;
                iDenominator = 1;
	}

	//////////////////////////////////////////////////////////////////////////
	// display the integer value
	void Fraction::display() const
	{
		cout << m_iNumerator << "/" << m_iDenominator << endl;
	}
	// compare if two Numbers are numerically equal
	bool Fraction::operator==(const Number& num) const
	{
		const Fraction* pFrac = dynamic_cast<const Fraction*>(&num);
		if (pFrac)
		{
			int iNumerator = 0, iDenominator = 0;
			pFrac->getValue(iNumerator, iDenominator);
			// compare two fraction value
			if (m_iNumerator / m_iDenominator != iNumerator / iDenominator)
				return false;
                        // handle potential overflow/underflow
                        int iTmp1 = m_iDenominator * iNumerator;
                        int iTmp2 = m_iNumerator * iDenominator;
                        if ( (m_iDenominator != 0 && iTmp1 / m_iDenominator != iNumerator)
                            || (iDenominator != 0 && iTmp2 / iDenominator != m_iNumerator) )
                            throw runtime_error("Operator '==' causes overflow/underflow when comparing two fractions!");
                       
                        return iTmp1 == iTmp2;
		}
		const Integer* pInt = dynamic_cast<const Integer*>(&num);
		if (pInt == NULL)
			throw runtime_error("Invalid number type when do the operator '=='.");
		// compare fraction with integer	
		int iNumerator = 0, iDenominator = 0;
		pInt->getValue(iNumerator, iDenominator);
		return ((m_iNumerator % m_iDenominator == 0) &&
			(iNumerator == m_iNumerator / m_iDenominator));
	}
	// add the Number itself with another Number and return a third Number
        Number& Fraction::operator+(const Number& num) const
	{
		int iNewNumerator = 0, iNewDenominator = 0;
		const Integer* pInt = dynamic_cast<const Integer*>(&num);
		if (pInt)  // integer + fraction, return a new fraction
		{
			// handle potential overflow/underflow
			int iNumerator = 0, iDenominator = 0;
			pInt->getValue(iNumerator, iDenominator);
			int iTmp = m_iDenominator*iNumerator;
			iNewNumerator = m_iNumerator + iTmp;
			if ( (m_iDenominator != 0 && iTmp / m_iDenominator != iNumerator)
				 || (iTmp>0 && m_iNumerator>INT_MAX - iTmp)
				 || (iTmp<0 && m_iNumerator<INT_MIN - iTmp) )
				throw runtime_error("Operator '+' causes overflow/underflow!");

			iNewDenominator = m_iDenominator;
		}
		else // fraction + fraction, return a new fraction
		{
			const Fraction* pFrac = dynamic_cast<const Fraction*>(&num);
			if (pFrac == NULL)
				throw runtime_error("Invalid number type when do the operator '+'.");

			int iNumerator = 0, iDenominator = 0;
			pFrac->getValue(iNumerator, iDenominator);
			// handle potential overflow/underflow
			int iTmp1 = iNumerator*m_iDenominator;
			int iTmp2 = iDenominator*m_iNumerator;
			iNewNumerator = iTmp1 + iTmp2;
			iNewDenominator = iDenominator*m_iDenominator;
			if (iTmp1 / m_iDenominator != iNumerator
				|| iTmp2 / iDenominator != m_iNumerator
				|| iNewDenominator/iDenominator != m_iDenominator
				|| (iTmp1>0 && iTmp2>INT_MAX-iTmp1)
				|| (iTmp1<0 && iTmp2<INT_MIN - iTmp1) )
				throw runtime_error("Operator '+' causes overflow/underflow!");
		}
		Number* pNum = NumberFactory::creatNumber(NumberFactory::FractionType);
		Fraction* pNewFrac = dynamic_cast<Fraction*>(pNum);
		if (pNewFrac == NULL)
			throw runtime_error("Create 'Number' type failed!");

		pNewFrac->setValue(iNewNumerator, iNewDenominator);
		return *pNum;
	}

	void Fraction::setValue(int iNumerator, int iDenominator /* = 1 */)
	{
		if (0 == iDenominator)
			throw invalid_argument("Denominator can not be zero!");

		m_iNumerator = iNumerator;
		m_iDenominator = iDenominator;
	}
	void Fraction::getValue(int& iNumerator, int& iDenominator) const
	{
		iNumerator = m_iNumerator;
		iDenominator = m_iDenominator;
	}

}

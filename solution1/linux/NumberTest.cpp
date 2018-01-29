/* Summary : this is a test program for testing Numberlib.lib
*
* Author: Hongzhuan Lei
* Date : 12/13/2017 15:20:30 PM
*
*/

#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "inc/Numberlib.h"
#include <climits>

using namespace std;
using namespace NUM;

// detailed test function
void _test()
{
	// create two Integer objects: pInt1 and pInt2
	Number* pInt1 = NumberFactory::creatNumber(NumberFactory::IntegerType);
	if (pInt1 == NULL)
		throw runtime_error("Create Integer Type Failed!");
	pInt1->setValue(1);

	Number* pInt2 = NumberFactory::creatNumber(NumberFactory::IntegerType);
	if (pInt2 == NULL)
		throw runtime_error("Create Integer Type Failed!");
	pInt2->setValue(2);

	// create two Fraction objects: pFrac1 and pFrac2
	Number* pFrac1 = NumberFactory::creatNumber(NumberFactory::FractionType);
	if (pFrac1 == NULL)
		throw runtime_error("Create Fraction Type Failed!");
	pFrac1->setValue(1, 2);

	Number* pFrac2 = NumberFactory::creatNumber(NumberFactory::FractionType);
	if (pFrac2 == NULL)
		throw runtime_error("Create Fraction Type Failed!");
	pFrac2->setValue(2, 4);

	// test display function
	cout << "Test function 'display' : " << endl;
	cout << "Created two Integers: Int1  Int2 " << endl;
	pInt1->display();
	pInt2->display();
	cout << "Created two Fractions: Frac1 Frac2" << endl;
	pFrac1->display();
	pFrac2->display();
	cout << endl;

	// test '==' operator
	cout << "Test operator '==' : " << endl;
	cout << " Determine if Int1 == Int1: "<< endl;
	bool bRes = (*pInt1) == (*pInt1);
	cout << bRes << endl;
	cout << " Determine if Int1 == Int2: " << endl;
	bRes = (*pInt1) == (*pInt2);
	cout << bRes << endl;

	cout << " Determine if Frac1 == Frac1: " << endl;
	bRes = (*pFrac1) == (*pFrac1);
	cout << bRes << endl;
	cout << " Determine if Frac1 == Frac2: " << endl;
	bRes = (*pFrac1) == (*pFrac2);
	cout << bRes << endl;

	cout << " Determine if Int1 == Frac1: " << endl;
	bRes = (*pInt1) == (*pFrac1);
	cout << bRes << endl;

	cout << " Determine if Int1 == Frac2: " << endl;
	bRes = (*pInt1) == (*pFrac2);
	cout << bRes << endl;
	cout << endl;

	// test '+' operator
	cout << "Test operator '+' : " << endl;
	cout << " Int1 + Int2: " << endl;
	Number* pNew1 = &((*pInt1) + (*pInt2));
	if (pNew1 == NULL)
		throw runtime_error("Test 'Int1 + Int2' Failed!");
	pNew1->display();

	cout << " Frac1 + Frac2: " << endl;
	Number* pNew2 = &((*pFrac1) + (*pFrac2));
	if (pNew2 == NULL)
		throw runtime_error("Test 'Frac1 + Frac2' Failed!");
	pNew2->display();

	cout << " Int1 + Frac1: " << endl;
	Number* pNew3 = &((*pInt1) + (*pFrac1));
	if (pNew3 == NULL)
		throw runtime_error("Test 'Int1 + Frac1' Failed!");
	pNew3->display();
	
	cout << " Int1 + Int2 + Frac1 + Frac2: " << endl;
	Number* pNewCas = &((*pInt1) + (*pInt2)+ (*pFrac1) + (*pFrac2));
	if (pNewCas == NULL)
		throw runtime_error("Test 'Int1 + Int2 + Frac1 + Frac2' Failed!");
	pNewCas->display();
	cout << endl;

	// test potential exceptions
	cout << "Test exceptions: " << endl;
	// invalid Number type: compile error
	//Number* pNum4 = NumberFactory::creatNumber(2); 
	
	// denominator is zero 
	//pFrac1->setValue(2, 0); 

///*
	// test overflow for '+' operator
	pFrac1->setValue(INT_MAX, 1); 
	pFrac2->setValue(INT_MAX, 2); 
	cout << "Reset Frac1 and Frac2: " << endl;
	pFrac1->display();
	pFrac2->display();
	cout << " Frac1 + Frac2: " << endl;
	Number* pNew4 = &((*pFrac1) + (*pFrac2));
	if (pNew4 == NULL)
		throw runtime_error("Test 'Frac1 + Frac2' Failed!");
	pNew4->display();
//*/

/*
	// test underflow for '+' operator
	pFrac1->setValue(INT_MIN, 1);  
	pFrac2->setValue(INT_MIN, 2); 
	cout << "Reset Frac1 and Frac2: " << endl;
	pFrac1->display();
	pFrac2->display();
	cout << " Frac1 + Frac2: " << endl;
	Number* pNew5 = &((*pFrac1) + (*pFrac2));
	if (pNew5 == NULL)
		throw runtime_error("Test 'Frac1 + Frac2' Failed!");
	pNew5->display();
*/
	cout << endl;
	cout << "End of Test." << endl;

	// free memory
	delete pInt1, pInt2, pFrac1, pFrac2;
	delete pNew1, pNew2, pNew3, pNew4, pNewCas;
	
}
// test function
void test()
{
	try
	{
		_test();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
// main function
int  main()
{
	test();
        return 0;
}

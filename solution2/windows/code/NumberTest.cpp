/* Summary : this is a test program for testing Numberlib.lib
*
* Author: Hongzhuan Lei
* Date : 12/13/2017 15:20:30 PM
*
*/

#include <stdlib.h>
#include <iostream>
#include "inc\Numberlib.h"

using namespace std;
using namespace NUM;

// detailed test function
void _test()
{
	// create two Integer objects: pInt1 and pInt2
	unique_ptr<Number> pNum1 = NumberFactory::creatNumber(NumberFactory::IntegerType);
	Integer* pInt1 = dynamic_cast<Integer*>(pNum1.get());
	if (pInt1 == NULL)
		throw runtime_error("Create Integer Type Failed!");
	pInt1->setValue(1);

	unique_ptr<Number> pNum2 = NumberFactory::creatNumber(NumberFactory::IntegerType);
	Integer* pInt2 = dynamic_cast<Integer*>(pNum2.get());
	if (pInt2 == NULL)
		throw runtime_error("Create Integer Type Failed!");
	pInt2->setValue(2);

	// create two Fraction objects: pFrac1 and pFrac2
	unique_ptr<Number> pNum3 = NumberFactory::creatNumber(NumberFactory::FractionType);
	Fraction* pFrac1 = dynamic_cast<Fraction*>(pNum3.get());
	if (pFrac1 == NULL)
		throw runtime_error("Create Fraction Type Failed!");
	pFrac1->setValue(2, 1);

	unique_ptr<Number> pNum4 = NumberFactory::creatNumber(NumberFactory::FractionType);
	Fraction* pFrac2 = dynamic_cast<Fraction*>(pNum4.get());
	if (pFrac2 == NULL)
		throw runtime_error("Create Fraction Type Failed!");
	pFrac2->setValue(2, 2);

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
	unique_ptr<Number> pNew1 = (*pInt1) + (*pInt2);
	if (pNew1 == NULL)
		throw runtime_error("Test 'Int1 + Int2' Failed!");
	pNew1->display();

	cout << " Frac1 + Frac2: " << endl;
	unique_ptr<Number> pNew2 = (*pFrac1) + (*pFrac2);
	if (pNew2 == NULL)
		throw runtime_error("Test 'Frac1 + Frac2' Failed!");
	pNew2->display();

	cout << " Int1 + Frac1: " << endl;
	unique_ptr<Number> pNew3 = (*pInt1) + (*pFrac1);
	if (pNew3 == NULL)
		throw runtime_error("Test 'Int1 + Frac1' Failed!");
	pNew3->display();
	cout << endl;
	
	// test potential exceptions
	cout << "Test exceptions: " << endl;
	// invalid Number type: compile error
	//unique_ptr<Number> pNum4 = NumberFactory::creatNumber(2); 
	
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
	unique_ptr<Number> pNew4 = (*pFrac1) + (*pFrac2);
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
	unique_ptr<Number> pNew5 = (*pFrac1) + (*pFrac2);
	if (pNew5 == NULL)
		throw runtime_error("Test 'Frac1 + Frac2' Failed!");
	pNew5->display();
*/
	cout << endl;
	cout << "End of Test." << endl;
	
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
int main()
{
	test();
	return 0;
}

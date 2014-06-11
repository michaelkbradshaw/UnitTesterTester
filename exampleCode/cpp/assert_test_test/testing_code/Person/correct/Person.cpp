/*
 * Person.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: bradshaw
 */

#include "Person.h"


Person::Person()
{
	init("John","Doe",0);

}

Person::Person(string fname,string lname)
{
	init(fname,lname,0);

}

Person::Person(string fname,string lname,int age)
{
	init(fname,lname,age);

}

Person operator +(const Person& A, const Person& B)
{
  Person C(A.getFirstName(),B.getLastName(),0);
	return C;
}

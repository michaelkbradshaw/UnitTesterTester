//#inlcude "Person.h"
#include <string>
#include <iostream>

using namespace std;
/*
class Person: public ProtoPerson
{
 public:


Person()
{
	init("John","Doe",0);

}

Person(string fname,string lname)
{
	init(fname,lname,0);

}

Person(string fname,string lname,int age)
{
	init(fname,lname,age);

}


void setLastName(string s)
{
  setFirstName(s);
}

  

};
*/


#include "Person.h"


void 
Person::setLastName(string s)
{
  setFirstName(s);
}




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








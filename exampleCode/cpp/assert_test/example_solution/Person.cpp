/*
 * Person.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: bradshaw
 */

#include "Person.h"


void
Person::init(string fname,string lname,int age)
{
	this->fname=fname;
	this->lname=lname;
	this->age = age;
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

//accessors

string Person::getFullName() const
{
	return fname+" "+lname;
}

string Person::getFirstName() const
{
	return fname;
}

void Person::setFirstName(string fname)
{
	this->fname = fname;
}

string Person::getLastName() const
{
	return lname;
}

void Person::setLastName(string lname)
{
	this->lname = lname;
}

int Person::getAge() const {
	return age;
}

void Person::setAge(int newAge) {
	age = newAge;
}

void Person::agePerson()
{
	age++;
}

bool Person::operator ==(const Person& them)
{
	return fname==them.fname && lname==them.lname &&
			age==them.age;
}

bool Person::operator !=(const Person& them)
{
	return ! (*this == them);
}
/*
Person operator +(const Person& A, const Person& B)
{
	Person C(A.getFirstName(),B.getLastName(),0);
	return C;
}
*/

//Person: John Doe 8
istream& operator >>(istream& in, Person& p)
{
	string junk;
	string f;
	string l;
	int a;

	in>>junk>>f>>l>>a;
	p.setFirstName(f);
	p.setLastName(l);
	p.setAge(a);
	return in;


}

ostream& operator <<(ostream& out, const Person& p)
{
	out<<"Person: "<<p.getFullName()<<" "<<p.getAge();
	return out;
}

bool Person::operator <(const Person& them)
{
	if(lname !=them.lname)
	{
		return lname<them.lname;
	}
	else if(fname != them.fname)
	{
		return fname<them.fname;
	}
	else
	{
		return age<them.age;
	}

}



Person operator +(const Person& A, const Person& B)
{
  Person C(A.getFirstName(),B.getLastName(),0);
	return C;
}




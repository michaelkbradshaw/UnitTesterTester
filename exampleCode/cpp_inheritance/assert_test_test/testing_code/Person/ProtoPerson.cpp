/*
 * ProtoPerson.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: bradshaw
 */

#include "ProtoPerson.h"


void
ProtoPerson::init(string fname,string lname,int age)
{
	this->fname=fname;
	this->lname=lname;
	this->age = age;
}

ProtoPerson::ProtoPerson()
{
	init("John","Doe",0);

}

ProtoPerson::ProtoPerson(string fname,string lname)
{
	init(fname,lname,0);

}

ProtoPerson::ProtoPerson(string fname,string lname,int age)
{
	init(fname,lname,age);

}

//accessors

string ProtoPerson::getFullName() const
{
	return fname+" "+lname;
}

string ProtoPerson::getFirstName() const
{
	return fname;
}

void ProtoPerson::setFirstName(string fname)
{
	this->fname = fname;
}

string ProtoPerson::getLastName() const
{
	return lname;
}

void ProtoPerson::setLastName(string lname)
{
	this->lname = lname;
}

int ProtoPerson::getAge() const {
	return age;
}

void ProtoPerson::setAge(int newAge) {
	age = newAge;
}

void ProtoPerson::agePerson()
{
	age++;
}

bool ProtoPerson::operator ==(const ProtoPerson& them)
{
	return fname==them.fname && lname==them.lname &&
			age==them.age;
}

bool ProtoPerson::operator !=(const ProtoPerson& them)
{
	return ! (*this == them);
}
/*
ProtoPerson operator +(const ProtoPerson& A, const ProtoPerson& B)
{
	ProtoPerson C(A.getFirstName(),B.getLastName(),0);
	return C;
}
*/

//ProtoPerson: John Doe 8
istream& operator >>(istream& in, ProtoPerson& p)
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

ostream& operator <<(ostream& out, const ProtoPerson& p)
{
	out<<"ProtoPerson: "<<p.getFullName()<<" "<<p.getAge();
	return out;
}

bool ProtoPerson::operator <(const ProtoPerson& them)
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

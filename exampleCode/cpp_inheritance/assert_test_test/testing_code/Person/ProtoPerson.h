/*
 * ProtoPerson.h
 *
 *  Created on: Jan 28, 2013
 *      Author: bradshaw
 */

#ifndef PROTOPERSON_H_
#define PROTOPERSON_H_

#include <string>
#include <iostream>

using namespace std;

class ProtoPerson
{
private:
	string fname;
	string lname;
	int age;

 protected:
	void init(string fname,string lname,int age);

	
public:

	/**
	 * creates newborn person, john Doe aged 0.
	 */
	ProtoPerson();

	/**
	 * creates newborn person, fname lname aged 0.
	 */
	ProtoPerson(string fname,string lname);

	/**
	 * Created person fname lname aged age.
	 */
	ProtoPerson(string fname,string lname,int age);


	/**
	 * Returns a string composed fof the first and last name separated by a space
	 */
	string getFullName() const;
	/**
	 * Returns the first name
	 */
	string getFirstName() const;
	/**
	 * Returns the last name
	 */
	string getLastName() const;
	/**
	 * gets the age of the person
	 */
	int getAge() const;

	/**
	 * setters for the person
	 */
	virtual void setFirstName(string newName);
	virtual void setLastName(string newName);
	virtual void setAge(int newAge);


	/**
	 * person becomes one year older
	 */
	virtual void agePerson();


	/**
	 * two persons are equal if their names and ages are the same
	 */
	virtual bool operator==(const ProtoPerson& them);

	/**
	 * if they are not equal this returns true.
	 */
	virtual bool operator!=(const ProtoPerson& them);

	/**
	 * determines the alphabetical ordering of two people.
	 *  First by last name, then first, finally by age
	 */
	virtual bool operator<(const ProtoPerson & them);

};

/**
 * As in real life, when you add two people together you get a new person.
 * The new person has the first name of A, the last name of B and is aged 0
 */
//ProtoPerson operator+(const ProtoPerson& A,const ProtoPerson & B);

/*
 * Reads in a person from a stream.
 * Assumes the person is formatted as specified in the output stream oeprator
 */
istream & operator>>(istream & in,ProtoPerson &p);


/**
 * stream operator to output a person.  John Doe aged 8 would look like
 *
 * ProtoPerson: John Doe, 8
 */
ostream & operator<<(ostream & out,const ProtoPerson & p);



#endif /* PERSON_H_ */

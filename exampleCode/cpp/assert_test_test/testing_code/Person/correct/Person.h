/*
 * Person.h
 *
 *  Created on: Jan 28, 2013
 *      Author: bradshaw
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "../ProtoPerson.h"
#include <string>
#include <iostream>

using namespace std;

class Person: public ProtoPerson
{
 public:
  Person();
  /**
   * creates newborn person, fname lname aged 0.
   */
  Person(string fname,string lname);
  
  /**
   * Created person fname lname aged age.
   */
  Person(string fname,string lname,int age);
  

};

Person operator +(const Person& A, const Person& B);



#endif /* PERSON_H_ */

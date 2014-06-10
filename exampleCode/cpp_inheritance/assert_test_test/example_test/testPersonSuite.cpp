//#include "Person.h"
#include "TEST_LIB"
#include <cassert>
#include <string>
#include <sstream>

Person A;
Person B;
Person C;

void setUp()
{
  A = Person();
  B = Person("Fred","Miller");
  C = Person("Michael","Bradshaw",100);
}


void test_global_Person_Person()
{
  
  assert(A.getFullName()=="John Doe");
  assert(A.getFirstName()=="John");
  assert(A.getLastName()=="Doe");
  assert(A.getAge()==0);
  
  assert(B.getFullName()=="Fred Miller");
  assert(B.getFirstName()=="Fred");
  assert(B.getLastName()=="Miller");
  assert(B.getAge()==0);
  
  assert(C.getFullName()=="Michael Bradshaw");
  assert(C.getFirstName()=="Michael");
  assert(C.getLastName()=="Bradshaw");
  assert(C.getAge()==100);
  
  
  
}

void testSetters()
{
  A.setFirstName("Deer");
  assert(A.getFullName()=="Deer Doe");
  assert(A.getFirstName()=="Deer");
  assert(A.getLastName()=="Doe");
  assert(A.getAge()==0);
  
  A.setLastName("Done");
  assert(A.getFullName()=="Deer Done");
  assert(A.getFirstName()=="Deer");
  assert(A.getLastName()=="Done");
  assert(A.getAge()==0);
  
  A.setAge(-15);
  
  assert(A.getFullName()=="Deer Done");
  assert(A.getFirstName()=="Deer");
  assert(A.getLastName()=="Done");
  assert(A.getAge()==-15);
  
}

void testAgePerson()
{
  C.agePerson();
  C.agePerson();
  assert(C.getAge()==102);
}

void testOperatorEquals()
{
  Person A1 = Person();
  Person B1 = Person("Fred","Miller");
  Person C1 = Person("Michael","Bradshaw",100);
  
  assert(A1==A);
  assert(B1==B);
  assert(C1==C);

  
  assert(!(A1==B));
  assert(!(B1==A) );
  assert(!(C1==B) );
  
  
  
  assert(A1!=B);
  assert(B1!=A );
  assert(C1!=B );
  
  
  assert(!(A1!=A));
  assert(!(B1!=B) );
  assert(!(C1!=C) );
  
  Person D("John","Doe",100);
  assert(A!=D);
  assert(C!=D);
  
}


void testLessThan()
{
  Person A1 = Person();
  Person B1 = Person("John","Miller");
  Person B2 = Person("Derek","Doe");
  Person B3 = Person("Derek","Doe",1);
  
  Person C1 = Person("Michael","Bradshaw",100);
  
  
  assert(! (A<A));
  
  assert(A<B);
  assert(! (B<A));
  
  assert(B2<A);
  assert(! (A<B2));
  
  assert(B2<B3);
  assert(! (B3<B2));
  
}

void testOperatorAdd()
{
  Person X = A+C;
  Person Y = C+A;

  assert(X.getFullName()=="John Bradshaw");
  assert(X.getFirstName()=="John");
  assert(X.getLastName()=="Bradshaw");
  assert(X.getAge()==0);
  
  assert(Y.getFullName()=="Michael Doe");
  assert(Y.getFirstName()=="Michael");
  assert(Y.getLastName()=="Doe");
  assert(Y.getAge()==0);
}

void testOperatorIO()
{
  
  stringstream s;

  s<<A<<" "<<B<<" "<<C;
  
  Person A1;
  Person B1;
  Person C1;
  
  s>>A1>>B1>>C1;
  
  assert(A==A1);
  assert(B==B1);
  assert(C==C1);
  
  
}



int main()
{
  setUp();
  test_global_Person_Person();
  setUp();
  testSetters();
  setUp();
  testAgePerson();
  setUp();
  testOperatorEquals();
  setUp();
  testLessThan();
  setUp();
  testOperatorAdd();
  setUp();
  testOperatorIO();
  return 0;

}

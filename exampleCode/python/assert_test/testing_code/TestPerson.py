#from TEST_LIB import *
from Person import *


def testConstructor():
    A = Person("joe","smith")
    assert A.getFirstName()=="joe"
    assert A.getLastName()=="smith"


def testSetters():
    A = Person("A","B")
    A.setFirstName("ralph")
    assert A.getFirstName()=="ralph"
    
    A.setLastName("jones")
    assert A.getLastName()=="jones"




def main():
    testConstructor()
    testSetters()

main()





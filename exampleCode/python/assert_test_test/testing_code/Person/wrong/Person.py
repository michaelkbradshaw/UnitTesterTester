# Person.py -- correct
#
# Michael K. Bradshaw
#
# June 2014




import Person.BasePerson

class Person(Person.BasePerson.BasePerson):


    def setLastName(self,lname):
        self.fname = lname


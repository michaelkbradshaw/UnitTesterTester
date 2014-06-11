# Person.py
#
# Michael K. Bradshaw
#
# June 2014

class Person(object):
    
    # fname - first name
    # lname - last name
    
    def __init__(self,fname,lname):
        self.fname = fname
        self.lname = lname

    def getFirstName(self):
        return self.fname

    def getLastName(self):
        return self.lname

    def setFirstName(self,fname):
        self.fname=fname

    def setLastName(self,lname):
        self.lname=lname

    def __str__(self):
        s = self.fname +" "+ self.lname
        return s







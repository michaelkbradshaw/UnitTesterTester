#!/bin/bash
#Unit Tester Tester
#VPL script
#
#Michael Bradshaw
#2014


#load VPL environment vars
. common_script.sh


cat > vpl_execution<<EOF
#!/usr/bin/python3
import sys
import random

#from StringIO import StringIO
import subprocess 
import glob
import os.path
import zipfile

TESTFILE = "TEST_FILE_RUNNING.cpp"
EXECFILE = "EXEC_TEST_FILE"
TEST_LIB="TEST_LIB"

def relink(text,lib):
    
    if(text.count(TEST_LIB)==0):
        print("<|--\nYou forgot to include {0} in your file\n--|>".format(TEST_LIB))
        raise Exception("No {0} included".format(TEST_LIB))

    return text.replace(TEST_LIB,lib)

def storeText(orginFile,text):
    f = open(orginFile,"w")
    f.write(text)
    f.close()

def getJars():
   return glob.glob('*.jar')

def createCommandPath(jars):
    path = ".:"
    for jar in jars:
        path+=jar+":"
    return path[:-1]

def runFile(linkedFile):
    #compile command

    #JARS = getJars() #JAVA
    compError = False
    message=""
    try:
        #cmd = ['javac','-J-Xmx16m','-cp',createCommandPath(JARS),linkedFile] #JAVA
        cmd = ['g++','-g','-o',EXECFILE ,'-lm','-lutil',linkedFile] #C/C++
        message = subprocess.check_output(cmd,stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        compError=True
        message = e.output.decode("utf-8")
 
    if(compError):
        print("<|--\nUnit Test did not compile,check locally and try again\n\nOUTPUT\n\n{0}\n--|>".format(message))
        #return False
        raise subprocess.CalledProcessError("Does not compile")

    #run command
    
    # linkedClass = linkedFile[:linkedFile.rindex('.')] # JAVA


    message = ""
    success = True
    try:
        #cmd = ['java','-cp',createCommandPath(JARS),'org.junit.runner.JUnitCore',linkedClass] #java
        cmd = ["valgrind","-q","--error-exitcode=1","--leak-check=yes","./"+EXECFILE]
        message = subprocess.check_output(cmd,stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        message = e.output
        success = False


    #return not (subprocess.call(["./"+EXECFILE],stderr=open(os.devnull)))
    return success,message.decode("utf-8")

def getText(originFile):
    f = open(originFile,'r')
    text = f.read()
    f.close()
    return text

TARGET = "VPLTestingFiles.zip"

def expandZip():
    if(os.path.isfile(TARGET)):
      z = zipfile.ZipFile(TARGET)
      z.extractall()
      z.close()


def main():
    originFile = '$VPL_SUBFILE0'#"unit.py"#sys.argv[1]

    expandZip()
     
    #get File Text - it will be destroyed later on
    text = getText(originFile)
    
    correct = 0
    total  = 0    
    
    testFile = open("Tests.txt")
    lines = testFile.readlines()
    testFile.close()
    
    for line in lines:
        line = line.strip()
        if(len(line)<2 or line[0]=='#' or line.count(":")<2):
            continue  #bad example line
        lib,result,message= line.split(':')

        total = total +1
  
        linkedtext = relink(text,lib)
        storeText(TESTFILE,linkedtext)#for C/Python use alternative path name
        success,output = runFile(TESTFILE)
        if(str(success)==result):
            correct=correct+1
            print ("passed: "+message)
        else:
            print("<|--\n{0}\n\nOUTPUT\n\n{1}\n--|>".format(message,output))
            if(result=="True"):
               correct=0
               break
    print("Grade :=>> {0}".format($VPL_GRADEMAX*correct/total))
    if (correct == total):
        print("<|--\nPerfect Score!\n--|>")
    #storeText(originFile,text) clean up not needed in C++
main()
EOF

chmod +x vpl_execution

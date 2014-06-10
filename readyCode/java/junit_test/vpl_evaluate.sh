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

#TESTFILE = "TEST_FILE_RUNNING.java"
#EXECFILE = "EXEC_TEST_FILE"
TEST_LIB="TEST_LIB"
UNIT_TEST_FILE = "vpl_unit_test.txt"


def getUnitTest():
   f = open(UNIT_TEST_FILE)
   name = f.read()
   f.close()
   return name.strip()



def getJars():
   return glob.glob('*.jar')

def createCommandPath(jars):
    path = ".:"
    for jar in jars:
        path+=jar+":"
    return path[:-1]

def runFile(linkedFile):
    #compile command
    JARS = getJars()
    compError = False
    message=""
    try:
        cmd = ['javac','-J-Xmx16m','-cp',createCommandPath(JARS),linkedFile]
        #print(cmd)
        message = subprocess.check_output(cmd,stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        compError=True
        message = e.output.decode("utf-8")
 
    if(compError):
        print("<|--\nUnit Test did not compile,check locally and try again\n\nOUTPUT\n\n{0}\n--|>".format(message))
        #return False
        raise subprocess.CalledProcessError("Does not compile")

    #run command
    
    linkedClass = linkedFile[:linkedFile.rindex('.')]


    message = ""
    success = True
    try:
        cmd = ['java','-cp',createCommandPath(JARS),'org.junit.runner.JUnitCore',linkedClass]

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
    
    orginFiles = '$VPL_SUBFILES'.split();
    sourcefiles = []
    for f in orginFiles:
        if(f.endswith("java")):
            sourcefiles.append(f)

    expandZip()


    success,output = runFile(getUnitTest())
    if(success):
        print("Grade :=>> {0}".format($VPL_GRADEMAX))
        print("<|--\nPerfect Score!\n--|>")
    else:
        print("<|--\n{0}\n\nOUTPUT\n\n{1}\n--|>".format(message,output))
  


#    print("Grade :=>> {0}".format($VPL_GRADEMAX*correct/total))

#    if (correct == total):
#        print("<|--\nPerfect Score!\n--|>")
#    storeText(originFile,text)
main()
EOF

chmod +x vpl_execution

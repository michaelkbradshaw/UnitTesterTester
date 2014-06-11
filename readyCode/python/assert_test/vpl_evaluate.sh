#!/bin/bash
# $Id: default_evaluate.sh,v 1.5 2012-07-25 19:02:21 juanca Exp $
# Default evaluate script for VPL
# Copyright (C) 2012 Juan Carlos Rodríguez-del-Pino
# License http://www.gnu.org/copyleft/gpl.html GNU GPL v3 or later
# Author Juan Carlos Rodríguez-del-Pino <jcrodriguez@dis.ulpgc.es>

#load VPL environment vars
. common_script.sh


#cool

cat > vpl_execution<<EOF
#!/usr/bin/python3
import sys
import random

#from StringIO import StringIO
import subprocess 
import glob
import os.path
import zipfile

TESTFILE = "TEST_FILE_RUNNING.py"
EXECFILE = "EXEC_TEST_FILE"
TEST_LIB="TEST_LIB"
UNIT_TEST_FILE = "vpl_unit_test.txt"

def getUnitTest():
   f = open(UNIT_TEST_FILE)
   name = f.read()
   f.close()
   return name.strip()

TARGET = "VPLTestingFiles.zip"

def expandZip():
    if(os.path.isfile(TARGET)):
      z = zipfile.ZipFile(TARGET)
      z.extractall()
      z.close()



def runFile(sourcefiles,test):

    # objs = []
    # for source in sourcefiles:

    #     base = source.split('.')[0]
    #     obj = base+".o"
    #     objs.append(obj)

    # message = ""
    # #compile source
    # try:
    #        cmd = ['g++','-g','-c','-lm','-lutil',source]
    #        message = subprocess.check_output(cmd,stderr=subprocess.STDOUT)


    #        cmd = ['g++','-g','-o',EXECFILE,'-lm','-lutil',test]+objs
    #        message +=subprocess.check_output(cmd,stderr=subprocess.STDOUT)
    # except:
    #           print(source+" failed to compile aborting test");
    #           message = e.output.decode("utf-8")
    #           print("<|--\nUnit Test did not compile,check locally and try again\n\n{0}\n\nOUTPUT\n\n{1}\n--|>".format(cmd,message))
    #           raise subprocess.CalledProcessError("Does not compile")
              

        


    #Run command
    

    message=""
    success = True
    try:
       #cmd = ["valgrind","-q","--leak-check=full","--error-exitcode=1","./"+EXECFILE]
       cmd = ["python3",test]

       message = subprocess.check_output(cmd,stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        message = e.output
        success = False


    #return not (subprocess.call(["./"+EXECFILE],stderr=open(os.devnull)))
    return success,message.decode("utf-8")




def main():
    orginFiles = '$VPL_SUBFILES'.split();
    sourcefiles = []
    for f in orginFiles:
        if(f.endswith("cpp") or f.endswith(".c") or f.endswith(".C")):
            sourcefiles.append(f)


    expandZip()


    success,output = runFile(sourcefiles,getUnitTest())

    if(success):
        print("Grade :=>> {0}".format($VPL_GRADEMAX))
        print("<|--\nPerfect Score!\n--|>")
    else:
        print("<|--\n{0}\n\nOUTPUT\n\n{1}\n--|>".format("Your code did not pass",output))
    



main()
EOF
chmod +x vpl_execution

#!/usr/bin/python3
import os
import base64
import zipfile
TARGET = "VPLTestingFiles.zip"


#stolen from here
# http://stackoverflow.com/questions/1855095/how-to-create-a-zip-archive-of-a-directory-in-python
def make_zipfile(output_filename,source_dir):
    #relroot = os.path.abspath(os.path.join(source_dir, os.pardir))
    relroot = os.getcwd()
    with zipfile.ZipFile(output_filename, "w", zipfile.ZIP_DEFLATED) as zip:
        for root, dirs, files in os.walk(source_dir):
            # add directory (needed for empty dirs)
            zip.write(root, os.path.relpath(root, relroot))
            for file in files:
                if(file.startswith(TARGET)):# or file.startswith(__file__)):
                    continue
                filename = os.path.join(root, file)
                print(filename)
                if os.path.isfile(filename): # regular files only
                    arcname = os.path.join(os.path.relpath(root, relroot), file)
                    zip.write(filename, arcname)


def main():
    
    make_zipfile(TARGET,".")
    fin = open(TARGET,"rb")
    bData = fin.read()
    fin.close()
    fout = open(TARGET+".b64",'wb')

    fout.write(base64.b64encode(bData))
    fout.close()
    

main()

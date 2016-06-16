//Please contact me at srinuk@gmail.com ,For any related work or modifications

This utility inserts doxygen template in source code before functions with one of the parameters as "message"


1.Compile the source code as shown below

While writing the source g++ 4.9 was used .

g++ doxygen_template_insertion.cpp -std=c++11 -o doxygen_template_insertion

Please check whether the version g++ 4.9 is used otherwise the tool is not going to work .For regex you need 

g++ --version
g++ (Ubuntu 4.9.3-8ubuntu2~14.04) 4.9.3
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

2.Usage
Keep the source files to be modified in "src" directory 

For Example:

/home/srinivas/browser/a.c 
/home/srinivas/browser/b.c

Put the files in src directory as shown below
/home/srinivas/browser/src/a.c
/home/srinivas/browser/src/b.c

If the above is tough feel free to modify the source at line 1084 in main function 

./doxygen_template_insertion "source code directory" "doxygen.template"

./doxygen_template_insertion /home/srinivas/browser doxygen.template 


3.In the source code repository you should see 
/home/srinivas/browser/src/a.c --->File added with doxygen template before function 
with "Message" as one of the function parameter 

/home/srinivas/browser/src/a.c.orig-->orginal source code code


/home/srinivas/browser/src/a.c-->modified source with doxygen template inserted


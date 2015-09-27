
1.Compile the source code as shown below

While writing the source g++ 4.9 was used .

g++ doxygen_template_insertion.cpp -std=c++11 -o doxygen_template_insertion

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

/home/srinivas/browser/src/a.c.orig

Original source code file



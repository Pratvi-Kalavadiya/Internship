#include<string>
#include<iostream>
#include "ExampleJNI.h"
#include "StubJava.h"

int main(int argc, const char *argv[]) {
 
std::string argument=argv[1];
int TempNumOne=argument.size();
StubJava obj2;
for (int a=0;a<=TempNumOne;a++)
        {
            obj2.argPath[a]=argument[a];
        }
     //   std::cout<<obj2.argPath;
ExampleJNI ex1;
ExampleJNI ex2;
  ex1.addValue("JNI");
  ex1.addValue("Obj1");
  
 

  ex2.addValue("JNI");
  ex2.addValue("obj2");
  ex2.addValue("done");
  ex2.printValues();
  ex2.getSize();
  ex2.sleeping();
 
  ex1.printValues();
  ex1.getSize();
  ex1.sleeping();

  return 0;
}

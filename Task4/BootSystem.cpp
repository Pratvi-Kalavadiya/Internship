
#include "BootSystem.h"
#include "StubJava.h"
#include "ExampleJNI.h"

#include "Trace.h"

BootSystem::BootSystem(){
  Trace T("BootSystem::BootSystem()");
int i,j;

 i= StubJava::initialize();
 if(i != 0){
   std::cout<<"error occured in Stubjava initialization";
 }
 j= ExampleJNI::initialize();
 if(j != 0){
   std::cout<<"error occured in Stubjava initialization";
 }
  
}

BootSystem::~BootSystem(){
  Trace T("BootSystem::~BootSystem()");
  ExampleJNI::clean();
  StubJava::clean();
}

BootSystem jniStart;

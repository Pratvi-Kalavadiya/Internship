#include <iostream>
#include <cstring>
#include "Trace.h"
#include "ExampleJNI.h"
#include "StubJava.h"


jclass ExampleJNI::cls;
jmethodID  ExampleJNI::constructor;
//jobject ExampleJNI::simpleJNITestInstance;
jmethodID  ExampleJNI::add;
jmethodID  ExampleJNI::get;
jmethodID  ExampleJNI::print;
jmethodID  ExampleJNI::sleep;
  

int ExampleJNI::initialize() {

  Trace t("ExampleJNI::initialize()");
  if(cls==0)
  {
  cls = StubJava::env->FindClass("example_simple/SimpleJNITest");
  constructor = StubJava::env->GetMethodID(cls, "<init>", "()V");
  //simpleJNITestInstance = StubJava::env->NewObject(cls, constructor);
  add = StubJava::env->GetMethodID(cls, "addValue", "(Ljava/lang/String;)V");
  get=  StubJava::env->GetMethodID(cls, "getSize", "()I");
  print =  StubJava::env->GetMethodID(cls, "printValues", "()V");
  sleep=  StubJava::env->GetMethodID(cls, "sleeping", "()V");

  return 0;
  }
  return 1;
}

void ExampleJNI::clean() {
  Trace t("ExampleJNI::clean()");
  delete cls;
 /* delete constructor;
  delete add;
  delete get;
  delete print;
  delete sleep;*/
 
}

ExampleJNI::ExampleJNI(){
  Trace t("ExampleJNI::ExampleJNI()");
  
  simpleJNITestInstance = StubJava::env->NewObject(cls, constructor);
  //if ( simpleJNITestInstance == 0 ) {
   // fprintf(stderr, "I could not create NewObject\n\n"); 
  //}  
   
}

ExampleJNI::~ExampleJNI(){
  Trace t("ExampleJNI::~ExampleJNI()");
  
}

void ExampleJNI::addValue(std::string v){
  
  char * cstr = new char [v.length()+1];
  std::strcpy(cstr, v.c_str());
  char * p = std::strtok (cstr," ");
  jstring jstr1 =  StubJava::env->NewStringUTF(p);
  StubJava::env->CallObjectMethod(simpleJNITestInstance ,add, jstr1);   
}
 	
int ExampleJNI::getSize(){

  jint listSize;
  listSize =  StubJava::env->CallIntMethod(simpleJNITestInstance , get);
  printf("The size of the Java list is: %d\n", listSize);
  return listSize;

}

void ExampleJNI::printValues(){

  StubJava::env->CallObjectMethod(simpleJNITestInstance , print);
}

void ExampleJNI::sleeping(){
  
  StubJava::env->CallObjectMethod(simpleJNITestInstance ,sleep);
    
}


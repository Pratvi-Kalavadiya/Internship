#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Trace.h"
#include "StubJava.h"

JNIEnv *StubJava::env;
JavaVM *StubJava::jvm;
char StubJava::argPath[500];
//std::string StubJava::argPath;
int StubJava::initialize() {
  //char path[500];
  Trace t("StubJava::initialize()");
  JavaVMOption options[1];
  //  std::cout << "Enter the .class file path :";
  //std::cin >> path;
  char optionString[] = "-Djava.class.path=";//"-Djava.class.path=/home/pratvi/Desktop/internship/pratvi/interoperability/call_Java_from_C++/Task2/Task4/";
  strcat(optionString,argPath);
  std::cout<<argPath;
  options[0].optionString = optionString;
  JavaVMInitArgs vm_args; //locally
  memset(&vm_args, 0, sizeof(vm_args));
  vm_args.version = JNI_VERSION_1_6;
  vm_args.nOptions = 1;
  vm_args.options = options;
  long status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args); 

   if (status == JNI_ERR) {
    fprintf(stderr, "Erro JNI_ERR\n");
    return 1; 
  }
  return 0;
}

void StubJava::clean() {
  Trace t("StubJava::clean()");
  //delete env;
  //delete jvm;
  
}

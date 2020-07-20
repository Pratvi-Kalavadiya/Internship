
#ifndef EXAMPLE_JNI_H
#define EXAMPLE_JNI_H
#include <cstring>
#include<iostream>
#include <jni.h>

class ExampleJNI {
  friend class BootSystem;
  public:
  static jclass cls;
  static jmethodID constructor;
  jobject simpleJNITestInstance;
  
  static jmethodID add;
  static jmethodID print;
  static jmethodID get;
  static jmethodID sleep;
  
  static int initialize();
  static void clean();
  
  //const char *name;
  
  public:
  
    ExampleJNI();
    ~ExampleJNI();
    void addValue(std::string v);
    int getSize();
    void printValues();
    void sleeping();
};

#endif

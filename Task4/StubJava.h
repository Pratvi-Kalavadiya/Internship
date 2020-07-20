
#ifndef STUB_JAVA_H
#define STUB_JAVA_H
#include <jni.h>
#include <cstring>
#include <string>
//class JNIEnv;
//class JavaVM;

class StubJava{

  friend class ExampleJNI;
  friend class BootSystem;

  public:
    static JNIEnv *env;
    static JavaVM *jvm;
    static char argPath[];
  static int initialize();
  static void clean();
};

#endif

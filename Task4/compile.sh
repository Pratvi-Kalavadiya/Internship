
#g++  -o UseSimpleJNITestAS -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -L${JAVA_HOME}/jre/lib/amd64/server UseSimpleJNITestAS.cpp SimpleJNITestAS.cpp -ljvm 

g++  -o Application -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -L${JAVA_HOME}/jre/lib/amd64/server  *.cpp -ljvm 






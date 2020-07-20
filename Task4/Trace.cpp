#include <iostream>

#include "Trace.h"

Trace :: Trace(const char *m){
  mess = m;
  std::cout << "enter " << mess << std::endl;
}

Trace :: ~Trace(){
  std::cout << "leave " << mess << std::endl;
}

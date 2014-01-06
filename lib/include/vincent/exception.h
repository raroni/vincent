#ifndef VINCENT_EXCEPTION_H
#define VINCENT_EXCEPTION_H

#include <string>

namespace Vincent {
  class Exception {
    std::string message;
  public:
    Exception(std::string message) : message(message) { }
  };
}

#endif

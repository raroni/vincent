#include <string>

class Exception {
  std::string message;
public:
  Exception(std::string message) : message(message) { }
};

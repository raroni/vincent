#include <string>
#include "failed_assertion.h"

namespace Vincent {
  class FailedStringEqualAssertion : public FailedAssertion {
    std::string expected;
    std::string actual;
  public:
    FailedStringEqualAssertion(std::string expected, std::string actual) : FailedAssertion(FailedAssertion::Type::StringEqual) {
      this->expected = expected;
      this->actual = actual;
    }
    std::string getExpected() {
      return expected;
    }
    std::string getActual() {
      return actual;
    }
  };
}

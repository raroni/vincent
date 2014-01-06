#include "failed_assertion.h"

namespace Vincent {
  class FailedIntegerEqualAssertion : public FailedAssertion {
    int expected;
    int actual;
  public:
    FailedIntegerEqualAssertion(int expected, int actual) : FailedAssertion(FailedAssertion::Type::IntegerEqual) {
      this->expected = expected;
      this->actual = actual;
    }
    int getExpected() {
      return expected;
    }
    int getActual() {
      return actual;
    }
  };
}

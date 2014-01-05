#include "failed_assertion.h"

namespace Vincent {
  class FailedIntegerEqualAssertion : public FailedAssertion {
    int a;
    int b;
  public:
    FailedIntegerEqualAssertion(int a, int b) : FailedAssertion(FailedAssertion::Type::IntegerEqual) {
      this->a = a;
      this->b = b;
    }
    int getA() {
      return a;
    }
    int getB() {
      return b;
    }
  };
}

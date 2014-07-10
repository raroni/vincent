#include "failed_assertion.h"

namespace Vincent {
  class FailedInRangeAssertion : public FailedAssertion {
    float expected;
    float actual;
    float tolerance;
  public:
    FailedInRangeAssertion(float expected, float actual, float tolerance) : FailedAssertion(FailedAssertion::Type::InRange) {
      this->expected = expected;
      this->actual = actual;
      this->tolerance = tolerance;
    }
    float getExpected() {
      return expected;
    }
    float getActual() {
      return actual;
    }
    float getTolerance() {
      return tolerance;
    }
  };
}

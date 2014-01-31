#include "failed_assertion.h"

namespace Vincent {
  class FailedThrowsAssertion : public FailedAssertion {
  public:
    FailedThrowsAssertion() : FailedAssertion(FailedAssertion::Type::Throws) { }
  };
}

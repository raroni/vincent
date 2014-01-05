#include "vincent/test_result.h"
#include "vincent/failed_assertion.h"
#include "vincent/test.h"

namespace Vincent {
  void Test::assert(bool result) {
    if(!result) {
      currentResult->add(new FailedAssertion(FailedAssertion::Type::True));
    }
    currentResult->incrementAssertions();
  }
  void Test::run(TestResult& result) {
    currentResult = &result;
    result.setName(name);
    run();
    currentResult = nullptr;
  }
  Test::~Test() { };
}

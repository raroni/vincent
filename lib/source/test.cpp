#include "vincent/test_result.h"
#include "vincent/failed_assertion.h"
#include "vincent/failed_integer_equal_assertion.h"
#include "vincent/test.h"

namespace Vincent {
  void Test::assert(bool result) {
    if(!result) {
      currentResult->add(new FailedAssertion(FailedAssertion::Type::True));
    }
    currentResult->incrementAssertions();
  }
  void Test::assertEqual(int expected, int actual) {
    if(expected != actual) {
      currentResult->add(new FailedIntegerEqualAssertion(expected, actual));
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

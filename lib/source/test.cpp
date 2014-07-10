#include "vincent/test_result.h"
#include "vincent/failed_assertion.h"
#include "vincent/failed_integer_equal_assertion.h"
#include "vincent/failed_string_equal_assertion.h"
#include "vincent/failed_in_range_assertion.h"
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
  
  void Test::assertInRange(float expected, float actual, float tolerance) {
    if(expected < actual-tolerance || expected > actual+tolerance) {
      currentResult->add(new FailedInRangeAssertion(expected, actual, tolerance));
    }
    currentResult->incrementAssertions();
  }

  void Test::assertEqual(std::string expected, std::string actual) {
    if(expected != actual) {
      currentResult->add(new FailedStringEqualAssertion(expected, actual));
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

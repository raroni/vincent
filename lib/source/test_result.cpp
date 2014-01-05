#include "vincent/test_case_result.h"
#include "vincent/failed_assertion.h"

namespace Vincent {
  TestResult::TestResult(TestCaseResult& testCaseResult) : testCaseResult(testCaseResult) { }

  std::string TestResult::getTestCaseName() {
    return testCaseResult.getName();
  }

  std::string TestResult::getName() {
    return name;
  }

  void TestResult::setName(std::string name) {
    this->name = name;
  }

  void TestResult::add(FailedAssertion* failedAssertion) {
    failedAssertion->setTestResult(*this);
    failedAssertions.push_back(failedAssertion);
  }

  void TestResult::incrementAssertions() {
    ++assertionsCount;
  }

  std::vector<FailedAssertion*>& TestResult::getFailedAssertions() {
    return failedAssertions;
  }

  int TestResult::getAssertionsCount() {
    return assertionsCount;
  }

  TestResult::~TestResult() {
    for(auto iterator = failedAssertions.begin(); iterator != failedAssertions.end(); ++iterator) {
      delete (*iterator);
    }
  }
}

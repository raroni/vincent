#ifndef VINCENT_FAILED_ASSERTION_H
#define VINCENT_FAILED_ASSERTION_H

#include "test_result.h"

namespace Vincent {
  class FailedAssertion {
  public:
    enum Type {
      True,
      IntegerEqual,
      Throws
    };
  private:
    TestResult* testResult = nullptr;
    Type type;
  public:
    FailedAssertion(Type type) : type(type) { }
    Type& getType() {
      return type;
    }
    void setTestResult(TestResult& testResult) {
      this->testResult = &testResult;
    }
    std::string getTestCaseName() {
      return testResult->getTestCaseName();
    }
    std::string getTestName() {
      return testResult->getName();
    }
  };
}

#endif

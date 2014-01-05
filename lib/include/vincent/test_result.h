#ifndef TEST_RESULT_H
#define TEST_RESULT_H

#include <string>
#include <vector>

namespace Vincent {
  class TestCaseResult;
  class FailedAssertion;

  class TestResult {
    std::string name;
    TestCaseResult& testCaseResult;
    std::vector<FailedAssertion*> failedAssertions;
    int assertionsCount = 0;
  public:
    TestResult(TestCaseResult& testCaseResult);
    void add(FailedAssertion* failedAssertion);
    std::string getTestCaseName();
    std::string getName();
    void incrementAssertions();
    void setName(std::string name);
    std::vector<FailedAssertion*>& getFailedAssertions();
    int getAssertionsCount();
    ~TestResult();
  };
}

#endif

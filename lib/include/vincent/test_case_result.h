#ifndef VINCENT_TEST_CASE_RESULT_H
#define VINCENT_TEST_CASE_RESULT_H

#include <vector>
#include "test_result.h"

namespace Vincent {
  class FailedAssertion;

  class TestCaseResult {
    std::vector<TestResult> testResults;
    std::string name;
  public:
    TestResult& createTestResult() {
      testResults.push_back(TestResult(*this));
      return testResults.back();
    }
    std::vector<FailedAssertion*> getFailedAssertions() {
      std::vector<FailedAssertion*> list;
      std::vector<FailedAssertion*>* testList;
      for(auto iterator = testResults.begin(); iterator != testResults.end(); ++iterator) {
        testList = &(iterator->getFailedAssertions());
        list.insert(list.end(), testList->begin(), testList->end());
      }
      return list;
    }
    std::string getName() {
      return name;
    }
    void setName(std::string name) {
      this->name = name;
    }
    int getAssertionsCount() {
      int count = 0;
      for(auto iterator = testResults.begin(); iterator != testResults.end(); ++iterator) {
        count += iterator->getAssertionsCount();
      }
      return count;
    }
  };
}

#endif

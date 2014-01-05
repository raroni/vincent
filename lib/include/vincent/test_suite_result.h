#include "test_case_result.h"

namespace Vincent {
  class FailedAssertion;

  class TestSuiteResult {
    std::vector<TestCaseResult> testCaseResults;
  public:
    TestCaseResult& createTestCaseResult() {
      testCaseResults.push_back(TestCaseResult());
      return testCaseResults.back();
    }
    std::vector<FailedAssertion*> getFailedAssertions() {
      std::vector<FailedAssertion*> list;
      std::vector<FailedAssertion*> testCaseList;
      for(auto iterator = testCaseResults.begin(); iterator != testCaseResults.end(); ++iterator) {
        testCaseList = iterator->getFailedAssertions();
        list.insert(list.end(), testCaseList.begin(), testCaseList.end());
      }
      return list;
    }
    int getAssertionsCount() {
      int count = 0;
      for(auto iterator = testCaseResults.begin(); iterator != testCaseResults.end(); ++iterator) {
        count += iterator->getAssertionsCount();
      }
      return count;
    }
  };
}

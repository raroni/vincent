#include "test_case_result.h"

namespace Vincent {
  class FailedAssertion;

  class TestSuiteResult {
    std::vector<TestCaseResult*> testCaseResults;
  public:
    TestCaseResult& createTestCaseResult() {
      testCaseResults.push_back(new TestCaseResult());
      return *testCaseResults.back();
    }
    std::vector<FailedAssertion*> getFailedAssertions() {
      std::vector<FailedAssertion*> list;
      std::vector<FailedAssertion*> testCaseList;
      for(TestCaseResult* testCaseResult : testCaseResults) {
        testCaseList = testCaseResult->getFailedAssertions();
        list.insert(list.end(), testCaseList.begin(), testCaseList.end());
      }
      return list;
    }
    int getAssertionsCount() {
      int count = 0;
      for(TestCaseResult* testCaseResult : testCaseResults) {
        count += testCaseResult->getAssertionsCount();
      }
      return count;
    }
    ~TestSuiteResult() {
      for(TestCaseResult* testCaseResult : testCaseResults) {
        delete testCaseResult;
      }
    }
  };
}

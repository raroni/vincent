#include <vector>
#include "test_case.h"
#include "test_suite_result.h"

namespace Vincent {
  class TestSuite {
    std::vector<TestCase*> cases;
  public:
    void add(TestCase* testCase) {
      cases.push_back(testCase);
    }
    ~TestSuite() {
      for(auto iterator = cases.begin(); iterator != cases.end(); ++iterator) {
        delete (*iterator);
      }
    }
    void run(TestSuiteResult& result) {
      TestCase* testCase;
      for(auto iterator = cases.begin(); iterator != cases.end(); ++iterator) {
        testCase = *iterator;
        testCase->run(result.createTestCaseResult());
      }
    }
  };
}

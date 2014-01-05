#include <iostream>
#include "failed_assertion.h"

namespace Vincent {
  class TextPresentation {
    TestSuiteResult& result;
    std::string getText(FailedAssertion& failedAssertion) {
      std::string message = failedAssertion.getTestCaseName() + "/" + failedAssertion.getTestName() + ": ";
      switch(failedAssertion.getType()) {
        case FailedAssertion::Type::True:
        message += "Expected true.";
        break;
        default:
        throw new Exception("Did not understand failed assertion type.");
        break;
      }
      return message;
    }
  public:
    TextPresentation(TestSuiteResult& result) : result(result) { }
    void present() {
      std::vector<FailedAssertion*> failedAssertions = result.getFailedAssertions();
      std::cout << result.getAssertionsCount() << " assertions, " << failedAssertions.size() << " failed.\n";
      if(failedAssertions.size() != 0) {
        std::cout << "\n";
        for(auto iterator = failedAssertions.begin(); iterator != failedAssertions.end(); ++iterator) {
          std::cout << getText(**iterator) << "\n";
        }
      }
    }
  };
}

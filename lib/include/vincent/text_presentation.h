#include <iostream>
#include "vincent/failed_assertion.h"
#include "vincent/failed_integer_equal_assertion.h"
#include "vincent/failed_string_equal_assertion.h"

namespace Vincent {
  class TextPresentation {
    TestSuiteResult& result;
    std::string getText(FailedAssertion& failedAssertion) {
      std::string message = failedAssertion.getTestCaseName() + "/" + failedAssertion.getTestName() + ": ";
      switch(failedAssertion.getType()) {
        case FailedAssertion::Type::True:
        message += "Expected true";
        break;
        case FailedAssertion::Type::IntegerEqual: {
          auto failedIntegerEqualAssertion = static_cast<FailedIntegerEqualAssertion&>(failedAssertion);
          message += std::to_string(failedIntegerEqualAssertion.getExpected());
          message += " did not equal ";
          message += std::to_string(failedIntegerEqualAssertion.getActual());
          break;
        }
        case FailedAssertion::Type::StringEqual: {
          auto failedStringEqualAssertion = static_cast<FailedStringEqualAssertion&>(failedAssertion);
          message += "'" + failedStringEqualAssertion.getExpected() + "'";
          message += " did not equal ";
          message += "'" + failedStringEqualAssertion.getActual() + "'";
          break;
        }
        case FailedAssertion::Type::Throws:
        message += "Did not throw exception";
        break;
        default:
        throw new Exception("Did not understand failed assertion type.");
        break;
      }
      message += ".";
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

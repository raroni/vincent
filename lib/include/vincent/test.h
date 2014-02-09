#ifndef VINCENT_TEST_H
#define VINCENT_TEST_H

#include <string>
#include <functional>
#include "vincent/failed_throws_assertion.h"

namespace Vincent {
  class TestResult;

  class Test {
    TestResult* currentResult = nullptr;
  protected:
    std::string name;
    void assert(bool result);
    void assertEqual(int expected, int actual);
    void assertEqual(std::string expected, std::string actual);
    template <class T>
    void assertThrows(std::function<void ()> function) {
      bool thrown = false;

      try {
        function();
      }
      catch(T e) {
        thrown = true;
      }

      if(!thrown) {
        currentResult->add(new FailedThrowsAssertion());
      }
      currentResult->incrementAssertions();
    }
  public:
    void run(TestResult& result);
    virtual void run() = 0;
    virtual ~Test();
  };
}

#endif

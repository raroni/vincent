#ifndef TEST_CASE_H
#define TEST_CASE_H

#include <string>
#include "test.h"
#include "exception.h"
#include "test_case_result.h"

namespace Vincent {
  class TestCase {
    std::vector<Test*> tests;
  protected:
    std::string name;
    void add(Test* test) {
      tests.push_back(test);
    }
  public:
    void run(TestCaseResult& result) {
      Test* test;
      result.setName(name);
      for(auto iterator = tests.begin(); iterator != tests.end(); ++iterator) {
        test = *iterator;
        test->run(result.createTestResult());
      }
    }
    ~TestCase() {
      for(auto iterator = tests.begin(); iterator != tests.end(); ++iterator) {
        delete (*iterator);
      }
    }
  };
}

#endif

#ifndef TEST_H
#define TEST_H

#include <string>

namespace Vincent {
  class TestResult;

  class Test {
    TestResult* currentResult = nullptr;
  protected:
    std::string name;
    void assert(bool result);
  public:
    void run(TestResult& result);
    virtual void run() = 0;
    virtual ~Test();
  };
}

#endif

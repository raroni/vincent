#ifndef VINCENT_TEST_H
#define VINCENT_TEST_H

#include <string>

namespace Vincent {
  class TestResult;

  class Test {
    TestResult* currentResult = nullptr;
  protected:
    std::string name;
    void assert(bool result);
    void assertEqual(int expected, int actual);
  public:
    void run(TestResult& result);
    virtual void run() = 0;
    virtual ~Test();
  };
}

#endif

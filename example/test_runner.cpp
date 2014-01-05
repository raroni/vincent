#include "vincent/test_suite.h"
#include "vincent/text_presentation.h"
#include "car_test_case.h"

int main() {
  Vincent::TestSuiteResult result;
  Vincent::TestSuite suite;
  suite.add(new CarTestCase());
  suite.run(result);
  Vincent::TextPresentation presentation(result);
  presentation.present();
}

#include "vincent/test.h"
#include "car.h"

class CarEngineTest : public Vincent::Test {
public:
  CarEngineTest() {
    name = "engine";
  }
  void run() {
    Car car;
    assert(car.hasEngine);
    assert(car.hasWheels);
  }
};

class CarTestCase : public Vincent::TestCase {
public:
  CarTestCase() {
    name = "car";
    add(new CarEngineTest());
  }
};

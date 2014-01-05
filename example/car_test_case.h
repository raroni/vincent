#include "vincent/test.h"
#include "car.h"

class CarEngineTest : public Vincent::Test {
public:
  CarEngineTest() {
    name = "engine";
  }
  void run() {
    Car car;
    assert(true); // just testing
    assert(car.hasEngine);
  }
};

class CarWheelsTest : public Vincent::Test {
public:
  CarWheelsTest() {
    name = "wheels";
  }
  void run() {
    Car car;
    assertEqual(car.wheelsCount, 4);
  }
};

class CarTestCase : public Vincent::TestCase {
public:
  CarTestCase() {
    name = "car";
    add(new CarEngineTest());
    add(new CarWheelsTest());
  }
};

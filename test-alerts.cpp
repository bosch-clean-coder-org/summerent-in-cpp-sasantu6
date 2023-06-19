#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to limits:TOO_HIGH") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}
TEST_CASE("infers the breach according to limits:NORMAL") {
  REQUIRE(inferBreach(32, 20, 30) == NORMAL);
}
TEST_CASE("classify temperature according to cooling type test1") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}
TEST_CASE("classify temperature according to cooling type test2") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}
TEST_CASE("classify temperature according to cooling type test3") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
}

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits UC1") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("classify temperature according to cooling type UC1") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}
TEST_CASE("classify temperature according to cooling type UC2") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}
TEST_CASE("classify temperature according to cooling type UC3") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
}
SCENARIO("checkAndAlert tests", "[checkAndAlert]")
{
	GIVEN("cooling type and temperature")
	{
		BatteryCharacter BatteryChar;
		BatteryChar.coolingType = PASSIVE_COOLING;	
		WHEN("coolingType is PASSIVE_COOLING")
		{
			checkAndAlert(TO_CONTROLLER,BatteryChar,40);
			THEN("BreachType  return as TOO_HIGH")
			{
				REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
			}
		}
		WHEN("coolingType is PASSIVE_COOLING")
		{
			checkAndAlert(TO_EMAIL,BatteryChar,40);
			THEN("BreachType  return as TOO_HIGH")
			{
				REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
			}
		}
	}
}

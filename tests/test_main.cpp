
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("test1") {
  REQUIRE(std::sqrt(1) == 1);
  REQUIRE_FALSE(2 == 1);
}
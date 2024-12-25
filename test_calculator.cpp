#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calculator.h"

TEST_SUITE("math") {
TEST_CASE("applyOperation") {
CHECK(applyOperation(2, 3, '+') == 5);
CHECK(applyOperation(5, 3, '-') == 2);
CHECK(applyOperation(4, 2, '*') == 8);
CHECK(applyOperation(6, 2, '/') == 3);
}

TEST_CASE("isValidExpression") {
CHECK(isValidExpression("12 + 5"));
CHECK(!isValidExpression("12 + a"));
CHECK(isValidExpression("3.14 * 2"));
CHECK(!isValidExpression("#invalid"));
}
}

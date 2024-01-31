#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TEST_FOR_MAX_MIN
#include <boost/test/unit_test.hpp>

#include "../headers/operations.h"

BOOST_AUTO_TEST_SUITE(MathOperationsUnitTest)

/// @addtogroup test_math_operations
/// @test [TEST_05] Test implementation of different maths operation.
///
/// TEST STEPS
/// -# Call each functiom from MathOperations and AdvancedMathOperations class
/// EXPECTED RESULT:
/// -# Each operation is working as expected
BOOST_AUTO_TEST_CASE(testMathOperations)
{
    AdvancedMathOperations calc;
    BOOST_CHECK_EQUAL(calc.performAdvancedOperation(5,7, 4), 12);
    BOOST_CHECK_CLOSE_FRACTION(calc.squareRoot(26), 5, 0.01);

    // BOOST_CHECK_EQUAL(calc.squareRoot(-1), 0);
}

BOOST_AUTO_TEST_SUITE_END()
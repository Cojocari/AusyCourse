#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TEST_FOR_MAX_MIN
#include <boost/test/unit_test.hpp>

#include "../headers/min.h"

BOOST_AUTO_TEST_SUITE(MinValUnitTest)
/// @addtogroup test_number_compare
/// @test [TEST_03] The Min object should be able to return max value from 3 ize.
///
/// TEST STEPS
/// -# Call getMin function using integer numbers
/// EXPECTED RESULT:
/// -# Min number is returned
/// TEST STEPS
/// -# Call getMin function using float numbers
/// EXPECTED RESULT:
/// -# Min number is returned
BOOST_AUTO_TEST_CASE(testMin)
{
    Min m;
    BOOST_CHECK_EQUAL(m.getMin(4,1,2), 1);
    BOOST_CHECK_EQUAL(m.getMin(4.3,1.3,2.0), 1.3);
}

/// @addtogroup test_number_compare
/// @test [TEST_04] The Min object should be abble to sort an array in asc order.
///
/// TEST STEPS
/// -# Call sortArrayAsc function using integer array
/// EXPECTED RESULT:
/// -# Array shold be sorted in asc order.

BOOST_AUTO_TEST_CASE(testSortAsc)
{
    int array[] = {2,5,4,3,1};
    int array_sorted[] = {1,2,3,4,5};
    Min m;

    BOOST_CHECK_MESSAGE(array[4] == m.getMinVal(array, 5), "something went wrong 1");
    BOOST_CHECK_EQUAL(array[4] , m.getMinVal(array, 5));

    m.sortArrayAsc(array, sizeof(array)/ sizeof(array[0]));

    for(int i = 0; i < sizeof(array)/ sizeof(array[0]); i++)
    {
        BOOST_CHECK_EQUAL(array[i], array_sorted[i]);
    }

    // or 

    BOOST_CHECK_EQUAL_COLLECTIONS(array, array + 5, array_sorted, array_sorted +5 );


    // let's simulate an error
    BOOST_CHECK_EQUAL(array[4] , m.getMinVal(array, 5));

    BOOST_CHECK_MESSAGE(array[4] == m.getMinVal(array, 5), "something went wrong 2");

    // but we know that array is sorted now so the min val is on first position
    BOOST_CHECK_MESSAGE(array[0] == m.getMinVal(array, 5), "something went wrong 3");
}

BOOST_AUTO_TEST_SUITE_END()
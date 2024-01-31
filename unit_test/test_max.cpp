#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TEST_FOR_MAX_MIN
#include <boost/test/unit_test.hpp>

#include "../headers/max.h"
#include <boost/mpl/list.hpp>

BOOST_AUTO_TEST_SUITE(MaxValUnitTest)

/// @addtogroup test_number_compare
/// @test [TEST_01] The Max object should be able to return max value from 3.
///
/// TEST STEPS
/// -# Call getMax function using integer numbers
/// EXPECTED RESULT:
/// -# Max number is returned
/// TEST STEPS
/// -# Call getMax function using float numbers
/// EXPECTED RESULT:
/// -# Max number is returned
BOOST_AUTO_TEST_CASE(testMax)
{
    Max m;
    BOOST_CHECK_EQUAL(m.getMax(4,1,2), 4);
    BOOST_CHECK_EQUAL(m.getMax(4.3,1.3,2.0), 4.3);
}

/// @addtogroup test_number_compare
/// @test [TEST_02] The Max object should be abble to sort an array in desceding order
///
/// TEST STEPS
/// -# Call sortArrayDesc function using integer array
/// EXPECTED RESULT:
/// -# Array shold be sorted in desc order.

BOOST_AUTO_TEST_CASE(testSortDesc)
{
    int array[] = {1,4,5,3,2};
    int array_sorted[] = {5,4,3,2,1};
    Max m;

    BOOST_CHECK_MESSAGE(array[2] == m.getMaxVal(array, 5), "something went wrong 1");
    
    m.sortArrayDesc(array, sizeof(array)/ sizeof(array[0]));

    for(int i = 0; i < sizeof(array)/ sizeof(array[0]); i++)
    {
        BOOST_CHECK_EQUAL(array[i], array_sorted[i]);
    }

    // or 
    BOOST_CHECK_EQUAL_COLLECTIONS(array, array + 5, array_sorted, array_sorted +5 );

    BOOST_CHECK_MESSAGE(array[2] != m.getMaxVal(array, 5), "something went wrong 2");
    //or
    BOOST_CHECK_NE(array[2], m.getMaxVal(array, 5));
    BOOST_CHECK_MESSAGE(array[0] == m.getMaxVal(array, 5), "something went wrong 3");
}

struct my_exception
{
  explicit my_exception( int ec = 0 ) : m_error_code( ec )
  {}

  int m_error_code;
};

bool is_critical( my_exception const& ex ) { return ex.m_error_code; }

void some_func( int i ) { if( i>=0 ) throw my_exception( i ); }

BOOST_AUTO_TEST_CASE( test_exception_predicate )
{
  BOOST_CHECK_EXCEPTION( some_func(0), my_exception, !is_critical );
  BOOST_CHECK_EXCEPTION( some_func(1), my_exception, !is_critical );
  BOOST_CHECK_EXCEPTION( some_func(-1), my_exception, is_critical );
}


BOOST_AUTO_TEST_SUITE_END()
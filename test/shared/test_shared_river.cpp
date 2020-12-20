#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;


BOOST_AUTO_TEST_SUITE(shared_River)

BOOST_AUTO_TEST_CASE(River_constructor){
    shared_ptr<River> river0 = make_shared<River>(0);
    shared_ptr<River> river0 = make_shared<River>(1);
    shared_ptr<River> river0 = make_shared<River>(2);
    shared_ptr<River> river0 = make_shared<River>(3);

    BOOST_TEST(river0->cardPool.empty());
    BOOST_TEST(!(river0->cardPool.empty()));
    BOOST_TEST(!(river0->cardPool.empty()));
    BOOST_TEST(!(river0->cardPool.empty()));

}
BOOST_AUTO_TEST_SUITE_END();
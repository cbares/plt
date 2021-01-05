#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"
#include "../../src/shared/ai.h"

using namespace state;
using namespace engine;
using namespace ai;
using namespace std;

BOOST_AUTO_TEST_SUITE(test_Node);

BOOST_AUTO_TEST_CASE(Node_constructor){
    shared_ptr<State> state1 = make_shared<State>(2,"../../../res/cardsData/");
    shared_ptr<Node> root1 = make_shared<Node>(state1,3);
    BOOST_TEST(root1->childs.size() == 5);
    BOOST_TEST(root1->childs[0]->childs.size() == 5);
    BOOST_TEST(root1->childs[0]->childs[0]->childs[0]->childs.size() == 0);

    shared_ptr<State> state2 = make_shared<State>(3,"../../../res/cardsData/");
    shared_ptr<Node> root2 = make_shared<Node>(state2,2);
    BOOST_TEST(root2->childs.size() == 5);
    BOOST_TEST(root2->childs[0]->childs.size() == 5);
    BOOST_TEST(root2->childs[0]->childs[0]->childs.size() == 0);

    shared_ptr<State> state3 = make_shared<State>(42,"../../../res/cardsData/");
    shared_ptr<Node> root3 = make_shared<Node>(state3,4);
    BOOST_TEST(1);

}

BOOST_AUTO_TEST_SUITE_END();
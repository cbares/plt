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

BOOST_AUTO_TEST_SUITE(test_AI_DeepAI);

BOOST_AUTO_TEST_CASE(DeepAI_alphabeta){
    shared_ptr<State> state = make_shared<State>(42,"../../../res/cardsData/");
    shared_ptr<Node> root = make_shared<Node>(state,5);
    cout << DeepAI::alphabeta(root,true,INT32_MIN,INT32_MAX,5);
    BOOST_TEST(1);
}

BOOST_AUTO_TEST_SUITE_END();
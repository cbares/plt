#include <gtest/gtest.h>

#include "../../src/shared/state/Exemple.h"

using namespace ::state;

TEST(TestExemple,TestExemple) {
    
    {
        Exemple ex {};
        EXPECT_EQ(ex.x, 0);
        ex.setX(21);
        EXPECT_EQ(ex.x, 21);
    }
    {
        Exemple ex {};
        ex.setX(21);
        EXPECT_LE(ex.x, 32); // Less than equal
        EXPECT_GT(ex.x, 11); // Greater than equl
    }
}
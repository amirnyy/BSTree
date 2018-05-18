#include "catch.hpp"
#include "binarytree.hpp"

TEST_CASE("Creating tree") 
{
    binarytree tree{5,3,6};
    binarytree tree_{};
    REQUIRE(tree.return_root() != nullptr);
    REQUIRE(tree_.return_root() == nullptr);
}

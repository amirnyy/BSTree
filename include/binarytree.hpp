//
//  binarytree.hpp
//  Binarytree
//
//  Created by Алексей Мирный on 11.04.2018.
//  Copyright © 2018 alexey. All rights reserved.
//

#ifndef binarytree_hpp
#define binarytree_hpp
#include <iostream>
struct BinaryNode
{
    int data;
    BinaryNode* r;
    BinaryNode* l;
    BinaryNode(int val,BinaryNode* left, BinaryNode* right)
    {
        data = val;
        l=left;
        r=right;
    }
};
enum class traversal_order {pre, in, post};
class binarytree
{
    BinaryNode* root;
    auto clean(BinaryNode * &) ->void;
    auto print_elements(BinaryNode * root,int space) const ->void;
    auto direct_print(BinaryNode * root) const ->void;
    auto symmetric_print(BinaryNode * root) const ->void;
    auto reverse_print(BinaryNode * root) const ->void;
public:
    binarytree();
    binarytree(std::initializer_list<int> list);
    binarytree(const binarytree& tree);
    auto operator=(const binarytree& tree) -> binarytree&;
    auto print_order(std::ostream& stream, traversal_order order) const -> std::ostream&;
    auto print() const -> void;
    auto return_root() -> BinaryNode *;
    auto insert(int value) -> bool;
    auto save(const std::string& path) -> bool;
    auto load(const std::string& path) -> bool;
    auto remove(int value)-> bool;
    auto search(int value) const -> bool;
    auto swap(binarytree& tree) -> void;
    auto friend operator<<(std::ostream& stream, const binarytree& tree) -> std::ostream&
    {
        return tree.print_order(stream, traversal_order::pre);
    }
    ~binarytree();
};

#endif /* binarytree_hpp */

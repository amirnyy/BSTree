//
//  binarytree.cpp
//  Binarytree
//
//  Created by Алексей Мирный on 11.04.2018.
//  Copyright © 2018 alexey. All rights reserved.
//

#include "binarytree.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
binarytree::binarytree()
{
    root = nullptr;
}

auto binarytree::clean(BinaryNode*& curr) -> void
{
    //обратный порядок удаления
    if (curr == nullptr)
        return;
    clean(curr->l);
    clean(curr->r);
    delete curr; // delete только освобождает память, а указатели остаются не тронутыми
    curr = nullptr;
}
auto binarytree::direct_print(BinaryNode* curr) const -> void
{
    if (curr == nullptr)
    {
        //std::cout << "Дерево пустое!" << std::endl;
        return;
    }
    std::cout << curr->data;
    direct_print(curr->l);
    direct_print(curr->r);
}
auto binarytree::symmetric_print(BinaryNode* curr) const -> void
{
            if (curr == nullptr)
            {
                //std::cout << "Дерево пустое!" << std::endl;
                return;
            }
            symmetric_print(curr->l);
            std::cout << curr->data;
            symmetric_print(curr->r);
}
auto binarytree::reverse_print(BinaryNode* curr) const -> void
{
            if (curr == nullptr)
            {
                //std::cout << "Дерево пустое!" << std::endl;
                return;
            }
            direct_print(curr->l);
            direct_print(curr->r);
            std::cout << curr->data;
}
auto binarytree::print_elements(BinaryNode* curr, int place) const -> void
{
            if (curr != nullptr)
            {
                if (curr->r != nullptr)
                    print_elements(curr->r, place + 1);
                for (int i = 0; i < place; i++)
                {
                    std::cout << "   ";
                }
                if ((curr->data) != (root->data))
                    std::cout << "--";
                std::cout << curr->data << std::endl;
                if (curr->l != nullptr)
                    print_elements(curr->l, place + 1);
            }
            else
                std::cout << "Дерево пустое!" << std::endl;
}
auto binarytree::print() const -> void
{
    print_elements(root, 0);
}
auto binarytree::return_root() -> BinaryNode *
{
  return (root);
}
auto binarytree::insert(int value) -> bool
        {
            if (root == nullptr)
            {
                root = new BinaryNode{ value, nullptr, nullptr };
                return true;
            }
            BinaryNode* current = root;
            while (true)
            {
                if (value > (current->data) && current->r != nullptr)
                {
                    current = current->r;
                    continue;
                }
                else
                {
                    if (value > (current->data) && ((current->r) == nullptr))
                    {
                        current->r = new BinaryNode{ value, nullptr, nullptr };
                        return true;
                    }
                }
                if (value < (current->data) && current->l != nullptr)
                {
                    current = current->l;
                    continue;
                }
                else
                {
                    if (value < (current->data) && ((current->l) == nullptr))
                    {
                        current->l = new BinaryNode{ value, nullptr, nullptr };
                        return true;
                    }
                }
            }
        }
binarytree::~binarytree()
        {
            clean(root);
        }
auto binarytree::print_order(std::ostream& out, traversal_order order) const  -> std::ostream& {
        if(order == traversal_order::pre) {
            direct_print(root);
        } else if (order == traversal_order::in) {
            symmetric_print(root);
        } else {
            reverse_print(root);
        }
        return out;
    }
binarytree::binarytree(std::initializer_list<int> list)
    {
        root = nullptr;
        for (auto x: list )
        {
            this->insert(x);
        }
    }
binarytree::binarytree(const binarytree& tree) : binarytree{}
    {
        std::string str;
        std::stringstream out(str);
        out << tree;
        int value;
        while(out)
        {
            out >> value;
            this->insert(value);
        }
    }
auto binarytree::swap(binarytree& tree) -> void
    {
        std::swap(root, tree.root);
    }
auto binarytree::operator=(const binarytree &tree) -> binarytree&
    {
        clean(root);
         binarytree tmp{tree};
        this->swap(tmp);
        return *this;
    }
auto binarytree::search(int value) const -> bool
    {
        if(root == nullptr)
            return false;
        BinaryNode* curr = root;
        while (curr->data != value) {
            if(curr->data > value)
                curr = curr -> l;
            else
                curr = curr -> r;
            if(curr == nullptr)
                return false;
        }
        return true;
    }
auto binarytree::remove(int value) -> bool
    {
        if(!search(value))
            return false;
        BinaryNode* curr = root;
        BinaryNode* parent  = nullptr;
        while( curr->data != value) {
            parent = curr;
            if(value < curr->data)
                curr = curr->l;
            else
                curr = curr->r;
        }
        BinaryNode* removed = nullptr;
        if (curr->l == nullptr || curr->r == nullptr) {
            BinaryNode* child = nullptr;
            removed = curr;
            if(curr->l != nullptr)
                child = curr->l;
            else if(curr->r != nullptr)
                child = curr->r;
            if(parent == nullptr)
                root = child;
            else {
                if(parent->l == curr)
                    parent->l = child;
                else
                    parent->r = child;
            }
        } else {
            BinaryNode* mostLeft = curr->r;
            BinaryNode* mostLeftParent = curr;
            while (mostLeft->l != nullptr) {
                mostLeftParent = mostLeft;
                mostLeft = mostLeft->l;
            }
            curr->data = mostLeft->data;
            removed = mostLeft;
            if(mostLeftParent->l == mostLeft)
                mostLeftParent->l = nullptr;
            else
                mostLeftParent->r = mostLeft->r;
        }
        delete removed;
        removed = nullptr;
        return true;
    }
auto binarytree::save(const std::string& filename) -> bool {
        std::ifstream fin(filename.c_str());
        if (!fin.is_open()) {
            std::ofstream fout(filename.c_str());
            fout << *this;
            fout.close();
            return true;
        } else {
            std::string answer;
            std::cout << "Перезаписать файл? (y, n)" << std::endl;
            std::cin >> answer;
            if ((answer == "Yes") || (answer == "y") || (answer == "Y") || (answer == "YES") || (answer == "yes"))
            {
                std::ofstream fout(filename.c_str());
                fout << *this;
                fout.close();
                return true;
            }
            else
                return false;
        }
    }
auto binarytree::load(const std::string& filename) -> bool{
        std::ifstream fin(filename.c_str());
        if (!fin.is_open())
            return false;
        clean(root);
        int value;
        fin >> value;
        if(!fin)
            return false;
        while(fin)
        {
            this->insert(value);
            fin >> value;
        }
        return true;
    }


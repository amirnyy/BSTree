//
//  main.cpp
//  Binarytree
//
//  Created by Алексей Мирный on 11.04.2018.
//  Copyright © 2018 alexey. All rights reserved.
//
#include "binarytree.hpp"
#include <iostream>
#include <string>

int main(int argc, char * argv[]) {
    size_t z;
    binarytree tree;
    for (int i = 1; i < argc; i++)
    {
        tree.insert(atoi(argv[i]));
    }
    while(1)
    {
        std::cout << "1. Вывести дерево на экран\n";
        std::cout << "2. Вывести список узлов дерева\n";
        std::cout << "3. Добавить узел в дерево\n";
        std::cout << "4. Удалить узел из дерева\n";
        std::cout << "5. Сохранить дерево в файл\n";
        std::cout << "6. Загрузить дерево из файла\n";
        std::cout << "7. Проверить наличие узла\n";
        std::cout << "8. Завершить работу программы\n";
        std::cin >> z;
        switch(z)
        {
            case 1:
            {
                tree.print();
                break;
            }
            case 2:
            {
                std::cout <<"a. Прямой обход\n";
                std::cout <<"b. Симметричный обход\n";
                std::cout <<"c. Обратный обход\n";
                char a;
                std::cin >> a;
                switch(a)
                {
                    case 'a':
                    {
                        if(tree.return_root() == nullptr)
                        {
                            std::cout << "Дерево пустое!" << std::endl;
                            break;
                        }
                        tree.print_order(std::cout, traversal_order::pre);
                        std::cout << std::endl;
                        break;
                    }
                    case 'b':
                    {
                        if(tree.return_root() == nullptr)
                        {
                            std::cout << "Дерево пустое!" << std::endl;
                            break;
                        }
                        tree.print_order(std::cout, traversal_order::in);
                        std::cout << std::endl;
                        break;
                    }
                    case 'c':
                    {
                        if(tree.return_root() == nullptr)
                        {
                            std::cout<<"Дерево пустое!"<<std::endl;
                            break;
                        }
                        tree.print_order(std::cout, traversal_order::post);
                        std::cout << std::endl;
                        break;
                    }
                    default:
                    {
                        std::cout << "Нет такой команды, либо введена не буква!\n";
                        break;
                    }
                }
                break;
                
            }
            case 3:
            {
                int val;
                std::cout << "Введите значение для нового узла: ";
                std::cin >> val;
                std::cout << std::endl;
                if (!tree.search(val))
                    tree.insert(val);
                else
                    std:: cout << "Узел уже существует в дереве";
                break;
            }
            case 4:
            {
                int val;
                std::cout << "Введите значение для удаления узла: ";
                std::cin >> val;
                std::cout << std::endl;
                if (!tree.remove(val))
                    std::cout << "Узел не был найден в дереве" << std::endl;
                break;
            }
            case 5:
            {
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;
                std::cout << std::endl;
                if (tree.save(filename))
                    std::cout << "Дерево было успешно сохранено\n";
                break;
            }
            case 6:
            {
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;
                std::cout << std::endl;
                if (tree.load(filename))
                    std::cout << "Дерево было успешно загружено\n";
                else
                    std::cout << "Файл с указанным именем не существует\n";
                break;
            }
            case 7:
            {
                int val;
                std::cout << "Введите значение узла: ";
                std::cin >> val;
                std::cout << std::endl;
                if (tree.search(val))
                    std::cout << "Узел найден\n";
                else
                    std::cout << "Узел не найден\n";
                break;
            }
            case 8:
            {
                std::string y;
                std::cout << "Вы хотите выйти из программы? (y/N) \n";
                std::cin >> y;
                if ((y == "y") || (y == "Y") || (y == "yes") || (y == "Yes") || (y == "YES"))
                {
                    std::cout << "До свидания!\n";
                    exit(0);
                }
                if ((y == "n") || (y == "N") || (y == "no") || (y == "No") || (y == "NO"))
                    break;
            }
            default:
            {
                std::cout << "Нет такой команды, либо введено не число!\n";
                break;
            }
        }
    }
    return 0;
}

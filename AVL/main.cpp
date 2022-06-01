#include <iostream>
#include "AVL.h"

int AVL::data_root = 0;

int main() {
    AVL b, * root = NULL;
    root = b.Insert(root, 50);
    b.set_root(root->get_data());
    b.Insert(root, 70);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 15);
    b.Insert(root, 10);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);
    std::cout << "\n";
    

    if (b.Search(root, 100))
        std::cout << "exista\n";
    else
        std::cout << "nu exista\n";

    b.DeleteNode(root, 80);

    b.Inorder(root);
    std::cout << "\n";
}

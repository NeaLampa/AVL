#include <iostream>
#include <algorithm>
#include "AVL.h"

void AVL::set_root(int x) {
    this->data_root = x;
}
int AVL::get_data() {
    return this->data;
}
int AVL::get_height() {
    if (this == nullptr) {
        return 0;
    }
    return this->height;
}
AVL::AVL() {
    this->data = 0;
    this->height = 0;
    this->left = this->right = nullptr;
}
AVL::AVL(int x) {
    this->height = 1;
    this->data = x;
    this->left = this->right = nullptr;
}
AVL* AVL::Insert(AVL* root, int x) {
    if (!root) {
        return new AVL(x);
    }
    if (x > root->data) {
        root->right = Insert(root->right, x);
    }
    else if(x < root->data) {
        root->left = Insert(root->left, x);
    }
    else
        return root;
    
    root->height = 1 + std::max(root->left->get_height(), root->right->get_height());
    int balance = 0;
    if (root != nullptr) {
        if (root->left != nullptr && root->right != nullptr) {
            balance = (root->left->height - root->right->height);
        }
        if (root->left == nullptr && root->right != nullptr) {
            balance = (1 - root->right->height);
        }
        if (root->left != nullptr && root->right == nullptr) {
            balance = (root->left->height - 0);
        }
    }

    // Left Left
    if (balance > 1 && x < root->left->data) {
        return rightRotate(root);
    }
        

    // Right Right
    if (balance < -1 && x > root->right->data) {
        return leftRotate(root);
    }
        

    // Left Right
    if (balance > 1 && x > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && x < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void AVL::Inorder(AVL* root) {
    if (!root) {
        return;
    }
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
}
bool AVL::Search(AVL* root, int x) {
    if (!root)
        return false;
    if (root->data == x)
        return true;
    if (root->data > x)
        return Search(root->left, x);
    if (root->data < x)
        return Search(root->right, x);
    return false;
}
AVL* AVL::minValueNode(AVL* root) {
    AVL* temp = root;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}
AVL* AVL::DeleteNode(AVL* root, int key) {
    if (root == NULL)
        return root;
    //daca e mai mic atunci e in stanga
    if (key < root->data)
        root->left = DeleteNode(root->left, key);
    //daca e mai mare e in dreapta
    else if (key > root->data)
        root->right = DeleteNode(root->right, key);
    //daca e egal atunci trebe sters
    else {
        if (root->left == nullptr || root->right == nullptr) {
            AVL* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            AVL* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;

    root->height = 1 + std::max(root->left->get_height(), root->right->get_height());
    int balance = 0;
    if (root != nullptr) {
        if (root->left != nullptr && root->right != nullptr) {
            balance = (root->left->height - root->right->height);
        }
        if (root->left == nullptr && root->right != nullptr) {
            balance = (1 - root->right->height);
        }
        if (root->left != nullptr && root->right == nullptr) {
            balance = (root->left->height - 0);
        }
    }

    // Left Left
    if (balance > 1 && key < root->left->data) {
        return rightRotate(root);
    }


    // Right Right
    if (balance < -1 && key > root->right->data) {
        return leftRotate(root);
    }


    // Left Right
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void AVL::Mirror(AVL* root) {
    if (root == NULL)
        return;
    else {
        AVL* temp = NULL;
        Mirror(root->left);
        Mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
bool AVL::isBST(AVL* root) {
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->data > root->data)
        return false;
    if (root->right != NULL && root->right->data < root->data)
        return false;
    if (!isBST(root->left) || !isBST(root->right))
        return false;
    return true;
}
AVL* AVL::leftRotate(AVL* root) {
    if (root->data == root->data_root);
        return root;

    AVL* x = root->right;
    AVL* T2 = x->left;

    x->left = root;
    root->right = T2;

    root->height = std::max(root->left->get_height(), root->right->get_height()) + 1;
    x->height = std::max(x->left->get_height(), x->right->get_height()) + 1;

    return x;
}
AVL* AVL::rightRotate(AVL* root) {
    if (root->data == root->data_root);
        return root;

    AVL* x = root->left;
    AVL* T2 = x->right;

    x->right = root;
    root->left = T2;

    root->height = std::max(root->left->get_height(), root->right->get_height()) + 1;
    x->height = std::max(x->left->get_height(), x->right->get_height()) + 1;

    x->Inorder(x);
    std::cout << "\n";

    return x;
}



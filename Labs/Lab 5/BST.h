#include <iostream>

template<typename T>
class Node {
public:
    Node<T>* left;
    T data;
    Node<T>* right;
};

template<typename T>
class BST {
private:
    Node<T>* root;

    void insertInBST(Node<T>*& root, T value);

    void inorder(Node<T>* root);

    void preorder(Node<T>* root);

    int getHeight(Node<T>* root);

public:
    BST() {
        root = nullptr;
    }

    void insertInBST(T value);

    void inorder();

    void preorder();

    int getHeight();

};

template<typename T>
void BST<T>::insertInBST(Node<T>*& root, T value) {
    if(root == nullptr) {
        root = new Node<T>{nullptr, value, nullptr};
    } 

    else if(value <= root->data) {
        insertInBST(root->left, value);
    } 
    
    else if(value > root->data) {
        insertInBST(root->right, value);
    }
}

template<typename T>
void BST<T>::insertInBST(T value) {
    insertInBST(root, value);
}

template<typename T>
void BST<T>::inorder() {
    inorder(root);
}

template<typename T>
void BST<T>::inorder(Node<T>* root) {
    if(root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

template<typename T>
void BST<T>::preorder() {
    preorder(root);
}

template<typename T>
void BST<T>::preorder(Node<T>* root) {
    if(root != nullptr) {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

template<typename T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template<typename T>
int BST<T>::getHeight(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);

    if(lheight > rheight) {
        return lheight + 1;
    }else {
        return rheight + 1;
    }
}


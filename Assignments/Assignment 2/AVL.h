#ifndef AVL_H
#define AVL_H

template<typename T>
class AVL{
    public:
        AVL();

        int height();

        void insert(const T &value);

        void deleteRoot(const T &value);

        void preorder();

        void inOrder();

        void deletingAVL();

    private:
        struct Node{
                Node* left;
                T data;
                Node* right;

                int height;
            };
        
        Node* root;
    

        Node* insert(Node* root, const T &value);

        int balanceFactor(Node* root);

        Node* rotatingLeft(Node* root);

        Node* rotatingRight(Node* root);

        int newHeight(Node* root);

        void preorder(Node* root);

        void inOrder(Node* root);

        Node* inorderSucc(Node* root);

        Node* deleting(const T &value);

        Node* deleting(Node* root, const T &value);

        void deletingAVL(Node* root);

};

template<typename T>
AVL<T>::AVL() {
    root = nullptr;
}

template<typename T>
void AVL<T>::insert(const T &value) {
    root = insert(root, value);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::insert(Node* root, const T &value) {
    if(root == nullptr) {
        return new Node{nullptr, value, nullptr};
    }
    if(value <= root->data) {
        root->left = insert(root->left, value);
    }
    if(value > root->data) {
        root->right = insert(root->right, value);
    }
    int l = newHeight(root);

    int balance = balanceFactor(root); 

    if (balance > 1 && value < root->left->data) 
        return rotatingRight(root); 

    if (balance < -1 && value > root->right->data) 
        return rotatingLeft(root); 

    if (balance > 1 && value > root->left->data) {
        root->left = rotatingLeft(root->left); 
        return rotatingRight(root);
    } 

    if (balance < -1 && value < root->right->data) { 
        root->right = rotatingRight(root->right); 
        return rotatingLeft(root); 
    } 

    return root;
    
}

template<typename T>
typename AVL<T>::Node* AVL<T>::rotatingRight(Node* root) {
    Node* r = root->left;
    Node* left = root->right;

    r->right = root;
    root->left = left;

    int l = newHeight(root);
    int rL = newHeight(r);

    return r;

}

template<typename T>
typename AVL<T>::Node* AVL<T>::rotatingLeft(Node* root) {
    Node* r = root->right;
    Node* right = r->left;

    r->left = root;
    root->right = right;

    int l = newHeight(root);
    int rL = newHeight(r);

    return r;
}

template<typename T>
int AVL<T>::balanceFactor(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

template<typename T>
int AVL<T>::height() {
    return newHeight(root);
}

template<typename T>
int AVL<T>::newHeight(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        root->height = 1;
        return root->height;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight > rheight) {
        root->height = lheight + 1;
    }else {
        root->height = rheight + 1;
    }

    return root->height;
}

template<typename T>
void AVL<T>::preorder() {
    preorder(root);
}

template<typename T>
void AVL<T>::preorder(Node* root) {
    if(root != nullptr) {
        preorder(root->left);
        std::cout << root->data << " ";
        preorder(root->right);
    }
}

template<typename T>
void AVL<T>::inOrder() {
    inOrder(root);
}

template<typename T>
void AVL<T>::inOrder(Node* root) {
    if(root != nullptr) {
        std::cout << root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}


template<typename T>
typename AVL<T>::Node* AVL<T>::inorderSucc(Node* root) {
    Node* temp = root;
    while(temp != nullptr && temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

template<typename T>
void AVL<T>::deleteRoot(const T& value) {
    root = deleting(value);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::deleting(const T& value) {
    root = deleting(root, value);

    int l = newHeight(root);

    int balance = balanceFactor(root); 

    if (balance > 1 && value < root->left->data) 
        return rotatingRight(root); 

    if (balance < -1 && value > root->right->data) 
        return rotatingLeft(root); 

    if (balance > 1 && value > root->left->data) {
        root->left = rotatingLeft(root->left); 
        return rotatingRight(root);
    } 

    if (balance < -1 && value < root->right->data) { 
        root->right = rotatingRight(root->right); 
        return rotatingLeft(root); 
    } 

    return root;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::deleting(Node* root, const T& value) {
    if(value < root->data) {
        root->left = deleting(root->left, value);
    }
    else if(value > root->data) {
        root->right = deleting(root->right, value);
    }
    else{
        if(root->left == nullptr) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleting(root->right, temp->data);
        }
    }
    return root;
}

template<typename T>
void AVL<T>::deletingAVL() {
    deletingAVL(root);
}

template<typename T>
void AVL<T>::deletingAVL(Node* root) {
    if(root == nullptr) {
        return;
    }
    deletingAVL(root->left);
    deletingAVL(root->right);
    delete root;
}



#endif


#include <iostream>
#include <fstream>
#include <ctime>
#include "AVL.H"

using namespace std;

int getInput() {
    cout << "Enter non-negative number: ";
    int num;
    cin >> num;
    return num;
}

void genInputFile(int n, string filename) {
    std::srand(time(0));
    ofstream f(filename);

    f << n << std::endl;

    for(int i = 0; i < n; i++) {
        int random = 1000 + rand() % 4000;
        f << random << std::endl;
    }
    f.close();
}

AVL<int> BuildAVLTree(string filename) {
    ifstream f(filename);

    int n;
    f >> n;

    AVL<int> avl;
    for(int i = 0; i < n; i++) {
        int number;
        f >> number;
        avl.insert(number);
    }
    f.close();

    return avl;

}

void InsertNodeAVL(AVL<int>& avl, int& node) {
    avl.insert(node);
}

void printAVL(AVL<int> avl){
    cout << "Preorder: ";
    avl.preorder();
    cout << endl;

    cout << "Inorder: ";
    avl.inOrder();
    cout << endl;
}


void DeleteNodeAVL(AVL<int> avl, int node) {
    avl.deleteRoot(node);
}

void DeleteAVLTree(AVL<int> avl) {
    avl.deletingAVL();
}


int main() {
    int n;
    n = getInput();

    string filename = "input.txt";
    genInputFile(n, filename);

    AVL<int> avl;
    avl = BuildAVLTree(filename);

    cout << "height of AVL tree is: " << avl.height() << endl;
    printAVL(avl);

    int node;
    cout << "Enter a value to insert: ";
    cin >> node;
    InsertNodeAVL(avl, node);

    cout << "height of AVL tree is: " << avl.height() << endl;
    printAVL(avl);
    

    cout << "Enter a value to delete: ";
    cin >> node;
    DeleteNodeAVL(avl, node);
    cout << "height of AVL tree is: " << avl.height() << endl;
    printAVL(avl);

    DeleteAVLTree(avl);
    printAVL(avl);

    return 0;
}
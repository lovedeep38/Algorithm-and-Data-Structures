#include <iostream>
#include <ctime>
#include <vector>
#include "BST.h"

using namespace std;

int getInput() {
    return rand()%10 + 1;           //getting size from 1 to 10
}

vector<int> genData(int n1) {
    vector<int> v(n1);
    for(int i = 0; i < n1; i++) {
        v[i] = rand()%n1*2 - n1;          //value from -n or n
    }

    return v;


}

void printList(vector<int> list1) {
    for(int i = 0; i < list1.size(); i++) {
        cout << list1[i] << " ";
    }
    
}

BST<int> makeBST(vector<int> list1) {
    BST<int> bst1;
    for(int i = 0; i < list1.size(); i++) {
        int val = list1[i];
        bst1.insertInBST(val);
    }

    return bst1;
}

void printBST(BST<int> bst1) {
    cout << "Inorder traversal : ";
    bst1.inorder();
    cout << endl;
    cout << "Preorder traversal: ";
    bst1.preorder();
    cout << endl;
}

int height(BST<int> bst1) {
    return bst1.getHeight();
}

int main() {
    srand(time(0));
    int n1;
    n1 = getInput();
    
    vector<int> list1(n1);
    list1 = genData(n1);

    cout << "The List: ";
    printList(list1);
    cout << endl;

    BST<int> bst1;
    bst1 = makeBST(list1);

    printBST(bst1);

    cout << "The height of bst1 is " << height(bst1) << endl;

    return 0;
}
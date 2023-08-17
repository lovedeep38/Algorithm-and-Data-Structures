#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node{
    char data;
    int frequency;
    Node* left;
    Node* right;
};

Node* makeHuffmanTree(string x) {
    map<char, int> frequency;
    for(int i = 0; i < x.length(); i++) {
        frequency[x[i]]++;
    }

    priority_queue<Node, vector<Node*>> p;

    for (const auto& i : frequency) {
        Node* node = new Node{i.first, i.second, nullptr, nullptr};
        p.push(node);
    }

    while (p.size() > 1) {
        Node* left = p.top();
        p.pop();
        Node* right = p.top();
        p.pop();

        Node* newNode = new Node{' ', left->frequency + right->frequency, nullptr, nullptr};
        newNode->left = left;
        newNode->right = right;

        p.push(newNode);
    }

    return p.top();
}

void print(const Node* root, string x = "") {
    if(root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            std::cout << root->data << ": " << x << endl;
        }

        print(root->left, x + "0");
        print(root->right, x + "1");

    }
}

int main() {
    std::cout << "Write a message: ";
    string x;
    cin >> x;
    Node* root = makeHuffmanTree(x);
    
    std::cout << "Here are codes for each word: " << endl;
    print(root);


    return 0;
}

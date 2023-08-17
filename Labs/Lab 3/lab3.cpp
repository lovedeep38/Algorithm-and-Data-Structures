#include <iostream>

using namespace std;

int numPathsFromHome(int street, int avenue) {
    if(street == 0 && avenue == 0) {
        return 1;
    }

    if(street < 0 || avenue < 0) {
        return 0;
    }
    int paths = 0;

    if(street >= 0 || avenue >= 0) {
        paths = numPathsFromHome(street-1, avenue) + numPathsFromHome(street, avenue-1);
    }

    return paths;
}

bool hasSubsequence(const char T[],  const char S[]) {
    if(S[0] == '\0') {
        return true;
    }

    if(T[0] == '\0') {
        return false;
    }

    if(T[0] == S[0]) {
        return hasSubsequence(T + 1, S + 1);
    }
    return hasSubsequence(T + 1, S);
}

int main() {
    //Part 1
    cout << "Street is 1 and avenue is 2, total paths are: " << numPathsFromHome(1, 2) << endl;
    cout << "Street is 1 and avenue is 1, total paths are: " << numPathsFromHome(1, 1) << endl;
    cout << "Street is 0 and avenue is 5, total paths are: " << numPathsFromHome(0, 5) << endl;
    cout << "Street is 3 and avenue is 0, total paths are: " << numPathsFromHome(3, 0) << endl;
    cout << "Street is 5 and avenue is 5, total paths are: " << numPathsFromHome(5, 5) << endl;

    cout << endl;
    //Part 2
    char* T = new char[10];
    T[0] = '\0';

    char* S = new char[3];
    S[0] = 'p';
    S[1] = 'i';
    S[2] = 'n';

    //if T is empty, its false
    if(hasSubsequence(T, S)) {
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    
    T[0] = 'P';
    T[1] = 'r';
    T[2] = 'o';
    T[3] = 'g';
    T[4] = 'r';
    T[5] = 'a';
    T[6] = 'm';
    T[7] = 'i';
    T[8] = 'n';
    T[9] = 'g';

    //if letter in T is Uppercase and S is lowercase, it must be false
    if(hasSubsequence(T, S)) {
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    S[0] = '\0';
    //if S is empty and T is not empty, it is true
    if(hasSubsequence(T, S)) {
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    
    S[0] = 'P';
    S[1] = 'i';
    S[2] = 'n';
    //if S is subsequence of T, its true
    if(hasSubsequence(T, S)) {
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    delete[] S;
    delete[] T;


    return 0;
}
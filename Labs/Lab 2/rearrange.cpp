#include <iostream>

using namespace std;

void swap(string & colour1, string & colour2){
    string tmp = colour1;
    colour1 = colour2;
    colour2 = tmp;
}

void rearranging(string* keys, int size) {
    int IndexForRed = 0;
    int index = size-1;
    int IndexForWhite = size-1;

    while(IndexForRed <= index) {
        if(keys[index] == "red") {
            swap(keys[index], keys[IndexForRed]);
            IndexForRed++;
        }
        else if(keys[index] == "blue") {
            index--;
        }
        else if(keys[index] == "white") {
            swap(keys[index], keys[IndexForWhite]);
            index--;
            IndexForWhite--;
        }
    }
}

int main() {
    int size = 7;
    string* keys = new string[size];
    keys[0] = "white";
    keys[1] = "red";
    keys[2] = "white";
    keys[3] = "blue";
    keys[4] = "blue";
    keys[5] = "red";
    keys[6] = "white";

    rearranging(keys, size);

    for(int i = 0; i < size; i++) {
        cout << keys[i] << " " << endl;
    }

    delete[] keys;

    return 0;
}



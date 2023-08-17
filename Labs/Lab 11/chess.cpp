#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int x;
        int y;
        int d;
    
    Node(int X, int Y, int D) {
        x = X;
        y = Y;
        d = D;
    }

};

bool IsValidMove(int x, int y, int boardSize) {
    if(x >= 0 && y >= 0 && x < boardSize && y < boardSize) {
        return true;
    }
    return false;
}

vector<vector<int>> knightMoves(int currRow, int currCol, int destRow, int destCol) {
    int boardSize = 8;

    int knightRows[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int knightCols[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    vector<vector<int>> v(8, vector<int>(8, 0));

    queue<Node> q;

    bool isVisited[boardSize][boardSize];
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            isVisited[i][j] = false;
        }
    }

    q.push(Node(currRow, currCol, 0));

    isVisited[currRow][currCol] = true;

    while(!q.empty()) {
        Node f = q.front();
        q.pop();

        if(f.x == destRow && f.y == destCol) {
            v[f.x][f.y] = 1;
            break;
        }

        for(int i = 0; i < boardSize; i++) {
            int x = f.x + knightRows[i];
            int y = f.y + knightCols[i];

            if(IsValidMove(x, y, boardSize) && !isVisited[x][y]) {
                isVisited[x][y] = true;
                q.push(Node(x, y, f.d + 1));
                cout << x  << " " << y << endl;
            }
        }
    }

    return v;
}

int main() {
    int currRow, currCol;

    cout << "=> Enter the current Knight's location: ";
    cin >> currRow;
    cin >> currCol;

    int destRow, destCol;
    cout << "=> Enter the destination location: ";
    cin >> destRow;
    cin >> destCol;

    vector<vector<int>> v = knightMoves(currRow, currCol, destRow, destCol);
    

    return 0;
}
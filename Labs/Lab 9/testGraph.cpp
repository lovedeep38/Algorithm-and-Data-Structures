#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Edge{
    int d;
    int weight;

};

class Graph{
    private:
        int e;
        int v;
        vector<Edge> edges;



    public:
        Graph(int n);

        int getN();

        void setE(int ed);

        int getE();

};

Graph::Graph(int n) {
    v = n;
    e = 0;
}

int  Graph::getN() { 
    return v;
}

int Graph::getE() {
    return e;
}

void Graph::setE(int ed) {
    e = ed;
}

vector<vector<Edge>>  makeSparseUDWG(int n) {
    srand(time(0));
    int totalEdges = 2*n;
    Graph g(n);

    vector<vector<Edge>> vec(n);
    int i =0;
    while(i < totalEdges) {
        int s = rand() % n;
        int d = rand() % n;
        int w = rand() % 100 + 1;

        if (s != d) {
            bool b = false;
            for (const auto& edge : vec[s]) {
                if (edge.d == d) {
                    b = true;
                    int e = g.getE();
                    e++;
                    g.setE(e);
                    break;
                }
            }

            if (!b) {
                vec[s].push_back({d, w});
                vec[d].push_back({s, w});
                i++;
            }
        }
    }

    cout << "Sparse Graph"<< endl;
        for(int i = 0; i < n; i++) {
            cout << i << ": " ;
            for (const Edge& e : vec[i]) {
                std::cout << e.d << ", " << e.weight;
            }
            cout<< endl;
        }

    return vec;

}

vector<vector<int>> makeDenseDWG(int n) {
    vector<vector<int>> den(n, vector<int>(n,0));
    if(n > 10) {
        srand(time(0));
        int Edges = ((n-2)*n)/2;

        int m = (rand()%2*n) + Edges;
        Graph g(n);
        int i = 0;
        while (i < Edges) {
            int s = rand() %n;
            int d = rand() %n;
            int w = rand()%100 + 1;

            if (s != d && den[s][d] == 0) {
                den[s][d] = w;
                i++;
            }

            if (i % m == 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i != j && den[i][j] == 0) {
                            den[i][j] = rand()%100 +1;
                            i++;
                        }
                    }
                }
            }
        }

        cout << "Dense Graph"<< endl;
        for(int i = 0; i < n; i++) {
            cout << i << ": " ;
            for(int j = 0; j< n; j++) {
                cout << den[i][j] << ",";
            }
            cout << endl;
        }
    }


    return den;
}

void printGraph(string filename, vector<vector<int>> v, Graph g) {
    ofstream f(filename);

    if(f.is_open()) {
        f << g.getN() << endl;
        for(int i = 0; i < g.getE(); i++) {
            f << i;
            for(int j = 0; j< v.size(); j++) {
                f << v[i][j] << ",";
            }
            f << endl;
        }
    }

    f.close();
}

int main() {
    int n = 11;

    Graph g(n);

    vector<vector<Edge>> spa = makeSparseUDWG(n);
    
    vector<vector<int>> den = makeDenseDWG(n);

    printGraph("den.txt", den, g);

    return 0;
}
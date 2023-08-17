#include <iostream>
#include <vector>
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

        void makingSparse(int n);

        void makingDense(int n);

        int getN();

        int getE();

        void printFile(string filename,vector<vector<int>> den, Graph g);



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

void  Graph::makingSparse(int n) {
    srand(time(0));
    int totalEdges = 2*n;

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
                    e++;
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

}

void Graph::makingDense(int n) {
    if(n > 10) {
        srand(time(0));
        int Edges = ((n-2)*n)/2;

        int m = (rand()%2*n) + Edges;
        vector<vector<int>> den(n, vector<int>(n,0));
        Graph g(n);
        int i = 0;
        while (i < Edges) {
            int s = rand() %n;
            int d = rand() %n;
            int w = rand()%100 + 1;

            // Avoid self-loops and duplicate edges
            if (s != d && den[s][d] == 0) {
                den[s][d] = w;
                i++;
            }

            // Check if we need to add more edges between each pair of nodes
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

        printFile("dense.txt", den, g);

    }
}

void Graph::printFile(string filename, vector<vector<int>> v, Graph g) {
    ofstream f(filename);
    cout << "f";

    if(f.is_open()) {
        f << g.getN() << endl;
        for(int i = 0; i < g.getE(); i++) {
            f << i;
            for (const auto& edge : v[i]) {
                f << edge << " ";
            }
            f << endl;
        }
    }

    f.close();
}
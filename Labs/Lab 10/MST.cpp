#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Edge{
    int city1;
    int city2;
    int distance;
};

vector<Edge> sortingInDescending(vector<Edge> edges) {
    for(int i = 0; i < edges.size(); i++) {
        int d1 = edges[i].distance;

        for(int j = 0; j < edges.size(); j++) {
            if(d1 > edges[j].distance) {
                Edge tmp = edges[j];
                edges[j] = edges[i];
                edges[i] = tmp;
            }
        }
    }
    return edges;
}

int findParent(int v, int* parent) {
    if(parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}

void reverseKruskal(int nodes, vector<Edge> edges) {
    edges = sortingInDescending(edges);

    vector<Edge> spanningTree;
    int *parent = new int[nodes];
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
    }

    int i = edges.size()-1;

    cout << "Removed Edges: " << endl;
    while(i >= 0) {
        Edge current = edges[i];

        int city1Parent = findParent(current.city1, parent);
        int city2Parent = findParent(current.city2, parent);

        //this is the removed edges
        if(city1Parent == city2Parent) {
            cout << current.city1 << " " << current.city2 << " " << current.distance << endl;
        }
        //spanning tree
        else{
            spanningTree.push_back(current);

            parent[city1Parent] = city2Parent;
        }
        i--;
    }

    int totalDistance = 0;
    cout << "Minimum spanning Tree: " << endl;
    for(int i = 0; i < spanningTree.size(); i++) {
        cout << spanningTree[i].city1 << " " << spanningTree[i].city2 << " " << spanningTree[i].distance << endl;
        totalDistance += spanningTree[i].distance;
    }

    cout << "Total Distance of Minimum Spanning is " << totalDistance << endl;

}

int main() {
    ifstream file("sparse25.txt");

    int nodes;
    file >> nodes;

    int c1;
    int c2;
    int d;

    vector<Edge> edges;

    while(file >> c1 >> c2 >> d) {
        edges.push_back(Edge{c1, c2, d});    
    
    }

    reverseKruskal(nodes, edges);

    return 0;
}
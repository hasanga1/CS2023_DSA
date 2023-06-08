//
// Created by Hasanga Ranasinghe on 2023-06-08.
//

#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> vertices;
    int size;

    void privateSetMST(Graph* mst, vector<int> visited, vector<bool> flags) {
        int minCost = 999999999;
        int cheapest;
        int selectedVisitedVertex;

        for (int visitedVertex: visited) {
            for (auto neighbour: this->vertices[visitedVertex]) {
                if (!flags[neighbour.first] && neighbour.second < minCost) {
                    cheapest = neighbour.first;
                    minCost = neighbour.second;
                    selectedVisitedVertex = visitedVertex;
                }
            }
        }

        if (minCost != 999999999) {
            mst->addConnection(selectedVisitedVertex, cheapest, minCost);
            visited.push_back(cheapest);
            flags[cheapest] = true;

            privateSetMST(mst, visited, flags);
        }
    }

public:
    Graph(int n) {
        this->size = n;
        vertices = vector<vector<pair<int, int>>>(n);
    }

    void addConnection(int v1, int v2, int weight) {
        vertices[v1].emplace_back(v2, weight);
        vertices[v2].emplace_back(v1, weight);
    }

    void print() {
        cout << "Vertex\t\tNeighbours(weight)" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << "\t\t\t";
            for (auto neighbour: vertices[i]) {
                cout << neighbour.first << "(" << neighbour.second << ")";
                if (neighbour != vertices[i][vertices[i].size() - 1]) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

    Graph* setMST(int vertex) {
        vector<int> visited;
        vector<bool> flags(6, false);

        visited.push_back(vertex);
        flags[vertex] = true;

        Graph *mst = new Graph(6);

        privateSetMST(mst, visited, flags);

        return mst;
    }
};

int main() {
    Graph *graph = new Graph(6);

    graph->addConnection(0, 1, 3);
    graph->addConnection(1, 2, 2);
    graph->addConnection(2, 3, 3);
    graph->addConnection(3, 4, 5);
    graph->addConnection(4, 5, 4);
    graph->addConnection(5, 0, 1);
    graph->addConnection(1, 4, 10);
    graph->addConnection(1, 3, 1);
    graph->addConnection(2, 5, 5);

    Graph *mst = graph->setMST(0);

    mst->print();
}
//
// Created by Hasanga Ranasinghe on 2023-06-08.
//

#include <vector>
#include <iostream>

using namespace std;

void printMST(vector<vector<int>> mst) {
    cout << "Edge\t\tWeight" << endl;
    for (int i = 0; i < mst.size(); i++) {
        for (int j = i + 1; j < mst[0].size(); j++) {
            if (mst[i][j] != 0) {
                cout << i << " - " << j << "\t\t" << mst[i][j] << endl;
            }
        }
    }
}

vector<vector<int>> setMST(vector<vector<int>> adjacencyMatrix, int start) {
    vector<vector<int>> mst(adjacencyMatrix.size(), vector<int> (adjacencyMatrix.size(), 0));

    vector<int> flags(adjacencyMatrix.size(), false);
    vector<int> visited;

    visited.push_back(start);
    flags[start] = true;

    while (visited.size() < adjacencyMatrix.size()) {
        int minCost = 999999999;
        int vertex;
        int neighbour;

        for (int visitedVertex: visited) {
            for (int i = 0; i < adjacencyMatrix.size(); i++) {
                if (adjacencyMatrix[visitedVertex][i] < minCost && adjacencyMatrix[visitedVertex][i] != 0 && !flags[i]) {
                    minCost = adjacencyMatrix[visitedVertex][i];
                    vertex = visitedVertex;
                    neighbour = i;
                }
            }
        }

        if (minCost != 999999999) {
            mst[vertex][neighbour] = minCost;
            mst[neighbour][vertex] = minCost;
            flags[neighbour] = true;
            visited.push_back(neighbour);
        }
    }
    return mst;
}


int main() {
    vector<vector<int>> adjacencyMatrix = {{0, 3, 0, 0, 0, 1},
                                           {3, 0, 2, 1, 10, 0},
                                           {0, 2, 0, 3, 0, 5},
                                           {0, 1, 3, 0, 5, 0},
                                           {0, 10, 0, 5, 0, 4},
                                           {1, 0, 5, 0, 4, 0}};

    vector<vector<int>> mst = setMST(adjacencyMatrix, 0);

    printMST(mst);
}
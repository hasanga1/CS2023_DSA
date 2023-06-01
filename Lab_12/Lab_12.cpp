#include <iostream>
#include <vector>

using namespace std;

#define INF 999999999

int getCheapest(bool visited[6], vector<int> timeTaken, int n) {
    int cheapest = INF;
    int selectedCity = -1;
    for (int i = 0; i < n; i++) {
        if (timeTaken[i] < cheapest && !visited[i]) {
            cheapest = timeTaken[i];
            selectedCity = i;
        }
    }
    return selectedCity;
}

vector<int> dijkstra(int map[6][6], int n, int s) {
    bool visited[6] = {false, false, false, false, false, false};
    vector<int> timeTaken = {INF, INF, INF, INF, INF, INF};

    timeTaken[s] = 0;

    for (int i = 0; i < n; i++) {
        int cheapest = getCheapest(visited, timeTaken, n);

        visited[cheapest] = true;

        for (int j = 0; j < n; j++) {
            if (map[cheapest][j] != INF && timeTaken[j] > map[cheapest][j] + timeTaken[cheapest]) {
                timeTaken[j] = map[cheapest][j] + timeTaken[cheapest];
            }
        }
    }

    return timeTaken;
}

int main() {

    int map[6][6] = {{0, 10, INF, INF, 15, 5},
                     {10, 0, 10, 30, INF, INF},
                     {INF, 10, 0, 12, 5, INF},
                     {INF, 30, 12, 0, INF, 20},
                     {15, INF, 5, INF, 0, INF},
                     {5, INF, INF, 20, INF, 0}};

    double minAvg = INF;
    vector<int> idealCities;

    for (int i = 0; i < 6; i++) {
        vector<int> timeTaken = dijkstra(map, 6, i);
        double avg = 0;

        cout << "Time Taken from city " << i << "\n" << endl;
        cout << "City\t\tTime taken" << endl;
        for (int j = 0; j < 6; j++) {
            if (i != j) {
                cout << j << "\t\t\t" << timeTaken[j] << endl;
                avg += timeTaken[j];
            }
        }
        avg = avg / 5;

        if (avg < minAvg) {
            minAvg = avg;
            idealCities.clear();
            idealCities.push_back(i);
        }

        else if (avg == minAvg) {
            idealCities.push_back(i);
        }

        cout << "Average time: " << avg <<  "\n" << endl;
        cout << "--------------------------------------" << endl;
    }

    string str = "Therefore the ideal city is ";
    if (idealCities.size() != 1) {
        str = "Therefore the ideal cities are ";
    }
    cout << str;
    for (int i = 0; i < idealCities.size(); i++) {
        cout << idealCities[i];
        if (i != idealCities.size() - 1) {
            cout << ", ";
        }
        else {
            cout << "." << endl;
        }
    }


    return 0;
}

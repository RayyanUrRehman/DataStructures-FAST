#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Pair {
    T first;
    T second;
};

template <typename T>
using Matrix = vector<vector<T>>;

Matrix<int> GetAdjacencyList(const int V, const vector<Pair<int>>& edges) {
    Matrix<int> list(V);
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        list[u].push_back(v);
        list[v].push_back(u);
    }

    return list;
}

int main() {
    int V = 5;
    vector<Pair<int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3},
                                {1, 3}, {1, 2}, {3, 2}};

    auto list = GetAdjacencyList(V, edges);

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " is connected to:";
        if (list[i].empty()) {
            cout << " None";
        } else {
            for (const auto& neighbor : list[i]) {
                cout << " " << neighbor;
            }
        }
        cout << endl;
    }

    return 0;
}
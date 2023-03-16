#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int k;

void dfs(vector<set<int>> &graph, bool *visited, int now, vector<int> &comp) {
    visited[now] = true;
    comp.push_back(now);
    k++;
    for (auto el : graph[now]) {
        if (!visited[el]) dfs(graph, visited, el, comp);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adjList(n + 1);
    vector<int> comp;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == y) continue;
        adjList[x].insert(y);
        adjList[y].insert(x);
    }
    bool visited[n + 1];
    fill_n(visited, n + 1, false);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adjList, visited, i, comp);
            count++;
        }
    }
    cout << count << endl;
    fill_n(visited, n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp.clear();
            k = 0;
            dfs(adjList, visited, i, comp);
            cout << k << endl;
            sort(comp.begin(), comp.end());
            for (auto el : comp) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
}

/*
 Дан неориентированный невзвешенный граф, состоящий из N вершин и M ребер. Необходимо посчитать количество его компонент
 связности и вывести их.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int k;

void dfs(vector<set<int>> &graph, bool *visited, int now) {
    visited[now] = true;
    k++;
    for (auto el : graph[now]) {
        if (!visited[el]) dfs(graph, visited, el);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adjList(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == y) continue;
        adjList[x].insert(y);
        adjList[y].insert(x);
    }
    bool visited[n + 1];
    fill_n(visited, n + 1, false);
    dfs(adjList, visited, 1);
    cout << k << endl;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cout << i << " ";
    }
}

/*
 Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую
 первую вершину.
 */

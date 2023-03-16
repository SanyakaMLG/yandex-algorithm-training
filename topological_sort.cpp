#include <iostream>
#include <vector>

using namespace std;

bool correct = true;

void dfs(vector<vector<int>> &graph, int *visited, int now, vector<int> &ans) {
    visited[now] = 1;
    for (auto el : graph[now]) {
        if (visited[el] == 1) correct = false;
        if (visited[el] == 0) dfs(graph, visited, el, ans);
    }
    visited[now] = 2;
    ans.push_back(now);
}

vector<int> topological_sort(vector<vector<int>> &graph) {
    int visited[graph.size()];
    fill_n(visited, graph.size(), 0);
    vector<int> ans;
    for (int i = 1; i < graph.size(); i++) {
        if (!visited[i]) dfs(graph, visited, i, ans);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adjList[x].push_back(y);
    }
    vector<int> ans = topological_sort(adjList);
    if (!correct) {
        cout << -1;
        return 0;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
 Дан ориентированный граф. Необходимо построить топологическую сортировку.
 */
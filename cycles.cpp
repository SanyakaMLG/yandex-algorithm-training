#include <iostream>
#include <vector>
#include <set>

using namespace std;

int c_start = -1;
int c_end = -1;

bool dfs(vector<vector<int>> &graph, bool *visited, int now, int *prev) {
    visited[now] = true;
    for (auto el : graph[now]) {
        if (visited[el] && el != prev[now]) {
            c_start = el;
            c_end = now;
            return true;
        }
        if (!visited[el]) {
            prev[el] = now;
            if (dfs(graph, visited, el, prev)) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjList(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x) adjList[i].push_back(j);
        }
    }
    bool visited[n + 1];
    int prev[n + 1];
    fill_n(prev, n + 1, -1);
    fill_n(visited, n + 1, false);
    for (int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            if (dfs(adjList, visited, i, prev)) break;
        }
    }
    if (c_start == -1) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        vector<int> ans;
        for (int v = c_end; v != c_start; v = prev[v]) {
            ans.push_back(v);
        }
        ans.push_back(c_start);
        cout << ans.size() << endl;
        for (int an : ans) {
            cout << an << " ";
        }
    }
}

/*
 Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его.
 */

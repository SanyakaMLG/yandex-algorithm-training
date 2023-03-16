#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int n, int start, vector<int> &dist, vector<int> &prev) {
    queue<int> qu;
    qu.push(start);
    vector<bool> visited(n);
    visited[start] = true;
    dist[start] = 0;
    prev[start] = -1;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            int to = graph[now][i];
            if (!visited[to]) {
                visited[to] = true;
                qu.push(to);
                dist[to] = dist[now] + 1;
                prev[to] = now;
            }
        }
    }
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
    int start, end;
    cin >> start >> end;
    vector<int> dist(n + 1), prev(n + 1);
    fill_n(dist.begin(), n + 1, -1);
    bfs(adjList, n + 1, start, dist, prev);

    if (dist[end] == -1) {
        cout << -1;
        return 0;
    } else {
        cout << dist[end] << endl;
        vector<int> ans;
        for (int v = end; v != -1; v = prev[v]) {
            ans.push_back(v);
        }
        if (ans.size() == 1) return 0;
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }
}

/*
 В неориентированном графе требуется найти минимальный путь между двумя вершинами.
 */
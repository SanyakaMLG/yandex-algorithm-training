#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int n, int start) {
    queue<int> qu;
    qu.push(start);
    vector<bool> visited(n);
    vector<int> d(n), p(n);
    fill_n(d.begin(), n, -1);
    visited[start] = true;
    d[start] = 0;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            int to = graph[now][i];
            if (!visited[to]) {
                visited[to] = true;
                qu.push(to);
                d[to] = d[now] + 1;
                p[to] = now;
            }
        }
    }
    return d;
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
    vector<int> res = bfs(adjList, n + 1, start);
    cout << res[end];
}

/*
 В неориентированном графе требуется найти длину минимального пути между двумя вершинами.
*/
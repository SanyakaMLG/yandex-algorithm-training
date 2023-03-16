#include <iostream>
#include <vector>

using namespace std;

bool correct = true;

void dfs(vector<vector<int>> &graph, int *visited, int now, int color) {
    visited[now] = color;
    for (auto el : graph[now]) {
        if (visited[el] == color) correct = false;
        if (visited[el] == 0) {
            if (color == 1) {
                dfs(graph, visited, el, 2);
            } else {
                dfs(graph, visited, el, 1);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == y) continue;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int visited[n + 1];
    fill_n(visited, n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) dfs(adjList, visited, i, 1);
    }
    if (correct) cout << "YES";
    else cout << "NO";
    return 0;
}

/*
 Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. Сначала он хотел поставить
 им всем двойки, но в тот день профессор был добрым, а потому решил разделить студентов на две группы: списывающих и дающих
 списывать, и поставить двойки только первым.
 У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на
 две группы так, чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.
 */
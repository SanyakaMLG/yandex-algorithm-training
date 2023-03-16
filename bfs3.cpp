#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

void bfs(int **distance, int n, int m, int start_x, int start_y) {
    queue<pair<int, int>> qu;
    qu.push(make_pair(start_x, start_y));
    bool visited[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
            distance[i][j] = -1;
        }
    }
    visited[start_x][start_y] = true;
    distance[start_x][start_y] = 0;
    while (!qu.empty()) {
        auto now = qu.front();
        qu.pop();
        int x = now.first;
        int y = now.second;
        for (int i = 0; i < 8; i++) {
            if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m && !visited[x + dx[i]][y + dy[i]]) {
                visited[x + dx[i]][y + dy[i]] = true;
                qu.push(make_pair(x + dx[i], y + dy[i]));
                distance[x + dx[i]][y + dy[i]] = distance[x][y] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int s, t, q;
    cin >> s >> t >> q;
    int **distance = new int*[n + 1];
    for (int i = 1; i <= n; i++) {
        distance[i] = new int[m + 1];
    }
    bfs(distance, n, m, s, t);

    bool check = true;
    int sum = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (distance[x][y] == -1) check = false;
        sum += distance[x][y];
    }

    if (check) cout << sum;
    else cout << -1;
}

/*
 На клеточном поле, размером NxM (2 ≤ N, M ≤ 250) сидит Q (0 ≤ Q ≤ 10000) блох в различных клетках. "Прием пищи" блохами
 возможен только в кормушке - одна из клеток поля, заранее известная. Блохи перемещаются по полю странным образом, а именно,
 прыжками, совпадающими с ходом обыкновенного шахматного коня. Длина пути каждой блохи до кормушки определяется как количество
 прыжков. Определить минимальное значение суммы длин путей блох до кормушки или, если собраться блохам у кормушки невозможно,
 то сообщить об этом. Сбор невозможен, если хотя бы одна из блох не может попасть к кормушке.
 */

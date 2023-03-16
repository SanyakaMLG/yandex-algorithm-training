#include <iostream>
#include <queue>

using namespace std;

struct triple {
    triple(int x1, int y1, int z1) {
        x = x1;
        y = y1;
        z = z1;
    }

    int x, y, z;
};

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int bfs(char ***arr, int n, int start_x, int start_y, int start_z) {
    queue<triple> qu;
    qu.push(triple(start_x, start_y, start_z));
    int distance[n][n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                distance[i][j][k] = -1;
            }
        }
    }
    distance[start_x][start_y][start_z] = 0;
    while (!qu.empty()) {
        triple now = qu.front();
        qu.pop();
        if (now.x == 0) {
            return distance[now.x][now.y][now.z];
        }
        for (int i = 0; i < 6; i++) {
            if (now.x + dx[i] >= 0 && now.x + dx[i] < n && now.y + dy[i] >= 0 && now.y + dy[i] < n &&
                    now.z + dz[i] >= 0 && now.z + dz[i] < n && arr[now.x + dx[i]][now.y + dy[i]][now.z + dz[i]] == '.' &&
                    distance[now.x + dx[i]][now.y + dy[i]][now.z + dz[i]] == -1) {
                qu.push(triple(now.x + dx[i], now.y + dy[i], now.z + dz[i]));
                distance[now.x + dx[i]][now.y + dy[i]][now.z + dz[i]] = distance[now.x][now.y][now.z] + 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    char ***arr = new char **[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new char*[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = new char[n];
        }
    }
    int s_x, s_y, s_z;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string str;
            cin >> str;
            for (int k = 0; k < n; k++) {
                arr[i][j][k] = str[k];
                if (str[k] == 'S') {
                    s_x = i;
                    s_y = j;
                    s_z = k;
                }
            }
        }
    }
    cout << bfs(arr, n, s_x, s_y, s_z);
}

/*
 Пещера представлена кубом, разбитым на N частей по каждому измерению (то есть на N^3 кубических клеток). Каждая клетка может
 быть или пустой, или полностью заполненной камнем. Исходя из положения спелеолога в пещере, требуется найти, какое минимальное
 количество перемещений по клеткам ему требуется, чтобы выбраться на поверхность. Переходить из клетки в клетку можно, только
 если они обе свободны и имеют общую грань.
 */
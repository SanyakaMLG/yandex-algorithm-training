#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, char> dp[n][m];
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1 && j >= 1) {
                dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first) + arr[i][j];
                if (dp[i][j].first - arr[i][j] == dp[i - 1][j].first) dp[i][j].second = 'D';
                else dp[i][j].second = 'R';
            } else if (i >= 1) {
                dp[i][j].first = dp[i - 1][j].first + arr[i][j];
                dp[i][j].second = 'D';
            } else if (j >= 1) {
                dp[i][j].first = dp[i][j - 1].first + arr[i][j];
                dp[i][j].second = 'R';
            } else {
                dp[i][j].first = arr[i][j];
                dp[i][j].second = 'S';
            }
        }
    }
    cout << dp[n - 1][m - 1].first << endl;

    int i = n - 1, j = m - 1;
    vector<char> ans;
    while (dp[i][j].second != 'S') {
        ans.push_back(dp[i][j].second);
        if (dp[i][j].second == 'R') j--;
        else i--;
    }
    for (i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}

/*
 В левом верхнем углу прямоугольной таблицы размером N×M находится черепашка. В каждой клетке таблицы записано некоторое число.
 Черепашка может перемещаться вправо или вниз, при этом маршрут черепашки заканчивается в правом нижнем углу таблицы.
 Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку). Найдите
 наибольшее возможное значение этой суммы и маршрут, на котором достигается эта сумма.
 */
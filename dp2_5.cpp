#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int k = n, q = m;
    vector<int> ans;
    while(dp[k][q] != 0) {
        if (dp[k - 1][q] == dp[k][q]) {
            k--;
        } else if (dp[k][q - 1] == dp[k][q]) {
            q--;
        } else {
            ans.push_back(arr1[k - 1]);
            k--;
            q--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}

/*
 Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.
 */
#include <iostream>
#include <vector>

int min(const int &a, const int &b, const int &c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int n;
    std::cin >> n;
    int dp[n + 1];
    int prev[n + 1];
    dp[1] = 0;
    prev[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0 && i % 2 == 0) {
            dp[i] = min(dp[i - 1], dp[i / 3], dp[i / 2]) + 1;
            if (dp[i] - 1 == dp[i - 1]) prev[i] = i - 1;
            else if (dp[i] - 1 == dp[i / 3]) prev[i] = i / 3;
            else prev[i] = i / 2;
        } else if (i % 3 == 0) {
            dp[i] = std::min(dp[i - 1], dp[i / 3]) + 1;
            if (dp[i] - 1 == dp[i - 1]) prev[i] = i - 1;
            else prev[i] = i / 3;
        } else if (i % 2 == 0) {
            dp[i] = std::min(dp[i - 1], dp[i / 2]) + 1;
            if (dp[i] - 1 == dp[i - 1]) prev[i] = i - 1;
            else prev[i] = i / 2;
        } else {
            dp[i] = dp[i - 1] + 1;
            prev[i] = i - 1;
        }
    }
    std::cout << dp[n] << std::endl;
    int k = n;
    std::vector<int> ans;
    while (k != 1) {
        ans.push_back(k);
        k = prev[k];
    }
    ans.push_back(1);
    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] << " ";
    }
    return 0;
}

/*
 Имеется калькулятор, который выполняет следующие операции:
   умножить число X на 2;
   умножить число X на 3;
   прибавить к числу X единицу.
 Определите, какое наименьшее количество операций требуется, чтобы получить из числа 1 число N.
 */
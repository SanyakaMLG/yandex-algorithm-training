#include <iostream>
#define MAX_INT 2147483647

int main() {
    int n;
    std::cin >> n;
    int dp[n + 3];
    int a[n + 3], b[n + 3], c[n + 3];
    a[0] = a[1] = a[2] = b[0] = b[1] = b[2] = c[0] = c[1] = c[2] = MAX_INT;
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 3; i < n + 3; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 3; i < n + 3; i++) {
        dp[i] = std::min(dp[i - 1] + a[i], std::min(dp[i - 2] + b[i - 1], dp[i - 3] + c[i - 2]));
    }
    std::cout << dp[n + 2];
    return 0;
}

/*
 В кассу выстроилась очередь из N людей. Каждый человек может купить билет себе за Ai времени, себе и следующему за ним за Bi времени,
 себе и двум следующим за Ci времени. Обилетить всех как можно быстрее.
 */
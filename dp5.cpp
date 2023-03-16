#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int dp[n];
    dp[0] = arr[1] - arr[0];
    dp[1] = arr[2] - arr[0];
    for (int i = 3; i < n; i++) {
        dp[i - 1] = min(dp[i - 3], dp[i - 2]) + arr[i] - arr[i - 1];
    }
    cout << dp[n - 2];
    return 0;
}

/*
 В дощечке в один ряд вбиты гвоздики. Любые два гвоздика можно соединить ниточкой. Требуется соединить некоторые пары гвоздиков
 ниточками так, чтобы к каждому гвоздику была привязана хотя бы одна ниточка, а суммарная длина всех ниточек была минимальна.
 */
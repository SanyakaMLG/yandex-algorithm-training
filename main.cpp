#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, s;
int ql[N], qr[N];
void read(){
    cin >> n >> s; // Ввод количество отрезков
    for (int i = 1; i <= n; i++){
        cin >> ql[i] >> qr[i];  // Ввод отрезков
    }
}
long long check(int l, int r){
    int A = 0; // Количество чисел которые будут стоять слева от медианы
    int B = 0; // Количество чисел которые будут стоять слева от медианы
    long long sum = 0; // Сумма чисел которые выбрали внутри отрезков
    vector <int> L;
    for (int i = 1; i <= n; i++){
        if (qr[i] < l){
            A++; // число ql[i] уходит в левую часть от медианы
            sum += ql[i];
        }else if (ql[i] > r){
            B++; // число ql[i] уходит в правую часть от медианы
            sum += ql[i];
        }else{
            L.push_back(ql[i]); // Запоминаем все числа которые не ушли ни в какую сторону
        }
    }
    sort(L.begin(), L.end());
    if (A <= n / 2 && B <= n / 2){ // Необходимое условие
        for (int i = 0; i < n / 2 - A; i++){
            sum += L[i]; // Дописываем слева числа чтобы их стало рано n / 2
        }
        long long oc = max(0ll, s - sum);
        long long c = oc / ((n / 2 + 1 - B)); // Находим максимальную медиану такую чтобы суммой не превосходили
        if (c >= r) c = r;
        sum += c * 1ll * (n / 2 + 1 - B); // sum сумма чисел которые выбрали в отрезках
        if (sum <= s && c >= l && c <= r) return c;
    }
    return -1;
}
void solver(){
    vector <int> a;
    for (int i = 1; i <= n; i++){
        a.push_back(ql[i]); // Записываем все кроя отрезков в вектор
        a.push_back(qr[i]);
    }
    sort(a.begin(), a.end()); // Отсортируем
    a.erase(unique(a.begin(), a.end()), a.end()); // Убираем повторы
    long long ans = -1;
    int mid = a.size() / 2;
    for (int del = -1; del <= 1 ; del++){
        int i = mid + del;
        if (i >= 1 && i <= n)
            ans = max(ans, check(a[i], a[i])); // Проверяем что медиана лежит на отрезке [a[i], a[i]]
    }

    for (int del = -1; del <= 1 ; del++){
        int i = mid + del;
        if (i >= 1 && i < n)
            ans = max(ans, check(a[i], a[i + 1])); // Проверяем что медиана лежит на отрезке [a[i], a[i]]
    }
    cout << ans << endl;
}

void solve(){
    read();
    solver();
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0); // Для быстрого ввода
    solve();
}
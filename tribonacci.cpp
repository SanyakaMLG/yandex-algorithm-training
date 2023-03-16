#include <iostream>

int main() {
    int n, prev3 = 0, prev2 = 1, prev1 = 1, cur;
    std::cin >> n;
    for (int i = 3; i < n + 3; i++) {
        cur = prev3 + prev2 + prev1;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    std::cout << cur;
    return 0;
}

/*
 По данному числу N определите количество последовательностей из нулей и единиц длины N, в которых никакие три единицы не стоят рядом.
 */
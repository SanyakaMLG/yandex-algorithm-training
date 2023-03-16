#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int x, y;
    int x_max = -1, y_max = -1, y_min = 1000000001, x_min = 1000000001;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        if (x > x_max) x_max = x;
        if (x < x_min) x_min = x;
        if (y > y_max) y_max = y;
        if (y < y_min) y_min = y;
    }
    std::cout << x_min << " " << y_min << " " << x_max << " " << y_max;
    return 0;
}

/*
 На клетчатой плоскости закрашено K клеток. Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными
 линиям сетки, покрывающий все закрашенные клетки.
 */
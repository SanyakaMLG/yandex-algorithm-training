#include <vector>
#include <iostream>

class Heap {
    std::vector<int> data;
public:
    void push(int x) {
        data.push_back(x);
        int pos = data.size() - 1;
        while (pos > 0 && data[pos] < data[(pos - 1) / 2]) {
            std::swap(data[pos], data[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }
    int pop() {
        int ret = data[0];
        int length = data.size();
        data[0] = data[length - 1];
        int pos = 0;
        while (pos * 2 + 2 < length) {
            int min_son_idx = pos * 2 + 1;
            if (data[pos * 2 + 2] < data[min_son_idx])
                min_son_idx = pos * 2 + 2;
            if (data[pos] > data[min_son_idx]) {
                std::swap(data[min_son_idx], data[pos]);
                pos = min_son_idx;
            } else {
                break;
            }
        }
        data.pop_back();
        return ret;
    }
};

int main() {
    int n;
    Heap heap;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        heap.push(x);
    }
    for (int i = 0; i < n; i++) {
        std::cout << heap.pop() << " ";
    }
    return 0;
}
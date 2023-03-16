#include <vector>
#include <iostream>

class Heap {
    std::vector<int> data;
public:
    void push(int x) {
        data.push_back(x);
        int pos = data.size() - 1;
        while (pos > 0 && data[pos] > data[(pos - 1) / 2]) {
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
            int max_son_idx = pos * 2 + 1;
            if (data[pos * 2 + 2] > data[max_son_idx])
                max_son_idx = pos * 2 + 2;
            if (data[pos] < data[max_son_idx]) {
                std::swap(data[max_son_idx], data[pos]);
                pos = max_son_idx;
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
        if (x == 0) {
            std::cin >> x;
            heap.push(x);
        } else {
            std::cout << heap.pop() << std::endl;
        }
    }
    return 0;
}
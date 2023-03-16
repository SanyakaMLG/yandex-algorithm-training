#include <iostream>
#include <vector>

class Queue {
    std::vector<int> queue;
    int head, tail;
public:
    Queue() {
        head = tail = 0;
    }
    void push(int x) {
        queue.push_back(x);
        tail++;
    }
    int pop() {
        int ret = queue[head++];
        if (head >= 100) {
            queue.assign(queue.begin() + head, queue.end());
            tail -= head;
            head = 0;
        }
        return ret;
    }
    int front() {
        return queue[head];
    }
    int size() {
        return tail - head;
    }
    void clear() {
        head = tail = 0;
        queue.clear();
    }
};

int main() {
    std::string s;
    Queue qu;
    int i = 1;
    while (s != "exit") {
        std::cin >> s;
        if (s == "pop") {
            if (qu.size() != 0) {
                std::cout << qu.pop() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "front") {
            if (qu.size() != 0) {
                std::cout << qu.front() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "size") {
            std::cout << qu.size() << std::endl;
        } else if (s == "clear") {
            qu.clear();
            std::cout << "ok\n";
        } else if (s == "push") {
            int x;
            std::cin >> x;
            qu.push(x);
            std::cout << "ok\n";
        }
    }
    std::cout << "bye";
    return 0;
}

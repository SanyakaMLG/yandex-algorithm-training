#include <cstring>
#include <string>
#include <iostream>

class Stack {
    int capacity, size;
    int *data;
public:
    Stack() {
        capacity = 50, size = 0;
        data = new int[capacity];
    }
    void push(int x) {
        if (size == capacity) {
            capacity *= 2;
            int *new_data = new int[capacity];
            std::memcpy(&new_data, &data, sizeof(data));
            delete[] data;
            data = new_data;
        }
        data[size++] = x;
    }
    int pop() {
        // TODO reduce the capacity of array
        return data[--size];
    }
    int back() {
        return data[size - 1];
    }
    void clear() {
        capacity = 50, size = 0;
        delete[] data;
        data = new int[capacity];
    }
    int get_size() {
        return size;
    }
};

int main() {
    Stack st;
    std::string s;
    while (true) {
        std::getline(std::cin, s);
        if (s == "pop") {
            if (st.get_size() != 0) {
                std::cout << st.pop() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "back") {
            if (st.get_size() != 0) {
                std::cout << st.back() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "size") {
            std::cout << st.get_size() << std::endl;
        } else if (s == "clear") {
            st.clear();
            std::cout << "ok" << std::endl;
        } else if (s == "exit") {
            std::cout << "bye";
            return 0;
        } else {
            int c = 1;
            int value = 0;
            int i = s.size() - 1;
            while (s[i] != ' ') {
                if (s[i] == '-') {
                    value *= -1;
                } else {
                    value += c * (s[i] - '0');
                    c *= 10;
                }
                i--;
            }
            st.push(value);
            std::cout << "ok" << std::endl;
        }
    }
    return 0;
}
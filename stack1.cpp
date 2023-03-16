#include <iostream>

struct node {
    node *next;
    int data;
};

class stack {
    node *head;
    int size;
public:
    stack() {
        head = nullptr;
        size = 0;
    }
    void push(int x) {
        node *p = new node;
        p->data = x;
        if (head == nullptr) {
            p->next = nullptr;
        } else {
            p->next = head;
        }
        head = p;
        size++;
    }
    int back() {
        return head->data;
    }
    int pop() {
        node *p;
        p = head;
        head = p->next;
        int res = p->data;
        delete p;
        size--;
        return res;
    }
    int get_size() {
        return size;
    }
    void clear() {
        if (head == nullptr) return;
        node *p = head, *p_next;
        while (p != nullptr) {
            p_next = p->next;
            delete p;
            p = p_next;
        }
        head = nullptr;
        size = 0;
    }
};

int main() {
    stack st;
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
}
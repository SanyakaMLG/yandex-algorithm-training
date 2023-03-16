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
    std::getline(std::cin, s);
    for (auto i : s) {
        if (i == '(' || i == '{' || i == '[') {
            st.push(i);
        } else {
            if (st.get_size() == 0) {
                std::cout << "no";
                return 0;
            }
            auto bracket = st.pop();
            if (i - bracket != 1 && i - bracket != 2) {
                std::cout << "no";
                return 0;
            }
        }
    }
    if (st.get_size() == 0) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}

/*
 Рассмотрим последовательность, состоящую из круглых, квадратных и фигурных скобок. Программа дожна определить, является ли данная
 скобочная последовательность правильной. Пустая последовательность явлется правильной. Если A – правильная, то последовательности
 (A), [A], {A} – правильные. Если A и B – правильные последовательности, то последовательность AB – правильная.
 */
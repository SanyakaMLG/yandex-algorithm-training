#include <iostream>
#include <vector>

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
    int n;
    std::cin >> n;
    std::vector<int> vec;
    vec.push_back(0);
    st.push(101);
    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (vec[vec.size() - 1] + 1 == x) {
            vec.push_back(x);
        } else if (x < st.back()) {
            st.push(x);
        } else {
            while (st.back() == vec[vec.size() - 1] + 1) {
                vec.push_back(st.pop());
            }
            if (x > st.back()) {
                std::cout << "NO";
                return 0;
            } else {
                st.push(x);
            }
        }
    }
    std::cout << "YES";
    return 0;
}

/*
 Определить, возможно ли отсортировать последовательность чисел от 1 до N с использованием одного стека.
 */
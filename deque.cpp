#include <iostream>

struct node {
    int data;
    node *next, *prev;
};

class Deque {
    node *head, *tail;
    int size;
public:
    Deque() {
        head = tail = nullptr;
        size = 0;
    }
    void push_front(int x) {
        node *p = new node;
        p->data = x;
        if (size == 0) {
            p->prev = head;
            p->next = tail;
            head = tail = p;
        } else {
            p->prev = nullptr;
            p->next = head;
            head->prev = p;
            head = p;
        }
        size++;
    }
    void push_back(int x) {
        node *p = new node;
        p->data = x;
        if (size == 0) {
            p->prev = head;
            p->next = tail;
            head = tail = p;
        } else {
            p->next = nullptr;
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
        size++;
    }
    int front() {
        return head->data;
    }
    int back() {
        return tail->data;
    }
    int pop_back() {
        node *p = tail;
        tail = p->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        int ret = p->data;
        delete p;
        size--;
        return ret;
    }
    int pop_front() {
        node *p = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        int ret = p->data;
        delete p;
        size--;
        return ret;
    }
    int get_size() {
        return size;
    }
    void clear() {
        node *p, *p1;
        p = head;
        while(p != nullptr) {
            p1 = p->next;
            delete p;
            p = p1;
        }
        head = tail = nullptr;
        size = 0;
    }
};

int main() {
    std::string s;
    Deque dq;
    while(s != "exit") {
        std::cin >> s;
        if (s == "pop_front") {
            if (dq.get_size() != 0) {
                std::cout << dq.pop_front() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "pop_back") {
            if (dq.get_size() != 0) {
                std::cout << dq.pop_back() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "back") {
            if (dq.get_size() != 0) {
                std::cout << dq.back() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "front") {
            if (dq.get_size() != 0) {
                std::cout << dq.front() << std::endl;
            } else {
                std::cout << "error\n";
            }
        } else if (s == "size") {
            std::cout << dq.get_size() << std::endl;
        } else if (s == "clear") {
            dq.clear();
            std::cout << "ok\n";
        } else if (s == "push_back") {
            int x;
            std::cin >> x;
            dq.push_back(x);
            std::cout << "ok\n";
        } else if (s == "push_front") {
            int x;
            std::cin >> x;
            dq.push_front(x);
            std::cout << "ok\n";
        }
    }
    std::cout << "bye";
    return 0;
}
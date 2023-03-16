#include <iostream>
#include <vector>

struct node {
    node *next;
    std::pair<int, int> data;
};

class stack {
    node *head;
    int size;
public:
    stack() {
        head = nullptr;
        size = 0;
    }
    void push(std::pair<int, int> val) {
        node *p = new node;
        p->data = val;
        if (head == nullptr) {
            p->next = nullptr;
        } else {
            p->next = head;
        }
        head = p;
        size++;
    }
    std::pair<int, int> back() {
        return head->data;
    }
    std::pair<int, int> pop() {
        node *p;
        p = head;
        head = p->next;
        std::pair<int, int> res = p->data;
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
    std::pair<int, int> array[n];
    int ans[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i].first;
        array[i].second = i;
    }
    st.push(std::pair<int, int>(-1, -1));
    for (int i = 0; i < n; i++) {
        while (array[i].first < st.back().first) {
            auto tmp = st.pop();
            ans[tmp.second] = array[i].second;
        }
        st.push(array[i]);
    }
    while (st.get_size() != 0) {
        auto tmp = st.pop();
        ans[tmp.second] = -1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    return 0;
}

/*
 Лайнландия представляет из себя одномерный мир, являющийся прямой, на котором распологаются N городов, последовательно
 пронумерованных от 0 до N - 1 . Направление в сторону от первого города к нулевому названо западным, а в обратную — восточным.
 Когда в Лайнландии неожиданно начался кризис, все были жители мира стали испытывать глубокое смятение. По всей Лайнландии
 стали ходить слухи, что на востоке живётся лучше, чем на западе.
 Так и началось Великое Лайнландское переселение. Обитатели мира целыми городами отправились на восток, покинув родные улицы,
 и двигались до тех пор, пока не приходили в город, в котором средняя цена проживания была меньше, чем в родном.
 */
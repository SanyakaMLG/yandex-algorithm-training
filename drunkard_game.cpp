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
    Queue first, second;
    for (int i = 0; i < 5; i++) {
        int x;
        std::cin >> x;
        first.push(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        std::cin >> x;
        second.push(x);
    }
    for (int i = 0; i < 1000000; ++i) {
        int first_card = first.pop();
        int second_card = second.pop();
        if (!(first_card == 9 && second_card == 0) && first_card > second_card || first_card == 0 && second_card == 9) {
            first.push(first_card);
            first.push(second_card);
        } else {
            second.push(first_card);
            second.push(second_card);
        }
        if (second.size() == 0) {
            std::cout << "first " << i + 1;
            return 0;
        } else if (first.size() == 0) {
            std::cout << "second " << i + 1;
            return 0;
        }
    }
    std::cout << "botva";
    return 0;
}

/*
 В игре в пьяницу карточная колода раздается поровну двум игрокам. Далее они вскрывают по одной верхней карте, и тот, чья карта
 старше, забирает себе обе вскрытые карты, которые кладутся под низ его колоды. Тот, кто остается без карт – проигрывает. Для
 простоты будем считать, что все карты различны по номиналу, а также, что самая младшая карта побеждает самую старшую карту
 ("шестерка берет туза"). Игрок, который забирает себе карты, сначала кладет под низ своей колоды карту первого игрока, затем
 карту второго игрока (то есть карта второго игрока оказывается внизу колоды). Напишите программу, которая моделирует игру в
 пьяницу и определяет, кто выигрывает. В игре участвует 10 карт, имеющих значения от 0 до 9, большая карта побеждает меньшую,
 карта со значением 0 побеждает карту 9.
 Программа должна определить, кто выигрывает при данной раздаче, и вывести слово first или second, после чего вывести количество
 ходов, сделанных до выигрыша. Если на протяжении 10^6 ходов игра не заканчивается, программа должна вывести слово botva.
 */
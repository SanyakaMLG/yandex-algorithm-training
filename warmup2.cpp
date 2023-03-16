#include <iostream>

int chars[26];
int max;

void find_max() {
    max = 0;
    for (int i : chars) {
        if (i > max) max = i;
    }
}

int main() {
    int k, ans = 0;
    std::cin >> k;
    std::string s;
    std::cin >> s;
    int i = 0, j = 0;
    chars[s[i] - 'a']++;
    find_max();
    while (i < s.size() - 1) {
        if (i - j + 1 - max <= k) {
            i++;
            chars[s[i] - 'a']++;
            find_max();
        } else {
            ans = std::max(ans, i - j);
            chars[s[j] - 'a']--;
            find_max();
            j++;
        }
    }
    std::cout << (i - j + 1 - max <= k ? std::max(ans, i-j+1) : std::max(ans, i-j));
    return 0;
}

/*
 Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки abcaabdddettq равна 3)
 Сделайте данную вам строку как можно более красивой, если вы можете сделать не более k операций замены символа.
 Выведите одно число — максимально возможную красоту строчки, которую можно получить.
 */
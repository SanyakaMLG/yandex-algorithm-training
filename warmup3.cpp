#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int bin_search(std::vector<int> &arr, int size, int x) {
    int L = -1, R = size;
    while (L != R - 1) {
        int mid = (L + R) / 2;
        if (arr[mid] >= x) {
            R = mid;
        } else {
            L = mid;
        }
    }
    return R;
}

int main() {
    int n;
    std::cin >> n;
    int collection[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> collection[i];
    }
    std::unordered_map<int, int> mp;
    std::sort(collection, collection + n);
    std::vector<int> new_collection;
    int cur = collection[0];
    new_collection.push_back(cur);
    for (int i = 1; i < n; ++i) {
        if (collection[i] != cur) {
            cur = collection[i];
            new_collection.push_back(cur);
        }
    }
    int new_n = new_collection.size();
    int k;
    std::cin >> k;
    int x;
    for (int i = 0; i < k; ++i) {
        std::cin >> x;
        if (mp.count(x) == 0) {
            mp.insert(std::make_pair(x, bin_search(new_collection, new_n, x)));
        }
        std::cout << mp.find(x)->second << std::endl;
    }
}

/*
 Диего увлекается коллекционированием наклеек. На каждой из них написано число, и каждый коллекционер мечтает собрать наклейки со
 всеми встречающимися числами.
 Диего собрал N наклеек, некоторые из которых, возможно, совпадают. Как-то раз к нему пришли K коллекционеров. i-й из них собрал все
 наклейки с номерами не меньшими, чем pi. Напишите программу, которая поможет каждому из коллекционеров определить, сколько
 недостающих ему наклеек есть у Диего. Разумеется, гостей Диего не интересуют повторные экземпляры наклеек.
 */
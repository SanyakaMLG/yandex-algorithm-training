#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_set<int> intersect(const unordered_set<int>& first, const unordered_set<int>& second) {
    unordered_set<int> ret;
    for (auto el : first) {
        if (second.contains(el)) ret.insert(el);
    }
    return ret;
}

int bfs(vector<vector<int>> &graph, const unordered_set<int>& starts, const unordered_set<int>& ends, int m) {
    int ans = 100;
    int distance[m + 1];
    for (int i = 1; i <= m; i++) distance[i] = -1;
    queue<int> qu;
    for (auto el : starts) {
        distance[el] = 0;
        qu.push(el);
    }
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (auto v : graph[now]) {
            if (distance[v] == -1) {
                distance[v] = distance[now] + 1;
                qu.push(v);
            }
        }
    }
    for (auto el : ends) {
        if (distance[el] != -1 && distance[el] < ans) ans = distance[el];
    }
    return ans == 100 ? -1 : ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList (m + 1);
    vector<unordered_set<int>> sets;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        unordered_set<int> tmp;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            tmp.insert(x);
        }
        sets.push_back(tmp);
    }
    int start, end;
    cin >> start >> end;
    unordered_set<int> starts, ends;

    for (int i = 0; i < m; i++) {
        if (sets[i].contains(start)) {
            starts.insert(i + 1);
        }
        if (sets[i].contains(end)) {
            ends.insert(i + 1);
        }
        for (int j = i + 1; j < m; j++) {
            unordered_set<int> tmp = intersect(sets[i], sets[j]);
            if (!tmp.empty()) {
                adjList[i + 1].push_back(j + 1);
                adjList[j + 1].push_back(i + 1);
            }
        }
    }
    cout << bfs(adjList, starts, ends, m);
}

/*
 Метрополитен состоит из нескольких линий метро. Все станции метро в городе пронумерованы натуральными числами от 1 до N. На
 каждой линии расположено несколько станций. Если одна и та же станция расположена сразу на нескольких линиях, то она является
 станцией пересадки и на этой станции можно пересесть с любой линии, которая через нее проходит, на любую другую (опять же
 проходящую через нее).
 Напишите программу, которая по данному вам описанию метрополитена определит, с каким минимальным числом пересадок можно
 добраться со станции A на станцию B. Если данный метрополитен не соединяет все линии в одну систему, то может так получиться,
 что со станции A на станцию B добраться невозможно, в этом случае ваша программа должна это определить.
 */
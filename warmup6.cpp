#include <iostream>
#include <unordered_set>

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

bool has_intersect(std::pair<int, int> src, std::pair<int, int> val) {
    return !(val.second < src.first || val.first > src.second);
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::unordered_set<std::pair<int, int>, pair_hash> st;
    int x1, x2, res = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x1 >> x2;
        std::pair<int, int> tmp = std::make_pair(x1, x2);
        for (auto it = st.begin(); it != st.end(); ) {
            if (has_intersect(tmp, *it)) {
                res--;
                it = st.erase(it);
            } else {
                it++;
            }
        }
        st.insert(tmp);
        res++;
    }
    std::cout << res;
    return 0;
}

/*
 Васин жесткий диск состоит из M секторов. Вася последовательно устанавливал на него различные операционные системы следующим
 методом: он создавал новый раздел диска из последовательных секторов, начиная с сектора номер ai и до сектора bi включительно,
 и устанавливал на него очередную систему. При этом, если очередной раздел хотя бы по одному сектору пересекается с каким-то ранее
 созданным разделом, то ранее созданный раздел «затирается», и операционная система, которая на него была установлена, больше не
 может быть загружена.
 Напишите программу, которая по информации о том, какие разделы на диске создавал Вася, определит, сколько в итоге работоспособных
 операционных систем установлено и работает в настоящий момент на Васином компьютере.
 */
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class DSU {
public:
    // متغیرها را public کردیم تا اگر تست‌ها نیاز به بررسی دارند، خطا ندهد
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

class DSU {
public:
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

int main() {
    // بهینه‌سازی سرعت ورودی/خروجی
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        DSU dsu(n);
        for (int i = 0; i < m; ++i) {
            string type;
            int u, v;
            cin >> type >> u >> v;

            if (type == "+") {
                dsu.unionSet(u, v);
            } else if (type == "?") {
                if (dsu.findSet(u) == dsu.findSet(v)) {
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }
            }
        }
    }
    return 0;
}
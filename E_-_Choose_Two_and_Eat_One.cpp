#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int m) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b >>= 1;
    }
    return res;
}

const int MAXN = 501;

struct Disjoint_Set {
    int arr[MAXN << 1], cnt[MAXN << 1];
    Disjoint_Set() {
        for (int i = 1; i < MAXN * 2; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return false;
        if (cnt[j] > cnt[i])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
        return true;
    }
} dsu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            g[i][j] = g[j][i] = (power(a[i], a[j], m) + power(a[j], a[i], m)) % m;
        }
    }
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            edges.emplace_back(-g[i][j], i, j);
        }
    }
    sort(edges.begin(), edges.end());
    long long ans = 0;
    for(auto [w, x, y] : edges) {
        if(dsu.unite(x, y)) {
            ans += w;
        }
    }
    cout << -ans << "\n";
    return 0;
}
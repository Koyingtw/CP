#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if !LOCAL
#define endl '\n'
#endif

using namespace std;

int n = 1;

vector<pair<char, char>> ans;
#define pb push_back

void hannoi(int i, char A, char B, char C) {
    if (i == n)
        return;
    hannoi(i + 1, A, B, C);
    ans.pb({A, B});
    hannoi(i + 1, C, B, A);
    ans.pb({B, C});
    hannoi(i + 1, A, B, C);
}


void sol() {
    for (n = 1; n <= 9; n++) {
        string s = ("0" + to_string(n) + ".out");
        freopen(s.c_str(), "w", stdout);
        ans.clear();
        hannoi(0, '1', '2', '3');
        cout << ans.size() << endl;
        for (auto it: ans)
            cout << it.F << ' ' << it.S << endl;
    }
}



signed main() {
    int _ = 1;
    while (_--) {
        sol();
    }
    return 0;
} 
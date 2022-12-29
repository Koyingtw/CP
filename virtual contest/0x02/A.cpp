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

int n, m;   
map<string, int> money;

void sol() {
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name;
        int mon;
        getline(cin, name);
        cin >> mon;
        cin.ignore();
        money[name] = mon;
    }

    pair<string, int> ans {"", 0};
    for (int i = 0; i < m; i++) {
        string name;
        int mon;
        getline(cin, name);
        cin >> mon;
        cin.ignore();
        if (name == ans.F)
            continue;
        if (mon <= ans.S)
            continue;
        if (mon > money[name])
            continue;
        ans = {name, mon};
    }
    cout << ans.F << '\n' << ans.S << endl;
}

/*
3 6
Little A
400
Little B
530
Little C
1
Little A
200
Little B
200
Little B
300
Little C
350
Little A
250
Little B
400

*/

signed main() {
    int _ = 1;
    while (_--) {
        sol();
    }
    return 0;
} 
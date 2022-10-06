// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], y[MAXN], z[MAXN];

void sol() {
    vector<int> neg, pos;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        z[i] = y[i] - x[i];
        if (z[i] < 0)
            neg.pb(z[i]);
        else
            pos.pb(z[i]);
    }

    sort(all(neg));
    sort(all(pos), greater<int>());

    // for (int i = 0; i < n; i++)
    //     cout << z[i] << ' ';
    // cout << endl;

    int ans = 0;
    int i = 0, j = 0;

    for (; i < neg.size() && j < pos.size(); j++) {
        while (i < neg.size() && -neg[i] > pos[j])
            i++;
        if (i < neg.size()) {
            ans++;
            i++;
        }
        else
            break;
    }

    // cout << j << endl;

    if (j < pos.size())
        ans += (pos.size() - j) / 2;

    // cout << pos.size() << ' ' << j << endl;
    cout << ans << endl;
}

auto main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
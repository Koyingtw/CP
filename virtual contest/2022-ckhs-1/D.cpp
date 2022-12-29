#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
using namespace std;

#define MAXN 2000005
#define MAXM 1000005

int n, k;
string s;
int x[MAXN];

void sol() {
    cin >> n >> k;
    cin >> s;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ans = 0, cnt = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
        cnt += s[i] - '0';

        while (pq.size() && cnt - pq.top().S > k)
            pq.pop();
        
        if (pq.size())
            cmax(ans, sum - pq.top().F);
        if (cnt <= k)
            cmax(ans, sum);

        pq.push(pii(sum, cnt));
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    int _ = 1; 
    // cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}
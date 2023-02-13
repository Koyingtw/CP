#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const ll P = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

const int MAXN = 50005;
const int MAXM = 1000005;

int n, m, a, b, c;
int dp[MAXN][2];

int fpow(int a, int b) {
    if (b < 0)
        return 0;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void pre() {
    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + (i - 1) * fpow(2, i - 2);
        // cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }
}

struct Fenwick_Tree {
    int arr[MAXN];

    void update(int i, int val) {
        for (; i < MAXN; i += lowbit(i));
            arr[i] += val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += arr[i];
        return res;
    }
} BIT;

string s;
void sol() {

    // if (m != 0)
    //     return;


    // cin >> s;
    n = s.size();

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (s[i] == '?');
    int Acnt = 0, Ccnt = 0;
    int revcnt = 0;
    int ques = 0;
    int cases = fpow(2, cnt);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') {
            ques++;
        }
        else {
            revcnt += dp[ques][0] + dp[ques][1];
            revcnt += Acnt * (ques) * fpow(2, ques - 1);
            // cout << revcnt << endl;

            if (s[i] == 'A')
                Acnt++;
            if (s[i] == 'C') {
                Ccnt++;
                revcnt += Acnt * cases;
                revcnt += (ques) * fpow(2, ques - 1);
            }
            Acnt += (ques) * fpow(2, ques - 1);
            Ccnt += (ques) * fpow(2, ques - 1);
            ques = 0;
        }
    }
    revcnt += dp[ques][0] + dp[ques][1];
    revcnt += Acnt * (ques) * fpow(2, ques - 1);
    // Acnt += (ques) * fpow(2, ques - 1);
    // Ccnt += (ques) * fpow(2, ques - 1);
    ques = 0;
    
    // cout << revcnt << endl;
    cout << revcnt * b + cases * c << endl;
}

signed main() {
    Koying;
    pre();
    int t = 1;

    cin >> n >> m >> a >> b >> c;
    cin >> s;
    s = " " + s;

    sol();

    int pos;
    char c;
    char tmp;
    while (m--) {
        cin >> pos >> c;
        tmp = s[pos];
        s[pos] = c;
        cout << s << endl;
        sol();
        // s[pos] = tmp;
    }

    // cin >> t;
    // while (t--)
    //     sol();
}
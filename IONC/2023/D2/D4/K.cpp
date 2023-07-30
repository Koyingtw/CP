#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

int x[26];

void MOV(char d, char a, char b) {
    if (x[d - 'a'] != '0')
        x[a - 'a'] = x[b - 'a'];
}
void ADD(char d, char a, char b, char c) {
    if (x[d - 'a'] != 0)
        x[a - 'a'] = x[b - 'a'] + x[c - 'a'];
}

void SUB(char d, char a, char b, char c) {
    if (x[d - 'a'] != 0)
        x[a - 'a'] = x[b - 'a'] - x[c - 'a'];
}

void LES(char a, char b, char c) {
    x[a - 'a'] = (x[b - 'a'] < x[c - 'a'] ? 1 : 0);
    // cout << x[b - 'a'] << ' ' << x[c - 'a'] << endl;
}

void sol() {
    for (int i = 0; i < 26; i++)
        x[i] = 1;
    // cin >> x[0];

    cout << 64 << endl;
    cout << "ADD y b b b" << endl;
    for (int i = 2; i <= 16; i++) {
        cout << "ADD y " << (char)('a' + i) << ' ' << (char)('a' + i - 1) << ' ' << (char)('a' + i - 1) << endl;
        ADD('y', 'a' + i, ('a' + i - 1), ('a' + i - 1));
        // cout << x[i] << ' ';
    }
    // cout << endl;


    // x[i] = 2^i (i = 1 ~ 16)
    char tmp1 = 'z';
    char tmp2 = 'y'; // tmp2 = 1 (const)
    char tmp3 = 'x'; // bool
    char tmp4 = 'w'; // ans

    cout << "MOV y " << tmp4 << ' ' << 'a' << endl;
    MOV('y', tmp4, 'a');

    cout << "ADD y " << 'a' << ' ' << 'a' << ' ' << tmp2 << endl;
    ADD('y', 'a', 'a', tmp2);

    for (int i = 15; i >= 1; i--) {
        // tmp1 = 2^i
        // cout << "MOV 1 " << tmp1 << ' ' << (char)('a' + i) << endl;
        // MOV(1, tmp1, ('a' + i));

        // tmp1 -= 1
        tmp1 = (char)('a' + i);
        // cout << "SUB 1 " << tmp1 << ' ' << tmp1 << ' ' << tmp2 << endl;

        // if a > 2^(i)
        cout << "LES " << tmp3 << ' ' << tmp1 << ' ' << "a" << endl;
        LES(tmp3, tmp1, 'a');
        // cout << x[tmp3 - 'a'] << endl;

        // if a > 2^(i), add 2^(i-1) to
        // cout << "ADD " << tmp3 << ' ' << tmp4 << ' ' << tmp4 << ' ' << (i > 1 ? (char)('a' + i - 1) : tmp2) << endl;
        // ADD(x[tmp3 - 'a'], tmp4, tmp4, (i > 1 ? (char)('a' + i - 1) : tmp2));
        // cout << x[tmp4 - 'a'] << endl;

        // if a > 2^(i), tmp4 = tmp4 - 2^(i - 1)
        cout << "SUB " << tmp3 << ' ' << tmp4 << ' ' << tmp4 << ' ' << (i > 1 ? (char)('a' + i - 1) : tmp2) << endl;
        SUB(tmp3, tmp4, tmp4, (i > 1 ? (char)('a' + i - 1) : tmp2)); 
        // cout << "0: " << x[0] << endl;
        
        // if a > 2^i, a = a - 2^i
        cout << "SUB " << tmp3 << ' ' << 'a' << ' ' << 'a' << ' ' << (char)('a' + i) << endl;
        SUB(tmp3, 'a', 'a', (char)('a' + i));

        // cout << x[tmp3 - 'a'] << endl;
    }

    // a = tmp4
    cout << "MOV y " << 'a' << ' ' << tmp4 << endl;
    MOV('y', 'a', tmp4);

    // cout << x[0] << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
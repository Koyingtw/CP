#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 200005

int n;

void sol() {
    string s;
    string team[2];
    cin >> n >> team[0] >> team[1];
    cin >> s;

    int win1 = 0, win2 = 0;
    bool the93 = false;

    for (int i = 0; i < min(12, n); i++) {
        if (s[i] == 'A')
            win1++;
        else
            win2++;
    }

    if (abs(win1 - win2) == 6 && n > 12) 
        the93 = true;

    string first_round = (win1 > win2 ? team[0] : team[1]);

    if (n <= 12) {
        cout << "ATK " << team[0] << " | " << win1 << " : " << win2 << " | " << team[1] << " DEF" << endl;
        cout << "Match in Progress" << endl;
        return;
    }

    for (int i = 12; i < min(24, n); i++) {
        if (s[i] == 'A')
            win2++;
        else
            win1++;
        if (max(win1, win2) == 13 && i != n - 1) {
            cout << "something went wrong :(" << endl;
            return;
        }
    }

    string second_round;

    if (max(win1, win2) > 13) {
        cout << "something went wrong :(" << endl;
        return;
    }


    if (max(win1, win2) < 13 && n <= 24) {
        cout << "DEF " << team[0] << " | " << win1 << " : " << win2 << " | " << team[1] << " ATK" << endl;
        cout << "Match in Progress" << endl;
        return;
    }
    if (max(win1, win2) == 13 && n <= 24) {
        cout << "DEF " << team[0] << " | " << win1 << " : " << win2 << " | " << team[1] << " ATK" << endl;
        cout << (win1 == 13 ? "Defenders" : "Attackers") << " Win";

        second_round = (win1 > win2 ? team[0] : team[1]);
        if (the93 && first_round != second_round)
            cout << ", 9-3 Curse!";
        cout << endl;
        return;
    }

    // assert(false);

    for (int i = 24; i < n; i++) {
        if (s[i] == 'A' && i % 2)
            win2++;
        else if (s[i] == 'A')
            win1++;
        else if (s[i] == 'D' && i % 2)
            win1++;
        else
            win2++;
        if (max(win1, win2) > 13 && abs(win1 - win2) > 2 - (i != n - 1)) {
            cout << "something went wrong :(" << endl;
            return;
        }
    }


    if (n % 2)
        cout << "ATK " << team[0] << " | " << win1 << " : " << win2 << " | " << team[1] << " DEF" << endl;
    else
        cout << "DEF " << team[0] << " | " << win1 << " : " << win2 << " | " << team[1] << " ATK" << endl;

    if (abs(win1 - win2) < 2) {
        cout << "Match in Progress" << endl;
        return;
    }
    
    if (n % 2) {
        cout << (win2 == max(win1, win2) ? "Defenders" : "Attackers") << " Win";
    }
    else
        cout << (win1 == max(win1, win2) ? "Defenders" : "Attackers") << " Win";

    second_round = (win1 > win2 ? team[0] : team[1]);
    if (the93 && first_round != second_round)
        cout << ", 9-3 Curse!";
    cout << endl;
}

/*
1
23 TL LEV
DDDDDADAADADAADDDDADADA

Match 1:
DEF TL | 10 : 13 | LEV ATK
Attackers Win


2
16 BME OPTC
AADDDDDADDDDAAAA
22 DRX FPX
DDADDADDDDDADDDDDDDDDD

5
24 LOUD OPTC
AADDDDDDAADAAADDDAAADDDD
25 LOUD OPTC
AADDDDDDAADAAADDDAAADDDDA
26 LOUD OPTC
AADDDDDDAADAAADDDAAADDDDAA
27 LOUD OPTC
AADDDDDDAADAAADDDAAADDDDAAA
28 LOUD OPTC
AADDDDDDAADAAADDDAAADDDDAAAD

2
14 AAA bbb
AAAAAAAAAAAADD
27 CCC ddd
AAAAAAAAAAAAAAAAAAAAAAAAADD
*/

signed main() {
    Koying;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Match " << i << ":\n";
        sol();
    }
    return 0;
}
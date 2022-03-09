#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 45
#define MAXM 1000005 
int n, L, R;
int x[MAXN];
int y[1 << 22], yy[1 << 22];

void sol()
{
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int sum = (1ll << n) - 1;
	L = sum - L + 1;
	R = sum - R + 1;
	// swap(L, R);
	sort(x, x + n);
	for (; L >= R; L--) {
		int l = 0, r = 1e18, mid = (l + r) / 2, tmp = 0;
		while (l < r) {
			mid = (l + r) / 2;
			int now = 1, cnt1 = 0, cnt2 = 0, now2 = 0;
			// cout << l << " " << r << endl;
			// cout << mid << endl;
			for (int mask = 1; mask < (1 << (n / 2)); mask++) {
				tmp = 0;
				for (int i = 0; i < n / 2; i++) {
					if (mask & (1 << i)) {
						tmp += x[i];
					}
				}
				y[now] = tmp;
				cnt2 += tmp <= mid;
				now++;
			}
			if (cnt2 > L) {
				r = mid - 1;
				continue;
			}
			sort(y, y + now);
			for (int mask = 1; mask < (1 << (n - n / 2)) && cnt2 < L; mask++) {
				tmp = 0;
				for (int i = n / 2; i < n; i++) {
					if (mask & (1 << (i - n / 2))) {
						tmp += x[i];
					}
				}
				yy[now2] = tmp;
				now2++;
			}
			if (cnt2 >= L) {
				r = mid;
				continue;
			}
			sort(yy, yy + now2);
			int a = now - 1, b = 0;
			for (; b < now2; b++) {
				while (a >= 0 && y[a] + yy[b] > mid)
					a--;
				if (a >= 0 && y[a] + yy[b] <= mid)
					cnt2 += a + 1;
			}
			if (cnt2 < L) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
			// cout << cnt2 << endl;
		}
		cout << r << " ";
	}
	cout << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}
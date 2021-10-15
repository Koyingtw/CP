#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
void sol1()
{
    int n, k;
    cin >> n >> k;
    int x[k];
    for (int i = 0; i < k; i++)
        cin >> x[i];
    sort(x, x + k, greater<int>());
    int pos = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (x[i] > pos)
        {
            pos += n - x[i];
            ans++;
        }
        else
            break;
    }
    cout << ans << endl;
}
void sol()
{
    int n, k;
    cin >> n >> k;
    int x[k];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        cin >> x[i];
        pq.push(x[i]);
    }
    int pos = 0, ans = 0;
    while (pq.size() && pos < n)
    {
        int now = pq.top();
        pq.pop();
        pos += pq.top() - now + (pq.top() == now);
        now += pq.top() - now + (pq.top() == now);
        pq.push(now);
        while (pq.top() < pos && pq.top() < now)
            pq.pop();
    }
    cout << pq.size() << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol1();
        }
    return 0;
}
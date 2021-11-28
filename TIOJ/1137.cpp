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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 10005
int timestamp = 1;
int D[MAXN], L[MAXN];
vector<int> v[MAXN], nodeAP;
vector<pr> edgebridge;
void dfs(int i, int fa)
{
    D[i] = L[i] = timestamp++;
    int childcnt = 0;
    bool isAP = false;

    for (int w : v[i])
    {
        if (w == fa)
            continue;
        if (!D[w])
        {
            dfs(w, i);
            childcnt++;
            if (D[i] <= L[w])
                isAP = true;
            L[i] = min(L[i], L[w]);
        }
        L[i] = min(L[i], D[w]);
    }
    if (i == fa && childcnt < 2)
        isAP = false; //特判根節點
    if (isAP)
        nodeAP.push_back(i);
}

void init()
{
    for (int i = 0; i < MAXN; i++)
        v[i].clear();
    MEM(D, 0);
    MEM(L, 0);
    nodeAP.clear();
    edgebridge.clear();
}
void sol()
{
    int n, m;
    cin >> n >> m;
    {
        init();
        for (int i = 0, a, b; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1, 1);
        sort(nodeAP.begin(), nodeAP.end());
        bool yes = true;
        cout << nodeAP.size() << endl;
        if (!nodeAP.size())
            nodeAP.push_back(0);
        for (int it : nodeAP)
            cout << it << " ";
        cout << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}
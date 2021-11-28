const int MAXN = 2e5 + 5;
int dsu[MAXN]; //dsu
int cnt[MAXN]; //set size

void init(int n) //初始化
{
    for (int i = 0; i < n; i++)
    {
        dsu[i] = i;
        cnt[i] = 1;
    }
}

int find(int i) //查找
{
    if (dsu[i] == i)
        return i;
    else
        return dsu[i] = find(dsu[i]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y) //合併
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (x > y)
        swap(x, y);
    dsu[y] = x;
    return;
}
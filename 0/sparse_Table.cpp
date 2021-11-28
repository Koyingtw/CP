int rmq[500005][33];
int x[500005];

fr(i, 0, n)
{
    cin >> x[i];
    rmq[i][0] = x[i];
}
fr(j, 1, 33)
{
    if ((1 << j) > n)
        break;
    fr(i, 0, n)
    {
        int a = 1 << j;
        if (i + a > n)
            break;
        a >>= 1;
        rmq[i][j] = max(rmq[i][j - 1], rmq[i + a][j - 1]);
    }
}

while (m--) //查詢 [a,b]
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    a--;
    int r = (b - a), tmp = a, cnt = 0;
    int ans = 0;
    while (r)
    {
        if (r % 2)
        {
            ans = max(ans, rmq[tmp][cnt]);
            tmp += 1 << cnt;
        }
        r >>= 1;
        cnt++;
    }
    cout << ans << endl;
}
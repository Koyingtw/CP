
#define lowbit(x) x &(-x)
#define MAXN 200005
struct bit
{
    int arr[MAXN];
    int query(int i)
    {
        int sum = 0;
        while (i)
        {
            sum += arr[i];
            i -= lowbit(i);
        }
        return sum;
    }

    void update(int i, int val)
    {
        while (i < MAXN)
        {
            arr[i] += val;
            i += lowbit(i);
        }
        return;
    }
};

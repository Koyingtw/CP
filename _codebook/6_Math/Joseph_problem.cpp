int josephus(int n, int k) { //0-based O(n)
    int s = 0;
    for (int i = 2; i <= n; i++)
        s = (s + k) % i;
    return s;
}

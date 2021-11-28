bool six(int n)
{
    if ((n % 6 == 1 || n % 6 == 5))
        return true;
    else
        return false;
}
vector<int> prime;
void pre()
{
    vector<bool> x(46341, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 46341; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 215)
            {
                for (int j = i * i; j < 46341; j += i)
                {
                    x[j] = false;
                }
            }
            prime.push_back(i);
        }
    }
}
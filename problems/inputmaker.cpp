#include <bits/stdc++.h>
#define ll long long

using namespace std;
int argc = 1000;
string argv = "100000";
ifstream ifs;
ofstream file;
string name = "C:/Users/koyin/OneDrive/CP/input/in";
void start() // 建立檔案
{
    int sum = 0, cnt = 0;
    for (int i = 0;; i++)
    {
        ifs.open(name + "_" + to_string(i) + ".txt");
        if (!ifs.is_open())
        {
            file.open(name + "_" + to_string(i) + ".txt");
            break;
        }
        else
            ifs.close();
    }
}
random_device rd;
auto tt = chrono::high_resolution_clock::now();
std::mt19937_64 gen = std::mt19937_64(tt.time_since_epoch().count());
std::uniform_int_distribution<> dis(1, 100000); //0~1之間，小數(若要改成整數real改int)
auto randfun = bind(dis, gen);

void makestring()
{
    int t = randfun() % 100000 + 1;
    file << t << endl;
    string a[t];
    for (int j = 0; j < t; j++)
    {
        int len = randfun() % 50 + 1;
        for (int i = 0; i < len; ++i)
        {
            int tmp = randfun() % 26;
            if (tmp < 26)
            {
                char c = 'a' + tmp;
                a[j] += c;
            }
            else
            {
                tmp -= 26;
                char c = 'A' + tmp;
                a[j] += c;
            }
        }
        file << a[j] << endl;
    }
}

void make()
{

    long long n = 100000, q = 100000, maxN = n, maxQ = q;
    string s = argv;
    stringstream ss;
    int num;
    ss << s;
    ss >> num;
    bool op = false, op2 = false;
    maxN = n, maxQ = q;
    if (randfun() % 2)
    {
        n = randfun() % 10000 + 1;
    }
    if (randfun() % 2)
    {
        q = randfun() % 100000 + 1;
    }
    cout << n << " " << q << endl;
    file << n << " " << q << endl;
    vector<ll> arr;
    vector<ll> arr1;
    ll mul = randfun();

    for (int i = 0; i < n; ++i)
    {
        file << randfun() % maxN + 1 << " ";
    }
    file << endl;

    for (int i = 0; i < q; ++i)
    {
        file << randfun() % n + 1 << endl;
        //arr1.push_back(mul * tmp % maxQ);
    }
    return;
    for (int i = 0; i < n; ++i)
    {
        //cout << arr[i] << " " << arr1[i] << endl;
        if (arr[i] == arr1[i])
            arr1[i]++;
        file << arr[i] << " ";
        //file << min(arr[i], arr1[i]) << " " << max(arr[i], arr1[i]) << endl;
    }
    file << endl;
    /*<< q << endl;
    int l, r, type;
    
    for (int i = 0; i < q; ++i)
    {
        type = randfun();
        l = randfun() % n + 1, r = randfun() % n + 1;
        if (l > r)
            swap(l, r);
        if (type % 2 == 1 || op)
        {
            cout << 1 << " " << l << " " << r << endl;
        }
        else
        {
            if (op2)
                r = l;
            ll v = randfun();
            type = randfun();
            if (type % 4 == 0)
                v *= mul;
            cout << 2 << " " << l << " " << r << " " << v << endl;
        }
    }*/
}

int main()
{
    int n = 20;
    //cin >> n;
    while (n--)
    {
        start();
        int t = 1;
        // if (randfun() % 2)
        //     t = randfun() % t + 1;
        // file << t << endl;
        while (t--)
            make();
        file.close();
    }
    return 0;
}

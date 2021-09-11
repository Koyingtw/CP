#include <iostream>
using namespace std;
int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    int siz = s1.size();
    int a = 0, b = 0;
    for (int i = 0; i < siz; i++)
    {
        if (s1[i] == s2[i])
            a++;
    }
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            if (i != j)
            {
                if (s1[i] == s2[j])
                {
                    b++;
                    cout << s1[i] << endl;
                }
            }
        }
    }
    cout << a << " " << b;
    system("pause");
}
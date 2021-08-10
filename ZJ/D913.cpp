/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include <bits/stdc++.h>
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
int arr[6] = {1, 2, 3, 4, 5, 6};
void sol()
{
    int x[6][7];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
            cin >> x[i][j];
    }
    do
    {
        bool yes = 1;
        for (int i = 0; i < 6; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 6; j++)
                if (x[i][j] == arr[j])
                    cnt++;
            if (cnt != x[i][6])
                yes = 0;
        }
        if (yes)
        {
            for (int i = 0; i < 6; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }
    } while (next_permutation(arr, arr + 6));
}

signed main()
{
    Koying;
    //while (1)
    sol();
    return 0;
}
#include <iostream>

using namespace std;

int n;
int a[1000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
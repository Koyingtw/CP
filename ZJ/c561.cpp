#include <iostream>

using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        int x[100005], mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            int b = 0;
            while (x[i]) {
                b = b * 10 + x[i] % 10;
                x[i] /= 10;
            }
            mx = max(b, mx);
        }
        cout << mx << endl;
    }

    return 0;
}
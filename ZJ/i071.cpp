#include <iostream>

using namespace std;

int main() {
    int n, m;
    int x[1005];

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> x[i];
    
    int mx = x[m], ans = 0;

    for (int i = m + 1; i <= n; i++) {
        if (x[i] > mx) {
            mx = x[i];
            ans++;
        }
    }
    mx = x[m];

    for (int i = m - 1; i >= 1; i--) {
        if (x[i] > mx) {
            mx = x[i];
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
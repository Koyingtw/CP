#include <iostream>

using namespace std;

int n;
int x[10005], cnt[30005];

int main() {
    cin >> n;
    int mxcnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cnt[x[i]]++;

        if (cnt[x[i]] > mxcnt)
            mxcnt = cnt[x[i]];
    }

    for (int i = 0; i <= 30000; i++) {
        if (cnt[i] == mxcnt)
            cout << i << ' ' << cnt[i] << endl;
    }
    return 0;
}
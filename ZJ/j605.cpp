#include <iostream>

using namespace std;

int t[105], s[105];

int main() {
    int score = 0;
    int mx = -1;
    int mxtime = 0;
    int bad = 0;
    int k;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> t[i] >> s[i];
        if (s[i] > mx) {
            mx = s[i];
            mxtime = t[i];
        }

        if (s[i] == -1)
            bad++;
    }

    score = mx - k - 2 * bad;

    if (score < 0)
        score = 0;

    cout << score << ' ' << mxtime << endl; 
    return 0;
}
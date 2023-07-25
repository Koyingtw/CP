#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string s, m;
    int ans;
    while(cin >> s >> m) {
        ans = (m[0] + 26 - s[0]) % 26;
        cout << ans << endl;
    }
    return 0;
}
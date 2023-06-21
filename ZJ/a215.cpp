#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int sum = 0, cnt = 0;
        do {
            sum += n;
            n++;
            cnt++;
        } while (sum <= m);
        cout << cnt << endl;
    }
    return 0;
}
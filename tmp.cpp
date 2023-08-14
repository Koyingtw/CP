#include <iostream>
 
using namespace std;


int main() {
    int n, m;
    cin >> n >> m; // n < m
    int i = n;
    while (1) {
        cout << i << endl;
        i += 2;
        if (i > m) {
            break;
        }
    }

    return 0;
}

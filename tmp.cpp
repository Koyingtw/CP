#include <iostream>
 
using namespace std;

int main() {
    int a[505];
    a[1] = 1;
    for (int i = 2; i <= 500; i++) {
        a[i] = a[i - 1] + i - 1;
    }

    int n;
    while (cin >> n) {
        cout << a[n] << endl;
    }
}

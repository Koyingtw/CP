#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << ((b - b % 2) - (a + a % 2)) / 2 + 1 << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= 2 * a - 1; i += 2) {
        for (int j = 0; j < (2 * a - 1 - i) / 2; j++)
            cout << '_';
        for (int j = 0; j < i; j++)
            cout << '*';
        for (int j = 0; j < (2 * a - 1 - i) / 2; j++)
            cout << '_';
        cout << endl;
    }
    return 0;
}
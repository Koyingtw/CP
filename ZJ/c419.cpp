#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j < a - i; j++)
            cout << '_';
        for (int j = a - i; j < a; j++)
            cout << '*';
        cout << endl;
    }
    return 0;
}
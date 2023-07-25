#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        int A = 0, B = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if ((s[i] == t[j]) && (i == j))
                    A++;
                else if (s[i] == t[j])
                    B++;
            }
        }
        cout << A << 'A' << B << 'B' << endl;
    }
}
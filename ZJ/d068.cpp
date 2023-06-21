#include <iostream>

using namespace std;

int main() {
    int weight;
    cin >> weight;
    if (weight > 50)
        weight--;
    cout << weight << endl;
    return 0;
}
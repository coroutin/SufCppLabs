#include <iostream>

using namespace std;

int main() {
    int n, m, vse = 0 ;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char bukeff = 'a' + (vse % 4);
            cout << bukeff;
            vse++;
        }
        cout << endl;
    }
}
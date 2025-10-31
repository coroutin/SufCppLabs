#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long orig = n;
    long long kamikatze = n;
    int minDigit = 9;
    int maxDigit = 0;
    int minPos = -1;
    int maxPos = -1;
    int curPos = 0;

    while (kamikatze > 0) {
        int d = kamikatze % 10;

        if (d < minDigit) {
            minDigit = d;
            minPos = curPos;
        }

        if (d > maxDigit) {
            maxDigit = d;
            maxPos = curPos;
        }

        kamikatze /= 10;
        curPos++;
    }

    kamikatze = orig;

    long long nn = 0;
    curPos = 0;
    int multiplier = 1;

    while (kamikatze > 0) {
        int di = kamikatze % 10;

        if (curPos == minPos) {
            di = maxDigit;
        }
        else if (curPos == maxPos) {
            di = minDigit;
        }

        nn += di * multiplier;
        multiplier *= 10;

        kamikatze /= 10;
        curPos++;
    }

    cout << nn << endl;
    cout << nn * 2 << endl;

    return 0;
}
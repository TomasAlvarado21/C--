#include <iostream>

using namespace std;

int main() {
    int n, h;

    cin >> n >> h;

    int i = 0;
    int x;
    int count = 0;

    while (i < n) {
        cin >> x;
        if (x > h) {
            count += 2;
        } else {
            count += 1;
        }
        i++;
    }
    cout << count << endl;
}

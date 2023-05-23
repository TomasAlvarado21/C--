#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int maxDistinctChars(string s) {
    int n = s.length();
    unordered_set<char> distinctChars;

    int maxDistinct = 0;
    for (int i = 0; i < n; i++) {
        distinctChars.insert(s[i]);
        maxDistinct = max(maxDistinct, static_cast<int>(distinctChars.size()));
    }

    return maxDistinct;
}

int maxDistinctSum(string s) {
    int n = s.length();
    int maxSum = 0;

    for (int i = 1; i < n; i++) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - i);

        int distinctA = maxDistinctChars(a);
        int distinctB = maxDistinctChars(b);

        maxSum = max(maxSum, distinctA + distinctB);
    }

    return maxSum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int result = maxDistinctSum(s);
        cout << result << endl;
    }

    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> seen;

    for (char c : s) {
        if (seen.find(c) != seen.end()) {
            cout << c;
            return 0;
        }
        seen.insert(c);
    }

    cout << -1;
    return 0;
}
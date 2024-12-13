#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> FindOverlaps(const string& str, const string& pattern) {
    vector<int> overlaps;
    for (size_t i = 0; i <= str.size() - pattern.size(); i++) {
        if (str.substr(i, pattern.size()) == pattern) {
            overlaps.push_back(i);
        }
    }
    return overlaps;
}

int main() {
    auto overlaps = FindOverlaps("abababab", "aba");

    if (overlaps.empty()) {
        cout << "No overlaps found." << endl;
    } else {
        cout << "Overlaps found at indices: ";
        for (auto idx : overlaps) {
            cout << idx << " ";
        }
        cout << endl;
    }
}
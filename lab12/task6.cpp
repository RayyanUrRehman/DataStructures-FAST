#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const long long prime = 31;
const long long mod = 1e9 + 9;

long long Hash(const string& str) {
    long long value = 0;
    long long p = 1;
    for (auto c : str) {
        value = (value + (c - 'a' + 1) * p) % mod;
        p = (p * prime) % mod;
    }
    return value;
}

vector<string> PalindromicSubstrings(const string& text) {
    vector<string> substrings;
    unordered_set<long long> hashes;

    for (int length = 1; length <= static_cast<int>(text.size()); length++) {
        for (int i = 0; i <= static_cast<int>(text.size()) - length; i++) {
            string substring = text.substr(i, length);
            string reversed_substring = string(substring.rbegin(), substring.rend());

            long long hash1 = Hash(substring);
            long long hash2 = Hash(reversed_substring);

            if (hash1 == hash2 && hashes.find(hash1) == hashes.end()) {
                substrings.push_back(substring);
                hashes.insert(hash1);
            }
        }
    }

    return substrings;
}

int main() {
    string text = "ABCBAB";
    vector<string> palindromes = PalindromicSubstrings(text);

    cout << "Found palindromic substrings:\n";
    for (const auto& palindrome : palindromes) {
        cout << palindrome << '\n';
    }

    return 0;
}
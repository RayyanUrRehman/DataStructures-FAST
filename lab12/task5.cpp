#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void PreprocessBadChar(const vector<string>& patterns,
                       unordered_map<char, int>& bad_char,
                       int pattern_length) {
    for (auto& pattern : patterns) {
        for (int i = 0; i < pattern_length; ++i) {
            bad_char[pattern[i]] = i;
        }
    }
}

void SearchPatterns(const string& text, const vector<string>& patterns) {
    int max_pattern_length = 0;
    for (const auto& pattern : patterns) {
        max_pattern_length = max(max_pattern_length, static_cast<int>(pattern.length()));
    }

    unordered_map<char, int> bad_char;
    PreprocessBadChar(patterns, bad_char, max_pattern_length);

    for (const auto& pattern : patterns) {
        int pattern_length = pattern.length();
        int shift = 0;

        while (shift <= (static_cast<int>(text.length()) - pattern_length)) {
            int j = pattern_length - 1;

            while (j >= 0 && pattern[j] == text[shift + j]) j--;

            if (j < 0) {
                cout << "Found pattern: \"" << pattern << "\" at index " << shift << endl;
                shift += (shift + pattern_length < static_cast<int>(text.length()))
                             ? pattern_length - bad_char[text[shift + pattern_length]]
                             : 1;
            } else {
                shift += max(1, j - bad_char[text[shift + j]]);
            }
        }
    }
}

int main() {
    string text = "ABCDEFG";
    vector<string> patterns = {"ABC", "EFG"};

    cout << "Searching for patterns in the text: \"" << text << "\"" << endl;
    SearchPatterns(text, patterns);

    return 0;
}
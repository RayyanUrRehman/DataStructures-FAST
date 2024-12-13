#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string StringToLowerCase(const string& str) {
    string lower_string;
    for (char c : str) {
        lower_string += tolower(c);
    }
    return lower_string;
}

vector<int> ComputeLPSArray(const string& pattern) {
    int N = pattern.size();
    vector<int> lps(N, 0);
    int length = 0;
    int idx = 1;

    while (idx < N) {
        if (pattern[idx] == pattern[length]) {
            length++;
            lps[idx] = length;
            idx++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[idx] = 0;
                idx++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& txt, const string& pat) {
    string lower_txt = StringToLowerCase(txt);
    string lower_pat = StringToLowerCase(pat);
    int N = lower_txt.size();
    int M = lower_pat.size();

    vector<int> lps = ComputeLPSArray(lower_pat);
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < N) {
        if (lower_pat[j] == lower_txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < N && lower_pat[j] != lower_txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    string text = "Data Structures";
    string pattern = "data";
    vector<int> result = KMPSearch(text, pattern);

    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at the following indices:" << endl;
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
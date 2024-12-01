#include<iostream>
using namespace std;


void bruteForce(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i=0;i<n-m;i++){

        int j=0;
        while(j<m && text[i+j]==pattern[j]){
            j++;
        }
        if (j == m){
            cout<<"Pattern found at "<<i<<endl;
        }
    }
}


int main()
{
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";
    bruteForce(text, pattern);

    return 0;
}
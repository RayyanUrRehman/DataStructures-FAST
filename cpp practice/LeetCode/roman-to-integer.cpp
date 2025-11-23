#include<iostream>
using namespace std;

int solve(string s){
    char symbol[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int value[7] =   {1000, 500, 100, 50,  10,  5,   1};

    int sum = 0;
    int i=0;

    while (i < s.length()){
        int j=0,k=0;
        while(s[i] != symbol[j]){
            j++;
        }
        while(s[i+1] != symbol[k]){
            k++;
        }
        cout<<j<<" "<<k<<endl;
        
        if (value[j] >= value[k]){
            sum += value[j];
            
        }
        else{
            sum += value[j] - value[k];
            i++;
        }

        i++;
    }

    cout<<sum;

}

int main(){
    string s = "LVIII";
    solve(s);
}
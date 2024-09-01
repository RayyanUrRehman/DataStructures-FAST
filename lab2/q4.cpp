#include<iostream>
using namespace std;

// jagged array is the optimal solution due to varying length of each row.

int main()
{
    int count[4] = {3,4,2,1};

    float** course = new float*[4];
    *(course+0) = new float[3] {2.7,3.4,3.9};
    *(course+1) = new float[4] {2.7,3.4,3.3,3.9};
    *(course+2) = new float[2] {2.7,3.4};
    *(course+3) = new float[1] {2.7};

    for (int i=0;i<4;i++){
        for (int k=0;k<count[i];++k){
            cout<<course[i][k]<<endl;
        }
        cout<<endl;
    }                     //outputting all data in order.


}

#include<iostream>
using namespace std;

int main()
{
    int rownum;
    cout<<"Number of rows: "; 
    cin>>rownum;

    string** rows = new string*[rownum];

    //allotting seats
    int seatnum;
    for (int i=0;i<rownum;i++){
        cout<<"Enter number of seats in row number "<<i+1<<" :";
        cin>>seatnum;
        rows[i] = new string[seatnum];
    }

    // allotting names
    string name;
    for (int i=0;i<rownum;i++){
        for (int j=0;j<seatnum;j++){
            cout<<"Enter name of attendee for row "<<i+1<<" seat "<<j+1<<": ";
            cin>>name;
            rows[i][j] = name;
        }
    }

    cout<<endl;

    //displaying
    for (int i=0;i<rownum;i++){
        for (int j=0;j<seatnum;j++){
            cout<<rows[i][j]<<" has been allotted row "<<i+1<<" seat "<<j+1<<endl;
        }
        cout<<endl;
    }

}
#include<iostream>
using namespace std;

class date
{
    public:
    int day=0;
    int month=0;
    int year=0;

    date(){};
    date(int d, int m, int y):day(d),month(m),year(y){};
};


void display(date arr[])
{
    for (int i=0;i<5;i++){
        cout<<"Date "<<i+1<<":"<<endl;
        cout<<arr[i].day<<"/"<<arr[i].month<<"/"<<arr[i].year<<endl<<endl;
    }
}


void selectSort(date arr[])
{
    for (int i=0;i<5;i++){
        int min = i;
        for (int j=i+1;j<5;j++){
            if (arr[j].year < arr[min].year){
                min = j;
            }
        }
        date temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int main()
{
    date arr[5];

    for (int i=0;i<5;i++){
        cout<<"Enter date "<<i+1<<" (dd/mm/yy): ";
        cin>>arr[i].day;
        cin>>arr[i].month;
        cin>>arr[i].year;
    }
    
    selectSort(arr);
    display(arr);

    return 0;
}
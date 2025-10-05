#include <iostream>
#include <vector>
using namespace std;

// int removeDuplicates(vector<int> &nums)
// {
//     vector<int> arr;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         bool unique = true;
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if (nums[i] == arr[j])
//             {
//                 unique = false;
//                 j = arr.size();
//             }
//         }
//         if (unique == true)
//         {
//             arr.push_back(nums[i]);
//             unique=false;
//         }
        
//     }

//     for (int i = 0; i < nums.size(); i++){
//         cout << nums[i];
        
//     }
    

// }

// int main()
// {
//     vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
//     // vector<int> nums = {1,1,2};
//     removeDuplicates(nums);
// }


int removeDuplicates(vector<int> &nums)
{
    if (nums.size()==1){
        return 0;
    }

    int j = 0;

    for (int i=1; i<nums.size(); i++){
        if (nums[i] != nums[j]){
            j++;
            nums[j] = nums[i];
        }
       
    }

    return j+1;

}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    // vector<int> nums = {1,1,2};
    removeDuplicates(nums);
}
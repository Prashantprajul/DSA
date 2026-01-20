#include<iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums.size()-i-1; j++)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

// Yet To Implement
void Recursive_BubbleSort(vector<int>& nums)
{

}

void SelectionSort(vector<int>& nums)
{

}

void InsertionSort(vector<int>& nums)
{

}

int main()
{
    // int n;
    // cout<<"Enter Size:";
    // cin>>n;
    vector<int> nums = {5, 2, 4, 6, 1, 3};
    // for(int i=0; i<nums.size(); i++)
    // {
    //     int k;
    //     cin>>k;
    //     nums.push_back(k);
    // }
    BubbleSort(nums);

    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;

}
#include<iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &nums, int lo, int mid, int hi) //Merge 2 sorted array 
{
    vector<int> tmp;

    int ptr1 = lo;
    int ptr2 = mid + 1;   

    while(ptr1 <= mid && ptr2 <= hi)  
    {
        if(nums[ptr1] <= nums[ptr2])
            tmp.push_back(nums[ptr1++]);
        else
            tmp.push_back(nums[ptr2++]);
    }

    while(ptr1 <= mid)
        tmp.push_back(nums[ptr1++]);

    while(ptr2 <= hi)
        tmp.push_back(nums[ptr2++]);

    for(int i = 0; i < tmp.size(); i++)
        nums[lo + i] = tmp[i];
}

void MergeSort(vector<int>& nums, int lo, int hi)
{
    if(lo<hi)
    {
        int mid = lo+(hi-lo)/2;
        MergeSort(nums, lo, mid);
        MergeSort(nums, mid+1, hi);

        Merge(nums, lo, mid, hi);
    }
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
    MergeSort(nums, 0, 5);

    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
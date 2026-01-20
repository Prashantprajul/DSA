#include<iostream>
using namespace std;

#pragma region Fixed size window

int Max_sum_subarray_of_size_K(vector<int>& nums, int k)
{
    int ans = INT_MIN, tmp = 0;
    if(k > nums.size())
        return -1;
    int front = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(i<k)
        {
            tmp += nums[i];
            continue;
        }
        else
        {
            ans = max(tmp, ans);
            tmp -= nums[front];
            tmp += nums[i];
            front++;
        }
    }
    return max(tmp, ans);
}

int Min_sum_subarray_of_size_K(vector<int>& nums, int k)
{
    int ans = INT_MAX, tmp = 0;
    if(k > nums.size())
        return -1;
    int front = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(i<k)
        {
            tmp += nums[i];
            continue;
        }
        else
        {
            ans = min(tmp, ans);
            tmp -= nums[front];
            tmp += nums[i];
            front++;
        }
    }
    return min(tmp, ans);
}

vector<int> First_Neg_in_WinSize_K(vector<int> nums, int k)
{

}

vector<int> Max_of_all_subarray_of_size_K(vector<int> nums, int k)
{

}


#pragma endregion

#pragma region  Variable window size

#pragma endregion


int main()
{
    // int n;
    // cout<<"Enter Size:";
    // cin>>n;

    //{2, 5, 1, 8, 2, 9, 1};
    vector<int> nums = {12, -1, -7, 8, -15, 30, 13, 28};

    // for(int i=0; i<nums.size(); i++)
    // {
    //     int k;
    //     cin>>k;
    //     nums.push_back(k);
    // }


    // int sum = Max_sum_subarray_of_size_K(nums, 3);
    //int sum = Min_sum_subarray_of_size_K(nums, 3);
    //cout<<sum;


    vector<int> ans;

    // for(int i=0;i<ans.size();i++)
    //     cout<<ans[i]<<" ";
    cout<<endl;
}
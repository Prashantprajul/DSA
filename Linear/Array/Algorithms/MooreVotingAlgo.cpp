#include<iostream>
using namespace std;

//NOTE : We cant find Elements exists exactly n/2 times

//If Element exists more than n/2 times
vector<int> MooresVotingAlgorithm(vector<int> nums)
{
    int cnt=0, curr=INT_MIN;
    for(auto it : nums)
    {
        if(cnt == 0)
            curr = it;
        if(it == curr)
            cnt++;
        else
            cnt--;
    }
    return {curr};
}

//If Element exists more than n/3 times
vector<int> MooresVotingAlgorithm3(vector<int> nums) //
{
    int n =nums.size();
    n/=3;
    ++n;

    int cnt1=0, curr1=INT_MIN;
    int cnt2=0, curr2=INT_MIN;
    for(auto it : nums)
    {
        if(cnt1 == 0 && it != curr2)
        {
            curr1 = it;
            cnt1++;
        }
        else if(cnt2 == 0 && it != curr1)
        {
            curr2 = it;
            cnt2++;
        }
        else if(it == curr1)
        {
            cnt1++;
        }
        else if(it == curr2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(auto it : nums)
    {
        if(it == curr1)
            cnt1++;
        if(it == curr2)
            cnt2++;
    }

    vector<int> ans;

    if(cnt1 >= n)
        ans.push_back(curr1);
    if(cnt2 >= n)
        ans.push_back(curr2);

    return ans;
}


int main()
{
    // int n;
    // cout<<"Enter Size:";
    // cin>>n;
    vector<int> nums = {5, 7, 7, 5, 5, 1, 5};
    // for(int i=0; i<nums.size(); i++)
    // {
    //     int k;
    //     cin>>k;
    //     nums.push_back(k);
    // }
    vector<int> ans;

    ans = MooresVotingAlgorithm(nums);
        cout<<"Elements occuring greater than n/2 times"<<ans[0];

    ans = MooresVotingAlgorithm3(nums);
    for(auto it : ans)
        cout<<"Elements occuring greater than n/3 times"<<ans[0]<<" "<<ans[1];
}
#include<iostream>
using namespace std;

int MooresVotingAlgorithm(vector<int> nums)
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
    return curr;
}

//If Element exists only n/2 times
//INCOMPLETE 
int MooresVotingAlgorithm2(vector<int> nums)
{
    int cnt=0 ,curr=INT_MIN;
    for(auto it : nums)
    {
        if(cnt == 0)
        {

        }
        if(it == curr)
            cnt++;
        else
            cnt--;
    }
    return curr;
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
    cout<<MooresVotingAlgorithm(nums);//Exists n/2 + 1 times
    // cout<<MooresVotingAlgorithm2(nums);
}
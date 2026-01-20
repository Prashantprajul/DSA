#include<iostream>
using namespace std;

void rotate(vector<int>& nums, int k) 
{
    int cnt=0,cycle=0,curr=0;
    int val=nums[0];
    int n=nums.size();
    while(cnt<n)
    {
        int nw=(curr+k)%n; // Index to be shifted
        int tmp=val;    //Stored value to be shifted in tmp var
        val=nums[nw];   //Stored the shifted position value in a new variable
        nums[nw]=tmp;
        cnt++;
        curr=nw;
        if(cycle==curr)
        {
            curr=(curr+1)%n;
            cycle=curr;
            val=nums[curr];
        }
    }
}

int main()
{
     // int n;
    // cout<<"Enter Size:";
    // cin>>n;
    vector<int> nums = {1, 2, 3, 4, 5, 6,};
    // for(int i=0; i<nums.size(); i++)
    // {
    //     int k;
    //     cin>>k;
    //     nums.push_back(k);
    // }
    rotate(nums, 2);

    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
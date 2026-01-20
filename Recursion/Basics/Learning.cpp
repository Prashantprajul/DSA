#include<iostream>
using namespace std;

void printn_1(int n) // Recursion call concept 
{
    if(n == 0)
        return;
    cout<<n<<" "; // when recursion continues to call
    printn_1(n-1);
    cout<<n<<" "; // after starting returning so the value comes in rev ie 1, 2, 3
}

int sum (int n)
{
    if(n == 1)
        return 1;
    return n + sum(n-1);
}

void fib(int n)
{
    
}

void rev(vector<int>& nums, int n, int i)
{
    if(i>=n)
        return;
    swap(nums[i],nums[n]);
    rev(nums, n-1, i+1);

}
bool ispal(string& st, int n, int i)
{
    if(i>=n)
        return true;
    if(st[n] != st[i])
        return false;
    return ispal(st, n-1, i+1);
}
int main()
{
    //printn_1(11);
    // cout << sum(5);

    // vector<int> nums = {5, 2, 4, 6, 1};
    // rev(nums, 4, 0);
    // for(int i=0;i<nums.size();i++)
    //     cout<<nums[i]<<" ";

    // string nums = "raca";
    // cout<<ispal(nums,4,0);

    fib(5);

    cout<<endl;
}
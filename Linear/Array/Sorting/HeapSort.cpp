#include<iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>& nums, int last, int i)
{
    while(true)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left<last && nums[left]>nums[largest])
            largest = left;
        if(right<last  && nums[right]>nums[largest])
            largest = right;
        
        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            i = largest;
        }
        else
            break;
    }
}
void HeapSort(vector<int>& nums)
{
    make_heap(nums.begin(), nums.end());
    //INSTEAD OF make_heap() WRITE THE LOGIC TO MAKE IT AS A HEAP
    // HOW TO CONVERT AN ARRAY TO A HEAP

    
    int n =nums.size();

    for(int i = n; i>1; i--)
    {
        swap(nums[0], nums[i-1]);
        Heapify(nums, i-1, 0);
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
    HeapSort(nums);

    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
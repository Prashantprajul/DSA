#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    //PART 1 --------------------------------------------------------
    //MAX HEAP STL 

    // priority_queue<int> pq;
    // pq.push(5);
    // pq.push(10);
    // pq.push(3); 
    // pq.push(2);
    // pq.push(11);
    // pq.emplace(55); // we can use it 
    // //But prefered to used in scenario when we are working with custom class
    // //Enhance performance by directly construct inside heap instead of creating a instance then copy/move -> heap

    // cout<<pq.size();
    // cout<<endl;

    // cout<<"Priority Queue is Empty?"<<pq.empty();
    // cout<<endl;

    // while(!pq.empty())
    // {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // cout<<endl;
    
    // cout<<"Priority Queue is Empty?"<<pq.empty();
    // cout<<endl;


    //PART 2 --------------------------------------------------------
    //MIN HEAP STL 


    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(10);
    pq.push(3); 
    pq.push(2);
    pq.push(11);
    pq.emplace(55); // we can use it 
    //But prefered to used in scenario when we are working with custom class
    //Enhance performance by directly construct inside heap instead of creating a instance then copy/move -> heap

    cout<<pq.size();
    cout<<endl;

    cout<<"Priority Queue is Empty?"<<pq.empty();
    cout<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    
    cout<<"Priority Queue is Empty?"<<pq.empty();
    cout<<endl;



    //PART 3 --------------------------------------------------------

    // vector<int> v={9,3,6,0,12,4,7,2};
    // make_heap(v.begin(), v.end());

    // for(auto it : v)
    //     cout<<it<<" ";
    // cout<<endl;


}
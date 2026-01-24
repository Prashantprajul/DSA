#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MinHeap{

private:
    vector<int> heap;

    void heapify_Up(int i)
    {
        while(i>0)
        {
            int parent = (i-1)/2;
            if(heap[parent] > heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapify_Down(int i)
    {
        int n = heap.size();
        while(true)
        {
            int left = 2*i+1;
            int right = 2*i+2;
            int smallest = i;

            if(left<n && heap[left]<heap[smallest])
                smallest = left;
            if(right<n && heap[right]<heap[smallest])
                smallest = right;
            
            if(smallest != i)
            {
                swap(heap[smallest], heap[i]);
                i = smallest;
            }
            else    
                break;
        }
    }
public:
    void push(int val)
    {
        heap.push_back(val);
        heapify_Up(heap.size()-1);
    }

    int pop()
    {
        if(heap.size() == 0)
        {
            cout<<"Heap is Empty"<<endl;
            return INT_MIN;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_Down(0);
        return min;
    }

    int getMin()
    {
        return heap.empty() ? -1 : heap[0];
    }

    int size()
    {
        return heap.size();
    }
    
    bool empty()
    {
        return heap.empty();
    }

    void PrintHeap()
    {
        for(auto it : heap)
            cout<<it<<" ";
        cout<<endl;
    }

    bool check()
    {
        int n = heap.size();
        for(int i=0; i<=heap.size()/2-1; i++)
        {
            int left = i*2+1;
            int right = i*2+2;
            if(left<n && heap[i] > heap[left])
                return false;
            if(right<n && heap[i] > heap[right])
                return false;
        }
        return true;
    }
};

class MaxHeap{
private:
    vector<int> heap;

    void heapify_Up(int i)
    {
        while(i>0)
        {
            int parent = (i-1)/2;
            if(heap[parent] < heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapify_Down(int i)
    {
        int n = heap.size();
        while(1)
        {
            int left = 2*i+1;
            int right = 2*i+2;
            int largest = i;

            if(left<n && heap[left]>heap[largest])
                largest = left;
            if(right<n && heap[right]>heap[largest])
                largest = right;
            
            if(largest != i)
            {
                swap(heap[largest], heap[i]);
                i = largest;
            }
            else   
                break;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        heapify_Up(heap.size()-1);
    }

    int pop()
    {
        if(heap.size() == 0)
        {
            cout<<"Heap is Empty"<<endl;
            return INT_MIN;
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_Down(0);
        return max;
    }

    int getMax()
    {
        return heap.empty() ? -1 : heap[0];
    }

    int size()
    {
        return heap.size();
    }

    bool empty()
    {
        return heap.empty();
    }
    
    void PrintHeap()
    {
        for(auto it : heap)
            cout<<it<<" ";
        cout<<endl;
    }

    bool check()
    {
        int n = heap.size();
        for(int i=0; i<heap.size()/2; i++)
        {
            int left = i*2+1;
            int right = i*2+2;
            if(left<n && heap[i] < heap[left])
                return false;
            if(right<n && heap[i] < heap[right])
                return false;
        }
        return true;
    }
};

int main() {
    MinHeap minH;
    minH.push(10);
    minH.push(4);
    minH.push(15);
    minH.push(2);

    minH.PrintHeap();      // 2 4 15 10
    cout << minH.pop() << endl; // 2

    MaxHeap maxH;
    maxH.push(10);
    maxH.push(4);
    maxH.push(15);
    maxH.push(2);

    maxH.PrintHeap();      // 15 4 10 2
    cout << maxH.pop() << endl; // 15
}

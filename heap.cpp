# include<bits/stdc++.h>
using namespace std;
class heap
{
    vector<int>v;
    bool minheap=true;
    bool compare(int p,int d)
    {
        if(minheap)
            return p>d;/// min heap
        else
            return d>p;/// max heap
    }
public:
    heap(bool type=true)
    {
        minheap=type;
        v.push_back(-1);
    }
    void push(int d)
    {   v.push_back(d);
        int index=v.size()-1;
        int parent=index/2;
        while(parent >=1 && compare(v[parent],v[index]))
        {
            swap(v[parent],v[index]);
            index=parent;
            parent=index/2;
        }
    }
    int top()
    {
        return v[1];
    }
    void heapify(int i)
    {
        int minindex=i;
        int left=i*2;
        int right=i*2+1;
        if(left <v.size() && compare(v[i],v[left]))
            minindex=left;
        if(right <v.size() && compare(v[minindex],v[right]))
            minindex=right;
        if(minindex!=i)
        {
            swap(v[i],v[minindex]);
            heapify(minindex);
        }
    }
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    bool isempty()
    {
        if(v.size()>1)
            return false;
        return true;

    }
};
int main()
{
    heap h(false);/// max heap now as default value is true ...see the constructor
    h.push(12);
    h.push(55);
    h.push(5);
    h.push(2);
    h.push(11);
    //cout<<h.top()<<endl;
    while(!h.isempty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }

}

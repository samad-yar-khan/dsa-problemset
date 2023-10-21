#include<bits/stdc++.h>
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    
    vector<NestedInteger> nestedList;
    vector<int> flatList;
    int index;
    
    void flatten(vector<NestedInteger> &l){
        int n = l.size();
        for(int i =0;i<n;i++){
            if(l[i].isInteger()){
                flatList.push_back(l[i].getInteger());
            }else{
                this->flatten(l[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = nestedList;
        vector<int>l(0);
        flatList = l;
        this->index =0;
        this->flatten(this->nestedList);
    }

    
    int next() {
        return flatList[this->index++];
    }
    
    bool hasNext() {
        return this->index < this->flatList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
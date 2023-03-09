#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void get(BinaryTreeNode<int> * root,map<int,int> &m ){
    if( root==NULL )
        return;
    
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});

    while( !q.empty() ){
        auto curr = q.front();
        auto *node = curr.first;
        int d = curr.second;
        q.pop();

        m[d] = node->data;
        if( node->left )
            q.push({node->left,d-1});
        if( node->right )
            q.push({node->right,d+1});
        
    }
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    map<int,int> m;
    get(root,m);

    for( auto elem : m ){
        ans.push_back(elem.second);
    }

    return ans;
    
}


int main()
{
  
  return 0;
}
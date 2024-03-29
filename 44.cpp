#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


 
    Node *lca(Node *root, int v1,int v2) {


    if( v1 > v2 ){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }
   
    while(1) {
        if( v1 <= root->data && root->data <= v2 ) {
            return root;
        }
        if( v1 < root->data ){
            root = root->left;
        }
        else {
            root = root->right;
       
    }
}
    }

};
int main() {
 
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;
    vector<int> a;
    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        a.push_back(data);
        root = myTree.insert(root, data);
    }
 
  int v1, v2;
  std::cin >> v1 >> v2;
    int f=0,g=0;
  for(int i=0;i<a.size();i++)
  {
      if(a[i]==v1)
      f=1;
      if(a[i]==v2)
      g=1;
  } 
  if(!f || !g)
  {
    cout<<-1;
   return 0;
  }
    Node *ans = myTree.lca(root, v1, v2);
  std::cout << ans->data;

    return 0;
}

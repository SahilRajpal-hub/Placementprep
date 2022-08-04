#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int data;
        Tree *left,*right;

        Tree(int d){
            data=d;
            left=right=NULL;
        }

        Tree* insert(int d, Tree* root){
            if(root==NULL){
                return new Tree(d);
            }
            if(d<root->data){
                root->left=insert(d,root->left);
            }else if(d>root->data){
                root->right=insert(d,root->right);
            }
            return root;
        }

        void preOrder(Tree* root){
            if(root==NULL) return;

            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }

        void inOrder(Tree* root){
            if(root==NULL) return;

            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }

        void postOrder(Tree* root){
            if(root==NULL) return;

            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }

        void levelOrder(Tree* root){
            if(root==NULL) return;
            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                Tree* node = q.front();
                q.pop();
                cout<<node->data<<" ";

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

        }

        void leftView(Tree* root){
            if(root==NULL) return;
            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                int n = q.size();

                for(int i=0; i<n; i++){
                    Tree* node = q.front();
                    q.pop();
                    if(i==0) cout<<node->data<<" ";

                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }

        void rightView(Tree* root){
            if(root==NULL) return;

            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                int n = q.size();

                for(int i=0; i<n; i++){
                    Tree* node = q.front();
                    q.pop();
                    if(i==n-1) cout<<node->data<<" ";

                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }

        void topView(Tree* root){
            if(root==NULL) return;
            map<int,int> mp;
            queue<pair<Tree*,int>> q;
            q.push({root,0});

            while(!q.empty()){
                auto fr = q.front();
                q.pop();
                int hd = fr.second;
                if(mp.count(hd)==0){
                    mp[hd]=fr.first->data;
                }
                if(fr.first->left) q.push({fr.first->left,hd-1});
                if(fr.first->right) q.push({fr.first->right,hd+1});
            }

            for(auto el:mp){
                cout<<el.second<<" ";
            }
        }
        
        void bottomView(Tree* root){
            if(root==NULL) return;
            map<int,int> mp;
            queue<pair<Tree*,int>> q;
            q.push({root,0});

            while(!q.empty()){
                auto fr = q.front();
                q.pop();
                int hd = fr.second;

                mp[hd]=fr.first->data;

                if(fr.first->left) q.push({fr.first->left,hd-1});
                if(fr.first->right) q.push({fr.first->right,hd+1});
            }

            for(auto el:mp){
                cout<<el.second<<" ";
            }
        }

        int maxDepth(Tree* root) {
            if(root==NULL) return 0;
            return 1+max(maxDepth(root->left),maxDepth(root->right));
        }

        Tree* BSTFromSortedArray(vector<int>& nums, int s, int e) {
            if(s>e) return NULL;
            int m = (s+e)/2;
            Tree* root = new Tree(nums[m]);
            root->left = BSTFromSortedArray(nums,s,m-1);
            root->right = BSTFromSortedArray(nums,m+1,e);
            return root;
        }

        
        
        void fun();
};

int main(){
    Tree *root;
    root=NULL;
    root=root->insert(4,root);
    root=root->insert(2,root);
    root=root->insert(3,root);
    root=root->insert(1,root);
    root=root->insert(6,root);
    root=root->insert(5,root);
    root=root->insert(7,root);
    root=root->insert(8,root);
    // root->preOrder(root); cout<<endl;
    // root->postOrder(root); cout<<endl;
    // root->inOrder(root); cout<<endl;
    root->levelOrder(root); cout<<endl;
    // root->leftView(root); cout<<endl;
    // root->rightView(root); cout<<endl;
    root->topView(root); cout<<endl;
    root->bottomView(root); cout<<endl;
    cout<<root->maxDepth(root)<<endl;
    return 0;
}
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

        // *** questions
        // *** 1. Maximum Depth of Binary Tree
        int maxDepth(Tree* root) {
            if(root==NULL) return 0;
            return 1+max(maxDepth(root->left),maxDepth(root->right));
        }

        // *** 2. Minimum Depth of Binary Tree
        int minDepth(Tree* root) {
        if(root==NULL) return 0;

        // ? if it is leaf node
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
        if(root->left==NULL){
            return 1+minDepth(root->right);
        }
        if(root->right==NULL){
            return 1+minDepth(root->left);
        }
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
        
        // *** 3. Diameter of BT
        int height(Tree* root){
            if(root==NULL) return 0;
            return 1+max(height(root->left),height(root->right));
        }
        int diameterOfBinaryTree(Tree* root) {
            if(root==NULL) return 0;
            
            int c1 = height(root->left) + height(root->right);
            int c2 = diameterOfBinaryTree(root->left);
            int c3 = diameterOfBinaryTree(root->right);
            
            return max(c1,max(c2,c3));
            
        }
        // ! optimised approach -> No need to go for diameter and height seprately
        int height(Tree* root, int &ans){
            if(root==NULL) return 0;
            int ld = height(root->left,ans);
            int rd = height(root->right,ans);
            ans = max(ans,ld+rd);
            return 1+max(ld,rd);
        }
        int diameterOfBinaryTree(Tree* root) {
            int ans = 0;
            height(root,ans);
            return ans;
        }

        // *** 4. Balanced Binary Tree
        int height(Tree* root){
            if(root==NULL) return 0;
            return 1+max(height(root->left),height(root->right));
        }
        bool isBalanced(Tree* root) {
            if(root==NULL) return true;
            return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
        }
        // ! optimised approach -> No need to go twice for height and child nodes check
        int height(Tree* root, bool &ans){
            if(root==NULL) return 0;
            int lh = height(root->left, ans);
            int rh = height(root->right, ans);
            ans = abs(lh-rh)<=1 && ans; 
            return 1+max(lh,rh);
        }
        bool isBalanced(Tree* root) {
            bool ans = true;
            height(root,ans);
            return ans;
        }

        // *** 5. is trees identical
        bool isSameTree(Tree* p, Tree* q) {
            if(p==NULL && q==NULL) return true;
            if(p==NULL || q==NULL) return false;
            
            return p->data==q->data && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }

        // *** 6. check sum tree
        int sum(Tree* root){
            if(root==NULL) return 0;
            return root->data+sum(root->left)+sum(root->right);
        }
        bool isSumTree(Tree* root)
        {
            if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
            return root->data==sum(root->left)+sum(root->right) && isSumTree(root->left) && isSumTree(root->right);
        }
        // ! optimised approach
        int sum(Tree* root, bool &ans){
            if(root==NULL) return 0;
            if(root->left==NULL && root->right==NULL) return root->data;
            int ls = sum(root->left,ans);
            int rs = sum(root->right,ans);
            ans = ans && ls+rs==root->data;
            return root->data+ls+rs;
        }
        bool isSumTree(Tree* root)
        {
            if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
            bool ans = true;
            sum(root,ans);
            return ans;
        }

        // *** Zig-zag traversal in binary tree
        vector<int> zigZagTraversal(Tree* root)
        {
            vector<int> ans;
            if(root==NULL) return ans;
            queue<Tree*> q;
            q.push(root);
            bool isLeftToRight = true;
            
            while(!q.empty()){
                vector<int> tmp;
                int size = q.size();
                for(int i=0; i<size; i++){
                    Tree* node = q.front();
                    q.pop();
                    tmp.push_back(node->data);
                    
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                if(isLeftToRight){
                    for(int i:tmp){
                        ans.push_back(i);
                    }
                }else{
                    reverse(tmp.begin(),tmp.end());
                    for(int i:tmp){
                        ans.push_back(i);
                    }
                }
                isLeftToRight = !isLeftToRight;
            }
            
            return ans;
        }

        // *** boundary of Binary tree
        vector<int> left(Tree* root){
            vector<int> ans;
            if(root==NULL) return ans;
            queue<Tree*> q;
            q.push(root);
            
            while(!q.empty()){
                int size = q.size();
                for(int i=0; i<size; i++){
                    Tree* node = q.front();
                    q.pop();
                    if(node->left==NULL && node->right==NULL) return ans;
                    if(i==0){
                        ans.push_back(node->data);
                    }
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            
            return ans;
        }
        void leaf(Tree* root,vector<int> &ans){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL){
                ans.push_back(root->data);
                return;
            }
            leaf(root->left,ans);
            leaf(root->right,ans);
        }
        vector<int> right(Tree* root){
            vector<int> ans;
            if(root==NULL) return ans;
            queue<Tree*> q;
            q.push(root);
            
            while(!q.empty()){
                int size = q.size();
                for(int i=0; i<size; i++){
                    Tree* node = q.front();
                    q.pop();
                    if(node->left==NULL && node->right==NULL) return ans;
                    if(i==size-1){
                        ans.push_back(node->data);
                    }
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            
            return ans;
        }
        vector<int> boundary(Tree* root)
        {
            if(root==NULL) return {};
            if(root->left==NULL && root->right==NULL) return {root->data};
            vector<int> leftNodes;
            if(root->left){
                leftNodes=left(root);
            }else leftNodes.push_back(root->data);
            
                
            vector<int>  leafNodes; 
            leaf(root,leafNodes);
            
            vector<int> rightNodes;
            if(root->right){
                rightNodes=right(root);
            }
            
            
            for(int i=0; i<leafNodes.size(); i++){
                leftNodes.push_back(leafNodes[i]);
            }
            
            for(int i=rightNodes.size()-1; i>0; i--){
                leftNodes.push_back(rightNodes[i]);
            }
            
            return leftNodes;
        }

        // *** Vertical Traversal of Binary Tree
        vector<int> verticalOrder(Tree *root)
        {
            if(root==NULL) return {};
            queue<pair<int,Tree*>> q;
            vector<pair<int,Tree*>> tmp;
            q.push({0,root});
            vector<int> ans;
            
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                tmp.push_back(node);
                if(node.second->left) q.push({node.first-1,node.second->left});
                if(node.second->right) q.push({node.first+1,node.second->right});
            }
            stable_sort(tmp.begin(),tmp.end(), [](const auto &a,const auto &b){
                return a.first<b.first;
            });
            for(auto p:tmp){
                ans.push_back(p.second->data);
            }
            return ans;
        }
        // *** Leetcode version of this question -> Vertical Order Traversal of a Binary Tree
        vector<vector<int>> verticalTraversal(Tree* root) {
            if(root==NULL) return {};
            queue<pair<pair<int,int>,Tree*>> q;
            map<pair<int,int>,vector<int>> tmp;
            q.push({{0,0},root});
            vector<vector<int>> ans;
            
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                tmp[{node.first.first,node.first.second}].push_back(node.second->data);
                if(node.second->left) q.push({{node.first.first-1,node.first.second+1},node.second->left});
                if(node.second->right) q.push({{node.first.first+1,node.first.second+1},node.second->right});
            }
            map<int,vector<int>> mp;
            
            for(auto p:tmp){
                sort(p.second.begin(),p.second.end());
                for(int i:p.second){
                    mp[p.first.first].push_back(i);
                }
            }
            
            for(auto p:mp){
                ans.push_back(p.second);
            }
            
            return ans;
        } 

        // *** diagonal traversal of binary tree
        vector<int> diagonal(Tree *root)
        {
            vector<int> ans;
            if(root==NULL){
            return ans;
            }
            queue<Tree*> q;
            q.push(root);
            
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                
                while(node){
                    ans.push_back(node->data);
                    if(node->left) q.push(node->left);
                    node = node->right;
                }
            }
            
            return ans;
        }

        // *** Sum of the Longest Bloodline of a Tree
        int ans = 0;
        int maxDist = 0;
        void solve(Tree* root, int dist, int tmp){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL){
                if(dist+1>maxDist){
                    ans = tmp+root->data;
                    maxDist=dist+1;
                }
            }
            if(root->right) solve(root->right,dist+1,tmp+root->data);
            if(root->left) solve(root->left,dist+1,tmp+root->data);
        }
        int sumOfLongRootToLeafPath(Tree *root)
        {
            solve(root,0,0);
            return ans;
        }
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
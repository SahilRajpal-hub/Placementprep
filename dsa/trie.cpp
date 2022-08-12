#include <bits/stdc++.h>
using namespace std;

// *** Complexities
// ? -> Operation    TC       SC
// ? #  Insert      O(M)     O(26*M*N)
// ? #  Search      O(M)     O(1)
class Trie{
    public:
        Trie* children[26];
        bool isEndOfWord;

        Trie(){
            isEndOfWord=false;
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
        }

        void insert(string s, Trie* root){
            for(int i=0; i<s.length(); i++){
                int idx = s[i]-'a';
                if(root->children[idx]==NULL){
                    root->children[idx] = new Trie();
                }
                root = root->children[idx];
            }
            root->isEndOfWord = true;
        }

        bool search(string s, Trie* root){
            for(int i=0; i<s.length(); i++){
                int idx = s[i] - 'a';
                if(root->children[idx]==NULL){
                    return false;
                }
                root = root->children[idx];
            }
            return root->isEndOfWord;
        }
};

// *** Longest Common Prefix
bool single(Trie* root, char &c){
    int count = 0;
    for(int i=0; i<26; i++){
        if(root->children[i]!=NULL){
            count++;
            c=(char)(i+'a');
        }
        if(count>1) return false;
    }
    return count==1;
}
string longestCommonPrefix(vector<string>& strs) {
    Trie* root = new Trie();
    for(string s:strs){
        if(s=="") return s;
        root->insert(s,root);
    }
    string ans = "";
    while(root){
        char c;
        if(single(root,c)){
            ans += c;
        }else return ans;
        root=root->children[c-'a'];
        if(root->isEndOfWord) return ans;
    }
    return ans;
}


int main(){
    Trie* root = new Trie();
    root->insert("abc",root);
    root->insert("abcd",root);
    root->insert("ab",root);
    cout<<root->search("abc",root)<<endl;
    cout<<root->search("abd",root)<<endl;
    cout<<root->search("abcd",root)<<endl;
    cout<<root->search("a",root)<<endl;
    cout<<root->search("ab",root)<<endl;
    return 0;
}
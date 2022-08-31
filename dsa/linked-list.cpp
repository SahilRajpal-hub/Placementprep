#include <bits/stdc++.h>
using namespace std;

// *** linked list-> https://leetcode.com/problems/add-two-numbers/discuss/1340/A-summary-about-how-to-solve-Linked-List-problem-C%2B%2B

class Node{

    public:

    int data;
    Node* next;
    Node* random; // just for a single question -> copy a linked list with random pointer
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    void insert(Node* &head, int data){
        if(head->next==NULL){
            Node* temp = new Node(data);
            head->next=temp;
            return;
        }
        insert(head->next,data);
    }

    void fastInsert(Node* &tail, int data){
        Node* temp = new Node(data);
        tail->next=temp;
        tail=tail->next;
    }

    void insertAtKthPosition(Node* &head, int data, int k){
        Node* tmp=head;
        while(--k>0){
            tmp=tmp->next;
        }
        Node* tm = tmp->next;
        Node* newNode = new Node(data);
        tmp->next=newNode;
        newNode->next=tm;
    }

    void print(Node* head){
        if(head==NULL) return;
        cout<<head->data<<" ";
        print(head->next);
    }

    // *** reverse a linked list
    Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node *curr=head,*prev=NULL;
        
        while(curr){
            Node *temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    // *** find middle of linked list
    Node* middleNode(Node* head) {
        if(head==NULL) return NULL;
        Node *slow=head,*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    // *** reverse nodes is k group
    Node* reverseKGroup(Node* head, int k) {
        Node* temp = head;
        int K=k;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        if(n<k) return head;
        
        Node *curr=head,*prev=NULL;
        while(curr && k--){
            Node *temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head->next=reverseKGroup(curr,K);
        return prev;
    }

    // *** detect cycle
    bool hasCycle(Node *head) {
        if(head==NULL || head->next==NULL) return false;
        if(head==head->next) return true;
        Node *slow=head,*fast=head;
        
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }

    // *** detect loop and remove it
    void removeLoop(Node* head)
    {
        Node *slow=head,*fast=head;
        Node* prev = NULL;
        while(slow && fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow!=fast) return;
        fast=head;
        while(slow!=fast){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=NULL;
    }

    // *** Remove Duplicates from Sorted List
    Node* deleteDuplicates(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *prev=head,*curr=head->next;
        while(curr){
            if(prev->data==curr->data){
                prev->next=curr->next;
                curr=curr->next;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }

    // *** merge two sorted list (recursive approach)
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->data<=list2->data){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }else if(list1->data>list2->data){
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        
        return NULL;
    }

    // *** Given a linked list of 0s, 1s and 2s, sort it.
    Node* segregate(Node *head) {
        int nz=0,no=0,nt=0;
        Node *tmp=head;
        while(tmp){
            if(tmp->data==0) nz++;
            else if(tmp->data==1) no++;
            else nt++;
            tmp=tmp->next;
        }
        tmp = head;
        while(nz--){
            tmp->data=0;
            tmp=tmp->next;
        }
        while(no--){
            tmp->data=1;
            tmp=tmp->next;
        }
        while(nt--){
            tmp->data=2;
            tmp=tmp->next;
        }
        return head;
    }                                                                           

    // *** check palindrome in linked list
    // *** with O(N) TC and O(N) SC
    bool isPalindrome(Node* head) {
        if(head==NULL || head->next==NULL) return true;
        if(head->next->next==NULL){
            return head->data==head->next->data;
        }
        vector<int> v;
        Node* tmp = head;
        int n = 0;
        while(tmp){
            v.push_back(tmp->data);
            tmp=tmp->next;
            n++;
        }
        for(int i=0; i<n; i++){
            if(v[i]!=v[n-i-1]) return false;
        }
        return true;
    }

    // *** with O(N) TC and O(1) SC
    bool isPalindrome(Node* head) {
        Node *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->data != slow->data) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }

    // *** Add Two Numbers
    // *** 1. recursive code
    void addNumber(Node* l1, Node* l2, int c,Node* tmp){
        if(l1==NULL && l2==NULL){
            if(c!=0) tmp->next=new Node(c);
            return;
        }
        
        int sum = (l1==NULL?0:l1->data) + (l2==NULL?0:l2->data) + c;
        int carry = sum/10;
        
        tmp->next=new Node(sum%10);
        tmp=tmp->next;
        
        addNumber(l1!=NULL?l1->next:l1,l2!=NULL?l2->next:l2,carry,tmp);
    }
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *head=new Node(0); // giving dummy value
        Node *tmp=head;
        addNumber(l1,l2,0,tmp);
        return head->next;    // removing dummy value
    }
    // *** 2. iterative code
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *head=new Node(0); // giving dummy value
        Node *tmp=head;
        
        int sum = 0;
        int carry = 0;
        while(l1 || l2){
            sum = (l1==NULL?0:l1->data) + (l2==NULL?0:l2->data) + carry;
            carry = sum/10;
            tmp->next=new Node(sum%10);
            tmp=tmp->next;
            l1!=NULL?l1=l1->next:l1=NULL;
            l2!=NULL?l2=l2->next:l2=NULL;
        }
        if(carry!=0) tmp->next=new Node(carry);
        
        return head->next;    // removing dummy value
    }

    // *** clone a linked list with random pointer
    // *** 1. With TC = O(N) and SC = O(N)
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        map<Node*,Node*> mp;
        Node* hh = new Node(head->data);
        mp[head]=hh;
        Node *tmp = hh;
        Node *thead = head->next;
        while(thead){
            tmp->next = new Node(thead->data);
            tmp = tmp->next;
            mp[thead]=tmp;
            thead = thead->next;
        }
        tmp=hh;
        thead=head;
        while(thead){
            Node *rt = mp[thead->random];
            tmp->random = rt;
            thead = thead->next;
            tmp = tmp->next;
        }
        
        return hh;
    }
    //  TODO : 2. with TC = O(N) and SC = O(1) 

    // *** merge sort in linked list
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->data<=list2->data){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }else if(list1->data>list2->data){
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        
        return NULL;
    }
    Node* sortList(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node *slow=head,*fast=head,*temp=slow;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        
        return mergeTwoLists(sortList(head),sortList(slow));
    }
};

int main(){
    Node* head = new Node(1);
    Node* tail=head;
    tail->fastInsert(tail,2);
    tail->fastInsert(tail,3);
    tail->fastInsert(tail,4);
    tail->fastInsert(tail,5);
    tail->fastInsert(tail,6);
    tail->insertAtKthPosition(head,7,6);
    head->print(head);
    return 0;
}
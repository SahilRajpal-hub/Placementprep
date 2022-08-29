#include <bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* next;
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
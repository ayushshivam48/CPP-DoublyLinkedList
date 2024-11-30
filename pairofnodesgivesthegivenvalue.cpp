#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Node{

    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }

};

class Doublyll{

    public:
    Node* head;
    Node* tail;

    Doublyll(){
        head=NULL;
        tail=NULL;
    }

    void display(){

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtStart(int val){

        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtEnd(int val){

        Node* new_node = new Node(val);  
        if(tail==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void insertAtPosition(int val , int k){

        Node* temp = head;
        int count = 1;
        while(count<k-1){
            temp = temp->next;
            count++;
        }

        //temp will be pointing to the node at (k-1)th position
        Node* new_node = new Node(val);  
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
        }

};


bool isCriticalPoint(Node* &currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val) //local maxima
        return true;
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val) //local minima
        return true;

    return false;
}

vector<int> pairSumDll(Node* head, Node* tail , int x){

    vector<int> ans(2,-1);
    while(head != tail){
        int sum = head->val + tail->val;
        if(sum == x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }

        if(sum > x){  // i need smaller values, i will move tail back
            tail = tail->prev;
        } else {  // i need bigger values, i will move head forward
            head = head->next;
        }
    }
    return ans;
}
    

int main(){

    Doublyll dll;
    dll.insertAtEnd(2);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.insertAtEnd(8);
    dll.insertAtEnd(10);
    dll.display();
   vector<int> ans = pairSumDll(dll.head,dll.tail,11);
    cout<<ans[0]<<" "<<ans[1]<<endl;

}
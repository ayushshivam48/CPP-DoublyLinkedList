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

vector<int> distanceBetweenCriticalPoints(Node* head, Node* tail){

    vector<int> ans(2,INT_MAX);
    int firstCP = -1, lastCP = -1;

    Node* currNode = tail->prev;
    if(currNode==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }

    int currPos = 0;
    while(currNode->prev!=NULL){
        if(isCriticalPoint(currNode)){
            if(firstCP==-1){
                firstCP = lastCP = currPos;
            }else{
                ans[0] = min(ans[0],currPos-lastCP); //min distance
                ans[1] = currPos - firstCP; //max distance
                lastCP = currPos;
            }
        }
        currPos++;
        currNode = currNode->prev;
    }

    if(ans[0]==INT_MAX){
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main(){

    Doublyll dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(5);
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);
    dll.display();
   vector<int> ans = distanceBetweenCriticalPoints(dll.head,dll.tail);
    cout<<ans[0]<<" "<<ans[1]<<endl;

}
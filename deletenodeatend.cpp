#include<iostream>
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

    void deleteAtStart(){

        if(head==NULL){
            return;
        }

        Node* temp = head;
        head = head->next;
        if(head==NULL){  // if doubly ll had omly one node
            tail=NULL;
        }else{
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtEnd(){

        if(head==NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if(tail==NULL){  // if doubly ll had omly one node
            head=NULL;
        }else{
           tail->next = NULL;
        }
        free(temp);
        return;
    }

};


int main(){

    Doublyll dll;
    dll.insertAtStart(3);
    dll.insertAtStart(2);
    dll.insertAtStart(1);
    dll.display();
    dll.insertAtEnd(5);
    dll.display();
    dll.insertAtPosition(4,4);
    dll.display();
    dll.deleteAtStart();
    dll.display();
    dll.deleteAtEnd();
    dll.display();

}
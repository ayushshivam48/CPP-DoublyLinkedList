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

};


int main(){

    Node* new_node = new Node(3);

    Doublyll dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout<<dll.head->val<<endl;

}
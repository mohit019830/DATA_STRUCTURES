#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
class DLL{
    Node *head;
    Node *tail;
public:
    DLL(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node *newNode=new Node(val);
        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is empty!!";
        }else{
            Node *temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(tail==NULL){
            cout<<"List is empty!!";
        }else{
            Node *temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }
    void printall(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void printrev(){
        Node *temp=tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
};

int main(){
    DLL l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.pop_back();
    l1.pop_front();
    l1.printall();
    cout<<endl;
    l1.printrev();
    return 0;
}
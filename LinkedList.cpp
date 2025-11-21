#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next=NULL;
    }

};
 
class List{
    Node *head;
    Node *tail;
public:
    List(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    
    void push_back(int val){
        Node *newNode= new Node(val);
        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printall(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    
    void pop_back(){
        if(tail==NULL){
            cout<<"The list is empty!!"<<endl;
        }else{
            Node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
        }
    }
    
    void pop_front(){
        if(head==NULL){
            cout<<"The list is empty!!"<<endl;
        }else{
            Node *temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void insert(int val,int pos){
        Node *newNode=new Node(val);
        Node *temp=head;
        if(pos<0){
            cout<<"Invalid Position"<<endl;
        }else if(pos==0){
            push_front(val);
        }else{
            for(int i=1;i<pos;i++){
                if(temp==NULL){
                    cout<<"Invalid Position"<<endl;
                }
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    int search(int val){
        Node *temp=head;
        int idx=0;
        while(temp->next!=NULL){
            if(temp->data==val){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
        return -1;
    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.insert(4,0);
    // ll.printall();
    cout<<ll.search(3);

    return 0;
} 
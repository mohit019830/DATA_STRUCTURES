#include<iostream>
using namespace std;

class Node{
public:
    int coeff,power;
    Node *next;

    Node(int coeff,int power){
        this->coeff = coeff;
        this->power=power;
        next=NULL;
    }

};
 
class List{
public:
    void add(int coeff, int pow){
        Node *newNode=new Node(coeff,pow);
        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node *head;
    Node *tail;
    List(){
        head=tail=NULL;
    }
    
    void input(){
        List l1;
        int coeff,pow;
        cin>>coeff>>pow;
        while(pow>=0){
            l1.add(coeff,pow);
            cin>>coeff>>pow;
        }
        List l2;
        int coeff2,pow2;
        cin>>coeff2>>pow2;
        while(pow2>=0){
            l2.add(coeff2,pow2);
            cin>>coeff2>>pow2;
        }
        List l3;
        Node *temp1=l1.head;
        Node *temp2=l2.head;
        while(temp1->next!=NULL){
            while(temp2->next!=NULL){
                if(temp1->power==temp2->power){
                    temp1->coeff+=temp2->coeff;
                }
                temp2=temp2->next;
            }
            temp2=l2.head;
            temp1=temp1->next;
            l3.add(temp1->coeff,temp1->power);
        }
        l3.printall();
    }
    void printall(){
        Node *temp=head;
        while(temp->next!=NULL){
            cout<<temp->coeff<<"x^"<<temp->power<<"+";
            temp=temp->next;
        }
        cout<<temp->coeff<<"x^"<<temp->power;
    }

};

int main(){
    List ll;
    ll.input();
    return 0;
} 
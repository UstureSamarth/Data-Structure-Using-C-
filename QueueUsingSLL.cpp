#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Node{
public:
    Node *prev;
    Node *next;
    int data;
    Node(){
        this->prev=NULL;
        this->next=NULL;
        this->data=0;
    }
};

class Queue{
private:
    Node *rear,*front;
public:
    Queue()
    {
        this->front=NULL;
        this->rear=NULL;
    }

    void push(int value);
    void pop();
    int peek();
    void display();
};

void Queue::push(int value)
{
    Node *node=new Node;
    node->data=value;

    if(this->rear==NULL){
        this->rear=node;
        this->front=node;
    }else{
        node->next=this->rear;
        this->rear->prev=node;
        this->rear=node;
    }
}
void Queue::pop()
{
    if(this->front==NULL){
        cout<<"Queue is empty"<<endl;
        getch();
    }else{
        Node *temp=this->front;
        if(this->front==this->rear){
            this->front=NULL;
            this->rear=NULL;
        }else{
            temp->prev->next=NULL;
            this->front=temp->prev;
        }
        delete temp;
    }

}
int Queue::peek()
{
    if(this->rear==NULL)
        return -1;
    return this->front->data;
}
void Queue::display()
{
    if(this->front==NULL)
        cout<<"Queue is empty";
    else{
        Node *temp=this->front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
}

int main()
{
    Queue q;
    while(1)
   {
       system("cls");
       if(q.peek()!=-1)
        cout<<"Top element is "<<q.peek()<<endl;
       q.display();
       cout<<"\n1.Push\n2.Pop\n3.Exit\n";
       int ch,val,index;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data:";
            cin>>val;
            q.push(val);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout<<"Enter any key to exit";
            getch();
            exit(0);
            break;
        default:
            cout<<"Enter Valid Choice\n";
            cout<<"Press any key to continue";
            getch();
       }

   }

}

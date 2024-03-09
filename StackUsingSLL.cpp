#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;


class Node
{
    public:
        Node()
        {
            this->next=NULL;
        }
        int data;
        Node *next;

};

class Stack
{
private:
    Node *head;
public:
    Stack()
    {
        head=NULL;
    }
    ~Stack()
     {
        delete head;
     }
    void push(int data);
    void pop();
    int peek();
    void display();
};


int Stack::peek()
{
    if(this->head==NULL)
        return -1;
    return this->head->data;
}

void Stack::push(int data)
{
    Node *node=new Node;
    node->data=data;
    node->next=this->head;
    this->head=node;
}
void Stack::pop()
{
    if(this->head==NULL){
        cout<<"Stack is empty"<<endl;
        getch();
    }
    else
    {
        Node *node=this->head;
        this->head=node->next;
        delete node;
    }
}
void Stack::display()
{
    if(this->head==NULL)
        cout<<"Stack is empty";
    else{
        Node *temp=this->head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
}
int main()
{
    Stack s;
    while(1)
   {
       system("cls");
       if(s.peek()!=-1)
            cout<<"Top element is "<<s.peek()<<endl;
       s.display();
       cout<<"\n1.Push\n2.Pop\n3.Exit\n";
       int ch,val,index;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to Push:";
            cin>>val;
            s.push(val);
            break;
        case 2:
            s.pop();
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

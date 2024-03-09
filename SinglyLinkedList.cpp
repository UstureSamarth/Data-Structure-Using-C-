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

class SinglyLinkedList
{
private:
    Node *head;
public:
    SinglyLinkedList()
    {
        head=NULL;
    }
    void insertAtFirst(int data);
    void deleteAtFirst();
    void insertAtLast(int data);
    void deleteAtLast();
    Node* search(int data);
    void insertAfter(int searchData, int newData);
    void deleteparticular(int data);
    void view();
    void edit(int data);
};

void SinglyLinkedList::edit(int data)
{
    Node *node=this->search(data);
    if(node)
    {
       int newData;
       cout<<"Enter new data:";
       cin>>newData;
       node->data=newData;
    }
    else
        cout<<"Item not found"<<endl;
}
void SinglyLinkedList::view()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *node=this->head;
        while(node)
        {
            cout<<node->data<<" ";
            node=node->next;
        }
    }
}
Node* SinglyLinkedList::search(int data)
{
    if(this->head==NULL)
        return NULL;
    Node *node=this->head;
    while(node)
    {
        if(node->data==data)
            return node;
        node=node->next;
    }
    return NULL;
}
void SinglyLinkedList::insertAtFirst(int data)
{
    Node *node=new Node;
    node->data=data;
    node->next=this->head;
    this->head=node;
}
void SinglyLinkedList::deleteAtFirst()
{
    if(this->head==NULL)
        cout<<"LinkedList is empty"<<endl;
    else
    {
        Node *node=this->head;
        this->head=node->next;
        delete node;
    }
}
void SinglyLinkedList::insertAtLast(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    if(this->head==NULL)
        this->head=newNode;
    else
    {
        Node *node=this->head;
        while(node->next)
            node=node->next;
        node->next=newNode;
    }

}
void SinglyLinkedList::deleteAtLast()
{

    if(this->head==NULL)
        cout<<"LinkedList is empty"<<endl;
    else
    {
        Node *front=this->head;
        Node *back=this->head;
        while(front->next)
        {
            back=front;
            front=front->next;
        }
        if(front==back)
            this->head=NULL;
        else
            back->next=NULL;
        delete front;

    }
}
void SinglyLinkedList::insertAfter(int searchData, int newData)
{
    Node *node=this->search(searchData);
    if(node)
    {
        Node *newNode=new Node;
        newNode->data=newData;
        newNode->next=node->next;
        node->next=newNode;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
}
void SinglyLinkedList::deleteparticular(int data)
{
    Node *node=this->search(data);
    if(node)
    {
        Node *temp=this->head;
        if(temp==node)
            this->head=node->next;
        else
        {
            while(temp->next!=node)
                temp=temp->next;
            temp->next=node->next;
        }

        delete node;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
}
int main()
{
    SinglyLinkedList sLL;
    while(1)
   {
       system("cls");
       sLL.view();
       cout<<"\n1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.InsertAfter\n6.DeleteParticular\n7.Edit\n8.Exit\n";
       int ch,val,data,newData;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to InsertAtFirst:";
            cin>>val;
            sLL.insertAtFirst(val);
            break;
        case 2:
            cout<<"Enter Data to InsertAtLast:";
            cin>>val;
            sLL.insertAtLast(val);
            break;
        case 3:
            sLL.deleteAtFirst();
            break;
        case 4:
            sLL.deleteAtLast();
            break;
        case 5:
            cout<<"Enter data to which InsertAfter:";
            cin>>data;
            cout<<"Enter data to Insert:";
            cin>>newData;
            sLL.insertAfter(data,newData);
            break;
        case 6:
            cout<<"Enter data to which DeleteParticular:";
            cin>>data;
            sLL.deleteparticular(data);
            break;
        case 7:
            cout<<"Enter data to edit:";
            cin>>data;
            sLL.edit(data);
            break;
        case 8:
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

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Node
{
    public:
        Node()
        {
            this->prev=NULL;
            this->next=NULL;
        }
        Node *prev;
        int data;
        Node *next;

};

class DoublyLinkedList
{
private:
    Node *head;
public:
    DoublyLinkedList()
    {
        this->head=NULL;
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
void DoublyLinkedList::edit(int data)
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
void DoublyLinkedList::view()
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
void DoublyLinkedList::insertAtFirst(int data)
{
    Node *node=new Node;
    node->data=data;
    node->next=this->head;
    if(this->head!=NULL)
        this->head->prev=node;
    this->head=node;
}

void DoublyLinkedList::deleteAtFirst()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp=this->head;
        if(temp->next!=NULL)
            temp->next->prev=NULL;
        this->head=temp->next;
        delete temp;
    }
}

void DoublyLinkedList::insertAtLast(int data)
{
    Node *node=new Node;
    node->data=data;
    if(this->head==NULL)
        this->head=node;
    else
    {
        Node *temp=this->head;
        while(temp->next)
            temp=temp->next;
        node->prev=temp;
        temp->next=node;
    }
}

void DoublyLinkedList::deleteAtLast()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp=this->head;
        if(temp->next==NULL)
            this->head=NULL;
        else
        {
            while(temp->next)
              temp=temp->next;
            temp->prev->next=NULL;
        }
        delete temp;
    }
}
Node* DoublyLinkedList::search(int data)
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
void DoublyLinkedList::insertAfter(int searchData, int newData)
{
    Node *node=this->search(searchData);
    if(node)
    {
        Node *newNode=new Node;
        newNode->data=newData;

        newNode->next=node->next;
        newNode->prev=node;

        if(node->next!=NULL)
            node->next->prev=newNode;
        node->next=newNode;
    }
    else
        cout<<"Item not found"<<endl;
}

void DoublyLinkedList::deleteparticular(int data)
{
    Node *node=this->search(data);
    if(node)
    {
        Node *temp=this->head;
        if(temp==node)
        {
            this->head=node->next;
            if(node->next!=NULL)
                node->next->prev=NULL;
        }
        else
        {
            if(node->next!=NULL)
                node->next->prev=node->prev;
            if(node->prev!=NULL)
                node->prev->next=node->next;
        }

        delete node;
    }
    else
        cout<<"Item not found"<<endl;
}

int main()
{
    DoublyLinkedList dLL;
    while(1)
   {
       system("cls");
       dLL.view();
       cout<<"\n1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.InsertAfter\n6.DeleteParticular\n7.Edit\n8.Exit\n";
       int ch,val,data,newData;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to InsertAtFirst:";
            cin>>val;
            dLL.insertAtFirst(val);
            break;
        case 2:
            cout<<"Enter Data to InsertAtLast:";
            cin>>val;
            dLL.insertAtLast(val);
            break;
        case 3:
            dLL.deleteAtFirst();
            break;
        case 4:
            dLL.deleteAtLast();
            break;
        case 5:
            cout<<"Enter data to which InsertAfter:";
            cin>>data;
            cout<<"Enter data to Insert:";
            cin>>newData;
            dLL.insertAfter(data,newData);
            break;
        case 6:
            cout<<"Enter data to which DeleteParticular:";
            cin>>data;
            dLL.deleteparticular(data);
            break;
        case 7:
            cout<<"Enter data to edit:";
            cin>>data;
            dLL.edit(data);
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

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

class CircularDoublyLinkedList
{
private:
    Node *head;
public:
    CircularDoublyLinkedList()
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
void CircularDoublyLinkedList::edit(int data)
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
    {
        cout<<"Item not found"<<endl;
        getch();
    }

}
void CircularDoublyLinkedList::view()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *node=this->head;
        cout<<node->data<<" ";
        node=node->next;
        while(node!=this->head)
        {
            cout<<node->data<<" ";
            node=node->next;
        }
    }
}
void CircularDoublyLinkedList::insertAtFirst(int data)
{
    Node *node=new Node;
    node->data=data;
    if(this->head==NULL)
    {
        node->prev=node;
        node->next=node;
        this->head=node;
    }
    else
    {
        node->next=this->head;
        node->prev=this->head->prev;
        this->head->prev->next=node;
        this->head->prev=node;
        this->head=node;
    }

}

void CircularDoublyLinkedList::deleteAtFirst()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp=this->head;
        if(temp->next==this->head)
            this->head=NULL;
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            this->head=temp->next;
        }

        delete temp;
    }
}

void CircularDoublyLinkedList::insertAtLast(int data)
{
    Node *node=new Node;
    node->data=data;
    if(this->head==NULL)
    {
        node->prev=node;
        node->next=node;
        this->head=node;
    }
    else
    {
        Node *temp=this->head;
        node->prev=temp->prev;
        node->next=temp;
        temp->prev->next=node;
        temp->prev=node;
    }
}

void CircularDoublyLinkedList::deleteAtLast()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp=this->head;

        if(this->head==temp->next)
            this->head=NULL;
        else
        {
            temp=temp->prev;
            temp->prev->next=this->head;
            this->head->prev=temp->prev;
        }

        delete temp;
    }
}

Node* CircularDoublyLinkedList::search(int data)
{
    if(this->head==NULL)
        return NULL;

    Node *node=this->head;
    if(node->data==data)
        return node;
    node=node->next;
    while(node!=this->head)
    {
        if(node->data==data)
             return node;
        node=node->next;

    }

    return NULL;
}

void CircularDoublyLinkedList::insertAfter(int searchData, int newData)
{
    Node *node=this->search(searchData);
    if(node)
    {
        Node *newNode=new Node;
        newNode->data=newData;

        newNode->next=node->next;
        newNode->prev=node->prev;
        node->next=newNode;

    }
    else
    {
        cout<<"Item not found"<<endl;
        getch();
    }

}

void CircularDoublyLinkedList::deleteparticular(int data)
{
    Node *node=this->search(data);

    if(node)
    {
        if(node->next==node)
            this->head=NULL;
        else if(node->prev==this->head->prev)
        {
            node->next->prev=node->prev;
            node->prev->next=node->next;
            this->head=node->next;
        }
        else
        {
            node->next->prev=node->prev;
            node->prev->next=node->next;
        }

        delete node;
    }
    else
    {
        cout<<"Item not found"<<endl;
        getch();
    }

}

int main()
{
    CircularDoublyLinkedList cdLL;
    while(1)
   {
       system("cls");
       cdLL.view();
       cout<<"\n1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.InsertAfter\n6.DeleteParticular\n7.Edit\n8.Exit\n";
       int ch,val,data,newData;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to InsertAtFirst:";
            cin>>val;
            cdLL.insertAtFirst(val);
            break;
        case 2:
            cout<<"Enter Data to InsertAtLast:";
            cin>>val;
            cdLL.insertAtLast(val);
            break;
        case 3:
            cdLL.deleteAtFirst();
            break;
        case 4:
            cdLL.deleteAtLast();
            break;
        case 5:
            cout<<"Enter data to which InsertAfter:";
            cin>>data;
            cout<<"Enter data to Insert:";
            cin>>newData;
            cdLL.insertAfter(data,newData);
            break;
        case 6:
            cout<<"Enter data to which DeleteParticular:";
            cin>>data;
            cdLL.deleteparticular(data);
            break;
        case 7:
            cout<<"Enter data to edit:";
            cin>>data;
            cdLL.edit(data);
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

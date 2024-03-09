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

class CircularLinkedList
{
private:
    Node *head;
public:
    CircularLinkedList()
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
void CircularLinkedList::edit(int data)
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

void CircularLinkedList::view()
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

void CircularLinkedList::insertAtFirst(int data)
{
    Node *node=new Node;
    node->data=data;
    if(this->head==NULL)
    {
        node->next=node;
        this->head=node;
    }
    else
    {
        Node *temp=this->head;
        while(temp->next!=this->head)
            temp=temp->next;
        node->next=this->head;
        temp->next=node;
        this->head=node;
    }
}

void CircularLinkedList::deleteAtFirst()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp=this->head;
        if(this->head==this->head->next)
            this->head=NULL;
        else
        {
            Node *temp2=this->head;
            while(temp2->next!=this->head)
              temp2=temp2->next;
            temp2->next=temp->next;
            this->head=temp->next;
            delete temp;

        }
    }
}

void CircularLinkedList::insertAtLast(int data)
{
    Node *node=new Node;
    node->data=data;
    if(this->head==NULL)
    {
        node->next=node;
        this->head=node;
    }
    else
    {
        Node *temp=this->head;
        while(temp->next!=this->head)
            temp=temp->next;
        node->next=temp->next;
        temp->next=node;
    }
}
void CircularLinkedList::deleteAtLast()
{
    if(this->head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        Node *temp1=this->head;
        if(this->head==this->head->next)
            this->head=NULL;
        else
        {
            Node *temp2=this->head;
            while(temp1->next!=this->head)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=temp1->next;
        }
        delete temp1;
    }
}

Node* CircularLinkedList::search(int data)
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

void CircularLinkedList::insertAfter(int searchData, int newData)
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
        cout<<"Item not found"<<endl;
}

void CircularLinkedList::deleteparticular(int data)
{
    Node *node=this->search(data);
    if(node)
    {
        Node *temp=this->head;
        if(this->head==this->head->next)
            this->head=NULL;
        else if(temp==node)
        {
            while(temp->next!=this->head)
                temp=temp->next;
            temp->next=node->next;
            this->head=node->next;
        }
        else
        {
            while(temp->next!=node)
                temp=temp->next;
            temp->next=node->next;
        }

        delete node;
    }
    else
        cout<<"Item not found"<<endl;
}

int main()
{
    CircularLinkedList cLL;
    while(1)
   {
       system("cls");
       cLL.view();
       cout<<"\n1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.InsertAfter\n6.DeleteParticular\n7.Edit\n8.Exit\n";
       int ch,val,data,newData;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to InsertAtFirst:";
            cin>>val;
            cLL.insertAtFirst(val);
            break;
        case 2:
            cout<<"Enter Data to InsertAtLast:";
            cin>>val;
            cLL.insertAtLast(val);
            break;
        case 3:
            cLL.deleteAtFirst();
            break;
        case 4:
            cLL.deleteAtLast();
            break;
        case 5:
            cout<<"Enter data to which InsertAfter:";
            cin>>data;
            cout<<"Enter data to Insert:";
            cin>>newData;
            cLL.insertAfter(data,newData);
            break;
        case 6:
            cout<<"Enter data to which DeleteParticular:";
            cin>>data;
            cLL.deleteparticular(data);
            break;
        case 7:
            cout<<"Enter data to edit:";
            cin>>data;
            cLL.edit(data);
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

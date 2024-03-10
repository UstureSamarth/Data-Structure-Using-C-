#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Deque{
private:
    int *ptr,rear,front,capacity;
public:
    Deque(int capacity){
        this->capacity=capacity;
        this->rear=-1;
        this->front=-1;
        this->ptr= new int[this->capacity];
    }
    ~Deque(){
        delete[] ptr;
    }
   void insertionAtRear(int val);
   void insertionAtFront(int val);
   void deletionAtRear();
   void deletionAtFront();
   int getFront();
   int getRear();
};

void Deque::insertionAtRear(int val)
{
    if((this->front==0 && this->rear==this->capacity-1) || this->rear+1==this->front)
    {
        cout<<"Deque is full"<<endl;
        getch();
    }else
    {
         if(this->rear==-1)
        {
            this->rear=0;
            this->front=0;
        }else if(this->rear==this->capacity-1)
            this->rear=0;
        else
            this->rear+=1;
        this->ptr[this->rear]=val;
    }
}

void Deque::insertionAtFront(int val)
{
    if((this->front==0 && this->rear==this->capacity-1) || this->rear+1==this->front)
    {
        cout<<"Deque is full"<<endl;
        getch();
    }else
    {
         if(this->front==-1)
        {
            this->rear=0;
            this->front=0;
        }else if(this->front==0)
            this->front=this->capacity-1;
        else
            this->front-=1;
        this->ptr[this->front]=val;
    }
}

void Deque::deletionAtRear()
{
    if(this->rear==-1)
    {
        cout<<"Deque is empty"<<endl;
        getch();
    }else if(this->rear==this->front)
    {
        this->rear=-1;
        this->front=-1;
    }else if(this->rear==0)
        this->rear=this->capacity-1;
    else
        this->rear-=1;
}

void Deque::deletionAtFront()
{
    if(this->front==-1)
    {
        cout<<"Deque is empty"<<endl;
        getch();
    }else if(this->rear==this->front)
    {
        this->rear=-1;
        this->front=-1;
    }else if(this->front==this->capacity-1)
      this->front=0;
    else
        this->front+=1;
}

int Deque::getFront()
{
    if(this->front==-1)
        return -1;
    return this->ptr[this->front];
}

int Deque::getRear()
{
    if(this->rear==-1)
        return -1;
    return this->ptr[this->rear];
}

int main()
{
    int n;
    cout<<"Enter Size of Queue : ";
    cin>>n;
    Deque q(n);
    while(1)
   {
       system("cls");
       cout<<"Size of Deque is "<<n<<endl;
       if(q.getFront()!=-1)
        cout<<"Element at Front is "<<q.getFront()<<endl;
       if(q.getRear()!=-1)
        cout<<"Element at Rear is "<<q.getRear()<<endl;
       cout<<"\n1.InsertAtRear\n2.InsertAtFront\n3.DeleteAtRear\n4.DeleteAtFront\n5.Exit\n";
       int ch,val,index;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data:";
            cin>>val;
            q.insertionAtRear(val);
            break;
        case 2:
            cout<<"Enter Data:";
            cin>>val;
            q.insertionAtFront(val);
            break;
        case 3:
            q.deletionAtRear();
            break;
        case 4:
            q.deletionAtFront();
            break;
        case 5:
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

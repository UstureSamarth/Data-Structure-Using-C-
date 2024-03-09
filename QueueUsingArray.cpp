#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Queue{
private:
    int *ptr,rear,front,capacity;
public:
    Queue(int capacity){
        this->capacity=capacity;
        this->rear=-1;
        this->front=-1;
        this->ptr= new int[this->capacity];
    }
    ~Queue(){
        delete[] ptr;
    }
    void push(int value);
    void pop();
    int peek();
    void display();
};

void Queue::push(int value)
{
    if((this->front==0 && this->rear==this->capacity-1) || (this->rear+1==this->front)){
        cout<<"Queue is full"<<endl;
        getch();
    }else
    {
        if(this->rear==-1){
            this->front+=1;
            this->rear+=1;
        }else if(this->rear==this->capacity-1)
            this->rear=0;
        else
            this->rear+=1;
        this->ptr[this->rear]=value;
    }
}

void Queue::pop()
{
    if(this->front==-1){
        cout<<"Queue is empty"<<endl;
        getch();
    }else
    {
        if(this->rear==this->front){
            this->front=-1;
            this->rear=-1;
        }else if(this->front==this->capacity-1)
            this->front=0;
        else
            this->front+=1;
    }
}
int Queue::peek()
{
    if(this->front==-1)
        return -1;
    return this->ptr[this->front];
}
void Queue::display() {
    if (front == -1)
        cout << "Queue is empty" << endl;
    else {
        cout << "Queue elements: ";
        int i = front;
        do {
            cout << ptr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
}
int main()
{
    int n;
    cout<<"Enter Size of Queue : ";
    cin>>n;
    Queue q(n);
    while(1)
   {
       system("cls");
       cout<<"Size of Queue is "<<n<<endl;
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

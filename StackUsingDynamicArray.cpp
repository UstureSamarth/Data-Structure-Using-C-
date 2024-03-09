#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Stack{
private:
    int *ptr,lastindex,capacity;
public:
    Stack(int capacity){
        this->capacity=capacity;
        this->lastindex=-1;
        this->ptr= new int[this->capacity];
    }
     ~Stack()
     {
        delete[] ptr;
     }
    int getCapacity();
    void doubleArray();
    void halfArray();
    void push(int value);
    void pop();
    int peek();
    void display();
};

int Stack::getCapacity()
{
    return this->capacity;
}
void Stack::doubleArray()
{
    int newCapacity = (this->capacity) * 2;
    if (newCapacity == 0)
        newCapacity = 1;

    int *temp=new int[newCapacity];
    for(int i=0;i<=(this->lastindex);i++)
            temp[i]=(this->ptr[i]);
    delete[] this->ptr;
    this->ptr=temp;
    this->capacity=newCapacity;
}

void Stack::halfArray()
{
    int newCapacity = (this->capacity) / 2;
    if (newCapacity == 0)
        newCapacity = 1;
    int *temp=new int[newCapacity];
    for(int i=0;i<=(this->lastindex);i++)
            temp[i]=(this->ptr[i]);
    delete[] this->ptr;
    this->ptr=temp;
    this->capacity=newCapacity;
}

void Stack::push(int value)
{
    if(this->lastindex==(this->capacity)-1)
        this->doubleArray();
    this->lastindex+=1;
    this->ptr[this->lastindex]=value;

}


int Stack::peek()
{
    if(this->lastindex==-1)
        return -1;
    return this->ptr[this->lastindex];

}
void Stack::pop()
{
    if(this->lastindex==-1){
        cout<<"Stack is empty"<<endl;
        getch();
    }
    else
    {
        this->lastindex-=1;
        if((this->lastindex+1)<=(this->capacity)/2)
            this->halfArray();
    }
}

void Stack::display()
{
    if(this->lastindex==-1)
        cout<<"Stack is empty"<<endl;
    else
        for(int i=this->lastindex;i>=0;i--)
            cout<<this->ptr[i]<<" ";
}

int main()
{
    Stack s(2);
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

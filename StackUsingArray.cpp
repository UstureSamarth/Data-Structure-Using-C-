#include<iostream>
#include<stdlib.h>
using namespace std;

class Stack
{
private:
    int *ptr,lastindex,capacity;
public:
    Stack(int capacity)
    {
        this->capacity=capacity;
        this->lastindex=-1;
        this->ptr= new int[this->capacity];
    }
    ~Stack()
     {
        delete[] ptr;
     }
    void push(int value);
    void pop();
    int peek();
    void display();
};

void Stack::push(int value)
{
    if(this->lastindex==(this->capacity)-1)
    {
        cout<<"Stack is full"<<endl;
        cin.ignore();
        cin.get();
    }
    else
    {
        this->lastindex+=1;
        this->ptr[this->lastindex]=value;
    }
}
void Stack::pop()
{
    if(this->lastindex==-1)
    {
        cout<<"Stack is empty"<<endl;
        cin.ignore();
        cin.get();
    }
    else
        this->lastindex-=1;
}

int Stack::peek()
{
    if(this->lastindex==-1)
        return -1;
    return this->ptr[this->lastindex];
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
    int n;
    cout<<"Enter Size of Stack :";
    cin>>n;
    Stack s(n);
    while(1)
   {
       system("cls");
       cout<<"Size of stack is "<<n<<endl;
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
            cin.ignore();
            cin.get();
            exit(0);
            break;
        default:
            cout<<"Enter Valid Choice\n";
            cout<<"Press any key to continue";
            cin.ignore();
            cin.get();
       }

   }

}

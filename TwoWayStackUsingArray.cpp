#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class TWStack{
private:
    int *ptr,top1,top2,capacity;
public:
    TWStack(int capacity){
        this->capacity=capacity;
        this->top1=-1;
        this->top2=capacity;
        this->ptr= new int[this->capacity];
    }
    void push1(int value);
    void push2(int value);
    void pop1();
    void pop2();
    int peek1();
    int peek2();
    void view1();
    void view2();
};

void TWStack::push1(int value)
{
    if(this->top1==this->capacity-1 || this->top2==0 || this->top1+1==this->top2)
    {
        cout<<"Stack is full"<<endl;
        getch();
    }
    else
    {
        this->top1+=1;
        this->ptr[this->top1]=value;
    }
}
void TWStack::push2(int value)
{
    if(this->top1==this->capacity-1 || this->top2==0 || this->top1+1==this->top2)
    {
        cout<<"Stack is full"<<endl;
        getch();
    }
    else
    {
        this->top2-=1;
        this->ptr[this->top2]=value;
    }
}

void TWStack::pop1()
{
    if(this->top1==-1 && this->top2==this->capacity)
    {
        cout<<"Stack is empty"<<endl;
        getch();
    }
    else if(this->top1==-1)
    {
        cout<<"Stack1 is empty"<<endl;
        getch();
    }
    else
        this->top1-=1;
}

void TWStack::pop2()
{
    if(this->top1==-1 && this->top2==this->capacity)
    {
        cout<<"Stack is empty"<<endl;
        getch();
    }
    else if(this->top2==this->capacity)
    {
        cout<<"Stack2 is empty"<<endl;
        getch();
    }
    else
        this->top2+=1;
}

int TWStack::peek1()
{
    if(this->top1==-1)
        return -1;
    return this->ptr[this->top1];
}

int TWStack::peek2()
{
    if(this->top2==this->capacity)
        return -1;
    return this->ptr[this->top2];
}

void TWStack::view1()
{
    if(this->top1==-1)
        cout<<"Stack1 is empty"<<endl;
    else
        for(int i=this->top1;i>=0;i--)
            cout<<this->ptr[i]<<" ";
}
void TWStack::view2()
{
    if(this->top2==this->capacity)
        cout<<"Stack2 is empty"<<endl;
    else
        for(int i=this->top2;i<=this->capacity-1;i++)
            cout<<this->ptr[i]<<" ";
}

int main()
{
    TWStack st(5);
    while(1)
   {
       system("cls");
       if(st.peek1()!=-1)
        cout<<"Top1 is "<<st.peek1()<<endl;
       st.view1();
       cout<<endl;
       if(st.peek2()!=-1)
        cout<<"Top2 is "<<st.peek2()<<endl;
       st.view2();
       cout<<endl;
       cout<<"\n1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Exit\n";
       int ch,val,index;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to Append:";
            cin>>val;
            st.push1(val);
            break;
        case 2:
            cout<<"Enter Data to Append:";
            cin>>val;
            st.push2(val);
            break;
        case 3:
            st.pop1();
            break;
        case 4:
            st.pop2();
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

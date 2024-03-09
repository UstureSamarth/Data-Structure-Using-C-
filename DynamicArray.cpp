#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class DynamicArray{
private:
    int *ptr,lastindex,capacity;
public:
    DynamicArray(int capacity){
        this->capacity=capacity;
        this->lastindex=-1;
        this->ptr= new int[this->capacity];
    }
    void append(int value);
    void insert(int index,int value);
    void edit(int index,int value);
    void deleteitem(int index);
    void doubleArray();
    void halfArray();
    void view();
    int getCapacity();
};

int DynamicArray::getCapacity()
{
    return this->capacity;
}
void DynamicArray::doubleArray()
{
    int *temp=new int[(this->capacity)*2];
    for(int i=0;i<=(this->lastindex);i++)
            temp[i]=(this->ptr[i]);
    delete this->ptr;
    this->ptr=temp;
    this->capacity=(this->capacity)*2;
}

void DynamicArray::halfArray()
{
    int *temp=new int[(this->capacity)/2];
    for(int i=0;i<=(this->lastindex);i++)
            temp[i]=(this->ptr[i]);
    delete this->ptr;
    this->ptr=temp;
    this->capacity=(this->capacity)/2;
}

void DynamicArray::append(int value)
{
    if(this->lastindex==(this->capacity)-1)
        this->doubleArray();
    this->lastindex+=1;
    this->ptr[this->lastindex]=value;

}
void DynamicArray::insert(int index,int value)
{

    if(index<0 || index >(this->lastindex+1))
        cout<<"Invalid Index"<<endl;
    else
    {
        if(this->lastindex==(this->capacity)-1)
            this->doubleArray();

        for(int i=(this->lastindex);i>=index;i--)
            this->ptr[i+1]=this->ptr[i];
        this->ptr[index]=value;
        this->lastindex+=1;
    }

}

void DynamicArray::edit(int index,int value)
{
    if(index<0 || index >(this->lastindex+1))
        cout<<"Invalid Index"<<endl;
    else
        this->ptr[index]=value;

}
void DynamicArray::deleteitem(int index)
{
    if(this->lastindex==-1)
        cout<<"Array is empty"<<endl;
    else if(index > (this->lastindex))
        cout<<"Invalid Index";
    else
    {
        for(int i=index;i<(this->lastindex);i++)
            this->ptr[i]=this->ptr[i+1];
        this->lastindex-=1;
        if((this->lastindex+1)<=(this->capacity)/2)
            this->halfArray();
    }
}
void DynamicArray::view()
{
    for(int i=0;i<=this->lastindex;i++)
        cout<<this->ptr[i]<<" ";
}

int main()
{
    DynamicArray arr(2);
    while(1)
   {
       system("cls");
       cout<<"Size of Array is "<<arr.getCapacity()<<endl;
       arr.view();
       cout<<"\n1.Append\n2.Insert\n3.Delete\n4.Edit\n5.Exit\n";
       int ch,val,index;
       cout<<"Enter Your Choice:";
       cin>>ch;
       switch(ch)
       {
        case 1:
            cout<<"Enter Data to Append:";
            cin>>val;
            arr.append(val);
            break;
        case 2:
            cout<<"Enter index to which Value is entered:";
            cin>>index;
            cout<<"Enter Value:";
            cin>>val;
            arr.insert(index,val);
            break;
        case 3:
            cout<<"Enter Index of value to delete:";
            cin>>index;
            arr.deleteitem(index);
            break;
        case 4:
            cout<<"Enter Index to Edit:";
            cin>>index;
            printf("Enter Value:");
            cin>>val;
            arr.edit(index,val);
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

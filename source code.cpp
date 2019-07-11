///CIRCULAR QUEUE USING TEMPLATES 
/// IMPLEMENTING OOPS
#include<iostream>
#include<stdlib.h>
using namespace std;

template<class Type>
class Queue
{
Type s[10];
int rear,front,n;
public:
Queue()
{
cout<<"\n\tEnter the Queue Size : ";
cin>>n;
rear=front=n-1;
}
void insert(Type elt)
{
if((rear+1)%n!=front)
{
rear=(rear+1)%n;
s[rear]=elt;
}
else
cout<<"\n\tQueue is full.Can't insert "<<elt<<endl;
}
void remove()
{
if(front==rear)
cout<<"\n\tQueue is empty.\n";
else
{
front=(front+1)%n;
cout<<"\n\tRemoved elt : "<<s[front];
}
}
void que_operation();
void display();
};
template<class Type>
void Queue<Type> :: display()
{
if(rear!=front)
{
cout<<"\n\t\tQueue Content :\n\n\t";
for(int i=(front+1)%n;;i=(i+1)%n)
{
cout<<s[i]<<"\t";
if(i==rear) break;
}
}
else
cout<<"\n\tEmpty Queue Can't Be Print\n";
}
template<class Type>
void Queue<Type> :: que_operation()
{
int choice=1,i;
Type elt;
while(choice>0 && choice<3)
{
cout<<"\n\n\t1.Insert\t2.Remove\tAny Key To Exit\n\tChoice : ";
cin>>choice;
switch(choice)
{
case 1 : //insert
cout<<"\n\tEnter the Elt to insert : ";
cin>>elt;
insert(elt);
display();
break;
case 2 : //remove
remove();
display();
break;
}
}
}
int main()
{	
cout<<"\n\t\tQUEUE OPERATION USING TEMPLATE\n\n";
cout<<"\n\t INT\n";
Queue<int> que1;
cout<<"\n\t FLOAT\n";
Queue<float> que2;
int ch;
while(1)
{
cout<<"\n\t\t\tQUEUE OPERATION \n\n";
cout<<"\t1.INT QUEUE\t2.FLOAT QUEUE\tAny Key To Exit\n\tChoice : ";
cin>>ch;
switch(ch)
{
case 1 : //perform queue operation on int queue
que1.que_operation();
break;
case 2 : //float
que2.que_operation();
break;
default : exit(0);
}
}
return 0;
}

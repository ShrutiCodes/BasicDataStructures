//============================================================================
// Name        : Assignment5.cpp
// Author      : Shruti
// Roll No.    : 21168
// Description : Binary Number Implementation using Doubly Linked Lists
//============================================================================

#include <iostream>
using namespace std;
class Node
{
   bool no;
   Node *prev;
   Node *next;
public:
   Node()
    {
	  no = 0;
	  prev = NULL;
	  next = NULL;
    }
   Node(bool b)
   {
	   no = b;
	   prev = NULL;
	   next = NULL;
   }
  friend class DLL;
};
class DLL
{
	Node *start;
public:
	DLL()
    {
		start=NULL;
	}
	void Accept(int m);
	void Insert(bool b);
	int ConvBD();
	void Display();
	DLL Cmp1s();
	DLL Cmp2s();
	DLL Add(DLL *d);
};
void DLL :: Accept(int m)
{
	int d;
	bool r;
	if(m!=0)
	   d=1;
	else
	{
	 do{
	 cout<<"Enter a decimal number \n";
	 cin>>d;
	 if(d<0){
		 cout<<"Cannot accept negative numbers!\n Enter again! \n";
		 continue;
	 }
	 }while(d<0);
	}
	do
	{
		r=d%2;
		Insert(r);
		d=d/2;
	}while(d>=1);
}
void DLL :: Insert(bool b)
{
	Node *new1 = new Node(b);
	if(start==NULL)
	   start=new1;
	else
	    {
		  new1->next=start;
		  start->prev=new1;
		  start=new1;
	    }
}
int DLL :: ConvBD()
{
	int D=0;
	Node *q = start;
	while(q!=NULL)
	{
		D=(D<<1)+q->no;
		q=q->next;
	}
	return D;

}
void DLL :: Display()
{
	Node *q = start;
	cout<<"Binary: ";
	while(q!=NULL)
	{
		cout<<q->no;
		q=q->next;
	}
	cout<<endl;
    cout<<"Decimal: "<<ConvBD()<<endl;
}
DLL DLL :: Cmp1s()
{
	DLL d;
	bool b;
	Node *q = start;
	while(q->next!=NULL)
		q=q->next;
    while(q!=NULL)
    {
    	if(q->no==1)
    		{
    		  b=0;
    		  d.Insert(b);
    		}
    	else if(q->no==0)
    		{
    		  b=1;
    		  d.Insert(b);
    		}
    	q=q->prev;
    }
    return d;
}
DLL DLL :: Add(DLL *d5)
{
	DLL d;
	Node *p1=start, *p2=d5->start;
	bool sum=0,carry=0,b;

	while(p1->next!=NULL)
	  p1=p1->next;
	while(p2->next!=NULL)
	  p2=p2->next;

	while((p1!=NULL)&&(p2!=NULL))
	{
      sum=((p1->no)^(p2->no));
      sum=(sum^carry);
      carry=((p1->no&p2->no)|(p1->no&carry)|(p2->no&carry));

      d.Insert(sum);
      p1=p1->prev;
      p2=p2->prev;
	}

	while(p1!=NULL)
	{
		if(carry==1)
		{
		  b=(carry^p1->no);
		  d.Insert(b);
			  if(p1->no==1)
				  carry=1;
			  else
				  carry=0;
		}
		else
		  d.Insert(p1->no);
	    p1=p1->prev;
	}
	while(p2!=NULL)
    {
		if(carry==1)
		{
		  b=(carry^p2->no);
		  d.Insert(b);

	      cout<<carry<<"c";

		  if(p2->no==1)
			  carry=1;
		  else
			  carry=0;
		}
		else
	     d.Insert(p2->no);
	   p2=p2->prev;
	}
	if(carry==1)
		d.Insert(carry);
	return d;
}
DLL DLL :: Cmp2s()
{
	DLL *d4,d3;
	d4=new DLL;
	d4->Accept(1);
	d3=Cmp1s();
	d3=d3.Add(d4);
	return d3;
}
int main() {
	cout<<"  BINARY NUMBER OPERATIONS  \n";
	DLL d1,d3, *d2;
	d1.Accept(0);
	d1.Display();
    int x;
    do{
    	cout<<"\nEnter: \n1 to find 1's Complement \n2 to find 2's Complement \n3 to Add two numbers \n4 to Exit \n";
    	cin>>x;
    	switch(x)
    	{
    	  case 1: d3=d1.Cmp1s();
    	          cout<<"1's complement :";
    	          d3.Display();
                  break;
    	  case 2: d3=d1.Cmp2s();
    		      cout<<"2's complement:";
    		      d3.Display();
    	          break;
    	  case 3: d2=new DLL;
    		      d2->Accept(0);
    	          d2->Display();
    	          cout<<"Addition is: "<<endl;
    	          d3=d1.Add(d2);
    	          d3.Display();
    	          delete d2;
    		      break;
    	  case 4: break;
    	  default: cout<<"INVALID option! Enter another! \n";
    	}
    }while(x!=4);
	return 0;
}
/*
 OUTPUT
   BINARY NUMBER OPERATIONS
Enter a decimal number
4
Binary: 100
Decimal: 4

Enter:
1 to find 1's Complement
2 to find 2's Complement
3 to Add two numbers
4 to Exit
1
1's complement :Binary: 011
Decimal: 3

Enter:
1 to find 1's Complement
2 to find 2's Complement
3 to Add two numbers
4 to Exit
2
2's complement:Binary: 100
Decimal: 4

Enter:
1 to find 1's Complement
2 to find 2's Complement
3 to Add two numbers
4 to Exit
3
Enter a decimal number
12
Binary: 1100
Decimal: 12
Addition is:
1cBinary: 10000
Decimal: 16

Enter:
1 to find 1's Complement
2 to find 2's Complement
3 to Add two numbers
4 to Exit
4
 */

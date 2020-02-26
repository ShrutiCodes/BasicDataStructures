//============================================================================
// Name        : Assignment6.cpp
// Author      : Shruti
// Roll No.    : 21168
// Description : Polynomial using Circular Linked List
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
class Term
{
	int c;
	int e;
	Term *next;
public:
	Term(){
		c=0;
		e=0;
		next=NULL;
	}
	Term(int c1, int e1){
		c=c1;
		e=e1;
	    next=NULL;
	}
friend class Poly;
};
class Poly
{
	Term *last;
public:
	Poly(){
		last=NULL;
	}
	void Create(int, int);
	void Display();
	int Evaluate(int y);
	Poly PolyAdd(Poly P2);
};
void Poly :: Create(int c1, int e1)
{
	Term *new1 = new Term(c1,e1);

	if(last==NULL){
		    last=new1;
			last->next=last;
		}
		else{
			new1->next=last->next;
			last->next=new1;
			last=new1;
		}
}

void Poly :: Display()
{
	Term *p=last;

    if(last==NULL)
		cout<<"\nList Empty!";
    else if(last->next==last)
		cout<<p->c<<"x^"<<p->e;
	else{
		p=p->next;
		while(p!=last)
		{
		  if(p->e==0)
			  cout<<p->c<<"+";
		  else if(p->c==1)
			  cout<<"x^"<<p->e<<"+";
		  else
		      cout<<p->c<<"x^"<<p->e<<" + ";
		  p=p->next;
		}
		if(p->e==0)
		  cout<<p->c;
		else if(p->c==1)
		  cout<<"x^"<<p->e;
		else
		  cout<<p->c<<"x^"<<p->e;
	  }
}

int Poly :: Evaluate(int y)
{
	int sum=0;
	Term *p=last->next;
	while(p!=last){
	 sum+=p->c*pow(y,p->e);
	 p=p->next;
	}
	sum+=p->c*pow(y,p->e);
	p=p->next;
	return sum;
}

Poly Poly :: PolyAdd(Poly P2)
{
	int f1=0, f2=0;
	Poly temp;
	Term *p = last->next;
	Term *q = P2.last->next;

	while((f1==0) && (f2==0)){
		  if(p==last)
			  f1=1;
		  if(q==P2.last)
			  f2=1;
		  if(p->e==q->e){
			temp.Create(p->c+q->c,p->e);
			p=p->next;
			q=q->next;
		  }
		  else if(p->e > q->e){
			  temp.Create(p->c,p->e);
			  p=p->next;
		  }
		  else if(q->e > p->e){
			  temp.Create(q->c,q->e);
			  q=q->next;
		  }
	}

	while(f1==0){
		if(p==last)
			f1=1;
		temp.Create(p->c,p->e);
	    p=p->next;
	}

	while(f2==0){
		if(q==P2.last)
			f2=1;
		temp.Create(q->c,q->e);
		q=q->next;
	}

	return temp;
}
int main() {
	int x,y,z,co,ex,n;
	Poly P1,P2,P3;
	cout<<"Enter number of terms in 1st polynomial ";
	cin>>n;
	for(int i=0;i<n;i++){
    cout<<"Enter exponent ";
    cin>>ex;
    cout<<"Enter coefficient ";
    cin>>co;
	P1.Create(co,ex);
	}
	P1.Display();
	do
	{
		cout<<"\nEnter: \n1 to Evaluate \n2 to Add two polynomials \n3 to Exit\n";
		cin>>x;
		switch(x)
		{
		  case 1: cout<<"Enter value of x to evaluate for \n";
		          cin>>y;
		          z = P1.Evaluate(y);
		          cout<<"Value of polynomial for "<<y<<" = "<<z;
		          break;
		  case 2: cout<<"Enter number of terms in 2nd polynomial: ";
		          cin>>n;
		          for(int i=0;i<n;i++){
		            cout<<"Enter exponent ";
		            cin>>ex;
		            cout<<"Enter coefficient ";
		            cin>>co;
		            P2.Create(co,ex);
		          }
		          P3 = P1.PolyAdd(P2);
		          P3.Display();
		          break;
		  case 3: break;
		  default: cout<<"INVALID menu number! Please enter again! \n";
		}
	}while(x!=3);
	return 0;
}
/*    OUTPUT
 * Enter number of terms in 1st polynomial 3
Enter exponent 3
Enter coefficient 2
Enter exponent 2
Enter coefficient 4
Enter exponent 1
Enter coefficient 2
2x^3 + 4x^2 + 2x^1
Enter:
1 to Evaluate
2 to Add two polynomials
3 to Exit
1
Enter value of x to evaluate for
2
Value of polynomial for 2 = 36
Enter:
1 to Evaluate
2 to Add two polynomials
3 to Exit
2
Enter number of terms in 2nd polynomial: 3
Enter exponent 2
Enter coefficient 1
Enter exponent 1
Enter coefficient 4
Enter exponent 0
Enter coefficient 2
2x^3 + 5x^2 + 6x^1 + 2
Enter:
1 to Evaluate
2 to Add two polynomials
3 to Exit
3
 */
 */

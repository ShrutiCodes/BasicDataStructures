//============================================================================//
// Name        : Assignment4.cpp
// Author      : Shruti
// Roll no     : 21168
// Description : Linked list : Pinaccle club
//============================================================================//
#include <iostream>
using namespace std;
class Node
{
   int PRN;
   string name;
   Node *next;
public:
   Node()
   {
	 PRN=0;
	 name="Name";
	 next=NULL;
   }
   Node(int P, string N)
   {
	   PRN=P;
	   name=N;
	   next=NULL;
   }
   void Accept();
   friend class Pinaccle;
};
class Pinaccle
{
	Node *start;
public:
	Pinaccle()
     {
	   start=NULL;
     }
	Pinaccle(int p, string s)
	{
		start = new Node();
		start->PRN=p;
		start->name=s;
		start->next=NULL;
	}
	void Display();
	bool revstart();
	void DisplayReverse(Node *t);
    void InsertPresident();
    void InsertSecretary();
    void InsertMember();
    void DeleteMember();
    void DeletePresident();
    void DeleteSecretary();
    void Total();
    void Sort();
    void Concatenate(Pinaccle &PC);
};
void Node :: Accept()
{
	cout<<"Enter PRN ";
	cin>>PRN;
	cout<<"Enter name ";
	cin>>name;
	next=NULL;
}
void Pinaccle :: Display()
{
	cout<<(start->PRN)<<endl;
	cout<<(start->name)<<endl;
	Node *q=start->next;
	if(q!=NULL)
	 {
		while(q->next!=NULL)
  	     {
	  	   cout<<q->PRN<<endl;
		   cout<<q->name<<endl;
		   q=q->next;
	     }
	   cout<<q->PRN<<endl;
	   cout<<q->name<<endl;
	 }
}
bool Pinaccle :: revstart()
{
   if(start==NULL)
       return false;
   Node *temp=start;
   DisplayReverse(temp);
       return true;
}
void Pinaccle :: DisplayReverse(Node *t)
{
	if(t==NULL)
			return;
		else
		{
			DisplayReverse(t->next);
			cout<<t->PRN<<endl;
			cout<<t->name<<endl;
	}
}
void Pinaccle :: InsertPresident()
{
	Node *q= new Node();
	cout<<"Enter President details \n";
	q->Accept();
	if(start==NULL)
	 {
	   q->next=NULL;
	   start=q;
	 }
	else
	 {
	   q->next=start;
	   start=q;
	 }
}
void Pinaccle :: InsertSecretary()
{
	Node *q = new Node();
	cout<<"Enter Secretary details \n";
	q->Accept();
	Node *p = start;
	if(start==NULL)
	{
		cout<<"There cannot be a Secretary without a President! Insertion not possible ";
	}
	else
	{
		while(p->next!=NULL)
		  p=p->next;
	    p->next=q;
	}
}
void Pinaccle :: InsertMember()
{
	Node *q = new Node();
	cout<<"Enter Member details \n";
	q->Accept();
	if(start==NULL)
		cout<<"There cannot be a member without a President! Insertion not possible ";
	else
	 {
		if(start->next==NULL)
			start->next=q;
		else
			{
			    q->next=start->next;
			    start->next=q;
			}
 	 }
}
void Pinaccle :: DeletePresident()
{
  Node *p;
  if(start==NULL)
	  cout<<"Cannot delete from an empty list! \n";
  else
   {
	  p=start;
	  start=start->next;
      p->next=NULL;
	  delete p;
   }
}
void Pinaccle :: DeleteSecretary()
{
	Node *p=start,*x;
	if(start==NULL)
		cout<<"Cannot delete from an empty list! \n";
	else
	{
		while(p->next!=NULL)
		{
		 x=p;
		 p=p->next;
		}
		x->next=NULL;
	    delete p;
	}

}
void Pinaccle :: DeleteMember()
{
	int no,flag=0;
	Node *t,*prev;
	if(start==NULL)
		cout<<"Cannot delete from an empty list!";
	else
		{
			cout<<"Enter PRN no. of member to be deleted: ";
			cin>>no;
			t=start;
			while(t->next!=NULL)
			{
				if(t->PRN==no){
					flag=1;
					break;
				}
				prev=t;
				t=t->next;
			}
			if(flag==1)
			{
				prev->next=t->next;
				t->next=NULL;
				delete t;
				cout<<"Member with PRN no: "<<no<<" is deleted.\n";
	        }
			else
	          cout<<"Member not found in List. Cannot be deleted!\n";
		}
}
void Pinaccle :: Total()
{
	Node *p=start;
	int c=0;
	while(p->next!=NULL)
	{
	  p=p->next;
	  c++;
	}
	c++;
	cout<<"Number of members = "<<c;
}
void Pinaccle :: Sort()
{
		Node *i,*j;
		int tprn;
		string tname;

	if(start==NULL)
	{
		cout<<"\nList is empty.";
		return ;
	}
	for(i=start;i->next!=NULL;i=i->next)
	{
		for(j=start;j->next!=NULL;j=j->next)
		{
			if((j->PRN)>(j->next->PRN))
			{
				tprn=j->PRN;
				tname=j->name;
				j->PRN=j->next->PRN;
				j->name=j->next->name;

				j->next->PRN=tprn;
				j->next->name=tname;

			}
		}
	}
	Display();
}
void Pinaccle :: Concatenate(Pinaccle &PC)
{
	Node *t,*p;
	t=PC.start;
    if(t==NULL)
	  {
	    cout<<"\nThere are no members in this Club!\n";
		return;
	  }
	p=start;
	while(p->next!=NULL)
		p=p->next;
    p->next=t;
    PC.start=NULL;
    Display();
}
int main() {
	 int x,y,z,prn;
	 string n;
	 char c;
	 Pinaccle *P;
     cout<<"PINACCLE CLUB : DEPARTMENT OF COMPUTER ENGINEERING \n        WELCOMES STUDENTS OF SE, TE and BE! \n";
     cout<<"Enter the PRN and Name of the Founding Member for the Club for First Shift ";
     cin>>prn>>n;
     Pinaccle P1(prn,n);
     cout<<"Enter the PRN and Name of the Founding Member for the Club for Second Shift ";
     cin>>prn>>n;
     Pinaccle P2(prn,n);
     do{
        cout<<"Enter which Shift's Club you want to make changes to \n";
        cin>>y;
        if(y==1)
    	   P=&P1;
        else if(y==2)
    	   P=&P2;
        else
    	   cout<<"Invalid Shift number. Please enter again!\n";
     }
     while(y>2);
     do
     {
    	 cout<<"\nEnter \n1 to Insert members, President, or Secretary \n2 to Delete members, President or Secretary \n3 to find Total number of members of club \n4 to display list in Reverse \n5 to Sort the list by PRN \n6 to Concatenate two lists \n7 to make changes to the other list \n8 to exit \n";
         cin>>x;
         switch(x)
         {
           case 1: cout<<"Original: ";
                   P->Display();
	               do{
                        cout<<"Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary \n";
                        cin>>z;
                        switch(z)
                          {
                             case 1: P1.InsertPresident();
                                     P->Display();
                                     break;
                             case 2 :P->InsertMember();
                                     P->Display();
                                     break;
                             case 3: P->InsertSecretary();
                                     P->Display();
                                     break;
                             default: cout<<"INVALID. Enter again \n";
                         }
                       cout<<"Insert again? Enter y/n ";
                       cin>>c;
	                 }while((c=='y')||(c=='Y'));
        	       break;
           case 2:  cout<<"Original: ";
                    P->Display();
        	        do{
                    cout<<"Enter 1 to delete President, 2 to delete a member, or 3 to delete Secretary \n";
                    cin>>z;
                    switch(z)
                     {
                      case 1: P->DeletePresident();
                              P->Display();
                              break;
                      case 2 :P->DeleteMember();
                              P->Display();
                              break;
                      case 3: P->DeleteSecretary();
                              P->Display();
                              break;
                      default: cout<<"INVALID. Enter again \n";
                    }
                    cout<<"Delete again? Enter y/n ";
                    cin>>c;
        	        }while((c=='y')||(c=='Y'));
        	       break;
           case 3: P->Total();
        	       break;
           case 4: P->revstart();
        	       break;
           case 5: P->Sort();
        	       break;
           case 6: if(y==1)
	                   P->Concatenate(P2);
                   else
                       P->Concatenate(P1);
        	       break;
           case 7: if(y==1)
                      {
        	            P=&P2;
        	            y=2;
                      }
                   else
                      {
                 	    P=&P1;
                 	    y=1;
                      }
                   break;
           case 8: break;
           default: cout<<"Invalid option, please enter again \n";
         }
     }while(x!=8);
	return 0;
}

/**   OUTPUT
 PINACCLE CLUB : DEPARTMENT OF COMPUTER ENGINEERING
        WELCOMES STUDENTS OF SE, TE and BE!
Enter the PRN and Name of the Founding Member for the Club for First Shift 21168
Shruti
Enter the PRN and Name of the Founding Member for the Club for Second Shift 20144
Jinisha
Enter which Shift's Club you want to make changes to
1

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
1
Original: 21168
Shruti
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
1
Enter President details
Enter PRN 21163
Enter name Sarah
21163
Sarah
21168
Shruti
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
2
Enter Member details
Enter PRN 21164
Enter name Rasika
21163
Sarah
21164
Rasika
21168
Shruti
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
2
Enter Member details
Enter PRN 21165 Soham
Enter name 21163
Sarah
21165
Soham
21164
Rasika
21168
Shruti
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
2
Enter Member details
Enter PRN 21167
Enter name Shreyas
21163
Sarah
21167
Shreyas
21165
Soham
21164
Rasika
21168
Shruti
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
3
Enter Secretary details
Enter PRN 21174
Enter name Swapnil
21163
Sarah
21167
Shreyas
21165
Soham
21164
Rasika
21168
Shruti
21174
Swapnil
Insert again? Enter y/n n

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
2
Original: 21163
Sarah
21167
Shreyas
21165
Soham
21164
Rasika
21168
Shruti
21174
Swapnil
Enter 1 to delete President, 2 to delete a member, or 3 to delete Secretary
1
21167
Shreyas
21165
Soham
21164
Rasika
21168
Shruti
21174
Swapnil
Delete again? Enter y/n y
Enter 1 to delete President, 2 to delete a member, or 3 to delete Secretary
2
Enter PRN no. of member to be deleted: 21165
Member with PRN no: 21165 is deleted.
21167
Shreyas
21164
Rasika
21168
Shruti
21174
Swapnil
Delete again? Enter y/n y
Enter 1 to delete President, 2 to delete a member, or 3 to delete Secretary
3
21167
Shreyas
21164
Rasika
21168
Shruti
Delete again? Enter y/n n

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
3
Number of members = 3
Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
4
21168
Shruti
21164
Rasika
21167
Shreyas

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
5
21164
Rasika
21167
Shreyas
21168
Shruti

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
7

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
1
Original: 20144
Jinisha
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
2
Enter Member details
Enter PRN 20132
Enter name Lokesh
20144
Jinisha
20132
Lokesh
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
2
Enter Member details
Enter PRN 20135
Enter name Jaswant
20144
Jinisha
20135
Jaswant
20132
Lokesh
Insert again? Enter y/n y
Enter 1 to insert President, 2 to insert a member, or 3 to insert Secretary
3
Enter Secretary details
Enter PRN 20154
Enter name Abhishek
20144
Jinisha
20135
Jaswant
20132
Lokesh
20154
Abhishek
Insert again? Enter y/n n

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
2
Original: 20144
Jinisha
20135
Jaswant
20132
Lokesh
20154
Abhishek
Enter 1 to delete President, 2 to delete a member, or 3 to delete Secretary
2
Enter PRN no. of member to be deleted: 20135
Member with PRN no: 20135 is deleted.
20144
Jinisha
20132
Lokesh
20154
Abhishek
Delete again? Enter y/n n

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
3
Number of members = 3
Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
4
20154
Abhishek
20132
Lokesh
20144
Jinisha

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
5
20132
Lokesh
20144
Jinisha
20154
Abhishek

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
6
20132
Lokesh
20144
Jinisha
20154
Abhishek
21164
Rasika
21167
Shreyas
21168
Shruti

Enter
1 to Insert members, President, or Secretary
2 to Delete members, President or Secretary
3 to find Total number of members of club
4 to display list in Reverse
5 to Sort the list by PRN
6 to Concatenate two lists
7 to make changes to the other list
8 to exit
8
 */

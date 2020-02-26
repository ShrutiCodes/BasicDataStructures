//============================================================================
// Name        : Assignment9.cpp
// Author      : Shruti Phadke
// Version     :
// Copyright   : Your copyright notice
// Description : Queue Operations
//============================================================================

#include <iostream>
using namespace std;

class node;
class queue;

class node{
	string job_name;
	node *next;
public:
	node(){job_name='\0'; next=NULL;}
	node(string n){job_name=n; next=NULL;}
	friend class queue;
};

class queue{
	node *front;
	node *rear;
public:
	queue(){front=NULL; rear=NULL;}
	void insert_job();
	void display();
	void delete_job();
	void delete_all();
};

void queue :: insert_job(){
	string n;
	cout<<"Enter Job name or code ";
	cin>>n;
	cout<<endl;
	node *temp=new node(n);

	if(front==NULL && rear==NULL){
		front=temp;
		rear=temp;
	}

	else{
		rear->next=temp;
		rear=temp;
	}
}

void queue :: delete_job(){
	node *p=front;
	if(front==NULL && rear==NULL)
		cout<<"Empty Queue!\n";

	else{
		front=front->next;
		p->next=NULL;
		delete p;
	}
}
void queue :: display(){
	node *p=front;
	if(rear==NULL || front==NULL){
		cout<<"Queue Empty!\n";
		return;
	}

	else{
		cout<<"Queue: \n";
		while(p!=NULL){
			cout<<p->job_name;
			p=p->next;
		}
	}
}

int main() {
	cout<<"--------------------------------WELCOME TO JOB QUEUE OPERATIONS--------------------------------";
	int c;
	char ch;
	queue ob;
	do{
		cout<<"\nMenu: ";
		cout<<"\n1. Add Job"
			<<"\n2. Delete Job"
			<<"\n3. Exit \n";
		cin>>c;

		switch(c)
		{
		case 1:
			ob.insert_job();
			ob.display();
			break;
		case 2:
			ob.delete_job();
			ob.display();
			break;
		case 3:
			break;
		default:
			cout<<"\nInvalid Option Chosen";
		}
	}while(c!=3);
	return 0;
}
/*
 * --------------------------------WELCOME TO JOB QUEUE OPERATIONS--------------------------------
Menu:
1. Add Job
2. Delete Job
3. Exit
1
Enter Job name or code AA

Queue:
AA

Menu:
1. Add Job
2. Delete Job
3. Exit
1
Enter Job name or code BB

Queue:
AA
BB

Menu:
1. Add Job
2. Delete Job
3. Exit
1
Enter Job name or code CC

Queue:
AA
BB
CC

Menu:
1. Add Job
2. Delete Job
3. Exit
1
Enter Job name or code DD

Queue:
AA
BB
CC
DD

Menu:
1. Add Job
2. Delete Job
3. Exit
2
Queue:
BB
CC
DD

Menu:
1. Add Job
2. Delete Job
3. Exit
2
Queue:
CC
DD

Menu:
1. Add Job
2. Delete Job
3. Exit
2
Queue:
DD

Menu:
1. Add Job
2. Delete Job
3. Exit
2
Queue Empty!

Menu:
1. Add Job
2. Delete Job
3. Exit
3
 *
 */


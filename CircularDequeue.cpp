//============================================================================
// Name        : Assignment10.cpp
// Author      : Shruti
// Roll No.    : 21168
// Description : Dequeue using Array - circular
//============================================================================
#include <iostream>
using namespace std;

class Queue{
	int *arr;
	int front;
	int rear;
	int SIZE;
public:
	Queue(int n){
		arr = new int[n];
		front=-1;
		rear=-1;
		SIZE = n;
	}
	void InsertatFront();
	void InsertatRear();
	void RemovefromFront();
	void RemovefromRear();
	bool isEmpty();
	void Display();
	bool isFull();
};

void Queue :: InsertatFront(){
	int d;
	cout<<"Enter data: ";
	cin>>d;
	if (isFull())
		cout<<"Queue Full! Cannot be added!";

	else{
		if(isEmpty()){
			rear=0;
			front=0;
		}
		else if(front==0)
			front=SIZE-1;

		else
			front--;
		arr[front]=d;
	}
}
void Queue :: RemovefromFront(){
	if(isEmpty())
		cout<<"Empty Queue!";

	else if(rear==front){
		rear=-1;
		front=-1;
	}
	else
		front=(front+1)%SIZE;
}

void Queue :: InsertatRear(){
	int d;
	cout<<"Enter data to insert: ";
	cin>>d;
	if(isFull())
		cout<<"Queue Full! Cannot be added!";

	else{
		if(isEmpty()){
			rear=0;
			front=0;
		}
		else
			rear=(rear+1)%SIZE;
		arr[rear]=d;
	}
}
void Queue :: RemovefromRear(){
	if(isEmpty())
		cout<<"Empty Queue!";

	else if(rear==front){
		rear=-1;
		front=-1;
	}

	else if(rear==0)
		rear=SIZE-1;

	else
		rear--;
}
bool Queue :: isEmpty(){
	if(rear==-1 || front==-1)
		return true;
	else
		return false;
}

bool Queue :: isFull(){
	if(front==rear+1 ||(front==0 && rear==SIZE-1))
		return true;
	else
		return false;
}

void Queue :: Display(){
	if(isEmpty())
		cout<<"\nEmpty Queue";
	else{
		int i;
		for(i=front; i!=rear ; i=(i+1)%SIZE)
			cout<<arr[i]<<" ";
		cout<<arr[i]<<"\n";
	}
}

int main() {
	cout<<"\nWELCOME TO CIRCULAR DEQUE USING 1-D ARRAY!!!\n";
	int c,z;
	cout<<"Enter size of deque ";
	cin>>z;
	Queue Q(z);
	do{
		cout<<"\nEnter: "
			<<"\n1. Insert at Beginning"
			<<"\n2. Remove from Beginning"
			<<"\n3. Insert at End"
			<<"\n4. Remove from End"
			<<"\n5. Exit \n";
		cin>>c;

		switch(c)
		{
		case 1: Q.InsertatFront();
				Q.Display();
				break;
		case 2: Q.RemovefromFront();
				Q.Display();
			    break;
		case 3: Q.InsertatRear();
				Q.Display();
			    break;
		case 4: Q.RemovefromRear();
				Q.Display();
			    break;
		case 5: break;
		default: cout<<"\nInvalid Option Chosen";
		}
	}while(c!=5);
	return 0;
}
/*

WELCOME TO CIRCULAR DEQUE USING 1-D ARRAY!!!
Enter size of deque 5

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
1
Enter data: 1
1

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
1
Enter data: 2
2 1

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
3
Enter data to insert: 3
2 1 3

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
3
Enter data to insert: 4
2 1 3 4

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
1
Enter data: 5
5 2 1 3 4

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
2
2 1 3 4

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
4
2 1 3

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
2
1 3

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
4
1

Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
2

Empty Queue
Enter:
1. Insert at Beginning
2. Remove from Beginning
3. Insert at End
4. Remove from End
5. Exit
5

 */

//============================================================================
// Name        : Assignment12.cpp
// Author      : Shruti
// Roll no     : 21168
// Description : Sorting
//============================================================================

#include <iostream>
using namespace std;
class Sorting{
	int *per;
	int size;
public:
	Sorting(){
		size=0;
		cout<<"Enter size ";
		cin>>size;
		per=new int[size];
	}
	void Accept();
	void Swap(int *, int *);
	void BubbleSort();
	void SelectionSort();
	void Display();
};
void Sorting :: Accept(){
	cout<<"Enter percentages \n";
	for(int i=0; i<size;i++)
	cin>>per[i];
}
void Sorting :: Swap(int *n, int *m){
	int temp;
	temp=*n;
	*n=*m;
	*m=temp;
}
void Sorting :: BubbleSort(){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(per[j]>per[j+1])
				Swap(&per[j],&per[j+1]);
		}
	}
}
void Sorting :: SelectionSort(){
	int i,j,min;
	for(i=0;i<size;i++){
		min=i;
		for(j=i+1;j<size;j++)
			if(per[j]<per[min])
				min=j;
		Swap(&per[min],&per[i]);
	}
}
void Sorting :: Display(){
	for(int i=0; i<size; i++)
		cout<<per[i]<<" ";
}
int main() {
	cout<<"-----------------Welcome to Sorting Operations!-----------------\n";
	Sorting s;
	int x;
	do{
		cout<<"\nEnter \n1 to input percentages \n2 to perform Bubble Sort \n3 to perform Selection sort \n4 to exit \n";
		cin>>x;
		switch(x){
		case 1: s.Accept();
				s.Display();
				break;
		case 2: s.BubbleSort();
				s.Display();
				break;
		case 3: s.SelectionSort();
				s.Display();
				break;
		case 4: break;
		default: cout<<"Invalid menu number! Please enter again \n";
		}
	}while(x!=4);
	return 0;
}
/*
 *-----------------Welcome to Sorting Operations!-----------------
Enter size 6

Enter
1 to input percentages
2 to perform Bubble Sort
3 to perform Selection sort
4 to exit
1
Enter percentages
22
34
16
77
18
4
22 34 16 77 18 4
Enter
1 to input percentages
2 to perform Bubble Sort
3 to perform Selection sort
4 to exit
2
4 16 18 22 34 77
Enter
1 to input percentages
2 to perform Bubble Sort
3 to perform Selection sort
4 to exit
1
Enter percentages
54
12
33
17
77
1
54 12 33 17 77 1
Enter
1 to input percentages
2 to perform Bubble Sort
3 to perform Selection sort
4 to exit
3
1 12 17 33 54 77
Enter
1 to input percentages
2 to perform Bubble Sort
3 to perform Selection sort
4 to exit
4
 *
 */

//============================================================================
// Name        : Assignment8.cpp
// Author      : Shruti
// Roll no     : 21168
// Description : Conversion to Postfix and Evaluation
//============================================================================
#include<cmath>
#include <iostream>
using namespace std;
template <class T>
class stack{
	T arr[100];
	int top;
public:
	stack(){ arr[0]='\0'; top=-1;}
	void push(char);
	void pop();
	void display();
	bool is_Empty();
	char show_top();
	friend class exp;
};
class express{
	string s;
	char post[100];
public:
	express(){
		s="";
		post[0]='\0';
	}
	int priority(char);
	void input();
	void postfix_expression();
	void Evaluate();
};
template <class T>
void stack<T>:: push(char c){
	arr[++top]=c;
}
template <class T>
void stack<T>:: pop(){
	if(!is_Empty())
		top--;
	else
		cout<<"\nCannot be Popped as Stack is empty!";
}
template <class T>
bool stack<T>:: is_Empty(){
	if (top==-1)
		return true;
	else
		return false;
}
template <class T>
void stack<T>:: display(){
	int i;
	for(i=0; i!=(top+1); i++)
		cout<<arr[i];
}
template <class T>
char stack<T> :: show_top(){
	if(!is_Empty())
		return arr[top];
	else
		cout<<"\nEmpty Stack";
		return 0;
}
void express :: input(){
	cout<<"Enter Expression : ";
	cin>>s;
}
int express :: priority(char c){
	if (c=='#')
		return -1;

	else if(c=='+' || c=='-')
		return 1;

	else if(c=='*' || c=='/')
		return 2;

	else if(c=='^')
		return 3;

	else
	return 0;
}
void express :: postfix_expression(){
	int pr,top_pr;
	int i,j,c=0;
	stack<char> st;
	for(i=0; s[i]!='\0'; i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			post[c++]=s[i];
		}
		else if(s[i]==')'){
			while(st.show_top()!='('){
				post[c++]=st.show_top();
				st.pop();
			}
			if(st.show_top()=='('){
				st.pop();
			}
		}
		else if(s[i]=='(')
			st.push(s[i]);
		else{
			if(!st.is_Empty()){
				pr=priority(s[i]);
				top_pr=priority(st.show_top());
				while(pr<=top_pr){
					post[c++]=st.show_top();
					st.pop();
					top_pr=priority(st.show_top());
				}
				st.push(s[i]);
			}
			else{
				st.push(s[i]);
			}
		}
	}
	cout<<"Converted Expression: ";
	while(!st.is_Empty()){
		post[c++]=st.show_top();
		st.pop();
	}
	for(j=0; post[j]!='\0'; j++)
		cout<<post[j];
	cout<<endl;
}
void express :: Evaluate(){
 stack<int>st;
 int q,x,y,eval;
 for(int i=0;post[i]!='\0';i++){
	 if((post[i]>='a' && post[i]<='z') || (post[i]>='A' && post[i]<='Z')){
		 cout<<"Enter value for:"<<post[i]<<" ";
		 cin>>q;
		 st.push(q);
	 }
	 else{
		 y=st.show_top();
		 st.pop();
		 x=st.show_top();
		 st.pop();
		 switch(post[i]){
		 case '+': st.push((x+y));
		 	 	   break;
		 case '-': st.push((x-y));
		 	 	   break;
		 case '*': st.push((x*y));
		 	 	   break;
		 case '/': st.push((x/y));
		 	 	   break;
		 case '^': st.push((pow(x,y)));
		           break;
		 default: cout<<"Invalid";
		 }
	 }
  }
 eval=st.show_top();
 st.pop();
 cout<<"The postfix expression evaluates to :"<<eval<<endl;
}
int main(){
	express obj;
	cout<<"Welcome to Infix-Postfix Conversion";
	char ch;
	int c;
	cout<<"\n-------------MENU-------------";
	do{
		cout<<"\n1. Input Infix Expression"
			<<"\n2. Convert and Show Postfix Expression"
			<<"\n3. Evaluate \n";
		cin>>c;
		switch(c)
		{
		case 1: obj.input();
		    	break;
		case 2: obj.postfix_expression();
			    break;
		case 3: obj.Evaluate();
				break;
		default:
			cout<<"\nInvalid!";
		}
		cout<<"Do you want to continue? Enter Y/N ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
/*--------------------------------OUTPUT--------------------------------
Welcome to Infix-Postfix Conversion
-------------MENU-------------
1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
1
Enter Expression : (a+b)*c
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
2
Converted Expression: ab+c*
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
3
Enter value for:a 1
Enter value for:b 2
Enter value for:c 3
The postfix expression evaluates to :9
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
1
Enter Expression : (a-b+c)/(a*b+d)
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
2
Converted Expression: ab-c+ab*d+/
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
3
Enter value for:a 1
Enter value for:b 2
Enter value for:c 3
Enter value for:a 1
Enter value for:b 2
Enter value for:d 4
The postfix expression evaluates to :1
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
1
Enter Expression : a+b-c*d/e
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
2

Converted Expression: ab+cd*e/-
Do you want to continue? Enter Y/N Y

1. Input Infix Expression
2. Convert and Show Postfix Expression
3. Evaluate
3
Enter value for:a 1
Enter value for:b 2
Enter value for:c 3
Enter value for:d 4
Enter value for:e 5
The postfix expression evaluates to :1
Do you want to continue? Enter Y/N N
*/

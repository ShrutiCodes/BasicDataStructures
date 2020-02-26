//============================================================================
// Name        : Assignment7.cpp
// Author      : Shruti
// Roll No     : 21168
// Description : Parenthesis checker using Stack (array)
//============================================================================
#include <iostream>
using namespace std;
class Stack{
protected:
	char st[50];
	int top;
	int max;
public:
	Stack(){
		top=-1;
		max=0;
		st[0]='\0';
	}
	void setMax(int m){
		max=m;
	}
	void PUSH(char c);
	char getTop();
	void POP();
	bool isFull();
	bool isEmpty();

};
class Expression : public Stack{
	char *ch;
	int n;
public:
	Expression(){
		ch=NULL;
		n=0;
	}
	void Accept();
	bool Validate();
};
bool Stack :: isFull(){
	if(top==max-1)
		return true;
	else
		return false;
}
bool Stack :: isEmpty(){
	if(top==-1)
		return true;
	else
		return false;
}
void Stack :: PUSH(char c){
	if(!isFull())
	  st[++top]=c;
	}
void Stack :: POP(){
	if(!isEmpty())
		top--;
}
char Stack :: getTop(){
    if(!isEmpty())
		return st[top];
}
void Expression :: Accept(){
	cout<<"Enter number of character in expression (include all brackets, operands and operators!)\n";
	cin>>n;
	if(n!=0){
    ch=new char[n];
    for(int i=0;i<n;i++)
    	cin>>ch[i];
	}
	else
		cout<<"Size cannot be null!\n";
}
bool Expression :: Validate(){
	Stack s;
	s.setMax(n);
	char temp;
	for(int i=0;i<n;i++){
		if((ch[i]=='{')||(ch[i]=='[')||(ch[i]=='(')){
			s.PUSH(ch[i]);
		}
		else if(s.isEmpty())
		   return false;
		else if((ch[i]=='}')||(ch[i]==']')||(ch[i]==')'))
		{
			temp=s.getTop();
			s.POP();
			if(ch[i]=='}'&&temp!='{')
				return false;
			if(ch[i]==']'&&temp!='[')
		    	return false;
			if(ch[i]==')'&&temp!='(')
				return false;
		}
	}
	if(s.isEmpty())
		return true;
	else
		return false;
}
int main(){
	char c;
	Expression e;
	do{
	    e.Accept();
	    if(e.Validate())
		   cout<<"Valid \n";
	    else
		   cout<<"Invalid! \n";
	    cout<<"Check another expression? Enter y/n \n";
	    cin>>c;
	}while(c!='n');
	return 0;
}
/*                                   OUTPUT
Enter number of character in expression (include all brackets, operands and operators!)
7
a+b*c)}
Invalid!
Check another expression? Enter y/n
y
Enter number of character in expression (include all brackets, operands and operators!)
11
{a+b*(c/l)}
Valid
Check another expression? Enter y/n
y
Enter number of character in expression (include all brackets, operands and operators!)
13
{(a+b)*[e+f]}
Valid
Check another expression? Enter y/n
y
Enter number of character in expression (include all brackets, operands and operators!)
7
{(a+b]}
Invalid!
Check another expression? Enter y/n
y
Enter number of character in expression (include all brackets, operands and operators!)
7
{a+b*d}
Valid
Check another expression? Enter y/n
y
Enter number of character in expression (include all brackets, operands and operators!)
5
a+b*c
Valid!
Check another expression? Enter y/n
n
 *
 */

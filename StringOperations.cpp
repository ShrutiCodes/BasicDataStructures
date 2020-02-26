//============================================================================
// Name        : Assignment2.2.cpp
// Author      : Shruti
// Roll No.    : 21168
// Description : String Operations
//============================================================================
#define SIZE 80
#include <iostream>
#include <string>
using namespace std;
class String1
{
	char st[SIZE];
public :
	String1()
      {
		st[80]='\0';
      }
	String1(String1 &S)
	  {
	   int i;
	   for(i=0;S.st[i]!='\0';i++)
		   st[i]=S.st[i];
	   S.st[i]='\0';
	  }
	String1(char *t)
	{
		for(int i=0;t[i]!='\0';i++)
			st[i]=t[i];
	}
	void Accept();
	void Display();
	int strlength();
	String1 copystr();
	int strequal(String1 x);
	String1 Reverse();
	void Concat(String1 x);
	void checksubs(String1 x);
	int Frequency(char c);
	String1 Delete(int m,int n);
	void charDel(char c);
	void Palindrome();
	String1 Replace(String1 x, String1 y);
};
void String1 :: Accept()
{
	cout<<"Enter string \n";
	cin>>st;
}
void String1 :: Display()
{
	cout<<st<<endl;
}
int String1 :: strlength()
{
	int i,l=0;
	for(i=0;st[i]!='\0';i++)
		l++;
	return l;
}
String1 String1 :: copystr()
{
	String1 temp;
	int i,l;
	l=strlength();
	for(i=0;i<l;i++)
		temp.st[i]=st[i];
	temp.st[i]='\0';
	return temp;
}
int String1 :: strequal(String1 x)
{
	int i,f=0,l;
	l=strlength();
	for(i=0;i<l;i++)
		{
		  if(st[i]!=x.st[i])
			break;
		  else
			  f++;
		}
	if(f==l)
		return 0;
	else
		return 1;
}
String1 String1 :: Reverse()
{
	String1 temp;
	int i,l,j;
	l=strlength();
	j=l-1;
	for(i=0;i<l;i++,j--){
		temp.st[j]=st[i];
	}
	temp.st[i]='\0';
return temp;
}
void String1 :: Concat(String1 x)
{
  String1 temp;
  int l;
  int m = x.strlength();
  int i,j;
  temp=copystr();
  l=temp.strlength();
  for(i=l,j=0;i<m+1+l,j<m+1;i++,j++)
	temp.st[i]=x.st[j];
  cout<<"Concatenated string is : ";
  temp.Display();
}
int String1 :: Frequency(char c)
{
	int i,f=0,l;
	l=strlength();
	for(i=0;i<l;i++)
	{
		if(st[i]==c)
			f++;
	}
	return f;
}
void String1 :: Palindrome()
{
	int i,j,l,f=0;
	l=strlength();
	for(i=0,j=l-1;i<l/2;i++,j--)
	{
		if(st[i]==st[j])
			f++;
		else
			f=0;
	}
	if(f==(l/2))
		cout<<"Palindrome \n";
	else if(f==0)
		cout<<"Not Palindrome \n";
}
String1 String1 :: Delete(int m, int n)
{
	int i,j,l;
	String1 temp;
    l=strlength();
    n=n-1;
	for(i=0,j=0;i<l,j<l-n;i++)
	{
      if((i>=m)&&(i<=(m+n)))
		continue;
      else
    	  {
    	   temp.st[j]=st[i];
    	   j++;
    	  }
	}
	temp.st[j]='\0';
	return temp;
}
void String1 :: charDel(char c)
{
	int i,j,l,f,g=0;
	String1 temp;
	l=strlength();
	f=Frequency(c);
	for(i=0,j=0;i<l,j<l-f;i++)
	{
      if(st[i]==c)
      {
    	g=1;
      }
      else
    	 {
    	   temp.st[j]=st[i];
    	   j++;
    	 }
	}
	temp.st[j]='\0';
	if(g!=1)
		cout<<"Character does not exist in string, deletion not possible \n";
	else
	temp.Display();
}
void String1 :: checksubs(String1 x)
{
	int i,j,f,u,v;
	u=strlength();
	v=x.strlength();
	for(i=0;i<v;i++)
	{
	  f=0;
	  for(j=0;j<u;j++)
	  {
		  if(x.st[i+j]==st[j])
		    f++;
	  }
	}
	if(u==f)
		cout<<"Substring found \n";
	else
		cout<<"Substring not found \n";
}
String1 String1 :: Replace(String1 x, String1 y)
{
	String1 temp;
    int l,m,n;
    n=strlength();
    l=x.strlength();
    m=y.strlength();
    int i,j,count=0,ending_index=0,starting_index,flag=0;
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<l;j++){
            if(st[i+j]==x.st[j]){
                ending_index=(i+j+1);
                count++;
            }
        }
        if(l==count){
            starting_index = ending_index - count;
            flag=1;
            break;
        }
    }
    if(flag==1){
        for(i=0; i<starting_index;i++)
            temp.st[i]=st[i];
        temp.st[i]='\0';
        
        for(j=0;j<l;j++)
            temp.st[starting_index+j]=y.st[j];
        
        j+=starting_index;
        i+=l;
        for(i,j;i<n;i++,j++)
            temp.st[j]=st[i];
        temp.st[j]='\0';
        temp.Display();
    }
    else
        cout<<"\n not a substring";
    
    
    
	return temp;
}
int main() {
	int y,z,m,l;
	char c;
	String1 s1,s2,s3,s4;
	s1.Accept();
	do
	{
		cout<<"Enter:\n 1 to find length "
			<<"\n 2 to copy "
			<<"\n 3 to concatenate "
			<<"\n 4 to reverse "
			<<"\n 5 to check equal "
			<<"\n 6 to to find frequency of character "
			<<"\n 7 to check if Palindrome  "
			<<"\n 8 to delete characters "
			<<"\n 9 to delete all occurences of a particular character "
			<<"\n 10 to check substring \n 11 to replace substring "
			<<"\n 12 to exit ";


		cin>>y;
		switch(y)
		{
        case 1:	cout<<"Length : "<<s1.strlength()<<endl;
        break;
		case 2: s2=s1.copystr();
		        cout<<"Copied string is ";
		        s2.Display();
        break;
		case 3: s2.Accept();
			    s1.Concat(s2);
        break;
		case 4:  s3=s1.Reverse();
			     cout<<"Reversed string is \n";
			     s3.Display();
		break;
		case 5: s2.Accept();
			    z= s1.strequal(s2);
                if(z==0)
    	           cout<<"The entered strings are equal \n";
                else cout<<"The entered strings are not equal \n";
        break;
		case 6: cout<<"Enter character to check frequency ";
		        cin>>c;
		        z=s1.Frequency(c);
		        cout<<"Frequency of "<<c<<" is "<<z<<endl;
	    break;
		case 7: s1.Palindrome();
		break;
		case 8: cout<<"Enter start index ";
		        cin>>m;
		        cout<<"Enter number of characters to delete ";
		        cin>>l;
			    s3=s1.Delete(m,l);
			    s3.Display();
		break;
		case 9: cout<<"Enter character to delete ";
		        cin>>c;
		        s1.charDel(c);

		break;
		case 10: cout<<"Enter substring ";
		         s2.Accept();
		         s2.checksubs(s1);
		break;
		case 11: cout<<"Enter substring to replace \n";
			     s2.Accept();
                 cout<<"Enter substring to replace it with \n";
                 s3.Accept();
			     s4=s1.Replace(s2,s3);
		break;
		case 12:
			break;
		default : cout<<"Invalid option, please enter again \n";
		}
	}while(y!=12);
  return 0;
}
/*
 *             OUTPUT
Enter string
hello
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 1
Length : 5
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 2
Copied string is hello
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 3
Enter string
world
Concatenated string is : helloworld
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 4
Reversed string is
olleh
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 5
Enter string
wello
The entered strings are not equal
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 6
Enter character to check frequency l
Frequency of l is 2
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 7
Not Palindrome
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 8
Enter start index 2
Enter number of characters to delete 3
he
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 9
Enter character to delete e
hllo
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 10
Enter substring Enter string
ell
Substring found
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 11
Enter substring to replace
Enter string
ell
Enter substring to replace it with
Enter string
all
hallo
Enter:
 1 to find length
 2 to copy
 3 to concatenate
 4 to reverse
 5 to check equal
 6 to to find frequency of character
 7 to check if Palindrome
 8 to delete characters
 9 to delete all occurences of a particular character
 10 to check substring
 11 to replace substring
 12 to exit 12
 */

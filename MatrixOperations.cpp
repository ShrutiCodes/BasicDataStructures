//============================================================================
//============================================================================
// Name        : Assignment2.cpp
// Author      : Shruti Phadke
// Roll No     : 21168
// Description : Matrix
//============================================================================

#include <iostream>
using namespace std;
class MatrixOp
{
	int r;
	int c;
	int m[10][10];
public:
	MatrixOp();
	MatrixOp(int o,int n);
	//MatrixOp(MatrixOp a);
	void Accept();
	void Display();
	void DisplayMul(MatrixOp a);
	void DisplayT();
	int checkSquare();
	int checkEqual(MatrixOp a);
	int checkValidity(MatrixOp a);
	void UpperTriangular();
	void SumDiagonal();
	MatrixOp Transpose();
	void Operations(MatrixOp a);
	void checkSaddle();
};
MatrixOp :: MatrixOp()
{
	r=c=0;
}
MatrixOp :: MatrixOp(int o, int n)
{
	r=o;
	c=n;
}
void MatrixOp :: Accept()
{
	cout<<"Enter number of rows ";
	cin>>r;
	cout<<"Enter number of columns ";
	cin>>c;
	cout<<"Enter elements "<<endl;
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>m[i][j];
		}
	}
}
void MatrixOp :: Display()
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
void MatrixOp :: DisplayMul(MatrixOp a)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<a.c;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
void MatrixOp :: DisplayT()
{
	int i,j;
		for(i=0;i<c;i++)
		{
			for(j=0;j<r;j++)
			{
				cout<<m[i][j]<<" ";
			}
			cout<<endl;
		}
}
int MatrixOp :: checkSquare()
{
  if(r==c)
	  return 1;
  else
	  return 0;
}
int MatrixOp :: checkEqual(MatrixOp a)
{
  if(r==a.r && c==a.c)
	  return 1;
  else
	  return 0;
}
int MatrixOp :: checkValidity(MatrixOp a)
{
	if(c==a.r)
		return 1;
	else
		return 0;
}
void MatrixOp :: UpperTriangular()
{
	int i,j,f;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
          if(i>j)
          {
        	  if(m[i][j]!=0){
        		  f=1;
        	      break;
               }
          }
		}
	}
	if(f!=1)
		cout<<"Upper Triangular \n";
	else if(f==1)
		cout<<"Not Upper Triangular \n";
}
void MatrixOp :: SumDiagonal()
{
	int i,j,sum=0;
	int f= checkSquare();
	if(f==1)
	{
	  for(i=0;i<r;i++)
	   {
		 for(j=0;j<c;j++)
		   {
	         if(i==j)
	    	   sum+=m[i][j];
		   }
	    }
	 cout<<"Sum of diagonal elements is "<<sum<<endl;
	}
}
MatrixOp MatrixOp :: Transpose()
{
	MatrixOp temp;
	temp.r=r;
	temp.c=c;
	int i,j;
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
		       temp.m[j][i]=m[i][j];
			}
		}
	return temp;
}
void MatrixOp :: Operations(MatrixOp a)
{
	int x,i,j,k,f;
	MatrixOp temp;
	temp.r=r;
	temp.c=c;
	cout<<"Enter 1 for Addition \n 2 for Subtraction \n 3 for Multiplication \n";
	cin>>x;
	switch(x)
	{
	 case 1: f=checkEqual(a);
		     if(f==1)
		     {
	          for(i=0;i<r;i++)
		       {
			    for(j=0;j<c;j++)
			      {
	                 temp.m[i][j]=m[i][j]+a.m[i][j];
			      }
		     }
	          temp.Display();
		     }
		     else
		    	 cout<<"Matrices not compatible for addition! ";

	  break;
	 case 2: f=checkEqual(a);
	         if(f==1)
	 		   {
		        for(i=0;i<r;i++)
			      {
				    for(j=0;j<c;j++)
				      {
		                 temp.m[i][j]=m[i][j]-a.m[i][j];
				      }
			      }
		           temp.Display();
	 		   }
	         else
	          cout<<"Matrices not compatible for subtraction! ";
	  break;
	 case 3: f=checkValidity(a);
	            if(f==1){
	            for(i=0;i<r;i++)
			     {
				  for(j=0;j<a.c;j++)
				    {
					  temp.m[i][j]=0;
                      for(k=0;k<c;k++)
                    	  temp.m[i][j]+=m[i][k]*a.m[k][j];
				    }
			    }
		        temp.DisplayMul(a);
		       }
	         else
	           cout<<"Matrices not compatible for multiplication! ";
		       break;
	 default : cout<<"Invalid Option \n";
	}
}
void MatrixOp :: checkSaddle()
{
	int i,j,k,f,g=0,minrow;
	for(i=0;i<r;i++)
	{
	 minrow=m[i][0];
	 for(j=1;j<c;j++)
	  {
		if(minrow>m[i][j])
		{
			minrow=m[i][j];
			f=i;
		}
	  }
	 for(k=0;k<c;k++)
	 {
		 if(minrow<m[k][f])
			break;
	 }
	if(k==c)
	 {
		cout<<"Saddle Point is "<<minrow<<endl;
		g=1;
	 }
	 }
	if(g==0)
		cout<<"No saddle point present \n";
}
int main() {

	int x,f;
	MatrixOp m1,m2,m3;
	m1.Accept();
	m1.Display();
     do{
    	cout<<"Enter: \n 1 for checking Upper Triangular "
    		<<"\n 2 for Sum of Diagonal Elements "
    		<<"\n 3 for Transpose "
    		<<"\n 4 for Operations "
    		<<"\n 5 for checking if Saddle Point is present "
    		<<"\n 6 for Exit \n";
 		cin>>x;
    	switch(x)
	     {
	        case 1:m1.UpperTriangular();
	         break;
	        case 2: m1.SumDiagonal();
	         break;
	        case 3: m2 = m1.Transpose();
	                m2.DisplayT();
	         break;
	        case 4: cout<<"Enter 2nd Matrix \n";
	                m2.Accept();
	                do{
	                m1.Operations(m2);
	        	    cout<<"Enter 1 to perform another operation, otherwise enter 0 ";
	        	    cin>>f;
	        	    if(f==0)
	        	    	break;
	                }while(f!=0);
             break;
	        case 5: cout<<"Checking saddle point \n";
	        	    m1.checkSaddle();
	         break;
	        case 6 : break;
	        default: cout<<"Invalid Option. Please enter again. \n";
	    }
	}while(x!=6);
	return 0;
}
/*
                 ***OUTPUT***
Enter number of rows 3
Enter number of columns 3
Enter elements
1
2
3
4
5
6
7
8
9
1 2 3
4 5 6
7 8 9
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
1
Not Upper Triangular
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
2
Sum of diagonal elements is 15
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
3
1 4 7
2 5 8
3 6 9
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
4
Enter 2nd Matrix
Enter number of rows 3
Enter number of columns 2
Enter elements
1
2
3
4
5
6
Enter 1 for Addition
 2 for Subtraction
 3 for Multiplication
1
Matrices not compatible for addition! Enter 1 to perform another operation, otherwise enter 0 1
Enter 1 for Addition
 2 for Subtraction
 3 for Multiplication
3
22 28
49 64
76 100
Enter 1 to perform another operation, otherwise enter 0 0
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
4
Enter 2nd Matrix
Enter number of rows 3
Enter number of columns 3
Enter elements
0
1
2
3
4
5
6
7
8
Enter 1 for Addition
 2 for Subtraction
 3 for Multiplication
1
1 3 5
7 9 11
13 15 17
Enter 1 to perform another operation, otherwise enter 0 1
Enter 1 for Addition
 2 for Subtraction
 3 for Multiplication
2
1 1 1
1 1 1
1 1 1
Enter 1 to perform another operation, otherwise enter 0 0
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
5
Checking saddle point
Saddle point is : 7
Enter:
 1 for checking Upper Triangular
 2 for Sum of Diagonal Elements
 3 for Transpose
 4 for Operations
 5 for checking if Saddle Point is present
 6 for Exit
6
 */

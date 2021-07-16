/*
Naive approach:

A simple method is to do a row wise traversal of the matrix, count the number of 1s in each row and compare the count with max. 
Finally, return the index of row with maximum 1s.

TC => O(r*c)
SC => O(1)

Better approach: Binary search

Use Binary Search to count of 1s in each row. We find the index of first instance of 1 in each row. 
The count of 1s will be equal to total number of columns minus the index of first 1.

TC: O(r*Log(c))
SC => O(1) (iterative BS use kiya)

Most efficient approach:

Instead of doing binary search in every row, we first check whether the row has more 1s than max so far. 
If the row has more 1s, then only count 1s in the row. 
Also, to count 1s in a row, we don’t do binary search in complete row, we do search in before the index of last max.

TC: O(r*Log(c)) 
SC => O(1) (iterative BS use kiya)

HERE I HAVE USED 2nd APPROACH:

*/

//ISSUES:
//use vetors and Dymanic allocation karo vector ka

#include<iostream>
//#include<algorithm>
//#include<vector>
                     
using namespace std;


/*
//globals
int R=0;
int C=0;
*/

//using binary search left most 1 nikaalo. It returns row index of leftmost 1 
int Left_most_1(bool mat[4][4],int current_row)
{
	
	int left=0;              //pata hi hai ki size 4 by 4 hai.
	int right=3;
	
	while(left<=right)
	{
		int mid=left+(right-left)/2; 
		cout<<"\nleft => "<<left;
		cout<<"\nright => "<<right;
		cout<<"\nMid => "<<mid;
		
		//base case(current element is leftmost 1) jaha recursion tutegaa
		if(mat[current_row][mid]==1 && mat[current_row][mid-1]==0)
		{
			return mid;
			break;
		}
		else if(mat[current_row][mid]==0)  //0001 aur hum 2nd index pe hai, to right me jaao
		{
			left=mid+1;
		}
		else if(mat[current_row][mid]==1)  //0111 aur hum 4th index pe hai, to left me jaao
		{
			right=mid-1;
		}
	} 
	
}

int Row_Max(bool mat[4][4],int r,int c)
{
	int Max=0,count=0,ans_row=0,leftmost1=0;
	
	for(int i=0;i<r;i++)
	{
		leftmost1=Left_most_1(mat,i);
		count=4-leftmost1;  //pata hai 4 columns hai
		if(count>Max)
		{
			Max=count;
			ans_row=i;	
		}
	}
	
	return ans_row;
}

int main()
{
	/*
	int r,c;
	
	cout<<"\n Enter number of rows => ";
	cin>>r;
	R=r;
	
	cout<<"\n Enter number of columns => ";
	cin>>c;
	C=c;
	*/
	
	bool mat[4][4]={
			{0,1,1,1},
			{0,0,1,1},
			{1,1,1,1},
			{0,0,0,0}	
		};
	
	/*
	cout<<"\nFeed matrix(BOOLEAN ONLY) :\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"\nMat"<<i<<j<<" => ";
			cin>>element;
			mat[i].push_back(element);
		}
	}
	*/
	
	cout<<"\nRow with max number of 1s => "<<Row_Max(mat,4,4);
	
	return 0;
}

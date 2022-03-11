#include<bits/stdc++.h>
using namespace std;
 int ans=0;
bool isSafe(int board[8][8], int row, int col)
{
    int i, j;
  
    /* Check this row on left side */
    if(board[row][col]==2)
    return false;
    for (i = 0; i < col; i++)
        if (board[row][i]==1)
            return false;
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]==1)
            return false;
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (board[i][j]==1)
            return false;
  
    return true;
}
  

void solveNQUtil(int board[8][8], int col)
{
    
    if (col >= 8)
    { ans++;
        return ;
    }
  
    for (int i = 0; i < 8; i++) {
       
        if (isSafe(board, i, col)) {
           
            board[i][col] = 1;
  
           
            solveNQUtil(board, col + 1);
              
  
          
        }
    }
}
    int main()
    {  
        ans=0;
       int arr[8][8]={0};
       for(int i=0;i<8;i++)
       {
           string s;
           cin>>s;
           for(int j=0;j<s.length();j++)
           {
               if(s[j]=='.')
               arr[i][j]=0;
               else if(s[j]=='*')
               arr[i][j]=2;
           }
       }
    //    for(int i=0;i<8;i++)
    //    for(int j=0;j<8;j++)
    //    cout<<arr[i][j]<<endl;
       solveNQUtil(arr,0);
        cout<<ans<<endl;
    }
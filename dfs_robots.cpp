#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int n,char arr[][n]){
    if(i<=0 || j<=0 || i>=n-1 || j>=n-1 || arr[i][j]=='X' || arr[i][j]=="*")
        return;
        
    if(arr[i][j]=='O' || arr[i][j]==0)
        arr[i][j] = '*';
        
    dfs(i+1,j,n,arr);
    dfs(i,j+1,n,arr);
    dfs(i-1,j,n,arr);
    dfs(i,j-1,n,arr);
    
}

void check(int rows,int cols,int n,char arr[][n])
{
    if(arr==NULL || n==0)
        return;
    
    for(int i=0;i<rows;i++){
        if(arr[i][0]=='O' || arr[i][0]==0)
        dfs(i,1,n,arr);
        if(arr[i][cols-1]=='O' || arr[i][cols-1]==0)
        dfs(i,cols-2,n,arr);
    }
    
    for(int i=0;i<cols;i++){
        if(arr[0][i]=='O' || arr[0][i]==0)
        dfs(1,i,n,arr);
        if(arr[i][rows-1]=='O' || arr[i][rows-1]==0)
        dfs(rows-2,i,n,arr);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='*')arr[i][j]='O';
            
            else if(arr[i][j]=='O')arr[i][j]='X';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;
    char arr[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    check(n,n,n,arr);
    
    return 0;
}
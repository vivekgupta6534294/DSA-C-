#include<iostream>
using namespace std;
bool isSafe(int** arr,int x,int y,int n){
    //checking if queen is present in the same column
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    //Checking upper left diagonal 
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    //Now checking for upper right diagonal
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool nQueen(int** arr,int x,int n){
    //Not putting int y beacuse once queen has been placed we are moving to next row instead of checking the same row.
    if(x>=n){//means n queens placed
         return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }
    return false;
}

int main (){
    int n;
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    //Give the Input only one integer like 4 ,5

    return 0;
}
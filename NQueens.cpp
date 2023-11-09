#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>> &board, int n){
    int i=n;
    int j=n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col, int n){
    int i=row;
    int j=col;

    //check within row
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    //check in upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    //check in bottom left diagnal
    i=row;
    j=col;
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
}

void solve(vector<vector<char>> &board, int col, int n){
    //base case
    if(col>=n){
        //possible solution found
        printSolution(board,n);
        return;
    }

    //1-case solve kardo
    for(int row=0 ; row<n ; row++){
        if(isSafe(board, row, col, n)){
            board[row][col]='Q';
            //recursive col for remaining columns
            solve(board, col+1,n);
            //backtracking
            board[row][col]='-';

        }
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<endl;

    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0; //initially starting with first col
    solve(board, col, n);

}
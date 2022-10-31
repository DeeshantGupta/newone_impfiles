#include<iostream>
using namespace std;

int grid[15][15];

//function to print the solution
void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        cout<<"\t";
        for (int j = 0;j <= n-1; j++) {
            cout <<grid[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"\n\n";

}
//function to check if the position is safe or not
//row is indicates the queen no. and col represents the possible positions
bool isSafe(int col, int row, int n) {
  //check for same column
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    //check for upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //check for upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}
//function to find the position for each queen
bool solve (int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    //variable sol is use for possible backtracking
    bool sol = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            //recursive call solve(n, row+1) for next queen (row+1)
            sol = solve(n, row+1) || sol;//if sol ==false then changes are backtracked by assigning the grid[row][i] = 0
            grid[row][i] = 0;
        }
    }
    return sol;
}

int main(){
    int n;
    cout<<"\t\t\t\t N-QUEEN PROBLEM\n";
    cout<<"Enter the value of n : ";
    cin >> n;
    cout<<"\n\n";
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            grid[i][j] = 0;
        }
    }
    bool sol = solve(n, 0);
    if(sol == false) {
        cout <<"No Possible Solution !!" << endl; //if there is no possible solution
    }
    else {
        cout << endl;
    }
    return 0;
}
//Main ends

#include <bits/stdc++.h>
using namespace std;
bool isEmptyPosition(vector<vector<char>> &board, int &row, int &col)
{
    for (int i = row; i < 9; i++)
    {
        for (int j = row; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafe(vector<vector<char>> &board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
        {
            return false;
        }
    }
    row -= (row % 3);
    col -= (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[row + i][col + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Sudokuhelp(vector<vector<char>> &board)
{
    int row = 0, col = 0;
    if (!isEmptyPosition(board, row, col))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        string temp = to_string(i);
        if (isSafe(board, row, col, temp[0]))
        {
            board[row][col] = temp[0];
            if (Sudokuhelp(board))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    Sudokuhelp(board);
}
int main(){
    vector<vector<char>> board(9,vector<char>(9));
    cout<<"Enter the elements of sudoko in row wise manner, and fill the blank places with '.' :"<<endl;
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            cin>>board[i][j];
        }
    }
    solveSudoku(board);
    cout<<endl;
    cout<<"The Solution for the above sudoko is ..."<<endl;
    cout<<endl;
    for(int i = 0;i < 9;i++){
        cout<<"|";
        for(int j = 0;j < 9;j++){
            if((j+1) % 3 == 0) cout<<board[i][j]<<"|";
            else cout<<board[i][j]<<" ";
        }
        if((i+1)%3 == 0 && i != 8){
            cout<<endl;
            cout<<"|";
            for(int k = 0;k < 17;k++) cout<<"-";
            cout<<"|";
        }
        cout<<endl;
    }
    cout<<endl;
}
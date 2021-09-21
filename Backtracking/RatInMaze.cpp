#include<iostream>
using namespace std;

//Returns total number of paths
int ratInMazePaths(char maze[10][10], int soln[10][10], int i, int j, int m, int n){
    //Base Case
    if(i == m && j == n){
        soln[i][j] = 1;

        //Printing Path
        for(int i=0; i <= m; i++){
            for(int j=0; j <= n; j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }

    //Checking is rat in maze
    if(i > m || j > n){
        return 0;
    }
    if(maze[i][j] == 'X'){
        return 0;
    }

    //Recursive Case

    soln[i][j] = 1;
    int rightPath = ratInMazePaths(maze, soln, i, j+1, m, n);
    int downPath  = ratInMazePaths(maze, soln, i+1, j, m, n);

    //Backtracking
    soln[i][j] = 0;

    return rightPath + downPath;
}

//check if path is present or not
bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n){
    //Base Case
    if(i == m && j == n){
        soln[i][j] = 1;

        //Printing Path
        for(int i=0; i <= m; i++){
            for(int j=0; j <= n; j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //Checking is rat in maze
    if(i > m || j > n){
        return false;
    }
    if(maze[i][j] == 'X'){
        return false;
    }

    //Recursive Case

    soln[i][j] = 1;
    bool rightPath = ratInMaze(maze, soln, i, j+1, m, n);
    bool downPath  = ratInMaze(maze, soln, i+1, j, m, n);

    //Backtracking
    soln[i][j] = 0;

    if(rightPath || downPath){
        return true;
    }
    return false;
}

int main(){
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    
    int m = 4;
    int n = 4;

    int soln[10][10] = {0};

    int ans = ratInMazePaths(maze, soln, 0, 0, m-1, n-1);
    cout<<ans<<" paths are present in maze";

    return 0;
}
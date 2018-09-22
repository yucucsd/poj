#include <iostream>
using namespace std;
void dfs(char** maze, int row, int col, int &num, int x, int y){
    maze[x][y] = '#';
    num++;
    if (x != 0 && maze[x - 1][y] == '.'){
        dfs(maze, row, col, num, x - 1, y);
    }
    if (y != 0 && maze[x][y - 1] == '.'){
        dfs(maze, row, col, num, x, y - 1);
    }
    if (x != row - 1 && maze[x + 1][y] == '.'){
        dfs(maze, row, col, num, x + 1, y);
    }
    if (y != col - 1 && maze[x][y + 1] == '.'){
        dfs(maze, row, col, num, x, y + 1);
    }
}

int main(){
    int row, col;
    while (cin >> col >> row && row != 0 && col != 0){
        char** maze = new char*[row];
        int sx, sy;
        for (int i = 0; i < row; i++)
            maze[i] = new char[col];
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cin >> maze[i][j];
                if (maze[i][j] == '@'){
                    sx = i; sy = j;
                }
            }
        }
        int num = 0;
        dfs(maze, row, col, num, sx, sy);
        cout << num << endl;
    }
}

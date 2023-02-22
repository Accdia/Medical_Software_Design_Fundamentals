#include<iostream>
#include<stack>
#include <ctime> 
#include<stdlib.h>
using namespace std;

void printfmaze(int maze[10][10]) 
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << maze[i][j] << "  ";
            cout.setf(ios_base::unitbuf);
        }
        cout << endl;
    }
}//打印输出

void   Delay(int time)//time*1000为秒数 
{
    clock_t   now = clock();

    while (clock() - now < time);
}
int main()
{
    int maze[10][10] = {
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
    int x, y, z;
    x = 1; y = 1; z = 0;
    stack<int>stk;
    stk.push(x);
    stk.push(y);//读取初始位置
    while (!stk.empty())
    {
        y = stk.top();
        stk.pop();
        x = stk.top();
        stk.push(y);//从栈中读取坐标
        maze[x][y] = 1;
        if (maze[x - 1][y] == 0){
            stk.push(x-1);
            stk.push(y);
            
        }
        else if (maze[x + 1][y] == 0) {
            stk.push(x + 1);
            stk.push(y);
            
        }
        else if (maze[x][y - 1] == 0) {
            stk.push(x);
            stk.push(y - 1);
            
        }
        else if (maze[x][y + 1] == 0) {
            stk.push(x);
            stk.push(y + 1);
            
        }//移动
        else {
            stk.pop();
            stk.pop();
        }//如有阻碍就退回一步
        printfmaze(maze);
        Delay(500);
        cout << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                z = z + maze[i][j];
            }
        }
        if (z==136)
        {
            exit(100);
        }
        else
        {
            z = 0;
        }
    }//判断是否填满
    return 0;
}
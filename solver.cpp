#include <iostream>
using namespace std;
int tbl[10][10][10];
int grouping(int c)
{
    if(c<=3)
        return 1;
    else if(c>=7)
        return 3;
    else
        return 2;
}
void cut(int x,int y,int a)
{
    for(int i=1;i<10;i++)
    {
        tbl[i][y][0]--;
        tbl[i][y][a] = 0;
    }
    for(int i=1;i<10;i++)
    {
        tbl[x][i][0]--;
        tbl[x][i][a] = 0;
    }
}
int main()
{
    int ans[10][10][1]; //actually can use only char but I use int for easy to get input
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            tbl[i][j][0] = 9;
            for(int k=1;k<10;k++)
                tbl[i][j][k] = 1;
        }
    }
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cin >> ans[i][j][0];
        }
    }


    return 0;
}

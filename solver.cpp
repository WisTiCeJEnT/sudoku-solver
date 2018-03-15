#include <iostream>
using namespace std;
int tbl[10][10][10];
int ans[10][10]; //actually can use only char but I use int for easy to get input
void printAns()
{
     //Print ans
    cout << "Answer table" << endl;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    //Print tbl
    cout << "Calculation table" << endl;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout << tbl[i][j][0] << " ";
        }
        cout << endl;
    }
}
int grouping(int c)
{
    if(c<=3)
        return 1;
    else if(c>=7)
        return 7;
    else
        return 4;
}
void cut(int x,int y,int a)
{
    tbl[x][y][0] = 0;
    for(int i=1;i<10;i++)
    {
        if (tbl[i][y][a] != 0 && tbl[i][y][0] != 0)
        {
            tbl[i][y][0]--;
            tbl[i][y][a] = 0;
        }
    }
    for(int i=1;i<10;i++)
    {
        if(tbl[x][i][a] != 0 && tbl[x][i][0] != 0)
        {
            tbl[x][i][0]--;
            tbl[x][i][a] = 0;
        }
    }
    //cut in 3x3 group
    int i = grouping(x);
    int j = grouping(y);
    for(int ii=i;ii<=i+2;ii++)
    {
        for(int jj=j;jj<=j+2;jj++)
        {
            if(tbl[ii][jj][a] != 0 && tbl[ii][jj][0] != 0)
            {
                tbl[ii][jj][0]--;
                tbl[ii][jj][a] = 0;
            }
        }
    }
}
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            tbl[i][j][0] = 9;
            for(int k=1;k<10;k++)
                tbl[i][j][k] = 1;
        }
    }
    //printAns();
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cin >> ans[i][j];
            if(ans[i][j]!=0)
                cut(i,j,ans[i][j]);
        }
    }
    printAns();
    return 0;
}

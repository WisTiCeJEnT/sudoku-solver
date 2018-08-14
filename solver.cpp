#include <iostream>
using namespace std;
int tbl[10][10][10];
int ans[10][10]; //actually can use only char but I use int for easy to get input

int col[10][10];
void printAns()
{
     //Print ans
    cout << "Answer table" << endl;
    for(int i=1;i<10;i++)
    {
        if(i==4 || i==7)
            cout << "- - - + - - - + - - -" << endl;
        for(int j=1;j<10;j++)
        {
            if(j==4 || j==7)
                cout << "| ";
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
        if (tbl[i][y][a] != 0)
        {
            if(tbl[i][y][0] != 0)
                tbl[i][y][0]--;
            tbl[i][y][a] = 0;
            //col[i][a]--;
        }
    }
    for(int i=1;i<10;i++)
    {
        if(tbl[x][i][a] != 0)
        {
            if(tbl[x][i][0] != 0)
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
            if(tbl[ii][jj][a] != 0)
            {
                if(tbl[ii][jj][0] != 0)
                    tbl[ii][jj][0]--;
                tbl[ii][jj][a] = 0;
            }
        }
    }
}
int find_min(int c)
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            if (tbl[i][j][0] == 1)
            {
                for(int k=1;k<10;k++)
                {
                    if(tbl[i][j][k]==1)
                    {
                        ans[i][j] = k;
                        cut(i,j,k);
                        c--;
                        break;
                    }
                }
            }
        }
    }
    return c;
}
void cSol(int c) //countSolution
{
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
            col[i][j] = 0;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=1;k<10;k++)
            {
                col[j][k] += tbl[i][j][k];
            }
        }
    }
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout << col[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int count = 81;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            //col[i][j] = 0;
            tbl[i][j][0] = 9;
            for(int k=1;k<10;k++)
            {
                tbl[i][j][k] = 1;
            }
        }
    }
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cin >> ans[i][j];
            if(ans[i][j]!=0)
            {
                cut(i,j,ans[i][j]);
                count--;
            }
        }
    }
    while(count!=0)
    {
        int tmp = count;
        count = find_min(count);
        if(tmp==count)
        {
            cSol(count);
            for(int col_ind=1;col_ind<10;col_ind++)
            {
                for(int num_ind=1;num_ind<10;num_ind++)
                {
                    if(col[col_ind][num_ind] == 1)
                    {
                        for(int row_ind=1;row_ind<10;row_ind++)
                        {
                            if(tbl[row_ind][col_ind][num_ind] == 1)
                            {
                                count--;
                                cut(row_ind,col_ind,num_ind);
                                break;
                            }
                        }
                    }
                }
            }
            if(tmp==count)
            {
                cout << "I'm out T^T" << endl;
                break;
            }
        }
    }
    printAns();
    /*
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout << i << " " << j << " > ";
            for(int k=1;k<10;k++)
            {
                cout << tbl[i][j][k];
            }
            cout << endl;
        }
    }
    */
    return 0;
}

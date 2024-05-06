#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void show(vector<vector<int>> temp,int depth)
{
    cout<< depth << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int cal_misplaced(vector<vector<int>> temp, vector<vector<int>> goal)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(temp[i][j]!=goal[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
void astar(vector<vector<int>> goal, vector<vector<int>> start, int prev,int depth)
{
    vector<vector<int>> temp = start;
    show(temp,depth+1);
    int a=-1,b=-1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(temp[i][j]==0)
            {   
                a=i;
                b=j;
                break;
            }
        }
    }
    int min_val = INT_MAX;
    vector<vector<vector<int>>> best;
    if(a-1>=0 && start[a-1][b]!=prev)
    {
        swap(temp[a][b], temp[a - 1][b]);
        int a = cal_misplaced(temp, goal);
        if(a<min_val)
        {
            min_val = a;
            best.push_back(temp);
        }
    }
    if(a+1<3 && start[a+1][b]!=prev)
    {
        temp=start;
        swap(temp[a][b], temp[a + 1][b]);
        int a = cal_misplaced(temp, goal);
        if(a<min_val)
        {
            min_val = a;
            best.clear();
            best.push_back(temp);
        }
        if(a==min_val)
        {
            best.push_back(temp);
        }
    }
    if(b-1>=0 && start[a][b-1]!=prev)
    {
        temp=start;
        swap(temp[a][b], temp[a][b-1]);
        int a = cal_misplaced(temp, goal);
        if(a<min_val)
        {
            min_val = a;
            best.clear();
            best.push_back(temp);
        }
        if(a==min_val)
        {
            best.push_back(temp);
        }
    }
    if(b+1<3 && start[a][b+1]!=prev)
    {
        temp=start;
        swap(temp[a][b], temp[a][b+1]);
        int a = cal_misplaced(temp, goal);
        if(a<min_val)
        {
            min_val = a;
            best.clear();
            best.push_back(temp);
        }
        if(a==min_val)
        {
            best.push_back(temp);
        }
    }
    if(min_val==0)
    {
        cout << "Goal State Reached" << endl;
        show(temp,depth);
        return;
    }
    astar(goal,best[0],best[0][a][b],depth+1);
    
}
int main()
{
    vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    vector<vector<int>> start = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
    astar(goal, start,-1,0);
}
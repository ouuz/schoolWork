#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;
int graph[100][100], n, m = 0;
int ans[50], count = 0;
bool visted[50];
int b;

struct stack
{
    int top, node[100];
}s;

//输出随机生成的无向图关系矩阵
void Print(){
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

//初始化图
void Init(){
    bool flag = false;
    memset(graph, 0, sizeof(graph));
    memset(visted, false, sizeof(visted));
    memset(ans, 0, sizeof(ans));
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            graph[i][j] = 0 + rand() % 2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(graph[i][j])
            {
                flag = true;
                m++;
                graph[j][i] = 1;
                b = i;
            }
    while(!flag)
        Init();
}

//深度优先搜索
void DFS(int x)
{   
    visted[x] = true;
    for(int i = 0; i < n; i++)
        if(!visted[i] && graph[x][i])
            DFS(i);
}   
 
//从所设定的起点深度优先遍历图，若有一个点没被访问，则为非连通图
bool Judge()
{
    DFS(b);
    for(int i = 0; i < n; i++)
        if(!visted[i])
            return false;
    return true;
}

//深度优先搜索
void DFSGraph(int x)
{
    s.top++;
    s.node[s.top] = x;
    for(int i = 0; i < n; i++)
    {
        if(graph[i][x] > 0)
        {
            graph[i][x] = 0;
            graph[x][i] = 0; 
            DFSGraph(i);
            break;
        }
    }
}

//Fleury算法
void Fleury(int x){
    int flag;
    s.top = 0; 
    s.node[s.top] = x;
    while(s.top >= 0)
    {
        flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(graph[s.node[s.top]][i] > 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            ans[count ++] = s.node[s.top] + 1;
            s.top --;
        }
        else
        {
            s.top --;
            DFSGraph(s.node[s.top + 1]);
        }
    }
    cout << endl;
}

//输出答案
void Answer(){
    for(int i = 0; i < count; i++)
        cout << ans[i] << " ";
    cout << endl;
}


int main()
{
    int num = 0, start = 0, degree;
    cout << "请输入结点数n: ";
    cin >> n;
    Init();
    cout << endl << "完全无向图为: " << endl;
    Print();
    cout << endl;
    if(!Judge()){
        cout << "不连通图" << endl;
        return 0;   
    }
    for(int i = 0; i < n; i++)
    {
        degree = 0;
        for(int j = 0; j < n; j++)
            degree += graph[i][j];
        if(degree % 2)
        {
            start = i;
            num++;
        }
    }

    if(num == 0 || num == 2){
        Fleury(start);

        if(ans[0] == ans[count - 1])
            cout << "是欧拉图，欧拉路径为: ";
        else
            cout << "是半欧拉图，欧拉路径为: ";
        Answer();
    }
    else
        cout << "是非欧拉图或半欧拉图" << endl;
    return 0;
}


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

//���������ɵ�����ͼ��ϵ����
void Print(){
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

//��ʼ��ͼ
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

//�����������
void DFS(int x)
{   
    visted[x] = true;
    for(int i = 0; i < n; i++)
        if(!visted[i] && graph[x][i])
            DFS(i);
}   
 
//�����趨�����������ȱ���ͼ������һ����û�����ʣ���Ϊ����ͨͼ
bool Judge()
{
    DFS(b);
    for(int i = 0; i < n; i++)
        if(!visted[i])
            return false;
    return true;
}

//�����������
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

//Fleury�㷨
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

//�����
void Answer(){
    for(int i = 0; i < count; i++)
        cout << ans[i] << " ";
    cout << endl;
}


int main()
{
    int num = 0, start = 0, degree;
    cout << "����������n: ";
    cin >> n;
    Init();
    cout << endl << "��ȫ����ͼΪ: " << endl;
    Print();
    cout << endl;
    if(!Judge()){
        cout << "����ͨͼ" << endl;
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
            cout << "��ŷ��ͼ��ŷ��·��Ϊ: ";
        else
            cout << "�ǰ�ŷ��ͼ��ŷ��·��Ϊ: ";
        Answer();
    }
    else
        cout << "�Ƿ�ŷ��ͼ���ŷ��ͼ" << endl;
    return 0;
}


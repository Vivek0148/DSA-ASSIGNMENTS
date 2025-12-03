#include<iostream>
using namespace std;
struct Edge {
    int s;
    int d;
};
int main() {
    int v = 7;
    Edge g[7][10]; 
    int c[7];      
    for(int i=0;i<7;i++) c[i]=0;
    g[0][c[0]].s = 0; g[0][c[0]++].d = 2;
    g[0][c[0]].s = 0; g[0][c[0]++].d = 1;
    g[1][c[1]].s = 1; g[1][c[1]++].d = 0;
    g[1][c[1]].s = 1; g[1][c[1]++].d = 3;
    g[2][c[2]].s = 2; g[2][c[2]++].d = 0;
    g[2][c[2]].s = 2; g[2][c[2]++].d = 4;
    g[3][c[3]].s = 3; g[3][c[3]++].d = 4;
    g[3][c[3]].s = 3; g[3][c[3]++].d = 1;
    g[3][c[3]].s = 3; g[3][c[3]++].d = 5;
    g[4][c[4]].s = 4; g[4][c[4]++].d = 2;
    g[4][c[4]].s = 4; g[4][c[4]++].d = 3;
    g[4][c[4]].s = 4; g[4][c[4]++].d = 5;
    g[5][c[5]].s = 5; g[5][c[5]++].d = 3;
    g[5][c[5]].s = 5; g[5][c[5]++].d = 4;
    g[5][c[5]].s = 5; g[5][c[5]++].d = 6;
    g[6][c[6]].s = 6; g[6][c[6]++].d = 5;
    int vis[7];
    for(int i=0;i<7;i++)
    vis[i]=0;
    int q[100]; 
    int front = 0, rear = 0;
    cout<<"BFS Traversal: ";
    for(int start=0;start<7; start++) {
        if(vis[start]==0) {
            q[rear++] = start;
            while(front !=rear){
                int curr = q[front++];
                if(vis[curr] == 0) {
                    cout<<curr<<" ";
                    vis[curr] = 1;
                    for(int j=0; j<c[curr]; j++) {
                        int nxt = g[curr][j].d;
                        q[rear++] = nxt;
                    }
                }
            }
        }
    }
    cout<<endl;
    return 0;
}

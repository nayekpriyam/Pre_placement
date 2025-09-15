#include <stdio.h>

typedef struct{int x,y,t;} Cell;

int orangesRotting(int grid[3][3],int r,int c){
    Cell q[100];int f=0,rp=0,fresh=0,time=0;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        if(grid[i][j]==2) q[rp++] = (Cell){i,j,0};
        if(grid[i][j]==1) fresh++;
    }
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(f<rp){
        Cell cur=q[f++];time=cur.t;
        for(int k=0;k<4;k++){
            int nx=cur.x+dir[k][0],ny=cur.y+dir[k][1];
            if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]==1){
                grid[nx][ny]=2;fresh--;
                q[rp++]=(Cell){nx,ny,cur.t+1};
            }
        }
    }
    return fresh==0?time:-1;
}

int main(){
    int grid[3][3]={{2,1,1},{1,1,0},{0,1,1}};
    printf("%d\n",orangesRotting(grid,3,3));
    return 0;
}

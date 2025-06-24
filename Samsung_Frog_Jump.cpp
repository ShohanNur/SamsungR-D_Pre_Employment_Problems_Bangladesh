#include<iostream>
using namespace std;


#define  MXN  100005;



struct Point{
     int x,y;
};


int n, sx,sy,tx,ty;

int a[105][105], dis[105][105], vis[105][105];


Point queue[MXN];

int front = 0, rear = 0;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


bool isValid(int i, int j){
	 return (i>=0 and i<n and j>=0 and j<n);
} 


int main(){
	  cin>n;

	  for(int i=0;i<n;i++){
	  	 for(int j=0;j<n;j++){
	  	 	cin>>a[i][j];

	  	 	vis[i][j] = 0;
	  	 	dis[i][j] = 0;
	  	 }
	  }

	  cin>>sx>>sy>>tx>>ty;

	  queue[rear].x = sx;
	  queue[rear].y = sy;

	  rear = (rear+1)%MXN;

	  vis[sx][sy] = 1;
	  dis[sx][sy] = 0;

	  while(front != rear){
	  	   int px = queue[front].x;
	  	   int py = queue[front].y;

	  	   front = (front+1)%MXN;


	  	   for(int i=0;i<4;i++){
	  	   	   int nx = px + dx[i];
	  	   	   int ny = py + dy[i];

	  	   	   if(isValid(nx,ny) and a[nx][ny]==1 and vis[nx][ny]==0){
	  	   	   	    if(i==0 or i==2){
	  	   	   	    	dis[nx][ny] = dis[px][py];
	  	   	   	    }
	  	   	   	    else{
	  	   	   	    	dis[nx][ny] = 1 + dis[px][py];
	  	   	   	    }
	  	   	   	    vis[px][py] = 1;

	  	   	   	    queue[rear].x = nx;
	  	   	   	    queue[rear].y = ny;
	  	   	   	    rear = (rear+1)%MXN;
	  	   	   }
	  	   }
	  }
	  cout<<dis[tx][ty]<<endl;

}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define LL long long 

using namespace std;

LL n,m,k,x,y;
struct Matrix{
    LL Data[105][105];
    void Init(){
		memset(Data,0,sizeof(Data));
	}
}Ans,Cat;
char Key;

Matrix Mul(Matrix a,Matrix b,LL n,LL m,LL r)
{
    Matrix c;
    c.Init();
    for(LL k=1;k<=m;k++){
        for(LL i=1;i<=n;i++){
            if(a.Data[i][k]){
				for(LL j=1;j<=r;j++){
            	    c.Data[i][j]+=(a.Data[i][k])*(b.Data[k][j]);
        	    }
        	}
        }
    }
    return c;
}
Matrix Pow(Matrix a,LL n,LL k)
{
    Matrix c;
    c.Init();
    for(LL i=1;i<=n;i++){
        c.Data[i][i]=1;
    }
    while(k){
        if(k&1)c=Mul(c,a,n,n,n);
        k>>=1;
        a=Mul(a,a,n,n,n);
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    while((cin>>n>>m>>k)&&n){
		Matrix Ans,Cat;
    	Ans.Init();
    	Cat.Init();
    	for(LL i=1;i<=n+1;i++){
	        Ans.Data[i][i]=1;
    	}
	    for(LL i=1;i<=k;i++){
        	cin>>Key;
    	    switch(Key){
	            case 'g':
                	cin>>x;
            	    Ans.Data[x][n+1]++;
        	        break;
    	        case 'e':
	                cin>>x;
                	for(LL i=1;i<=n+1;i++){
            	    	Ans.Data[x][i]=0;
					}
    	            break;
	            case 's':
            	    cin>>x>>y;
        	        for(LL i=1;i<=n+1;i++){
    	            	swap(Ans.Data[x][i],Ans.Data[y][i]);
					}
            	    break; 
            	default :
            	    break;
        	}
    	}
 		Ans=Pow(Ans,n+1,m);
  		Cat.Data[n+1][1]=1;
 		Ans=Mul(Ans,Cat,n+1,n+1,1);
	    for(LL i=1;i<=n;i++){
	    	cout<<Ans.Data[i][1]<<' ';
		}
		cout<<endl;
	}
    return 0;
}

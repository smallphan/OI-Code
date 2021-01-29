#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N,Num[500],Sum[500];
int DP_Min[500][500],DP_Max[500][500],Ans_Min=0xf777,Ans_Max=-1;

inline int GetSum(int l,int r)
{
    return Sum[r]-Sum[l-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Num[i];
        Num[i+N]=Num[i];
    }
    for(int i=1;i<=2*N;i++){
        Sum[i]=Sum[i-1]+Num[i];
    }
    memset(DP_Min,0xf777,sizeof(DP_Min));
    memset(DP_Max,-1,sizeof(DP_Max));
    for(int i=1;i<=2*N;i++){
        DP_Min[i][i]=DP_Max[i][i]=0;
    }
    for(int i=0;i<=N;i++){
        for(int Len=2;Len<=N;Len++){
            for(int L=i+1,R=i+Len;R<=i+N;L++,R++){
                for(int Mid=L;Mid<R;Mid++){
                    DP_Min[L][R]=min(DP_Min[L][R],DP_Min[L][Mid]+DP_Min[Mid+1][R]+GetSum(L,R));
                    DP_Max[L][R]=max(DP_Max[L][R],DP_Max[L][Mid]+DP_Max[Mid+1][R]+GetSum(L,R));                
                }
            }
        }
    }
    for(int i=0;i<=N;i++){
        Ans_Min=min(Ans_Min,DP_Min[i+1][i+N]);
        Ans_Max=max(Ans_Max,DP_Max[i+1][i+N]);
    }
    cout<<Ans_Min<<endl<<Ans_Max<<endl;
    return 0;
}
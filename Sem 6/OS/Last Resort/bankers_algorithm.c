#include<stdio.h>
#include<stdlib.h>
int n,m,A[10],M[10][10],L[10][10],N[10][10],W[10],F[10],S[10],R[10],p;
void rv(int*v,int s){for(int i=0;i<s;i++)scanf("%d",&v[i]);}
void rm(int a[][10]){for(int i=0;i<n;i++)rv(a[i],m);}
void cn(){for(int i=0;i<n;i++)for(int j=0;j<m;j++)N[i][j]=M[i][j]-L[i][j];}
void dp(){for(int i=0;i<n;i++){printf("P%d|",i);for(int j=0;j<m;j++)printf("%d ",L[i][j]);printf("|");for(int j=0;j<m;j++)printf("%d ",M[i][j]);printf("|");for(int j=0;j<m;j++)printf("%d ",N[i][j]);printf("\n");}for(int i=0;i<m;i++)printf("%d ",A[i]);printf("\n");}
int ok(int x){for(int j=0;j<m;j++)if(N[x][j]>W[j])return 0;return 1;}
void sf(){for(int i=0;i<m;i++)W[i]=A[i];for(int i=0;i<n;i++)F[i]=0;for(int l=0,f=1;l<n&&f;){f=0;for(int i=0;i<n;i++)if(!F[i]&&ok(i)){for(int k=0;k<m;k++)W[k]+=L[i][k];F[i]=1;S[l++]=i;f=1;}if(!f){printf("UNSAFE\n");return;}}printf("Safe:");for(int i=0;i<n;i++)printf("P%d ",S[i]);printf("\n");}
void rq(){scanf("%d",&p);rv(R,m);for(int i=0;i<m;i++)if(R[i]>N[p][i]){printf("Exceeds\n");return;}for(int i=0;i<m;i++)if(R[i]>A[i]){printf("Wait\n");return;}for(int i=0;i<m;i++){A[i]-=R[i];L[p][i]+=R[i];N[p][i]-=R[i];}sf();}
int main(){scanf("%d%d",&n,&m);for(int o=0;;){scanf("%d",&o);switch(o){case 1:rm(L);break;case 2:rm(M);break;case 3:cn();break;case 4:rv(A,m);break;case 5:dp();break;case 6:rq();break;case 7:sf();break;case 8:exit(0);}}}

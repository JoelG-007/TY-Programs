#include<stdio.h>
#include<stdlib.h>
#define MC 200
int n,q[200];
void srt(int*a,int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)if(a[j]>a[j+1]){int t=a[j];a[j]=a[j+1];a[j+1]=t;}}
void fcfs(int h){int t=0;printf("%d",h);for(int i=0;i<n;i++){t+=abs(q[i]-h);h=q[i];printf("->%d",h);}printf("\n%d\n",t);}
void sstf(int h){int v[200]={0},t=0,s[200];for(int i=0;i<n;i++)s[i]=q[i];srt(s,n);printf("%d",h);for(int c=0;c<n;c++){int l=-1,r=n;for(int i=0;i<n;i++)if(!v[i]&&s[i]<h)l=i;for(int i=0;i<n;i++)if(!v[i]&&s[i]>=h){r=i;break;}int nr=(l<0)?r:(r==n)?l:(h-s[l]<=s[r]-h)?l:r;t+=abs(s[nr]-h);h=s[nr];v[nr]=1;printf("->%d",h);}printf("\n%d\n",t);}
void scan(int h,int d){int s[200],t=0,sp=0;for(int i=0;i<n;i++)s[i]=q[i];srt(s,n);while(sp<n&&s[sp]<h)sp++;printf("%d",h);if(d==1){for(int i=sp;i<n;i++){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}if(h<MC-1){t+=MC-1-h;h=MC-1;printf("->%d",h);}for(int i=sp-1;i>=0;i--){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}}else{for(int i=sp-1;i>=0;i--){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}if(h>0){t+=h;h=0;printf("->0");}for(int i=sp;i<n;i++){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}}printf("\n%d\n",t);}
void cscan(int h,int d){int s[200],t=0,sp=0;for(int i=0;i<n;i++)s[i]=q[i];srt(s,n);while(sp<n&&s[sp]<h)sp++;printf("%d",h);if(d==1){for(int i=sp;i<n;i++){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}t+=(MC-1-h)+(MC-1);h=0;printf("->%d->0",MC-1);for(int i=0;i<sp;i++){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}}else{for(int i=sp-1;i>=0;i--){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}t+=h+(MC-1);h=MC-1;printf("->0->%d",MC-1);for(int i=n-1;i>=sp;i--){t+=abs(s[i]-h);h=s[i];printf("->%d",h);}}printf("\n%d\n",t);}
int main(){int h,d,c;scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",&q[i]);scanf("%d",&h);for(;;){scanf("%d",&c);if(c==3||c==4)scanf("%d",&d);switch(c){case 1:fcfs(h);break;case 2:sstf(h);break;case 3:scan(h,d);break;case 4:cscan(h,d);break;case 5:exit(0);}}}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct{char n[10];int s,z;}d[100];
int b[100],ms,c=0;
void ib(){scanf("%d",&ms);for(int i=0;i<ms;i++)b[i]=1;}
void sb(){for(int i=0;i<ms;i++)printf("[%d:%d]",i,b[i]);printf("\n");}
int fs(int z){for(int i=0;i<=ms-z;i++){int ok=1;for(int j=i;j<i+z;j++)if(!b[j]){ok=0;break;}if(ok)return i;}return -1;}
void cr(){char n[10];int z;scanf("%s%d",n,&z);int s=fs(z);if(s<0){printf("No space\n");return;}for(int i=s;i<s+z;i++)b[i]=0;strcpy(d[c].n,n);d[c].s=s;d[c].z=z;c++;printf("OK@%d\n",s);}
void dl(){char n[10];scanf("%s",n);for(int i=0;i<c;i++)if(!strcmp(d[i].n,n)){for(int j=d[i].s;j<d[i].s+d[i].z;j++)b[j]=1;d[i]=d[--c];printf("Done\n");return;}printf("?\n");}
void sd(){for(int i=0;i<c;i++)printf("%s s=%d z=%d\n",d[i].n,d[i].s,d[i].z);}
int main(){ib();for(int c;;){scanf("%d",&c);switch(c){case 1:sb();break;case 2:cr();break;case 3:sd();break;case 4:dl();break;case 5:exit(0);}}}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
typedef struct{char n[50];int z,ib;}FD;
typedef struct{int a,ix[MAX];}BK;
BK bv[MAX];FD*dir[MAX];int ms,fm;
void ib(){scanf("%d",&ms);fm=ms;for(int i=0;i<ms;i++)bv[i].a=0;for(int i=0;i<MAX;i++)dir[i]=NULL;}
void sb(){for(int i=0;i<ms;i++)printf("[%d:%d]",i,bv[i].a);printf("\n");}
int gf(char*n){for(int i=0;i<MAX;i++)if(dir[i]&&!strcmp(dir[i]->n,n))return i;return -1;}
void ad(FD*f){for(int i=0;i<MAX;i++)if(!dir[i]){dir[i]=f;return;}}
void cr(){char n[50];int z;scanf("%s%d",n,&z);if(gf(n)>=0){printf("Exists\n");return;}if(fm<z+1){printf("No mem\n");return;}FD*f=malloc(sizeof(FD));strcpy(f->n,n);f->z=z;f->ib=-1;for(int i=0;i<z;){int id=rand()%ms;if(bv[id].a)continue;bv[id].a=1;if(f->ib<0)f->ib=id;else bv[f->ib].ix[i-1]=id;i++;}fm-=(z+1);ad(f);printf("IB:%d\n",f->ib);}
void dl(){char n[50];scanf("%s",n);int x=gf(n);if(x<0){printf("?\n");return;}FD*f=dir[x];for(int i=0;i<f->z;i++)bv[bv[f->ib].ix[i]].a=0;bv[f->ib].a=0;fm+=f->z+1;dir[x]=NULL;free(f);printf("Done\n");}
void sd(){for(int i=0;i<MAX;i++){if(!dir[i])continue;printf("%s ib=%d z=%d|",dir[i]->n,dir[i]->ib,dir[i]->z);for(int j=0;j<dir[i]->z;j++)printf("%d ",bv[dir[i]->ib].ix[j]);printf("\n");}}
int main(){ib();for(int c;;){scanf("%d",&c);switch(c){case 1:sb();break;case 2:cr();break;case 3:sd();break;case 4:dl();break;case 5:exit(0);}}}

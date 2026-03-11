#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct{char n[10];int z,s,e;}d[100];
int b[100],ms,fb,c=0;
void ib(){scanf("%d",&ms);for(int i=0;i<ms;i++)b[i]=-1;fb=ms;}
void sb(){for(int i=0;i<ms;i++)printf("[%d:%d]",i,b[i]);printf("F:%d\n",fb);}
void cr(){char n[10];int z;scanf("%s%d",n,&z);if(fb<z){printf("No mem\n");return;}int s=-1,pv=-1,cur;for(int k=0;k<z;){cur=rand()%ms;if(b[cur]!=-1)continue;if(pv<0)s=cur;else b[pv]=cur;pv=cur;k++;}b[pv]=-9;strcpy(d[c].n,n);d[c].z=z;d[c].s=s;d[c].e=pv;fb-=z;c++;printf("S:%d E:%d\n",s,pv);}
void dl(){char n[10];scanf("%s",n);for(int i=0;i<c;i++)if(!strcmp(d[i].n,n)){int cur=d[i].s,nx;while(cur!=-9){nx=b[cur];b[cur]=-1;fb++;cur=nx;}d[i]=d[--c];printf("Done\n");return;}printf("?\n");}
void sd(){for(int i=0;i<c;i++)printf("%s z=%d s=%d e=%d\n",d[i].n,d[i].z,d[i].s,d[i].e);}
int main(){ib();for(int ch;;){scanf("%d",&ch);switch(ch){case 1:sb();break;case 2:cr();break;case 3:sd();break;case 4:dl();break;case 5:exit(0);}}}

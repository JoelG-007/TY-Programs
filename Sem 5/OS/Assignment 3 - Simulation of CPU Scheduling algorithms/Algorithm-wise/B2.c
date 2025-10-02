// Priority Scheduling with I/O
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct process{
  int pid, at, bt1, bt2, priority;
  int io_complete, ct, tat, wt;
  int flag1, flag2;
}p[20];

struct gantt{
  int pid, start, end;
}g[40];

int n, gc=0;;
float avg_wt=0, avg_tat=0;

void input(){
  int i;
  printf("Enter number of process- ");
  scanf("%d",&n);

  for(i=0;i<n;i++){
    p[i].pid=i+1;
    printf("Enter arrival time- ");
    scanf("%d",&p[i].at);
    printf("Enter burst time- ");
    scanf("%d",&p[i].bt1);
    printf("Enter Priority- ");
    scanf("%d",&p[i].priority);
    p[i].bt2=rand()%10+1;
    p[i].flag1=p[i].flag2=0;
  }
}

void simulatePriority(){
  int time=0, completed=0, i;
  while(completed<n){
    int idx=-1, max_pri=-9999;
    for(i=0;i<n;i++){
      if(p[i].at<=time && p[i].flag1==0){
	if(p[i].priority>max_pri){
	  max_pri=p[i].priority;
	  idx=i;
	}
      }
    }
    if(idx!=-1){
      g[gc].pid=p[idx].pid;
      g[gc].start=time;
      time+=p[idx].bt1;
      g[gc].end=time;
      gc++;

      p[idx].io_complete=time+2;
      p[idx].flag1=1;
      completed++;
    }else{
      time++;
    }
  }
  completed=0;

  //2nd CPU burst
  while(completed<n){
    int idx=-1, max_pri=-9999;
    for(i=0;i<n;i++){
      if(p[i].at<=time && p[i].flag2==0){
	if(p[i].priority>max_pri){
	  max_pri=p[i].priority;
	  idx=i;
	}
      }
    }
    if(idx!=-1){
      g[gc].pid=p[idx].pid;
      g[gc].start=time;
      time+=p[idx].bt2;
      g[gc].end=time;
      gc++;

      p[idx].ct=time;
      p[idx].tat=p[idx].ct-p[idx].at;
      p[idx].wt=p[idx].tat-(p[idx].bt1+2+p[idx].bt2);
    
      avg_wt+=p[idx].wt;
      avg_tat+=p[idx].tat;

      p[idx].flag2=1;
      completed++;
    }else  time++;
  }
  avg_wt=avg_wt/n;
  avg_tat=avg_tat/n;
}

void ganttChart(){
  int i;
  printf("\n\nGantt Chart:\n|");
  for(i=0;i<gc;i++){
    printf(" P%d\t|",g[i].pid);
  }
  printf("\n0");
  for(i=0;i<gc;i++){
    printf("\t%d",g[i].end);
  }
  printf("\n");
}

void display(){
  int i;
  printf("\nPID\tAT\tBT1\tBT2\tCT\tWT\tTAT\tPriority\n");
    for(i=0;i<n;i++)
      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt1,p[i].bt2,p[i].ct,p[i].wt,p[i].tat,p[i].priority);

  printf("\nAverage Waiting Time: %.2f",avg_wt);
  printf("\nAverage Turnaround Time: %.2f\n",avg_tat);
}

void main(){
  input();
  simulatePriority();
  display();
  ganttChart();
}

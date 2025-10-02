// SJF with I/O
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct process{
  int pid, at, bt1, bt2, ct, wt, tat, completed;
  int io_start, io_complete;
}p[20];

struct gantt{
  int pid, start, end;
}g[40];

int n, gc = 0;
float avg_wt=0, avg_tat=0;

void input(){
  int i;
  printf("Enter number of process- ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    p[i].pid=i+1;
    printf("Enter arrival time for P%d - ",i+1);
    scanf("%d",&p[i].at);
    printf("Enter burst time for P%d - ",i+1);
    scanf("%d",&p[i].bt1);
    p[i].bt2=rand()%10+1;
    p[i].completed=0;
  }
}

void simulateSJF(){
  int time=0, completed=0, i;

  //1st CPU bt
  while(completed<n){
    int idx=-1,min_bt=9999;
    for(i=0;i<n;i++){
      if(p[i].at<=time && p[i].completed==0 && p[i].bt1<min_bt){
	min_bt=p[i].bt1;
	idx=i;
      }
    }
    if(idx!=-1){
      g[gc].pid=p[idx].pid;
      g[gc].start=time;
      time+=p[idx].bt1;
      g[gc].end=time;
      gc++;

      p[idx].io_start=time;
      p[idx].io_complete=time+2;
      p[idx].completed=1;
      completed++;
    }else{
      time++;
    }
  }

  //Reset for bt2
  for(i=0;i<n;i++) p[i].completed=0;

  //2nd CPU bt
  completed=0;
  while(completed<n){
    int idx=-1,min_bt=9999;
    for(i=0;i<n;i++){
      if(p[i].io_complete<=time && p[i].completed==0 && p[i].bt2<min_bt){
	min_bt=p[i].bt2;
	idx=i;
      }
    }
    if(idx!=-1){
      g[gc].pid=p[idx].pid;
      g[gc].start=time;
      time+=p[idx].bt2;
      g[gc].end=time;
      gc++;

      p[idx].ct=time;
      p[idx].tat=p[idx].ct - p[idx].at;
      p[idx].wt=p[idx].tat - (p[idx].bt1 + 2 + p[idx].bt2);
    
      avg_wt+=p[idx].wt;
      avg_tat+=p[idx].tat;

      p[idx].completed=1;
      completed++;
    }else{
      time++;
    }
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
  printf("\nPID\tAT\tBT1\tBT2\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt1,p[i].bt2,p[i].ct,p[i].wt,p[i].tat);

  printf("\nAverage Waiting Time: %.2f",avg_wt);
  printf("\nAverage Turnaround Time: %.2f",avg_tat);
}

void main(){
  input();
  simulateSJF();
  display();
  ganttChart();
}

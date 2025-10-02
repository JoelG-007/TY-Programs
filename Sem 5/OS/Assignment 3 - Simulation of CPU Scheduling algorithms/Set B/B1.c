// Round Robin
/*
Write the program to simulate Round Robin (RR) scheduling. The arrival time and 
first CPU-burst for different n number of processes should be input to the algorithm. 
Also give the time quantum as input. Assume the fixed IO waiting time (2 units). 
The next CPU-burst should be generated randomly. The output should give Gantt 
chart, turnaround time and waiting time for each process. Also find the average 
waiting time and turnaround time. 
*/

// Round Robin
#include<stdio.h>

struct process{
  int pid, at, bt1, bt2, rt1, rt2;
  int ct, wt, tat, io_complete;
  int flag1, flag2;
}p[20];

struct gantt{
  int pid, start, end;
}g[40];

int n, gc=0, tq=2;
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
    p[i].rt1=p[i].bt1;
    p[i].rt2=p[i].bt2;
    p[i].flag1=p[i].flag2=0;
  }
}

void simulateRoundRobin(){
  int time=0, completed=0, i;

  //1st CPU burst
  while(completed<n){
    int flag=0;
    for(i=0;i<n;i++){
      if(p[i].at<=time && p[i].rt1>0 && p[i].flag1==0){
	flag=1;
	g[gc].pid=p[i].pid;
	g[gc].start=time;
	if(p[i].rt1<=tq){
	  time+=p[i].rt1;
	  p[i].rt1=0;
	  p[i].io_complete=time+2;
	  p[i].flag1=1;
	  completed++;
	}else{
	  time+=tq;
	  p[i].rt1-=tq;
	}
	g[gc].end=time;
	gc++;
      }
    }
    if(!flag)time++;
  }

  completed=0;

  //2nd CPU burst
  while(completed<n){
    int flag=0;
    for(i=0;i<n;i++){
      if(p[i].at<=time && p[i].rt2>0 && p[i].flag2==0){
	flag=1;
	g[gc].pid=p[i].pid;
	g[gc].start=time;
	if(p[i].rt2<=tq){
	  time+=p[i].rt2;
	  p[i].rt2=0;
	  p[i].ct=time;
	  p[i].tat=p[i].ct-p[i].at;
	  p[i].wt=p[i].tat-(p[i].bt1+2+p[i].bt2);
    
	  avg_wt+=p[i].wt;
	  avg_tat+=p[i].tat;

	  p[i].flag2=1;
	  completed++;
	}else{
	  time+=tq;
	  p[i].rt2-=tq;
	}
	g[gc].end=time;
	gc++;
      }
    }
    if(!flag)time++;
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
  simulateRoundRobin();
  display();
  ganttChart();
}

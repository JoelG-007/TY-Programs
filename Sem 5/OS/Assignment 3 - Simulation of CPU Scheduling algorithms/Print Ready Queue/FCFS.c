#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct process {
    int pid, at, bt1, bt2, ct, wt, tat, io_start, io_complete;
} p[20];

struct gantt{
    int pid, start, end;
} g[40];

int n, gc = 0;
float avg_wt=0, avg_tat=0;

void input(){
    int i;
    printf("Enter number of process- ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        p[i].pid=i+1;
        printf("Enter arrival time for P%d - ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for P%d - ", i+1);
        scanf("%d", &p[i].bt1);
        p[i].bt2 = rand()%10+1;  // random 2nd CPU burst
    }
}

void sort(){
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if(p[j].at > p[j+1].at){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
}

void printReadyQueue(int time){
    int i;
    printf("\nReady Queue at time %d: [", time);
    int first = 1;
    for(i=0; i<n; i++){
        if(p[i].at <= time && p[i].ct == 0){ // has arrived but not completed
            if(!first) printf(", ");
            printf("P%d", p[i].pid);
            first = 0;
        }
    }
    printf("]\n");
}

void simulateFCFS(){
    int time=0, i;

    for(i=0; i<n; i++){     //1st CPU burst
        if(time < p[i].at)
            time = p[i].at;

        printReadyQueue(time);

        g[gc].pid = p[i].pid;
        g[gc].start = time;
        time += p[i].bt1;
        g[gc].end = time;
        gc++;

        //Schedule I/O (fixed 2 units)
        p[i].io_start = time;
        p[i].io_complete = time + 2;
    }

    for(i=0; i<n; i++){    //2nd CPU burst after I/O
        if(time < p[i].io_complete)
            time = p[i].io_complete;

        printReadyQueue(time);

        g[gc].pid = p[i].pid;
        g[gc].start = time;
        time += p[i].bt2;
        g[gc].end = time;
        gc++;

        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - (p[i].bt1 + 2 + p[i].bt2);

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt = avg_wt/n;
    avg_tat = avg_tat/n;
}

void ganttChart(){
    int i;
    printf("\n\nGantt Chart:\n|");
    for(i=0; i<gc; i++){
        printf(" P%d\t|", g[i].pid);
    }
    printf("\n0");
    for(i=0; i<gc; i++){
        printf("\t%d", g[i].end);
    }
    printf("\n");
}

void display(){
    int i;
    printf("\nPID\tAT\tBT1\tBT2\tCT\tWT\tTAT\n");
    for(i=0; i<n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,p[i].at,p[i].bt1,p[i].bt2,p[i].ct,p[i].wt,p[i].tat);

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

int main(){
    // srand(time(0)); // Can be added for different random values each run
    input();
    sort();
    simulateFCFS();
    display();
    ganttChart();
    return 0;
}

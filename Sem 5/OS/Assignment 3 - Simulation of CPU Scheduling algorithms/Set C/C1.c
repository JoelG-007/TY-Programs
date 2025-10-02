// Preemptive Priority Scheduling
/*
Write the program to simulate Preemptive Priority scheduling. The arrival time and 
first CPU-burst and priority for different n number of processes should be input to 
the algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst 
should be generated randomly. The output should give Gantt chart, turnaround time 
and waiting time for each process. Also find the average waiting time and 
turnaround time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct process{
    int pid, at, bt1, bt2, priority;
    int rem_bt1, rem_bt2;
    int io_complete, ct, tat, wt;
    int finished1, finished2;
}p[20];

struct gantt{
    int pid, start, end;
}g[100];

int n, gc = 0;
float avg_wt=0, avg_tat=0;

void input(){
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        p[i].pid = i + 1;
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter first CPU burst for P%d: ", i+1);
        scanf("%d", &p[i].bt1);
        printf("Enter priority for P%d (higher = higher priority): ", i+1);
        scanf("%d", &p[i].priority);
        p[i].bt2 = rand() % 10 + 1;   // random 2nd burst
        p[i].rem_bt1 = p[i].bt1;
        p[i].rem_bt2 = p[i].bt2;
        p[i].finished1 = 0;
        p[i].finished2 = 0;
        p[i].ct = 0;
    }
}

int getHighestPriority(int time, int phase){
    int i, idx = -1, max_pri = -9999;
    for(i = 0; i < n; i++){
        if(phase == 1){
            if(p[i].at <= time && !p[i].finished1 && p[i].rem_bt1 > 0){
                if (p[i].priority > max_pri){
                    max_pri = p[i].priority;
                    idx = i;
                }
            }
        }else{
            if(p[i].io_complete <= time && !p[i].finished2 && p[i].rem_bt2 > 0){
                if(p[i].priority > max_pri){
                    max_pri = p[i].priority;
                    idx = i;
                }
            }
        }
    }
    return idx;
}

void simulatePreemptivePriority(){
    int time = 0, completed = 0, i;
    int running = -1;

    //First CPU Burst
    while(completed < n){
        int idx = getHighestPriority(time, 1);

        if(idx != -1){
            if (running != idx){  // context switch
                g[gc].pid = p[idx].pid;
                g[gc].start = time;
                running = idx;
            }
            time++;
            p[idx].rem_bt1--;

            if(p[idx].rem_bt1 == 0){
                p[idx].finished1 = 1;
                p[idx].io_complete = time + 2; // I/O wait
                completed++;
                g[gc].end = time;
                gc++;
                running = -1; // CPU free
            }
        }else{
            time++;
        }
    }

    //Second CPU Burst
    completed = 0;
    running = -1;
    while (completed < n){
        int idx = getHighestPriority(time, 2);

        if(idx != -1){
            if(running != idx){
                g[gc].pid = p[idx].pid;
                g[gc].start = time;
                running = idx;
            }
            time++;
            p[idx].rem_bt2--;

            if (p[idx].rem_bt2 == 0){
                p[idx].finished2 = 1;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - (p[idx].bt1 + 2 + p[idx].bt2);

                avg_wt += p[idx].wt;
                avg_tat += p[idx].tat;

                completed++;
                g[gc].end = time;
                gc++;
                running = -1;
            }
        }else{
            time++;
        }
    }

    avg_wt /= n;
    avg_tat /= n;
}

void ganttChart(){
    int i;
    printf("\n\nGantt Chart:\n|");
    for(i = 0; i < gc; i++){
        printf(" P%d\t|", g[i].pid);
    }
    printf("\n0");
    for(i = 0; i < gc; i++){
        printf("\t%d", g[i].end);
    }
    printf("\n");
}

void display(){
    int i;
    printf("\nPID\tAT\tBT1\tBT2\tCT\tWT\tTAT\tPriority\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt1, p[i].bt2,
            p[i].ct, p[i].wt, p[i].tat, p[i].priority);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

int main(){
    input();
    simulatePreemptivePriority();
    display();
    ganttChart();
    return 0;
}

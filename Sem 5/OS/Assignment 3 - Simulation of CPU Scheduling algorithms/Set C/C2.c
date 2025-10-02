// Preemptive SJF
/*
Write the program to simulate Preemptive Shortest Job First (SJF) -scheduling. The 
arrival time and first CPU-burst for different n number of processes should be input 
to the algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst 
should be generated randomly. The output should give Gantt chart, turnaround time 
and waiting time for each process. Also find the average waiting time and turnaround 
time. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct process{
    int pid, at, bt1, bt2;
    int rem_bt1, rem_bt2;
    int io_complete, ct, tat, wt;
    int flag1, flag2;
}p[20];

struct gantt{
    int pid, start, end;
}g[200]; // extra slots for preemptions

int n, gc = 0;
float avg_wt = 0, avg_tat = 0;

void input(){
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p[i].pid = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter first CPU burst time for P%d: ", i + 1);
        scanf("%d", &p[i].bt1);

        p[i].bt2 = rand() % 10 + 1; // random second burst
        p[i].rem_bt1 = p[i].bt1;
        p[i].rem_bt2 = p[i].bt2;
        p[i].flag1 = p[i].flag2 = 0;
    }
}

void simulatePreemptiveSJF(){
    int time = 0, completed1 = 0, completed2 = 0;
    int i, running = -1;

    // First CPU burst
    while(completed1 < n){
        int idx = -1, min_bt = 9999;
        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].flag1 == 0 && p[i].rem_bt1 > 0){
                if(p[i].rem_bt1 < min_bt){
                    min_bt = p[i].rem_bt1;
                    idx = i;
                }
            }
        }

        if(idx != -1){
            if(running != idx){ // context switch
                g[gc].pid = p[idx].pid;
                g[gc].start = time;
                running = idx;
            }

            p[idx].rem_bt1--;
            time++;

            if(p[idx].rem_bt1 == 0){
                g[gc].end = time;
                gc++;

                p[idx].io_complete = time + 2;
                p[idx].flag1 = 1;
                completed1++;
                running = -1;
            }
        }else{
            time++;
            running = -1;
        }
    }

    // Second CPU burst
    running = -1;
    while(completed2 < n){
        int idx = -1, min_bt = 9999;
        for(i = 0; i < n; i++){
            if(p[i].io_complete <= time && p[i].flag2 == 0 && p[i].rem_bt2 > 0){
                if(p[i].rem_bt2 < min_bt){
                    min_bt = p[i].rem_bt2;
                    idx = i;
                }
            }
        }

        if(idx != -1){
            if(running != idx){ // context switch
                g[gc].pid = p[idx].pid;
                g[gc].start = time;
                running = idx;
            }

            p[idx].rem_bt2--;
            time++;

            if(p[idx].rem_bt2 == 0){
                g[gc].end = time;
                gc++;

                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - (p[idx].bt1 + 2 + p[idx].bt2);

                avg_wt += p[idx].wt;
                avg_tat += p[idx].tat;

                p[idx].flag2 = 1;
                completed2++;
                running = -1;
            }
        }else{
            time++;
            running = -1;
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
    printf("\nPID\tAT\tBT1\tBT2\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt1, p[i].bt2,
               p[i].ct, p[i].wt, p[i].tat);

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

int main(){
    input();
    simulatePreemptiveSJF();
    display();
    ganttChart();
    return 0;
}

/*
Note - Use srand(time(0)); in main to get different random values for bt2 on each run.
*/
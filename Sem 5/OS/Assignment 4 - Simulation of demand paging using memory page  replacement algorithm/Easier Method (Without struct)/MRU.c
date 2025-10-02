#include<stdio.h>
int main(){
    int ref[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int n=16;
    int frames[10], time[10], counter=0, faults=0;
    int f,i,j,k,flag,pos;

    printf("Enter number of frames:");
    scanf("%d",&f);

    for(i=0;i<f;i++){
        frames[i]=-1;
        time[i]=0;
    }

    printf("MRU Page Replacement Simulation:\n");

    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(frames[j]==ref[i]){
                flag=1;
                counter++;
                time[j]=counter;
                break;
            }
        }
        printf("Reference %2d--->", ref[i]);
        if(flag==0){
            // find most recently used page
            pos=0;
            for(j=1;j<f;j++){
                if(time[j]>time[pos]) pos=j;
            }
            // if empty slot exists, use it
            for(j=0;j<f;j++){
                if(frames[j]==-1){
                    pos=j;
                    break;
                }
            }
            frames[pos]=ref[i];
            counter++;
            time[pos]=counter;
            faults++;
        }
        for(k=0;k<f;k++){
            if(frames[k]!=-1) printf("%2d ", frames[k]);
            else printf("-- ");
        }
        printf("\n");
    }

    printf("Total Page Faults (MRU) : %d\n", faults);
    return 0;
}

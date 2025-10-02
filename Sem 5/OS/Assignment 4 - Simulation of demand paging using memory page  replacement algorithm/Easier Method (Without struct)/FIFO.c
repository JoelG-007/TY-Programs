#include<stdio.h>
int main(){
    int ref[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int n=16;
    int frames[10], next_replace=0, faults=0;
    int f,i,j,flag,k;

    printf("Enter number of frames:");
    scanf("%d",&f);

    for(i=0;i<f;i++) frames[i]=-1;

    printf("FIFO Page Replacement Simulation:\n");

    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(frames[j]==ref[i]){
                flag=1;
                break;
            }
        }
        printf("Reference %2d--->", ref[i]);
        if(flag==0){
            frames[next_replace]=ref[i];
            next_replace=(next_replace+1)%f;
            faults++;
        }
        for(k=0;k<f;k++){
            if(frames[k]!=-1) printf("%2d ", frames[k]);
            else printf("-- ");
        }
        printf("\n");
    }
    printf("Total Page Faults (FIFO) : %d\n", faults);
    return 0;
}

#include<stdio.h>
int main(){
    int ref[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int n=16;
    int frames[10], refbit[10], next=0, faults=0;
    int f,i,j,flag,k;

    printf("Enter number of frames:");
    scanf("%d",&f);

    for(i=0;i<f;i++){
        frames[i]=-1;
        refbit[i]=0;
    }

    printf("Second Chance Page Replacement Simulation:\n");

    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(frames[j]==ref[i]){
                flag=1;
                refbit[j]=1;
                break;
            }
        }
        printf("Reference %2d--->", ref[i]);
        if(flag==0){
            // find victim using second chance
            while(refbit[next]==1){
                refbit[next]=0;
                next=(next+1)%f;
            }
            frames[next]=ref[i];
            refbit[next]=0;
            next=(next+1)%f;
            faults++;
        }
        for(k=0;k<f;k++){
            if(frames[k]!=-1) printf("%2d ", frames[k]);
            else printf("-- ");
        }
        printf("\n");
    }

    printf("Total Page Faults (Second Chance) : %d\n", faults);
    return 0;
}

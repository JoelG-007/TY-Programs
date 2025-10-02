#include<stdio.h>
int main(){
    int ref[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int n=16;
    int frames[10], freq[10], faults=0;
    int f,i,j,k,flag,pos;

    printf("Enter number of frames:");
    scanf("%d",&f);

    for(i=0;i<f;i++){
        frames[i]=-1;
        freq[i]=0;
    }

    printf("LFU Page Replacement Simulation:\n");

    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(frames[j]==ref[i]){
                flag=1;
                freq[j]++;
                break;
            }
        }
        printf("Reference %2d--->", ref[i]);
        if(flag==0){
            // find LFU page
            pos=0;
            for(j=1;j<f;j++){
                if(frames[j]==-1){
                    pos=j;
                    break;
                }
                if(freq[j]<freq[pos]) pos=j;
            }
            frames[pos]=ref[i];
            freq[pos]=1;
            faults++;
        }
        for(k=0;k<f;k++){
            if(frames[k]!=-1) printf("%2d ", frames[k]);
            else printf("-- ");
        }
        printf("\n");
    }

    printf("Total Page Faults (LFU) : %d\n", faults);
    return 0;
}

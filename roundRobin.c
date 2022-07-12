

#include<stdio.h>
int main(){
    int P[10],CT[10],WT[10],TAT[10],BT[10],RT[10],TQ,n,r,i,Time=0;
    printf("Input Number of process\n");
    scanf("%d",&n);
    printf("Input TQ\n");
    scanf("%d",&TQ);
    printf("Input BT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
        RT[i]=BT[i];
        P[i]=i+1;
    }
    r=n;
    for(Time=0;r!=0;)
    {
        for(i=0;i<n;i++)
        {
            if(RT[i]<=TQ && RT[i]!=0)
            {
                Time=Time+RT[i];
                RT[i]=0;
                r--;
                CT[i]=Time;
                TAT[i]=CT[i];
                printf("\n%d %d",i,Time);
            }
            else if (RT[i]>TQ)
            {
                Time=Time+TQ;
                RT[i]=RT[i]-TQ;
                printf("\n%d %d",i,Time);
            }  
        }
    }
     for(i=0;i<n;i++)
    {
        WT[i]=TAT[i]-BT[i];
    }
      printf("\n Process No \t BT \t TAT \t WT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d",P[i]);
        printf("\t\t %d \t %d \t %d",BT[i],TAT[i],WT[i]);
        printf("\n");
    }
}
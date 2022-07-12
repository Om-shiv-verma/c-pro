#include<stdio.h>
void main()
{
    int n,P[10],BT[10],AT[10],WT[10],TA[10],RT[10],i,Time=0,nn;
    int pass,temp;
    float tat=0,awt=0;
    printf("Enter No of process\n");
    scanf("%d",&n);
    printf("Enter AT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AT[i]);
       
    }
    
    printf("Enter BT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
        P[i]=i+1;
        
    }

    // for(i=0;i<n;i++)
    // printf("\n %d  ",AT[i]);
    
      
    for(pass=1;pass<=n-1;pass++)
    {
        for(i=0;i<=n-1-pass;i++)
        {
            // printf("\n  * %d  %d",AT[i],AT[i+1]);

            if(AT[i] > AT[i+1])
            {
                temp=AT[i];
                AT[i]=AT[i+1];
                AT[i+1]=temp;
                //swapping of processes according to AT time
                temp=P[i];
                P[i]=P[i+1];
                P[i+1]=temp;
                //swapping of BT time according to AT time
                temp=BT[i];
                BT[i]=BT[i+1];
                BT[i+1]=temp;
            }
        }
    }
    //  printf("Sorting of AT time:\n");
    // for(i=0;i<n;i++)
    // printf("\n %d  ",AT[i]);

    for(i=0;i<n;i++)
    {
        RT[i]=BT[i];
    }
  
    nn=n;
    while( nn!=0 )
    {
        for(i=0;i<n;i++)
       {
           if(Time>=AT[i] && RT[i]!=0)
           {
            WT[i]=Time-AT[i];
            Time=Time+BT[i];
            RT[i]=0;
            nn--;
           }
           else
           {
               Time++;
               i--;
           }
       }
    }
    for(i=0;i<n;i++)
    {
        TA[i]=BT[i]+WT[i];
    }

    // printf("\n Process No \t AT \tBT \t WT \t TA \n");
    // for(i=0;i<n;i++)
    // {
    //     printf("%d",P[i]);
    //     printf("\t\t %d \t %d \t %d \t %d",AT[i],BT[i],WT[i],TA[i]);
    //     printf("\n");
    // }
    
    for(pass=1;pass<=n-1;pass++)
    {
        for(i=0;i<=n-1-pass;i++)
        {
            // printf("\n  * %d  %d",AT[i],AT[i+1]);

            if(P[i] > P[i+1])
            {
                temp=P[i];
                P[i]=P[i+1];
                P[i+1]=temp;

                temp=AT[i];
                AT[i]=AT[i+1];
                AT[i+1]=temp;
                //swapping of processes according to AT time
                
                //swapping of BT time according to AT time
                temp=BT[i];
                BT[i]=BT[i+1];
                BT[i+1]=temp;

                temp=TA[i];
                TA[i]=TA[i+1];
                TA[i+1]=temp;

                temp=WT[i];
                WT[i]=WT[i+1];
                WT[i+1]=temp;
            }
        }
    }
    printf("\n Process No \t AT \tBT \t WT \t TA \n");
    for(i=0;i<n;i++)
    {
        printf("%d",P[i]);
        printf("\t\t %d \t %d \t %d \t %d",AT[i],BT[i],WT[i],TA[i]);
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        awt=awt+WT[i];
       tat=tat+TA[i];
    }
    printf("the awt of WT is:%f\n",awt/n);
    printf("the tat of TA is:%f",tat/n);

}





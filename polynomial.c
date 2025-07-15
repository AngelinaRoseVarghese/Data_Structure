#include<stdio.h>
struct polynomial
{
    int coeff;
    int expo;
}polynomial1[10],polynomial2[10],result[20];
int main()
{
    int i=0,j=0,k=0,count1,count2;
    printf("No. of terms you wish to enter in first polynomial: ");
    scanf("%d",&count1);
    printf("Enter the details of the first polynomial\n");
    for(i=0;i<count1;i++)
    {
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d",&polynomial1[i].coeff,&polynomial1[i].expo);
    }
    
    printf("No. of terms you wish to enter in second polynomial: ");
    scanf("%d",&count2);
    printf("Enter the details of the second polynomial\n");
    for(i=0;i<count2;i++)
    {
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d",&polynomial2[i].coeff,&polynomial2[i].expo);
    }
    
   
    while(i<count1 && j<count2)
    {
        if(polynomial1[i].expo==polynomial2[i].expo)
        {
            result[k].coeff=polynomial2[i].coeff+polynomial2[j].coeff;
            result[k].expo=polynomial1[i].expo;
            
        }
        else if(polynomial1[i].expo<polynomial2[j].expo)
        {
            result[k].coeff=polynomial2[j].coeff;
            result[k].expo=polynomial2[j].expo;
            
        }
        else
        {
            result[k].coeff=polynomial1[i].coeff;
            result[k].expo=polynomial1[i].expo;
            
        }
        i++,k++,j++;
    }
    
    while(i<count1)
    {
        result[k].coeff=polynomial1[i].coeff;
        result[k].expo=polynomial1[i].expo;
        i++,k++;
    }
    while(j<count2)
    {
        result[k].coeff=polynomial2[j].coeff;
        result[k].expo=polynomial2[j].expo;
        j++,k++;
    }
    if (count1>count2)
      k=count1;
    else
      k=count2;
    
        
    for(i=0;i<k;i++)
    {
        if(result[i].expo!=0)
        {
            printf("%dx^%d+",result[i].coeff,result[i].expo);
        }
        else
        {
            printf("%d\n",result[i].coeff);
        }
        
    }   
    return 0;
}

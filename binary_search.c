#include <stdio.h>
int main() 
{
    int time=2,flag=0,count,i,key;
    printf("numbers count");
    scanf("%d",&count);
    time++;
    int num[count];
    for(i=0;i<count;i++)
    {
        scanf("%d",&num[i]);
    }
    time++;
    int a=0,b=count-1;
    printf("key");
    scanf("%d",&key);
    while(a<=b)
    {
        int c=(a+b)/2;
        if(num[c]==key)
        {
            flag=1;
            time++;
            break;
        }
        else if(num[c]<key)
        {
            a=c+1;
            time++;
        }
        else 
        {
            b=c-1;
            time++;
        }
    }
    if(flag==0)
    {
        printf("no");
    }
    else
    {
        printf("yes");
    }
    int space=16+count+count;
    printf("%d",space);
    printf("%d",time);
    return 0;
}

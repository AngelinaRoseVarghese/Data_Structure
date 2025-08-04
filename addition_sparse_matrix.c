#include<stdio.h>
int main()
{
    int i,j,k=1,row1,column1;
    printf("Enter the no.of rows and columns in first matrix: ");
    scanf("%d%d",&row1,&column1);
    int num2[row1][column1];
    int num1[row1][column1];
    int result[100][3];
    int transpose[100][3];
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column1;j++)
        {
            scanf("%d",&num1[i][j]);
        }
    }

    printf("Enter the elements of second matrix: ");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column1;j++)
        {
            scanf("%d",&num2[i][j]);
        }
    }

    result[0][0]=row1;
    result[0][1]=column1;
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column1;j++)
        {
            int sum=num1[i][j]+num2[i][j];
            if(sum!=0)
            {
                result[k][0]=i;
                result[k][1]=j;
                result[k][2]=sum;
                k++;
            }
        }

    }
    result[0][0]=row1;
    result[0][1]=column1;
    result[0][2]=k-1;

    printf("Sparse Matrix \n");
    for(j=0;j<k;j++)
    {
        printf("%d\t",result[j][0]);
        printf("%d\t",result[j][1]);
        printf("%d\t",result[j][2]);
        printf("\n");
    }

    printf("Transpose of Sparse Matrix \n");
    for(i=0;i<k;i++)
    {
            transpose[i][0]=result[i][1];
            transpose[i][1]=result[i][0];
            transpose[i][2]=result[i][2];
    }
    for(i=0;i<k;i++)
    {
        printf("%d\t",transpose[i][0]);
        printf("%d\t",transpose[i][1]);
        printf("%d\t",transpose[i][2]);
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int a[20][20];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j,circle=1;//circle记录进行到了第几圈
        int pos=1;
        while(pos<=n*(n+1)/2)
        {
            for(i=circle,j=circle; j<=n-(circle-1)*2; j++)//横向向右赋值
                a[i][j]=pos++;
            for(i=circle+1,j=n-(circle-1)*2-1; i<=n-(circle-1)*2&&j>=circle; i++,j--)//对角线左下向赋值
                a[i][j]=pos++;
            for(i=n-(circle-1)*2-1,j=circle; i>=circle+1; i--)//竖向向上赋值
                a[i][j]=pos++;
            circle++;
        }
        for(i=1; i<=n; i++)//倒三角输出
        {
            for(j=1; j<=n-i+1; j++)
                printf("%4d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}


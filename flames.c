#include<stdio.h>
#include<string.h>
char f[]="flames";
char a[50],b[50];
int n,m,temp,i,j,k,sc,tc,rc,l=1,fc=5;
void cancel_same()
{
     for(int i=0;i<n;i++)
    {
        temp=a[i];
        for(int j=0;j<n;j++)
        {
            if(temp == b[i])
            {
                a[i]=-1;
                b[i]=-1;
                sc+=2;
                break;
            }
        }
    }
}
void rem_space()
{
    for(i=0;i<n;i++)
    {
        if(a[i] == ' ')
        {
            for(int j=i;j<n;j++)
            {
                a[j]=a[j+1];
            }
            n--;
        }
    }
    for(i=0;i<n;i++)
    {
        if(b[i] == ' ')
        {
            for(int j=i;j<n;j++)
            {
                b[j]=b[j+1];
            }
            n--;
        }
    }
}
int flame_calc()
{
    k=0;
    for(i=0;i<5;i++)
    {
        for(j=1;j<rc;)
        {
            k=(k+1)%6;
            j++;
            if(f[k]=='1')
            {
                j--;
            }
        }
            f[k]='1';
            while(f[k]=='1')
            {
                k=(k+1)%6;
            }
        }
        k=0;
        while(f[k]!='\0')
        {
            if(f[k]!='1')
                printf("\n%c",f[k]);
        }
}
int main()
{
    printf("Enter first name:\n");
    scanf("%[^\n]s",a);
    printf("Enter second name:\n");
    scanf("%[\n]s",b);
    n=strlen(a);
    m=strlen(b);
    rem_space();
    cancel_same();
    tc=m+n;
    rc=tc-sc;
    printf("%d",rc);
    flame_calc();
    // switch(f[k])
    // {
    //     case 'f':
    //         printf("friends");
    //         break;
    //     case 'l':
    //         printf("love");
    //         break;
    //     case 'a':
    //         printf("affection");
    //         break;
    //     case 'm':
    //         printf("marriage");
    //         break;
    //     case 'e':
    //         printf("enemies");
    //         break;
    //     case 's':
    //         printf("sister");
    //         break;
    //     default:
    //         printf("nthg...!!!!!!");
    // }
}












// fault code...............

    // for(i=0;;i++)
    // {
    //     if(l==rc)
    //     {
    //         for(k=0;f[k]!='\0';k++)
    //         {
    //             f[k]=f[k+1];
    //         }
    //         f[k+1]='\0';
    //         fc-=fc;
    //         i-=i;
    //         l=0;
    //     }
    //     if(i==fc)
    //     {
    //         i=-1;
    //     }
    //     if(fc==0)
    //     {
    //         break;
    //     }
    //     l++;
    // }
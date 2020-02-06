#include<stdio.h>

void comment1(int k);
void comment2(void);
void echo_quote(int k);

int main(void)
{
    int k;
    
    printf(" To Check /* Quoted String */ \n");
    
    while((k=getchar())!=EOF)
        comment1(k);
    
    return 0;
}

void comment1(int k)
{
    int g;
    if( k == '/')
    {
        if((g=getchar())=='*')
            comment2();
        else if( g == '/')
        {
            putchar(k);
            comment1(g);
        }
        else
        {
            putchar(k);
            putchar(g);
        }
    }
    else if( k == '\''|| k == '"')
        echo_quote(k);
    else
        putchar(k);
}

void comment2()
{
    int k,g;
    
    k = getchar();
    g = getchar();
    
    while(k!='*' || g !='/')
    {
        k =g;
        g = getchar();
    }
}

void echo_quote(int k)
{
    int g;
    
    putchar(k);
    
    while((g=getchar())!=k)
    {
        putchar(g);
        
        if(g == '\\')
            putchar(getchar());
    }
    putchar(g);
}

#include <stdio.h>
#define tabs 8

int main(int argc, const char * argv[])
{
    int r1 = 0;
    int r2 = 1;
    char c;
    

    while((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
            r1 = tabs - ((r2 - 1) % tabs);
            
            while (r1 > 0)
            {
                putchar('#');
                --r1;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            r2 = 1;
        }
        else
        {
            putchar(c);
            ++r2;
        }
    }
    return 0;
}

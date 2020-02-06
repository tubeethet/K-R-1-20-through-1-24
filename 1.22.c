#include<stdio.h>

#define MAX 50
#define TAB 8

char line[MAX];
int expandtab(int pos);
void printline(int pos);
int getblank(int pos);
int newposition(int pos);

int main(void)
{
    int pos,c;
    pos = 0;
    
    while((c=getchar())!=EOF)
    {
        line[pos] = c;
        
        if( c == '\t')
            pos = expandtab(pos);
        if( c == '\n')
        {
            printline(pos);
            pos = 0;
        }
        else if( ++pos >= MAX )
        {
            pos = getblank(pos);
            printline(pos);
            pos = newposition(pos);
        }
    }
    return 0;
}

int expandtab(int pos)
{
    line[pos] = ' ';
    
    for(++pos; (pos < MAX)&&((pos % TAB)!= 0); ++pos)
        line[pos] = ' ';
    
    if( pos >= MAX)
    {
        printline(pos);
        return 0;
    }
    else
        return pos;
}

void printline(int pos)
{
    int i;
    for(i = 0; i < pos; ++i)
        putchar(line[i]);
    if( pos > 0)
        putchar('\n');
}

int getblank(int pos)
{
    if( pos > 0)
        while( line[pos] != ' ')
            --pos;
    if(pos == 0)
        return MAX;
    else
        return pos + 1;
}
int newposition( int pos)
{
    int i,j;
    
    if(pos <= 0 || pos >= MAX)
        return 0;
    else
    {
        i = 0;
        for(j=pos;j < MAX; ++j,++i)
            line[i] = line[j];
    }
    return i;
}


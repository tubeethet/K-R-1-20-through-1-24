//
//  main.m
//  1.24
//
//  Created by Abdultawab Alubidy on 2/5/20.
//  Copyright © 2020 Abdultawab Alubidy. All rights reserved.
//

#include<stdio.h>

int krace,krack,paren;


void quote(int c);
void search(int c);
void comment();

int main()
{
    int c;
    
    extern int krace,krack,paren;
    
    while((c=getchar())!=EOF)
        if( c == '/')
            if((c=getchar())== '*')
                comment();
            else
                search(c);
            else if( c == '\'' || c == '"')
                quote(c);
            else
                search(c);
    
    if( krace < 0)
    {
        printf("Unmatched Braces\n");
        krace = 0;
    }
    else if( krack < 0)
    {
        printf("Unmatched brackets\n");
        krack = 0;
    }
    else if( paren < 0)
    {
        printf("Unmatched parenthesis\n");
        paren = 0;
    }
    
    if(krace > 0)
        printf("Unmatched braces\n");
    else if(krack > 0)
        printf("Unmatched brackets\n");
    else if(paren > 0)
        printf("Unmatched parenthesis\n");
    
    return 0;
}

void comment()
{
    int c,d;
    
    c = getchar();
    d = getchar();
    
    while(c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

void quote(int c)
{
    int d;
    
    putchar(c);
    
    while((d=getchar())!=c)
        if( d == '\\')
            getchar();
}

void search(int c)
{
    extern int krace,krack,paren;
    
    if ( c == '{')
        --krace;
    else if ( c == '}')
        ++krace;
    else if( c == '(')
        --krack;
    else if( c == ')')
        ++krack;
    else if( c == '[')
        --paren;
    else if( c == ']')
        ++paren;
}



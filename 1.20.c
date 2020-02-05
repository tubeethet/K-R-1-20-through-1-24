//
//  main.m
//  H.W. 1-20 to 1-24
//
//  Created by Abdultawab Alubidy on 2/5/20.
//  Copyright © 2020 Abdultawab Alubidy. All rights reserved.
//

#include<stdio.h>
#define TABINC 8

int main(int argc, const char * argv[]) {
    int nb, pos, c;
    
    nb = 0;
    pos = 1;
    
    while ((c=getchar()) != EOF)
    {
        if ( c == '\t')
        {
            nb = TABINC - (( pos -1) % TABINC);
            
            while (nb>0)
            {
                putchar('#');
                ++pos;
                --nb;
            }
        }
    else if ( c == '\n')
    {
        putchar (c);
        pos = 1;
    }
        else
        {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}

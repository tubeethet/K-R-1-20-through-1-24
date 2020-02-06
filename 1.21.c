//
//  main.m
//  1.21
//
//  Created by Abdultawab Alubidy on 2/5/20.
//  Copyright © 2020 Abdultawab Alubidy. All rights reserved.
//

#include<stdio.h>
#define tabs 8

int main(int argc, const char * argv[]) {
   
    int r1, r2, pos, c;
    r1 = 0;
    r2 = 0;
    
    for (pos=1;(c=getchar())!=EOF;++pos)
        if(c==' ')
        {
            if((pos % tabs) != 0)
                ++r1;
            else
            {
                r1 = 0;
                ++r2;
            }
        }
        else {
            for ( ; r2 > 0 ; --r2)
                putchar('\t');
            if ( c == '\t')
                r1 = 0;
            else
                for ( ; r1 > 0; --r1)
                    putchar(' ');
        
            putchar(c);
            
            if (c == '\n')
                pos = 0;
            else if ( c == '\t')
                pos = pos + (tabs - (pos-1)% tabs) -1;
        }
    
    return 0;

}

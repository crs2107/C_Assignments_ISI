#include <stdio.h>

int main(int argc, char **argv)
{
    int i ;
    for (i = 0; i < argc; i++) {
        printf("%d th argument is %s\n",i, argv[i]) ;
    }
    return 0 ;
}

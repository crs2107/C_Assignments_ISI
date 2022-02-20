#include<stdio.h>
int main()
{
int x , y , c = 0;
for(x = -10 ; x <= 10 ; x++)
{
  for(y = -10; y <= 10; y++)
  {
    if( (x*x)+(y*y)<100)
        c = c+1;
  }

}
printf("the number of integer is %d\n",c);
return 0;
}

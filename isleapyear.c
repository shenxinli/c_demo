/*是否闰年
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} bool;

bool isleapyear(int year)
{
	if (year%400==0 || (year%4==0 && year%100!=0))
		return true;
	else
		return false;
}

int main(int argc,char *argv[])
{
	if (argc>1)
	{
		int iyear=atoi(argv[1]);
		printf("The %d year is%sleap year!\n",iyear,(isleapyear(iyear))?" ":" not ");
	}
	return 0;
}

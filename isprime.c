/*isprime
 * 参数num
 * 返回：是素数-true 不是素数-false
 *
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef enum {false,true} bool;

bool isprime(double num)
{
	int i,k,m;
	m=(int)num;
	k=(int)sqrt(num);
	for (i=2;i<=k;i++)
		if (m%i==0) break;
	return (i>k)?1:0;		
}

int main(int argc,char *argv[])
{
	if (argc>1)
	{
		char *msg;
		msg=isprime((double)atoi(argv[1]))?" ":" not ";
		printf("%s is%sa prime!\n",argv[1],msg);
	}
	return 0;
}

/*isprime
 * 参数num
 * 返回：是素数-true 不是素数-false
 * linux下没有链接到math库，所以要加上-lm参数如下：
 * gcc isprime.c -lm -o isprime
 * -lm参数要放在源文件后面，
 * 若:gcc -lm isprime.c -o isprime则不会成功,报如下错误
 * isprime.c:(.text+0x1f): undefined reference to `sqrt'
 * collect2: ld returned 1 exit status
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef enum {false,true} bool;

bool isprime(int num)
{
	int i,k;
	k=(int)sqrt(num);
	for (i=2;i<=k;i++)
		if (num%i==0) break;
	return (i>k)?true:false;		
}

int main(int argc,char *argv[])
{
	if (argc>1)
	{
		char *msg;
		msg=isprime(atoi(argv[1]))?" ":" not ";
		printf("%s is%sa prime!\n",argv[1],msg);
	}
	return 0;
}

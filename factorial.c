/*函数getfactorial
 * 输入参数
 *参数ibegin：	起始数(1)
 *参数iend：	截止数(10)
 *返回：1!+2!+...+10!
 */
#include <stdlib.h>
#include <stdio.h>

int getfactorial(int ibegin,int iend)
{
	int s=0,n=1;
	int i;
	for (i=ibegin;i<=iend;i++)
	{
		n=n*i;
		s=s+n;
	}
	return s;
}

int main(int argc,char *argv[])
{
	if (argc==1)
		printf("no arg is define,default calculate the factorial summation from 1 to 10 is %d.\n",getfactorial(1,10));
	else if (argc==2)
	{
		int iarg=atoi(argv[1]);
		if (iarg>10)
			printf("The first arg is greater than 10, so calculate the factorial summation form 10 to %d is %d.\n",iarg,getfactorial(10,iarg));
		else
			printf("The first arg is less than 10, so calculate the factorial summation form %d to 10 is %d.\n",iarg,getfactorial(iarg,10));
	}
	else
	{
		int iargs[2];
		iargs[0]=atoi(argv[1]);
		iargs[1]=atoi(argv[2]);
		printf("The first arg is less than 10, so calculate the factorial summation form %d to %d is %d.\n",iargs[0],iargs[1],getfactorial(iargs[0],iargs[1]));
	}	
	return 0;
}

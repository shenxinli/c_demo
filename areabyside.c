/*输入三角形的三边长求三角形的面积
 * 参数：double a,b,c
 *
 */
#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,s,area;
	printf("input three wigth:");
	scanf("%lf%lf%lf",&a,&b,&c);
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("%f\t%f\t%f,area=%f\n",a,b,c,area);
	return getchar();
}


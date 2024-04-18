#include <stdio.h>
int main()
{
	int N;
	float C, y, Value=0, Discount,Duration=0;
	printf("Input the number of cash flows:");
	scanf("%d",&N);
	printf("Input the coupon for each period:");
	scanf("%f",&C);
	printf("Input the yield for each period:");
	scanf("%f",&y);


    for(int i=1;i<=N;i=i+1)
	{
	 Discount=1;
	 for(int j=1;j<=i;j++)
	 {
	    Discount=Discount/(1+y); 	 
	 }
     Duration=Duration+i*Discount*C;
	 Value=Value+Discount*C;
	 if(i==N)
	 {
	    Value=Value+Discount*100;
	    Duration=Duration+N*Discount*100;
	 }
	}
    Duration=Duration/Value;
    printf("BondValue=%lf\n",Value);
	printf("Duration=%f\n",Duration);
	printf("Modified Duration=%f",Duration/(1+y));
	return 0;
}

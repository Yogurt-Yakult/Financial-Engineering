#include<stdio.h>
#include<math.h>
int main()
{
  double ZeroRate[6]; 
  double Yield[6];
  double C[6];
  for (int i=0;i<6;i++){
  	printf("Input %d-th coupon payment per period $C:",i+1);
    scanf("%lf",&C[i]);
  }
  
  for(int i=0;i<6;i=i+1)
  {
       printf("Input the i-th period yield rate %d:",i+1);
       scanf("%lf",&Yield[i]);
  }
  ZeroRate[0]=Yield[0];
  for(int i=1;i<=5;i++)
  {
       double BondValue=0;
       for(int j=0;j<=i;j=j+1)
       {
	        double Discount=1;
	        for(int k=0;k<=j;k++)
	        {
	           Discount=Discount/(1+Yield[i]); 	 
	        }
            BondValue=BondValue+Discount*C[i];
	        if(j==i)
	        {
	           BondValue=BondValue+Discount*100;
	        }
       }
       double sumPV = 0;
       for(int j=0;j<i;j=j+1)
       {
           double PV=C[i];
	       for(int k=0;k<=j;k++)
	       {
	           PV=PV/(1+ZeroRate[j]);
	       }  
           sumPV = sumPV + PV;
       }   
       ZeroRate[i]=pow((C[i]+100)/(BondValue-sumPV),1.0/(i+1))-1;
  }  
  for(int i=0;i<=5;i++)
  {
      printf("The %d-th period zero rate=%lf\n",i,ZeroRate[i]);  
  }
  for (int j=0;j<=5;j++){
  	  printf("The %d-th year zero rate=%lf\n",j,ZeroRate[j]*2);
  }
  return 0;
}

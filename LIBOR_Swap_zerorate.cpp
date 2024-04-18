#include<stdio.h>
#include<math.h>
int main()
{
  double ZeroRate[6]; 
  double SwapRate[6];
  double Coupon[6];
  double C;
  double Principle;
  printf("Input the Facevalue:");
  scanf("%lf",&Principle);
  for(int i=0;i<6;i=i+1)
  {
       printf("Input the %d-th period Coupon rate(Swaprate):",i+1);
       scanf("%lf",&SwapRate[i]);
  }
  for(int i=0;i<6;i++)
  {
  	   Coupon[i]=Principle*SwapRate[i];
  }
  ZeroRate[0]=SwapRate[0];
  for(int i=1;i<=5;i++)
  {
       double sumPV = 0;
       for(int j=0;j<i;j=j+1)
       {
           double PV=Coupon[i];
	       for(int k=0;k<=j;k++)
	       {
	           PV=PV/(1+ZeroRate[j]);
	       }  
           sumPV = sumPV + PV;
       }  
       ZeroRate[i]=pow((Coupon[i]+100)/(Principle-sumPV),1.0/(i+1))-1;
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

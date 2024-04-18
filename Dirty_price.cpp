#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    printf("Input the number of periods:");
    scanf("%lf",&n);
    double Settlement_date;
    printf("Input the Settlement to Next coupon date(Use matlab):");
	scanf("%lf",&Settlement_date);
	double coupon_period;
    printf("Input the number of days in a coupon period(Use matlab):");
    scanf("%lf",&coupon_period);

    double Accrued_interest;
    double C;
    printf("Input the coupon payment per period:");
    scanf("%lf",&C);
    double Clean_price;
    double Dirty_price;
    printf("Input the clear_price:");
    scanf("%lf", &Clean_price);  // Use %lf for double
    double Yield;
    double period;
    period = Settlement_date / coupon_period;
    Accrued_interest = C * (1 - period);
    printf("Accrued_price=%lf\n",Accrued_interest);
    Dirty_price = Clean_price + Accrued_interest;
    printf("\n");
    printf("Dirty price=%lf\n", Dirty_price);
    Yield=(100-Clean_price)/Clean_price*(365/Settlement_date);
    printf("Annualize yield =%lf",Yield);
    
}

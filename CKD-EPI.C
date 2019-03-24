#include<stdio.h>   /* FOR eGFR CALCULATION USING CKD-EPI FORMLUA*/
#include<conio.h>
#include<math.h>
#include<errno.h>
void main()
{
int gender,age,i;
float GFR,sercreat,alpha,beta,kappa,creatkappa,creatkappapow,agepow;
beta=0.993;
clrscr();
i=1;
while(i<=5)
{
printf("----------------------------------------------------------------------------\n");
printf("***** WELCOME TO THE PROGRAM FOR eGFR ESTIMATION USING CKD-EPI FORMULA *****\n");
printf("----------------------------------------------------------------------------\n");
printf("Enter the Gender 0f the patient: 1= MALE 2= FEMALE \n");
scanf("%d",&gender);
printf("Enter the Age of the Patient : \n");
scanf("%d",&age);
printf("Enter the Serum Creatinine value(mG/dL): \n");
scanf("%f",&sercreat);
/*IF MALE*/if(gender==1)
	     {
	      kappa=0.9;
/* First Strat on MALE creat value*/if(sercreat>0.9)
				{
				alpha= -1.209;
				creatkappa=sercreat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				GFR=(141*(creatkappapow)*(agepow));
				printf("The GFR is %f mL/Min \n",GFR);
				getch();
				}
/* Second Strat on MALE creat value*/else if(sercreat<=0.9)
				{
				alpha= -0.411;
				creatkappa=sercreat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				GFR=(141*(creatkappapow)*(agepow));
				printf("The GFR is %f mL/Min \n",GFR);
				getch();
				}
				else
				printf("Unable to calculate GFR for Male \n");
				getch();
				}
/*IF FEMALE*/else if(gender==2)
				{
				kappa=0.7;
/* First Strat on FEMALE creat value*/if(sercreat>0.7)
				{
				alpha= -1.209;
				creatkappa=sercreat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				GFR=141*(creatkappapow)*(agepow)*1.018;
				printf("The GFR is %f mL/Min \n",GFR);
				getch();
				}
/* Second Strat on FEMALE creat value*/else if(sercreat<=0.7)
				{
				alpha= -0.329;
				creatkappa=(sercreat/kappa);
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				GFR=141*(creatkappapow)*(agepow)*1.018;
				printf("The GFR is %f mL/Min \n",GFR);
				getch();
				}
				else
				printf("Unable to calculate for Female \n");
				}
else
printf("Unable to Calculate GFR for any Gender \n");
i=i++;
printf("                         # END OF THE PROGRAM #                          \n");
}
}
#include<stdio.h>

void shortestJobFirst();
void firstComeFirstServe();
void setCpuIdle();
int main()
{
	printf("\n**********************************************************************************");
	printf("\n<------------------Enter to the world of Scheduling..!---------------------->");
	printf("\n***********************************************************************************");
	int ch;
	do
	{
		printf("\n");
		printf("---------------------------------------------------------------------------");
		printf("\nWhat we offer is:");
		printf("\n1.Shortest Job First\n2.First Come First Serve\n3.Set CPU idle\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:shortestJobFirst();
					break;
			case 2:firstComeFirstServe();
					break;
			case 3:setCpuIdle();
					break;
			case 4:ch=0;
					break;
			default:
				printf("Choose Wisely..!");
				break;
		}
	}while(ch!=0);
//return ;
}
void shortestJobFirst()
{
		int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	float bt[10],temp,tt[10],ta=0,sum=0;
	int j;
	float at[10], temp2,wt[10];
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf(" -------Shortest Job First Scheduling ( NP )-------\n");
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
 
	for(i=0;i<n;i++)
	{
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %f",&bt[i]);
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %f",&at[i]);
	}
 
/*Sorting According to Arrival Time*/
 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp2=at[j];
				at[j]=at[i];
				at[i]=temp2;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp2=at[k];
				at[k]=at[i];
				at[i]=temp2;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
 
	tavg=(tsum/n);
 
	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %f\t %f\t\t %f\t\t\t%f",p[i],bt[i],at[i],wt[i],tt[i]);
	}
 
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
}
void firstComeFirstServe()
{
	printf("hello all");
int a[10],w[10],b[10],awt=0,tat[10],n,i;
float wsum=0;
float tsum=0;
printf("\t\t --First Come First Serve Scheduling--\n\n");
printf("Enter the number of processes :\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Burst time for process %d : ",i+1);
scanf("%d",&b[i]);
printf("Arrival time for process %d : ",i+1);
scanf("%d",&a[i]);
}
 
printf("\tPROCESS  BURST TIME  ARRIVAL TIME");
for(i=0; i<n; i++)
{
printf("\n\t %d",i+1);
printf("\t    %d",b[i]);
printf("\t        %d",a[i]);
}
w[0]=0;
for(i=1; i<n; i++)
{
w[i]=b[i-1]-a[i]+w[i-1];
wsum=wsum+w[i];
}
printf("\nTotal Waiting Time : %f\n", wsum);
printf("Average Waiting Time : %f\n", wsum/n);
 
tat[0]=b[0]-a[0];
tsum=tat[0];
for(i=1; i<n; i++)
{
tat[i]=b[i]-a[i]+tat[i-1];
tsum=tsum+tat[i];
}
printf("\nTotal Turn Around Time : %f",tsum);
printf("\nAverage Turn Around Time : %f",(tsum/n));
}
void setCpuIdle()
{
	printf("hello all");
		int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	float bt[10],temp,tt[10],ta=0,sum=0;
	int j;
	float at[10], temp2,wt[10];
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf(" -------Shortest Job First Scheduling ( NP )-------\n");
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
 
	for(i=0;i<n;i++)
	{
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %f",&bt[i]);
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %f",&at[i]);
	}
 
/*Sorting According to Arrival Time*/
 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp2=at[j];
				at[j]=at[i];
				at[i]=temp2;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp2=at[k];
				at[k]=at[i];
				at[i]=temp2;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}
	wt[0]=1;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
 
	tavg=(tsum/n);
 
	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %f\t %f\t\t %f\t\t\t%f",p[i],bt[i],at[i],wt[i],tt[i]);
	}
 
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
}

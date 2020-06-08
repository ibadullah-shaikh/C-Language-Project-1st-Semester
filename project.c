#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int i,j,temp;
struct date{
    int month,day,year;
    };
    struct {

    char name[60];
    char lname[60];
    int id_no;
    char cityname[60];
    long long int phone;
    struct date present;

    }add,updd,check,rem;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu() 
{
	int choice;
	system("cls");
    system("color 3");
    printf("\n\n\t\t\t\t\t\tONLINE SHOPPING SYSTEM");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create a membership account\n\t\t2.Update information of an existing membership account\n\t\t3.Place an Order\n\t\t4.Removing an existing membership account\n\t\t5.View membership's account list\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:upd();
        break;
        case 3:order();
        break;
        case 4:erase();
        break;
        case 5:view_all();
        break;
        case 6:close();
        break;
        default:
    {
	printf("Invalid");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&temp);
        if (temp==1)
        {
            system("cls");
 
           menu();
        }
        else
        close();

    }
}
}
//Function to close the program
close()
{
system("cls");
printf("Thanks for Shopping.\nHope to see you again...!!");
system("color F4");
printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-Nuces \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
exit(1);
}

//Function to Create a membership account
new_acc()
{
    FILE *ptr;
enter_again:

    ptr=fopen("record.dat","a+");
    system("cls");
  printf("\t\t\t\t\t\xB2\xB2\xB2\xB2 Add A New Membership Account\xB2\xB2\xB2\xB2\n");
  fflush(stdin);
  printf("Enter todays date (dd-mm-yyyy):");
  scanf("%d/%d/%d",&add.present.day,&add.present.month,&add.present.year);
  if(add.present.day>31 ||add.present.day<1  ||add.present.month>12||add.present.month<1||add.present.year>2020||add.present.year<2000)
  {
  	printf("Please enter correct Date.\n");
  	fordelay(100000000);
  	goto enter_again;
  }
  fflush(stdin);
  x:
  system("cls");
  printf("Todays Date: %d-%d-%d\n",add.present.day,add.present.month,add.present.year);
  u:
  printf("Enter ID:");
  scanf("%d",&check.id_no);
  if(check.id_no<1000 || check.id_no>9999)
  {
  	printf("Please Enter 4 digit ID.\n");
  	goto u;
  }
  while(fscanf(ptr,"%d/%d/%d %d %s %s %d %s",&add.present.day,&add.present.month,&add.present.year,&add.id_no,&add.name,add.lname,&add.phone,&add.cityname)!=EOF)
{
         if (check.id_no==add.id_no)
             {
                 printf("ID already in use.Please re-enter:");
                 fordelay(100000000);
                 goto x;
             }
}
add.id_no=check.id_no;
  fflush(stdin);
  printf("Enter your First Name:");
  gets(add.name);
  printf("Enter your last Name:");
  gets(add.lname);
  printf("Enter Phone Number:");
  scanf("%lld",&add.phone);
  fflush(stdin);
  printf("Enter your city name:");
  gets(add.cityname);
  fprintf(ptr,"%d/%d/%d\t\t%d\t\t%s %s\t\t+92%lld\t\t%s\n",add.present.day,add.present.month,add.present.year,add.id_no,add.name,add.lname,add.phone,add.cityname);
  fclose(ptr);	
  printf("Membership Account Created Successfully");
  printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&temp);
        if (temp==1)
        {
            system("cls");
            menu();
        }
        else
        close();
}
//Function to Update information of an existing membership account
upd()
{
    int choice,t=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
printf("Enter ID of membership account you want to update:");
scanf("%d",&updd.id_no);
while(fscanf(old,"%d/%d/%d %d %s %s %d %s",&add.present.day,&add.present.month,&add.present.year,&add.id_no,&add.name,&add.lname,&add.phone,&add.cityname)!=EOF)
{
	if(add.id_no==updd.id_no)
{
  t++;
  tenter_again:
  printf("Enter todays date (dd/mm/yyyy):");
  scanf("%d/%d/%d",&add.present.day,&add.present.month,&add.present.year);
  if(add.present.day>31 ||add.present.day<1  ||add.present.month>12||add.present.month<1||add.present.year>2020||add.present.year<2000)
  {
  	printf("Please enter correct Date.\n");
  	fordelay(100000000);
  	goto tenter_again;
  }
  fflush(stdin);
  system("cls");
  printf("Date On which Account Updated: %d-%d-%d\n",add.present.day,add.present.month,add.present.year);

  fflush(stdin);
  printf("Enter Your First Name:");
  gets(add.name);
  printf("Enter your last Name:");
  gets(add.lname);
  printf("Enter Phone Number:");
  scanf("%lld",&add.phone);
  fflush(stdin);
  printf("Enter City Name:");
  gets(add.cityname);

  fprintf(newrec,"%d/%d/%d  %d  %s %s +92%lld  %s\n",add.present.day,add.present.month,add.present.year,add.id_no,add.name,add.lname,add.phone,add.cityname);
  printf("Membership Account Updated Successfully");

		
}
	else
	fprintf(newrec,"%d/%d/%d  %d  %s %s  +92%lld  %s\n",add.present.day,add.present.month,add.present.year,add.id_no,add.name,add.lname,add.phone,add.cityname);
}
fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
t:
if(t!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
             
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&temp);
              system("cls");
                 if (temp==1)

                    menu();
                else if (temp==2)
                    close();
                else if(temp==0)
                    upd();
                else
                    {
					printf("\nInvalid!\a");
                    goto t;
					}
        }
    else
        {
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&temp);
        system("cls");
        if (temp==1)
            menu();
        else
            close();
        }
}	

	

//Function to place an order
order()
{
	system("cls");
	system("color 3");
int id[50],price[50],c,q,total=0,r=0,pri[100],a=0,prq[100];
char name[20];
int t=1;
FILE *fptr,*bill,*checkk;
fptr=fopen("item.dat","r");
bill=fopen("bill.dat","w");
checkk=fopen("item.dat","r");
printf("Item ID:\t\tName:\t\t\tPrice:\n");
while(fscanf(fptr,"%d %s %d",&id[t],&name,&price[t])!=EOF)
{
	printf("%d\t\t\t%s\t\t\tRs.%d\n",id[t],name,price[t]);
	t++;
}	
printf("Please Enter the ID of item and then enter Quantity(Enter item ID 0 to finish order):\n");
while(1)
{
	w:
	printf("Item ID:");
	scanf("%d",&c);
	if(c>20)
	{
		printf("Invalid Item ID, Enter Again\n");
		goto w;
	}
	if(c==0)
	break;
	pri[a]=c;
	printf("Quantity:");
	scanf("%d",&q);
	prq[a]=q;
	
	total=total+(price[c]*q);
	a++;

	
}


for(i=0;i<a;i++)
{
	for(j=i+1;j<a;j++)
	{
		if(pri[i]>pri[j])
		{
			temp=pri[i];
			pri[i]=pri[j];
			pri[j]=temp;
		}
	}
}

int e=0;
t=0;
while(fscanf(checkk,"%d %s %d",&id[t],&name,&price[t])!=EOF)
{
	if(pri[e]==id[t])
	{
	fprintf(bill,"%d %s %d %d\n",id[t],name,price[t],prq[t]);
    e++;
    t++; 
	}
	

}
fclose(bill);
fclose(checkk);
char ch;
tryaga:
printf("Do You have a Membership account?(Y or N):");
scanf(" %c",&ch);
if(ch=='n'||ch=='N')
{
	y:
	system("cls");
	FILE *see;
	see=fopen("bill.dat","r");
	int idd,pricee,qua;
	char namee[20];
	system("color 6");
	printf("\t\t\t\t\t\t\xB2\xB2\xB2\xB2TOTAL BILL\xB2\xB2\xB2\xB2\n\n\n");
	printf("Item ID:\tItem Name:\tItem Price:\tItem Quantity:\n");
	while(fscanf(see,"%d %s %d %d",&idd,&namee,&pricee,&qua)!=EOF)
	{
		printf("%d\t\t%s\t\tRs.%d\t\t%d\n",idd,namee,pricee,qua);
	}
printf("\n\nTotal Bill:%d\n\n",total);

}
else if(ch=='y'||ch=='Y')
{
	
	FILE *check;
	int a=0,n,w=0;
	x:
check=fopen("record.dat","r");

printf("Enter Your Membership ID:");
scanf("%d",&n);	
while(fscanf(check,"%d/%d/%d %d %s %s %d %s",&add.present.day,&add.present.month,&add.present.year,&add.id_no,&add.name,&add.lname,&add.phone,&add.cityname)!=EOF)
{
	if(add.id_no==n)
	w++;

}
if(w!=0)
{
	system("cls");
	FILE *see;
	see=fopen("bill.dat","r");
	int idd,pricee,qua;
	char namee[20];
	system("color 6");
	printf("\t\t\t\t\t\t\xB2\xB2\xB2\xB2TOTAL BILL\xB2\xB2\xB2\xB2\n\n");
	printf("\t\t\t\t\t     Special MemberShip Account\n");
	printf("Account ID:%d\n",n);
	//printf("Date: %d/%d/%d \n\n",add.present.day,add.present.month,add.present.year);
	printf("Item ID:\tItem Name:\tItem Price:\tItem Quantity:\n");
	while(fscanf(see,"%d %s %d %d",&idd,&namee,&pricee,&qua)!=EOF)
	{
		printf("%d\t\t%s\t\tRs.%d\t\t\t%d\n",idd,namee,pricee,qua);
	}

	a=total;
	printf("\n************The total bill was:Rs %d*************\n",total);
	total=total*1/5;
	a=a-total;
	printf("**********The bill after 20%% discount is:Rs %d**********\n\n",a);
    }



if(w==0)

{
	int cho=0;
	printf("wrong ID\n");
	q:
	printf("1.Do You want to re-enter ID.\n2.Pay the total bill without any discount.\nChoice:");
	scanf("%d",&cho);
	if(cho==1)
	goto x;
	else if (cho==2)
	{
	goto y;
    }
	else
	{
	printf("Invalid\nEnter choice again:\n");
	goto q;
    }
}
}
else
{
printf("Invalid Choice, Enter Again\n");
goto tryaga;
}

fclose(fptr);
	
printf("\nEnter 1 to go to the main menu,Enter 2 to Place anothrer order and 0 to exit:");
        scanf("%d",&temp);
        if (temp==1)
        {
            system("cls");
            menu();
        }
        else if(temp==2)
        order();
        else
        close();
	
	
}
//Function to Remove an existing membership account
erase()
{
FILE *old,*newrec;
int t=0;
old=fopen("record.dat","r");
newrec=fopen("new.dat","w");
 printf("Enter the ID no. of the customer you want to delete:");
    scanf("%d",&rem.id_no);
    while(fscanf(old,"%d/%d/%d %d %s %s %lld %s",&add.present.day,&add.present.month,&add.present.year,&add.id_no,&add.name,&add.lname,&add.phone,&add.cityname)!=EOF)
    {
    	if(add.id_no!=rem.id_no)
    	fprintf(newrec,"%d/%d/%d  %d  %s %s  %lld  %s\n",add.present.day,add.present.month,add.present.year,add.id_no,add.name,add.lname,add.phone,add.cityname);
    	else
    	{
		t++;
    	printf("\nRecord deleted successfully!\n");
        }
	}
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(t==0)
        {
            printf("\nRecord not found!!\a\a\a");

        }
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&temp);
        if (temp==1)
        {
            system("cls");
            menu();
        }
        else
        close();

	
}
//Function to View membership's account list
view_all()
{
	FILE *view;
	view=fopen("record.dat","r");
    int t=0;
    char ch[1000];
    system("cls");
    while(fscanf(view,"%d/%d/%d %d %s %s %lld %s",&add.present.day,&add.present.month,&add.present.year,&add.id_no,&add.name,&add.lname,&add.phone,&add.cityname)!=EOF)
    {
    	printf("Account ID: %d\nName:%s %s\nDate On which Account created:%d/%d/%d\nContact Number:%lld\nCity Name:%s",add.id_no,add.name,add.lname,add.present.day,add.present.month,add.present.year,add.phone,add.cityname);
    	printf("\n-------------------------------------------------------------------------\n");
    	t++;
	}
	fclose(view);
	if(t==0)
	printf("No Records Found");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&temp);
        if (temp==1)
        {
            system("cls");
            menu();
        }
        else
        close();
}
void main ()
{
	int i;
	printf("\n\n\t\t\t\t\tWelcometo AL-FAST ONLINE SHOPPING SYSTEM\nLoading");
	for(i=0;i<=6;i++)
        {
            fordelay(1000000);
            printf(".");
        }
	menu();
}


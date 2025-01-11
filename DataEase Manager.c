#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct cricket
{
	char pname[20];
	char tname[20];
	int avg;
	int age;
	char gen[10];
	
}player[1000],temp;
struct car
{
	int regno;
	float price;
	char fuel[10];
	char trans[20];
	char caown[100];
}c[10000],tem;
struct student
{
	char stname[100];
	int stno;
	char sname[1000];
	int sub[6];
	char gen[10];
	
}stud[1000],t;

void stu();
void cric();
void ca();


int main()
{
	int choice;
	printf("Enter:\n 1 for Cricket Data entry\n2 for Student data entry\n3 for car data entry\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		cric();
		break;
		case 2:
		stu();
		break;
		case 3:
		ca();
		break;
		
		default:
		printf("Enter appropriate options available\n");
	}
}

//CRICKET DATA//
void cric()
{
	int i,n,choice,x,j,a,c=0;
	char limit[20];
    char g[10];
	printf("Enter the Number of players: ");
	scanf("%d",&n);
	printf("Enter the Details of %d players\n",n);
	printf("Enter\n");
	//Accepting Data//
	for(i=0;i<n;i++)
	{   
		printf(" Name of the Player%d: ",i+1);
		fflush(stdin);
		gets(player[i].pname);
	    printf(" Team name of the Player%d: ",i+1);
	    fflush(stdin);
		gets(player[i].tname);
		printf(" Average of the Player%d: ",i+1);
		fflush(stdin);
		scanf("%d",&player[i].avg);
		printf(" Age of the Player%d: ",i+1);
		fflush(stdin);
		scanf("%d",&player[i].age);
		printf(" Gender: ",i+1);
		fflush(stdin);
		gets(player[i].gen);
		printf("\n");
	}
	
	//Sorting//
	for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(strcmp(player[i].pname,player[j].pname)>0)
				{
					temp=player[j];
					player[j]=player[i];
					player[i]=temp;
					
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;player[i].pname[j]!='\0';j++)
			{
				player[i].pname[j]= toupper(player[i].pname[j]);
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;player[i].tname[j]!='\0';j++)
			{
				player[i].tname[j]= toupper(player[i].tname[j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;player[i].gen[j]!='\0';j++)
			{
				player[i].gen[j]= toupper(player[i].gen[j]);
			}
		}
		
	//USER CHOICE//	
	printf("Enter:\n1 to search for players who are above the required average\n2 to Display the full list of Players\n3 To sort players on the basis of age\n4 To display Male cricketers/Female cricketers\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter the Required average to sort players: ");
		scanf("%d",&x);
		for(i=0;i<n;i++)
		{
			if(player[i].avg>=x)
			{
				printf("\nPlayer%d:\n Player name: %s\n Player's Team: %s\n Player's Average: %d\n Age= %d\n Gender= %s\n",i+1,player[i].pname,player[i].tname,player[i].avg,player[i].age,player[i].gen);
				c++;
				printf("\n");
			}
		}
		if(c==0)
		printf("THERE IS NO SUCH PLAYER WHO IS ABOVE THE PROVIDED AVERAGE\n");
		break;
		
		case 2:
		for(i=0;i<n;i++)
		{
			printf("Player%d:\n Name= %s\n Team Name= %s\n Average= %d\n Age= %d\n Gender= %s\n",i+1,player[i].pname,player[i].tname,player[i].avg,player[i].age,player[i].gen);
            printf("\n");
			}
			break;
		
		
		case 3:
		printf("Enter the Age limit: ");
		scanf("%d",&a);
		printf("To sort players above the age limit or Below ?:  ");
		scanf("%s",&limit);
		c=0;
	
		
		for(i=0;i<n;i++)
		{
			if(limit[0]=='A'||limit[0]=='a')
			{
			   if(player[i].age>a)
			   { 
			   printf("\nPlayer%d:\n Name= %s\n Team Name= %s\n Average= %d\n Age= %d\n Gender= %s\n",i+1,player[i].pname,player[i].tname,player[i].avg,player[i].age,player[i].gen);
			   	  c++;
			   	  printf("\n");
					 }
				  
			}
			else if(limit[0]=='B'||limit[0]=='b')
			{
				if(player[i].age<=a)
			{ 
				printf("\nPlayer%d:\n Name= %s\n Team Name= %s\n Average= %d\n Age= %d\n Gender= %s\n",i+1,player[i].pname,player[i].tname,player[i].avg,player[i].age,player[i].gen);
				c++;
				printf("\n");
				}
				
			}
			
		}
		if(c==0)
		printf("THERE IS NO SUCH PLAYER WHO IS %s THE PROVIDED AGE LIMIT\n",limit);
		break;
		
		case 4:
		printf("Enter the Gender to display the players: ");
		fflush(stdin);
		scanf("%s",&g);
		g[0]= toupper(g[0]);
		c=0;
		for(i=0;i<n;i++)
		{
			
			if(player[i].gen[0]==g[0])
		  {
  			printf("\nPlayer%d:\n Name= %s\n Team Name= %s\n Average= %d\n Age= %d\n Gender= %s\n",i+1,player[i].pname,player[i].tname,player[i].avg,player[i].age,player[i].gen);
			c++;
		  }
		    printf("\n");
		}
		if(c==0)
		printf("THERE IS NO SUCH PLAYER UNDER %s SECTION\n",g);
		
	}
		
		
	}
	//END//


//STUDENT's DATA//
void stu()
{
	int i,j,n,choice,x,l,m,c=0,q;
	char limit[10];
	
	printf("Enter the Number of Students:  ");
	scanf("%d",&n);
	printf("Enter the Details of the Students:\n");
	
	
	//ACCEPTING DATA//
	for(i=0;i<n;i++)
	{
		printf("The Name of the student%d:  ",i+1);
		fflush(stdin);
		gets(stud[i].stname);
		printf("School name: ");
		fflush(stdin);
		gets(stud[i].sname);
		printf("Seat number: ");
		fflush(stdin);
		scanf("%d",&stud[i].stno);
		printf("Gender: ");
		fflush(stdin);
		scanf("%s",&stud[i].gen);
		
		
		printf("\n");
		
		}
		
		//SORTING//	
	for(i=0;i<n-1;i++)
	{   
	  for(j=i+1;j<n;j++)
	{
		
		if(strcmp(stud[i].stname,stud[j].stname)>0)
		{
			t=stud[j];
			stud[j]=stud[i];
			stud[i]=t;
		}
		
	}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;stud[i].stname[j]!='\0';j++)
		{
			stud[i].stname[j]=toupper(stud[i].stname[j]);
		}
		
		for(j=0;stud[i].sname[j]!='\0';j++)
		{
			stud[i].sname[j]=toupper(stud[i].sname[j]);
		}
		
		for(j=0;stud[i].gen[j]!='\0';j++)
		{
			stud[i].gen[j]= toupper(stud[i].gen[j]);
		}
	}
        
		printf("Enter the Choice:\n1 for To search for a student with help of SEAT NUMBER\n2 Display the Full List\n3 to sort out students on the basis of Seat number\n4 To add more number of students\n");
		fflush(stdin);
	scanf("%d",&choice);
		
	switch(choice)
 {
	case 2:
	for(i=0;i<n;i++)
	{
		printf("Student%d\nName= %s\n",i+1,stud[i].stname);
		printf("School= %s\n",stud[i].sname);
		printf("Seat number= %d\n",stud[i].stno);
		printf("Gender= %s\n",stud[i].gen);
		
		printf("\n");
		
	}
	break;
	
	case 1:
	printf("Enter The Seat number of the student: ");
	scanf("%d",&x);
	fflush(stdin);
	for(i=0;i<n;i++)
	{    
	   if(stud[i].stno==x)
	   printf("\nStudent%d:\nName: %s\nSchoolName: %s\nSeat number: %d\n",i+1,stud[i].stname,stud[i].sname,stud[i].stno,stud[i].gen);
	   c++; 
	}
	if(c==0)
	printf("THERE IS NO SUCH STUDENT WITH THE SEAT NUMBER %d\n",x);
	break;
	
	case 3:
	printf("Enter the Seat number: ");
	scanf("%d",&l);
	fflush(stdin);
	printf("Above or Below ?: ");
	scanf("%s",&limit);
	for(i=0;i<strlen(limit);i++)
	limit[i]=toupper(limit[i]);
	c=0;
	
	for(i=0;i<n;i++)
{
    if(limit[0]=='A')
  {
  	if(stud[i].stno>l)
	printf("\nStudent%d:\nName: %s\nSchoolName: %s\nSeat number: %d\n",i+1,stud[i].stname,stud[i].sname,stud[i].stno,stud[i].gen);
	c++;
	printf("\n");
  }
  else if (limit[0]=='B')
  {
  	if(stud[i].stno<=l)
  	printf("Student%d:\nName: %s\nSchoolName: %s\nSeat number: %d\nGender= %s\n",i+1,stud[i].stname,stud[i].sname,stud[i].stno,stud[i].gen);
  	c++;
	  printf("\n");
  }
}
  if(c==0)
   printf("THERE IS NO SUCH STUDENT WHO IS %s THE PROVIDED SEAT NUMBER\n",limit);
	break;
	
	
	case 4:
	printf("Enter the number of Students that are to be added to the list: ");
	scanf("%d",&m);
	q=n;
	n=n+m;
	//ACCEPTING MORE STUDENTS//
	printf("Enter the Details of the students: ");
	printf("Enter\n");
	for(i=1;i<=m;i++)
	{
		printf("The Name of the student%d:  ",q+i);
		fflush(stdin);
		gets(stud[n-i].stname);
		printf("School name: ");
		fflush(stdin);
		gets(stud[n-i].sname);
		printf("Seat number: ");
		fflush(stdin);
		scanf("%d",&stud[n-i].stno);
		printf("Gender: ");
		fflush(stdin);
		scanf("%s",&stud[n-i].gen);
		
	}
	break;
	
	default:
	printf("Enter valid options that are available\n");
	break;

	
	}
	for(i=0;i<n-1;i++)
	{   
	  for(j=i+1;j<n;j++)
	{
		
		if(strcmp(stud[i].stname,stud[j].stname)>0)
		{
			t=stud[j];
			stud[j]=stud[i];
			stud[i]=t;
		}
		
	}
	}
	
	//UPPER CASE//
	for(i=0;i<n;i++)
	{
		for(j=0;stud[i].stname[j]!='\0';j++)
		{
			stud[i].stname[j]=toupper(stud[i].stname[j]);
		}
		
		for(j=0;stud[i].sname[j]!='\0';j++)
		{
			stud[i].sname[j]=toupper(stud[i].sname[j]);
		}
		
		for(j=0;stud[i].gen[j]!='\0';j++)
		{
			stud[i].gen[j]= toupper(stud[i].gen[j]);
		}
	}
	
	printf("\nDo you want to dislay the full list\nEnter:\n 1 for yes\n2 for No\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		for(i=0;i<n;i++)
		{ printf("Student%d:\nName: %s\nSchool name: %s\nSeat number: %d\nGender= %s\n",i+1,stud[i].stname,stud[i].sname,stud[i].stno,stud[i].gen);
			printf("\n");
			}
			break;
  
	}
 }
//END//
	
	
	

//CAR DATA//
void ca()
{
	int i,n,j,x,choice,co=0,flag=0;
	
	char fu[10];
	printf("Enter The Number of Cars: ");
	scanf("%d",&n);
	printf("Enter the Details of %d cars(ENTER IN CAPITALS):\n",n);
	for(i=0;i<n;i++)
	{
		printf("Car%d\n",i+1);
		printf("The Owner of the Car: ");
		fflush(stdin);
		gets(c[i].caown);
		printf("The REGISTRATION Number of car: ");
		fflush(stdin);
		scanf("%d",&c[i].regno);
		printf("The Price of Car: ");
		fflush(stdin);
		scanf("%f",&c[i].price);
		printf("The Tranmission of Car: ");
		fflush(stdin);
		gets(c[i].trans);
		printf("The Fuel Type of Car: ");
		fflush(stdin);
		gets(c[i].fuel);
		printf("\n");
	}
	
	//ARRANGING THE RECORDS//
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(c[i].caown,c[j].caown)>0)
			{
				tem= c[j];
				c[j]=c[i];
				c[i]=tem;
			}
		}
	}
	
	//UPPER CASE//
	for(i=0;i<n;i++)
	{
		for(j=0;c[i].caown[j]!='\0';j++)
		{
			c[i].caown[j]= toupper(c[i].caown[j]);
		}
		
		for(j=0;c[i].fuel[j]!='\0';j++)
		{
			c[i].fuel[j]= toupper(c[i].fuel[j]);
		}
		
			for(j=0;c[i].trans[j]!='\0';j++)
		{
			c[i].trans[j]= toupper(c[i].trans[j]);
		}
	}
	printf("Enter\n");
	
	//USER CHOICE OPERATIONS//
	printf("1 to search for a car\n2 To display the list of cars\n3 To sort the cars on the basis of FUEL TYPE\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter the Registration of the Car: ");
		scanf("%d",&x);
		for(i=0;i<n;i++)
		{
			if(c[i].regno==x)
			flag=1;
			if(flag==1)
			break;
			
		
		
		}
		if(flag==1)
		printf("CAR %d\nOwner of the Car= %s\nREGISTRATION Number= %d\nTransmission of the Car= %s\nFUEL TYPE of the Car= %s\nPrice of the Car= %f\n",i+1,c[i].caown,c[i].regno,c[i].trans,c[i].fuel,c[i].price);
		else
		printf("\nTHE REGISTRATION number entered does not belong to any car\n");
	    break;
	    
	    case 2:
	    for(i=0;i<n;i++)
	    {
    		printf("Car%d:\nOwner of the car= %s\nREGISTRATION number= %d\nTransmission of the car= %s\nFUEL TYPE of the car= %s\nPrice of the Car= %f\n",i+1,c[i].caown,c[i].regno,c[i].trans,c[i].fuel,c[i].price);
    	   printf("\n");       
		   }
    	break;
    	
    	case 3:
    	printf("Enter the Fuel type: ");
    	fflush(stdin);
    	gets(fu);
    	fu[0]= toupper(fu[0]);
    	co=0;
    	for(i=0;i<n;i++)
    	{
	    	j=0;
	    	if(c[i].fuel[j]==fu[j])
	    	printf("\nCar%d:\nOwner of the car= %s\nREGISTRATION number= %d\nTransmission of the car= %s\nFUEL TYPE of the car= %s\nPrice of the Car= %f\n",i+1,c[i].caown,c[i].regno,c[i].trans,c[i].fuel,c[i].price);
	    	co++;
	    	printf("\n");
	    }
	    if(co==0)
	    printf("THERE DOES NOT EXIST A CAR WHO IS HAVING %s FUEL TYPE\n",fu);
	    break;
	    
     default:
     printf("PLEASE ENTER VALID OPTIONS AVAILABLE\n");  
    	  
  }
}
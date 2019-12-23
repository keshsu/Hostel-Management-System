#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
void menu();
void logo();

  void addrecords(void);
  void editrecords(void);
  void preview_single_record(void);
  void preview_all_records(void);
  void deleterecords(void);
  void setting(void);

  struct records
 {
	char name[40];
	int id;
	int roomno;
	float payment;
	char contactno[15];
	char parentscontactno[15];
	char parmanentaddress[50];
 };

int gd=DETECT,gm;
void main()
{
	FILE *fp;
	char text[6],ch,pow[6];
	int i=0,pow1;
	clrscr();
       /*	fp=fopen("PASSWORD1.DAT","w");
	printf("enter the new password");
	for(i=0;i<6;i++)
	{
		pow[i]=getch();
		printf("*");
		fwrite(&pow[i],sizeof(pow[i]),1,fp);
	}
	fclose(fp);
	fp=fopen("PASSWORD1.DAT","r");
	for(i=0;i<6;i++)
	{
		fread(&pow[i],sizeof (pow[i]),1,fp);
		printf("%c",pow[i]);
	}*/
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	logo();
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t");
	printf("Enter The Password\n\n");
	printf("\t\t\t\t");
	rectangle(255,125,400,145);
	lable1:// password entry
	pow1=0;
	while(1)
	{
		pow1=getch();
		if(pow1==13)
		{
			pow1=0;
			break;
		}
		else if(pow1==8)
		{
			i--;
		       printf("\b \b");
		}
		else
		{

				text[i]=pow1;
				printf("*");
				i++;
		}
	}
	fp=fopen("PASSWORD1.DAT","r");
	for(i=0;i!=EOF;i++)
	{
		fread(&pow[i],sizeof (pow[i]),1,fp);
		if(text[i]!=pow[i])
		{
			break;
		}
		else if(i==5)
		{
			goto lable5;
		}
	}
	printf("\n");
	 printf("WRONG password!!\n");
	 printf("\tDo you want try more(y/n)=_\b");
	 lable2:
	 scanf("%c",&ch);
	 if(ch=='\n')
		{
			ch='\0';
			goto lable2;
		}
	else if(ch=='y')
	 {
		printf("\n please enter the password correctly=");
		goto lable1;
	 }
	 else
	 {
		exit(0);
	 }
	lable5:
	menu();
	fclose(fp);
	getch();
	closegraph();
}
void menu()
{
	char choice;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	Label100:
	system("cls");
	textbackground(BLUE);

	while(1)
	{
	  system("cls");
	  textbackground(YELLOW);
	  cprintf("ACCESS GRANTED");
	  printf("\n\t\t\t");
	  printf("\n\t\t\t1) ADD RECORDS\n");
	  printf("\n\t\t\t2) EDIT &DELETE RECORDS\n");
	  printf("\n\t\t\t3) PREVIEW RECORDS\n");
	  printf("\n\t\t\t4) SETTING\n");
	  printf("\n\t\t\t5) Exit\n");
	  printf("\n\nEnter your choice:_\b");
	  fflush(stdin);
	  choice=getch();
	 switch(choice)
	 {
	   case '1':
	     addrecords();
	     break;

	   case '2':
		printf("\n");
		printf("1) Edit\n");
		printf("2) Delete\n");
		printf("3) Exit\n");
		fflush(stdin);
		choice=getch();
	    switch(choice)
	      {
		case '1':
		       editrecords(); //edit name,room no,id,contact no,parents contact no,address only.
		       //break;
		       goto Label100;

		case '2':
		       deleterecords();
		       //break;
		       goto Label100;

		case '3':
		       goto Label100;

	      }

	   case '3':
		printf("\n");
		printf("1) preview_single_record\n");
		printf("2) preview_all_record\n");
		printf("3) Exit\n");
		fflush(stdin);
		choice=getch();
	    switch(choice)
	      {
		case '1':
		       preview_single_record(); //edit name,room no,id,contact no,parents contact no,address only.
		       //break;
		       goto Label100;

		case '2':
		       preview_all_records();
		       //break;
		       goto Label100;

		case '3':
		       goto Label100;

	      }


	   /* case '4':
		printf("\t\t<<<<settings menu>>>>");
		printf("\n\n");
		printf("\n");
		printf("1) password settings\n");
		printf("2) Data recovery settings\n");
		printf("3) Exit\n");
		fflush(stdin);
		choice=getch();
	    switch(choice)
	      {
		case '1':
		       password settings(); //edit name,room no,id,contact no,parents contact no,address only.
		       //break;
		       goto Label100;

		case '2':
		       Data recovery();
		       //break;
		       goto Label100;

		case '3':
		       goto Label100;

	      }

	     break; */

	   case '5':
		clrscr();
		gotoxy(25,10);
		_setcursortype(_NOCURSOR);
		textcolor(BLACK);
		cprintf("THANKS FOR USING THIS SOFTWARE");
		getch();
		exit(1);
	 }
     }
  }


 void addrecords()
   {

	       /*	FILE *fp1;
		char another;
		system("cls");
		initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
		fp1=fopen("FILE10.DAT","a+");
		if(fp1==NULL)
			{
				puts("Cannot Open file");
				exit(0);

			}
		fseek(fp1,0,SEEK_END);
		another='y';
		while(another=='y')
			{    */
	FILE *fp;
	char another;
	struct records r;
	long int recsize;

	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	textbackground(WHITE);
	cprintf("****ADDING RECORDS****");
	fp=fopen("PROGRAM.DAT","ab+");
	if(fp==NULL)
	      {

		fp=fopen("PROGRAM.DAT","wb+");
		if(fp==NULL)
		 {
		  puts("Cannot Open file");
		  exit(0);
		 }
	      }
	recsize=sizeof(r);
	fseek(fp,0,SEEK_END);
	rewind(fp);
	another='y';
	       while(another=='y')
		{
			initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
			outtextxy(207,10,"ADDING RECORD");
			printf("\n\n\n\n\n\n");
			rectangle(180,95,400,112);//name box
			rectangle(180,125,400,145);//id box
			rectangle(180,158,400,177);//room box
			rectangle(180,189,400,209);//contact no box
			rectangle(180,221,400,241);//parents no
			rectangle(180,252,400,274);//permemnet address
			outtextxy(3,98,"student full name:");
			outtextxy(3,130,"student room number:");
			outtextxy(3,162,"student id number:");
			outtextxy(3,194,"student phone number:");
			outtextxy(3,226,"parents phone number:");
			outtextxy(3,258,"permanent address:");
			printf("Student full name:\t");
			rectangle(180,95,400,112);
			gets(r.name);
			printf("\nStudent room number:\t");
			rectangle(180,125,400,145);
			scanf("%d",&r.roomno);
			printf("\nStudent ID number:\t");
			rectangle(180,158,400,177);
			scanf("%d",&r.id);
			printf("\nStudent phone number:\t");
			rectangle(180,189,400,209);				scanf("%s",&r.contactno);
			printf("\nParents phone number:\t");
			rectangle(180,221,400,241);
			scanf("%s",&r.parentscontactno);
			printf("\nPermanent address:\t");
			rectangle(180,252,400,274);
			scanf("%s",&r.parmanentaddress);
			fwrite(&r,recsize,1,fp);
			printf("\nAdd new records(Y/N):");
			fflush(stdin);
			another=getche();
			}
	fclose(fp);
	getch();
   }

  void editrecords()
   {
	FILE *fp;
	char another;
	struct records r;
	int cid;
	long int recsize;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("****EDITING RECORDS****");
	fp=fopen("PROGRAM.DAT","rb+");
	recsize=sizeof(r);
	another='y';
	     while(another=='y')
	      {
		 printf("\n Enter ID of employee to modify:");
		 scanf("%d",&cid);
		 rewind(fp);
		 while(fread(&r,recsize,1,fp)>0)
		 {
		       if(r.id==cid)
			{
				textcolor(GREEN);
				printf("\n Enter new details");
				printf("name:");
				scanf("%s",&r.name);
				printf("room no:");
				scanf("%d",&r.roomno);
				printf("id:");
				scanf("%d",&r.id);
				printf("contact num:");
				scanf("%s",&r.contactno);
				printf("parentscontact num:");
				scanf("%s",&r.parentscontactno);
				printf("parmanentaddress:");
				scanf("%s",&r.parmanentaddress);
				fseek(fp,-recsize,SEEK_CUR);
				fwrite(&r,recsize,1,fp);
				break;
			}
		       else
			{
			 printf("\nID don't Match.. Try again with different ID no.");
			}
		  }
		printf("\n Modify another record (Y/N):");
		fflush(stdin);
		another=getche();
	      }
	fclose(fp);
	getch();
   }

  void deleterecords()
   {
	FILE *fp,*ft;
	char another;
	char stm[40];
	struct records r;
	long int recsize;
	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(RED);
	cprintf("****DELETING RECORDS****");
	fp=fopen("PROGRAM.DAT","rb+");
	recsize=sizeof(r);
	clrscr();
	another='y';
		while(another=='y')
		{
			textcolor(RED);
			printf("\n Enter name of student to delete:");
			scanf("%s",stm);
			ft=fopen("TEMP.DAT","wb+");
			rewind(fp);
			while(fread(&r,recsize,1,fp)>0)
			{
				if(strcmp(r.name,stm)!=0)
				{
				 fwrite(&r,recsize,1,ft);
				}
			}
		fclose(fp);
		fclose(ft);
		remove("PROGRAM.DAT");
		rename("TEMP.DAT","PROGRAM.DAT");
		fp=fopen("PROGRAM.DAT","rb+");
		printf("Delete another Record(y/n):");
		fflush(stdin);
		another=getche();

	}
	fclose(fp);
	getch();

   }

   void preview_single_record()
   {
	FILE *fp;
	struct records r;
	long int recsize;
	int team;
	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	cprintf("****SHOWING specific RECORDS****");
	fp=fopen("PROGRAM.DAT","rb+");
	if(fp==NULL)
	 {
		printf("\n\nNO DATA FOUND\n");
	 }
	else
	 {
	      printf("<<<<<single Data preview>>>>>\n\n");
	      printf("Enter the Id of student whose data you want to have: ");
	      scanf("%d",&team);
	      fseek(fp,0,SEEK_END);
	      rewind(fp);
	      recsize=sizeof(r);
	      while(fread(&r,recsize,1,fp)>0)
	      {
		if(r.id==team)
		{
		textcolor(GREEN);
		printf("\nName\tRoom no\tID\tContact No\tParents Contact No\tPermanent address");
		printf("\n%s",r.name);
		printf("\t%d",r.roomno);
		printf("\t%d",r.id);
		printf("\t%s",r.contactno);
		printf("\t%s",r.parentscontactno);
		printf("\t%s",r.parmanentaddress);
	      }
	      }
	}
    fclose(fp);
    getch();
   }


   void preview_all_records()
   {
	FILE *fp;
	struct records r;
	long int recsize;
	fflush(stdin);
	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	cprintf("****SHOWING ALL RECORDS****");
	fp=fopen("PROGRAM.DAT","rb+");
	if(fp==NULL)
	 {
		printf("\n\nNO DATA FOUND\n");
	 }
	else
	 {
	      fseek(fp,0,SEEK_END);
	      rewind(fp);
	      recsize=sizeof(r);
	      printf("\nName\tRoom no\tID\tContact No\tParents Contact No\tPermanent addres");
	      while(fread(&r,recsize,1,fp)>0)
	      {
		textcolor(GREEN);
		printf("\n%s",r.name);
		printf("\t%d",r.roomno);
		printf("\t%d",r.id);
		printf("\t%s",r.contactno);
		printf("\t%s",r.parentscontactno);
		printf("\t\t%s",r.parmanentaddress);
	      }
	}
    fclose(fp);
    getch();

   }



void logo()
{
       circle(308,40,30);
	circle(309,41,30);
	circle(310,42,30);
	circle(311,43,30);
	circle(312,44,30);
	circle(313,46,30);
	circle(314,48,30);
	outtextxy(288,39,"hostel");
	line(287,32,301,32);
	line(344,50,320,50);
}

/*
void settings()
{
	FILE *fp;
	struct records r;
	long int recsize;
	fflush(stdin);
	system("cls");
	gotoxy(2,5);
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	cprintf("****SHOWING ALL RECORDS****");
	fp=fopen("PROGRAM.DAT","rb+");
	if(fp==NULL)
	 {
		printf("\n\nNO DATA FOUND\n");
	 }
	else
	 {
	      fseek(fp,0,SEEK_END);
	      rewind(fp);
	      recsize=sizeof(r);
	      while(fread(&r,recsize,1,fp)>0)

	 }

  /*	char c,name[100];
	int choice,id;
	while(1)
	{
	choice=0;
	system("cls");

	printf("\n\t\t\t");
	printf("\n\t\t\t1) ADD record");
	printf("\n\t\t\t2) EDIT record");
	printf("\n\t\t\t3) LIST record");
	printf("\n\t\t\t4) SYSTEM setting");
	printf("\n\t\t\t5) EXIT");
	printf("\n\n enter your choice=_\b");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			system("cls");
			initgraph(&gd,&gm,"c:\\turboc3\\BGI");
			printf(" ADDING RECORD");
			rectangle(0,0,120,20);
			printf("\n\n\t\t");
			printf("student ID= ");
			rectangle(220,30,300,50);
			scanf("%d",&id);
			break;
		}
		case 2:
		{
			system("cls");
			printf("editing record");
			break;
		}
		case 3:
		{
			system("cls");
			printf("listing record");
			break;
		}
		case 4:
		{
			system("cls");
			printf("system setting");
			break;
		}
		case 5:
		{
			printf("Are you sure you want to leave??(y/n)");
			lable3:
			scanf("%c",&c);
			if(c=='\n')
			{
				c='\0';
				goto lable3;
			}
			if(c=='y')
			{
				exit(0);
			}
			break;
		}
		default:
		{
			printf("invalid input!!!\n");
			textcolor(RED);
			cprintf(" [make sure u press(1,2,3,4 or 5)]");
			break;
		}
		}
		getch();
	}
}  */
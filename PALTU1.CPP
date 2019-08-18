#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
char stream[3][10]={"pcm","pcb","commerce"};

class student
{
 public:
 long int adno;         //admission number
 char name[80];         //student name
 char fname[80];        //father's name
 char dob[22];          //date of birth
 char alstream[10];     //alloted stream
 float p,c,m,cs,e;      //marks
 void in();
 void strm();
}a;
void student::strm()
{
qw:
clrscr();
for(int i=0;i<3;i++)
 { cout<<"Set Of Streams:";
 cout<<"\t\t"<<stream[i]<<endl;
 }
  cout<<"\nEnter any of the above stream\n";
  cin>>alstream;
  if((!strcmpi(alstream,"pcm"))||(!strcmpi(alstream,"pcb"))||(!strcmpi(alstream,"commerce")))
  cout<<"You entered correct stream";
  else
  cout<<"You entered wrong stream";
  goto qw;
}


void student::in()
{er:
clrscr();
cout<<"Enter student details";
cout<<"Enter Admission Number";
 cin>>adno;
 int duplicate(int);
 int x=duplicate(adno);
 if(x!=0)
 cout<<"You entered correct admission number";
 else
 {
 cout<<"Admission number already exists";
 goto er;
 }
 cout<<"Enter Student name";
 gets(name);
 cout<<"Enter Father's name";
 gets(fname);
 cout<<"Enter Student's date of birth";
 gets(dob);
}
void add()              //add student record
{
 char ch;
 ofstream A("exmng.dat",ios::binary);
 do
 {clrscr();
 a.in();
 a.strm();
 A.write((char*)&a,sizeof(a));
 cout<<"Press Y or y to enter more records";
 cin>>ch;
  }while(ch=='y'||ch=='Y');
 }
 int duplicate(int t)
 {int v;
 ifstream B("exmng.dat",ios::binary);
 while(B.read((char*)&a,sizeof(a)))
 {
 if(a.adno!=t)
 v++;
 }
 B.close();
 return v;
 }
void update()   	//modify student details
{
 long int r;
 char s[10];
 int x=0;
 ifstream A("exmng.dat",ios::binary);
 ofstream B("temp.dat",ios::binary);
 cout<<"Enter admission number whose details are to be modified";
 cin>>r;
 while(A.read((char*)&a,sizeof(a)))
 {
 if(a.adno==r)
 { x++;
  cout<<"Enter admission number ";
  cin>>a.adno;
  cout<<"Enter Student name";
  gets(a.name);
  cout<<"Enter Father's name";
  gets(a.fname);
  cout<<"Enter Student's date of birth";
  gets(a.dob);
 }
    B.write((char*)&a,sizeof(a));
 }
 if(x==0)
 cout<<"Admission number not found";
 else
 cout<<"Record updated";
 remove("exmng.dat");
 rename("temp.dat","exmng.dat");
 B.close();
 A.close();
}
void erase()
{ long int r;
 char s[10];
 int x=0;
 ifstream A("exmng.dat",ios::binary);
 ofstream B("temp.dat",ios::binary);
 cout<<"Enter admission number whose details are to be modified";
 cin>>r;
 while(A.read((char*)&a,sizeof(a)))
 {
  if(a.adno==r)
  x++;
  else
  B.write((char*)&a,sizeof(a));
 }
 if(x==0)
 cout<<"record not found";
 else
 cout<<"record deleted ";
 remove("exmng.dat");
 rename("temp.dat","exmng.dat");
 A.close();
 B.close();
}

void mark()                  //entry of marks
{ int x=0,c=0;
 long int r;
 char s[10],ch;
 ty:
 do
 {
 clrscr();
 cout<<"Enter admission number";
 cin>>r;
 cout<<"Enter stream";
 cin>>s;
 fstream A("exmng.dat",ios::binary|ios::in|ios::out);
 while(A.read((char*)&a,sizeof(a)))
 {
 if(a.adno==r)
 { x++;
  if(!strcmpi(s,a.alstream))
   { c++;
    if(!strcmpi(s,"pcm"))
    {
     cout<<"Physics : ";
     cin>>a.p;
     cout<<"Chemistry : ";
     cin>>a.c;
     cout<<"Maths : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
    else if(!strcmpi(s,"pcb"))
    {
     cout<<"Physics : ";
     cin>>a.p;
     cout<<"Chemistry : ";
     cin>>a.c;
     cout<<"Biology : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
    else if(!strcmpi(s,"commerce"))
    {
     cout<<"Accounts : ";
     cin>>a.p;
     cout<<"Business Studies : ";
     cin>>a.c;
     cout<<"Economics : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
    }
    }
    if(x==0||c==0)
      {
      cout<<"\n\nYou entered wrong admission no./stream";
      goto ty;
      }
    A.write((char*)&a,sizeof(a));
  }
 cout<<"Press Y or y to enter more records otherwise press any key";

 } while(ch=='Y'||ch=='y');


}
void modmark()          //modification of marks
{
 long int r;
 char s[10];
 int x=0;
 cout<<"Enter admission number";
 cin>>r;
 cout<<"Enter chosen stream";
 cin>>s;
 ifstream A("exmng.dat",ios::binary);
 ofstream B("temp.dat",ios::binary);
 while(A.read((char*)&a,sizeof(a)))
 { if(a.adno==r)
   {
    if(!strcmpi(s,a.alstream))
    {
     x++;
     if(!strcmpi(s,"pcm"))
     {
      cout<<"Physics : ";
      cin>>a.p;
      cout<<"Chemistry : ";
      cin>>a.c;
     cout<<"Maths : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
    else if(!strcmpi(s,"pcb"))
    {
     cout<<"Physics : ";
     cin>>a.p;
     cout<<"Chemistry : ";
     cin>>a.c;
     cout<<"Biology : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
    else if(!strcmpi(s,"commerce"))
    {
     cout<<"Accounts : ";
     cin>>a.p;
     cout<<"Business Studies : ";
     cin>>a.c;
     cout<<"Economics : ";
     cin>>a.m;
     cout<<"Computer : ";
     cin>>a.cs;
     cout<<"English : ";
     cin>>a.e;
    }
   }
  }
  B.write((char*)&a,sizeof(a));
 }
 if(x==0)
 cout<<"record not found";
 else
 cout<<"record updated";
 remove("exmng.dat");
 rename("temp.dat","exmang.dat");
 A.close();
 B.close();

}
void msheet()			//marksheet
{
int div;
float o,g;
long int t;
char s[10];
cout<<"Enter your admission number";
cin>>t;
cout<<"Enter your stream";
cin>>s;
ifstream A("exmng.dat",ios::binary);
while (A.read((char*)&a,sizeof(a)))
{
	if(a.adno==t)
{
		if (!strcmpi(a.alstream,s))
{
 if(!strcmpi(s,"pcm"))
      {	o=(a.p+a.c+a.m+a.e+a.cs);
	g=o/5.0;
  if(g>=90)
  div=1;
  else if(g>=75&&g<90)
  div=2;
  else if(g>=60&&g<75)
  div=3;

	clrscr();
cout<<"\n\n"<<setw(49)<<"*8*8*8*8*8*8*8*8*8*8*\n" ;
cout<<setw(46)<<"STUDENT MARKSHEET" ;
cout<<"\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*\n\n";
cout<<"Admission Number :"<<a.adno<<"\t\t\t\t\t"<<"Class : XII\n";
cout<<"Name : "<<a.name<<"\t\t\t\t\t\t"<<"Date Of Birth : "<<a.dob;
cout<<"\n\n";
gotoxy(10,10);
cout<<"\tSubject";
gotoxy(50,10);
cout<<"Marks";
gotoxy(10,12);
cout<<"\tPhysics";
gotoxy(50,12);
cout<<a.p;
gotoxy(10,14);
cout<<"\tChemistry";
gotoxy(50,14);
cout<<a.c;
gotoxy(10,16);
cout<<"\tMaths";
gotoxy(50,16);
cout<<a.m;
gotoxy(10,18);
cout<<"\tComputer Science";
gotoxy(50,18);
cout<<a.cs;
gotoxy(10,20);
cout<<"\tEnglish";
gotoxy(50,20);
cout<<a.e;
gotoxy(10,22);
cout<<"Total";
gotoxy(50,22);
cout<<o;
gotoxy(10,24);
cout<<"Division : "<<div;
gotoxy(50,24);
cout<<"Percent : "<<g<<"%";

      }
    else if(!strcmpi(s,"pcb"))
      {	o=(a.p+a.c+a.m+a.e+a.cs);
	g=o/5.0;
  if(g>=90)
  div=1;
  else if(g>=75&&g<90)
  div=2;
  else if(g>=60&&g<75)
  div=3;
	clrscr();
cout<<"\n\n"<<setw(49)<<"*8*8*8*8*8*8*8*8*8*8*\n" ;
cout<<setw(46)<<"STUDENT MARKSHEET" ;
cout<<"\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*\n\n";
cout<<"Admission Number :"<<a.adno<<"\t\t\t\t\t"<<"Class : XII\n";
cout<<"Name : "<<a.name<<"\t\t\t\t\t\t"<<"Date Of Birth : "<<a.dob;
cout<<"\n\n";
gotoxy(10,10);
cout<<"\tSubject";
gotoxy(50,10);
cout<<"Marks";
gotoxy(10,12);
cout<<"\tPhysics";
gotoxy(50,12);
cout<<a.p;
gotoxy(10,14);
cout<<"\tChemistry";
gotoxy(50,14);
cout<<a.c;
gotoxy(10,16);
cout<<"\tMaths";
gotoxy(50,16);
cout<<a.m;
gotoxy(10,18);
cout<<"\tComputer Science";
gotoxy(50,18);
cout<<a.cs;
gotoxy(10,20);
cout<<"\tEnglish";
gotoxy(50,20);
cout<<a.e;
gotoxy(10,22);
cout<<"Total";
gotoxy(50,22);
cout<<o;
gotoxy(10,24);
cout<<"Division : "<<div;
gotoxy(50,24);
cout<<"Percent : "<<g<<"%";

      }
       else if(!strcmpi(s,"commerce"))
      {	o=(a.p+a.c+a.m+a.e+a.cs);
	g=o/5.0;

  if(g>=90)
  div=1;
  else if(g>=75&&g<90)
  div=2;
  else if(g>=60&&g<75)
  div=3;
	clrscr();
cout<<"\n\n"<<setw(49)<<"*8*8*8*8*8*8*8*8*8*8*\n" ;
cout<<setw(46)<<"STUDENT MARKSHEET" ;
cout<<"\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*\n\n";
cout<<"Admission Number :"<<a.adno<<"\t\t\t\t\t"<<"Class : XII\n";
cout<<"Name : "<<a.name<<"\t\t\t\t\t\t"<<"Date Of Birth : "<<a.dob;
cout<<"\n\n";
gotoxy(10,10);
cout<<"\tSubject";
gotoxy(50,10);
cout<<"Marks";
gotoxy(10,12);
cout<<"\tPhysics";
gotoxy(50,12);
cout<<a.p;
gotoxy(10,14);
cout<<"\tChemistry";
gotoxy(50,14);
cout<<a.c;
gotoxy(10,16);
cout<<"\tMaths";
gotoxy(50,16);
cout<<a.m;
gotoxy(10,18);
cout<<"\tComputer Science";
gotoxy(50,18);
cout<<a.cs;
gotoxy(10,20);
cout<<"\tEnglish";
gotoxy(50,20);
cout<<a.e;
gotoxy(10,22);
cout<<"Total";
gotoxy(50,22);
cout<<o;
gotoxy(10,24);
cout<<"Division : "<<div;
gotoxy(50,24);
cout<<"Percent : "<<g<<"%";
}
}
}
}

}


void report()
{ int p;
clrscr();
 cout<<"\n\n\n\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*8*\n\n" ;
cout<<setw(42)<<"REPORTING MENU" ;
cout<<"\n\n"<<setw(48)<<"*8*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(24,12);
 cout<<"1. Marksheet Of a Student";
 gotoxy(24,14);
 cout<<"2. Return To Main Menu";
 ad:
 gotoxy(18, 22);
 cout<<"ENTER ANY OF THE ABOVE NUMBER : ";
 cin>>p;
 switch(p)
 {
 case 1:
 msheet();	break;
 case 2:
 void menu();
 menu();	break;
 default:
 {cout<<"You entered wrong choice";
 goto ad;}
 }
}
void resp()
{       int p;
  clrscr();
 cout<<"\n\n\n\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*\n\n" ;
cout<<setw(42)<<"RESULT PROCESSING MENU" ;
cout<<"\n\n"<<setw(48)<<"*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(24,12);
 cout<<"1. Entry Of Marks";
 gotoxy(24,14);
 cout<<"2. Modification Of Marks(In case of mistake)";
 gotoxy(24,16);
 cout<<"3. Return To Main Menu";
 ad:
 gotoxy(18, 22);
 cout<<"ENTER ANY OF THE ABOVE NUMBER : ";
 cin>>p;
 switch(p)
 {
 case 1:
 mark();	break;
 case 2:
 modmark();	break;
 case 3:
 {
 void menu();
 menu();	break;
 }
 default:
 {cout<<"You entered wrong choice";
 goto ad;}
 }

}
void stu()
{int p;
 clrscr();
 cout<<"\n\n\n\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*8*\n\n" ;
cout<<setw(42)<<"STUDENT PROCESSING MENU" ;
cout<<"\n\n"<<setw(48)<<"*8*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(24,12);
 cout<<"1. Add New Student";
 gotoxy(24,14);
 cout<<"2. Modify Student Details";
 gotoxy(24,16);
 cout<<"3. Delete Student Record";
 gotoxy(24,18);
 cout<<"4. Return To Main Menu";
 ad:
 gotoxy(18, 22);
 cout<<"ENTER ANY OF THE ABOVE NUMBER : ";
 cin>>p;
 switch(p)
 {
 case 1:
 add();	break;
 case 2:
 update();	break;
 case 3:
 erase();	break;
 case 4:
 {void menu();
 menu();      break; }
 default:
 {cout<<"You entered wrong choice";
 goto ad;}
 }
}


void menu()
{
int p;
clrscr();
 cout<<"\n\n\n\n"<<setw(50)<<"*8*8*8*8*8*8*8*8*8*8*\n\n" ;
cout<<setw(42)<<"MAIN MENU" ;
cout<<"\n\n"<<setw(48)<<"*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(24,12);
 cout<<"1. STUDENT PROCESSING";
 gotoxy(24,14);
 cout<<"2. RESULT PROCESSING";
 gotoxy(24,16);
 cout<<"3. REPORTING";
 gotoxy(24,18);
 cout<<"4. EXIT";
 ad:
 gotoxy(18, 22);
 cout<<"ENTER ANY OF THE ABOVE NUMBER : ";
 cin>>p;
 switch(p)
 {
 case 1:
 stu();	break;
 case 2:
 resp();	break;
 case 3:
 report();	break;
 case 4:
 exit(0);       break;
 default:
 {cout<<"You entered wrong choice";
 goto ad;}
 }
	getch();
 }




void main()
{
 clrscr();
 gotoxy(24,4);
 cout<<"*8*8*8*8*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(24,7);
 cout<<"EXAMINATION MANAGEMENT SYSTEM";
 gotoxy(24,10);
 cout<<"*8*8*8*8*8*8*8*8*8*8*8*8*8*8*";
 gotoxy(25,16);
 cout<<"PRESS ANY KEY FOR MAIN MENU";
 getch();
 clrscr();menu();
}

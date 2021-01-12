#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

fstream file;
void insertfile();
void readfile();
void updatefile(int x,int key);
int main();
int stamp[]={1,2,5,10};							
int available[]={100,100,100,100};

void StampDistribution(int amt)
{

	int stmp[10],c,k=0;
	for(int c=3;c>=0;c--)
	{

		while(amt>stamp[c]&& available[c]>0)
		{
			amt-=stamp[c];
			stmp[k]=stamp[c];
			available[c]-=1;	
			updatefile(c,-1);		
			k++;
		}
		stmp[k]=amt;
	}
	cout<<"\n Stamp delivered :  ";
	for(c=0;c<=k;c++)
		cout<<stmp[c]<<"\t";										
	
}
 void user()
 {
 	int stmp,ch;
 	while(1)
 	{
 		cout<<"\n\t\t\t\tLIMIT PER PERSON:: 95";
 		cout<<"\n\t 1.BUY\n\t 2. EXIT\n";
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:cout<<"\n\t ENTER THE AMOUNT OF THE REQUIRED STAMP:";
 					cin>>stmp;
 					if(stmp>95)
 					{
 						cout<<"\n\t AMOUNT OF STAMP EXCEEDS THE LIMIT";
 						user();
 					}
 					else
 					{
 					StampDistribution(stmp);
 					break;
 				}
 			case 2: system("cls");
 					main();
 			default:cout<<"\n\tInvalid Input";
		 }
	 }
}
	 
	 void add()
	 {
	 	int st,n;
	 	cout<<"\n\t ENTER THE TYPE OF THE STAMP:: ";
	 	cin>>st;
	 	cout<<"\n\t ENTER THE NUMBER OF STAMP TO BE ADDED:: ";
	 	cin>>n;
	 	if(st==1)
	 	{
	 		available[0]=available[0]+n;
	 		updatefile(0,n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 1 RUPEE STAMP IS ADDED"<<endl;
		 }
		 	else if(st==2)
	 	{
	 		available[1]=available[1]+n;
	 		updatefile(1,n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 2 RUPEE STAMP IS ADDED"<<endl;
		 }
		 else	if(st==5)
	 	{
	 		available[2]=available[2]+n;
	 		updatefile(2,n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 5 RUPEE STAMP IS ADDED"<<endl;
		 }
		 	else
	 	{
	 		available[3]=available[3]+n;
	 		updatefile(3,n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 10 RuUPEE STAMP IS ADDED"<<endl;
		 }
		 cout<<"\n\t\t AFTER ADDING STOCK"<<endl;
		 	
		 for(int i=0;i<4;i++)
		 {
		 	cout<<stamp[i]<<":"<<available[i]<<endl;
		 }
	 }
	  void reduce()
	 {
	 	int st,n;
	 	cout<<"\n\t ENTER THE TYPE OF THE STAMP:: ";
	 	cin>>st;
	 	cout<<"\n\t ENTER THE NUMBER OF STAMP TO BE REMOVED:: ";
	 	cin>>n;
	 	if(st==1)
	 	{
	 		if(available[0]>=n)
	 		{
	 		available[0]=available[0]-n;
	 		updatefile(0,-n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 1 RUPEE STAMP IS REMOVED"<<endl;
	 	}
	 	else
	 	{
	 		cout<<"\n\t\t  YOUR INPUT EXCEEDS OUR CURRENT STOCK LIMIT!!"<<endl;
		 }
		 }
		else if(st==2)
	 	{
	 		if(available[1]>=n)
	 		{
	 		available[1]=available[1]-n;
	 		updatefile(1,-n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 2 RUPEE STAMP IS REMOVED"<<endl;
	 	}
	 	else
	 	{
	 		cout<<"\n\t\t  YOUR INPUT EXCEEDS OUR CURRENT STOCK LIMIT!!"<<endl;
		 }
		 }
		 else if(st==5)
	 	{
	 		if(available[2]>=n)
	 		{
	 		available[2]=available[2]-n;
	 		updatefile(2,-n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 5 RUPEE STAMP IS REMOVED"<<endl;
	 	}
	 	else
	 	{
	 		cout<<"\n\t\t  YOUR INPUT EXCEEDS OUR CURRENT STOCK LIMIT!!"<<endl;
		 }
		 }
		 else
	 	{
	 		if(available[3]>=n)
	 		{
	 		available[3]=available[3]-n;
	 		updatefile(3,-n);
 			readfile(); 	
	 		cout<<n<<"\n\t\t 10 RUPEE STAMP IS REMOVED"<<endl;
	 	}
	 	else
	 	{
	 		cout<<n<<"\n\t\t  YOUR INPUT EXCEEDS OUR CURRENT STOCK LIMIT!!"<<endl;
		 }
		 }
		 cout<<"\n\t\t AFTER REMOVING STOCK"<<endl;
		 	
		 for(int i=0;i<4;i++)
		 {
		 	cout<<stamp[i]<<":"<<available[i]<<endl;
		 }
	 }
	 void check()
	 {
	 	cout<<"\n\t\t STOCKS AVAILABLE TODAY"<<endl;
	 	for(int i=0;i<4;i++)
		 {
		 	cout<<stamp[i]<<":"<<available[i]<<endl;
		 }
	 }
	 void branchpostmaster()
	 { int ch;
	 	string username,password;
	 	cout<<"\n\t\t\t\t\t\tBRANCH POST MASTER LOGIN\n";
	 	cout<<"\n\tENTER YOUR BRANCHID:: ";
	 	cin>>username;
	 		cout<<"\n\tENTER THE PASSWORD:: ";
			 cin>>password;
	 		if(username=="1831003"&&password=="rspuram")
	 		{
                while(1)
                {
				
	 			cout<<"\n\t\t\t\tRS PURAM POST OFFICE";
	 			cout<<"\n\t 1-CHECK THE STOCK";
	 			cout<<"\n\t 2-ADD STOCK";
	 			cout<<"\n\t 3-REDUCE THE STOCK";
	 			cout<<"\n\t 4-EXIT";
	 			cout<<"\n\t ENTER YOUR CHOICE:: ";
	 			cin>>ch;
	 			switch(ch)
	 			{
	 				case 1:
	 					check();
	 					break;
	 				case 2:
	 					add();
	 					break;
	 				case 3:
	 					reduce();
	 					break;
	 				case 4:
	 					system("cls");
	 					main();
	 				default:cout<<"\n\tInvalid Input";
	 							}
	 						}}
	 						else
	 						{
	 							cout<<"\n\t SORRY!\n\t YOUR USERNAME OR PASSWORD ARE WRONG!\n\t ENTER THE VALID USERNAME AND PASSWORD";
							 }
				 }
		void insertfile()
		{
		 file.open("stamp.dat",ios::out|ios::binary);
		 for(int i=0;i<4;i++)
		 file.write((char *)&available[i],sizeof(available));
		 file.close();	
		}	 
		void readfile()
		{
			int i=0;
			file.open("stamp.dat",ios::in|ios::binary);
			while(file.read((char *)&available[i],sizeof(available)))
			{
			i++;
			}
			file.close();
			//cout<<"read"<<endl;	
			}
		void updatefile(int x,int key)
		{
			int i=0;
			int arr[10];
			//cout<<"enter :"<<endl;
				file.open("stamp.dat",ios::in|ios::binary);
				//file.seekg(sizeof(int)*x,ios::beg);
				while(file.read((char *)&arr[i],sizeof(available)))
				{
					//cout<<"enter :"<<endl;
					i++;
				}
				file.close();
				
				//for(int j=0;j<i;j++)
				//cout<<"a is ::"<<arr[j]<<endl;
				
				arr[x]=arr[x]+key;
				
		    file.open("stamp.dat",ios::out|ios::binary);
		    for(int i=0;i<4;i++)
		    file.write((char *)&arr[i],sizeof(available));
		    file.close();	
		}
		
 int main()
 {
 	int ch;
 	//insertfile();
 	//readfile();
 	//updatefile(0,10);
 	readfile();
 	while(1)
 	{
 		cout<<"\n\n\t\t\t\t\t\tRS PURAM POST OFFICE";
 		cout<<"\n\t 1.BRANCHPOSTMASTER";
 		cout<<"\n\t 2.CUSTOMER";
 		cout<<"\n\t 3.EXIT";
 		cout<<"\n\t ENTER THE CHOICE :";
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:
 				branchpostmaster();
 				break;
 				case 2:
 					user();
 					break;
 					case 3:
 						exit(0);
 					}
 				}
 				return 0;
 		}

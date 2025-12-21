#include<iostream>
#include<fstream>
using namespace std;
//criminal structure 
struct criminal
{
	string name;
	int age;
	int criminal_id;
	string crimes_commited;
	string dateOfArrest;
	string address;
	string punishment;
	string nickname;
	string anygang;
};
//function prototypes
void addrecord();
void editrecord();
void deleterecord();
void  searchrecord();
void displayrecord();
//main function
int main()
{
   int opt;
   char choice;
   do
   {	system("cls");
        system("color 30");
       system("color 0E");
        cout<<"_________________________________________: WELCOME TO CRIMINAL RECORD SYSTEM :_________________________________________"<<endl;
        cout<<"_______________________________________________________________________________________________________________________"<<endl;
        cout<<"\n\n\n\t\t\t\t*\tPress 1 for Add New Record of Crimminal        *"<<endl;
        cout<<"\t\t\t\t*\tPress 2 for Edit a Record of Criminal          *"<<endl;
        cout<<"\t\t\t\t*\tPress 3 for Delete a Criminal Record           *" <<endl;
        cout<<"\t\t\t\t*\tPress 4 for Search any Criminal Record         * "<<endl;
        cout<<"\t\t\t\t*\tPress 5 for Viewing all Records                * "<<endl;
        cout<<"\t\t\t\t*\tEnter a your Choice : ";
        cin>>opt;
        switch(opt)
        {
        	case 1:
		       {
		       	addrecord();
		       	break;
			} 
        	case 2:
		       {
		              editrecord();
				      break;	
			    }
		case 3:
		       {
		              deleterecord();
        		       break;    	
			}
		case 4: 
		       {
		              searchrecord();
				break;	
		       }
		case 5:
		       {
		       	displayrecord();
		       	break;
			}
		default :
		        {
		        	cout<<"Press correct Key :"<<endl;
			 }			  		
	 }
	 cout<<"Do You Want to Continue  press y/Y or n/N:  "<<endl;
	 cin>>choice;
    }while(choice=='y'||choice=='Y');
    
    return 0;
}
  
  //function defintions 
void addrecord()
{
	system("cls");
	criminal cr;
	cin.ignore();
	cout<<"Enter a NAME  of criminal : ";
	getline(cin,cr.name);
//	cin.ignore();
	cout<<"enter a AGE OF criminal : ";
	cin>>cr.age;
	cin.ignore();
	cout<<"Enter a CRIMINAL id : ";
	cin>>cr.criminal_id;
	cin.ignore();
	cout<<"Enter Crime Commited by a criminal : ";
	getline(cin,cr.crimes_commited);
	cout<<"Enter a Date of Arrest:  ";
	getline(cin,cr.dateOfArrest);
	cout<<"Enter a Adress of Criminal : ";
	getline(cin,cr.address);
	cout<<"Enter a CONVICTION OR PUNISHMENT : ";
	getline(cin,cr.punishment);
	cout<<"Enter any NICKNAME of criminal (optional ) :";
	getline(cin,cr.nickname);
	cout<<"Can CRIMINAL AFFILIATE WITH ANY GANG enter a name of GANG : ";
	getline(cin,cr.anygang);
	fstream file;
	file.open("criminalrecordfile.txt",ios::app);
	if(file)
	{
		file<<cr.name<<"\t"<<cr.age<<"\t"<<cr.criminal_id<<"\t"<<cr.crimes_commited<<"\t"<<cr.dateOfArrest<<"\t"<<cr.punishment<<"\t"<<cr.nickname<<"\t"<<cr.address<<"\t"<<cr.anygang<<endl;
		cout<<"Record is ADDED successfully :"<<endl;
		file.close();
	}
	else
	{
		cout<<"file is not opnened succesfully : "<<endl;
	}
}
//display function definition
void displayrecord()
{
	system("cls");
	criminal cr;
	fstream file;
	cout<<"__________________ALL CRIMINAL RECORDS__________________"<<endl;
	file.open("criminalrecordfile.txt",ios::in);
	if(file)
	{
		file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
		while(!file.eof())
		{
	
	    cout<<"\n\t\tName :                   "<<cr.name<<endl;
		cout<<"\t\tAge :                    "<<cr.age<<endl;
		cout<<"\t\tCriminal_ID :            "<<cr.criminal_id<<endl;
		cout<<"\t\tCrimes Commited :        "<<cr.crimes_commited<<endl;
		cout<<"\t\tDate_of_Arest :          "<<cr.dateOfArrest<<endl;
		cout<<"\t\tAddress of criminal :    "<<cr.address<<endl;
		cout<<"\t\tPunishment  :            "<<cr.punishment<<endl;
		cout<<"\t\tNICKNAME :               "<<cr.nickname<<endl;
		cout<<"\t\tGANG :                   "<<cr.anygang<<endl;
		cout<<"_______________________________________________________"<<endl;
		cout<<"_______________________________________________________"<<endl;	
		file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
	       
	      }
	      file.close();
       }
	else
	{
		cout<<"file not open succefully :"<<endl;
	}
	
}
//search function 
void searchrecord()
{
	string cs;//criminal search by name
	int temp=1;
	cin.ignore();
	criminal cr;
	system("cls");
	cout<<"Enter a name of Criminal : ";
	getline(cin,cs);
	fstream file;
	file.open("criminalrecordfile.txt",ios::in);
	if(file)
	{
		file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
		while(!file.eof())
		{
		 	if(cr.name==cs)
		 	{
		 		 temp=0;
	                      cout<<"Name : "<<cr.name<<endl;
		               cout<<"Age : "<<cr.age<<endl;
		               cout<<"Criminal_ID : "<<cr.criminal_id<<endl;
		               cout<<"Crimes Commited : "<<cr.crimes_commited<<endl;
		               cout<<"Date_of_Arest :"<<cr.dateOfArrest<<endl;
		               cout<<"Address of criminal : "<<cr.address<<endl;
		               cout<<"Punishment  : "<<cr.punishment<<endl;
		               cout<<"NICKNAME : "<<cr.nickname<<endl;
		               cout<<"GANG : "<<cr.anygang<<endl<<endl<<endl;
	             }
	                      file>>cr.name;
		               file>>cr.age;
		               file>>cr.criminal_id;
		               file>>cr.crimes_commited;
		               file>>cr.dateOfArrest;
		               file>>cr.address;
		               file>>cr.punishment;
		               file>>cr.nickname;
		               file>>cr.anygang;
	       }
	        file.close();
	}
	else
	{
		cout<<"file not open succefully :"<<endl;
	}
	if(temp)
	{
		cout<<"NO RECORD FOR THIS NAME : "<<endl;
	}
}
//edit record function defnition
 void editrecord()
 {
 	system("cls");
 	string sn;//edit name
 	int temp=1;
 	cin.ignore();
 	cout<<"enter a name of criminal you want to edit record : ";
 	getline(cin,sn);
 	fstream file;
	fstream nfile;
 	file.open("criminalrecordfile.txt",ios::in);
 	nfile.open("newfile.txt",ios::out);
 	if(nfile&&file)
 	{
 		criminal cr;
 	       file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
		while(!file.eof())
		{
		if(cr.name==sn)
		{
		       system("cls");
	              temp=0;
	              cout<<"Enter a NAME  of criminal : ";
	              getline(cin,cr.name);
                     //	cin.ignore();
	              cout<<"enter a AGE OF criminal : ";
                     cin>>cr.age;
	              cin.ignore();
	              cout<<"Enter a CRIMINAL id : ";
	              cin>>cr.criminal_id;
	              cin.ignore();
	              cout<<"Enter Crime Commited by a criminal : ";
	              getline(cin,cr.crimes_commited);
	              cout<<"Enter a Date of Arrest:  ";
                     getline(cin,cr.dateOfArrest);
	              cout<<"Enter a Adress of Criminal : ";
                     getline(cin,cr.address);
	              cout<<"Enter a CONVICTION OR PUNISHMENT : ";
	              getline(cin,cr.punishment);
	              cout<<"Enter any NICKNAME of criminal (optional ) :";
                     getline(cin,cr.nickname);
	              cout<<"Can CRIMINAL AFFILIATE WITH ANY GANG enter a name of GANG : ";
	              getline(cin,cr.anygang);
			nfile<<cr.name<<"\t"<<cr.age<<"\t"<<cr.criminal_id<<"\t"<<cr.crimes_commited<<"\t"<<cr.dateOfArrest<<"\t"<<cr.punishment<<"\t"<<cr.nickname<<"\t"<<cr.address<<"\t"<<cr.anygang<<endl;
			cout<<"RECORD IS UPDATED SUCCEFULLY : "<<endl;	 
				 
		}
		else
		{
		nfile<<cr.name<<"\t"<<cr.age<<"\t"<<cr.criminal_id<<"\t"<<cr.crimes_commited<<"\t"<<cr.dateOfArrest<<"\t"<<cr.punishment<<"\t"<<cr.nickname<<"\t"<<cr.address<<"\t"<<cr.anygang<<endl;
	       }
		file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
	       }
	       file.close();
	       nfile.close();
	       remove("criminalrecordfile.txt");
	       rename("newfile.txt","criminalrecordfile.txt");
	       
	}
	else
	{
		cout<<"file not opened succefully : "<<endl;
	}
	if(temp)
	{
		cout<<"NO record found for this name : "<<endl;
	}
 }
 //deleterecord  function defintion
 void deleterecord()
 {
 	system("cls");
 	string sn;//edit name
 	int temp=1;
 	cin.ignore();
 	cout<<"Enter a name of criminal you want to DELETE Record : ";
 	getline(cin,sn);
 	fstream file;
	fstream nfile;
 	file.open("criminalrecordfile.txt",ios::in);
 	nfile.open("newfile.txt",ios::out);
 	if(nfile&&file)
 	{
 		criminal cr;
 	       file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
		while(!file.eof())
		{
		if(cr.name==sn)
		{
		       system("cls");
	              temp=0;
	              cout<<"RECORD IS DELETED SUCCEFULLY : "<<endl;
	       }
		else
		{
		nfile<<cr.name<<"\t"<<cr.age<<"\t"<<cr.criminal_id<<"\t"<<cr.crimes_commited<<"\t"<<cr.dateOfArrest<<"\t"<<cr.punishment<<"\t"<<cr.nickname<<"\t"<<cr.address<<"\t"<<cr.anygang<<endl;
	       }
		file>>cr.name;
		file>>cr.age;
		file>>cr.criminal_id;
		file>>cr.crimes_commited;
		file>>cr.dateOfArrest;
		file>>cr.address;
		file>>cr.punishment;
		file>>cr.nickname;
		file>>cr.anygang;
	       }
	       file.close();
	       nfile.close();
	       remove("criminalrecordfile.txt");
	       rename("newfile.txt","criminalrecordfile.txt");
	       
	}
	else
	{
		cout<<"file not opened succefully : "<<endl;
	}
	if(temp)
	{
		cout<<"NO record found for this name : "<<endl;
	}
 }

//header files
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string.h>

using namespace std;
//global variable

//function prototype
int validdate(char *d);
int validdes(int ,int);
int validcnic(string c);
void show_ticket(int g);
void book_flight();
void local_flight_schedule(int choice);
void Global_flight_schedule(int choice);
void display(string s);
string returndt(int x);
string localsrc(int x);
string localdestination(int x);
string Globalsrc(int x);
int validpass(string pass);
string Globaldestination(int x);
void  Search();
void Clear();
void  Delete();
void viewing();
//structure
 struct passenger{
 	string pnr;
    	string  first_name;
	string  last_name;
	string cnic;
	string email;
	string contact;
	int no_of_pass;
    	char gender;
       int age;
       };
struct payment
{
	string bank;
	string first_name;
	string last_name;
	long int pass;
	string card;
	int cvv;
	char date[15];
	
};
//main function
int main() 
{
	  
	system("color 09");

	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t           *******************************************            "<<endl;
       cout<<"\t\t\t           *             WELCOME                     *           "<<endl;
       cout<<"\t\t\t           *                 TO                      *            "<<endl;
       cout<<"\t\t\t           *         AIRLINE RESERVATION             *               "<<endl;
       cout<<"\t\t\t           *               SYSTEM                    *            "<<endl;
       cout<<"\t\t\t           *******************************************             "<<endl;
       cout<<"\t\t\t           *          PROGRAMMED BY                  * ";
       cout<<"\n\t\t\t           *           SHAYAN AHMED KIANI            * ";
       cout<<"\n\t\t\t           *           TAIMOOR ARSHAD                *   ";
       cout<<"\n\t\t\t           ******************************************* "<<endl;
       Sleep(2000);
       Beep(800,500);
       system("cls");
       system("color 50");
       system("color 0e");
       cout<<"\n\n\n\n\n\n";

    int i;
    char input;
    do {
        int op;//option variable for main
        label:
        system("cls");
        
        cout << "\t\t\tMain Menu\n\n\n";
        cout << "1: Book Flight\n";
        cout << "2: Search Flight\n";
        cout << "3: Flight Schedule\n";
        cout<<  "4: ADMINISTRATOR \n";
        cout << "5: Exit\n";

        cout << "\n\n\nEnter the Choice\n";
        cin >> op;
        system("cls");
       switch (op)
	{
              case 1:
                book_flight();
                break;
              case 2:
		      {
                            string s;//search data from file
                             system("cls");
                             cin.ignore();
                            do
                            {
                               cout << "Enter cnic number of passenger (*****-*******-*) # :";
                                 getline(cin,s);
                            }while(validcnic(s)); 
		              display(s);
                            break;
                     }
              case 3:
                	int sch;      ///secdule check
            	       do
            	       {
            	       	system("cls");
            	              cout<<"1. LOCAL BOOKING"<<endl;
            	              cout<<"2. GLOBAL BOOKING"<<endl;
                        	cout<<"PRESS 1 to SEE LOCAL BOOKING SECDULE AND 2 FOR GLOBAL BOOKING SECDULE"<<endl;
            	              cin>>sch;
            	       }while(sch>2||sch<=0);
                  	switch(sch)
                 	{
            		       case 1:
            		       	do{
            		       		system("cls");
            			           cout<<"LOCAL BOOKING"<<endl;
                		           cout << "1)PIA\n2)AIRBLUE\n3)SERENE AIR\nEnter your choice: ";
                                       cin >> i;
                                    }while(i>3||i<=0);
                                    local_flight_schedule(i);
                                     break;
                            case 2:
                                   do{
                                   	system("cls");
            			         cout<<"GLOBAL BOOKING "<<endl;
                		         cout << "1)PIA\n2)AIRBLUE\n3)SERENE AIR\nEnter your choice: ";
                                      cin >> i;
                                    }
                                      while(i>3||i<=0);
                                    Global_flight_schedule(i);
                                      break;
                            default :
                              cout<<"INVALID INPUT";
                   
                }

	       case 4:
	       	{
	       	 system("cls");
	       	 string pass;
	       	 cin.ignore();
	       	 
	       	 do{
	       	 
	       	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                      cout<<"                                                    --LOG IN FIRST--"<<endl;
			 cout<<"                ENTER A PASSWORD   :";
			 getline(cin,pass);
			 }while(validpass(pass));
			 system("cls");
			 int op;
			 char ch;
			do
			{ 
			do{
				system("cls");
			       cout<<"PRESS 1 FOR VIEWING ALL RECORDS : "<<endl;
			       cout<<"PRESS 2 FOR DELETE ANY RECORD   : "<<endl;
			       cout<<"PRESS 3 FOR CLEAR ALL DATABASE FILE :"<<endl;
			       cout<<"PRESS 4 FOR SEARCH ANY RECORD   : "<<endl;
			       cout<<"PRESS 5 FOR LOG OUT :"<<endl;
			       cout<<"Enter your choice : ";
			       cin>>op;
			  }while(op>5||op<=0);
			switch(op)
			{
			 	case 1:
			 		system("cls");
			 		viewing();
			 		break;
			 	case 2: 
			 		system("cls");
				       Delete();
				       break;
				case 3:
				       Clear();
					break;
				case 4:
					system("cls");
				       Search();
					break;
				case 5:
					goto label;
					break;
				       				
			}
			cout<<"do you want to continue PRESS Y/y FOR YES OTHERWISE ANY KEY : "<<endl;
			cin>>ch;
			}while(ch=='Y'||ch=='y');
			 break;
		       }
              case 5:
                        exit(1);
                         break;
              default:
                       cout << "Invalid choice\n";
                       break;
        }

        cout << "\n\n\nDo you wish to continue? (y/Y)\n";
        cin >> input;
    } while (input == 'Y' || input == 'y');

    return 0;
}
//function defination
//1
void local_flight_schedule(int choice) {
	system("cls");
    cout << "\t\t****************";
    if (choice == 1)
       cout << "PAKISTAN AIRLINE";
    else if (choice == 2)
       cout << "AIRBLUE AIRLINE";
    else if (choice == 3)
       cout << "SERENE AIRLINE";
    cout << "*******************\n";
    Sleep(200);
    cout << "(1:-)\t08:00\t\t11:05\t\tRs.6000\t\tRefundable\n" << endl;
    Sleep(200);
    cout << "(2:-)\t14:00\t\t17:05\t\tRs.6000\t\tRefundable\n" <<endl;
    Sleep(200);
    cout << "(3:-)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n" <<endl;
    Sleep(500);
}
//2
//global filigh sedule
void Global_flight_schedule(int choice)
{
	system("cls");
	 cout << "\t\t****************";
    if (choice == 1)
       cout << "PAKISTAN AIRLINE";
    else if (choice == 2)
       cout << "AIRBLUE AIRLINE";
    else if (choice == 3)
       cout << "SERENE AIRLINE";
    cout << "*******************\n";
    Sleep(200);
    cout << "(1:-)\t07:00\t\t11:05\t\tRs.6000\t\tRefundable\n" << endl;
    Sleep(200);
    cout << "(2:-)\t18:00\t\t22:05\t\tRs.6000\t\tRefundable\n" <<endl;
    Sleep(200);
    cout << "(3:-)\t22:00\t\t2:05\t\tRs.6000\t\tRefundable\n" <<endl;
    Sleep(500);
}
//3
void show_ticket(int g) {
    switch (g) {
        case 1:
            cout << "08:00\n";
            break;
        case 2:
            cout << "14:00\n";
            break;
        case 3:
            cout << "19:00\n";
            break;
        default:
            break;
    }
}
//4
void book_flight() 
{
  int b_no;
   cin.ignore();
    cout<<"|______________________________________________|"<<endl;	
    cout << "\t\t   FLIGHTS\n";
    cout<<"|______________________________________________|"<<endl;
    do{

            cout<<" 1 .LOCAL BOOKING "<<endl;
            cout<<" 2. GLOBAL "<<endl;
            cout<<"Press 1 FOR LOCAL BOOKING AND 2 FOR GLOBAL BOOKING"<<endl;
            cin>>b_no;
      }while(b_no>2||b_no<1);     
   
    switch(b_no)
    {
    	//local booking
	case 1:
	 
      {	// Airline selection
               int i=0;
                string airline;
               do
               {
   
                  cout << "1)PIA\n2)AIRBLUE\n3)SERENE AIR\nEnter your choice: ";
    
                  cin >> i;
               }while(i>3||i<1);
               cin.ignore();
               if (i == 1)
               airline = "PIA";
               else if (i == 2)
               airline = "AIRBLUE";
               else if (i == 3)
               airline = "SERENE AIR";
    
                // Date of Journey and Destination selection
               char dofj[15];//date of journey
               int src, des;//scr arrival
               do
               {	
                      cout << "Enter the Date Of Journey (DD-MM-YYYY): ";
                      cin.getline(dofj,15);
               }while(validdate(dofj)!=0);
               do
               {
                      cout << "1:Islamabad\n2:Karachi\n3:Peshawar\n4:Quetta\n5:Sakardo\n6:Multan\n";
                      cout << "\nEnter the Arrival: ";
                      cin >> src;
                      cout << "\nEnter the Destination: ";
                      cin >> des;
               }while(validdes(src,des));
               // Displaying available flights based on source and destination
               local_flight_schedule(i);
               string DES=localdestination(des);
               string SRC=localsrc(src);

               // Flight selection
               int fo;
           do{
                     cout << "Enter choice: ";
                     cin >> fo;
              }while(fo>3||fo<=0);

               cin.ignore();
               // Displaying selected flight details
                cout << "Flight Selected\n";
                show_ticket(fo);
               system("cls");

                // Passenger details structure
    
                passenger passeng;
               cout << "\nEnter passenger details\n";
               cout<<"Enter  a passenger Passport number  :";
                getline(cin,passeng.pnr);
               cout << "Enter your first name: ";
               getline(cin,passeng.first_name);
               cout << "Enter your last name: ";
               getline(cin,passeng.last_name);
               cout << "Enter your age: ";
               cin >> passeng.age;
              
               do
               {
               	 cin.ignore();
                       cout << "Enter your CNIC number (*****-*******-*): ";
                       getline(cin,passeng.cnic);
                }while(validcnic(passeng.cnic));
               cout << "Gender (M/F): ";
               cin >> passeng.gender;
               cin.ignore();
               cout << "Enter your email address: ";
               getline(cin,passeng.email);
               cout << "Enter your contact#: ";
               getline(cin,passeng.contact);
               cout << "How many seat(s) you want to reserve: ";
               cin>>passeng.no_of_pass;
               cin.ignore();
             // Payment details
               int ch;
               do
               {
                 cout << "How will you do your payment?\n1. Credit Card\n2. Debit Card\nEnter your choice: ";
                 cin >> ch;
               }while(ch>2||ch<=0);
                cin.ignore();
                payment pay;
              switch (ch) 
              {
              case 1:
                     cout << "Bank name: ";
                     getline(cin,pay.bank);
                     cout << "Card Holder's First Name: ";
                     getline(cin,pay.first_name);
                     cout << "Card Holder's Last Name: ";
                     getline(cin,pay.last_name);
                     cout << "Credit Card Number: ";
                     getline(cin,pay.card);
                     do
                     {
                         cout << "Expiry Date: ";
                         cin.getline(pay.date,15);
                     }while(validdate(pay.date));
                     cout << "Enter the 3-digit PIN from your credit card:  (***) ";
                     cin>>pay.pass;
                     cin.ignore();
                     cout << "CVV Number : ";
                     cin >> pay.cvv;
                     cin.ignore();
                     cout << "Transaction Successful\n";
                     break;

              case 2:
                     cout << "Bank name: ";
                     getline(cin,pay.bank);
                     cout << "Card Holder's First Name: ";
                     getline(cin,pay.first_name);
                     cout << "Card Holder's Last Name: ";
                     getline(cin,pay.last_name);
                     cout << "Debit Card Number: ";
                     getline(cin,pay.card);
                     do
                     {
                      cout << "Expiry Date: ";
                      cin.getline(pay.date,15);
                     }while(validdate(pay.date));
                     cout << "Enter the 3-digit PIN from your Debit card:  (***) ";
                     cin>>pay.pass;
                     cin.ignore();
                     cout << "CVV Number : ";
                     cin >> pay.cvv;
                     cin.ignore();
                     cout << "Transaction Successful\n";
                     break;
              default:
                      cout << "Invalid choice\n";
                      break;
             }   
             fstream file;
              system("cls");
             file.open("airlinereservation.txt",ios::app);
             // Displaying final ticket
             Sleep(200);
              cout << "\n\n\nPassport number : " <<passeng.pnr<<endl;
              Sleep(200);
              cout << "TICKET\n";
              Sleep(200);
              cout << "Airline: " << airline <<endl;
              Sleep(200);
              cout << "Name: " << passeng.first_name << " " << passeng.last_name <<endl;
              Sleep(200);
              cout << "CNIC: " << passeng.cnic <<endl;
              Sleep(200);
              cout << "Contact Number : " << passeng.contact <<endl;
              Sleep(200);
              cout<<"Date of journey : "<<dofj<<endl;
              Sleep(200);
              cout << "Number of Seat(s): " << passeng.no_of_pass <<endl;
              Sleep(200);
              cout<<"Source  : "<<SRC<<endl;
              Sleep(200);
              cout<<"Destination   :"<<DES<<endl;
              Sleep(200);
              cout << "Departing Time: ";
              Sleep(200);
              show_ticket(fo);
              cout << "Arriving Time: ";
              show_ticket(fo);
              Sleep(200);

             file<< passeng.pnr<<endl;
             file<< airline <<endl;
             file<<passeng.first_name<<endl;
             file<< passeng.last_name <<endl;		
             file<<passeng.cnic <<endl;
             file<< passeng.contact<<endl;
             file<<dofj<<endl;
             file<<SRC<<endl;
             file<<DES<<endl;
             file<<passeng.no_of_pass <<endl;
             string dp=returndt(fo);
             file<<dp<<endl;
             file.close();
             cout << "Baggage allowed is 12kg per person.\n";
             cout << "Boarding pass will be provided after checking in.\n";
             cout << "Please remember your PNR # for further information\n";
             cout <<endl;
            break;
      }//case 1 closing
    
    //INTERNATIONAL BOOKING
    
    case 2:
   {	// Airline selection
               int i=0;
                string airline;
               do
               {
   
                  cout << "1)PIA\n2)AIRBLUE\n3)SERENE AIR\nEnter your choice: ";
    
                  cin >> i;
               }while(i>3||i<1);
               cin.ignore();
               if (i == 1)
               airline = "PIA";
               else if (i == 2)
               airline = "AIRBLUE";
               else if (i == 3)
               airline = "SERENE AIR";
    
                // Date of Journey and Destination selection
               char dofj[15];//date of journey
               int src, des;//scr arrival
               do
               {	
                      cout << "Enter the Date Of Journey (DD-MM-YYYY): ";
                      cin.getline(dofj,15);
               }while(validdate(dofj)!=0);
               do
               {
                      cout << "1:PAKISTAN\n2:ITALY\n3:GERMANY\n4:DUBAI\n5:FRANCE\n6:OMAN\n";
                      cout << "\nEnter the Arrival: ";
                      cin >> src;
                      cout << "\nEnter the Destination: ";
                      cin >> des;
               }while(validdes(src,des));
               string SRC=Globalsrc(src);
               string DES=Globaldestination(des);
               // Displaying available flights based on source and destination
               Global_flight_schedule(i);
               
               // Flight selection
               int fo;
           do{
                     cout << "Enter choice: ";
                     cin >> fo;
              }while(fo>3||fo<=0);

               cin.ignore();
               // Displaying selected flight details
                cout << "Flight Selected\n";
                show_ticket(fo);
               system("cls");

                // Passenger details structure
    
                passenger passeng;
               cout << "\nEnter passenger details\n";
               cout<<"Enter  a passenger Passport number  :";
                getline(cin,passeng.pnr);
               cout << "Enter your first name: ";
               getline(cin,passeng.first_name);
               cout << "Enter your last name: ";
               getline(cin,passeng.last_name);
               cout << "Enter your age: ";
               cin >> passeng.age;
              
               do
               {
               	cin.ignore();
                     cout << "Enter your CNIC number (*****-*******-*): ";
                     getline(cin,passeng.cnic);
                }while(validcnic(passeng.cnic));
               cout << "Gender (M/F): ";
               cin >> passeng.gender;
               cin.ignore();
               cout << "Enter your email address: ";
               getline(cin,passeng.email);
               cout << "Enter your contact#: ";
               getline(cin,passeng.contact);
               cout << "How many seat(s) you want to reserve: ";
               cin>>passeng.no_of_pass;
               cin.ignore();
             // Payment details
               int ch;
               do
               {
                 cout << "How will you do your payment?\n1. Credit Card\n2. Debit Card\nEnter your choice: ";
                 cin >> ch;
               }while(ch>2||ch<=0);
                cin.ignore();
                payment pay;
              switch (ch) 
              {
              case 1:
                     cout << "Bank name: ";
                     getline(cin,pay.bank);
                     cout << "Card Holder's First Name: ";
                     getline(cin,pay.first_name);
                     cout << "Card Holder's Last Name: ";
                     getline(cin,pay.last_name);
                     cout << "Credit Card Number: ";
                     getline(cin,pay.card);
                     do
                     {
                         cout << "Expiry Date: ";
                         cin.getline(pay.date,15);
                     }while(validdate(pay.date));
                     cout << "Enter the 3-digit PIN from your credit card:  (***) ";
                     cin>>pay.pass;
                     cin.ignore();
                     cout << "CVV Number : ";
                     cin >> pay.cvv;
                     cin.ignore();
                     cout << "Transaction Successful\n";
                     break;

              case 2:
                     cout << "Bank name: ";
                     getline(cin,pay.bank);
                     cout << "Card Holder's First Name: ";
                     getline(cin,pay.first_name);
                     cout << "Card Holder's Last Name: ";
                     getline(cin,pay.last_name);
                     cout << "Debit Card Number: ";
                     getline(cin,pay.card);
                     do
                     {
                      cout << "Expiry Date: ";
                      cin.getline(pay.date,15);
                     }while(validdate(pay.date));
                     cout << "Enter the 3-digit PIN from your Debit card:  (***) ";
                     cin>>pay.pass;
                     cin.ignore();
                     cout << "CVV Number : ";
                     cin >> pay.cvv;
                     cin.ignore();
                     cout << "Transaction Successful\n";
                     break;
              default:
                      cout << "Invalid choice\n";
                      break;
             }   
             fstream file;
             system("cls");
             file.open("airlinereservation.txt",ios::app);
             // Displaying final ticket
             Sleep(200);
              cout << "\n\n\nPassport number : " <<passeng.pnr<<endl;
              Sleep(200);
              cout << "TICKET\n";
              Sleep(200);
              cout << "Airline: " << airline <<endl;
              Sleep(200);
              cout << "Name: " << passeng.first_name << " " << passeng.last_name <<endl;
              Sleep(200);
              cout << "CNIC: " << passeng.cnic <<endl;
              Sleep(200);
              cout << "Contact Number : " << passeng.contact <<endl;
              Sleep(200);
              cout<<"Date of journey : "<<dofj<<endl;
              Sleep(200);
              cout << "Number of Seat(s): " << passeng.no_of_pass <<endl;
              Sleep(200);
              cout<<"Source  : "<<SRC<<endl;
              Sleep(200);
              cout<<"Destination   :"<<DES<<endl;
              Sleep(200);
              cout << "Departing Time: ";
              show_ticket(fo);
              Sleep(200);
              cout << "Arriving Time: ";
              show_ticket(fo);
              Sleep(200);

             file<< passeng.pnr<<endl;
             file<< airline <<endl;
             file<<passeng.first_name<<endl;
             file<< passeng.last_name <<endl;		
             file<<passeng.cnic <<endl;
             file<< passeng.contact<<endl;
             file<<dofj<<endl;
             file<<SRC<<endl;
             file<<DES<<endl;
             file<<passeng.no_of_pass <<endl;
             string dp=returndt(fo);
             file<<dp<<endl;
             file.close();
             cout << "Baggage allowed is 12kg per person.\n";
             cout << "Boarding pass will be provided after checking in.\n";
             cout << "Please remember your PNR # for further information\n";
             cout <<endl;
            break;
      }//case 2 closing
    }//switch backet
	///  bookk
//5
}
int validdate(char *d)
{

	
	if(d[2]!='-'||d[5]!='-')
	{
		system("cls");
		cout<<"INVALID DATE!"<<endl;
		
		return 1;
	}
	else 
	{
		if((d[0]>='0'&&d[0]<='3')&&(d[3]>='0'&&d[3]<='1'))
		{
			if((d[3]=='0'&&(d[4]>='1'&&d[4]<='9'))||(d[3]=='1'&&(d[4]>='0'&&d[4]<='2')))
			{
					return 0;
			}
			else
			{
				system("cls");
				cout<<"INVALID DATE!"<<endl;
				return 1;
			}
		}
   	}
   	return 0;
}
//6
int validdes(int src,int des)
{
	if(src==des)
	{
		system("cls");
		cout<<"destination and source cannot be same :"<<endl;
		return 1;
	}
	else
	{
		if((des>=1&&des<=6)&&(src>=1&&src<=6))
		{
			return 0;
		 }
		 else
		 {
		 	system("cls");
		 	cout<<"invalid!"<<endl;
		 	return 1;
		  } 
	}
}
//7
void display(string s)
{
	string pnr;
	string airline;
	string first_name;
	string last_name;
	string cnic;
	string contact;
	string dofj;
	string src;
	string des;
	int  pass;
	string dp;
	//file handeling
	fstream file;
	int temp=1;
      file.open("airlinereservation.txt",ios::in);
	if(file)
	{  
             file>>pnr;
             file>>airline;
             file>>first_name;
             file>>last_name;		
             file>>cnic;
             file>>contact;
             file>>dofj;
             file>>src;
             file>>des;
             file>>pass;
             file>>dp;
            while(!file.eof())
            { 
             if(cnic==s)
	      {
	      	      temp=0;
	      	      cout<<"________________________________________"<<endl;
	      	      cout<<"Passportnumber #       "<<pnr<<endl;
                    cout<<"Airline :              "<<airline<<endl;
                    cout<<"First_name  :          "<<first_name<<endl;
                    cout<<"Last_name :            "<<last_name<<endl;
                    cout<<"Cnic   :               "<<cnic<<endl;
                    cout<<"Contact  :             "<<contact<<endl;
                    cout<<"Date of Journey :      "<<dofj<<endl;
                    cout<<"Source       :         "<<src<<endl;
                    cout<<"Destination  :         "<<des<<endl;
                    cout<<"No of seats :          "<<pass<<endl;
                    cout<<"departure and arrivel time : "<<dp<<endl;
                    cout<<"________________________________________"<<endl;
                    
		}
	               file>>pnr;
                      file>>airline;
                      file>>first_name;
                      file>>last_name;		
                      file>>cnic;
                      file>>contact;
                      file>>dofj;
                      file>>src;
                      file>>des;
                      file>>pass;
                      file>>dp;
	      }
	     file.close();
       }
       else
       {
             	cout<<"file not open succefuly :";
	}
	 
	if(temp)
	 {
	 	cout<<"no data found for this CNIC : ";
	 }
}
//8
string returndt(int x)//
{
	string dt;
	if(x==1)
	{
		dt="08:00______11:05 ";
	}
	else if(x==2)
	{
		dt="14:00______17:05";
	}
	else if(x==3)
	{
		dt="19:00______22:05";
	}
	return dt;
}
//9
int validcnic(string c)
{
	if((c[5]=='-'&&c[13]=='-'))
	{
		return 0;
	}
	else
       {
       	system("cls");
       	cout<<"invalid !"<<endl;
       	return 1;
	}
} 

string Globaldestination(int x)
{
	string d;
	if(x==1)
	{
	 d="PAKISTAN";	
	}
	else if(x==2)
	{
		d="ITALY";
	}
	else if(x==3)
	{
		d="GERMANY";
	}
	else if (x==4)
	{
		d="DUBAI";
	}
	else if(x==5)
	{
		d="FRANCE";
	}
	else
	{
		d="OMAN";
	}
	return d;
}
string Globalsrc(int x)
{
	string d;
	if(x==1)
	{
	 d="PAKISTAN";	
	}
	else if(x==2)
	{
		d="ITALY";
	}
	else if(x==3)
	{
		d="GERMANY";
	}
	else if (x==4)
	{
		d="DUBAI";
	}
	else if(x==5)
	{
		d="FRANCE";
	}
	else
	{
		d="OMAN";
	}
	return d;
	
}
string localdestination(int x)
{
	string d;
	if(x==1)
	{
	 d="ISLAMABAD";	
	}
	else if(x==2)
	{
		d="Karachi";
	}
	else if(x==3)
	{
		d="Peshawar";
	}
	else if (x==4)
	{
		d="Quetta";
	}
	else if(x==5)
	{
		d="SakardU";
	}
	else
	{
		d="Multan";
	}
	return d;
}
string localsrc(int x)
{
	string d;
	
	if(x==1)
	{
	 d="ISLAMABAD";	
	}
	else if(x==2)
	{
		d="Karachi";
	}
	else if(x==3)
	{
		d="Peshawar";
	}
	else if (x==4)
	{
		d="Quetta";
	}
	else if(x==5)
	{
		d="SakardU";
	}
	else
	{
		d="Multan";
	}
	return d;
	
}
int validpass(string pass)
{
	if(pass=="12345678")
	{
		return 0;
	}
	else 
	{   
	      	system("cls");
	      cout<<"INVALID PASSWORD !";
		return 1;
	}
}
void viewing()
{
	fstream file;
	string pnr;
	string airline;
	string first_name;
	string last_name;
	string cnic;
	string contact;
	string dofj;
	string src;
	string des;
	int  pass;
	string dp;
	int temp=1;
	file.open("airlinereservation.txt",ios::in);
	if(file)
	{
		file>>pnr;
             file>>airline;
             file>>first_name;
             file>>last_name;		
             file>>cnic;
             file>>contact;
             file>>dofj;
             file>>src;
             file>>des;
             file>>pass;
             file>>dp;
             while(!file.eof())
             {
             	      Sleep(200);
             	       temp=0;
             	      cout<<"________________________________________"<<endl;
	      	      cout<<"Passportnumber #       "<<pnr<<endl;
                    cout<<"Airline :              "<<airline<<endl;
                    cout<<"First_name  :          "<<first_name<<endl;
                    cout<<"Last_name :            "<<last_name<<endl;
                    cout<<"Cnic   :               "<<cnic<<endl;
                    cout<<"Contact  :             "<<contact<<endl;
                    cout<<"Date of Journey :      "<<dofj<<endl;
                    cout<<"Source       :         "<<src<<endl;
                    cout<<"Destination  :         "<<des<<endl;
                    cout<<"No of seats :          "<<pass<<endl;
                    cout<<"departure and arrivel time : "<<dp<<endl;
                    cout<<"________________________________________"<<endl;
                    	file>>pnr;
                     file>>airline;
                     file>>first_name;
                     file>>last_name;		
                     file>>cnic;
                     file>>contact;
                     file>>dofj;
                     file>>src;
                     file>>des;
                     file>>pass;
                     file>>dp;
                    
	      }
	}
	else
       {
        	cout<<"File not open succesfully : "<<endl;
	}
	if(temp)
	{
		cout<<"File is clear : "<<endl;
	 } 
}
void Search()
{
	string pnr;
	string airline;
	string first_name;
	string last_name;
	string cnic;
	string contact;
	string dofj;
	string src;
	string des;
	int  pass;
	string dp;
	//file handeling
	fstream file;
	int temp=1;
	string S_cnic;
	cin.ignore();
	cout<<"ENTER A CNIC OF passenger you want to view record  :(*****-*******-*) ";
	getline(cin,S_cnic);
      file.open("airlinereservation.txt",ios::in);
	if(file)
	{  
             file>>pnr;
             file>>airline;
             file>>first_name;
             file>>last_name;		
             file>>cnic;
             file>>contact;
             file>>dofj;
             file>>src;
             file>>des;
             file>>pass;
             file>>dp;
            while(!file.eof())
            { 
             if(cnic==S_cnic)
	      {
	      	      temp=0;
	      	      cout<<"________________________________________"<<endl;
	      	      cout<<"Passportnumber #       "<<pnr<<endl;
                    cout<<"Airline :              "<<airline<<endl;
                    cout<<"First_name  :          "<<first_name<<endl;
                    cout<<"Last_name :            "<<last_name<<endl;
                    cout<<"Cnic   :               "<<cnic<<endl;
                    cout<<"Contact  :             "<<contact<<endl;
                    cout<<"Date of Journey :      "<<dofj<<endl;
                    cout<<"Source       :         "<<src<<endl;
                    cout<<"Destination  :         "<<des<<endl;
                    cout<<"No of seats :          "<<pass<<endl;
                    cout<<"departure and arrivel time : "<<dp<<endl;
                    cout<<"________________________________________"<<endl;
                    
		}
	               file>>pnr;
                      file>>airline;
                      file>>first_name;
                      file>>last_name;		
                      file>>cnic;
                      file>>contact;
                      file>>dofj;
                      file>>src;
                      file>>des;
                      file>>pass;
                      file>>dp;
	      }
	     file.close();
       }
       else
       {
             	cout<<"file not open succefuly :"<<endl;
	}
	 
	if(temp)
	 {
	 	cout<<"no data found for this CNIC : "<<endl;
	 }
	
}
void Delete()
{
	string pnr;
	string airline;
	string first_name;
	string last_name;
	string cnic;
	string contact;
	string dofj;
	string src;
	string des;
	int  pass;
	string dp;
	//file handeling
	fstream file,nfile;
	int temp=1;
	string S_cnic;
	cin.ignore();
	cout<<"ENTER A CNIC OF passenger you want to DEELETE record (*****-*******-*)  : ";
	getline(cin,S_cnic);
      file.open("airlinereservation.txt",ios::in);
      nfile.open("nfile.txt",ios::out);
	if(file&&nfile)
	{  
             file>>pnr;
             file>>airline;
             file>>first_name;
             file>>last_name;		
             file>>cnic;
             file>>contact;
             file>>dofj;
             file>>src;
             file>>des;
             file>>pass;
             file>>dp;
            while(!file.eof())
            { 
             if(cnic==S_cnic)
	      {
	      	      temp=0;
	      	     cout<<"record is deleted successfully : "<<endl;
		}
		else
		{
		       nfile<<pnr<<endl;
                     nfile<<airline<<endl;
                     nfile<<first_name<<endl;
                     nfile<<last_name<<endl;		
                     nfile<<cnic<<endl;
                     nfile<<contact<<endl;
                     nfile<<dofj<<endl;
                     nfile<<src<<endl;
                     nfile<<des<<endl;
                     nfile<<pass<<endl;
                     nfile<<dp<<endl;	
		}
	               file>>pnr;
                      file>>airline;
                      file>>first_name;
                      file>>last_name;		
                      file>>cnic;
                      file>>contact;
                      file>>dofj;
                      file>>src;
                      file>>des;
                      file>>pass;
                      file>>dp;
              }
	     file.close();
	     nfile.close();
	     remove("airlinereservation.txt");
	     rename("nfile.txt","airlinereservation.txt");
       }
       else
       {
             	cout<<"files not open succefuly :";
	}
	 
	if(temp)
	 {
	 	cout<<"no data found for this CNIC : "<<endl;
	 }
	
}
void Clear()
{
	fstream file;
	file.open("airlinereservation.txt",ios::out|ios::trunc);
	if(file)
	{
	   cout<<"file is clear succefully : "<<endl;
	}
	else
	{
		cout<<"file not open succsfully :"<<endl;
	}
	file.close();
}
                           //the end 

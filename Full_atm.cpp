//Program to Implement operation of atm for multiple users

#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
	int wan_acc, wan_pas;
		int Acc, pass, bal = 5000, wantedAcc, wantedPass;
		char name[20]; int amt, with;
		int pin = 1234;
		int p;

class process {
	public:
		void write()		// to write data in file
		{
			ofstream fout;
			fout.open("atm.txt", ios::app);
			cout<<"Enter Account no. & Password:";
			cin>>Acc>>pass;
			fflush(stdin);
			cin.getline(name, 20);
			fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
			fout.close();
		}
		
		void format()		// to format file
		{
			ofstream fout;
			fout.open("atm.txt", ios::out);
			fout.close();
			cout<<"\n\n********File Formatted*******\n\n";
		}
		
			void read()		// to read data from file and print on screen 
		{
			ifstream fin;
			fin.open("atm.txt");
			
			if(fin.fail())
			{
				cout<<"\n\n\t*********File not Found\n\n";
				return;
			}
			while(1)
			{
				fin>>Acc>>pass>>bal>>name;
				if(fin.eof())
				{
					break;
				}
				else
				{
					cout<<"Account No.:"<<Acc<<"\tBalance:"<<bal<<"\tUser Name:"<<name<<endl;
				}
			}
				fin.close();
		}
		
		
		void search()			// To search a particular account 
		{
			int jasus = 0;
			ifstream fin;
			fin.open("atm.txt");
			
			cout<<"Enter Account no. you want to search:";
			cin>>wantedAcc;
			
			while(1)
			{
				fin>>Acc>>pass>>bal>>name;
				if(fin.eof())
				break;
				
				else
					if(Acc == wantedAcc)
					{
						jasus=1;
						cout<<"Account No.:"<<Acc<<"\tName:"<<name<<endl;
						break;
					}
			}
			if(jasus == 1)
			{
				cout<<"\n\n\t***************Record Found***********\n\n";
			}
			else
			{
				cout<<"\n\n\t***************Record Not Found***********\n\n";
			}
			fin.close();
		}
		
			void del()			// to delete a account 
	{
		ofstream fout;
		fout.open("temp.txt");
		
		ifstream fin;
		fin.open("atm.txt");
		
		int wantedAcc , jasus = 0;
		cout <<"Enter account to delete";
		cin>>wantedAcc;
		
		while(1)
		{
			fin>>Acc>>pass>>bal>>name;
			if(fin.eof())
			break;
			
			if(wantedAcc!=Acc)
			{
				fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
			}
			else
			jasus = 1;
	    }
	    
	    if(jasus == 1)
	    cout<<" \n\n\t Record deleted\n\n";
	    
	    else
	    cout<<" \n\n\t Record not found\n\n";
	    
	    fin.close();
	    fout.close();
	    remove ("atm.txt");
	    rename("temp.txt","atm.txt");
	}
	
	void update()		// to update details of account
	{
		int jasus = 0;
		
		ifstream fin("atm.txt");
		ofstream fout ("temp.txt");
		
		cout<<" Enter account no to update\n\n";
		cin>>wantedAcc;
		
		while(1)
		{
			fin>>Acc>>pass>>bal>>name;
			
			if(fin.eof())
			break;
			
			if(wantedAcc != Acc)
			{
				fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
		}
		else
		{ 
		cout<<"enter new password and name : ";
		cin>>pass;
		fflush(stdin);
		cin.getline(name, 20);
		fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name;
		jasus = 1;
		break;
		}
	}
	if(jasus == 0)
	{
		cout<<"\n\n\t***********Record not found***********\n\n";
	}
	else
	{
		cout<<"\n\n\t***********Record Updated***********\n\n";
	}
	fin.close();
	fout.close();
	remove("atm.txt");
	rename("temp.txt", "atm.txt");
	}
	
		
		void deposit(){//task 2) deposit function
		v:
		cout<<"Enter your amount:";
		cin>>amt;
        if(amt%100==0 && amt>=100){//amt checked to be more than and multiple of 100
        ifstream fin("atm.txt");
        ofstream fout("temp.txt");
        
        while(1)
        {
        	fin>>Acc>>pass>>bal>>name;
        	
        	if(fin.eof())
        	break;
        	
        	if(Acc != wan_acc)
        	{
        		fout<<Acc<<pass<<bal<<name;
        	}
        	else
        	{
        		bal = amt + bal;
            	cout<<"Your deposit is successful..";
            	fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
        	}
        
    }
    fin.close();
        fout.close();
        remove("atm.txt");
        rename("temp.txt", "atm.txt");
    }

        else{//if amt is less than 100 or not a multiple
            goto v;
        }
}
 void withdrawl(){
			w:
	cout<<"Enter amount of maoney to withdarwl";
	cin>>with;
	
		if (with>=100 && with<=10000 && with%100==0 )
		
		{
			ifstream fin("atm.txt");
        	ofstream fout("temp.txt");
        
        while(1)
        {
        	cout<<"hello"<<endl;
        	getch();	
        	fin>>Acc>>pass>>bal>>name;
        //	cout<<bal<<endl;
        	if(fin.eof()){
        		break;
        	}
        	
        	if(Acc != wan_acc)
        	{
        		fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
        	}
        	else
        	{
        		bal = bal-with;
            	cout<<"You have successfully withdrawled.......";
            	cout<<"\n"<<bal<<endl;
            		fout<<Acc<<"\t"<<pass<<"\t"<<bal<<"\t"<<name<<endl;
            	break;
            	
        	}
        }
        cout<<"ya";
		fin.close();
        fout.close();
        
        remove("atm.txt");
        cout<<"yo";
		rename("temp.txt", "atm.txt");
    }
		else
		{
			goto w;
		}
	}
	void balance()
{
	ifstream fin("atm.txt");
	while(1)
	{
		fin>>Acc>>pass>>bal>>name;
		if(fin.eof())
		break;
		
		else if(Acc == wan_acc)
		{
			cout<<"\n\nYour balance is:"<<bal<<endl;
			break;
		}
	}
	fin.close();
}
		
    };
  
  
class admin: public process 
{
	
	public:
	void loginAd()
	{
	cout<<"Enter your Password:";
	cin>>p;
	if(pin == p)
	{
		int choice;
	
	do
	{
		cout<<"Press 1 to Add New Account no."<<endl;
		cout<<"Press 2 to View all Account no."<<endl;
		cout<<"Press 3 to format all Account no."<<endl;
		cout<<"Press 4 to delete a Account no."<<endl;
		cout<<"Press 5 to search a Account no."<<endl;
		cout<<"Press 6 to update a Account no."<<endl;
		cout<<"Press 0 to exit:"<<endl;
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: write();break;
			case 2: read(); break;
			case 3: format(); break;
			case 4: del(); break;
			case 5: search(); break;
			case 6: update();break;
			default: 
			cout<<"\n\n\tInvalid choice\n\n";
		}
	}while(choice != 0);
	}
}
};	
	 
class search :public admin
{
	public:

	char ch;
	void check()
	{
		ifstream fin("atm.txt");
		if(fin.fail())
		{
			cout<<"File not exist";
			return;
		}
		else
		{
			cout<<"Enter your Account no.";
			cin>>wantedAcc;
			cout<<"Enter your Password:";
			cin>>wantedPass;
			
			while(1)
			{
				fin>>Acc>>pass>>bal>>name;
				if(fin.eof())
				break;
				
				if(wantedAcc == Acc)
				{
					if(wantedPass == pass)
					{
						wan_acc = wantedAcc;
						wan_pas = wantedPass;
						
						do
						{
						cout<<"Press d for deposit\n";
						cout<<"Press b for balance enquiry\n";
						cout<<"press w for withdrawal\n";
						cout<<"press x for exit\n";
						cout<<"Enter your choice:";
						fin.close();
						cin>>ch;
						switch(ch)
						
						{
							cout<<"Inside switch\n";
							case 'd': deposit(); break;
							case 'b':balance(); break;
							case 'w': withdrawl(); break;
							case 'x':exit(0);break;
						}
					}while(1);
				}
			}
		}
	}
}


void create()
	{
		ofstream fout;

		fout.open("atm.txt", ios::app);

		cout << "Enter account number password and name";
		cin >> Acc >> pass;
		fflush(stdin);
		cin.getline(name, 20);
		fout << Acc << "\t" << pass << "\t" << bal << "\t" << name << endl;
		fout.close();
	}
	friend class process;
};




int main()
{
	int cho;

	search s;
	do
	{
		cout<<"Press 1. to create an account\n";
		cout<<"Press 2. to login as user\n";
		cout<<"press 3. to login as administrator\n";
		cout<<"Press 0. to exit\n";
		cout<<"Enter your choice:";
		cin>>cho;
		switch(cho)
		{
			case 1 :
				s.create();
				break;
			case 2 :
				s.check();
				break;
				case 3:
					s.loginAd();
		}
	}while(cho != 0);
}
							
						 
						
			
	

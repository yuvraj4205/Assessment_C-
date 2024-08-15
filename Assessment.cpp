#include<iostream>
#include<ctime>
using namespace std;

// Class representing an ATM
class ATM
{
	private:
		    int pin; // Store ATM PIN
		    double initialBalance; // Initial account balance
		    double currentBalance; // Current account balance

	public :
    // Constructor to initialize the ATM with initial values
		    ATM(int initPin,double initBalance,double currBalance)
		    {
		    	pin=initPin;
				initialBalance=initBalance;
				currentBalance=currBalance;
			}
		    void displayWelcomeScreen() {
		        time_t now=time(0);
        		tm *ltm=localtime(&now);
        		// Display the current date and time
        		cout<<"---Welcome to the ATM Banking Application!---";
		        cout<<endl<<"Current Date and Time : "<<1900+ltm->tm_year<<"-"
		            <<1+ltm->tm_mon<<"-"<<ltm->tm_mday<<" "
		            <<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"
		            <<1+ltm->tm_sec<<endl;
		    }
		    void displayMenu() {
		        cout<<endl<<"Menu :";
		        cout<<endl<<"      1. Enter ATM PIN";
		        cout<<endl<<"      2. Help Screen";
		        cout<<endl<<"      3. Exit";
		    }
		    void displayHelpScreen() {
		        cout<<endl<<"Help Screen :";
		        cout<<endl<<"1. Enter the correct ATM PIN to access your account.";
		        cout<<endl<<"2. You can deposit or withdraw money from your account.";
		        cout<<endl<<"3. Check your current balance anytime.";
		    }
		    bool handlePinInput() {
		        int enteredPin;
		        cout<<"Enter ATM PIN : ";
		        cin>>enteredPin;
		
		        if(enteredPin==pin) {
		            return true; // PIN is correct
		        }
				else {
		            cout<<endl<<"Incorrect PIN."<<endl<<endl<<"Exiting the program..."<<endl;
		            return false; // PIN is incorrect
		        }
		    }
		    void depositMoney() {
		        double amount;
		        cout<<"Enter amount to deposit : ";
		        cin>>amount;
		
		        if(amount>0) {
		            currentBalance+=amount;
		            cout<<endl<<"---Account holder---";
			        cout<<endl<<"Name of account holder : Rakesh Kharva";
			        cout<<endl<<"The address of account holder : Mumbai";
			        cout<<endl<<"The branch location : Andheri";
			        cout<<endl<<"Account no. : 5678"<<endl;
		            cout<<endl<<"Amount deposited successfully."<<endl;
		        }
				else {
		            cout<<endl<<"Invalid deposit amount."<<endl;
		        }
		    }
		    void withdrawMoney() {
		        double amount;
		        cout<<"Enter amount to withdraw: ";
		        cin>>amount;
		
		        if(amount>0 && amount<=currentBalance) {
		            currentBalance-=amount;
		            cout<<endl<<"Current Account Balance : "<<currentBalance;
		            cout<<endl<<"Amount withdrawn successfully."<<endl;
		        }
				else if(amount>currentBalance) {
					cout<<endl<<"---Account holder---";
			        cout<<endl<<"Name of account holder : Rakesh Kharva";
			        cout<<endl<<"The address of account holder : Mumbai";
			        cout<<endl<<"The branch location : Andheri";
			        cout<<endl<<"Account no. : 5678"<<endl;
		            cout<<endl<<"Insufficient in your account. Transaction failed."<<endl;
		        }
				else {
		            cout<<endl<<"Invalid withdrawal amount."<<endl;
		        }
		    }
		    void checkBalance() {
		        cout<<endl<<"Current Account Balance : "<<currentBalance<<endl;
		    }
		    // Main function to run the ATM application
		    void run() {
		        displayWelcomeScreen();
		        while(true) {
		            displayMenu();
		            int choice;
		            cout<<endl<<endl<<"Enter your choice: ";
		            cin>>choice;
		
		            switch(choice)
					{
		                case 1:
		                    if(handlePinInput())
							{
		                        while(true)
								{
		                            cout<<endl<<"Account Menu:";
		                            cout<<endl<<"1. Deposit Money";
		                            cout<<endl<<"2. Withdraw Money";
		                            cout<<endl<<"3. Check Balance";
		                            cout<<endl<<"4. Exit";
		                            cout<<endl<<endl<<"Enter your choice : ";
		                            cin>>choice;
			                        switch (choice)
									{
			                            case 1:
			                                depositMoney();
			                                break;
			                            case 2:
			                                withdrawMoney();
			                            	break;
			                        	case 3:
			                                checkBalance();
			                                break;
			                            case 4:
			                                cout<<endl<<"Thank you!"<<endl<<endl<<"Exiting...";
			                                return; // Exit the program
			                            default:
			                                cout<<endl<<"Invalid choice. Please try again.";
			                        }
		                        }
		                    }
							else {
		                        return; // Exit the program
		                    }
		                    break;
		                case 2:
		                    displayHelpScreen();
		                    break;
		                case 3:
		                    cout<<endl<<"Thank you!"<<endl<<endl<<"Exiting...";
		                    return; // Exit the program
		                default:
		                    cout<<endl<<"Invalid choice. Please try again.";
		            }
		        }
		    }
};

main()
{
    ATM atm(12345,60000,20000);
    atm.run();
}

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


// User Information Class

class userinfo{
    private:                    // Private Member Variable
        string name;
        long long accountNumber;
        int pin;
        long double balance;
        long long mobileNumber;
    
    public:                    // Public Member Variable
        void setData(string u_name, long long acc_Num, int u_pin, long double u_balance, long long mobile_num){
            name = u_name;
            accountNumber = acc_Num;
            pin = u_pin;
            balance = u_balance;
            mobileNumber = mobile_num;
        }

        string getName(){
            return name;        // getName function is returning the user's Name
        }

        long long getAccountNumber(){
            return accountNumber;       // getAccountNumber function is returning the user's account no.
        }

        int getPin(){
            return pin;         // getPin function is returning the user's PIN
        }

        long double getBalance(){
            return balance;         // getBalance is returning the user's Bank Balance
        }

        long long getmobileNumber(){
            return mobileNumber;        // getmobileNumber is returning the user's Mobile No.
        }

        //setBalance function is used to withdraw money from ATM
        void setBalance(long double a_balance){
            if(a_balance > 0 && a_balance < balance){
                balance-=a_balance;
                cout << "\t Collect Your Cash " << endl;
                cout << "\t Current Balance : " << balance << endl;
                getch();
            }

            else{
                cout << "\t Invalid Amount or Incorrect Amount" << endl;
                getch();
            }
        }

        //setMobile function is Updating the user mobile no
        void setMobile(long long old_mobileNum,long long new_mobileNum){
                if(old_mobileNum == mobileNumber){
                    mobileNumber = new_mobileNum;
                    cout << "\t Mobile Number is Updated" << endl;
                    getch();
                }

                else{
                    cout << "\t Incorrect Mobile Number" << endl;
                    getch();
                }
        }
};



int main()
{
    int userPin, choice;
    long long accountNum;

    system("cls");

    // object created for userinfo
    userinfo Information;

    // Set User Details ( into object )         ( Setting Default Data )
    Information.setData("Maxwell", 1234567890, 69420, 69420.69, 880166666);

    system("cls");      //Clear screen

    do{
                cout << endl << "\t *** Welcome To ATM ***" << endl;
                cout << "\t Enter Account Number : ";
                cin >> accountNum;

                cout << "\t Enter PIN : ";
                cin >> userPin;

                system("cls");
        
        // check whether enter values matches with 
        if(accountNum == Information.getAccountNumber() && userPin == Information.getPin()){

            do{
                long double cash_withdraw;
                long long Old_num, New_num;

                system("cls");

                // user Interface
                cout << endl << "\t *** Welcome To ATM ***" << endl;
                cout << endl << "\t Select an Option" << endl;
                cout << "\t 1. Check Balance " << endl;
                cout << "\t 2. Cash Withdraw " << endl;
                cout << "\t 3. Show User Details " << endl;
                cout << "\t 4. Update Mobile Number " << endl;
                cout << "\t 5. Exit " << endl;
                cout << "\t\t" << endl << "\t Select : ";
                cin >> choice;              // taking user choice
                cout << endl;

                switch(choice){             // switch condition
                    case 1: 
                        cout << "\t Balance : " << Information.getBalance() << endl;
                        getch();
                        break;
                    
                    case 2:
                        cout << "\t Enter Cash Withdraw Amount : ";
                        cin >> cash_withdraw;
                        Information.setBalance(cash_withdraw);
                        getch();
                        break;

                    case 3:
                        cout << "\t User Information " << endl;
                        cout << "\t Name : " << Information.getName() << endl;
                        cout << "\t Account Number : " << Information.getAccountNumber() << endl;
                        cout << "\t Balance : " << Information.getBalance() << endl;
                        cout << "\t Mobile Number : " << Information.getmobileNumber() << endl;
                        getch();
                        break;

                    case 4:
                        cout << "\t Enter Old Number : ";
                        cin >> Old_num;
                        cout << "\t Enter New Number : ";
                        cin >> New_num;
                        Information.setMobile(Old_num,New_num);
                        getch();
                        break;
                    
                    case 5:
                        exit(0);

                    default:
                        cout << "\t Enter Valid Choice " << endl;
                        getch();
                        break;
                }

        }while(1);      // MENU	   // condition will always TRUE and loop is capable of running infinite times

    }

        else{
                cout << "\t Invalid Choice " << endl;
                cout << "\t Please Enter Again " << endl;
                getch();
                system("cls");
            }

    }while(1);      // MENU	   // condition will always TRUE and loop is capable of running infinite times

    return 0;
}


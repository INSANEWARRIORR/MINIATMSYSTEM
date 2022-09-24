//   MINI ATM SYSTEM

#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

class atm
{
private:
     long int Account_No;
     string name;
     int PIN;
     double Balance;
     string Mobile_No;

public:
     // setData function is setting the Data into the private member variables.
     void setData(long int Account_No_a, string name_a, int PIN_a, double Balance_a, string Mobile_No_a)
     {
          Account_No = Account_No_a;         // assigning the formal arguments to private member variables.

          name = name_a;
          PIN = PIN_a;
          Balance = Balance_a;
          Mobile_No = Mobile_No_a;
     }

     long int getAccountNo()
     {
          return Account_No;
     }

     string getName()
     {
          return name;
     }

     int getPIN()
     {
          return PIN;
     }

     double getBalance()
     {
          return Balance;
     }

     string getMobileNo()
     {
          return Mobile_No;
     }

     // setMobile function is updating the user's mobile number.
     void setMobile(string mob_prev, string mob_new)
     {
          if (mob_prev == Mobile_No)      // it will checks old mobile number.
          {
               Mobile_No = mob_new;      // and update with new , if old matches.
               cout << endl
                    << "Sucessfully updated mobile number";
          }
          else
          {
               cout << endl
                    << "Incorrect !! old mobile number.";
          }
     }

     // setPIN function is updating the user's PIN
     void setPIN(int PIN_prev, int PIN_new)
     {
          if (PIN_prev == PIN)     // it will checks old PIN.
          {
               PIN = PIN_new;     // and update with new , if old matches.
               cout << endl
                    << "Sucessfully updated PIN";
          }
          else
          {
               cout << endl
                    << "Incorrect !! old PIN.";
          }
     }

     // cashWithDraw function is ude to withdraw money from atm.
     void cashWithDraw(int Amount_a)
     {
          if (Amount_a > 0 && Amount_a < Balance)        // check entered amount valadity
          {
               Balance -= Amount_a;
               cout << endl
                    << "Please collect your cash.";
               cout << endl
                    << "Available Balance : " << Balance;
          }
          else
          {
               cout << endl
                    << "Invalid input or Insufficient Balance";
          }
     }
};

int main()
{
     int choice = 0, enterPIN;       // enterPIN and enterAccountNo ---> user authentication.
     long int enterAccountNo;

     system("cls");
     /* system("cls") == It is used to pass the commands that can be executed in the command processor or the terminal of the operating system, and finally returns the command after it has been completed.*/

     // created user ( object )
     atm user1;

     // set user details ( into object )   (Setting default data)
     user1.setData(12345678, "Raj", 1111, 500012.45, "908945652");

     do
     {
          system("cls");

          cout << endl
               << " **** WELCOME TO ATM **** " << endl;
          cout << endl
               << "----------------------------";
          cout << endl
               << " ENTER YOUR ACCOUNT NUMBER : ";        // asking user to enter account number.
          cin >> enterAccountNo;

          cout << endl
               << " ENTER PIN : ";                       // asking user to enter PIN.
          cin >> enterPIN;

          if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
          {
               do
               {
                    int amount = 0;
                    string oldMobileNo, newMobileNo;
                    int oldPIN, newPIN;

                    system("cls");
                    cout << endl
                         << " **** WELCOME TO ATM **** " << endl;
                    cout << endl
                         << "----------------------------";
                    cout << endl
                         << " Select Options ";
                    cout << endl
                         << " 1. Check Balance ";
                    cout << endl
                         << " 2. Cash Withdraw ";
                    cout << endl
                         << " 3. Show User details ";
                    cout << endl
                         << " 4. Update Mobile Number ";
                    cout << endl
                         << " 5. Update PIN ";
                    cout << endl
                         << " 6. Exits " << endl;
                    cin >> choice;         // taking user choice

                    switch (choice)
                    {
                    case 1:
                         cout << endl
                              << " Your Bank Balance is : " << user1.getBalance();   // getBalance is..printing users bank balance.

                         _getch();
                         break;
                    case 2:
                         cout << endl
                              << " Enter the amount ";
                         cin >> amount;
                         user1.cashWithDraw(amount);   // calling cashWithDraw function passing the withdraw amount

                         _getch();
                         break;

                    case 3:
                         cout << endl
                              << "**** USER DETAILS :- ";
                         cout << endl
                              << "-> Account Number : " << user1.getAccountNo();
                         cout << endl
                              << "-> Name : " << user1.getName();
                         cout << endl
                              << "-> Balance : " << user1.getBalance();
                         cout << endl
                              << "-> Mobile Number : " << user1.getMobileNo();

                         _getch();
                         break;
                    case 4:
                         cout << endl
                              << " Enter Old Mobile Number : ";
                         cin >> oldMobileNo;     // takes old mobile number.

                         cout << endl
                              << " Enter New Mobile Number : ";
                         cin >> newMobileNo;    // takes new mobile number.

                         user1.setMobile(oldMobileNo, newMobileNo);

                         _getch();
                         break;
                    case 5:
                         cout << endl
                              << " Enter Old PIN : ";
                         cin >> oldPIN;      // takes old PIN.

                         cout << endl
                              << " Enter New PIN : ";
                         cin >> newPIN;     // takes new PIN.

                         user1.setPIN(oldPIN, newPIN);

                         _getch();
                         break;
                    case 6:
                         exit(0); // exit application
                    default:      // handle invalid input
                         cout << endl
                              << " Enter Valid data !! ";
                    }

               } while (1);      // MENU // condition will always TRUE and loop is capable of running infinite times.
          }
     } while (1);

     return 0;
}



//=======================================================
//                 CODE BY PRIYANSH SETH
//=======================================================
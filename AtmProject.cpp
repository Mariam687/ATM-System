
#include <iomanip>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


void ShowMainMenueScreen();
void ShowLoginScreen();
void QuickWithdrawMenue();


const string FileName = "ClientLineFile";


enum enMenue {
	QuickWithdraw = 1, NormalWithdraw, Deposit, CheckBalance, Logout
};

enum enQuickWithdrawChoices {
	one = 20, two = 50, three = 100, four = 200, five = 400, six = 600, seven = 800, eight = 1000, nine
};



struct Client {
	string name, phoneNumber, PinNumber, accountNumber;
	int accountBalance;
	bool MarkForDelete = 0;

};

Client CurrentClient;


string ReadString(string message) {
	string s;
	cout << message << " ";
	getline(cin, s);
	return s;
}


string ClientRecordToLine(Client client, string del) {
	string Rec = "";
	Rec += client.accountNumber + del;
	Rec += client.PinNumber + del;
	Rec += client.name + del;
	Rec += client.phoneNumber + del;
	Rec += to_string(client.accountBalance);
	return Rec;


}


void LoadVectorIntoFile(string FileName, vector<Client>vClient) {
	fstream File;
	string Line;
	File.open(FileName, ios::out);
	if (File.is_open()) {
		for (Client& i : vClient) {
			if (!i.MarkForDelete) {
				Line = ClientRecordToLine(i, "#//#");
				File << Line << endl;
			}
		}

		File.close();

	}


}


vector<string> Split(string s, string de) {
	vector<string>v;
	string del = de, ss;
	int pos, c = 0;
	while ((pos = s.find(del)) != std::string::npos) {
		ss = s.substr(0, pos);
		if (ss != "") {
			v.push_back(ss);

		}
		s.erase(0, pos + del.length());
	}
	if (s != "")
		v.push_back(s);
	return v;


}

Client ConvertLineToRecord(string Line, string sep) {
	vector<string>v;
	v = Split(Line, sep);
	Client client;
	client.accountNumber = v[0];
	client.PinNumber = v[1];
	client.name = v[2];
	client.phoneNumber = v[3];
	client.accountBalance = stoi(v[4]);
	return client;
}


vector <Client> LoadCleintsDataFromFile(string FileName) {
	vector <Client> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string Line; Client client;
	while (getline(MyFile, Line))
	{
		if (Line != "") {
			client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(client);
		}
	}
	MyFile.close();

	return vClients;
}


short ReadOperationFromMainMenue() {
	cout << "Enter the operation you want to do [1=>5]: " << endl;
	short operation;
	cin >> operation;
	cin.ignore(1, '\n');
	system("cls");
	return operation;

}


bool FindClienWithAccountAndPinNumber(string AccountNumber, string PinNumber, Client& client) {
	vector<Client>vClient = LoadCleintsDataFromFile(FileName);
	for (Client& i : vClient) {
		if (i.accountNumber == AccountNumber && i.PinNumber== PinNumber) {
			client = i;
			return 1;
		}


	}
	return 0;
}

void GoToMainMenue() {
	cout << "\n\n\nPlease Enter any key to go back to main menue...";

	system("pause>0");
	system("cls");
	ShowMainMenueScreen();

}

void Deposite(vector<Client>& vClient, int balance, string accountNumber) { 

	for (Client& theClient : vClient)
		if (theClient.accountNumber == accountNumber) {
			theClient.accountBalance += balance;
			CurrentClient.accountBalance = theClient.accountBalance;
			cout << "The new balane for account number " << theClient.accountNumber << " is " << theClient.accountBalance << endl;
			LoadVectorIntoFile(FileName, vClient);
			break;
		}
			
			
}

void DepositOperation() {
	
	int balance;
	vector<Client> vClient = LoadCleintsDataFromFile(FileName);
	char ans;
	
	cout << "Enter the balace you want to add: ";
	cin >> balance;
	cout << "Are you sure you want to do this transaction y/n ?";
	cin >> ans;
	if (tolower(ans) == 'y') {
		Deposite(vClient, balance, CurrentClient.accountNumber);

	}
	
}

void DepositMenue() {
	cout << "#################################" << endl;
	cout << "           Deposit Menue.        " << endl;
	cout << "#################################" << endl << endl;
	DepositOperation();
	GoToMainMenue();

}


void  MessageFromWithdrawMenue() {

	cout << "\n\nThe amount exceeds you balance, make another choice\n";
	cout << "Press any key to continue.....";
	system("pause>0");
	system("cls");
	
	QuickWithdrawMenue();

}


void WithdrawOperation(short choice) {
	vector<Client> vClient = LoadCleintsDataFromFile(FileName);
	for (Client& theClient : vClient)
		if (theClient.accountNumber == CurrentClient.accountNumber) {

			switch (choice)
			{
			case 1:
				if (one <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= one;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();

				}
				else
					MessageFromWithdrawMenue();

				break;
			case 2:
				if (two <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= two;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 3:
				if (three <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= three;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 4:
				if (four <= CurrentClient.accountBalance) {

					CurrentClient.accountBalance -= four;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 5:
				if (five <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= five;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 6:
				if (six <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= six;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 7:
				if (seven <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= seven;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();

				break;
			case 8:
				if (eight <= CurrentClient.accountBalance) {
					CurrentClient.accountBalance -= eight;
					cout << "\nDone successfully, the new balance is " << CurrentClient.accountBalance << endl;
					GoToMainMenue();
				}
				else
					MessageFromWithdrawMenue();
				break;
			default:
				system("cls");
				ShowMainMenueScreen();
			}

			theClient.accountBalance = CurrentClient.accountBalance;
			LoadVectorIntoFile(FileName, vClient);
			break;
		}
	


}


void QuickWithdrawMenue() {
	short choice;
	cout << "============================================" << endl;
	cout << "              Quick Withdraw Menue          " << endl;
	cout << "============================================" << endl;
	cout << "       [1] 20           [6] 600             " << endl;
	cout << "       [2] 50           [7] 800             " << endl;
	cout << "       [3] 100          [8] 1000            " << endl;
	cout << "       [4] 200		[9] Exit			 " << endl;
	cout << "       [5] 400							     " << endl;
	cout << "============================================" << endl;
	cout << "Your balance is " << CurrentClient.accountBalance << endl;
	do {
		cout << "Choose what to withdraw from [1] to [9]:  ";
		cin >> choice;
	} while (choice < 1 || choice > 9);

	WithdrawOperation(choice);
	

}
void NormalWithdrawOperation() {

	vector<Client> vClient = LoadCleintsDataFromFile(FileName);
	int balance;
	char ans;
	do {
		cout << "\nEnter an amount multiple of five: ";
		cin >> balance;
		if (balance > CurrentClient.accountBalance)
			cout << "The value exceeds you balance, try another amount\n";
		
	} while (balance % 5 != 0 || balance > CurrentClient.accountBalance);

	
	cout << "Are you sure you want to do this transaction y/n ?";
	cin >> ans;
	if (tolower(ans) == 'y') {
		Deposite(vClient, balance * -1, CurrentClient.accountNumber);
	}

}

void NormalWithdrawMenue() {
	cout << "#################################" << endl;
	cout << "       Normal Withdraw Menue.        " << endl;
	cout << "#################################" << endl << endl;
	NormalWithdrawOperation();
	GoToMainMenue();

}

void CheckBalanceMenue() {
	cout << "Your balance is " << CurrentClient.accountBalance << endl;
	GoToMainMenue();
}

void LogoutMenue() {
	system("cls");
	ShowLoginScreen();

}

void ShowTheOptionMainMenue(enMenue Menue, vector<Client>& vClient) {

	switch (Menue) {
	case enMenue::QuickWithdraw:
		QuickWithdrawMenue();
		break;
	case enMenue::NormalWithdraw:
		NormalWithdrawMenue();
		break;
	case enMenue::Deposit:
		DepositMenue();
		break;
	case enMenue::CheckBalance:
		CheckBalanceMenue();
		break;
	default:
	{
		LogoutMenue();
	}
	}
}

void ShowMainMenueScreen() {
	
	cout << "=================================" << endl;
	cout << "       ATM Main Menue Screen.      " << endl;
	cout << "=================================" << endl;
	cout << "   [1] Quick Withdraw " << endl;
	cout << "   [2] Normal Withdraw " << endl;
	cout << "   [3] Deposit " << endl;
	cout << "   [4] Check Balance " << endl;
	cout << "   [5] Logout" << endl;
	cout << "=================================" << endl;
	vector<Client> vClient = LoadCleintsDataFromFile(FileName);
	ShowTheOptionMainMenue(enMenue(ReadOperationFromMainMenue()), vClient);

}



void ShowLoginScreen() {
	string AccountNumber;
	cout << "=================================" << endl;
	cout << "           Login Screen.         " << endl;
	cout << "=================================" << endl;
	cout<<"Please enter the account number: ";
	getline(cin >> ws, AccountNumber);
	string PinNumber = ReadString("Please enter the pin number: ");

	while (!FindClienWithAccountAndPinNumber(AccountNumber, PinNumber, CurrentClient)) {

		cout << "Invalid Account Number/Pin Number!\n";
		AccountNumber = ReadString("Please enter another account number: ");
		PinNumber = ReadString("Please enter another pin number: ");
	}

	system("cls");

	ShowMainMenueScreen();


}

int main()
{
 
   
	ShowLoginScreen();


}

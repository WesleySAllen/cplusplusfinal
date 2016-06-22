//password generator
//Wesley Allen
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
int genpass();
int seepass();
int randall();

int main()// The main menu
{
	int pin = 0;
	int menu = 0;	
	cout << "Enter Pin Number" << endl;
	cin >> pin;
	if (pin == 1234)// Pin must be entered to use the program
	{
		cout << "Main Menu" << endl;
		cout << "1. Generate a password" << endl;
		cout << "2. View a password" << endl;
		cout << "3. Exit" << endl;
		cout << "Choose a menu option" << endl;
		cin >> menu;
		while (menu != 3)
			{
				while (menu != 1 && menu != 2)// Determine if the user wants to continue using to program
				{
					cout << "Invalid Menu Option" << endl;
					cout << "Main Menu" << endl;
					cout << "1. Generate a password" << endl;
					cout << "2. View password" << endl;
					cout << "3. Exit" << endl;
					cout << "Choose a menu option" << endl;
					cin >> menu;
				}
				if (menu == 1)
				{
					genpass();// Calls the function that generates a password for the user
					cout << "Main Menu" << endl;
					cout << "1. Generate a password" << endl;
					cout << "2. View password" << endl;
					cout << "3. Exit" << endl;
					cout << "Choose a menu option" << endl;
					cin >> menu;
				}
				else if (menu == 2)
				{
					seepass();// Calls a function that displays a password for the user
					cout << "Main Menu" << endl;
					cout << "1. Generate a password" << endl;
					cout << "2. View password" << endl;
					cout << "3. Exit" << endl;
					cout << "Choose a menu option" << endl;
					cin >> menu;
				}
			}
	}
	else
	{
		cout << "Invalid Pin Number" << endl;
	}
	cout << "Have A Nice Day :)" << endl;// Friendly goodbye message
	return 0;// End the main function and close the program
}

int genpass()// The generate a password for the user
{
	int length = 0;
	char confirm = 'n';
	int peramiters = 0;
	string designation = "";
	string d = "";
	string p = "";
	bool stored = false;// Yes i used a boolean this time
	int random[30] = {0};
	int shifted[30] = {0};
	char encrypted[30] = {' '};
	char keep[30] = {' '};
	const char base[75] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
							 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
								'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '$', '%', '^', '&', 
								'*', '?', '+' , '=', '-', '~', '/'};	
	
	srand(static_cast<int>(time(0)));// Seeds the random number generater to use the clock to ensure it is different each time the program is used
	cout << "What is this password for?" << endl;
	cin.ignore(100, '\n');
	getline(cin, designation);
	ifstream inpass;// Opens the text file to read
	inpass.open("password.txt", ios::in);
	while (!inpass.eof())// Searches the text file to see if the password designation already exists
	{
		getline(inpass, d, '#');
		getline(inpass, p);
		if (designation == d)
		{
			stored = true;
		}
	}
	inpass.close();
	
	if (stored == true)// If the password exists in the text file already
	{
		cout << "Are you sure? This will overwrite your saved password! (y/n)" << endl;// Confirms if the user still wants to overwrite the old password with a new password
		cin >> confirm;
		if (confirm == 'y')
		{
			ifstream pass;// Over writes the text file
			pass.open("password.txt");
			ofstream temp;
			temp.open("temp.txt");
			string linebeg = "";
			string lineend = "";
			while ((getline(pass,linebeg, '#')) && (getline(pass, lineend)))
			{
				if (linebeg != designation)
				{
					temp << linebeg << '#' << lineend << endl;
				}
			}
			temp.close();
			pass.close();
			remove("password.txt");
			rename("temp.txt","password.txt");
			cout <<endl;
		}
	}
	
	ofstream outpass;// Opens the test file for writing
	outpass.open("password.txt", ios::app);
	
	if (outpass.is_open())
	{
		cout << "Choose the length of the password(1-30)" << endl;// Define the length of the password to be generated
		cin >> length;
		for (int x = 0; x < length; x += 1)
		{
			random[x] = randall();// Fills the array with random numbers by callint the random generation function
			int y = random[x];
			
			keep[x] = base[y];// Converts the random number to a character
		}
		for (int w = 0; w < length; w += 3)// Shifts every third random number for encryption beginning with the first one based on the first letter of the encryption word
		{
			shifted[w] = (random[w] + 23);
			if (shifted[w] > 74)
			{
				shifted[w] = (shifted[w] - 74);
			}
			int y = shifted[w];
			encrypted[w] = base[y];
		}
		for (int e = 1; e < length; e += 3)// Shifts every third random number for encryption beginning with the second one based on the second letter of the encryption word
		{
			shifted[e] = (random[e] + 5);
			if (shifted[e] > 74)
			{
				shifted[e] = (shifted[e] - 74);
			}
			int y = shifted[e];
			encrypted[e] = base[y];
		}
		for (int s = 2; s < length; s += 3)// Shifts every third random number for encryption beginning with the third one based on the last letter of the encryption word
		{
			shifted[s] = (random[s] + 19);
			if (shifted[s] > 74)
			{
				shifted[s] = (shifted[s] - 74);
			}
			int y = shifted[s];
			encrypted[s] = base[y];// Converts the shifted numbers to characters
		}	
		outpass << designation << '#';// Writes the designation to the text file along with the defined seperation character
		cout << "Your new password for " << designation << " is: ";
		for (int z = 0; z < length; z+= 1)// Displays the password and writes the encrypted password to the text file
		{
			cout << keep[z];// Password characters to display
			outpass << encrypted[z];// Encrypted chatacters to write to the file
		}
		outpass << endl;
		cout << endl;
		outpass.close();// Closes the text file
	}
	else
	{
		cout << "File failed to open" << endl;// Error message if the file was umable to be opened for writing
	}
	return 0;// End of the generation function and return to tne main menu	
}

int randall()// The random number generation function
{
	int randall = 0;
	randall = (rand() % 75);// Ensures the random number will be between 0 and 75
	return randall;// ends the random generation function and returns the tandom number to the generation function to be stored in an array
}

int seepass()// The view the password function
{
	string password = "";
	int sub = 0;
	int length = 0;
	string d = "";
	string p = "";
	bool stored = false;
	string designation = "";
	char encrypted[30] = {' '};
	int shifted[30] = {0};
	int unshifted[30] = {0};
	char decrypted[30] = {' '};
	const char base[75] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '$', '%', '^', '&', 
		'*', '?', '+' , '=', '-', '~', '/'};	
	
	ifstream inpass;// Opens the text file for reading
	inpass.open("password.txt", ios::in);
	
	if (inpass.is_open())
	{
		cout << "What password do you want to view?" << endl;
		cin.ignore(100, '\n');
		getline(cin, designation);
		
		while (!inpass.eof())// Searches the text file for the chosen password
		{
			getline(inpass, d, '#');
			getline(inpass, p);
			if (designation == d)
			{
				stored = true;
			}
		}
		if (stored == true)
		{
			inpass.close();// To move the file pointer back to the beginning of the file
			inpass.open("password.txt", ios::in);
			while (!inpass.eof())
			{
				getline(inpass, d, '#');
				getline(inpass, p);
				if (designation == d)
				{
					length = p.length();// Determines the length of the desired password
				}
			}
			char pw[length];// Converts the encrypted password from a string to characters to fill an array
			p.copy(pw, length);
			for (int x = 0; x < length; x += 1)// Assigns the characters of the encrypted password a number
			{
				sub = 0;
				while (sub < 75  && base[sub] != pw[x])
				{
					sub += 1;
				}
				shifted[x] = sub;
			}
			for (int w = 0; w < length; w += 3)// Shiftes every third encrypted number beginning with the first one for decryption
			{
				unshifted[w] = (shifted[w] - 23);
				if (unshifted[w] < 0)
				{
					unshifted[w] = (unshifted[w] + 74);
				}
				int y = unshifted[w];
				decrypted[w] = base[y];// Converts the unshifted number back to a character
			}
			for (int e = 1; e < length; e += 3)// Shiftes every third encrypted number beginning with the second one for decryption
			{
				unshifted[e] = (shifted[e] - 5);
				if (unshifted[e] < 0)
				{
					unshifted[e] = (unshifted[e] + 74);
				}
				int y = unshifted[e];
				decrypted[e] = base[y];// Converts the unshifted number back to a character
			}
			for (int s = 2; s < length; s += 3)// Shiftes every third encrypted number beginning with the third one for decryption
			{
				unshifted[s] = (shifted[s] - 19);
				if (unshifted[s] < 0)
				{
					unshifted[s] = (unshifted[s] + 74);
				}
				int y = unshifted[s];
				decrypted[s] = base[y];// Converts the unshifted number back to a character
			}
			cout << "Your saved password for " << designation << " is: ";// Displays the decrypted password on the screen
			for (int z = 0; z < length; z+= 1)
			{
				cout << decrypted[z];
			}
			cout << endl;
		}
		else
		{
			cout << designation << " was not found" << endl;// If the desired designation was not found in the text file
		}
	}
	else
	{
		cout << "File failed to open" << endl;// If the file failed to open for reading
	}
	inpass.close();
	return 0;// Ends the view function and returns to the main menu
}
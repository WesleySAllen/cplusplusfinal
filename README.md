# cplusplusfinal
This application is a random password generator.
This application will generate a random password for the user.
This application will tag the password with its designated use.
This application will encrypt the password with a vigenere cypher.
The designation and the encrypted password will be saved for the user to draw from when they need to use the password.
This application will allow the user to view the decrypted.
This application is accessed by a pin number.

For your viewing pleasure below, I have provided screen shots of the application in action. As well as an example of the encrypted passwords saved in the text file.

<img src="Screen Shot 2016-06-22 at 1.00.15 PM.png" />
<img src="Screen Shot 2016-06-22 at 1.00.38 PM.png" />
<img src="Screen Shot 2016-06-22 at 1.01.18 PM.png" />
<img src="Screen Shot 2016-06-22 at 1.01.55 PM.png" />
<img src="Screen Shot 2016-06-22 at 1.02.22 PM.png" />
<img src="SScreen Shot 2016-06-22 at 1.03.46 PM.png" />
<img src="Screen Shot 2016-06-22 at 12.59.20 PM.png" />
<img src="Screen Shot 2016-06-22 at 12.59.38 PM.png" />

I created this project to generate and store random complex passwords because I have had password issues in my past. Random complex passwords are more secure than just using a meaningful word for your password. However it can be complicated to come up with and remember random complex passwords. I have had the issue where due to the network protocols at my school, I was required to change my password every couple months. The network system would also store old passwords so I couldn't recycle them. I was locked out of my school account for a week due to this very issue once, And had to do all my work on a guest user account. That is why this project is personal to me. I believe I am not the only one who has had this issue, And many other people could benefit from an application like this one. When you are required to change your password at predetermined intervals it is very tempting to use simple and easy to remember passwords. I believe this defeats the purpose of changing the password so often. This application solves that issue by generating a random complex password for the user and helps them easily remember the complex password they have generated.


Below is a sample of the code inside the application.

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


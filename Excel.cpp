#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
string line(int n)
{
	string content = "";
	for(int i = 0; i < n; i++)
		content += (char)205;
	return content;	
}
void midLine(int widths[], int m) {
	cout<<(char)204;
	for(int i = 0; i < m; i++)
	{
		cout<<line(widths[i]);
		if(i == m - 1)
			cout<<(char)185;
		else	
			cout<<(char)206;
	}
	cout<<"\n";
}
void borderBottom(int widths[], int m)
{
	cout<<(char)200;
	for(int i = 0; i < m; i++)
	{
		cout<<line(widths[i]);
		if(i == m - 1)
			cout<<(char)188;
		else	
			cout<<(char)202;
	}
}
string space(int n)
{
	string content = "";
	for(int i = 0; i < n; i++)
		content += " ";
	return content;
}
string align(string text, int w, char alignment)
{
	w = w - text.length();
	string sp = space(w / 2);
	if(w % 2 != 0)
		if(alignment == 'r')
			text = " " + text;
		else
			text += " ";
	switch(alignment)
	{
		case 'l':
			return text + sp + sp;
			break;
		case 'c':
			return sp + text + sp;
			break;
		case 'r':
			return sp + sp + text;
			break;		
	}
}
int main() {
	// get information
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	start:
	string content = "";
	int n, m, colorText, colorBorder;
	for(int i = 1; i <= 15; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout<<i<<"- "<<"Color\n";
		Sleep(200);
	}
	SetConsoleTextAttribute(hConsole, 4);
	cout<<"Please choice your color for texts: ";
	cin>>colorText;
	cout<<"Please choice your color for borders: ";
	cin>>colorBorder;
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	cout<<"Number of users: ";
	cin>>n;
	cout<<"Number of properties: ";
	cin>>m;
	string users[n][m];
	string headers[m];
	int widths[m];
	char aligns[m];
	cout<<"\n";
	for(int i = 0; i < m; i++)
	{
		cin.ignore();
		cout<<"Header of property #"<<i + 1<<": ";
		getline(cin, headers[i]);
		cout<<"Width of the header "<<headers[i]<<": ";
		cin>>widths[i];
		cout<<"Alignment of the header "<<headers[i]<<": ";
		cin>>aligns[i];
		cout<<"\n";
	}
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		cout<<"User #"<<i + 1<<":\n";
		for(int j = 0; j < m; j++)
		{
			cout<<headers[j]<<": ";
			getline(cin, users[i][j]);	
		}
	}
	system("cls");
	// Border-top 
	SetConsoleTextAttribute(hConsole, colorBorder);
	cout<<(char)201;
	for(int i = 0; i < m; i++)
	{
		cout<<line(widths[i]);
		if(i == m - 1)
			cout<<(char)187;
		else	
			cout<<(char)203;
	}
	cout<<"\n";
	// Header
	cout<<(char)186;
	for(int i = 0; i < m; i++)
	{
		SetConsoleTextAttribute(hConsole, colorText);
		cout<<align(headers[i], widths[i], aligns[i]);
		SetConsoleTextAttribute(hConsole, colorBorder);
		cout<<(char)186;
	}
	cout<<"\n";
	midLine(widths, m);
	// Print informations user
	for(int i = 0; i < n; i++)
	{
		cout<<(char)186;
		for(int j = 0; j < m; j++)
		{
			SetConsoleTextAttribute(hConsole, colorText);
			cout<<align(users[i][j], widths[j], aligns[j]);
			SetConsoleTextAttribute(hConsole, colorBorder);
			cout<<(char)186;
		}
		cout<<"\n";
		if(i != n - 1)
			midLine(widths, m);
		else	
			borderBottom(widths, m);	
	}
	SetConsoleTextAttribute(hConsole, 7);
	lable:
	cout<<"\n\nPress r to return to main menu";
	cout<<"\n\nPress x to exit the program\n";
	char ch = getch();
	if(ch == 'r')
	{
		system("cls");
		goto start;
	}
	else if(ch == 'x')
		exit(0);
	else
	{
		cout<<"\nInvalid !";
		goto lable;	
	}	
}

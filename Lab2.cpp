//============================================================================
// Name        : Lab2.cpp
// Author      : Andrew
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

void factorial() { //calculates factorial of input
	unsigned short x;
	unsigned long y;
	cout << "Pls input an unsigned short integer smaller than 12: ";
	fflush(stdout);
	cin >> x;
	if(x > 12) printf("Sorry, your number is too big\r\n");
	else {
		for(y=1; x>0; x--) //calculates factorial
			y*=x;
		cout << "The factorial is " << y << "\n";
	}
}

void leap_year() { //determines whether input year is a leap year
	unsigned int x;
	cout << "Pick a year to see if it is leap or not: ";
	fflush(stdout);
	cin >> x;
	if(x % 4 == 0) {
		cout << x << " is indeed a leap year\n"; //mod 4 to check for divisibility
	}
	else {
		cout << x << " is unfortunately not a leap year\r\n";
	}
}

void maximum() { //prints maximum of two numbers
	float x,y,z;
	cout << "Input the first number: ";
	fflush(stdout);
	cin >> x;
	cout << "Input the second number: ";
	fflush(stdout);
	cin >> y;
	z = x > y ? x : y;
	cout << z << " is the max number\r\n";
}

void division() { //divides two floats
	int x,y;
	float z;
	cout << "Input the first number: ";
	fflush(stdout);
	cin >> x;
	LOOP:
	cout << "Input the second number: ";
	fflush(stdout);
	cin >> y;
	if (y == 0) { 			//Error check for divide by zero
		cout << "Error, can't divide by zero\n";
		goto LOOP;
	}
	z = (float)x/(float)y;
	cout << "The answer is " << z << "\n";
}

void problem_1() {
	int exit = 0;
	char choice;
	while(exit == 0) { 			//Creates menu, option 5 will take you to Problem 2
		cout << "1. Factorial\r\n2. Leap Year\r\n3. Maximum\r\n4. Division\r\n5. Exit\r\nEnter a number: ";
		fflush(stdout);
		choice = getchar();
		switch(choice) {
		case '1': factorial();
				break;
		case '2': leap_year();
				break;
		case '3': maximum();
				break;
		case '4': division();
				break;
		case '5': exit = 1;
				break;
		default: cout << "\r\nInvalid input. Try again\r\n";
				break;
		}
		int c;
		while((c = getchar()) != '\n' && c != EOF);
	}

}

void problem_2() { 		//binary representation
	unsigned short x;
	cout << "Input a decimal number: ";
	fflush(stdout);
	cin >> x;
	char choice;
	int c;
			while((c = getchar()) != '\n' && c != EOF);
	cout << "How would you like this to be found, using (a)rithmetic or (b)itwise operations? ";
	fflush(stdout);
	choice = getchar();
	if(choice == 'a') { 		//arithmetic method
		int bits = 1;
		while(pow(2,bits) < x) 		//how many bits we need
			bits++;
		int buffer[bits];
		int i;
		for(i=0;i<bits;i++) { 		//pull out powers of 2
			buffer[bits-i-1] = x%2;
			x/=2;
		}
		cout << "Your number in binary is: " << "\n";
		for(i=0;i<bits;i++) { 		//print the output
			cout << buffer[i];
		}
	}
	else if (choice == 'b') { 		//bitwise method
		int buffer[16]; 		//max 16 bits for unsigned short
		int i;
		for(i=0;i<16;i++)
			buffer[16-i-1] = (x & (1<<i)) >> i; 		//the formula you want to see
		cout << "Your number in binary is: " << "\n";
		for(i=0;i<15;i++) 			//trim leading zeros
			if(buffer[i] == 1)
				break;
		for(;i<16;i++) { 		//print the output
			cout << buffer[i];
		}
	}
	else cout << "Invalid choice\r\n";
}

int main() {
	problem_1();
	problem_2();
	return 1;
}

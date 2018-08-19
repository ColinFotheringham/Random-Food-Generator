#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
#include <fstream>
using namespace std; 

//Functions we will use
int * getRand(int numOfDays, int numOfFood, int randomNum[]);
string getFileName();
string * readFile(string fileName, string food[]);
int countLines(string filename);
int numDays();
void display(int numOfDays, string days[], string food[], int randomNum[]);

/************************************************************
 * Main()
 *
 * Main is used to get file name and then to call the read
 * function
 ***********************************************************/
int main()
{

    string food[365];

    int randomNum[365]; 

 	string days [] = {"Monday", "Tuesday", 
 	                  "Wednesday", "Thursday",
 	                  "Friday", "Saturday", "Sunday"};
               

	cout << "Welcome To Food Generator\n" << endl;

    //Store Values in variables
	string fileName = getFileName();

    //Count number of words first. 
    const int numOfFood = countLines(fileName);

    const int numOfDays = numDays();

    if (numOfFood < numOfDays)
    {
    	cout << endl << endl;
    	cout << "ERROR the number of Food is less than"
    	     << " number of days." << endl;

    	cout << "PLEASE ENTER "  << numOfDays - numOfFood
    	     << " MORE ITEMS TO: " << fileName 
    	     << endl;

  	    exit(EXIT_FAILURE);

    }
 	
 	//Read in a file   
 	readFile(fileName, food);

 	//Genrate a random Number
 	getRand(numOfDays, numOfFood, randomNum);

 	display(numOfDays, days, food, randomNum);

 	//Make like a tree
	return 0;
}

/****************************************************************
 * getFileName():
 *
 * This function gets the filename from the user
 ***************************************************************/
string getFileName()
{
	string fileName; 
	cout << "FILENAME: ";
	cin >> fileName;

	return fileName;
}

/*****************************************************************
 * countWords()
 *
 * This function reads the file and counts the words.
 ****************************************************************/
int countLines(string fileName)
{
  ifstream fin(fileName);
  
  if(fin.fail())
  {
  	cout << "ERROR File cannot be found!\n";

  	exit(EXIT_FAILURE);
  } 

  int count = 0;
  string line;
  while(getline(fin, line)) 
  {
  	++count;
  }
  
  fin.close();

  return count;

}

/****************************************************************
 * numOfDays()
 *
 * This function gets the the ammount of days that the user
 * would like to plan for.
 ***************************************************************/
int numDays()
{
	int days = 0; 
	cout << "Days: ";
	cin >> days;

	return days;
}

/*****************************************************************
 * readFile()
 *
 * This function reads the file and throws errors if file not
 * found.
 ****************************************************************/
string * readFile(string fileName, string food[])
{
  ifstream fin(fileName);
  
  if(fin.fail())
  {
  	cout << "ERROR File cannot be found!\n";

  	exit(EXIT_FAILURE);
  } 

  int i = 0;

  while(!fin.eof())
  {
  	getline(fin, food[i]);
  	i++;

  }
  
  fin.close();

  return food;

}

/******************************************************************
 * getRand():
 *
 * This function gets a random number not chosen before.
 *****************************************************************/
int * getRand(int numOfDays, int numOfFood, int randomNum[])
{
	//Seed RNG First
 	srand(time(NULL));

 	//Generate random numbers
 	for (int i = 0; i < numOfDays; i++)
 	{
 		bool verify;
 		int num;

 		do
 		{
 			num = rand()%numOfFood;

 			verify = true;
 			for(int j = 0; j < i; j++)
 			{
 				if(num == randomNum[j])
 				{
 					verify = false;
 					break;
 				}
 			} 
 		}while (!verify);

 		randomNum[i] = num;
 	} 
 	return randomNum;
}

/******************************************************************
 * display():
 *
 * This function displays the food on the screen. 
 * (Need to add better display of info.) ASAP...
 *****************************************************************/
void display(int numOfDays, string days[], string food[], int randomNum[])
{
	int dayNames = 0;

	cout << endl;

 	for(int i = 0; i < numOfDays; i++)
 	{
 		cout << days[dayNames] << " : "
 		     << food[(randomNum[i])]<< endl;
 		dayNames++;

 		if(dayNames >= 7){
 			dayNames = 0;

 			cout << "\n \n \n";
 		}
 		
 	}
}
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>


using namespace std;
//function 1
//input strings
string enter(string inputtxt){	
	
	cout << "Enter text with max of 1000 characters >>\n\n";
			cin.ignore();
			getline(cin, inputtxt);
			if (inputtxt.size() > 1000){
				cout << "Too much characters, only limited to 1000 characters\n";
			}
			else if(inputtxt.empty()){
				while(inputtxt.empty()){
					cout <<"you can not leave text input empty, you must enter at least a character: \n";
					getline(cin, inputtxt);
					if (inputtxt.size() > 1000){
				cout << "Too much characters, only limited to 1000 characters\n";
					}
					else if(!inputtxt.empty()){
				cout <<"Display Input: " << inputtxt;
				cout << endl;
				}	
		}
		}
		
			else{
				cout <<"Display Input: " << inputtxt;
				cout << endl;	
			}
			cout <<"\n";
			return inputtxt;
}
//-------------------------------------------------

//funtion 2
//read files
 string reader(string inputtxt, string textcontent){
 			
 			string but ;
			cout <<"Enter name of text file, DON'T include .txt extension': \n";
			cin.ignore();	
			ifstream files;
			cin >> inputtxt;
			inputtxt.append(".txt");
			files.open(inputtxt.c_str());
			
			if(!files.is_open()){
				cout << "File does not exist or incorrect filename\n";
				
			}
			cout << "Content in the file are: \n\n";
			while(true){
				int i = 0;
				getline(files, textcontent);
				//cout << textcontent << endl;
				but = but + textcontent + "\n";
				
				if (files.eof()) break;
				
			}
			textcontent = but;
			cout <<textcontent;
			cout <<"\n\n";
			
			return textcontent;
 }
 //----------------------------------
 
 //function 3-1
 //string input charteristics
 void stat(string textcontent){
 	cout << fixed << showpoint << setprecision(2);
 	int a;
	a = textcontent.size();
	cout <<"Total characters: "<<a;
	cout << endl;
	
	int b = 1;
	for (int i =0; textcontent[i] !='\0'; i++){
		if (isspace(textcontent[i])){
			b++;
		}
		
	}
	cout << "The total words: "<<b;
	cout <<endl;
	
	float  average;
	average = a/float(b);
	cout << "Average number of Character per Word: " << average<<endl;
	
	//---------------hist
	char tempo[1000];
	
	for(int i = 0; i < a; i++){
		tempo[i] =tolower(textcontent[i]);
		
	}

	int frez[256] = {0};
	int i,j, count;
	
	for(i=0; tempo[i] !='\0'; i++){
		
		if(!islower(tempo[i]) && !isdigit(tempo[i])){
		count++;
		continue;
		}
		
		else{
			frez[tempo[i]]++;
		}
		
		
	}
	
	for (i=0;i<256;i++) {
	if (frez[i] != 0 ){
		cout <<"letter "<<char (toupper((char)i)) << " or " << (char)i <<"  >>  "<< frez[i]<<" times "<<endl;
		
	}
	}
	cout << "Others characters occur: >> " << count << " times "<< endl;
	cout << "Total is :>> "<< a;

		cout<<"\n\n";
}
//-----------------


//function 4-1
	//-----------decrypted Caeser cipher and store to decrpted file as file.txt
	
	void encrypt(string textcontent){
		string result = "";
	int shift;
	
	cout << "Enter the required decrypting key, only integer is allowed\n";
	cin >> shift;
	
	if (shift < 1 ){
		cout << "Only integer is required and must be greater than 1 for decryption process to start\n";
		cout << "This process is stop\n";
		
	}
	else{
    shift = 26 - shift;
		cout <<"Text decrption start------\n";
	    for (int i=0;i<textcontent.length();i++) 
	    { 
	        if (isupper(textcontent[i])) {
	        	result += char(int(textcontent[i]+shift-65)%26 +65); 
			}
	            
	    else if(islower(textcontent[i])){
	    	 result += char(int(textcontent[i]+shift-97)%26 +97);
		}
		
		else if (isdigit(textcontent[i])){
			result = result + textcontent[i];
		}
		
		else{
			result = result + textcontent[i];
		}
	        
	    } 
	    cout <<"Decrption completed... Decrpted text below\n";
	    cout <<">>:  " << result <<"\n\n";
	}
	cout <<"Press any key on you keyboard to store decrpted data into a file\n";
	system ("pause");
	cout <<"do you want to enter file name or stored as default name\n";
	cout << "enter y for yes or n for no: ";
	char input;
	cin >> input;
	while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
		cout << "wrong options you must enter Y or N: ";
		cin >> input;
	}
	cin.ignore();
	if (input == 'y' || input == 'Y'){
		string name;
		cout <<"Enter filename\n";
		cin >> name;
		ofstream myoutPut((name + ".txt").c_str());
	  	myoutPut << result;
	  	cout << "Congratulation you Decrypted file is stored...";
	}
	else{
	string name = "decyptedText.txt";
	ofstream myoutPut((name).c_str());
  	myoutPut << result;
  	cout << "Congratulation you decrypted File is stored with default name as decyptedText.txt...";
	}
	
}	
	//-----------end decrypted
	
//-----------------------------------------------------------------------------------------------------------------------------------------------
//file statistics 
//function 3-2
void stater(string textcontent){
 	cout << fixed << showpoint << setprecision(2);
 	int a;
	a = textcontent.size();
	cout <<"Total characters: "<<a;
	cout << endl;
	
	int b = 0;
	for (int i =0; textcontent[i] !='\0'; i++){
		if (isspace(textcontent[i])){
			b++;
		}
		
	}
	cout << "The total words: "<<b;
	cout <<endl;
	
	float  average;
	average = a/float(b);
	cout << "Average number of Character per Word: " << average<<endl;
	
	//---------------hist
	char tempo[10000];
	
	for(int i = 0; i < a; i++){
		tempo[i] =tolower(textcontent[i]);
		
	}

	int frez[256] = {0};
	int i,j, count;
	
	for(i=0; tempo[i] !='\0'; i++){
		
		if(!islower(tempo[i]) && !isdigit(tempo[i])){
		count++;
		continue;
		}
		
		else{
			frez[tempo[i]]++;
		}
		
		
	}
	
	for (i=0;i<256;i++) {
	if (frez[i] != 0 ){
		cout <<"letter "<<char (toupper((char)i)) << " or " << (char)i <<"  >>  "<< frez[i]<<" times "<<endl;
		
	}
	}
	cout << "Others characters occur: >> " << count << " times "<< endl;
	cout << "Total is :>> "<< a;

		cout<<"\n\n";
}

//end of function 3-2
//-----------------------------------------------------------------------------------------------------------------------------------------------
	
 
 
int main(){
	char choice;
	string inputtxt, textcontent;
	cout << "This program is design to read text/ String and store the result in Decrpted mode\n";
	cout <<"Read text from keyboard or Text file\n";
	cout <<"Enter  K for keyboard input or T for Textfile choose: ";
	cin >> choice;
	while(choice != 'k' && choice != 'K' && choice != 't' && choice != 'T'){
		cout << "Incorrect input\n";
		cout << "enter K or T only: ";
		cin >> choice;
	}
	cout << endl;
	//choice case
	switch (choice){
		case 'k':
		case 'K':
			
			textcontent = enter(inputtxt); //fun1
			stat(textcontent);//fun3-1
			encrypt(textcontent);//fun 4-1
			
			
			break;
		case 't':
		case 'T':
			
		textcontent = reader(inputtxt, textcontent); //fun2
		stater(textcontent);//fun3-2
		encrypt(textcontent);//fun 4-1
		
			break;
}
					
	
	return 0;
}

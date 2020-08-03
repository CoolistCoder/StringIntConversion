//conversions between integers and strings
#include <iostream>
using namespace std;

int string_to_int(std::string);

int main() {

	cout << string_to_int("0") << endl;

	return 0;
}


int string_to_int(std::string str){
	//in order to convert from a string to an integer,
	//a few rules must be remembered
	//all characters must translate to integers
	//all characters must be subracted by 32 to get their real values

	unsigned int multiplier = 1; //this value will be mutliplied by 10
	bool toneg = false; //determines if the value should be negative


	//check if str[0] is '-'
	if (str[0] == '-'){
		toneg = true; //make the integer negative
		str[0] = '0';
	}

	//go through each text character
	for (unsigned int i=str.length(); i>0; --i){
		//make sure the text character is not a letter
		if ((str[i-1]) < 48 || (str[i-1] > 57)){
			return 0;
		}
	}

	int accumulate = 0; //accumulates the value we need

	//go through each text character again!
	for (unsigned int i=str.length(); i>0; --i){
		//if we're at the point where we would have had a negative integer
		//just break
		if (str[i-1]==0){
			break;
		}

		//go through the string backwards so we can accumulate proper
		accumulate += ((str[i-1]-48)*multiplier); //drop the value by 48 and perform m^10
		multiplier *= 10; //m^10 each time

	}

	//make accumulate negative if our negative check occurred
	if (toneg)
		accumulate *= -1;

	return accumulate;
}

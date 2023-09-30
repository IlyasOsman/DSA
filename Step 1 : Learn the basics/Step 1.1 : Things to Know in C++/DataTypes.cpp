#include <iostream>

int dataTypes(string type) {
	// Write your code here
	if(type == "Integer")
	{
		return sizeof(int);
	}
	else if(type == "Long")
	{
		return sizeof(long);
	}
	else if(type == "Float")
	{
		return sizeof(float);
	}
	else if(type == "Double")
	{
		return sizeof(double);
	}
	else
	{
		return sizeof(char);
	}
}

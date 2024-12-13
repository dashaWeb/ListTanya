// ListTanya.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
int main()
{
	List<int> list;
	int choice;
	while (true)
	{

		cout << R"(
				[1] - Create a list of the specified length; 
				[2] - Print list; 
				[3] - Searching for an element by an indicative value; 
				[4] - Inserting a new element before the value; 
				[5] - Inserting a new element after the value; 
				[6] - Delete an element by value; 
				[0] - Exit;
				Enter your choice ::  
)";
		
		
		cin >> choice;
		
		if (choice < 0 and choice > 6)
			continue;
		switch (choice)
		{
		case 1:
			cout << "Input number of list --> ";
			int size;
			cin >> size;
			list = List<int>(size);
			break;
		case 2: 
			list.print();
			break;
		case 3:
			try
			{
				cout << "Input value :: ";
				int value;
				cin >> value;
				cout << "Input new value :: ";
				int newValue;
				cin >> newValue;
				list(value) = newValue;
				cout << "Item found" << endl;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 4:
			cout << "Input value :: ";
			int value;
			cin >> value;
			cout << "Input new value :: ";
			int newValue;
			cin >> newValue;
			list.insertBefore(value, newValue);
			break;
		case 5:
			cout << "Input value :: ";
			value;
			cin >> value;
			cout << "Input new value :: ";
			newValue;
			cin >> newValue;
			list.insertAfter(value, newValue);
			break;
		case 6:
			cout << "Input value :: ";
			value;
			cin >> value;
			list.removeByData(value);
			break;
		}
		if (choice == 0)
		{
			break;
		}
	}

}


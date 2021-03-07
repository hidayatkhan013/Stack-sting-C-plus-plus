/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr test;
	test.push_front("test push front first");
	test.push_front("test push front second");
	test.push_back("test push back first");
	test.push_back("test push back second");
	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test.get(i) << endl;
	}

	cout << endl << "after pop back" << endl<<endl;
	test.pop_back();
	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test.get(i) << endl;
	}
	cout << endl << "after pop front" << endl << endl;
	test.pop_front();
	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test.get(i) << endl;
	}

	cout << endl << "value at back : " << test.back() << endl;
	cout << endl << "value at front : " << test.front() << endl;
	

	

  return 0;
}

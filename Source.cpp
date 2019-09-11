#include "Queue.h"
#include <stack>
#include <string>
#include <cctype>


void palindromeTest(string str);
bool isPalindrome(Queue q, stack<char> s);

int main()
{
	string test1 = "madam";
	string test2 = "nurses run";
	string test3 = "random sentence";
	string test4 = "A man, a plan, a canal, panama!";
	string test5 = "Luis Severino Stifles Red Sox and Makes His Wild-Card Case";

	palindromeTest(test1);
	palindromeTest(test2);
	palindromeTest(test3);
	palindromeTest(test4);
	palindromeTest(test5);

	system("pause");

	return 0;
}

void palindromeTest(string str)
{
	Queue myQueue;

	stack<char> myStack;

	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			myQueue.push(tolower(str[i]));
			myStack.push(tolower(str[i]));
		}
	}

	if (isPalindrome(myQueue, myStack))
		cout << str << " is a palindrome.\n";
	else
		cout << str << " is NOT a palindrome.\n";
}

//This function will call class Queue's copy constructor, deep copy is a must
bool isPalindrome(Queue q, stack<char> s)
{
	while (q.isEmpty() == false)
	{
		char c1 = q.top();
		char c2 = s.top();

		if (c1 != c2)
			return false;
		q.pop();
		s.pop();
	}

	return true;
}

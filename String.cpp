#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
class String
{
public:
	void display()
	{
		cout << _str << endl;
	}
	friend ostream &operator<<(ostream&os, String&str);

	friend istream&operator>>(istream&is, String&str);

	String(const char*str = "")
	{
		int len = strlen(str);
		_str = new char[_capacity];
		_capacity = len+1;
		_size = len;
		strcpy(_str, str);

	}
	String(char*str)
		:_str(new char[strlen(str) + 1])

	{
		strcpy(_str, str);
	}
	~String()
	{}
	/*String(const String&str)
	:_str(new char[strlen(str._str)+1])
	{
	strcpy(_str, str._str);
	}*/
	void Swap(String &str)
	{
		swap(_str, str._str);
		swap(_capacity, str._capacity);
		swap(_size, str._size);

	}
	String(const String &str)
		:_str(NULL)
		
	{
		String temp(str._str);
		this->Swap(temp);

	}
	
	
	/*String&operator=(const String&str)
	{
	if (this != &str)
	{
	String tmp(str);
	swap(_str, tmp._str);
	}
	return*this;
	}*/
	String&operator=(String str)
	{

		//swap(_str, str._str);
	    Swap(str);
		return*this; 
	}
	bool operator > (const String&str)
	{
		char*str1 = _str;
		char*str2 = str._str;
		while (*str1&&*str2)
		{
			if (*str1 > *str2)
			{
				return true;
			}
			else if (*str1 < *str2)
			{
				return false;
			}
			else
			{
				str1++;
				str2++;
			}
		}
		if (*str1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (const String&str)
	{
		char *str1 = _str;
		char *str2 = str._str;
		while (*str1&&*str2)
		{
			if (*str1==*str2)
			{
				*str1++;
				*str2++;
			}
			else
			{
				return false;
			}
		}
		if (*str1 || *str2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator < (const String&str)
	{
		return!(*this>str._str || *this == str._str);
	}
	bool operator >= (const String&str)
	{
		return!(*this < str._str);
	}
	bool operator <= (const String&str)
	{
		return!(*this>str._str);
	}
	size_t size()
	{
		return (strlen(_str));
	}
	String operator+(const String&str)
	{
		String newstring;
		if (!&str)
		{
			return _str;
		}
		else if(!_str)
		{
			return str._str;
		}
		else
		{
			newstring._str = new char[strlen(_str) + strlen(str._str) + 1];
			strcpy(newstring._str, _str);
			strcat(newstring._str, str._str);
		}
		return newstring;
	}
	void Pushback(char ch)
	{
		checkcapacity(_size + 2);
		_str[_size++] = ch;
		_str[_size] = '\0';
		//Insert(_size, ch);
		
	}
	void Insert(size_t pos,  char ch)
	{
		checkcapacity(_size + 2);
		assert(pos <= _size);
			size_t end = _size ;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
	}
	void Insert(size_t pos, char*str)
	{
		size_t len = strlen(str);
		checkcapacity(len + _size + 1);
		assert(pos <= _size);
		size_t end = _size;
		while (end >= pos)
		{
			_str[end + len] = _str[end];
			end--;
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
		_size += len;
	}
	char&operator[](size_t index)
	{
		return _str[index];
	}
	
	private:
		void checkcapacity(size_t size)
		{
			if (size > _capacity)
			{
				size_t newcapacity = size > 2 * _capacity ? size : 2 * _capacity;
				/*char*temp =(char*)new int[newcapacity];
				memcpy(temp, _str, sizeof(char*)*_size);
				delete[]_str;
				temp = _str;*/
				_str = (char*)realloc(_str,newcapacity);
				_capacity = newcapacity;
			}
		}
private:
	char* _str;
	size_t _capacity;
	size_t _size;
};
 ostream &operator<<(ostream&os, String&str)
 {
	 os << str._str << endl;
	 return os;
 }
 istream&operator>>(istream&is, String&str)
 {
	 cout << "ÇëÊäÈëÒ»¸ö×Ö·û´®£¡";
	 is >> str._str;
	 return is;
 }

void Test()
{
	String s1("hello world");
	String s2("change world");
	//s2=s1;
	//s1.Insert(2, 'n');
	//cout << s1 << endl;
	s2.Insert(2, "ni");
	s2.display();
	/*String s3;
	s3 = s1;*/
	//cout << (s1+s2) << endl;
	//s1[0] ='a';
	//s2.Pushback('e');
	//cout << s2 << endl;
		
}
int main()
{
	Test();
	system("pause");
	return 0;
}
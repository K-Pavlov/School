#include <string.h>
#include <iostream>
using namespace std;

class IndexOutOfBoundsException
{
};

class String
{
	int capacity_;
	int size_;
	char* buffer_;
	
	void ensure_capacity(int cap)
	{
		if(capacity_>= cap) {
			return;
		}
		char* tmp = buffer_;
		capacity_ = cap;
		buffer_ = new char[capacity_];
		strcpy(buffer_, tmp);
		delete [] tmp;
		
	}
	
	friend ostream& operator<<(ostream&, const String&);
	
	
	public:
	String(int capacity)
		: capacity_(capacity),
		  size_(0),
		  buffer_(new char[capacity])
	{
		buffer_[0] = '\0';
	}
	
	~String()
	{
		delete [] buffer_;
	}
	
	String(const char* str)
	: capacity_(0),
	  size_(0),
	  buffer_(0)
	{
		size_ = strlen(str);
		capacity_ = size_ + 1;
		buffer_ = new char[capacity_];
		strcpy(buffer_, str);
	}
	
	int size() const
	{
		return strlen(buffer_) - 1;
	}
	
	int length() const
	{
		return strlen(buffer_) - 1;
	}
	
	int capacity() const
	{
		return capacity_;
	}
	
	bool empty() const
	{
		return buffer_[0] == '\0';
	}
	
	void clear()
	{
		memset(buffer_,0,strlen(buffer_));
	}
	
	char& at(int index)
	{
		if(index <= size_ - 1)
		{
			return buffer_[index];
		}	
		throw new IndexOutOfBoundsException(); 
	}
	
	String(const String& other_string)
	{
		size_ = other_string.size_;
		capacity_ = other_string.capacity_;
		buffer_ = other_string.buffer_;
	}
	
	String& operator=(const String& other_string)
	{
		if(*this == other_string)
		{
			return *this;
		}
		size_ = other_string.size_;
		capacity_ = other_string.capacity_;
		buffer_ = other_string.buffer_;
		return *this;
	}
	
	String& operator+=(const String& s) 
	{
		ensure_capacity(size_+s.size_+1);
		strcat(buffer_, s.buffer_);
		return *this;
	}		 
	
	bool operator ==(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) == 0;
	}
	
	bool operator !=(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) != 0;
	}
	
	bool operator <(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) < 0;
	}
	
	bool operator >(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) > 0;
	}
	
	bool operator <=(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) <= 0;
	}
	
	bool operator >=(const String& other_string)
	{
		return strcmp(buffer_, other_string.buffer_) >= 0;
	}
	
};

ostream& operator<<(ostream& out, const String& s) 
{
	out << s.buffer_;
	return out;
}

int main()
{
	String sd(300);
 	String s1("");
	String s2("World!");
	s1 = s2;
	cout << s1 << endl;
	cout << sd << endl;
	return 0;
}

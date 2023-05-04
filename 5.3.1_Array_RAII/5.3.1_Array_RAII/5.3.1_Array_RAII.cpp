#include <iostream>
#include <exception>


class smart_array
{
public:
	smart_array()
	{
		arr = nullptr;
		capacity = 0;
		size = 0;
	}
	smart_array(int _capacity)
	{
		if (_capacity > 0)
		{
			arr = new int[_capacity];
			capacity = _capacity;
			size = 0;
		}
		else
		{
			*this = smart_array();
		}		
	};
	~smart_array()
	{
		delete[] arr;
	};
	void add_element(int _value)
	{
		if (size + 1 <= capacity)
		{
			arr[++size - 1] = _value;
		}
		else
		{
			throw(std::out_of_range("Превышен размер массива!"));
		}
	};
	int get_element(int _index)
	{
		if (_index < size && _index >= 0)
		{
			return arr[_index];
		}
		else
		{
			throw(std::out_of_range("Попытка получить доступ к элементу с несуществующим индексом!"));
		}
	};
private:
	int *arr;
	int capacity;
	int size;
};


int main()
{
	setlocale(LC_ALL, "RU");
	
	try 
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception &ex) 
	{
		std::cout << ex.what() << std::endl;
	}
}



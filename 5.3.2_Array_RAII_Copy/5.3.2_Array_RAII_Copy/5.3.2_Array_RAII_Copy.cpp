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
			*this = smart_array();//присваивание перемещением
		}
	};
	smart_array &operator=(smart_array &&other) noexcept//оператор присваивания перемещением
	{
		if (this != &other)
		{	
			delete[] arr;	
			capacity = other.capacity;
			size = other.size;
			arr = other.arr;
			other.arr = nullptr;
		}
		return *this;
	}
	smart_array &operator=(const smart_array &other)//оператор присваивания копированием
	{
		if (this != &other)
		{
			delete[] arr;
			capacity = other.capacity;
			size = other.size;
			if (other.capacity > 0)
			{
				arr = new int[capacity];
				for (int i = 0; i < capacity; ++i)
				{
					arr[i] = other.arr[i];
				}
			}
		}
		return *this;
	}
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
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;//присваивание копированием
}

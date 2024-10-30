#include<iostream>
#include<vector>

template<class T>

class vector
{
public:
	vector(int s): Size(s), Capacity(s)
	{
		arr = new T[Capacity]();
	}

	vector() : vector(0) {}

	~vector()
	{
		delete[] arr;
	}

	vector(std::initializer_list<T> v):vector(static_cast<int>(v.size()))
	{
		auto it = v.begin();
		for (int i=0;i<v.size();++i)
		{
			arr[i] = *it;
			++it;
		}
	}

	T at(int index)
	{
		if (index<0 || index>Size - 1)
		{
			throw std::exception("invalid index");
		}
		else
		{
			return arr[index];
		}
	}

	void push_back(T value)
	{
		if (Capacity == Size)
		{
			T* arr2 = new T[Size];
			for (int i = 0; i < Size; ++i)
			{
				arr2[i] = arr[i];
			}
			delete[] arr;
			Capacity *= 2;
			arr = new T[Capacity];
			for (int i = 0; i < Size; ++i)
			{
				arr[i] = arr2[i];
			}
			delete[] arr2;
		}
		arr[Size] = value;
		++Size;
	}

	int size()
	{
		return Size;
	}
	int capacity()
	{
		return Capacity;
	}

private:
	T* arr;
	int Capacity;
	int Size;
};


int main()
{
	vector<int> v = { 1,2,3 };

	try
	{
		std::cout << v.at(0)<<std::endl;
		std::cout << v.at(1) << std::endl;
		std::cout << v.at(2) << std::endl;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}

	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;

	v.push_back(5);
	v.push_back(8);

	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;

	return 0;
}
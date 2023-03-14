#pragma once
#include "Book.h"
#include <initializer_list>
class Library {
	Book* arr;
	std::size_t size;

public:
	Library()
		: arr(nullptr), size(0)
	{}

	Library(std::size_t size)
		: size(size), arr(new Book[size])
	{}

	Library(std::initializer_list<Book> list)
		: size(list.size()), arr(new Book[list.size()])
	{
		std::size_t i = 0;
		for (Book book : list)
		{
			arr[i] = book;
			i++;
		}
	}

	Library(const Library& orig)
		: size(orig.size), arr(new Book[orig.size])
	{
		for (std::size_t i = 0; i < size; i++)
		{
			arr[i] = orig[i];
			i++;
		}
	}

	Library(Library&& orig)
		: arr(std::move(orig.arr)), size(std::move(orig.size))
	{}

	Library& operator=(const Library& right)
	{
		size = right.size;
		arr = new Book[size];

		for (std::size_t i = 0; i < size; i++)
		{
			arr[i] = right.arr[i];
		}

		return *this;
	}
	
	Library& operator=(Library&& right)
	{
		std::swap(size, right.size);
		std::swap(arr, right.arr);

		return *this;
	}

	Book& operator[](std::size_t index)
	{
		return arr[index];
	}

	const Book& operator[](std::size_t index) const
	{
		return arr[index];
	}

	std::size_t GetSize() const
	{
		return size;
	}

	~Library()
	{
		if (size > 0)
			delete[] arr;
	}
};

std::ostream& operator<<(std::ostream& out, const Library& l)
{
	auto size = l.GetSize();
	out << "Library contents {\n";
	for (auto i = 0; i < size; i++)
	{
		out << l[i];
	}
	out << "}\n";
	return out;
}
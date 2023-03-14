#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

class Book
{
	std::string author, title;

public:
	Book()
		: author(""), title("")
	{}

	Book(const std::string& author, const std::string& title)
		: author(author), title(title)
	{}


	Book(std::string&& author, std::string&& title)
		: author(author), title(title)
	{}

	std::string GetAuthor() const { return author; }
	std::string GetTitle() const { return title; }

	void SetAuthor(const std::string& new_author) { author = new_author; }
	void SetTitle(const std::string& new_title) { title = new_title; }

	void SetAuthor(std::string&& new_author) { author = new_author; }
	void SetTitle(std::string&& new_title) { title = new_title; }

	Book(const Book& other)
		: author(other.author), title(other.title)
	{}

	Book(Book&& other)
		: author(std::move(other.author)), title(std::move(other.title))
	{}

	Book& operator=(const Book& other)
	{
		author = other.author;
		title = other.title;
		return *this;
	}

	Book& operator=(Book&& other)
	{
		author = std::move(other.author);
		title = std::move(other.title);
		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
	out << b.GetTitle() << " by " << b.GetAuthor() << "\n";
	return out;
}
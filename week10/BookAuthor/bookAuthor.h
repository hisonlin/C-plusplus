#pragma once
#include<string>
#include<vector>
#include<memory>
#include<iostream>

class Author;//forward declaration of Author class
class Book
{
	std::string title;
	std::shared_ptr<Author> pAuthor;

public:
	Book(std::string t) :title(t) { std::cout << "Book created: " << title << std::endl; }

	~Book() 
	{ 
		std::cout << "~Book: " << title << std::endl;
		pAuthor = nullptr;
	}

	void setAuthor(std::shared_ptr<Author> author)
	{ 
		pAuthor = author;
	}

	std::string getTitle()
	{
		return title;
	}

};

class Author
{
	std::string name;
	std::weak_ptr<Book> pBook;

public:
	Author(std::string authorName) :name(authorName) { std::cout << "Author created: " << name << std::endl; }

	~Author()
	{
		std::cout << "~Author: " << name << std::endl;
		
		
	}

	void setBook(std::shared_ptr<Book> book)
	{
		pBook = book;
	}

	void printBookTitle()
	{
		std::shared_ptr<Book> bookPtr = pBook.lock();
		if(bookPtr){ std::cout << bookPtr->getTitle() << std::endl; }
		
	}
};
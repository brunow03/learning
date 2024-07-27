#ifndef BOOK_HPP
#define BOOK_HPP

#include "./Chrono.hpp"
#include <string>
#include <iostream>

namespace Library {

	enum class Genre
	{
		children = 1, fiction, nonfiction, periodical, biography
	};

	class Book {
		public:
			Book();
			Book(std::string& t_ISBN, std::string& t_title, std::string& t_author, const Chrono::Date& t_copyrightdate, Genre g);
			
			void setISBN(int v[]);
			void settitle(std::string str);
			void setauthor(std::string str);
			void setcopyrightdate(const Chrono::Date &d);
			void setgenre(Genre g);
			
			// Returning values:
			std::string getISBN() const;
			std::string gettitle() const;
			std::string getauthor() const;
			Chrono::Date getcopyrightdate() const;
			Genre getgenre() const;
			std::string printgenre() const;

		private:
			std::string ISBN, title, author;
			Chrono::Date copyrightdate;
			Genre gen;

	};

	class Patron {
		public:
			Patron();
		private:
	};

	class Library {
		public:
			Library();
		private:
	};

	bool operator==(const Book &a, const Book &b);
	bool operator!=(const Book &a, const Book &b);
	std::ostream& operator<<(std::ostream& os, const Book& b);
}

#endif // BOOK_HPP

#include "../include/book.hpp"

namespace Library {

	Book::Book() = default;

	Book::Book(std::string& t_ISBN, std::string& t_title, std::string& t_author, const Chrono::Date& t_copyrightdate, Genre g)
			: ISBN{t_ISBN}, title{t_title}, author{t_author}, copyrightdate{t_copyrightdate}, gen{g}
	{	
	}
	
	void Book::setISBN(int v[]){
		ISBN = std::to_string(v[0]) + "-" + std::to_string(v[1]) + "-" + std::to_string(v[2]) + "-" + std::to_string(v[3]);
	}
	
	void Book::settitle(std::string str){
		title = str;
	}
	
	void Book::setauthor(std::string str){
		author = str;
	}
	
	void Book::setcopyrightdate(const Chrono::Date &d){
		copyrightdate = d;
	}

	void Book::setgenre(Genre g){
		gen = g; 
	}
	
	// Returning values:
	std::string Book::getISBN() const {
		return ISBN;
	}

	std::string Book::gettitle() const {
		return title;
	}

	std::string Book::getauthor() const {
		return author;
	}

	Chrono::Date Book::getcopyrightdate() const {
		return copyrightdate;
	}

	Genre Book::getgenre() const {
		return gen;
	}

	std::string Book::printgenre() const {
		switch (static_cast<int>(gen)) {
			case 1:
				return "Children";
			case 2:
				return "Fiction";
			case 3:
				return "Nonfiction";
			case 4:
				return "Periodical";
			case 5:
				return "Biography";
			default:
				return "-";
		} 
	}
	
	bool operator==(const Book &a, const Book &b){
		return a.getISBN() == b.getISBN()
			&& a.gettitle() == b.gettitle()
			&& a.getauthor() == b.getauthor()
			&& a.getcopyrightdate() == b.getcopyrightdate()
			&& a.getgenre() == a.getgenre();
	}

	bool operator!=(const Book &a, const Book &b){
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Book& a){
		os 	<< "Book title:\t\t" << a.gettitle() << "\n"
			<< "Author:\t\t\t" << a.getauthor() << "\n"
			<< "Genre:\t\t\t" << a.printgenre() << "\n"
			<< "Copyright date:\t\t" << a.getcopyrightdate() << "\n"
			<< "ISBN\t\t\t" << a.getISBN() << "\n";
		return os;
	}

} // namespace library
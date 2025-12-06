#include "../include/Chrono.hpp"

namespace Chrono {

	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: y{yy}, m{mm}, d{dd}
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{2001, Month::jan, 1}; // start of 21st century
		return dd;
	}

	Date::Date()
		: y{default_date().year()},
		  m{default_date().month()},
		  d{default_date().day()}
	{
	}

	void Date::add_day(int n)
	{
		// Simplified implementation for demonstration purposes
		d += n;
		if (d > 31) {
			d -= 31;
			add_month(1);
		}
	}

	void Date::add_month(int n)
	{
		// Simplified implementation for demonstration purposes
		int new_month = static_cast<int>(m) + n;
		y += (new_month - 1) / 12;
		m = static_cast<Month>((new_month - 1) % 12 + 1);
	}

	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n)) { // beware of leap years!
			m = Month::mar; // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}

	// helper functions:

	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid

		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month = 31; // most months have 31 days

		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}

		if (days_in_month < d) return false;

		return true;
	}

	bool leapyear(int y)
	{
		// A year is a leap year if it is divisible by 4 but not by 100, except when it is divisible by 400.
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
				  << ',' << static_cast<int>(d.month())
				  << ',' << d.day() << ')';
	}

	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(std::ios_base::failbit); // set the fail bit
			return is;
		}

		dd = Date(y, Month(m), d); // update dd

		return is;
	}

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	Day day_of_week(const Date& d)
	{
		// Placeholder implementation
		return Day::sunday;
	}

	Date next_Sunday(const Date& d)
	{
		// Placeholder implementation
		return d;
	}

	Date next_weekday(const Date& d)
	{
		// Placeholder implementation
		return d;
	}

} // Chrono

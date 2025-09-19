#include "screen.hpp"

class Screen {

public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	char get() const
		{ return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr; // may change even in a const object
};

inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

void Screen::some_member() const
{
	++access_ctr;	// keep a count of the calls to any member function
	// whatever other work this member needs to do
}

class Window_mgr
{
private:
	// Screens this Window_mgr is tracking
	// by default, a Window_mgr has one standard sized blank Screen
	std::vector<Screen> screens{Screen(24, 80, ’ ’)};
};

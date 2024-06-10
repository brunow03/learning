#ifndef SCREEN_HPP
#define SCREEN_HPP

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
	mutable size_t access_ctr;

};

class Window_mgr
{
private:
	// Screens this Window_mgr is tracking
	// by default, a Window_mgr has one standard sized blank Screen
	std::vector<Screen> screens{Screen(24, 80, ’ ’)};
};

#endif // SCREEN_HPP

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Screen{
friend class Window_mgr;
public:
    using pos = string::size_type;
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd),contents(ht*wd, ' '){}
    Screen(pos ht, pos wd, char c):height(ht),
                width(wd),contents(ht*wd, c){ }
    char get() const{ return contents[cursor]; }            // *this is const
    const Screen display(ostream& os)const{
        do_display(os);
        return *this;
    }
    Screen  &display(ostream& os){
        do_display(os);
        return *this;
    }
private:
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;
    void do_display(ostream& os)const{ os << contents;}

};

inline Screen &Screen::move(pos r, pos col){
    cursor = r*width + col;
    return *this;
}

inline Screen &Screen::set(char ch){
    contents[cursor] = ch;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width+col] = ch;
    return *this;
}

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24,80,' ')};
};

void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.contents = string(s.height*s.width, ' ');
}

int main(){
    Screen myscreen(5,5,'X');
    myscreen.move(4,0).set('#').display(cout);
    cout << endl;
    myscreen.display(cout);
    cout << endl;
    // Screen sc(3,4, '*');
    //const Screen blank(5,5);
    // cout << sc.get() << endl;
    // sc.move(4,0).set('+');
    // cout << sc.get() << endl;
    // sc.display(cout).set(2,2,'+').display(cout);
    // blank.display(cout);
    return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>

using namespace std;

class BestSeller
{
    public:
        BestSeller();
        BestSeller(int y, string w, int r, int tID, string t, string a);
        BestSeller(const BestSeller &copy);
        ~BestSeller();
        void print() const;
        void readUserInput();
        void setYear(int y);
        void setWeek(string w);
        void setRank(int r);
        void setTitleID(int tID);
        void setTitle(string t);
        void setAuthor(string a);
        int getYear();
        string getWeek();
        int getRank();
        int getTitleID();
        string getTitle();
        string getAuthor();
        
    private:
        int year;
        string week;
        int rank;
        int titleID;
        string title;
        string author;
        
};
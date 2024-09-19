#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>
#include "bestseller.h"

using namespace std;

BestSeller::BestSeller()
{
    year = 0;
    week = "";
    rank = 0;
    titleID = 0;
    title = "";
    author = "";
}

BestSeller::BestSeller(int y, string w, int r, int tID, string t, string a)
{
    year = y;
    week = w;
    rank = r;
    titleID = tID;
    title = t;
    author = a;
}

BestSeller::BestSeller(const BestSeller &copy)
{
    year = copy.year;
    week = copy.week;
    rank = copy.rank;
    titleID = copy.titleID;
    title = copy.title;
    author = copy.author;
}

BestSeller::~BestSeller()
{
}

void BestSeller::readUserInput()
{
    cin >> year;
    cin >> week;
    cin >> rank;
    cin >> titleID;
    getline(cin, title);
    getline(cin, author);
}

void BestSeller::print() const
{
    cout << year << " "
        << week << " "
        << rank << " "
        << titleID << " "
        << title << " "
        << author << endl;
}

void BestSeller::setYear(int y)
{
    year = y;
}

void BestSeller::setWeek(string w)
{
    week = w;
}

void BestSeller::setRank(int r)
{
    rank = r;
}

void BestSeller::setTitleID(int tID)
{
    titleID = tID;
}

void BestSeller::setTitle(string t)
{
    title = t;
}

void BestSeller::setAuthor(string a)
{
    author = a;
}

int BestSeller::getYear()
{
    return year;
}

string BestSeller::getWeek()
{
    return week;
}

int BestSeller::getRank()
{
    return rank;
}

int BestSeller::getTitleID()
{
    return titleID;
}

string BestSeller::getTitle()
{
    return title;
}

string BestSeller::getAuthor()
{
    return author;
}

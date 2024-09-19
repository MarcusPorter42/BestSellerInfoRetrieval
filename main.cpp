//Marcus Porter 011001959
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>
#include "bestseller.h"

using namespace std;

string to_upper(const string str) {
    string upper = "";
    string modstring = "";
   for (unsigned int i = 0; i < str.length(); i++) {
       if(isdigit(str[i]) == true) {
           modstring += str[i];
       }
       else if (isdigit(str[i]) == false) {
           upper = toupper(str[i]);
           modstring += upper;
       }
   }
   return modstring;
}

void read_file(vector<BestSeller>& nyt)
    {
        int tempYear;
        string tempWeek;
        int tempRank;
        int tempTitleID;
        string tempTitle;
        string tempAuthor;
        string whiteSpace;
        string header;
        
        BestSeller list;
    
        //Initialize file
        ifstream infile;
  
        //Open file
        infile.open ("nyt_best_sellers.tsv");
    
        if (infile.fail ())
	    {
	       cout << "Error reading the file" << endl;
	    }

        getline(infile, header);
	    
        while(!(infile.eof()))
	    {
	       infile >> tempYear;
	       infile >> tempWeek;
	       infile >> tempRank;
	       infile >> tempTitleID;
	       getline(infile, whiteSpace, '\t');
	       getline(infile, tempTitle, '\t');
	       getline(infile, tempAuthor);
	       list.setYear(tempYear);
	       list.setWeek(tempWeek);
	       list.setRank(tempRank);
	       list.setTitleID(tempTitleID);
	       list.setTitle(tempTitle);
	       list.setAuthor(tempAuthor);
	       
	  
	       nyt.push_back(list);
	    }
    
        //Close file
        infile.close ();
    }
    
void find_title(vector<BestSeller>& nyt, string titleSearch)
{
    for(unsigned int i = 0; i < nyt.size(); i++) {
        if(nyt[i].getTitle() == to_upper(titleSearch)) {
            nyt[i].print();
        }
    }
}

void find_author(vector<BestSeller>& nyt, string authorSearch)
{
    for(unsigned int i = 0; i < nyt.size(); i++) {
        if(nyt[i].getAuthor() == authorSearch) {
            nyt[i].print();
        }
    }
}

void find_week(vector<BestSeller>& nyt, string weekSearchLB, string weekSearchUB)
{
    for(unsigned int i = 0; i < nyt.size(); i++) {
        if((nyt[i].getWeek() < weekSearchUB) && (nyt[i].getWeek() > weekSearchLB)) {
            nyt[i].print();
        }
    }
}

int main()
{
  cout << "Marcus Porter\nStudent ID: 011001959\n" << endl;

  //Initializations
  vector<BestSeller> nyt;
  
  

  read_file(nyt);
  
  cout << "Searching for title: MARAUDER" << endl;
  find_title(nyt, "mArauDer");
  cout << endl;

  cout << "Searching for author: John Galsworthy" << endl;
  find_author(nyt, "John Galsworthy");
  cout << endl;
  
  cout << "Searching between weeks: 1931-11-16 and 1932-01-25" << endl;
  find_week(nyt, "1931-11-16", "1932-01-25");
  cout << endl;
  
  

    return 0;
}
/*Name       :Lab2.cpp
*Author      :Lauri Burke
*Description :Working with streams and command line arguments
*/

#include <iostream>
/*
* Name          :Lab2.cpp
* Author        :Lauri Burke
* Description   :Working with streams and command line arguments
*/
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

// Program begins, includes argc and argv to pass in command-line arguments
int main(int argc, char *argv[]) {
  string nextline;
  ifstream fin;
  ofstream fout;
  string output;
  char single;
  string str_variable= "";

  // This loop will get a line from the user and then return same line out
  // until the end of the file, then close file.
  if (argc == 1) {
    do {
      getline(cin, nextline);
      cout << nextline << endl;
    } while (!cin.eof());

  // This loop checks to see if the file opens, returns error message if not.
  } else if (argc > 1) {
      for (int i = 1; i < argc; i++) {
        fin.open(argv[i]);
        if (fin.fail()) {
          cout << "Filename not valid" << endl;
          return 1;
        }
        fin.close();
      }

      // This loop opens a files, std::out whatever is in it, until the end of
      // the file, then closes file, and opens the next file, repeat until
      // there are no more arguments.
      for (int i = 1; i < argc; i++) {
        fin.open(argv[i]);
        fin.get(single);
        while (!fin.eof()) {
          cout << single;
          fin.get(single);
        }
        fin.close();
      }
    }
  return 0;
}

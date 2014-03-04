
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;
inline void eatline() { while(cin.get() != '\n') continue; }
int main()
{
   #if 0
   //////////////////////////////////////////////////////////
   /// Read data in text format
   // get name to file
   string filename;
   cout << "Enter the filename: ";
   cin >> filename;

   // create string and read information to this string
   cin.clear();
   eatline();
   cout << "Enter the information: ";
   string information;
   getline(cin, information);

   //std::cout << "filename: " << filename << endl;
   //std::cout << "information: " << information << endl;

   // create file and write information to it
   ofstream fileTxt(filename.c_str(), ios_base::out | ios_base::app);
   fileTxt << information << "\n";
   fileTxt.close();

   // read from file to console:
   ifstream fileTxtOut;
   fileTxtOut.open(filename.c_str(), ios_base::in);
   if(fileTxtOut.is_open()) {
      cout << "information of the file: " << filename << endl;
      char ch;
      while(fileTxtOut.get(ch)) cout << ch;
      cout << endl << "Done!" << endl;
      fileTxtOut.close();
   }
   #endif
   //////////////////////////////////////////////////////////
   /// Read data as binary
   // creating name of files
   std::string filename2 = "data2.dat";
   std::string filename3 = "data3.dat";
   // creating data
   cout << "Enter the information: ";
   string information;
   getline(cin, information);
   string informationCopied;
   // read data to file2
   try {
      ofstream fileOut(filename2.c_str(),
                       ios_base::out |/* ios_base::app | */ios_base::binary);
      fileOut.write((char*) &information, sizeof information);
      fileOut.close();
   }
   catch(std::exception &ex) { std::cerr << ex.what(); }


   // read from file2 and write into file 3, than read data from file 3 to
   // string.
   try {
      char ch;
      ofstream fileOut;
      fileOut.open(filename3.c_str(), ios_base::out | ios_base::binary);
      ifstream fileIn;
      fileIn.open(filename2.c_str(), ios_base::in | ios_base::binary);
      if(fileOut.is_open() && fileIn.is_open()) {
         while(fileIn.get(ch)) {
            fileOut << ch;
         }
         fileOut.close();
         fileIn.close();
      }
      // copy data from file3 to new string
      fileIn.open(filename3.c_str(), ios_base::in | ios_base::binary);
      if(fileIn.is_open()) {
         fileIn.read((char*) &informationCopied, sizeof information);
         fileIn.close();
      }
   }
   catch(std::exception &ex) { std::cerr << ex.what(); }
   // check on console new information from string
   std::cout << "your data: " << informationCopied;

   return 0;
}


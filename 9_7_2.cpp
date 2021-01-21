#include <iostream>
#include <fstream>
using namespace std;

int readFromFile(string numFile);
int writeToFile(string outputFile, string num);

int readFromFile(string numFile) {
  ifstream inFS;
  int fileNum;

   cout << "Opening file..." << endl;

   inFS.open("numFile.txt");
   if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1; // 1 indicates error
   }

   cout << "The even numbers from the files" << endl;
   inFS >> fileNum;
   while (!inFS.fail()) {
     cout << "num: "<< fileNum << endl;

     if(fileNum % 2==0){
       writeToFile("evenNumFile.txt", to_string(fileNum));
     }
     inFS >> fileNum;
   }

     if (!inFS.eof()){
       cout << "Error: didn't reach end of file" << endl;
       return 1;
     }
     cout << "Closing file numFile.txt." << endl;
     inFS.close();
   }



    int writeToFile(string outputFile, string num){
      ofstream outFS; // Output file stream
      outFS.open(outputFile, ios_base::app);


      cout << "Opening evenNumFile.txt" << endl;

      if (!outFS.is_open()) {
         cout << "Could not open file evenNumFile." << outputFile << endl;
         return 1;
      }

      // Write to file
      cout << "Writing to " << outputFile << endl;
      outFS << num << endl;


      // Done with file, so close
      outFS.close();

      cout << "File done writing" << endl;}

  int main(int argc, char** argv){
    readFromFile("numFile.txt");

    return 0;
  }
     // Open file

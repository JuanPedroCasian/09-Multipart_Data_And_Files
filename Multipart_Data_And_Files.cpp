/*
Multipart_Data_And_Files.cpp
Sep 19, 2017
Juan Casian
*/

#include <iostream>
#include <fstream>

using namespace std;

struct FileData {
  int NumberOfLines, NumberOfCharacters;
};

 string GetDocName () {   /*Simple program that captures the input of the user
                            into a string and tests if the input works to find a
``                          Program.
                          */
    string DocName;
   cout << "Please insert the name of the document you want to analyze: " << endl;

   cin >> DocName;

   ifstream TestFile (DocName);

   if (TestFile.good() == false) {
     cout << "Unable to open: " << DocName << endl;
     cout << "Please try again" << endl;
     DocName = GetDocName();
   }

     return DocName;

 }

 string GetDocData (string DocName, FileData& DataSet1){   
                                          /*
                                          In this program you take the data in the file and
                                          inputs it in a string so we can analyze it

                                          Also we add a counter to each time a new line is read
                                          to find the number of lines
                                          */

   string DocData, DataLine;
   ifstream TestFile (DocName);

   while (TestFile.good() == true){
     getline(TestFile, DataLine);
     DocData = DocData + DataLine + "\n";
     DataSet1.NumberOfLines +=1;
     if(TestFile.eof() == true) {
       break;
     }
   }
   return DocData;
 }

 void AnalyzeDataSet (string DocData, FileData& DataSet1) {     /*In this function I used referenced variables which
                                                                  is done by putting & after the variable type in the
                                                                  function variables.
                                                                  Referencing a variable is used to change the value
                                                                  of the original variable inside the functions.
                                                                */

                                              // Simple program to count the characters in the data acquired from the file
   DataSet1.NumberOfCharacters = DocData.size();
 }

int main (){

  string DocName = "", DocData = "";
  FileData DataSet1;

  DocName = GetDocName ();

  DocData = GetDocData (DocName, DataSet1);

  AnalyzeDataSet (DocData, DataSet1);

  cout << "The Document analyzed is called: " << DocName << "." << endl;
  cout << "The number of lines is: " << DataSet1.NumberOfLines << "." << endl;
  cout << "The number of characters is: " << DataSet1.NumberOfCharacters << "." << endl;

  cout << "The document text is: " <<endl;
  cout << DocData << endl;

  return 0;
}


/*                      Practice program
int main(){
  string Filename = "TestFile.txt";
  string Prueba;
  string todo = "";

  ifstream TestFile (Filename);          If stream creates a objecy either to input or output data to a file
                                                  two examples of streams we have used are: cin and cout.
                                                  This command is used like this:
                                                  ifstream NameYouWantToAssingToTheObject ("NameOfTheFileWhereToGetOrGiveData");


  if (TestFile.good() == false) {          Here we use the function .good() to know if the file is able to be reached or not
    cout << "Unable to open the file named: " << Filename << endl;
    exit (1);  exit() is a way to end the program from anywhere. When this code is reached it ends the program and returns the value in parenthesis
                1 = error during program
                0 = no problem in the whole program

  }



while (TestFile.good() == true) {      This while is when the file can be read
//  cout << "prueba1" << endl;
  getline (TestFile, Prueba);           All this code is to get the whole file in a string
  todo = todo + Prueba ;                This adds the previous data with the new line
  todo = todo + "\n";         Here we add a new line, so that the Text is in the same format as the document reached
                              /n  is the equivalent of endl

  if (TestFile.eof()) break;            NameOfStream.eof() is a function so see if the document got to the end.
}

  cout << todo << endl;

  return 0;
}
*/

// TestFile >> Prueba; With this comand you only get the first thing in the while until a space   Ex: File
/* getline (TestFile, Prueba); With this function you get the whole first line
* This fucntion is used:
* getline (CommandFromWhereToGetIt, VariableInWhichItWillBeStored);
*/

// random access files

/*
* sırayla okumak yerine radgele karakterlere atlayarak okuma yapılabilir.
* kullanılan fonksiyonlar - örnekler

    inf.seekg(14, ios::cur); // move forward 14 bytes
    inf.seekg(-18, ios::cur); // move backwards 18 bytes
    inf.seekg(22, ios::beg); // move to 22nd byte in file
    inf.seekg(24); // move to 24th byte in file
    inf.seekg(-28, ios::end); // move to the 28th byte before end of the file

Moving to the beginning or end of the file is easy:

    inf.seekg(0, ios::beg); // move to beginning of file
    inf.seekg(0, ios::end); // move to end of file

    ios::beg  -> dosya başlangıcı    
    ios::end  -> dosya sonu    
    ios::cur  -> dosyada o anda bulunulan konum   

    seekg(),  -> g for "get", okurken
    seekp()   -> p for "put", yazarken
    tellp()   -> curser ın o anda bulunduğu yeri söyler
    tellg()   -> okurken g, yazarken p kullanılır

*/
#include <iostream>
#include <fstream>
using namespace std;

//----------------------------------------------------------------
int main()
{
    using namespace std;
 
    ifstream inf("Sample.dat");
 
    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }
 
    string strData;
 
    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
 
    inf.seekg(8, ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
 
    inf.seekg(-15, ios::end); // move 15 bytes before end of file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
    
	return 0;
}
//----------------------------------------------------------------

/*
Two other useful functions are tellg() and tellp(), which return the absolute position of the file pointer. This can be used to determine the size of a file:

ifstream inf("Sample.dat");
inf.seekg(0, ios::end); // move to end of file
cout << inf.tellg();

*/

//------------------------------------------------------------------------
/*
int main()
{
    using namespace std;
 
	// Note we have to specify both in and out because we're using fstream
    fstream iofile("Sample.dat", ios::in | ios::out);
 
    // If we couldn't open iofile, print an error
    if (!iofile)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened!" << endl;
        exit(1);
    }
 
    char chChar; // we're going to do this character by character
 
    // While there's still data to process
    while (iofile.get(chChar))
    {
        switch (chChar)
        {
            // If we find a vowel
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
 
                // Back up one character
                iofile.seekg(-1, ios::cur);
 
                // Because we did a seek, we can now safely do a write, so
                // let's write a # over the vowel
                iofile << '#';
 
                // Now we want to go back to read mode so the next call
                // to get() will perform correctly.  We'll seekg() to the current
                // location because we don't want to move the file pointer.
                iofile.seekg(iofile.tellg(), ios::beg);
 
                break;
        }
    }
 
    return 0;
}
*/
//-----------------------------------------------------------------------

/*
// reading an entire binary file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  streampos size;
  char * memblock;

  ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory";

    delete[] memblock;
  }
  else cout << "Unable to open file";
  return 0;
}
*/

//------------------------------
/*
#include <fstream.h>
    ...
    char buffer[100];
    ofstream myFile ("data.bin", ios::out | ios::binary);
    myFile.write (buffer, 100);

*/
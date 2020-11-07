#include<iostream>
#include<io.h>
#include<fstream>

using namespace std;

string conv(char ch)
{
    switch (ch)
    {
    case '\t':
        return "\\t";
        break;
    case '\r':
        return "\\r";
        break;
    case '\n':
        return "\\n";
        break;
    case '\\':
        return "\\\\";
        break;
    case '\'':
        return "\\\'";
        break;
    case '\"':
        return "\\\"";
        break;
    case '\?':
        return "\\\?";
        break;
    default:
        break;
    }
    string ret{ ch };
    return ret;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Usage: EscapeCharacterConverter.exe [your text file name]" << endl;
        return 0;
    }
    if (_access(argv[1], 0) != 0)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    string outfile{ "output_" }; // output file name
    outfile += argv[1];

    if (_access(outfile.c_str(), 0) == 0)
    {
        cout << outfile<<" already exists!" << endl;
        return 0;
    }
    cout << "Converting..." << endl;

    ifstream fin(argv[1]); // input stream
    ofstream fout(outfile); // output stream
    char ch; //read a char
    
    while (fin.get(ch))
        fout << conv(ch);

    fout.close();
    fin.close();
    cout << "Done!";

    return 0;
}
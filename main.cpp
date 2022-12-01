#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Given a filename, will open the file and return the number of lines it has.
int get_number_of_lines(string filename) {
    fstream file(filename);

    if (file.is_open()) {
        string line;
        int line_count = 0;
        while (!file.eof()) {
            getline(file, line);
            line_count++;
        }
        return line_count;
    }

    else {
        std::cout << "Could not read given file." << endl;
        return -1;
    }
}

// Given a filename, will open the file and read it into a vector of strings.
// This allows for easier access to lines by index.
// Returns the vector of strings.
std::vector<string> read_file_to_array(string filename) {
    fstream file(filename);
    std::vector<string> file_text;
    if (file.is_open()) {
        int limit = get_number_of_lines(filename);    
        for (int i = 0; i < limit; i++) {
            string line_text;
            getline(file, line_text);
            file_text.push_back(line_text);
        }
    }
    else {
        std::cout << "Error reading file into vector." << endl;
    }
    return file_text;
}

// Given a string, and a character, will remove all instances of the character
// from the string.
std::string strip(string origin, char unwanted) {
    std::string result;
    result.reserve(origin.size()); // optional, avoids buffer reallocations in the loop
    for(size_t i = 0; i < origin.size(); ++i)
        if(origin[i] != unwanted) result += origin[i];
    return result;
}

// Implimentation of Python's .lower() function for strings.
// Ensures all characters are lower case.
void lowerCase(string& origin)
{
   for(unsigned int i=0;i<origin.length();i++)
   {
      origin[i] = tolower(origin[i]);
   }
}

// Hosts the gameplay loop and accepts / processes input from user.
int main() {
    char filename[256];
    // Prompt the user for the filename.
    std::cout << "Please enter the filename to read: ";
    cin >> filename;
    // Open the specified file.
    fstream file(filename);
    //Checks for any initial errors in the file.
    if (file.fail())
    {
       std::cout << "Error reading file \"" << filename << "\"" << endl;
       return -1;
    }

    if (file.is_open()) {
        bool output_to_console = true;
        int i = 0;
        std::vector<string> story = read_file_to_array(filename);
        string user_choice;
        int line_limit = get_number_of_lines(filename);

        for (int i = 0; i < line_limit; i++) {
            string line = story[i];

            if (line[0] == '*') {
                // Checks for user prompts, accept input from user.
                std::cout << "!!-------------------------------------------!!" << endl;
                std::cout << strip(line, '*') << " ";
                cin >> user_choice;
                std::cout << "!!-------------------------------------------!!" << endl;
                lowerCase(user_choice);
            }
            else if (line[0] == '#') {
                // Checks for option branches.
                string stripped_line = strip(strip(strip(line, '#'), ' '), '\n');
                if ( stripped_line== user_choice or stripped_line == "!")
                    output_to_console = true;
                else if (output_to_console)
                    output_to_console = false;
            }
            // Checks if lines should be output to the console,
            // or if they should stay hidden.
            // (Allows for skipping and line-jumps)
            else if (output_to_console) {
                if (line[0] == '@') {
                    i = stoi(strip(line, '@'));
                    output_to_console = true;
                }
                else std::cout << line << endl;
            }
        }
        file.close();
        std::cout << "Thanks for playing!" << endl;
    }
    return 0;
}
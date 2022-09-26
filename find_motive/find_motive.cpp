#include <fstream>
#include "find_motive.h"

int find_motive(std::string input_file_path, std::string input_motive)
{
    std::ifstream fin;
    std::string word;

    fin.open(input_file_path.c_str());

    if (fin.fail())
    {
        std::cout << "The file " << input_file_path << " could not be opened." << std::endl;
        return 1;
    }

    int motive_count = 0;
    while (fin >> word)
    {
        if (word.find(input_motive) != std::string::npos)
            motive_count++;
    }
    fin.close();

    std::cout << "The file " + input_file_path + " contains " << motive_count
              << " words containing the motive " + input_motive << std::endl;
    return 0;
}
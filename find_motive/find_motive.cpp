#include <fstream>
#include "find_motive.h"

/**
 * Count occurence of a motive in a given file.
 *
 * @param input_file_path Path of file in which motive should be searched.
 * @param input_motive Motive to be used.
 * @return 1 in case of error when opening file else 0.
 */
int find_motive(std::string input_file_path, std::string input_motive)
{
    std::ifstream file;
    std::string word;

    // Attempt to open file.
    file.open(input_file_path.c_str());

    if (file.fail())
    {
        std::cout << "The file " << input_file_path << " could not be opened."
            << std::endl;
        return 1;
    }

    // Count motive occurrence in given file.
    int motive_count = 0;
    while (file >> word)
    {
        if (word.find(input_motive) != std::string::npos)
            motive_count++;
    }
    file.close();

    std::cout << "The file " + input_file_path + " contains " << motive_count
              << " words containing the motive " + input_motive << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

namespace csv_reader_spc
{
    std::vector<std::unordered_map<std::string, std::string>> convert_csv_to_object(std::string file_Path)
    {
        std::fstream fin; 
        fin.open(file_Path, std::ios::in);
        
        std::vector<std::unordered_map<std::string, std::string>> csv_data; 
        std::string line, word;
        std::vector<std::string> header; 
        int row_iterator = 0;
        
        while (getline(fin, line)) 
        {   
            std::stringstream s(line);
            std::unordered_map<std::string, std::string> csv_column_data;

            if(row_iterator < 1)
            {
                while (getline(s, word, ',')) 
                {
                    header.push_back(word);
                }
            } 

            if(row_iterator > 0)
            {
                int column_iterator = 0;
                
                while (getline(s, word, ',')) 
                {
                    csv_column_data[header.at(column_iterator)] = word;
                    column_iterator++;
                }

                csv_data.push_back(csv_column_data);
            }

            row_iterator++;
        }

        return csv_data;
    }
}
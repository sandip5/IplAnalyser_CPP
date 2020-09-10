#include <iostream>
#include "../utility/csv_reader.h"
#include "ipl_run.h"

template<typename T>
class ipl_analyser
{
    std::string file_path = "../resources/MostRuns.csv";
    std::vector<std::unordered_map<std::string, std::string>> csv_data;
    std::vector<ipl_run<T>> player_records;

public:
    ipl_analyser()
    {
        this -> csv_data = csv_reader_spc::convert_csv_to_object(file_path);
    }

    void update_player_record()
    {
        for(std::unordered_map<std::string, std::string> itr : csv_data)
        {
            ipl_run<T> most_runs(itr.at("PLAYER"));
            most_runs.set_match() = std::stoi(itr.at("Mat"));
            most_runs.set_innings() = std::stoi(itr.at("Inns"));
            most_runs.set_run() = std::stoi(itr.at("Runs"));
            most_runs.set_high_score() = itr.at("HS");
            most_runs.set_average() = std::stod(itr.at("Avg"));
            most_runs.set_fifty() = std::stoi(itr.at("50"));
            most_runs.set_fours() = std::stoi(itr.at("4s"));
            most_runs.set_hundered() = std::stoi(itr.at("100"));
            most_runs.set_six() = std::stoi(itr.at("6s"));
            most_runs.set_strike_rate() = std::stod(itr.at("SR"));
            player_records.push_back(most_runs);
        }
    }

    ipl_run<T> find_data(std::string fields)
    {
        sort_data(fields);
        return player_records[0];
    }

    void sort_data(std::string fields)
    {
        std::unordered_map<std::string, T> temp;

        for (int iteration = 0; iteration < player_records.size(); iteration++)
        {
            int flag = 0;
            for (int player_index = 0; player_index < player_records.size() - 1 - iteration; player_index++)
            {
                if (player_records[player_index].get_player_mapped_details().at(fields) <
                    player_records[player_index + 1].get_player_mapped_details().at(fields))
                {
                    temp = player_records[player_index];
                    player_records[player_index] = player_records[player_index + 1];
                    player_records[player_index + 1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }   
    }
};


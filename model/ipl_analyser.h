#include <iostream>
#include "../utility/csv_reader.h"
#include "ipl_run.h"
#include <algorithm>

class ipl_analyser
{
    std::string file_path = "../resources/MostRuns.csv";
    std::vector<std::unordered_map<std::string, std::string>> csv_data;
    std::vector<ipl_run> player_records;

public:
    ipl_analyser()
    {
        this -> csv_data = csv_reader_spc::convert_csv_to_object(file_path);
        update_player_record();
    }

    std::vector<ipl_run> get_player_record()
    {
        return player_records;
    }

    void update_player_record()
    {
        for(std::unordered_map<std::string, std::string> itr : csv_data)
        {
            ipl_run most_runs(itr.at("PLAYER"));
            most_runs.set_match(std::stoi(itr.at("Mat")));
            most_runs.set_innings(std::stoi(itr.at("Inns")));
            most_runs.set_run(std::stoi(itr.at("Runs")));
            most_runs.set_high_score(itr.at("HS"));
            most_runs.set_average(std::stod(itr.at("Avg")));
            most_runs.set_fifty(std::stoi(itr.at("50")));
            most_runs.set_fours(std::stoi(itr.at("4s")));
            most_runs.set_hundered(std::stoi(itr.at("100")));
            most_runs.set_six(std::stoi(itr.at("6s")));
            most_runs.set_strike_rate(std::stod(itr.at("SR")));
            player_records.push_back(most_runs);
        }
    }

    ipl_run find_top_batting_average()
    {
        std::sort(player_records.begin(), player_records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return (first_batsman.get_average() < second_batsman.get_average());
            }
        );
        
        return player_records[player_records.size() - 1];
    }
};


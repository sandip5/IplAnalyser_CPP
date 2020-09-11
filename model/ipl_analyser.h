#include <iostream>
#include "../utility/csv_reader.h"
#include "ipl_run.h"
#include "ipl_wkts.h"
#include <algorithm>

class ipl_analyser
{
    std::vector<std::unordered_map<std::string, std::string>> csv_data;
    std::vector<ipl_run> batsman_records;
    std::vector<ipl_wkts> bowler_records;

public:
    void load_ipl_csv_file(std::string file_path, int select)
    {
        enum choice
        {
            BATSMAN = 1,
            BOWLER
        };

        this -> csv_data = csv_reader_spc::convert_csv_to_object(file_path);

        if(choice::BATSMAN == select)
        {
            update_batsman_record();
        }

        if(choice::BOWLER == select)
        {
            update_bowler_record();
        }
        
    }

    void update_batsman_record()
    {
        for(std::unordered_map<std::string, std::string> itr : csv_data)
        {
            ipl_run most_runs(itr.at("PLAYER"));
            most_runs.set_run(std::stoi(itr.at("Runs")));
            most_runs.set_average(std::stod(itr.at("Avg")));
            most_runs.set_fifty(std::stoi(itr.at("50")));
            most_runs.set_fours(std::stoi(itr.at("4s")));
            most_runs.set_hundered(std::stoi(itr.at("100")));
            most_runs.set_six(std::stoi(itr.at("6s")));
            most_runs.set_strike_rate(std::stod(itr.at("SR")));
            batsman_records.push_back(most_runs);
        }
    }

    void update_bowler_record()
    {
        for(std::unordered_map<std::string, std::string> itr : csv_data)
        {
            ipl_wkts most_wkts(itr.at("PLAYER"));
            most_wkts.set_run(std::stoi(itr.at("Runs")));
            most_wkts.set_wickets(std::stoi(itr.at("Wkts")));
            most_wkts.set_average(std::stod(itr.at("Avg")));
            most_wkts.set_fours_wkts(std::stoi(itr.at("4w")));
            most_wkts.set_five_wkts(std::stoi(itr.at("5w")));
            most_wkts.set_strike_rate(std::stod(itr.at("SR")));
            most_wkts.set_economy_rate(std::stod(itr.at("Econ")));
            bowler_records.push_back(most_wkts);
        }
    }    

    ipl_run find_top_batting_average()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return (first_batsman.get_average() < second_batsman.get_average());
            }
        );
        
        return records[records.size() - 1];
    }

    ipl_run find_top_striking_rate()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return (first_batsman.get_strike_rate() < second_batsman.get_strike_rate());
            }
        );

        return records[records.size() - 1];
    }

    ipl_run find_max_sixs_and_fours()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_six() < second_batsman.get_six()) && 
                            (first_batsman.get_four() < second_batsman.get_four()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_run find_best_strike_rate_with_best_six_and_four()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_six() < second_batsman.get_six()) && 
                            (first_batsman.get_six() < second_batsman.get_six()) && 
                            (first_batsman.get_four() < second_batsman.get_four()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_run find_great_average_with_best_strike_rate()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_average() < second_batsman.get_average()) && 
                            (first_batsman.get_strike_rate() < second_batsman.get_strike_rate()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_run find_maximum_runs_with_best_average()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_run() < second_batsman.get_run()) && 
                            (first_batsman.get_average() < second_batsman.get_average()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_wkts find_top_bowling_average()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_average() < second_bowler.get_average()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_wkts find_top_strike_rate_of_bowler()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_strike_rate() < second_bowler.get_strike_rate()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_wkts find_best_economy_rate()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_economy_rate() < second_bowler.get_economy_rate()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_wkts find_best_strike_with_5w_4w()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_four_wkts() < second_bowler.get_five_wkts())
                            && (first_bowler.get_five_wkts() < second_bowler.get_five_wkts())
                            || (first_bowler.get_strike_rate() < second_bowler.get_strike_rate()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_wkts find_bowling_avg_with_strike_rate()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_average() < second_bowler.get_average())
                            && (first_bowler.get_strike_rate() < second_bowler.get_strike_rate()));
            }
        );

        return records[records.size() - 1];
    }
};


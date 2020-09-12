#include <iostream>
#include "../utility/csv_reader.h"
#include "ipl_run.h"
#include "ipl_wkts.h"
#include "ipl_all_rounder.h"
#include <algorithm>

class ipl_analyser
{
    std::vector<std::unordered_map<std::string, std::string>> csv_data;
    std::vector<ipl_run> batsman_records;
    std::vector<ipl_wkts> bowler_records;
    std::vector<ipl_all_rounder> all_rounder_records;

public:
    void load_ipl_csv_file(std::string batsman_file_path, std::string bowler_file_path)
    {
        this -> csv_data = csv_reader_spc::convert_csv_to_object(batsman_file_path);
        update_batsman_record();
        this -> csv_data = csv_reader_spc::convert_csv_to_object(bowler_file_path);
        update_bowler_record();
        update_all_rounder_record();
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

    void update_all_rounder_record()
    {
        for(ipl_run batsman_itr : batsman_records)
        {
            for (ipl_wkts bowler_itr : bowler_records)
            {
                if(batsman_itr.get_player_name() == bowler_itr.get_player_name())
                {
                    ipl_all_rounder all_rounder(batsman_itr.get_player_name());
                    all_rounder.set_batsman_run(batsman_itr.get_run());
                    all_rounder.set_bowler_run(bowler_itr.get_run());
                    all_rounder.set_bowler_wickets(bowler_itr.get_wickets());
                    all_rounder.set_batting_avg(batsman_itr.get_average());
                    all_rounder.set_bowling_avg(bowler_itr.get_average());
                    all_rounder_records.push_back(all_rounder);
                }
            }
        }
    }   

    ipl_run find_top_batting_average()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return (first_batsman.get_average() > second_batsman.get_average());
            }
        );
        
        return records.at(0);
    }

    ipl_run find_top_striking_rate()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return (first_batsman.get_strike_rate() > second_batsman.get_strike_rate());
            }
        );

        return records.at(0);
    }

    ipl_run find_max_sixs_and_fours()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_six() + first_batsman.get_four() > second_batsman.get_six()
                            + second_batsman.get_four()));
            }
        );

        return records.at(0);
    }

    ipl_run find_best_strike_rate_with_best_six_and_four()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_strike_rate() > second_batsman.get_strike_rate()) && 
                            (first_batsman.get_six() + first_batsman.get_four() > second_batsman.get_six()
                            + second_batsman.get_four()));
            }
        );

        return records.at(0);
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
                return ((first_batsman.get_run() > second_batsman.get_run()) && 
                            (first_batsman.get_average() > second_batsman.get_average()));
            }
        );

        return records.at(0);
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
                return ((first_bowler.get_strike_rate() > second_bowler.get_strike_rate()));
            }
        );

        return records[records.size() - 2];
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

    ipl_wkts find_max_wkts_with_best_bowling_average()
    {
        std::vector<ipl_wkts> records = bowler_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_wkts &first_bowler, ipl_wkts &second_bowler) -> bool
            {
                return ((first_bowler.get_wickets() < second_bowler.get_wickets())
                            && (first_bowler.get_average() < second_bowler.get_average()));
            }
        );

        return records[records.size() - 1];
    }

    ipl_all_rounder find_batting_and_bowling_avg()
    {
        std::vector<ipl_all_rounder> records = all_rounder_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_all_rounder &first_all_rounder, ipl_all_rounder &second_all_rounder) -> bool
            {
                return ((first_all_rounder.get_batting_avg() > second_all_rounder.get_batting_avg()) && 
                            (first_all_rounder.get_bowling_avg() > second_all_rounder.get_bowling_avg()));
            }
        );

        return records.at(0);
    }

    ipl_all_rounder find_cricketer_who_had_most_runs_wickets()
    {
        std::vector<ipl_all_rounder> records = all_rounder_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_all_rounder &first_all_rounder, ipl_all_rounder &second_all_rounder) -> bool
            {
                return ((first_all_rounder.get_batsman_run() > second_all_rounder.get_batsman_run()) && 
                            (first_all_rounder.get_bowler_wickets() > second_all_rounder.get_bowler_wickets()));
            }
        );

        return records.at(0);
    }

    ipl_run find_cricketer_who_had_most_hundered_with_best_average()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_hundered() > second_batsman.get_hundered()));
            }
        );

        return records.at(0);
    }

    ipl_run find_cricketer_who_had_zero_hundered_and_fifty_with_best_average()
    {
        std::vector<ipl_run> records = batsman_records;

        std::sort(records.begin(), records.end(),[] (
           ipl_run &first_batsman, ipl_run &second_batsman) -> bool
            {
                return ((first_batsman.get_hundered() < second_batsman.get_hundered())
                        && (first_batsman.get_fifty() < second_batsman.get_fifty())
                        && (first_batsman.get_average() > second_batsman.get_average()));
            }
        );
        std::cout << records.at(0).get_hundered() << " " << records.at(0).get_fifty() << std::endl;
        return records.at(0);
    }
};


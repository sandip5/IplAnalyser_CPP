#include <iostream>
#include  <stdlib.h>

class ipl_controller
{
    std::string file_path_batsman = "../resources/MostRuns.csv";
    std::string file_path_bowler = "../resources/MostWkts.csv";
    ipl_view view;
    ipl_analyser analyser;
    ipl_run batsman;
    ipl_wkts bowler;

public:
    ipl_controller(){}

    ipl_controller(ipl_view view, ipl_analyser analyser)
    {
        this -> view = view;
        this -> analyser = analyser;
    }

    void show_welcome_message()
    {
        std::cout << "Welcome To Ipl Analyser System" << std::endl;
    }

    void present_screen()
    {
        bool is_csv_file_loaded = false;
        int operation_for_batsman_or_bowler = 0;

        enum choose_file
        {
            BATSMAN_CSV_FILE = 1,
            BOWLER_CSV_FILE = 2
        };

        while (!is_csv_file_loaded)
        {
            std::cout << "\n1. Load Batsman CSV Data\n2. Load Bowler CSV Data\n" << std::endl;

            switch (view.take_input_as_choice())
            {
            case choose_file::BATSMAN_CSV_FILE:
            {
                analyser.load_ipl_csv_file(file_path_batsman, choose_file::BATSMAN_CSV_FILE);
                is_csv_file_loaded = true;
                operation_for_batsman_or_bowler = 1;
                break;
            } 
            case choose_file::BOWLER_CSV_FILE:
            {
                analyser.load_ipl_csv_file(file_path_bowler, choose_file::BOWLER_CSV_FILE);
                is_csv_file_loaded = true;
                operation_for_batsman_or_bowler = 2;
                break;
            }        
            default:
                std::cout << "CSV Files Are Not Uploaded. For Proceed Forward Enter Valid Input.."
                            << std::endl;
                break;
            }
        }

        enum operation
        {
            BATSMAN = 1,
            BOWLER
        };

        bool start = true;
        
        while (start)
        {
            switch (operation_for_batsman_or_bowler)
            {
            case operation::BATSMAN:
                do_operation_for_batsman();
                start = false;
                break;
            case operation::BOWLER:
                do_operation_for_bowler();
                start = false;
                break;  
            default:
                std::cout << "Some Issue..." << std::endl;
                break;
            }
        }
    }

    void do_operation_for_batsman()
    {
        enum choice
        {
            TOP_BATTING_AVG = 1,
            TOP_STRIKING_RATE,
            MAX_SIXS_AND_FOURS,
            STRIKE_RATE_SIX_FOUR,
            AVERAGE_AND_STRIKE_RATE,
            RUNS_WITH_AVERAGE,
            CLEAR_SCREEN,
            EXIT
        };

        bool start = true;

        while (start)
        {
            std::cout << "\n1. Find Top Batting Average\n2. Find Top Striking Rate\n3. Find Max 6(s) And 4(s)" 
                        << "\n4. Find Best Strike Rate With Best Six And Four\n5. Find Great Average With Best Strike"
                        << "\n6. Find Maximum Runs With Best Averages\n7. Clear Screen\n8. Exit\n" 
                        << std::endl;
            switch (view.take_input_as_choice())
            {
            case choice::TOP_BATTING_AVG:
                find_top_batting_average();
                break;
            case choice::TOP_STRIKING_RATE:
                find_top_striking_rate();
                break;
            case choice::MAX_SIXS_AND_FOURS:
                find_max_sixs_and_fours();
                break; 
            case choice::STRIKE_RATE_SIX_FOUR:
                find_best_strike_rate_with_best_six_and_four();
                break;
            case choice::AVERAGE_AND_STRIKE_RATE:
                find_great_average_with_best_strike_rate();
                break;
            case choice::RUNS_WITH_AVERAGE:
                find_maximum_runs_with_best_average();
                break;                   
            case choice::CLEAR_SCREEN:
                system("cls");
                break;
            case choice::EXIT:
                start = false; 
                break;       
            default:
                std::cout << "Enter Valid Choice..." << std::endl;
                break;
            } 
        }
    }

    void do_operation_for_bowler()
    {
        enum choice
        {
            TOP_BOWLING_AVG = 1,
            STRIKE_RATE,
            ECONOMY_RATE,
            STRIKE_RATE_5W_4W,
            BOWLING_AVG_STRIKE_RATE,
            MAX_WKTS_BOWLING_AVERAGE,
            CLEAR_SCREEN,
            EXIT
        };

        bool start = true;

        while (start)
        {
            std::cout << "\n1. Find Top Batting Average\n2. Find Top Strike Rate Of Bowler"
                        << "\n3. Find Best Economy Rate\n4. Find Best Strike Rate With 5W And 4W"
                        << "\n5. Find Great Balling Average With Best Strike Rate"
                        << "\n6. Find Maximum Wickets With Best Bowling Average"  
                        << "\n7. Clear Screen\n8. Exit\n" << std::endl;
        
            switch (view.take_input_as_choice())
            {
            case choice::TOP_BOWLING_AVG:
                find_top_bowling_average();
                break;
            case choice::STRIKE_RATE:
                find_top_strike_rate_of_bowler();
                break;
            case choice::ECONOMY_RATE:
                find_best_economy_rate();
                break;
            case choice::STRIKE_RATE_5W_4W:
                find_best_strike_with_5w_4w();
                break;    
            case choice::BOWLING_AVG_STRIKE_RATE:
                find_bowling_avg_with_strike_rate();
                break;
            case choice::MAX_WKTS_BOWLING_AVERAGE:
                find_max_wkts_with_best_bowling_average();
                break;                             
            case choice::CLEAR_SCREEN:
                system("cls");
                break;
            case choice::EXIT:
                start = false; 
                break;       
            default:
                std::cout << "Enter Valid Choice..." << std::endl;
                break;
            } 
        }   
    }

    void get_choice()
    {
        view.take_input_as_choice();
    }

    void find_top_batting_average()
    {
        this -> batsman = analyser.find_top_batting_average();
        display_top_batting_avg();
    }

    void find_top_striking_rate()
    {
       this -> batsman = analyser.find_top_striking_rate();
       display_top_strike_rate();
    }

    void find_max_sixs_and_fours()
    {
        this -> batsman = analyser.find_max_sixs_and_fours();
        display_max_six_and_four();
    }

    void find_best_strike_rate_with_best_six_and_four()
    {
        this -> batsman = analyser.find_best_strike_rate_with_best_six_and_four();
        display_best_strike_rate_with_best_six_and_four();
    }

    void find_great_average_with_best_strike_rate()
    {
        this -> batsman = analyser.find_great_average_with_best_strike_rate();
        display_great_average_with_best_strike_rate();
    }

    void find_maximum_runs_with_best_average()
    {
        this -> batsman = analyser.find_maximum_runs_with_best_average();
        display_maximum_runs_with_best_average();
    }

    void display_top_batting_avg()
    {
        view.display_top_avg_with_name(batsman.get_player_name(), batsman.get_average());
    }

    void display_top_strike_rate()
    {
        view.display_top_strike_rate_with_name(batsman.get_player_name(), batsman.get_strike_rate());
    }

    void display_max_six_and_four()
    {
        view.display_max_six_and_four_with_player_name(batsman.get_player_name(), batsman.get_six(),
                                                        batsman.get_four());
    }

    void display_best_strike_rate_with_best_six_and_four()
    {
        view.display_best_strike_rate_with_best_six_and_four_with_name(batsman.get_player_name(), 
                                batsman.get_strike_rate(), batsman.get_six(), batsman.get_four());
    }

    void display_great_average_with_best_strike_rate()
    {
        view.display_great_average_with_best_strike_rate_with_name(batsman.get_player_name(), 
                                            batsman.get_average(), batsman.get_strike_rate());
    }

    void display_maximum_runs_with_best_average()
    {
        view.display_maximum_runs_with_best_average_with_name(batsman.get_player_name(), 
                                            batsman.get_run(), batsman.get_average());
    } 

    void find_top_bowling_average()
    {
        this -> bowler = analyser.find_top_bowling_average();
        display_top_bowling_average();
    }

    void find_top_strike_rate_of_bowler()
    {
        this -> bowler = analyser.find_top_strike_rate_of_bowler();
        display_top_strike_rate_of_bowler();
    }

    void find_best_economy_rate()
    {
        this -> bowler = analyser.find_best_economy_rate();
        display_best_economy_rate();
    }

    void find_best_strike_with_5w_4w()
    {
        this -> bowler = analyser.find_best_strike_with_5w_4w();
        display_best_strike_with_5w_4w();
    }

    void find_bowling_avg_with_strike_rate()
    {
        this -> bowler = analyser.find_bowling_avg_with_strike_rate();
        display_bowling_avg_with_strike_rate();
    }

    void find_max_wkts_with_best_bowling_average()
    {
        this -> bowler = analyser.find_max_wkts_with_best_bowling_average();
        display_max_wkts_with_best_bowling_average();
    }

    void display_top_bowling_average()
    {
        view.display_top_avg_with_name(bowler.get_player_name(), bowler.get_average());
    }

    void display_top_strike_rate_of_bowler()
    {
        view.display_top_strike_rate_with_name(bowler.get_player_name(), bowler.get_strike_rate());
    }

    void display_best_economy_rate()
    {
        view.display_beat_economy_rate_with_name(bowler.get_player_name(), bowler.get_economy_rate());
    }

    void display_best_strike_with_5w_4w()
    {
        view.display_best_strike_rate_with_4w_and_5w_with_name(bowler.get_player_name(),
                                    bowler.get_strike_rate(), bowler.get_four_wkts(), bowler.get_five_wkts());
    }

    void display_bowling_avg_with_strike_rate()
    {
        view.display_great_average_with_best_strike_rate_with_name(bowler.get_player_name(),
                                                    bowler.get_average(), bowler.get_strike_rate());
    }

    void display_max_wkts_with_best_bowling_average()
    {
        view.display_max_wkts_with_best_bowling_average_with_name(bowler.get_player_name(), bowler.get_wickets(),
                                                                    bowler.get_average());
    }
};

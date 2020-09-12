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
    ipl_all_rounder all_rounder;

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
        analyser.load_ipl_csv_file(file_path_batsman, file_path_bowler);

        enum choice
        {
            TOP_BATTING_AVG = 1,
            TOP_STRIKING_RATE,
            MAX_SIXS_AND_FOURS,
            STRIKE_RATE_SIX_FOUR,
            AVERAGE_AND_STRIKE_RATE,
            RUNS_WITH_AVERAGE,
            TOP_BOWLING_AVG,
            STRIKE_RATE,
            ECONOMY_RATE,
            STRIKE_RATE_5W_4W,
            BOWLING_AVG_STRIKE_RATE,
            MAX_WKTS_BOWLING_AVERAGE,
            ALL_ROUNDER_BAT_BALL_AVG,
            MOST_RUN_AND_WICKETS,
            MAX_100_AVG,
            CLEAR_SCREEN,
            EXIT
        };

        bool start = true;

        while (start)
        {
            std::cout << "\n1. Find Top Batting Average\n2. Find Top Striking Rate\n3. Find Max 6(s) And 4(s)" 
                        << "\n4. Find Best Strike Rate With Best Six And Four\n5. Find Great Average With Best Strike"
                        << "\n6. Find Maximum Runs With Best Averages"
                        << "\n7. Find Top Bowling Average\n8. Find Top Strike Rate Of Bowler"
                        << "\n9. Find Best Economy Rate\n10. Find Best Strike Rate With 5W And 4W"
                        << "\n11. Find Great Balling Average With Best Strike Rate"
                        << "\n12. Find Maximum Wickets With Best Bowling Average"
                        << "\n13. Find Best Bowling Average And Batsman Average"
                        << "\n14. Find Most Runs And Wickets Cricketer"
                        << "\n15. Find Most Max 100 And Avg\n16. Clear Screen\n17. Exit\n" 
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
            case choice::ALL_ROUNDER_BAT_BALL_AVG:
                find_batting_and_bowling_avg();
                break;
            case choice::MOST_RUN_AND_WICKETS:
                find_cricketer_who_had_most_runs_wickets();
                break;
            case choice::MAX_100_AVG:
                find_cricketer_who_had_most_hundered_with_best_average();
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

    void find_batting_and_bowling_avg()
    {
        this -> all_rounder = analyser.find_batting_and_bowling_avg();
        display_batting_and_bowling_avg();
    }

    void display_batting_and_bowling_avg()
    {
        view.display_batting_and_bowlimg_avg_with_name(all_rounder.get_player_name(),
                                                    all_rounder.get_batting_avg(), all_rounder.get_bowling_avg());
    }

    void find_cricketer_who_had_most_runs_wickets()
    {
        this -> all_rounder = analyser.find_cricketer_who_had_most_runs_wickets();
        display_cricketer_who_had_most_runs_wickets();
    }

    void display_cricketer_who_had_most_runs_wickets()
    {
        view.display_cricketer_who_had_most_runs_wickets_with_name(all_rounder.get_player_name(),
                                            all_rounder.get_batsman_run(), all_rounder.get_bowler_run());
    }

    void find_cricketer_who_had_most_hundered_with_best_average()
    {
        this -> batsman = analyser.find_cricketer_who_had_most_hundered_with_best_average();
        display_cricketer_who_had_most_hundered_with_best_average();
    }

    void display_cricketer_who_had_most_hundered_with_best_average()
    {
        view.display_cricketer_who_had_most_hundered_with_best_average(batsman.get_player_name(),
                                                batsman.get_hundered(), batsman.get_average());
    }
};

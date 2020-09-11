#include <iostream>
#include  <stdlib.h>

class ipl_controller
{
    ipl_view view;
    ipl_analyser analyser;
    ipl_run batsman;

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
        bool start = true;

        enum choice
        {
            TOP_BATTING_AVG = 1,
            TOP_STRIKING_RATE,
            MAX_SIXS_AND_FOURS,
            STRIKE_RATE_SIX_FOUR,
            CLEAR_SCREEN,
            EXIT
        };

        while (start)
        {
            std::cout << "1. Find Top Batting Average\n2. Find Top Striking Rate\n3. Find Max 6(s) And 4(s)" 
                        << "\n4. Find Best Strike Rate With Best Six And Four\n5. Clear Screen\n6. Exit\n" 
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

    void display_top_batting_avg()
    {
        view.display_top_batting_avg_with_name(batsman.get_player_name(), batsman.get_average());
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
};

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
            CLEAR_SCREEN,
            EXIT
        };

        while (start)
        {
            std::cout << "1. Find Top Batting Average" 
                        << "\n2. Clear Screen\n3. Exit\n" << std::endl;
            switch (view.take_input_as_choice())
            {
            case choice::TOP_BATTING_AVG:
                find_top_batting_average();
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

    void display_top_batting_avg()
    {
        view.display_top_batting_avg_with_name(batsman.get_player_name(),
             batsman.get_average());
    }
};

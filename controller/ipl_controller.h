#include <iostream>

class ipl_controller
{
    ipl_view view;
    ipl_analyser analyser;

public:
    ipl_controller(ipl_view view, ipl_analyser analyser)
    {
        this -> view = view;
        this -> analyser = analyser;
    }

    void show_welcome_message()
    {
        std::cout << "Welcome To Ipl Analyser System" << std::endl;
    }

    void display_top_batting_avg(std::string fields)
    {
        ipl_run most_run = analyser.find_data(fields);
        view.display_top_batting_avg_with_name(most_run.get_player_name(),
             most_run.get_average());
    }
};

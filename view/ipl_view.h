#include <iostream>

class ipl_view
{
public:
    int take_input_as_choice();
    void display_top_batting_avg_with_name(std::string cricketer_name, double batting_avg);
    void display_top_strike_rate_with_name(std::string cricketer_name, double strike_rate);
};

int ipl_view::take_input_as_choice()
{
    int choice;
    std::cout << "Enter Your Choice: ";
    std::cin >> choice;
    return choice;
}

void ipl_view::display_top_batting_avg_with_name(std::string cricketer_name, 
                                                    double batting_avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nTop Batting Average: "
            << batting_avg << std::endl;
}

void ipl_view::display_top_strike_rate_with_name(std::string cricketer_name, double strike_rate)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nTop Strike Rate: "
            << strike_rate << std::endl;
}
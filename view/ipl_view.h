#include <iostream>

class ipl_view
{
public:
    int take_input_as_choice();
    void display_top_batting_avg_with_name(std::string cricketer_name, double batting_avg);
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
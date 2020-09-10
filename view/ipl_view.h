#include <iostream>

class ipl_view
{
public:
    void display_top_batting_avg_with_name(std::string cricketer_name, double batting_avg);
};

void ipl_view::display_top_batting_avg_with_name(std::string cricketer_name, 
                                                    double batting_avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nTop Batting Average: "
            << batting_avg << std::endl;
}
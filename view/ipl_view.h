#include <iostream>

class ipl_view
{
public:
    int take_input_as_choice();
    void display_top_avg_with_name(std::string cricketer_name, double avg);
    void display_top_strike_rate_with_name(std::string cricketer_name, double strike_rate);
    void display_max_six_and_four_with_player_name(std::string cricketer_name, int six, int four);
    void display_best_strike_rate_with_best_six_and_four_with_name(std::string cricketer_name, 
                                                            double strike_rate, int six, int four);
    void display_great_average_with_best_strike_rate_with_name(std::string cricketer_name, double batting_avg,
                                                                                double strike_rate);
    void display_maximum_runs_with_best_average_with_name(std::string cricketer_name, int run,
                                                                                double batting_avg);
    void display_beat_economy_rate_with_name(std::string cricketer_name, double economy); 
    void display_best_strike_rate_with_4w_and_5w_with_name(std::string cricketer_name, 
                                                            double strike_rate, int four_wkts, int five_wkts);  
    void display_max_wkts_with_best_bowling_average_with_name(std::string cricketer_name, int wickets,
                                                                double avg);   
    void display_batting_and_bowlimg_avg_with_name(std::string cricketer_name, double batting_avg,
                                                                double bowling_avg);
    void display_cricketer_who_had_most_runs_wickets_with_name(std::string cricketer_name, int runs,
                                                                int wickets);  
    void display_cricketer_who_had_most_hundered_with_best_average(std::string cricketer_name, int hundred,
                                                                double avg);
    void display_cricketer_who_had_zero_hundered_and_fifty_with_best_average(std::string cricketer_name,
                                                                    double avg);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
};

int ipl_view::take_input_as_choice()
{
    int choice;
    std::cout << "Enter Your Choice: ";
    std::cin >> choice;
    return choice;
}

void ipl_view::display_top_avg_with_name(std::string cricketer_name, 
                                                    double avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nTop Batting Average: "
            << avg << std::endl;
}

void ipl_view::display_top_strike_rate_with_name(std::string cricketer_name, double strike_rate)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nTop Strike Rate: "
            << strike_rate << std::endl;
}

void ipl_view::display_max_six_and_four_with_player_name(std::string cricketer_name, int six, int four)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nSixs: "
            << six << "\nFours: " << four << std::endl;
}

void ipl_view::display_best_strike_rate_with_best_six_and_four_with_name(std::string cricketer_name, 
                                                            double strike_rate, int six, int four)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: "<< strike_rate 
                << "\nSixs: " << six << "\nFours: " << four << std::endl;
}

void ipl_view::display_great_average_with_best_strike_rate_with_name(std::string cricketer_name, double batting_avg,
                                                                                double strike_rate)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nAverage: " << batting_avg 
                 << "\nStrike Rate: "<< strike_rate << std::endl;
}

void ipl_view::display_maximum_runs_with_best_average_with_name(std::string cricketer_name, int run,
                                                                                double batting_avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nRuns: " << run 
                 << "\nBatting Average: "<< batting_avg << std::endl;
}

void ipl_view::display_beat_economy_rate_with_name(std::string cricketer_name, double economy)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nEconomy Rate: "
            << economy << std::endl;
}

void ipl_view::display_best_strike_rate_with_4w_and_5w_with_name(std::string cricketer_name, 
                                                        double strike_rate, int four_wkts, int five_wkts)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: "<< strike_rate 
                << "\n4w: " << four_wkts << "\n5w: " << five_wkts << std::endl;
}   

void ipl_view::display_max_wkts_with_best_bowling_average_with_name(std::string cricketer_name, int wickets,
                                                                double avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nWickets: " << wickets 
                 << "\nAverage: "<< avg << std::endl;
}

void ipl_view::display_batting_and_bowlimg_avg_with_name(std::string cricketer_name, double batting_avg,
                                                                double bowling_avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nBatting Average: " << batting_avg 
                 << "\nBowling Average: "<< bowling_avg << std::endl;
} 

void ipl_view::display_cricketer_who_had_most_runs_wickets_with_name(std::string cricketer_name, int runs,
                                                                int wickets)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nRun: " << runs 
                 << "\nWickets: "<< wickets << std::endl;
}  

void ipl_view::display_cricketer_who_had_most_hundered_with_best_average(std::string cricketer_name, int hundred,
                                                                double avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nHundered: " << hundred 
                 << "\nAverage: "<< avg << std::endl;
}                                                                
                            
void ipl_view::display_cricketer_who_had_zero_hundered_and_fifty_with_best_average(std::string cricketer_name,
                                                                    double avg)
{
    std::cout << "Name Of Cricketer: " << cricketer_name << "\nAverage: "<< avg << std::endl;
}                                                                    

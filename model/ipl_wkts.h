#include <iostream>

class ipl_wkts 
{    
    std::string player;
    int run, four_wkts, five_wkts, wickets;
    double  avg, strike_rate, economy_rate;

public:
    ipl_wkts(){};

    ipl_wkts(std::string player_name)
    {
        player = player_name;
    }

    std::string get_player_name()
    {
        return player;
    }

    void set_run(int run)
    {
        this -> run = run;
    }

    int get_run()
    {
        return run;
    }

    void set_wickets(int wickets)
    {
        this -> wickets = wickets;
    }

    int get_wickets()
    {
        return wickets;
    }
    
    void set_fours_wkts(int four_wkts)
    {
        this -> four_wkts = four_wkts;
    }

    int get_four_wkts()
    {
        return four_wkts;
    }

    void set_five_wkts(int five_wkts)
    {
        this -> five_wkts = five_wkts;
    }

    int get_five_wkts()
    {
        return five_wkts;
    }

    void set_average(double avg)
    {
        this -> avg = avg;
    }

    double get_average()
    {
        return avg;
    }

    void set_strike_rate(double strike_rate)
    {
        this -> strike_rate = strike_rate;
    }

    double get_strike_rate()
    {
        return strike_rate;
    }

    void set_economy_rate(double economy_rate)
    {
        this -> economy_rate = economy_rate;
    }

    double get_economy_rate()
    {
        return economy_rate;
    }
};    

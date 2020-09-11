#include <iostream>

class ipl_run 
{    
    std::string player;
    int run, hundred, fifty, fours, six;
    double  avg, strike_rate;

public:
    ipl_run(){};
    ipl_run(std::string player_name)
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
    
    void set_hundered(int hundered)
    {
        this -> hundred = hundred;
    }

    int get_hundered()
    {
        return hundred;
    }

    void set_fifty(int fifty)
    {
        this -> fifty = fifty;
    }

    int get_fifty()
    {
        return fifty;
    }
    
    void set_fours(int fours)
    {
        this -> fours = fours;
    }

    int get_four()
    {
        return fours;
    }

    void set_six(int six)
    {
        this -> six = six;
    }

    int get_six()
    {
        return six;
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
};    

#include <iostream>

class ipl_all_rounder
{
private:
    std::string player;
    int batsman_run, bowler_run, wickets;
    double  batting_avg, bowling_avg;

public:
    ipl_all_rounder(){}
    
    ipl_all_rounder(std::string player_name)
    {
        player = player_name;
    }

    std::string get_player_name()
    {
        return player;
    }

    void set_batsman_run(int run)
    {
        this -> batsman_run = run;
    }

    int get_batsman_run()
    {
        return batsman_run;
    }

    void set_bowler_run(int run)
    {
        this -> bowler_run = run;
    }

    int get_bowler_run()
    {
        return bowler_run;
    }

    void set_bowler_wickets(int wkts)
    {
        wickets= wkts;
    }

    int get_bowler_wickets()
    {
        return wickets;
    }

    void set_batting_avg(double avg)
    {
        this -> batting_avg = avg;
    }

    double get_batting_avg()
    {
        return batting_avg;
    }

    void set_bowling_avg(double avg)
    {
        this -> bowling_avg = avg;
    }

    double get_bowling_avg()
    {
        return bowling_avg;
    }
};
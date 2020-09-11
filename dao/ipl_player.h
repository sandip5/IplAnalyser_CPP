#include <iostream>
#include "../model/ipl_run.h"
#include "../model/ipl_wkts.h"

class ipl_dao
{
private:
    std::string player;
    int run, four_wkts, five_wkts, wickets, hundred, fifty, four, six;
    double  avg, strike_rate, economy_rate;

public:
    ipl_dao(ipl_run batsman)
    {
        player = batsman.get_player_name();
        run = batsman.get_run();
        hundred = batsman.get_hundered();
        fifty = batsman.get_fifty();
        four = batsman.get_four();
        six = batsman.get_six();
        avg = batsman.get_average();
        strike_rate = batsman.get_strike_rate();
    }

    ipl_dao(ipl_wkts bowler)
    {
        player = bowler.get_player_name();
        avg = bowler.get_average();
        strike_rate = bowler.get_strike_rate();
        economy_rate = bowler.get_economy_rate();
        five_wkts = bowler.get_five_wkts();
        four_wkts = bowler.get_four_wkts();
        wickets = bowler.get_wickets();
    }    
};
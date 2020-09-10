#include <iostream>
#include <unordered_map>

template<typename T>
class ipl_run 
{    
    std::string player, high_score;
    int match, innings, run, hundred, fifty, fours, six;
    double  avg, strike_rate;

    std::unordered_map<std::string, T> mapped_player_record;

public:
    ipl_run(){};
    ipl_run(T player_name)
    {
        player = player_name;
        mapped_player_record["Player Name"] = player; 
    }

    void set_high_score(T high_score)
    {
        this -> high_score = high_score;
        mapped_player_record["High Score"] = high_score;
    }

    void set_match(T match)
    {
        this -> match = match;
        mapped_player_record["Match"] = match;
    }

    void set_innings(T innings)
    {
        this -> innings = innings;
        mapped_player_record["Innings"] = innings;
    }

    void set_run(T run)
    {
        this -> run = run;
        mapped_player_record["Run"] = run;
    }
    
    void set_hundered(T hundered)
    {
        this -> hundred = hundred;
        mapped_player_record["Hundered"] = hundred;
    }

    void set_fifty(T fifty)
    {
        this -> fifty = fifty;
        mapped_player_record["Fifty"] = fifty;
    }
    
    void set_fours(T fours)
    {
        this -> fours = fours;
        mapped_player_record["Four"] = fours;
    }

    void set_six(T six)
    {
        this -> six = six;
        mapped_player_record["Six"] = six;
    }

    void set_average(T avg)
    {
        this -> avg = avg;
        mapped_player_record["Average"] = avg;
    }

    void set_strike_rate(T strike_rate)
    {
        this -> strike_rate = strike_rate;
        mapped_player_record["Strike Rate"] = strike_rate;
    }

    std::unordered_map<std::string, T> get_player_mapped_details()
    {
        return mapped_player_record;
    }
};    

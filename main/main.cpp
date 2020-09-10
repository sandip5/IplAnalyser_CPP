#include "../view/ipl_view.h"
#include "../model/ipl_analyser.h"
#include "../controller/ipl_controller.h"

int main()
{
    ipl_view view;
    ipl_analyser analyser;
    ipl_controller controller(view, analyser);
    controller.show_welcome_message();
    controller.display_top_batting_avg("Average");
    
    return 0;
}
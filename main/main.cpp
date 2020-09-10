#include "../view/ipl_view.h"
#include "../model/ipl_analyser.h"
#include "../controller/ipl_controller.h"

template<typename T>
void start_analyser()
{
    ipl_view view;
    ipl_analyser<T> analyser;
    ipl_controller<T> controller(view, analyser);
    controller.show_welcome_message();
    controller.display_top_batting_avg("Average");
}


int main()
{
    start_analyser<class ipl_run>();
    return 0;
}
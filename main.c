#include "ganesha.h"

int main()
{    	       
    WINDOW *myWins[WINCOUNT];		//WINDOW structure variable
    
    initCurses(myWins,0);
    attron(A_STANDOUT);

    stairs(myWins,1);

    attroff(A_STANDOUT);
    
    lightLeft();
    lightRight();
    
    lLeftRight(20,5,5,6,7);
    lLeftRight(20,146,5,6,7);
    lLeftRight(20,43,5,6,7);
    lLeftRight(20,108,5,6,7);

    attron(A_STANDOUT);

    swastikLeftRight(myWins,2);
    
    makhar(myWins,3);

    napms(500);

    name1(myWins,4);
    name2(myWins,5);
    name3(myWins,6);

    attroff(A_STANDOUT);

    ganesha();

    napms(1000);

    getch();

    /* Deallocate memory and Stop curses */
    endwin();

    return 0;
}
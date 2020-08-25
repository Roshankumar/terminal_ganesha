#include "ganesha.h"

#define BKG 1
#define STAIRS 2
#define LINES  3
#define LIGHTS1 4
#define SWASTIK 21
#define MAKHAR 31
#define NAME1 11
#define NAME2 11
#define NAME3 11
#define BAPPA1 41
#define BAPPA2 42
#define BAPPA3 43
#define MOUSE 45
#define BACK 17

//Global items
int colorno = 21;
int mainRowG = 100, mainColG = 160;   //variables to save outer border size
int mainPosXG = 0, mainPosYG = 0;	//variables to save x and y coordinates

void initCurses(WINDOW **wins, int i)							//program initializing function
{
    initscr();								//Allocate memory and clear the screen
    cbreak();								//Terminal in cbreake mode and process single char at a time
    noecho();								//Do not display(print) typed characters on screen
    curs_set(FALSE);						//Make cursur invisible
    keypad(stdscr, TRUE);					//Make keypad enable
    resize_term(mainRowG, mainColG);    	//resize window
    #ifdef A_COLOR							//conditional compilation
        if(has_colors()) 
        start_color();		//has color -> checks whether terminal supports color or not
    #endif                                  //closes #ifdef directive
    refresh();
    
//LINES
    init_pair(3,153,BACK);

//BORDER
    init_pair(1,153,BACK);

//STAIRS
    init_pair(2,231,BACK);

//LIGHTS
    init_pair(4,13,BACK);
    init_pair(5,11,BACK);
    init_pair(6,231,BACK);
    init_pair(7,118,BACK);
    init_pair(8,15,BACK);

//NAMES
    init_pair(11,227,BACK);

//SWASTIK
    init_pair(21,211,BACK);

//MAKHAR
    init_pair(31,220,BACK);

//BAPPA
    init_pair(41,226,BACK);
    init_pair(42,157,BACK);
    init_pair(43,190,BACK);

//MOUSE
    init_pair(45,0,BACK);

    wins[i]  = newwin(mainRowG,mainColG,mainPosXG,mainPosYG);   //creating window for actual screen
    attron(A_STANDOUT);
    wbkgd(wins[i], COLOR_PAIR(BKG));
    box(wins[i],0,0);                       //creating border for actual window 
	wborder(wins[i],'|','|','-','-','*','*','*','*');
    wrefresh(wins[i]);
}

void stairs(WINDOW **wins, int i)
{
    char stair3d[14][50] = { {"    ___________________________________"},
                            {"   |...................................|"},
                            {"   |#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#|"},
                            {"  /_____________________________________\\"},
                            {"  |.....................................|"},
                            {"  |#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#|"},
                            {" /_______________________________________\\"},
                            {" |.......................................|"},
                            {" |#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#|"},
                            {"/_________________________________________\\"},
                            {"|.........................................|"},
                            {"|#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#|"},
                            {"(_) (_) (_) (_) (_) (_) (_) (_) (_) (_) (_)"},
                            {" *   *   *   *   *   *   *   *   *   *   * "}};
    
    int x;

    wins[i]  = newwin(mainRowG-86,mainColG-110,mainPosXG+38,mainPosYG+58);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(STAIRS));
    for(x = 13; x >= 0; x--)
    {
        napms(300);
		mvwaddstr(wins[i],x,0,stair3d[x]);
        wrefresh(wins[i]); 
    }   
    wrefresh(wins[i]); 
}

void makhar(WINDOW **wins, int i)
{
    char ganapati[19][40] = {{"                 __{@}__              "},
                             {"           _____{_______}_____        "},
                             {"  ________{___________________}_____  "},
                             {"  -!--!--!--!--!--!-!!-!--!--!--!--!- "},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},   
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"},
                             {" {                                   }"}};

    int x;

    wins[i]  = newwin(mainRowG-81,mainColG-120,mainPosXG+20,mainPosYG+60);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(MAKHAR));
    for(x = 18; x >= 0; x--)
    {
		napms(300);
        mvwaddstr(wins[i],x,0,ganapati[x]);
        wrefresh(wins[i]); 
    }
    //wattroff(wins[i], COLOR_PAIR(MAKHAR));
    wrefresh(wins[i]); 
}

void ganesha()
{
    int i = 24, j = 62;
    attron(COLOR_PAIR(BAPPA1));
    mvprintw(i++,j,"                               ");
    mvprintw(i++,j,"                .(**).         ");
    mvprintw(i++,j,"               .(----).        ");
    attroff(COLOR_PAIR(BAPPA1));
    attron(COLOR_PAIR(BAPPA2));
    mvprintw(i++,j,"        ($)   [( 0  0 )]  ($)  ");
    mvprintw(i++,j,"        |  \\   '(    )'   / |  ");
    mvprintw(i++,j,"       __\\  \\/   | ||  \\ /  /  ");
    mvprintw(i++,j,"      |_|_| / \\  | |_   \\__/   ");
    mvprintw(i++,j,"      {   }|   \\  \\__\\   \\ \\   ");
    mvprintw(i++,j,"       \\_/ \\    \\ .     /|@|   ");
    mvprintw(i++,j,"          __\\____\\_____/__     ");
    attroff(COLOR_PAIR(BAPPA2)); 
    attron(COLOR_PAIR(BAPPA3));
    mvprintw(i++,j,"         /     \\    /      \\  ");
    mvprintw(i++,j,"        |       \\__/        |  ");
    mvprintw(i++,j,"        |         /        /   ");
    mvprintw(i++,j,"________\\_______/________/________");
    mvprintw(i++,j,"                                   ");
    attroff(COLOR_PAIR(BAPPA3));
    attron(COLOR_PAIR(MOUSE)); 
    mvprintw(36,66,"  __QQ");
    mvprintw(37,66,"-(!)_'>");
    attroff(COLOR_PAIR(MOUSE)); 
}

void swastikLeftRight(WINDOW **wins,int i)
{
    char sleft[9][19]={{"\\\\      ||=======//"},
	                   {"||      ||         "},	
	                   {"||  o   ||   o     "},
	                   {"||      ||         "},
                       {"================== "},
	                   {"        ||      || "},
	                   {"    o   ||   o  || "},
		               {"        ||      || "},
                       {"//======||      \\\\ "}};
    
    char sright[9][19]={{"\\\\      ||=======//"},
	                   {"||      ||         "},	
	                   {"||  o   ||   o     "},
	                   {"||      ||         "},
                       {"================== "},
	                   {"        ||      || "},
	                   {"    o   ||   o  || "},
		               {"        ||      || "},
                       {"//======||      \\\\ "}};

    int x;

    wins[i]  = newwin(mainRowG-91,mainColG-141,mainPosXG+26,mainPosYG+18);
    wins[i+1]  = newwin(mainRowG-91,mainColG-141,mainPosXG+26,mainPosYG+121);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(SWASTIK));
    wbkgd(wins[i+1], COLOR_PAIR(SWASTIK));
    for(x = 0; x < 9; x++)
    {
        mvwaddstr(wins[i],x,0,sleft[x]);
        mvwaddstr(wins[i+1],x,0,sright[x]);
    }
    wrefresh(wins[i]);
    wrefresh(wins[i+1]);
}

void name1(WINDOW **wins, int i)
{
    char nameg[8][65] = {{" .ggggg.                                                 gg   gg "},
                         {"gg'   `gg                                                gg      "},
                         {"gg        .gggggg. ggggggg. .gggggg. ggggggg. .gggggg. gggggg gg "},
                         {"gg   gggg gg'  `gg gg'  `gg gg'  `gg gg'  `gg gg'  `gg   gg   gg "},
                         {"gg.   .gg gg.  .gg gg    gg gg.  .gg gg.  .gg gg.  .gg   gg   gg "},
                         {" `ggggg'  `ggggggg gg    gg `ggggggg ggggggg' `ggggggg   gg   gg "},
                         {"                                     gg                          "},
                         {"                                     gg                          "}};   

    int x;

    wins[i]  = newwin(mainRowG-92,mainColG-95,mainPosXG+2,mainPosYG+20);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(NAME1));
    for(x = 0; x < 8; x++)
	  	mvwaddstr(wins[i],x,0,nameg[x]);
    
    wattroff(wins[i], COLOR_PAIR(NAME1));
    wrefresh(wins[i]);
}

void name2(WINDOW **wins, int i)
{
    char nameg[8][46] = {{" gggggggg                                     "},
                         {" gg    `gg                                    "},
                         {"ggggggggg' .gggggg. ggggggg. ggggggg. .gggggg."},
                         {" gg   `gg. gg'  `gg gg'  `gg gg'  `gg gg'  `gg"},
                         {" gg    .gg gg.  .gg gg.  .gg gg.  .gg gg.  .gg"},
                         {" ggggggggg `ggggggg ggggggg' ggggggg' `ggggggg"},
                         {"                    gg       gg               "},
                         {"                    gg       gg               "}};   

    int x;

    wins[i]  = newwin(mainRowG-92,mainColG-114,mainPosXG+2,mainPosYG+91);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(NAME2));
    for(x = 0; x < 8; x++)
	  	mvwaddstr(wins[i],x,0,nameg[x]);    
    wrefresh(wins[i]);
}

void name3(WINDOW **wins, int i)
{
    char nameg[8][48] = {{"gggggg.gggg                                     "},
                         {"gg  `gg  `gg                                    "},
                         {"gg   gg   gg .gggggg. ggggggg. gg    gg .gggggg."},
                         {"gg   gg   gg gg'  `gg gg'  `gg gg    gg gg'  `gg"},
                         {"gg   gg   gg gg.  .gg gg       gg.  .gg gg.  .gg"},
                         {"gg   gg   gg `gggggg' gg       `ggggggg `ggggggg"},
                         {"                                    .gg         "},
                         {"                                gggggg          "}};   

    int x;

    wins[i]  = newwin(mainRowG-92,mainColG-112,mainPosXG+11,mainPosYG+55);
    refresh();

    wbkgd(wins[i], COLOR_PAIR(NAME3));
    for(x = 0; x < 8; x++)
	  	mvwaddstr(wins[i],x,0,nameg[x]);   
    wrefresh(wins[i]);
}

void swastik(int j, int k)
{
    WINDOW *onoff;
    char swastiks[3][7] = {{"    __"},
                          {"|__|__"},
                          {" __|  |"}};

    int x;

    onoff  = newwin(mainRowG-97,mainColG-153,j,k);
    refresh();

    for(x = 0; x < 8; x++)
		mvwaddstr(onoff,x,0,swastiks[x]);   
    
    wrefresh(onoff); 
}

void lightLeft()
{
    int i,j;
    attron(COLOR_PAIR(LINES)); 
    for(i=19,j=0;j<52;j++)
    {   
        napms(100);
        mvaddch(i,j,'o');
        j++;
        mvaddch(i,j,'~');
        refresh();
    }
    for(i=19,j=52;(i>15)&&(j<55);i--,j++)
    {   
        napms(100);
        mvaddch(i,j,'{');
        refresh();
    }
    attroff(COLOR_PAIR(LINES));
    refresh(); 
}

void lLeftRight(int i, int j, int l2, int l3, int l4)
{
    int k = i*2;
    for(;i<k;i++)
    {
        if(i%2==0)
        { 
            attron(COLOR_PAIR(l2));
            mvprintw(i,j,"*");
            attroff(COLOR_PAIR(l2));
        }
        else
        { 
            attron(COLOR_PAIR(LIGHTS1));
            mvprintw(i,j,"!");
            attroff(COLOR_PAIR(LIGHTS1));
        }
        if(l2 != 8) napms(100);
        refresh();
    }
    attron(COLOR_PAIR(l2));
    mvprintw(i,j,"*");
    attroff(COLOR_PAIR(l2));
    refresh();
    j = j + 3;
    i = k/2;
    for(;i<k+2;i++)
    {
        if(i%2==0) 
        {
            attron(COLOR_PAIR(l3));
            mvprintw(i,j,"*");
            attroff(COLOR_PAIR(l3));
        }
        else 
        {
            attron(COLOR_PAIR(LIGHTS1));
            mvprintw(i,j,"!");
            attroff(COLOR_PAIR(LIGHTS1));
        }
        if(l2 != 8) napms(100);
        refresh();
    }
    attron(COLOR_PAIR(l3));
    mvprintw(i,j,"*");
    attroff(COLOR_PAIR(l3));
    refresh();
    j = j + 3;
    i = k/2;
    for(;i<k;i++)
    {
        if(i%2==0)
        { 
            attron(COLOR_PAIR(l4));
            mvprintw(i,j,"*");
            attroff(COLOR_PAIR(l4));
        }
        else
        { 
            attron(COLOR_PAIR(LIGHTS1));
            mvprintw(i,j,"!");
            attroff(COLOR_PAIR(LIGHTS1));
        }
        if(l2 != 8) napms(100);
        refresh();
    }
    attron(COLOR_PAIR(l4));
    mvprintw(i,j,"*");
    attroff(COLOR_PAIR(l4));
    refresh();
}

void lightRight()
{
    int i,j;
    attron(COLOR_PAIR(LINES));
    for(i=17,j=103;(i<20)&&(j<107);i++,j++)
    {
        napms(100);
        mvaddch(i,j,'}');
        refresh();
    }
    for(i=19,j=106;j<159;j++)
    {
        napms(100);
        mvaddch(i,j,'~');
        j++;
        mvaddch(i,j,'o');
        refresh();
    }
    attroff(COLOR_PAIR(LINES));
    refresh(); 
}
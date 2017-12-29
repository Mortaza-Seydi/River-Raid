/*
*************************************************************************************************************
*
*   In The Name Of ALLAH
*
*   Project Name   :   River Raid
*   Code Version   :   1.0
*     Written by   :   Mortaza Seydi - Zanjan University, IRAN - Fall 2017
*         GitHub   :   github.com/Mortaza-Seydi
*
*   Note : This Program is Only Executable On Linux With "Ncurses", "SDL" And "SDL_mixer" Library.
*          If You Want To Run It On Windows, Use "PDCurses", "SDL" And "SDL_mixer" (Windows version) Library,
*          With Full Screen Command Prompt (The Only Way To Run).
*
*   Compile (Linux)  :  gcc RiverRaid.c -o RiverRaid -lncurses -lSDL -lSDL_mixer
*       Run (Linux)  :  ./RiverRaid
*
*   Source Code Available on  :   github.com/Mortaza-Seydi
*
*************************************************************************************************************
*/

#include "RiverRaid.h"        /* Include The Game Own Library */

#include <ncurses.h>          /* Famouse Ncurses Library for Graphics */

#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <SDL/SDL.h>          /* for Sounds */
#include <SDL/SDL_mixer.h>    /* for Sounds */

/*  Functoins  */

void  Page_1_2     (void);   /* Print Texts In Page 1 and 2 */

void  Menu         (void);   /* Shows The Menubar */

void  Return_Menu  (void);   /* Return to The Menu From One Of The Menu Items */

void  Start        (void);   /* Start The Game */

void  High_Score   (void);   /* Save High Scores To The File, Sort It And Show It In Game */

void  How_To_Play  (void);   /* A Users Gudie To Play The Game */

void  About        (void);   /* Introduice The Programmer */

void  Exit_Page    (void);   /* Exit From The Game */

/***********************************************************************/

int main(void)            /* Main Function */
{

    initscr();
    curs_set(FALSE);          /* Disable Curser Show */
    keypad (stdscr,FALSE);    /* Turn Keyboard Off */

    /* Colors */

    start_color();
    init_pair(1,  COLOR_YELLOW,  COLOR_GREEN);
    init_pair(2,  COLOR_BLUE,    COLOR_CYAN);
    init_pair(3,  COLOR_BLACK,   COLOR_CYAN);
    init_pair(4,  COLOR_BLACK,   COLOR_GREEN);
    init_pair(5,  COLOR_RED,     COLOR_GREEN);
    init_pair(6,  COLOR_WHITE,   COLOR_BLUE);
    init_pair(7,  COLOR_BLUE,    COLOR_GREEN);
    init_pair(8,  COLOR_RED,     COLOR_YELLOW);
    init_pair(9,  COLOR_RED,     COLOR_RED);
    init_pair(10, COLOR_GREEN,   COLOR_GREEN);

    /********************************************/

    Page_1_2();     /* Print Texts In Page 1 and 2 */

    Menu();         /* Shows The Menubar */

    return 0;

}

void Page_1_2 (void)      /* Print Texts In Page 1 and 2 */
{

    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX); /* Get The Maximum Size of Standard Screen */
    bkgd(COLOR_PAIR(1));          /* Set Background Color */
    napms(1000);                  /* Wait 1 second*/

    attron(A_BOLD);
    wText_Style_1 (stdscr, maxY/2, maxX/2-5, "River  Raid"); /* "wText_Style_1" Is Functoins in RiverRaid.h Library */
    attroff(A_BOLD);

    refresh();                    /* Update The Screen */
    napms(3000);

    getmaxyx(stdscr, maxY, maxX);

    clear();                      /* Clear The Stdscr */
    bkgd(COLOR_PAIR(2));

    wText_Style_1(stdscr, 2, maxX/2-strlen("Welcome To The")/2, "Welcome To The");
    wText_Style_1(stdscr, 4, maxX/2-strlen("River Riad")/2,     "River Raid");      /* "maxX/2-strlen(char *Text)/2" This Sentence prints the Text 																								   in the Middle of The Screen */

    refresh();

    napms(1000);

    attron(A_BOLD);               /* Turn On Bolding Texts */

    mvaddstr(7, maxX/2-strlen("Start")/2, "Start");
    refresh();
    napms(250);

    mvaddstr(9, maxX/2-strlen("High Score")/2, "High Score");
    refresh();
    napms(250);

    mvaddstr(11, maxX/2-strlen("How To Play")/2, "How To Play");
    refresh();
    napms(250);

    mvaddstr(13, maxX/2-strlen("About Us")/2, "About Us");
    refresh();
    napms(250);

    mvaddstr(15, maxX/2-strlen("Quit")/2, "Quit");
    refresh();
    napms(250);

    attroff(A_BOLD);              /* Turn Off Bolding Texts */

    napms(300);

    attron(COLOR_PAIR(3));        /* Set The Color Pair 3 */

    mvaddstr(19 ,maxX/2-strlen("Make Terminal Full Screen And Use arrows keys to move and Enter to select")/2,
                          "Make Terminal Full Screen And Use arrows keys to move and Enter to select");
    refresh();

    attroff(COLOR_PAIR(3));
    napms(250);

}

void Menu (void)          /* Shows The Menubar */
{

    int maxX, maxY;
    int i;
    int key,number=0;
    char menu[5][12]=             /* Menu Items */
    {
        "Start\0",
        "High Score\0",
        "How To Play\0",
        "About Us\0",
        "Quit\0"
    };

    getmaxyx(stdscr, maxY, maxX);
    attron(A_REVERSE | A_BOLD);
    mvaddstr(7, maxX/2-strlen(menu[0])/2, menu[0]);   /* Print First Menu Item And Bold it And Reverse it */
    attroff(A_REVERSE | A_BOLD);

    keypad(stdscr,TRUE);                              /* Turn on Keyborad on Standard Screen */
    noecho();                                         /* The Words That You Entered does not Shown on The Stdscr */

    do
    {

        key = getch();            /* Gets An Arrow Key */

        switch(key)
        {
            case KEY_DOWN:        /* Down Arrow Keys */
            {
                number++;
                if(number > 4)
                    number = 0;
                break;
            }

            case KEY_UP:          /* Up Arrow Keys */
            {
                number--;
                if(number < 0)
                    number = 4;
                break;
            }

        }

        attron(A_BOLD);

        for(i=0; i<5; i++)
        {
            if( i == number )
                attron(A_REVERSE);      /* Reverse The Menu Item That Curser Shows */

            mvaddstr(7+(i*2), maxX/2-strlen(menu[i])/2, menu[i]);

            attroff(A_REVERSE);
        }

        attroff(A_BOLD);

    }   while(key != '\n');        /* \n is Enter */


    if (number == 0)              /* if You Select 1st Menu Item */
        Start();

    else if (number == 1)         /* if You Select 2nd Menu Item */
        High_Score();

    else if (number == 2)          /* if You Select 3rd Menu Item */
        How_To_Play();

    else if (number == 3)          /* if You Select 4th Menu Item */
        About();

    else if (number == 4)          /* if You Select 5th Menu Item */
        Exit_Page();

    Return_Menu();

}

void Return_Menu (void)   /* Return to The Menu From One Of The Menu Items Just Print Menu Items Without Any Stayle */
{

    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);

    clear();
    bkgd(COLOR_PAIR(2));

    mvaddstr(1,maxX/2-strlen("Welcome To The")/2,"Welcome To The");
    mvaddstr(3,maxX/2-strlen("River Raid")/2,"River Raid");

    attron(A_BOLD);

    mvaddstr(7,maxX/2-strlen("Start")/2,"Start");

    mvaddstr(9,maxX/2-strlen("High Score")/2,"High Score");

    mvaddstr(11,maxX/2-strlen("How To Play")/2,"How To Play");

    mvaddstr(13,maxX/2-strlen("About Us")/2,"About Us");

    mvaddstr(15,maxX/2-strlen("Quit")/2,"Quit");


    attroff(A_BOLD);

    attron(COLOR_PAIR(3));

    mvaddstr(19 ,maxX/2-strlen("Make Terminal Full Screen And Use arrows keys to move and Enter to select")/2,
                          "Make Terminal Full Screen And Use arrows keys to move and Enter to select");

    attroff(COLOR_PAIR(3));

    refresh();

    Menu();

}

void Start (void)         /* Start The Game */
{

  WINDOW *riverWin, *borderWin[2], *infoWin, *helpWin;  /* Defined Variables And Windows */

  Player player;             /* Player is Struct in RiverRaid.h Library */

  Things island[2];          /* Things is Struct in RiverRaid.h Library And It Is For Plane And Ships, etc. */

  Things ship[3];
  Things BoombShip[3];

  Things hk;
  Things BoombHK;

  Things plane;
  Things BoombPlane;

  Things fuel;

  int maxX , maxY, CurentX, CurentY ;
  unsigned long long int counter = 1;   /* Total Counter Used In Main Loop */

  int sec;
  int min;
  int n;          /* Used For Showing Fuel Progress */

  int  ch;        /* Get From KeyBoard */
  int i;          /* Used in For */
  char Progresss[12] = {'=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '\0'}; /* Used For Showing Fuel Progress */

  /************************************************************************************/

  mvprintw(23, 55, "Enter name : ");
  refresh();
  keypad(stdscr,TRUE);
  echo();                             /* The Texts That You Entered Will Be Shown in Screen */
  scanw("%s", player.name);
  refresh();

  /*  Sounds  */

  Mix_Music *LoseMusic, *ShipDestroyMusic, *HKDestroyMusic;
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_AllocateChannels(1);

  LoseMusic = Mix_LoadMUS("lose.mp3");
  ShipDestroyMusic = Mix_LoadMUS("ship.mp3");
  HKDestroyMusic = Mix_LoadMUS("hk.mp3");

  /***********************************************************************/

  srand(time(NULL));  /* Provides Real Random Numbers */
  noecho();
  getmaxyx(stdscr, maxY, maxX);

  /* Draw And Color The Windows */

  infoWin = newwin(maxY/2,(maxX/5),0,(maxX*8/10));
  wbkgd(infoWin,COLOR_PAIR(3));
  mvwprintw(infoWin,2,2,"Name : %s",player.name);
  wrefresh(infoWin);

  helpWin = newwin(maxY/2+1,(maxX/5),maxY/2,(maxX*8/10));
  wbkgd(helpWin,COLOR_PAIR(8));
  mvwprintw(helpWin,2,1,"Press BACKSPACE to Pause \n    Arrows to Move and shoot");
  wrefresh(helpWin);

  riverWin = newwin(maxY,(maxX*6/10)+1,0,(maxX/10));
  wbkgd(riverWin,COLOR_PAIR(6));
  wrefresh(riverWin);

  borderWin[0] = newwin(maxY,maxX/10,0,0);
  wbkgd(borderWin[0],COLOR_PAIR(4));
  wrefresh(borderWin[0]);

  borderWin[1] = newwin(maxY,maxX/10,0,(maxX*7/10));
  wbkgd(borderWin[1],COLOR_PAIR(4));
  wrefresh(borderWin[1]);

  /**************************************************************************/

  getmaxyx  (riverWin, maxY,maxX);
  keypad    (riverWin, FALSE);
  min=0;
  sec=0;
  player.Score =0;
  n=11;
  player.Score = 0;

  /*  Draw The First Sharps   */

  plane.x0 = maxX/2;
  plane.y0 = maxY-6;
  wPlane    (riverWin, plane.y0, plane.x0, '*');
  plane.x  = plane.x0;
  plane.y  = plane.y0;
  plane.counter[0] = 0;
  wrefresh  (riverWin);

  island[0].x0 = maxX-4;
  island[0].y0 = 35;
  wIsland (riverWin, island[0].y0, island[0].x0, '=');
  island[0].counter[1] = island[0].y0;
  island[0].counter[0] = 1;
  wrefresh  (riverWin);

  island[1].x0 = 3;
  island[1].y0 = 5;
  wIsland (riverWin, island[1].y0, island[1].x0, '=');
  island[1].counter[1] = island[1].y0;
  island[1].counter[0] = 1;
  wrefresh  (riverWin);

  ship[0].x0 = 10;
  ship[0].y0 = 10;
  wShip (riverWin, ship[0].y0, ship[0].x0, '~');
  ship[0].counter[1] = ship[0].y0;
  ship[0].counter[0] = 1;
  wrefresh  (riverWin);

  ship[1].x0 = 40;
  ship[1].y0 = 20;
  wShip (riverWin, ship[1].y0, ship[1].x0, '~');
  ship[1].counter[1] = 20;
  ship[1].counter[0] = 1;
  wrefresh  (riverWin);

  ship[2].x0 = 75;
  ship[2].y0 = 30;
  wShip (riverWin, ship[2].y0, ship[2].x0, '~');
  ship[2].counter[1] = ship[2].y0;
  ship[2].counter[0] = 1;
  wrefresh  (riverWin);

  hk.x0 = 75;
  hk.y0 = 3;
  wHK1  (riverWin, hk.y0, hk.x0, '$');
  hk.counter[1] = hk.y0;
  hk.counter[0] = 1;
  hk.counter[3] = hk.x0;
  hk.counter[4] = 1;
  wrefresh  (riverWin);

  BoombShip[0].x0 = ship[0].x0;
  BoombShip[0].y0 = ship[0].y0+4;
  BoombShip[0].counter[1] = BoombShip[0].y0;

  BoombShip[1].x0 = ship[1].x0;
  BoombShip[1].y0 = ship[1].y0+4;
  BoombShip[1].counter[1] = BoombShip[1].y0;

  BoombShip[2].x0 = ship[2].x0;
  BoombShip[2].y0 = ship[2].y0+4;
  BoombShip[2].counter[1] = BoombShip[2].y0;

  BoombHK.x0 = hk.x0-5;
  BoombHK.y0 = hk.y0;
  BoombHK.counter[1] = BoombHK.x0;
  BoombHK.counter[2] = BoombHK.y0;
  BoombHK.counter[3] = 1;

  BoombPlane.x0 = plane.x;
  BoombPlane.y0 = plane.y-3;
  BoombPlane.counter[1] = BoombPlane.x0;
  BoombPlane.counter[2] = BoombPlane.y0+4;
  BoombPlane.counter[0]=0;
  wrefresh(riverWin);

  /**************************************************************************/

  wmove (riverWin, plane.y0, plane.x0);
  wPause (riverWin);

  keypad    (riverWin, TRUE);
  nodelay   (riverWin, TRUE);

      while (TRUE)
      {

          getyx(riverWin, CurentY, CurentX);

          if (counter % 10000 == 1)  /*  Island 1 */
          {

                wIsland     (riverWin, island[0].y0, island[0].x0, ' ');
                wrefresh  (riverWin);
                wIsland     (riverWin, island[0].counter[1]+5, island[0].x0, '=');
                wrefresh  (riverWin);

                island[0].x=island[0].x0;
                island[0].y=island[0].counter[1]+5;

                wmove     (riverWin, CurentY, CurentX);

                island[0].y0 =island[0].counter[1]+5;
                island[0].counter[1]++;

                if (island[0].y>maxY+5)
                {
                    island[0].counter[1]=-5;
                    island[0].y0=-5;
                }

          }

          if (counter % 10000 == 1)  /*  Island 2 */
          {

                wIsland     (riverWin, island[1].y0, island[1].x0, ' ');
                wrefresh  (riverWin);
                wIsland     (riverWin, island[1].counter[1]+5, island[1].x0, '=');
                wrefresh  (riverWin);

                island[1].x=island[1].x0;
                island[1].y=island[1].counter[1]+5;

                wmove     (riverWin, CurentY, CurentX);

                island[1].y0 =island[1].counter[1]+5;
                island[1].counter[1]++;

                if (island[1].y>maxY+5)
                {
                    island[1].counter[1]=-5;
                    island[1].y0=-5;
                }

          }

          if (counter % 1000 == 1 && plane.counter[0] == 1) /* Plane Boomb */
          {

              mvwaddch  (riverWin, BoombPlane.y0, BoombPlane.x0, ' ');
              wrefresh  (riverWin);
              mvwaddch  (riverWin, BoombPlane.counter[1]-1, BoombPlane.x0, '@');
              wrefresh  (riverWin);

              BoombPlane.x=BoombPlane.x0;
              BoombPlane.y=BoombPlane.counter[1]-1;

              wmove     (riverWin, CurentY, CurentX);

              BoombPlane.y0 =BoombPlane.counter[1]-1;
              BoombPlane.counter[1]--;
              if (BoombPlane.y < 0 )
              {
                  BoombPlane.x0 = plane.x;
                  BoombPlane.y0 = plane.y-3;
                  BoombPlane.counter[1] = BoombPlane.y0;
                  plane.counter[0]=0;
              }
          }

          if (counter % 10000 == 1)  /*  Ship 1  */
          {
                if (ship[0].counter[0]  == 0)
                {
                    ship[0].x0 = rand() % (maxX*9/10+5);
                    ship[0].counter[0]=1;
                }

                wShip     (riverWin, ship[0].y0, ship[0].x0, ' ');
                wrefresh  (riverWin);
                wShip     (riverWin, ship[0].counter[1]+5, ship[0].x0, '~');
                wrefresh  (riverWin);

                ship[0].x=ship[0].x0;
                ship[0].y=ship[0].counter[1]+5;

                wmove     (riverWin, CurentY, CurentX);

                ship[0].y0 =ship[0].counter[1]+5;
                ship[0].counter[1]++;

                if (ship[0].y>maxY+5)
                {
                    ship[0].counter[1]=-5;
                    ship[0].y0=-5;
                    ship[0].counter[0]=0;
                }

          }

          if (counter % 3000 == 1)   /*  Ship 1 Boomb  */
          {

              mvwaddch  (riverWin, BoombShip[0].y0, BoombShip[0].x0, ' ');
              wrefresh  (riverWin);
              mvwaddch  (riverWin, BoombShip[0].counter[1]+1, BoombShip[0].x0, '$');
              wrefresh  (riverWin);

              BoombShip[0].x=BoombShip[0].x0;
              BoombShip[0].y=BoombShip[0].counter[1]+1;

              wmove     (riverWin, CurentY, CurentX);

              BoombShip[0].y0 =BoombShip[0].counter[1]+1;
              BoombShip[0].counter[1]++;

              if (BoombShip[0].y>maxY+5)
              {
                  BoombShip[0].counter[1]=ship[0].y+4;
                  BoombShip[0].y0=ship[0].y+4;
                  BoombShip[0].x0=ship[0].x;
              }
          }

          if (counter % 10000 == 1)  /*  Ship 2  */
          {
                if (ship[1].counter[0]  == 0)
                {
                    ship[1].x0 = rand() % (maxX*9/10+5);
                    ship[1].counter[0]=1;
                }

                wShip     (riverWin, ship[1].y0, ship[1].x0, ' ');
                wrefresh  (riverWin);
                wShip     (riverWin, ship[1].counter[1]+5, ship[1].x0, '~');
                wrefresh  (riverWin);

                ship[1].x=ship[1].x0;
                ship[1].y=ship[1].counter[1]+5;

                wmove     (riverWin, CurentY, CurentX);

                ship[1].y0 =ship[1].counter[1]+5;
                ship[1].counter[1]++;

                if (ship[1].y>maxY+5)
                {
                    ship[1].counter[1]=-5;
                    ship[1].y0=-5;
                    ship[1].counter[0]=0;
                }

          }

          if (counter % 3000 == 1)   /*  Ship 2 Boomb  */
          {

              mvwaddch  (riverWin, BoombShip[1].y0, BoombShip[1].x0, ' ');
              wrefresh  (riverWin);
              mvwaddch  (riverWin, BoombShip[1].counter[1]+1, BoombShip[1].x0, '$');
              wrefresh  (riverWin);

              BoombShip[1].x=BoombShip[1].x0;
              BoombShip[1].y=BoombShip[1].counter[1]+1;

              wmove     (riverWin, CurentY, CurentX);

              BoombShip[1].y0 =BoombShip[1].counter[1]+1;
              BoombShip[1].counter[1]++;

              if (BoombShip[1].y>maxY+5)
              {
                  BoombShip[1].counter[1]=ship[1].y+4;
                  BoombShip[1].y0=ship[1].y+4;
                  BoombShip[1].x0=ship[1].x;
              }
          }

          if (counter % 10000 == 1)  /*  Ship 3  */
          {
                if (ship[2].counter[0]  == 0)
                {
                    ship[2].x0 = rand() % (maxX*9/10+5);
                    ship[2].counter[0]=1;
                }

                wShip     (riverWin, ship[2].y0, ship[2].x0, ' ');
                wrefresh  (riverWin);
                wShip     (riverWin, ship[2].counter[1]+5, ship[2].x0, '~');
                wrefresh  (riverWin);

                ship[2].x=ship[2].x0;
                ship[2].y=ship[2].counter[1]+5;

                wmove     (riverWin, CurentY, CurentX);

                ship[2].y0 =ship[2].counter[1]+5;
                ship[2].counter[1]++;

                if (ship[2].y>maxY+5)
                {
                    ship[2].counter[1]=-5;
                    ship[2].y0=-5;
                    ship[2].counter[0]=0;
                }

          }

          if (counter % 3000 == 1)   /*  Ship 3 Boomb  */
          {

              mvwaddch  (riverWin, BoombShip[2].y0, BoombShip[2].x0, ' ');
              wrefresh  (riverWin);
              mvwaddch  (riverWin, BoombShip[2].counter[1]+1, BoombShip[2].x0, '$');
              wrefresh  (riverWin);

              BoombShip[2].x=BoombShip[2].x0;
              BoombShip[2].y=BoombShip[2].counter[1]+1;

              wmove     (riverWin, CurentY, CurentX);

              BoombShip[2].y0 =BoombShip[2].counter[1]+1;
              BoombShip[2].counter[1]++;

              if (BoombShip[2].y>maxY+5)
              {
                  BoombShip[2].counter[1]=ship[2].y+4;
                  BoombShip[2].y0=ship[2].y+4;
                  BoombShip[2].x0=ship[2].x;
              }
          }

          if (counter % 10000 == 1)  /*  HK  */
          {
                if (hk.counter[0]  == 0)
                {
                    hk.x0 = rand() % (maxX*9/10);
                    hk.counter[0] = 1;
                }

                if (hk.counter[4] == 1)
                {
                    wHK1      (riverWin,  hk.y0, hk.x0, ' ');
                    wrefresh  (riverWin);
                    wHK1      (riverWin, hk.counter[1]+5, hk.counter[3]-5, '$');
                    wrefresh  (riverWin);
                    hk.x=hk.counter[3]-5;
                    hk.y=hk.counter[1]+5;
                    hk.y0=hk.counter[1]+5;
                    hk.x0=hk.counter[3]-5;
                    hk.counter[1]++;
                    hk.counter[3]--;
                }

                if(hk.counter[4] == 2)
                {
                    wHK2      (riverWin,  hk.y, hk.x, ' ');
                    wrefresh  (riverWin);
                    wHK2      (riverWin, hk.counter[1]+5, hk.counter[3]+5, '$');
                    wrefresh  (riverWin);
                    hk.x=hk.counter[3]+5;
                    hk.y=hk.counter[1]+5;
                    hk.y0=hk.counter[1]+5;
                    hk.x0=hk.counter[3]+5;
                    hk.counter[1]++;
                    hk.counter[3]++;
                }

                wmove     (riverWin, CurentY, CurentX);

                if (hk.y>maxY+5)
                {
                    hk.counter[1]=-5;
                    hk.y0=-5;
                    hk.counter[0]=0;
                }

                if (hk.x < 5)
                {
                    wHK1 (riverWin, hk.y, hk.x, ' ');
                    hk.counter[4]=2;
                    hk.counter[1]=hk.y;
                    hk.counter[3]=hk.x;
                }
                if (hk.x > maxX -3)
                {
                    wHK2 (riverWin, hk.y, hk.x, ' ');
                    hk.counter[4]=1;
                    hk.counter[1]=hk.y;
                    hk.counter[3]=hk.x;
                }

                wmove     (riverWin, CurentY, CurentX);

          }

          if (counter % 500 == 1)   /*  HK Boomb  */
          {

              if(hk.counter[4] == 1)
              {
                  mvwaddch  (riverWin, BoombHK.y0, BoombHK.x0, ' ');
                  wrefresh  (riverWin);
                  mvwaddch  (riverWin, BoombHK.y0, BoombHK.counter[1]-1, '#');
                  wrefresh  (riverWin);

                  BoombHK.x=BoombHK.counter[1]-1;
                  BoombHK.y=BoombHK.y0;

                  wmove     (riverWin, CurentY, CurentX);

                  BoombHK.x0 =BoombHK.counter[1]-1;
                  BoombHK.counter[1]--;

                  if (BoombHK.x < -5)
                  {
                      BoombHK.counter[1]=hk.x-4;
                      BoombHK.y0=hk.y;
                      BoombHK.x0=hk.x-4;
                  }
              }

              if(hk.counter[4] == 2)
              {
                  mvwaddch  (riverWin, BoombHK.y0, BoombHK.x0, ' ');
                  wrefresh  (riverWin);
                  mvwaddch  (riverWin, BoombHK.y0, BoombHK.counter[1]+1, '#');
                  wrefresh  (riverWin);

                  BoombHK.x=BoombHK.counter[1]+4;
                  BoombHK.y=BoombHK.y0;

                  wmove     (riverWin, CurentY, CurentX);

                  BoombHK.x0 =BoombHK.counter[1]+1;
                  BoombHK.counter[1]++;

                  if (BoombHK.x > maxX+2)
                  {
                      BoombHK.counter[1]=hk.x+4;
                      BoombHK.y0=hk.y;
                      BoombHK.x0=hk.x+4;
                  }
              }


          }

          if (counter % 23000 == 1)  /*  Timer  */
          {
              wmove(infoWin,8,2);
              wclrtoeol(infoWin);
              mvwaddstr(infoWin, 8, 2, "Timer : ");
              wrefresh(infoWin);
              sec++;
              if (sec == 60)
              {
                  min++;
                  sec = 0;
              }
              mvwprintw (infoWin, 8, 10, "%d:%d", min, sec);
              wrefresh(infoWin);
          }

          if (counter % 20000 == 1)  /* Scores */
          {
              player.Score++;
              wmove(infoWin,10,10);
              wclrtoeol(infoWin);
              mvwaddstr(infoWin, 10, 2, "Score : ");
              wrefresh(infoWin);
              mvwprintw(infoWin, 10, 10, "%lld", player.Score);
              wrefresh(infoWin);
              wmove     (riverWin, CurentY, CurentX);
          }

          if (counter % 10000 == 1)  /*  Fuel  */
          {
            if (fuel.counter[0]  == 0)
            {
                      fuel.x0 = rand() % (maxX*9/10);
                      fuel.counter[0] = 1;
            }

            wFuel     (riverWin, fuel.y0, fuel.x0, ' ');
            wrefresh  (riverWin);
            wFuel     (riverWin, fuel.counter[1]+5, fuel.x0, 'F');
            wrefresh  (riverWin);

            fuel.x=fuel.x0;
            fuel.y=fuel.counter[1]+5;

            wmove     (riverWin, CurentY, CurentX);

            fuel.y0=fuel.counter[1]+5;
            fuel.counter[1]++;

            if (fuel.y > maxY+5)
            {
                fuel.y0=-10;
                fuel.counter[1]=-10;
                fuel.counter[0]=0;
            }

          }

          if (counter % 200000 == 1)  /* Fuel Progress */
          {
              wmove(infoWin,5,2);
              wclrtoeol(infoWin);
              int u=0;
              mvwaddstr(infoWin, 5,2, "Fuel : ");
              wattron(infoWin, COLOR_PAIR(9));
              for(u=0; u<n; u++)
                  mvwaddch(infoWin, 5, u+9, Progresss[u]);
              wrefresh(infoWin);
              wattroff(infoWin, COLOR_PAIR(9));
              n--;
              if (n == -1)
              {
                  Mix_PlayMusic(ShipDestroyMusic, -0);
                  int aa = wLose (riverWin, maxY/2, maxX/2);
                  if (aa == 0) break;
              }
              wmove     (riverWin, CurentY, CurentX);
          }

          int a = 0;
          a = Plane_VS_Fuel   (plane.y, plane.x, fuel.y, fuel.x);
          if (a==1)
          {
              wFuel (riverWin, fuel.y, fuel.x, ' ');
              fuel.y0=-10;
              fuel.counter[1]=-10;
              fuel.counter[0]=0;
              n=11;
              wmove     (riverWin, CurentY, CurentX);
          }

          int z = 0;
          z = plane_VS_ships (plane.y, plane.x, ship[0].y, ship[0].x,
                              ship[1].y, ship[1].x, ship[2].y, ship[2].x);
          if (z==1)
          {
              Mix_PlayMusic(LoseMusic, -0);
              int aa = wLose (riverWin, maxY/2, maxX/2);
              if (aa == 0) break;
          }

          int v = 0;
          v = plane_VS_island (plane.y, plane.x, island[0].y, island[0].x, island[1].y, island[1].x);
          if (v==1 )
          {
              Mix_PlayMusic(LoseMusic, -0);
              int aa = wLose (riverWin, maxY/2, maxX/2);
              if (aa == 0) break;
          }

          int d = 0;
          d = plane_VS_hk (plane.y, plane.x, hk.y, hk.x, hk.counter[4]);
          if (d == 1)
          {
              Mix_PlayMusic(LoseMusic, -0);
              int aa = wLose (riverWin, maxY/2, maxX/2);
              if (aa == 0) break;
          }

          int s = 0;
          s = Plane_VS_Boombs (plane.y, plane.x, BoombShip[0].y, BoombShip[0].x, BoombShip[1].y,
                               BoombShip[1].x, BoombShip[2].y, BoombShip[2].x, BoombHK.y, BoombHK.x);
          if (s==1 )
          {
               Mix_PlayMusic(LoseMusic, -0);
               int aa = wLose (riverWin, maxY/2, maxX/2);
               if (aa == 0) break;
          }

          int w = 0;
          w = PlaneBoombs_VS_Things (BoombPlane.y, BoombPlane.x, ship[0].y, ship[0].x,
                                     ship[1].y, ship[1].x, ship[2].y, ship[2].x, hk.y, hk.x, hk.counter[4]);
          if (w==1 || w==2 || w==3)
          {

              Mix_PlayMusic(ShipDestroyMusic, -0);

              wShip (riverWin, ship[w-1].y, ship[w-1].x, ' ');
              ship[w-1].counter[1]=-5;
              ship[w-1].y0=-5;
              ship[w-1].counter[0]=0;

              mvwaddch(riverWin, BoombPlane.y, BoombPlane.x, ' ');
              BoombPlane.y=-100;
              BoombPlane.x=-100;
              BoombPlane.counter[0]=1;

              wmove     (riverWin, CurentY, CurentX);
          }

          else if (w==4)
          {

              Mix_PlayMusic(HKDestroyMusic, -0);

              wHK1 (riverWin, hk.y, hk.x, ' ');
              hk.counter[1]=-5;
              hk.y0=-5;
              hk.counter[0]=0;

              mvwaddch(riverWin, BoombPlane.y, BoombPlane.x, ' ');
              BoombPlane.y=-100;
              BoombPlane.x=-100;
              BoombPlane.counter[0]=1;

              wmove     (riverWin, CurentY, CurentX);
          }

          ch = wgetch(riverWin);

          if(ch == KEY_UP && plane.counter[0] == 0)
          {
              BoombPlane.x0 = plane.x;
              BoombPlane.y0 = plane.y-3;
              BoombPlane.counter[1] = BoombPlane.y0;
              plane.counter[0]=1;
          }

          if (ch == KEY_RIGHT)
          {
                wPlane(riverWin,CurentY,CurentX,' ');
                wPlane(riverWin,CurentY,CurentX+5,'*');
                plane.x=CurentX+5;
                plane.y=CurentY;
                wrefresh(riverWin);
                if(plane.x == maxX -1)
                {
                    Mix_PlayMusic(LoseMusic, -0);
                    int aa = wLose (riverWin, maxY/2, maxX/2);
                    if (aa == 0) break;
                }
          }

          if (ch == KEY_LEFT)
          {
                  wPlane(riverWin,CurentY,CurentX,' ');
                  wPlane(riverWin,CurentY,CurentX-5,'*');
                  plane.x=CurentX-5;
                  plane.y=CurentY;
                  wrefresh(riverWin);
                  if(plane.x == 0)
                  {
                      Mix_PlayMusic(LoseMusic, -0);
                      int aa = wLose (riverWin, maxY/2, maxX/2);
                      if (aa == 0) break;
                  }
          }

          if (ch == KEY_BACKSPACE)
          {
              char gh;
              mvwaddstr(helpWin, 5,5,"Coutinoue Press c");
              mvwaddstr(helpWin, 6,5,"Exit Press Enter");
              keypad(helpWin,TRUE);
              noecho();
              gh = wgetch(helpWin);
              if(gh == '\n')
                break;
              keypad(helpWin,FALSE);
          }

          counter++;

      }

  FILE  *SaveScores;
  SaveScores = fopen ("Scores.bin","ab"); 		    	/* "ab" Is Short For "Attend Bainary" */
  fprintf (SaveScores, "%s\t%lld\n", player.name, player.Score);	/* Write Score To The File */
  fclose  (SaveScores);					/* Close The File */

}

void High_Score (void)    /* Read Scores From The File, Sort It And Show It */
{
    clear();
    bkgd(COLOR_PAIR(6));
    refresh();

    int i,j; /* Used in Loops */

    FILE *SaveScores;
    SaveScores = fopen ("Scores.bin","rb");   /* Read From Bianary File */
    if (SaveScores == NULL)
    {
        addstr("There Is No Score To Show Press Any Key To Go ...");
        refresh();
        napms(2000);
        getch();
    }

    else
    {
        printw("Scores (Sorted) : \n\n");

        Player Players[20];

        for(i=0; i<20; i++)
        {
            strcpy (Players[i].name, " ");
            Players[i].Score = -1;
        }

        for(i=0; i<20; i++)
        {
            fscanf(SaveScores, "%s\t", Players[i].name);	/* Read Names From The File */
            fscanf(SaveScores, "%lld\n", &Players[i].Score);    /* Read Scores From The File */
        }

        bubbleSort(Players, 10);				/* Sort */

        for (j=19; j>=0; j--)
        {
            if (Players[j].Score != -1)
            {
                printw("%s : ",  Players[j].name);		/* Print Names */
                printw("%lld\n\n", Players[j].Score);		/* Print Scores */
            }
        }


        refresh();
        fclose(SaveScores);				/* Close File */
        getch();
    }

}

void How_To_Play (void)   /* A Users Gudie To Play The Game */
{
  clear();
  bkgd(COLOR_PAIR(1));

  wText_Style_1(stdscr ,6,5,"Up Arrow : Shoot");

  wText_Style_1(stdscr ,8,5,"Right Arrow : Move Plane Right");

  wText_Style_1(stdscr ,10,5,"Left Arrow : Move Plane Left");

  wText_Style_1(stdscr ,12,5,"Backspace : Pause The Game ");

  wText_Style_1(stdscr ,14,5,"Note1 : Game Has Sounds, Turn on Audio Device");

  wText_Style_1(stdscr ,16,5,"Note2 : You Have To Make Terminal Full Screen");

  wText_Style_1(stdscr ,20,5,"Press Any Key To Go To The Main Menu");

  refresh();
  getch();

}

void About (void)         /* Introduice The Programmer */
{
    clear();
    bkgd(COLOR_PAIR(4));

    attron(COLOR_PAIR(1));
    wText_Style_1(stdscr ,5,5,"River Raid v1.0");
    refresh();
    napms(300);
    attroff(COLOR_PAIR(1));

    wText_Style_1(stdscr ,8,5,"Developer : ");
    refresh();
    napms(500);

    attron(A_BOLD);
    wText_Style_1(stdscr ,8,17,"Mortaza Seydi");
    refresh();
    napms(500);
    attroff(A_BOLD);

    wText_Style_1(stdscr ,8,30," - Zanjan University - Fall 2017");
    refresh();
    napms(500);

    wText_Style_1(stdscr ,11,5,"   GitHub : github.com/Mortaza-Seydi");
    refresh();
    napms(500);

    wText_Style_1(stdscr ,15,5,"Press Any Key To Go To Main Menu");
    refresh();
    getch();

}

void Exit_Page (void)     /* Exit From The Game */
{
    endwin();             /* Exit From Ncurse */
    exit(0);              /* Exit From Program */
}

/*     The End     */

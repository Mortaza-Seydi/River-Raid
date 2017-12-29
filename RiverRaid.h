#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Structs That Used In Game */

typedef struct
{
    char name[10];
    unsigned long long int Score;
}   Player ;

typedef struct
{
    int x, x0;
    int y, y0;
    unsigned long long int counter[6];
}   Things ;

typedef struct
{
    int y;
    int x;
}   YXPosition ;

/* Print Functions */

void  wIsland     (WINDOW *win, int y, int x, char ch) /* Print Islands */
{
    if (ch != ' ')
        wattron(win,COLOR_PAIR(10));

    mvwaddch(win, y-3, x, ch);
    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);
    mvwaddch(win, y+3, x, ch);
    mvwaddch(win, y+4, x, ch);

    mvwaddch(win, y-2, x+1, ch);
    mvwaddch(win, y-1, x+1, ch);
    mvwaddch(win, y,   x+1, ch);
    mvwaddch(win, y+1, x+1, ch);
    mvwaddch(win, y+2, x+1, ch);
    mvwaddch(win, y+3, x+1, ch);

    mvwaddch(win, y-2, x-1, ch);
    mvwaddch(win, y-1, x-1, ch);
    mvwaddch(win, y,   x-1, ch);
    mvwaddch(win, y+1, x-1, ch);
    mvwaddch(win, y+2, x-1, ch);
    mvwaddch(win, y+3, x-1, ch);

    mvwaddch(win, y-1, x-2, ch);
    mvwaddch(win, y,   x-2, ch);
    mvwaddch(win, y+1, x-2, ch);
    mvwaddch(win, y+2, x-2, ch);

    mvwaddch(win, y-1, x+2, ch);
    mvwaddch(win, y,   x+2, ch);
    mvwaddch(win, y+1, x+2, ch);
    mvwaddch(win, y+2, x+2, ch);

    mvwaddch(win, y,   x+3, ch);
    mvwaddch(win, y+1, x+3, ch);

    mvwaddch(win, y,   x-3, ch);
    mvwaddch(win, y+1, x-3, ch);
    wattroff(win,COLOR_PAIR(10));

    wmove (win,y,x);

}

void  wFuel       (WINDOW *win, int y, int x, char ch) /* Print Fuel */
{

    if (ch != ' ')
      wattron (win, COLOR_PAIR(8)|A_REVERSE);

    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);

    wattroff(win, COLOR_PAIR(8)|A_REVERSE);

    wmove(win, y, x);

}

void  wHK2        (WINDOW *win, int y, int x, char ch) /* Print Helicopter Type 2 */
{

    mvwaddch(win, y-3, x, ch);
    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);

    mvwaddch(win, y-2, x+1, ch);
    mvwaddch(win, y-1, x+1, ch);
    mvwaddch(win, y,   x+1, ch);
    mvwaddch(win, y+1, x+1, ch);
    mvwaddch(win, y+2, x+1, ch);

    mvwaddch(win, y-2, x-1, ch);
    mvwaddch(win, y-1, x-1, ch);
    mvwaddch(win, y,   x-1, ch);
    mvwaddch(win, y+1, x-1, ch);
    mvwaddch(win, y+2, x-1, ch);

    mvwaddch(win, y-1, x-2, ch);
    mvwaddch(win, y,   x-2, ch);
    mvwaddch(win, y+1, x-2, ch);
    mvwaddch(win, y+2, x-2, ch);

    mvwaddch(win, y-1, x+2, ch);
    mvwaddch(win, y,   x+2, ch);
    mvwaddch(win, y+1, x+2, ch);
    mvwaddch(win, y+2, x+2, ch);

    mvwaddch(win, y,   x+3, ch);
    mvwaddch(win, y+1, x+3, ch);

    mvwaddch(win, y,   x-3, ch);
    mvwaddch(win, y+1, x-3, ch);

    mvwaddch(win, y,   x-4, ch);
    mvwaddch(win, y+1, x-4, ch);

    mvwaddch(win, y,   x-5, ch);
    mvwaddch(win, y+1, x-5, ch);

    mvwaddch(win, y,   x-6, ch);
    mvwaddch(win, y+1, x-6, ch);

    mvwaddch(win, y,   x-7, ch);
    mvwaddch(win, y+1, x-7, ch);

    mvwaddch(win, y-1, x-8, ch);
    mvwaddch(win, y,   x-8, ch);
    mvwaddch(win, y+1, x-8, ch);

    mvwaddch(win, y-1, x-9, ch);
    mvwaddch(win, y,   x-9, ch);
    mvwaddch(win, y+1, x-9, ch);

    wmove (win,y,x);

}

void  wHK1        (WINDOW *win, int y, int x, char ch) /* Print Helicopter Type 1 */
{

    mvwaddch(win, y-3, x, ch);
    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);

    mvwaddch(win, y-2, x+1, ch);
    mvwaddch(win, y-1, x+1, ch);
    mvwaddch(win, y,   x+1, ch);
    mvwaddch(win, y+1, x+1, ch);
    mvwaddch(win, y+2, x+1, ch);

    mvwaddch(win, y-2, x-1, ch);
    mvwaddch(win, y-1, x-1, ch);
    mvwaddch(win, y,   x-1, ch);
    mvwaddch(win, y+1, x-1, ch);
    mvwaddch(win, y+2, x-1, ch);

    mvwaddch(win, y-1, x-2, ch);
    mvwaddch(win, y,   x-2, ch);
    mvwaddch(win, y+1, x-2, ch);
    mvwaddch(win, y+2, x-2, ch);

    mvwaddch(win, y+1, x-3, ch);
    mvwaddch(win, y,   x-3, ch);

    mvwaddch(win, y-1, x+2, ch);
    mvwaddch(win, y,   x+2, ch);
    mvwaddch(win, y+1, x+2, ch);
    mvwaddch(win, y+2, x+2, ch);

    mvwaddch(win, y,   x+3, ch);
    mvwaddch(win, y+1, x+3, ch);

    mvwaddch(win, y,   x+4, ch);
    mvwaddch(win, y+1, x+4, ch);

    mvwaddch(win, y,   x+5, ch);
    mvwaddch(win, y+1, x+5, ch);

    mvwaddch(win, y,   x+6, ch);
    mvwaddch(win, y+1, x+6, ch);

    mvwaddch(win, y,   x+7, ch);
    mvwaddch(win, y+1, x+7, ch);

    mvwaddch(win, y-1, x+8, ch);
    mvwaddch(win, y,   x+8, ch);
    mvwaddch(win, y+1, x+8, ch);

    mvwaddch(win, y-1, x+9, ch);
    mvwaddch(win, y,   x+9, ch);
    mvwaddch(win, y+1, x+9, ch);

    wmove (win,y,x);

}

void  wShip       (WINDOW *win, int y, int x, char ch) /* Print Ship */
{

    mvwaddch(win, y-3, x, ch);
    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);

    mvwaddch(win, y-2, x+1, ch);
    mvwaddch(win, y-1, x+1, ch);
    mvwaddch(win, y,   x+1, ch);
    mvwaddch(win, y+1, x+1, ch);
    mvwaddch(win, y+2, x+1, ch);

    mvwaddch(win, y-2, x-1, ch);
    mvwaddch(win, y-1, x-1, ch);
    mvwaddch(win, y,   x-1, ch);
    mvwaddch(win, y+1, x-1, ch);
    mvwaddch(win, y+2, x-1, ch);

    mvwaddch(win, y-1, x+2, ch);
    mvwaddch(win, y,   x+2, ch);
    mvwaddch(win, y+1, x+2, ch);
    mvwaddch(win, y+2, x+2, ch);

    mvwaddch(win, y-1, x-2, ch);
    mvwaddch(win, y,   x-2, ch);
    mvwaddch(win, y+1, x-2, ch);
    mvwaddch(win, y+2, x-2, ch);

    mvwaddch(win, y,   x-3, ch);
    mvwaddch(win, y,   x+3, ch);
    mvwaddch(win, y+1, x-3, ch);
    mvwaddch(win, y+1, x+3, ch);

    mvwaddch(win, y+1, x-4, ch);
    mvwaddch(win, y+1, x+4, ch);
    mvwaddch(win, y,   x-4, ch);
    mvwaddch(win, y,   x+4, ch);

    wmove(win,y,x);

}

void  wPlane      (WINDOW *win, int y, int x, char ch) /* Print Plane */
{

    mvwaddch(win, y-2, x, ch);
    mvwaddch(win, y-1, x, ch);
    mvwaddch(win, y,   x, ch);
    mvwaddch(win, y+1, x, ch);
    mvwaddch(win, y+2, x, ch);
    mvwaddch(win, y+3, x, ch);

    mvwaddch(win, y-1, x+1, ch);
    mvwaddch(win, y,   x+1, ch);
    mvwaddch(win, y+1, x+1, ch);
    mvwaddch(win, y+3, x+1, ch);

    mvwaddch(win, y-1, x-1, ch);
    mvwaddch(win, y,   x-1, ch);
    mvwaddch(win, y+1, x-1, ch);
    mvwaddch(win, y+3, x-1, ch);

    mvwaddch(win, y,   x-2, ch);
    mvwaddch(win, y+1, x-2, ch);

    mvwaddch(win ,y,   x+2, ch);
    mvwaddch(win, y+1, x+2, ch);

    mvwaddch(win, y,   x-3, ch);
    mvwaddch(win, y+1, x-3, ch);

    mvwaddch(win, y,   x+3, ch);
    mvwaddch(win, y+1, x+3, ch);

    wmove(win,y,x);

}

/**********************************************************************************/

/* Functoins That Returns The Coordinates of Things */

void  Fuelyx      (YXPosition *a, int y, int x) /* Returns The Coordinates of Fuels */
{

      a[0].x=x;
      a[0].y=y-2;

      a[1].x=x;
      a[1].y=y-1;

      a[2].x=x;
      a[2].y=y;

      a[3].x=x;
      a[3].y=y+1;

      a[4].x=x;
      a[4].y=y+2;

}

void  HK1yx       (YXPosition *a, int y, int x) /* Returns The Coordinates of Helicopter Type 1 */
{

      a[0].x=x;
      a[0].y=y-3;

      a[1].x=x;
      a[1].y=y+2;

      a[2].x=x+1;
      a[2].y=y-2;

      a[3].x=x+1;
      a[3].y=y+2;

      a[4].x=x-1;
      a[4].y=y-2;

      a[5].x=x-1;
      a[5].y=y+2;

      a[6].x=x+2;
      a[6].y=y-1;

      a[7].x=x-2;
      a[7].y=y-1;

      a[8].x=x+2;
      a[8].y=y+1;

      a[9].x=x-2;
      a[9].y=y+1;

      a[10].x=x+3;
      a[10].y=y;

      a[11].x=x-3;
      a[11].y=y;

      a[12].x=x+4;
      a[12].y=y;

      a[13].x=x+5;
      a[13].y=y;

      a[14].x=x+3;
      a[14].y=y+1;

      a[15].x=x-3;
      a[15].y=y+1;

      a[16].x=x+4;
      a[16].y=y+1;

      a[17].x=x+5;
      a[17].y=y+1;

      a[18].x=x+6;
      a[18].y=y+1;

      a[19].x=x+6;
      a[19].y=y;

      a[20].x=x+7;
      a[20].y=y;

      a[21].x=x+7;
      a[21].y=y+1;

      a[22].x=x+8;
      a[22].y=y;

      a[23].x=x+8;
      a[23].y=y+1;

      a[24].x=x+8;
      a[24].y=y-1;

      a[25].x=x+9;
      a[25].y=y;

      a[26].x=x+9;
      a[26].y=y+1;

      a[27].x=x+9;
      a[27].y=y-1;

}

void  HK2yx       (YXPosition *a, int y, int x) /* Returns The Coordinates of Helicopter Type 2 */
{

      a[0].x=x;
      a[0].y=y-3;

      a[1].x=x;
      a[1].y=y+2;

      a[2].x=x+1;
      a[2].y=y-2;

      a[3].x=x+1;
      a[3].y=y+2;

      a[4].x=x-1;
      a[4].y=y-2;

      a[5].x=x-1;
      a[5].y=y+2;

      a[6].x=x+2;
      a[6].y=y-1;

      a[7].x=x-2;
      a[7].y=y-1;

      a[8].x=x+2;
      a[8].y=y+2;

      a[9].x=x-2;
      a[9].y=y+2;

      a[10].x=x+3;
      a[10].y=y;

      a[11].x=x-3;
      a[11].y=y;

      a[12].x=x-4;
      a[12].y=y;

      a[13].x=x-5;
      a[13].y=y;

      a[14].x=x+3;
      a[14].y=y+1;

      a[15].x=x-3;
      a[15].y=y+1;

      a[16].x=x-4;
      a[16].y=y+1;

      a[17].x=x-5;
      a[17].y=y+1;

      a[18].x=x-6;
      a[18].y=y+1;

      a[19].x=x-6;
      a[19].y=y;

      a[20].x=x-7;
      a[20].y=y;

      a[21].x=x-7;
      a[21].y=y+1;

      a[22].x=x-8;
      a[22].y=y;

      a[23].x=x-8;
      a[23].y=y+1;

      a[24].x=x-8;
      a[24].y=y-1;

      a[25].x=x-9;
      a[25].y=y;

      a[26].x=x-9;
      a[26].y=y+1;

      a[27].x=x-9;
      a[27].y=y-1;

}

void  Shipyx      (YXPosition *a, int y, int x) /* Returns The Coordinates of Ship */
{

      a[0].x=x;
      a[0].y=y-3;

      a[1].x=x+1;
      a[1].y=y-2;

      a[2].x=x-1;
      a[2].y=y-2;

      a[3].x=x+2;
      a[3].y=y-1;

      a[4].x=x-2;
      a[4].y=y-1;

      a[5].x=x+3;
      a[5].y=y;

      a[6].x=x-3;
      a[6].y=y;

      a[7].x=x+4;
      a[7].y=y;

      a[8].x=x-4;
      a[8].y=y;

      a[9].x=x+3;
      a[9].y=y+1;

      a[10].x=x-3;
      a[10].y=y+1;

      a[11].x=x+4;
      a[11].y=y+1;

      a[12].x=x-4;
      a[12].y=y+1;

      a[13].x=x+1;
      a[13].y=y+2;

      a[14].x=x-1;
      a[14].y=y+2;

      a[15].x=x;
      a[15].y=y+2;

      a[16].x=x+2;
      a[16].y=y+2;

      a[17].x=x-2;
      a[17].y=y+2;

}

void  Planeyx     (YXPosition *a, int y, int x) /* Returns The Coordinates of Plane */
{

      a[0].x=x;
      a[0].y=y-2;

      a[1].x=x+1;
      a[1].y=y-1;

      a[2].x=x-1;
      a[2].y=y-1;

      a[3].x=x+2;
      a[3].y=y;

      a[4].x=x-2;
      a[4].y=y;

      a[5].x=x+3;
      a[5].y=y;

      a[6].x=x-3;
      a[6].y=y;

      a[7].x=x+2;
      a[7].y=y+1;

      a[8].x=x-2;
      a[8].y=y+1;

      a[9].x=x+3;
      a[9].y=y+1;

      a[10].x=x-3;
      a[10].y=y+1;

      a[11].x=x-1;
      a[11].y=y+3;

      a[12].x=x;
      a[12].y=y+3;

      a[13].x=x+1;
      a[13].y=y+3;

}

void  Islandyx    (YXPosition *a, int y, int x) /* Returns The Coordinates of Island */
{

      a[0].x=x;
      a[0].y=y-3;

      a[1].x=x+1;
      a[1].y=y-2;

      a[2].x=x-1;
      a[2].y=y-2;

      a[3].x=x+2;
      a[3].y=y-1;

      a[4].x=x-2;
      a[4].y=y-1;

      a[5].x=x+3;
      a[5].y=y;

      a[6].x=x-3;
      a[6].y=y;

      a[7].x=x+3;
      a[7].y=y+1;

      a[8].x=x-3;
      a[8].y=y+1;

      a[9].x=x+1;
      a[9].y=y+3;

      a[10].x=x-1;
      a[10].y=y+3;

      a[11].x=x;
      a[11].y=y+4;

      a[12].x=x+2;
      a[12].y=y+2;

      a[13].x=x-2;
      a[13].y=y+2;

}

/*******************************************************************************/

/* Functions That Probes Some Events */

int   plane_VS_ships    (int yplane, int xplane, int yship0, int xship0,
                         int yship1, int xship1, int yship2, int xship2) /* Probes Clash between Plane And Ship */
{

      YXPosition plane[14];
      Planeyx (plane, yplane,  xplane);  /*  14 Points */

      YXPosition ship0[18];
      Shipyx  (ship0, yship0,  xship0);   /*  18 Points */

      YXPosition ship1[18];
      Shipyx  (ship1, yship1,  xship1);   /*  18 Points */

      YXPosition ship2[19];
      Shipyx  (ship2, yship2,  xship2);   /*  18 Points */

      int i,j;

      for (i=0; i<14; i++)
      {
          for (j=0; j<18; j++)
            if (plane[i].y == ship0[j].y && plane[i].x == ship0[j].x)
                return 1;

          for (j=0; j<18; j++)
            if (plane[i].y == ship1[j].y && plane[i].x == ship1[j].x)
                return 1;

          for (j=0; j<18; j++)
            if (plane[i].y == ship2[j].y && plane[i].x == ship2[j].x)
               return 1;
      }

      return 100;
}

int   Plane_VS_Boombs   (int yplane, int xplane, int yboombship1, int xboombship1,int yboombship2,
                         int xboombship2, int yboombship3, int xboombship3, int yboombhk, int xboombhk) /* Probes Clash between Plane And Boombs From Things */
{

      YXPosition plane[14];
      Planeyx (plane, yplane,  xplane);  /*  14 Points */

      int i;

      for (i=0; i<14; i++)
      {
          if (plane[i].x == xboombship1 && plane[i].y == yboombship1)
              return 1;
          if (plane[i].x == xboombship2 && plane[i].y == yboombship2)
              return 1;
          if (plane[i].x == xboombship3 && plane[i].y == yboombship3)
              return 1;
          if (plane[i].x == xboombhk    && plane[i].y == yboombhk)
              return 1;
      }

      return 100;
}

int   Plane_VS_Fuel     (int yplane, int xplane, int yfuel, int xfuel) /* Probes Clash between Plane And Fuel */
{

    YXPosition plane[14];
    Planeyx (plane, yplane,  xplane);  /*  14 Points */

    YXPosition fuel[5];
    Fuelyx  (fuel, yfuel, xfuel);     /*  5 Points */

    int i, j;

    for (i=0; i<14; i++)
    {
        for (j=0; j<5; j++)
          if (plane[i].x == fuel[j].x && plane[i].y == fuel[j].y)
              return 1;
    }

    return 2;

}

int   PlaneBoombs_VS_Things   (int yPlaneBoomb, int xPlaneBoomb, int yship0, int xship0,
                               int yship1, int xship1, int yship2, int xship2, int yhk, int xhk, int hktype) /* Probes Clash between Plane Boomb And Things */
{

    YXPosition ship0[18];
    Shipyx  (ship0, yship0,  xship0);   /*  18 Points */

    YXPosition ship1[18];
    Shipyx  (ship1, yship1,  xship1);   /*  18 Points */

    YXPosition ship2[18];
    Shipyx  (ship2, yship2,  xship2);   /*  18 Points */

    YXPosition hk[28];
    if (hktype == 1)
    {
        HK1yx (hk, yhk,  xhk);  /*  28 Points  */
    }
    if (hktype == 2)
    {
        HK2yx (hk, yhk,  xhk);  /*  28 Points  */
    }

    int j;

    for (j=0; j<18; j++)
      if (yPlaneBoomb == ship0[j].y && xPlaneBoomb == ship0[j].x)
            return 1;

    for (j=0; j<18; j++)
      if (yPlaneBoomb == ship1[j].y && xPlaneBoomb == ship1[j].x)
           return 2;

    for (j=0; j<18; j++)
      if (yPlaneBoomb == ship2[j].y && xPlaneBoomb == ship2[j].x)
           return 3;

    for (j=0; j<28; j++)
      if (yPlaneBoomb == hk[j].y && xPlaneBoomb == hk[j].x)
             return 4;

    return 5;
}

int   plane_VS_hk       (int yplane, int xplane, int yhk, int xhk, int hktype) /* Probes Clash between Plane And Helicopter */
{

      YXPosition plane[14];
      Planeyx (plane, yplane,  xplane);  /*  14 Points  */
      YXPosition hk[28];
      if (hktype == 1)
      {
          HK1yx (hk, yhk,  xhk);  /*  28 Points  */
      }
      if (hktype == 2)
      {
          HK2yx (hk, yhk,  xhk);  /*  28 Points  */
      }

      int i,j;

      for (i=0; i<14; i++)
      {
          for (j=0; j<28; j++)
            if (plane[i].y == hk[j].y && plane[i].x == hk[j].x)
                return 1;
      }
      return 100;
}

int   plane_VS_island   (int yplane, int xplane, int yisland1, int xisland1, int yisland2, int xisland2)/* Probes Clash between Plane And Island */
{

      YXPosition plane[14];
      Planeyx (plane, yplane,  xplane);  /*  14 Points */

      YXPosition island1[14];
      Islandyx    (island1, yisland1, xisland1);

      YXPosition island2[14];
      Islandyx    (island2, yisland2, xisland2);

      int i,j;

      for (i=0; i<14; i++)
      {
          for (j=0; j<14; j++)
            if (plane[i].y == island1[j].y && plane[i].x == island1[j].x)
                return 1;

          for (j=0; j<14; j++)
            if (plane[i].y == island2[j].y && plane[i].x == island2[j].x)
                return 1;
      }

      return 100;
}

/*************************************************************************************************************/

/* Other Functoins */

void wText_Style_1    (WINDOW *win, int y, int x, char *text)  /* Prints The Text With Special Style */
{
    int i;
    move (y,x);
    for(i=0; i<(strlen(text)); i++)
    {
        waddch(win,text[i]);
        wrefresh(win);
        napms(100);
    }
}

int  wLose            (WINDOW *win, int y, int x)              /* Lose Functoin */
{

    WINDOW *loseWin;
    int ch;
    loseWin = subwin (win, 5, 25, y, x);
    wbkgd (loseWin, COLOR_PAIR(3));

    waddstr(loseWin, "\n      You Lose\n\n  Press Enter TO GO ...  \n");

    wrefresh (loseWin);
    keypad (loseWin , TRUE);
    noecho();
    do
    {

        ch = wgetch(loseWin);

    }   while (ch != '\n');

    return 0;

}

void wPause           (WINDOW *win)                            /* Pause The Game */
{

    WINDOW *PauseWin;
    PauseWin = subwin (win, 3, 3, 30, 50);
    wbkgd (PauseWin, COLOR_PAIR(3));
    box(PauseWin, '|', '-');
    wrefresh (PauseWin);

    mvwaddch(PauseWin,1,1,'3');
    wrefresh (PauseWin);
    napms(1000);

    mvwaddch(PauseWin,1,1,'2');
    wrefresh (PauseWin);
    napms(1000);

    mvwaddch(PauseWin,1,1,'1');
    wrefresh(PauseWin);
    napms(1000);

    wclear(PauseWin);
    delwin(PauseWin);
    wbkgd (win, COLOR_PAIR(6));
    wrefresh(win);

}

void  bubbleSort      (Player *a, int n)                       /* bubble Sort */
{
    int i,j;
    Player t;
    for (i=n; i>1; i--)
        for (j=0; j<=i; j++)
            if (a[j+1].Score < a[j].Score)
            {
                t.Score = a[j].Score;
                strcpy(t.name , a[j].name);

                a[j].Score = a[j+1].Score;
                strcpy(a[j].name , a[j+1].name);

                strcpy(a[j+1].name , t.name);
                a[j+1].Score = t.Score;
            }
}

/**********************************************************************/

/* The End */

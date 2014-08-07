#include <cgraphics>
#include <iostream>
#include <cstdlib>
using namespace std;

void InitGrafica() {
  int gdet = DETECT, gm, err;
  initgraph ( &gdet, &gm, "C:\\BC5\\BGI" );
  err = graphresult();
  if ( err != grOk ) {
    cout << "Eroare grafica: " << grapherrormsg ( err ) << endl;
    cout << "Apasati o tasta pentru iesire...";
    getch();
    exit ( 1 );
  }
}

void Patrat ( int x, int y, int l ) {
  if ( l > 20 ) {
    setbkcolor ( RED );
    setcolor ( GREEN );
    rectangle ( x - l / 2, y - l / 2, x + l / 2, y + l / 2 );
    Patrat ( x - l / 2, y - l / 2, l / 2 );
    Patrat ( x - l / 2, y + l / 2, l / 2 );
    Patrat ( x + l / 2, y - l / 2, l / 2 );
    Patrat ( x + l / 2, y + l / 2, l / 2 );
  }
}

void main() {
  InitGrafica();
  Patrat ( getmaxx() / 2, getmaxy() / 2, getmaxy() / 2 );
  getch();
  closegraph();
}




#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NYCFonts{
 public:
   NYCFonts(int, int, int);
   ~NYCFonts();
   void MoveLeft();
   int GetPoint();
 private:
   int size;
   int point_x; // coordinates of the left-up point
   int point_y;
};

NYCFonts::NYCFonts(int _size, int _point_x, int _point_y) :
         size(_size),
         point_x(_point_x),
         point_y(_point_y) {};

NYCFonts::~NYCFonts() {}

void NYCFonts::MoveLeft(){
  --point_x ;
}

int NYCFonts::GetPoint(){
  return point_x;
}


int main(int argc, const char *argv[])
{
  NYCFonts nycfonts(0, 200, 0);
  int i;
  while(nycfonts.GetPoint() != 0){
    for (i = 0; i < nycfonts.GetPoint(); i++) {
      std::cout << " " ;
    }
    std::cout << "Hello NYC!" << std::endl;
    nycfonts.MoveLeft();
  }
  return 0;
}

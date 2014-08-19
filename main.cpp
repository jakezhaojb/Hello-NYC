// Produced by Jake Zhao, when first arriving United States.
// ********************************************************
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <sys/ioctl.h>

using namespace std;

// strech length
int g_length = 100;

void wait(long m){
  long timeout = clock() + m;
  while(clock() < timeout){
    continue;
  }
}

string strech(string msg, int Llen = 0, int Rlen = g_length){
  string _msg, Ltemp, Rtemp;
  for (int i = 0; i < Llen; i++) {
    Ltemp += "\\ ";
  }
  //for (int i = 0; i < Rlen; i++) {
  //  Rtemp += "\\ ";
  //}
  //Ltemp.assign(Llen, "\ ");
  Rtemp.assign(Rlen, ' ');
  _msg = Ltemp + msg + Rtemp;
  return _msg;
}


int main(int argc, const char *argv[])
{
  // Get the console width.
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  g_length = w.ws_col; // strech limitation set up.

  std::cout << g_length << std::endl;
  string nyc = "Hello NYC!";
  string font_tool = "figlet ";
  int x = 0;
  while(x < g_length - 25){
    //std::cout << strech(nyc, x, g_length-x) << std::endl;
    system((font_tool + strech(nyc, x, g_length-x)).c_str());
    wait(50000);
    system("clear");
    x ++;
  }
  return 0;
}

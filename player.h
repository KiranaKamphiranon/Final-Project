#include <iostream>
//#include <iomanip>
#include "rdom.h"
using namespace std;

class player:public rdom
{
  string name;
  int meters,your_energy,coin;
public :
  player(string,int,int,int);//name,meters,your_energy,coin
  ~player();
  void show_player();
  void foodmarket();
  void get_coin();
  int random_activities();
  //int met_player(player);
  int met_player();
  int energy_player();
  void change_name(string);
  string name_player();
};

//meters

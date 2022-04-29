#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <exception> 
#include <string.h>
#include "color.h"
#include "player.h"
#include "interface.h"
#include "trycatch.h"

using namespace std;

int a = 1000;
int main() // AE wingdi AE
{
  srand(time(NULL));
  string name1, name2;
  my_cin myex;
  check_mycin myex1;
  int choose_menu = 0, checkerr;
  int checkmet = 0, turn = 1; //เลือกเมนู
  do 
  {
    player p1(name1, 0, a, 0), p2(name2, 0, 1000, 0);
    cout << "\033[0;0H\033[2J";
    menu();
    choose_menu = 0;
    do{
      checkerr=0;
      try
      {
        cout << endl << BHGRN << "\tCHOOSE MENU -> " << reset;
        cin >> choose_menu;
        if(cin.fail()){//ตัวอักษร
          cout << "\033[0;0H\033[2J";
          menu();
          throw myex;
        }
        if (choose_menu < 1 || choose_menu > 3)//ตัวเลข
        {
          cout << "\033[0;0H\033[2J";
          menu();
          throw myex1;
        }
      }
      catch(exception &e)
      {
        cout<<BRED<<e.what()<<reset;
        cout<<endl;
        cin.clear();// error 
        cin.ignore(50,'\n');
        checkerr=1;
      }
    }while(checkerr==1);
    if (choose_menu == 1) 
    {
      cout << "\033[0;0H\033[2J";
      do 
      {
        cout << BLKB << BHCYN << "Input player1's name : " << reset << reset;
        cin >> name1;
        if (strlen(name1.c_str()) > 10) 
        {
          cout << "\033[0;0H\033[2J";
          cout << BRED << "------Name Length is limited [10]------" << reset << endl;
        }
      } while (strlen(name1.c_str()) > 10);
      p1.change_name(name1);
      do
      {
        cout << BLKB << BHYEL << "Input player2's name : " << reset << reset;
        cin >> name2;
        if (strlen(name2.c_str()) > 10) 
        {
          cout << "\033[0;0H\033[2J";
          cout << BRED << "------Name Length is limited [10]------" << reset<< endl;
        }
      } while (strlen(name2.c_str()) > 10);
      p2.change_name(name2);
      while (checkmet == 0) 
      {
        if (turn == 1) 
        {
          checkmet = start_player1(&p1, &p2);
          turn++;
        } else {
          checkmet = start_player2(&p1, &p2);
          turn--;
        }
      }
      do 
      {
        if (checkmet != 1) 
        {
          cout << "\033[0;0H\033[2J";
          cout << endl << "\t\t";
        }
        cout << BHRED << "\tClick [1] to go back HOME -> " << reset;
        cin >> checkmet;
      } while (checkmet != 1);
      checkmet = 0;
      turn = 1;
    } else if (choose_menu == 2) 
    {
      how2play();
    } else if (choose_menu == 3) 
    {
      cout << "\033[0;0H\033[2J";
      cout << BLK << WHTB << "                                                "<< reset << endl;
      cout << BRED << WHTB << "                 EEEEE XX  XX IIIII TTTTT  0    "<< endl;
      cout << "                 EEEEE   XX     I     T      (  " << endl;
      cout << "                 EEEEE XX  XX   I     T    0    " << endl;
      cout << BBLK << WHTB << "                                                "<< endl;
      cout << BBLK << WHTB << "      # # # # #                                 "<< endl;
      cout << BBLK << WHTB << "    #           #                               "<< endl;
      cout << BBLK << WHTB << "   #    >    <   #                              "<< endl;
      cout << BBLK << WHTB << "  #       /\\      #"<< "       BYE BYE               " << endl;
      cout << BBLK << WHTB << "   #   3         # 3                            "<< endl;
      cout << BBLK << WHTB << "    #           #                               "<< endl;
      cout << BBLK << WHTB << "      # # # # #                                 "<< reset << endl;
      cout << BBLK << WHTB << "                                                "<< reset << endl;
    }
  } while (choose_menu != 3);
}

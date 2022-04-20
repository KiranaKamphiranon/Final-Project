#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
#include "color.h"
#include "player.h"

void menu();
void action();
void how2play();
int start_player1(player *, player *);
int start_player2(player *, player *);
void output(player, player);
int who_win(player, player);

int a = 1000;
int main() // AE wingdi AE
{
  srand(time(NULL));
  string name1, name2;
  int choose_menu = 0;
  int checkmet = 0, turn = 1; //เลือกเมนู
  do {
    player p1(name1, 0, a, 0), p2(name2, 0, 1000, 0);
    cout << "\033[0;0H\033[2J";
    menu();
    choose_menu = 0;
    cout <<endl << BHGRN << "\tCHOOSE MENU -> " << reset;
    cin >> choose_menu;
    while (choose_menu < 1 || choose_menu > 3) {
      cout << "\033[0;0H\033[2J";
      menu();
      cout<<endl<<BRED << "\tInput again!!! -> "<<reset;
      cin >> choose_menu;
    }
    if (choose_menu == 1) {
      cout << "\033[0;0H\033[2J";
      do{
      cout << BLKB << BHCYN << "Input player1's name : " << reset << reset;
      cin >> name1;
      if (strlen(name1.c_str())>10)
      {
        cout << "\033[0;0H\033[2J";
        cout<<BRED<<"------Name Length is limited [10]------"<<reset<<endl;
        }
      }while(strlen(name1.c_str())>10);
      p1.change_name(name1);
      
      do{
      cout << BLKB << BHYEL << "Input player2's name : " << reset << reset;
      cin >> name2;
       if (strlen(name2.c_str())>10)
      {
        cout << "\033[0;0H\033[2J";
        cout<<BRED<<"------Name Length is limited [10]------"<<reset<<endl;
        }
      }while(strlen(name2.c_str())>10);
      p2.change_name(name2);
      // player p1(name1,0,a,0),p2(name2,0,1000,0);
      // p1(name1);
      // srand(time(NULL)); //สุ่มค่า
      // num=rand()%100;
      while (checkmet == 0) {
        if (turn == 1) {
          checkmet = start_player1(&p1, &p2);
          turn++;
        } else {
          checkmet = start_player2(&p1, &p2);
          turn--;
        }
      }
      do {
        if (checkmet != 1) {
          cout << "\033[0;0H\033[2J";
          cout << endl << "\t\t";
        }
        cout << BHRED << "\tClick [1] to go back HOME -> " << reset;
        cin >> checkmet;
      } while (checkmet != 1);
      checkmet = 0;
      turn = 1;
    } else if (choose_menu == 2) {
      how2play();
    } else if (choose_menu == 3) {
      cout << "\033[0;0H\033[2J";
      cout<<BLK<<WHTB<<"                                                "<<reset<<endl;
      cout <<BRED<<WHTB<<"                 EEEEE XX  XX IIIII TTTTT  0    " << endl;
                cout << "                 EEEEE   XX     I     T      (  " << endl;
      cout <<"                 EEEEE XX  XX   I     T    0    " << endl;
      cout<<BBLK<<WHTB<<"                                                " << endl;
      cout<<BBLK<<WHTB<<"      # # # # #                                 "<<endl;
      cout<<BBLK<<WHTB<<"    #           #                               "<<endl;
      cout<<BBLK<<WHTB<<"   #    >    <   #                              "<<endl;
      cout<<BBLK<<WHTB<<"  #       /\\      #"<<"       BYE BYE               "<<endl;
      cout<<BBLK<<WHTB<<"   #   3         # 3                            "<<endl;
      cout<<BBLK<<WHTB<<"    #           #                               "<<endl;
      cout<<BBLK<<WHTB<<"      # # # # #                                 "<<reset<<endl;
       cout<<BBLK<<WHTB<<"                                                "<<reset<<endl;
    }
  } while (choose_menu != 3);
}

void menu() {
  cout <<WHTHB
       << "                                                        " << endl;
  cout << BBLK << "    A   ";
  cout << BBLU << "EEEEE  ";
  cout << BBLK << "W W W ";
  cout << BBLU << "I ";
  cout << BBLK << "NN  N ";
  cout << BBLU << "GGGGG ";
  cout << BBLK << "DDD  ";
  cout << BBLU << "I    ";
  cout << BBLK << "A   ";
  cout << BBLU << "EEEEE  " << endl;
  cout << BBLK << "   AAA  ";
  cout << BBLU << "EEEEE  ";
  cout << BBLK << "WW WW ";
  cout << BBLU << "I ";
  cout << BBLK << "N N N ";
  cout << BBLU << "G GGG ";
  cout << BBLK << "D  D ";
  cout << BBLU << "I   ";
  cout << BBLK << "AAA  ";
  cout << BBLU << "EEEEE  " << endl;
  cout << BBLK << "  A   A ";
  cout << BBLU << "EEEEE  ";
  cout << BBLK << "W   W ";
  cout << BBLU << "I ";
  cout << BBLK << "N  NN ";
  cout << BBLU << "GGGGG ";
  cout << BBLK << "DDD  ";
  cout << BBLU << "I  ";
  cout << BBLK << "A   A ";
  cout << BBLU << "EEEEE  " << endl;
  cout<<WHTHB<< "                                                        "<< endl;
  cout<<REDB <<"                                                        "<< endl;
  cout<<BHWHT<<"      [1] Start      [2] How to play     [3] Exit       "  <<endl;
  cout << "                                                        " <<reset <<reset<< endl;
}

void how2play() {
  int choose_h2p = 1, choose_h2p2 = 0;
  do {
    choose_h2p2 = 0;
    cout << "\033[0;0H\033[2J";
    cout << "=================================================================="
            "==="
         << endl;
    cout << WHTB << BBLK
         << "                          H O W   T O   P L A Y                   "
            "   "
         << reset << reset << endl;
    cout << "=================================================================="
            "==="
         << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 1. Input Player 1 name and Player 2 name.                       "
            "  |"
         << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 2. Start at Player 1 and then swap tp Player 2 turn by turn.    "
            "  |"
         << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 3. Your first stats have 1000 Energy and 0 coin.                "
            "  |"
         << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 4. When start he game. You can choose 3 action.                 "
            "  |"
         << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 5." << HCYN << " 'Choose a dice' " << reset
         << "is choose number 1-6 for move.                 |" << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 6." << HCYN << " 'Food market' " << reset
         << "is a shop that you can buy food for your energy. |" << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 7." << HCYN << " 'Turn skip' " << reset
         << "is skip to next player.                            |" << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 8. You'll lost energy = " <<HMAG<< "number of dice * activity" << reset <<" in each turn.   |"<<endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 9. If you can do 20/20 METERS and more than 0 " << HGRN
         << "YOU WIN" << reset << "             |" << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "| 10. If your Energy less than 0 or equal 0 " << RED << "YOU LOSE"
         << reset << "                |" << endl;
    cout << "|                                                                 "
            "  |"
         << endl;
    cout << "=================================================================="
            "==="
         << endl;
    cout << "\t[0] Back to menu \t[2] Read Activities  ";
    cout << "--> ";
    cin >> choose_h2p;
    while (choose_h2p == 2 && choose_h2p2 != 1) {
      cout << "\033[0;0H\033[2J";
      cout << "======================================" << endl;
      cout << WHTB << BBLK << "         A C T I V I T I E S          " << reset
           << reset << endl;
      cout << "======================================" << endl;
      cout << "| 0,9  Walk                  50      |" << endl;
      cout << "|  1   Run                   90      |" << endl;
      cout << "|  2   Drive car             70      |" << endl;
      cout << "|  3   Roll                  40      |" << endl;
      cout << "|  4   Jump                  95      |" << endl;
      cout << "|  5   Ride a bike          100      |" << endl;
      cout << "|  6   Fly an airplane      200      |" << endl;
      cout << "|  7   Use balloon           15      |" << endl;
      cout << "|  8   Ride a motorcycle     72      |" << endl;
      cout << "======================================" << endl;
      cout << "\t[1] back";
      cout << "  --> ";
      cin >> choose_h2p2;
    }
  } while (choose_h2p != 0);
}

void output(player p1, player p2) {
  cout << "===================================================" << endl;
  cout << WHTB << BBLK << "|    PLAYER     |  METERS  |   ENERGY   |  COIN$  |"
       << reset << reset << endl;
  cout << "===================================================" << endl;
  cout << "| 1) ";
  p1.show_player();
  cout << "| 2) ";
  p2.show_player();
  cout << "===================================================" << endl;
}

void action() {
  cout <<WHTB<< "                                                   " << reset << endl;
  cout << WHTB << BHBLK << "   Action : 1. Choose a dice                       "
       << endl;
  cout << "            2. Food market                         " << endl;
  cout << "            3. Turn skip                           " << reset
       << reset << endl;
  cout <<WHTB<< "                                                   " << reset << endl;
}

int start_player1(player *p1, player *p2) {
  int met = 0, choose_action = 0, check_dice = 1;
  while (choose_action != 3 &&
         ((*p1).met_player() == 0 && (*p1).energy_player() == 0) &&
         ((*p2).met_player() == 0 && (*p2).energy_player() == 0)) {
    cout << "\033[0;0H\033[2J";
    output(*p1, *p2);
    cout << BLKB<< "                                                   " << reset << endl;
    cout << BLKB << BHGRN
         << "                  PLAYER 1 TURN                    " << reset
         << reset << endl;
    cout << BLKB<< "                                                   " << reset << endl;
    action();
    cout << "---------------------------------------------------" << endl;
    cout << "Input --> ";
    cin >> choose_action;
    while ((choose_action < 1 || choose_action > 3)) {
      cout << "\033[0;0H\033[2J";
      output(*p1, *p2);
      cout << BLKB<< "                                                   " << reset << endl;
      cout << BLKB << BHGRN
           << "                  PLAYER 1 TURN                    " << reset
           << reset << endl;
      cout << BLKB<< "                                                   " << reset << endl;
      action();
      cout << "---------------------------------------------------" << endl;
      cout<<RED<< "Input again !!! --> "<<reset;
      cin >> choose_action;
    }
    if (choose_action == 1 && met != 1) {
      if (check_dice == 1) {
        (*p1).get_coin();
        check_dice = (*p1).random_activities();
        met = 1;
      }
    } else if (choose_action == 2) {
      cout << "\033[0;0H\033[2J";
      (*p1).foodmarket();
    }
  }
  return who_win(*p1, *p2);
}

int start_player2(player *p1, player *p2) {
  int met = 0, choose_action = 0, check_dice = 1;
  while (choose_action != 3 &&
         ((*p1).met_player() == 0 && (*p1).energy_player() == 0) &&
         ((*p2).met_player() == 0 && (*p2).energy_player() == 0)) {
    cout << "\033[0;0H\033[2J";
    output(*p1, *p2);
    cout << BLKB<< "                                                   " << reset << endl;
    cout << BLKB << BRED
         << "                  PLAYER 2 TURN                    " << reset<< reset << endl;
    cout << BLKB<< "                                                   " << reset << endl;
    action();
    cout << "---------------------------------------------------" << endl;
    cout << "Input --> ";
    cin >> choose_action;
    while ((choose_action < 1 || choose_action > 3) && check_dice != 2) {
      cout << "\033[0;0H\033[2J";
      output(*p1, *p2);
      cout << BLKB<< "                                                   " << reset << endl;
      cout << BLKB << BRED
           << "                  PLAYER 2 TURN                    " << reset
           << reset << endl;
      cout << BLKB<< "                                                   " << reset << endl;
      action();
      cout << "---------------------------------------------------" << endl;
      cout<<RED << "Input again !!! --> "<<reset;
      cin >> choose_action;
    }
    if (choose_action == 1 && met != 1) {
      if (check_dice == 1) {
        (*p2).get_coin();
        check_dice = (*p2).random_activities();
        met = 1;
      }
    } else if (choose_action == 2) {
      cout << "\033[0;0H\033[2J";
      (*p2).foodmarket();
    }
  }
  return who_win(*p1, *p2);
}

int who_win(player p1, player p2) {
  cout << "\033[0;0H\033[2J";
  output(p1, p2);
  if ((p1.met_player() == 1 && p1.energy_player() == 0) ||
      p2.energy_player() == 1) {
    cout << BLKB << BHGRN
         << "                                                   " << endl;
    cout << "          PLAYER 1 " << left << setw(10) << (p1).name_player()
         << " IS WINNER!!!         " << endl;
    cout << "                                                   " << reset
         << reset << endl<<endl;
    return 1;
  } else if ((p2.met_player() == 1 && p2.energy_player() == 0) ||
             p1.energy_player() == 1) {
    cout << BLKB << BRED
         << "                                                   " << endl;
    cout << "          PLAYER 2 " << left << setw(10) << (p2).name_player()
         << " IS WINNER!!!         " << endl;
    cout << "                                                   " << reset
         << reset << endl<<endl;
    return 1;
  }
  return 0;
}

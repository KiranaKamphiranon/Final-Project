#include <iostream>
#include <iomanip>
using namespace std;
#include "player.h"
#include "color.h"

void showmenubar()
{
  cout<<"----------------------------------"<<endl;
  cout<<WHTB<<BBLK<<"|      MENU      | ENERGY | COIN |"<<reset<<reset<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"| [1] Krapao     |  +100  |  01  |"<<endl;
  cout<<"| [2] Pizza      |  +250  |  02  |"<<endl;
  cout<<"| [3] Spaghetti  |  +400  |  03  |"<<endl;
  cout<<"| [4] Back       |        |      |"<<endl;
  cout<<"----------------------------------"<<endl;
}

void player::change_name(string n){
  this->name=n;
}

player::player(string n,int m,int e,int c)
{
  name=n;
  meters=m;
  your_energy=e;
  coin=c;
}
player::~player()
{
  //cout<<"hi"<<endl;
}

void player::show_player()
{
  cout<<left<<setw(10)<<name<<" |  ";
  cout<<right<<setw(2)<<meters<<"/20   |    ";
  cout<<right<<setw(4)<<your_energy<<"    |    "<<coin<<"    |"<<endl;

}

int player::met_player()
{
  if(meters<20) return 0;
  else return 1;
}

int player::energy_player()
{
  if(your_energy>0) return 0;
  else return 1;
}

void player::foodmarket()
{
  int i,checkenergy,outmarket=1;
  cout<<"\033[0;0H\033[2J";
  cout<<BHYEL<<"Your coin "<<coin<<" $"<<reset<<endl;
  showmenubar();
  cout<<BWHT<<"What can I do for you ?"<<reset<<endl;
  cout<<"Input --> ";
  cin>>i;
  do
  {
    if(i==1)//////////////////////////
    {
      if(coin>=1)
      {
        coin-=1;
        checkenergy=your_energy;
        your_energy+=100;
        cout<<BLU<<"You eat Krapao ";
        cout<<RED<<"(it so spicy!)"<<reset<<endl;
        cout<<HGRN<<" -> Your energy "<<WHT<<checkenergy<<" + 100 = "<< your_energy<<endl;
        cout<<BLU<<"Input --> "<<reset;
        cin>>i;
      }
      else
      {
        cout<<RED<<"Not Enough Coin"<<reset<<endl;
        cout<<BLU<<"Choose again -> "<<reset;
        cin>>i;
        cout<<"\033[0;0H\033[2J";
        cout<<YEL<<"Your coin "<<coin<<" $"<<reset<<endl;
        showmenubar();
      }
    }
    else if(i==2)//////////////////////////////
    {
      if(coin>=2)
      {
        coin-=2;
        checkenergy=your_energy;
        your_energy+=250;
        cout<<BLU<<"You eat Pizza ";
        cout<<RED<<"(it so delicious!)"<<reset<<endl;
        cout<<HGRN<<" -> Your energy "<<WHT<<checkenergy<<" + 250 = "<< your_energy<<endl;
        cout<<BLU<<"Input --> "<<reset;
        cin>>i;
      }
      else
      {
        cout<<RED<<"Not Enough Coin"<<endl;
        cout<<BLU<<"Choose again -> "<<reset;
        cin>>i;
        cout<<"\033[0;0H\033[2J";
        cout<<BHYEL<<"Your coin "<<coin<<" $"<<reset<<endl;
        showmenubar();
      }
    }
    else if(i==3)//////////////////////////////
    {
      if(coin>=3)
      {
        coin-=3;
        checkenergy=your_energy;
        your_energy+=400;
        cout<<BLU<<"You eat Spaghetti ";
        cout<<RED<<"(it so amazing!)"<<reset<<endl;
        cout<<HGRN<<" -> Your energy "<<WHT<<checkenergy<<" + 400 = "<< your_energy<<endl;
        cout<<BLU<<"Input --> "<<reset;
        cin>>i;
      }
      else
      {
        cout<<RED<<"Not Enough Coin"<<endl;
        cout<<BLU<<"Choose again -> "<<reset;
        cin>>i;
        cout<<"\033[0;0H\033[2J";
        cout<<BHYEL<<"Your coin "<<coin<<" $"<<reset<<endl;
        showmenubar();
      }
    }
    else if(i==4)
    {
      outmarket=0;
      //back
    }
    else
    {
      cout<<RED<<"Choose again --> "<<reset;
      cin>>i;
      cout<<"\033[0;0H\033[2J";
      cout<<BHYEL<<"Your coin "<<coin<<" $"<<reset<<endl;
      showmenubar();
    }
  }while(outmarket==1);
}

void player::get_coin()
{
  int i;
  i=rdom::getcoin();
  if(i==3||i==6||i==9)
  {
    coin+=1;
    cout<<BHYEL<<"coin +"<<1<<" $";
    cout<<RED<<" (You find a coin!) "<<reset<<endl;
  }
  else 
  {
    cout<<BHYEL<<"coin +"<<0<<" $"<<reset<<endl;
  }
}

int player::random_activities()//วาดลูกเต๋า
{
  int random_act,dice,checkdice=1;
  random_act=rdom::random_activities();
  cout<<BHMAG<<"Random Action: "<<reset;
  if(random_act==0||random_act==9){
    cout<<BCYN<<"Walk x50 "<<endl;
    random_act=50;
  }
  else if(random_act==1)
  {
    cout<<BHCYN<<"Run x75 "<<endl;
    random_act=75;
  }
  else if(random_act==2)
  {
    cout<<BHCYN<<"Drive a car x69 "<<endl;
    random_act=69;
  }
  else if(random_act==3)
  {
    cout<<BHCYN<<"Roll x40 "<<endl;
    random_act=40;
  }
  else if(random_act==4) 
  {
    cout<<BHCYN<<"Jump x95 "<<endl;
    random_act=95;
  }
  else if(random_act==5)
  {
    cout<<BHCYN<<"Ride a bike x100 "<<endl;
    random_act=100;
  }  
  else if(random_act==6) 
  {
    cout<<BHCYN<<"Fly an airplane x200 "<<endl;
    random_act=200;
  }  
  else if(random_act==7) 
  {
    cout<<BHCYN<<"Use balloon x15 "<<endl;
    random_act=15;
  }
  else if(random_act==8) 
  {
    cout<<BHCYN<<"Ride a motocycle x72 "<<endl;
    random_act=72;
  }
  do{
    cout<<reset<<BHBLU<<"CHOOOSE DICE"<<BWHT<<" [1-6] ";
    cout<<BHBLU<<"or Go Back"<<BWHT<<" [7] -> "<<reset;
    cin>>dice;
    if (dice<=6&&dice>=1)
    {
      your_energy=your_energy-(dice*random_act);
      checkdice=0;
      meters+=dice;
      if (meters>20&&your_energy<0){
        meters=20;
        your_energy=0;
        return 2;
      }
      if (your_energy<0){
        your_energy=0;
        return 2;
      }
      if (meters>20){
        meters=20;
        return 2;
      }
      return 0;
    }  
    else if(dice==7) checkdice=0;
    else cout<<RED<<"------------------Wrong number!!!------------------"<<reset<<endl;
    
  }while (checkdice==1);
  return 1;
}
string player::name_player(){
  return name;
}
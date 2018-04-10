#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <unistd.h>

class Card {

  public:
    Card(int suit_, int face_) {
      suit = suit_;
      face = face_;
    }
    
    int suit, face;
};

enum Suit {
  heart,
  club,
  diamond,
  spade
};

enum Face {
  ace,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack,
  queen,
  king
};



int main() {

  std::vector<Card> modeldeck;
  for (int i = 0; i<4; i++) {
    for (int j = 0; j < 13; j++) {
      modeldeck.push_back(Card(i,j));
    }
  }

  bool drew_spade, drew_heart;
  unsigned int microseconds = 15;
  int tot = 0;
  float nohearts = 0;
  for (;tot<1000000;tot++) {
    std::vector<Card> deck(modeldeck);
    drew_spade = drew_heart = false;
    int total_drawn = 0;
    while (not drew_spade) {
      srand(time(0));
      int index = rand() % deck.size();
      usleep(microseconds);
      Card drawn = deck[index];
      deck.erase(deck.begin()+index);
      if (drawn.suit == heart) {
        drew_heart = true;
      }
      else if (drawn.suit == spade) {
        drew_spade = true;
        break;
      }
      total_drawn++;
    }
    if (drew_heart == false) {nohearts += 1.0;}
    microseconds = rand() % 50;
    usleep(microseconds);
  }
  
  std::cout << nohearts << std::endl;
  double prob = nohearts/10000.0;
  std::cout << prob << std::endl;

}

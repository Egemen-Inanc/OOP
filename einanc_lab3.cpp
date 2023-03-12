#include <iostream>
#include <random>
using namespace std;

class Deck{
    private:
    int number_of_cards=52;
    int cards[52];
    public:
    Deck()
    {
        for(int i=0;i<number_of_cards;i++)
        {
            cards[i]=i/4;
        }
    }
    void printDeck()
    {
     cout<<"Cards on deck:"<<endl;    
        for(int i=0;i<number_of_cards;i++)
        {
            
            cout<<cards[i]<<",";
            if(i+1==number_of_cards)
            cout<<cards[i]<<"."<<endl;
        
        }
        cout<<endl;
    }
    int Deal()
    {
        srand(time(NULL));
        int tmp = rand() % (number_of_cards);
        int value = cards[tmp];
        cards[tmp] = 99;
        number_of_cards--;
        int tmp2;
        cards[tmp] = tmp2;
        cards[tmp] = cards[number_of_cards];
        cards[number_of_cards] = tmp2;
        return value;
    }
};
class Player{
    private:
    int cards_held = 0;
    int hand[52];//maximum number of cards a player can hold is 52.
    public:
    int& getCards()
    {
        return cards_held;
    }
    void Print()
    {
        for(int i=0;i<cards_held;i++)
        {
            cout<<hand[i]<<",";
            if(i+1==cards_held)
            cout<<hand[i]<<".";
        }
        cout<<endl;
    }
    int& addToHand()
    {
        return hand[cards_held++];
    }
};
void Random(Player& p, Deck& deck)
{
    p.addToHand() = deck.Deal();
}
void PrintHand(Player p)
{
    cout<<"Player's hand:"<<endl;
    p.Print();
}

int main(){
    Deck first;
    Player player;
    first.printDeck();
    PrintHand(player);
    for(int i=0;i<5;i++)
    {
        cout<<first.Deal()<<endl;
    }
    for(int i=0;i<5;i++)
    {
        Random(player,first);
    }
    PrintHand(player);
    first.printDeck();
}

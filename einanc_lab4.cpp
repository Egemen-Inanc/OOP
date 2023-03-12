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
        for(int i=0;i<number_of_cards-16;i++)
        {
            cards[i]=(i/4)+1;
        }
        for(int i=0;i<16;i++)
        {
            cards[36+i]=10;
        }
        for(int i=0;i<4;i++)
        {
            cards[i]+=10;
        }
    }
        void printDeck()
        {
        for(int i=0;i<number_of_cards;i++)
        {
            cout<<cards[i]<<", ";
        }
        cout<<endl;
    }
    
    int Deal()
    {
        srand(time(NULL));
        int tmp = rand() % (number_of_cards);
        int Value = cards[tmp];
        cards[tmp] = 99;
        //sorting
        number_of_cards--;
        int tmp2;
        cards[tmp] = tmp2;
        cards[tmp] = cards[number_of_cards];
        cards[number_of_cards] = tmp2;

        return Value;
    }
};
class Player
{
    private:
    int cards_held = 0;

    int hand[10];//maximum number of cards in hand

    public:
    int& recAmount()
    {
        return cards_held;
    }
    
      

    int& getCards()
    {
        return hand[cards_held++];
    }
    
    void Print()
    {
        int i;
        for(i;i<cards_held;i++)
        {
            cout<<hand[i]<<",";
        }
    cout<<endl;
    }

  
    int HandValue()
    {
        int tmp=0;
        for(int i=0;i<cards_held;i++)
        {
            tmp+=hand[i];
        }
        return tmp;
    }
    

    void reset()
    {
        for(int i=0;i<cards_held;i++)
        {
            hand[i]=0;
        }
        cards_held=0;
    }
};

void toHand(Player& plr, Deck& dck)
{
    plr.getCards() = dck.Deal();
}

void PrintHand(Player plr)
{
    plr.Print();
}








class Dealer
{
    private:
    int cards_held = 0;
    
    int hand[10];

    public:
    int& recAmount()
    {
        return cards_held;
    }

    int& getCards()
    {
        return hand[cards_held++];
    }

    void Print()
    {
        for(int i=0;i<cards_held;i++)
        {
            cout<<hand[i]<<",";
        }
        cout<<endl;
    }

    int HandValue()
    {
        int tmp=0;
        for(int i=0;i<cards_held;i++)
        {
            tmp+=hand[i];
        }
        return tmp;
    }

    void reset()
    {
        for(int i=0;i<cards_held;i++)
        {
            hand[i]=0;
        }
        cards_held=0;
    }

};

void ToDealerHand(Dealer& dlr, Deck& dck)
{
    dlr.getCards() = dck.Deal();
}

void DealerPrintHand(Dealer dlr)
{
    dlr.Print();
}

int Handed(Player plr)
{
    return plr.HandValue();
}

int DealerHand(Dealer dlr)
{
    return dlr.HandValue();
}
int Play(Dealer& dlr, Player& plr)
{

    Deck dck;

    plr.reset();
    dlr.reset();

    for(int i=0;i<2;i++)
        toHand(plr,dck);

    ToDealerHand(dlr,dck);

    while(true)
    {
        cout<<endl<<"your hand:";
        plr.Print();
        cout<<Handed(plr)<<endl;
        cout<<"dealer's hand:";
        dlr.Print();
        cout<<DealerHand(dlr)<<endl;
        

        if(Handed(plr)>21)
        {
            cout<<"You Busted, you lose!"<<endl;
            return 0;
        }

        if(Handed(plr)==21)
        {
            cout<<"blackjack, you win!"<<endl;
            return 1;
        }

        cout<<"HIT/STAND  (H/S)"<<endl;
        char choice;
        cin>>choice;

        if(choice == 'h' || choice == 'H')
        {
            toHand(plr,dck);
            continue;
        }
        if(choice == 's' || choice == 'S')
            break;
    }

    ToDealerHand(dlr,dck);
    

    while(true)
    {
        if(DealerHand(dlr)>21)
        {
            cout<<"Dealer's hand:";
            dlr.Print();
            cout<<DealerHand(dlr)<<endl;

            cout<<"Dealer Busted, you win!"<<endl;
            return 1;
        }

        if(DealerHand(dlr)<17)
        {
            ToDealerHand(dlr,dck);
            continue;
        }
        
          if(DealerHand(dlr)==21)
        {
            cout<<"Dealer's hand:";
            dlr.Print();
            cout<<DealerHand(dlr)<<endl;

            cout<<"Dealer blackjack, you lose!"<<endl;
            return 0;
        }
        
        if(DealerHand(dlr)>=17)
            break;
        
      

    }
    cout<<"your hand:";
    plr.Print();
    cout<<Handed(plr)<<endl;
    cout<<"dealer's hand:";
    dlr.Print();
    cout<<DealerHand(dlr)<<endl;

    if(Handed(plr)>DealerHand(dlr))
        cout<<"You win!"<<endl;
    if(Handed(plr)<DealerHand(dlr))
        cout<<"You lose!"<<endl;

    if(Handed(plr)==DealerHand(dlr))
        cout<<"It's even!"<<endl;
    
    return -1;
}

int main()
{
    Deck first;
    Player player0;
    Dealer dealer0;

    first.printDeck();
    Play(dealer0,player0);
}
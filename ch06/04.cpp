#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <ctime>

#define DECK_SIZE 52

enum class CardRank{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
};

enum class CardSuit{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
};

struct Card{
    CardRank cRank{};
    CardSuit cSuit{};
};

void printCard(const Card &card);
std::array<Card, DECK_SIZE> createDeck();
void printDeck(const std::array<Card, DECK_SIZE> &deck);
void shuffleDeck(std::array<Card, DECK_SIZE> &deck);
int getCardValue(Card card);
bool playBlackjack(std::array<Card, DECK_SIZE> deck);
void showPlayerScore(int score);

int main(){

    std::array<Card, DECK_SIZE> deck{};

    deck = createDeck();

    shuffleDeck(deck);

    if(playBlackjack(deck))
        std::cout << "Player won";
    else
        std::cout << "Dealer won";
        
    return 0;
}

void printCard(const Card &card){
    switch(card.cRank){
        case CardRank::RANK_2:
            std::cout << "2";
            break;
        case CardRank::RANK_3:
            std::cout << "3";
            break;
        case CardRank::RANK_4:
            std::cout << "4";
            break;
        case CardRank::RANK_5:
            std::cout << "5";
            break;
        case CardRank::RANK_6:
            std::cout << "6";
            break;
        case CardRank::RANK_7:
            std::cout << "7";
            break;
        case CardRank::RANK_8:
            std::cout << "8";
            break;
        case CardRank::RANK_9:
            std::cout << "9";
            break;
        case CardRank::RANK_10:
            std::cout << "10";
            break;
        case CardRank::RANK_JACK:
            std::cout << "J";
            break;
        case CardRank::RANK_QUEEN:
            std::cout << "Q";
            break;
        case CardRank::RANK_KING:
            std::cout << "K";
            break;
        case CardRank::RANK_ACE:
            std::cout << "A";
            break;
        default:
            std::cout << "?";
            break;
    }

    switch(card.cSuit){
        case CardSuit::SUIT_CLUB:
            std::cout << "C";
            break;
        case CardSuit::SUIT_HEART:
            std::cout << "H";
            break;
        case CardSuit::SUIT_DIAMOND:
            std::cout << "D";
            break;
        case CardSuit::SUIT_SPADE:
            std::cout << "S";
            break;
        default:
            std::cout << "?";
            break;
    }

    std::cout << " ";
}

std::array<Card, DECK_SIZE> createDeck(){
    std::array<Card, DECK_SIZE> deck{};
    int cnt{};

    for(int i=0; i<static_cast<int>(CardRank::MAX_RANKS); i++){
        for(int j=0; j<static_cast<int>(CardSuit::MAX_SUITS); j++, cnt++){
            deck[cnt].cRank = static_cast<CardRank> (i);       
            deck[cnt].cSuit = static_cast<CardSuit> (j);
        }
    }

    return deck;
}

void printDeck(const std::array<Card, DECK_SIZE> &deck){
    for(Card card : deck){
        printCard(card);
    }
    std::cout << "\n";
}

void shuffleDeck(std::array<Card, DECK_SIZE> &deck){
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mersenne);
}

int getCardValue(Card card){
    switch(card.cRank){
        case CardRank::RANK_2:
            return 2;
        case CardRank::RANK_3:
            return 3;
        case CardRank::RANK_4:
            return 4;
        case CardRank::RANK_5:
            return 5;
        case CardRank::RANK_6:
            return 6;
        case CardRank::RANK_7:
            return 7;
        case CardRank::RANK_8:
            return 8;
        case CardRank::RANK_9:
            return 9;
        case CardRank::RANK_10:
        case CardRank::RANK_JACK:
        case CardRank::RANK_QUEEN:
        case CardRank::RANK_KING: 
            return 10;
        case CardRank::RANK_ACE:
            return 11;
        default:
            return -1;
    }
}

bool playBlackjack(std::array<Card, DECK_SIZE> deck){
    int cardCnt{};
    int dealerCnt{};
    int playerCnt{};
    char op{};

    for(cardCnt=0; cardCnt<2; cardCnt++)
        playerCnt += getCardValue(deck[cardCnt]);

    showPlayerScore(playerCnt);
    
    /*
        Player's turn
        Hit or stand    
    */
    do{
        std::cout << "Hit (h) or stand (s)? ";
        std::cin  >> op;
        
        if(op == 's')
            break;
        else if(op = 'h'){
            playerCnt += getCardValue(deck[cardCnt]);
            cardCnt++;
            showPlayerScore(playerCnt);
        }

        if(playerCnt > 21)
            return false;
    }while(true);
    
    /*
        Dealer's turn
    */
    do{
        dealerCnt += getCardValue(deck[cardCnt]);
        cardCnt++;
        if(dealerCnt > 21)
            return true;
    }while(dealerCnt < 17);

    if(playerCnt > dealerCnt)
        return true;
    else
        return false;
}

void showPlayerScore(int score){
    std::cout << "Current player's score: " << score << "\n";
}
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

struct Card{
    int number;
    string suit;
};

class Game{
    private:
    std::random_device rng;
    vector<Card> deck;
    vector<Card> player1, player2, player3, player4;

    public:
    Game();
    void buildDeck();
    void dealCards();
    bool compareAndRemove(vector<Card>&, vector<Card>&);
    void playOneRound();
    void shuffleCards();
    bool isGameComplete();
    void playGame();
    void print();
};

Game::Game(){
    buildDeck();
    dealCards();
}

void Game::print(){
    cout << "P1\n";
    for(auto i: player1){
        cout << i.number << " ";
    }
    cout << endl;

    cout << "P2\n";
    for(auto i: player2){
        cout << i.number << " ";
    }
    cout << endl;

    cout << "P3\n";
    for(auto i: player3){
        cout << i.number << " ";
    }
    cout << endl;

    cout << "P4\n";
    for(auto i: player4){
        cout << i.number << " ";
    }
    cout << endl;

}

void Game::buildDeck(){
    for(int i = 0; i < 52; i++){
        if(i <= 13){
            deck.push_back(Card{i%13, "CLUB"});
        } else if(i <= 26){
            deck.push_back(Card{i%13, "DIAMOND"});
        } else if(i <= 39){
            deck.push_back(Card{i%13, "HEART"});
        } else {
            deck.push_back(Card{i%13, "SPADE"});
        }
    }
}

void Game::dealCards(){
    player1 = {deck.begin(), deck.begin() + 13};
    player2 = {deck.begin() + 13, deck.begin() + 26};
    player3 = {deck.begin() + 26, deck.begin() + 39};
    player4 = {deck.begin() + 39, deck.end()};
}

bool Game::compareAndRemove(vector<Card>& p1, vector<Card>& p2){
    cout << "Comparing " << p1.back().number << " " << p1.back().suit << " and " << p2.back().number << " " << p2.back().suit << endl;
    if(p1.back().number == p2.back().number){
        p1.pop_back();
        p2.pop_back();
        return true;
    }

    return false;
}

void Game::playOneRound(){
    if(compareAndRemove(player1, player2)){
        compareAndRemove(player3, player4);
    } else if (compareAndRemove(player1, player3)){
        compareAndRemove(player2, player4);
    } else if (compareAndRemove(player1, player4)){
        compareAndRemove(player2, player3);
    } else if (compareAndRemove(player2, player3)){
        compareAndRemove(player1, player4);
    } else if (compareAndRemove(player2, player4)){
        compareAndRemove(player1, player3);
    }
}

void Game::shuffleCards(){
    shuffle(player1.begin(), player1.end(), rng);
    shuffle(player2.begin(), player2.end(), rng);
    shuffle(player3.begin(), player3.end(), rng);
    shuffle(player4.begin(), player4.end(), rng);
}

bool Game::isGameComplete(){
    return player1.empty() || player2.empty() || player3.empty() || player4.empty();
}

void Game::playGame(){
    while(!isGameComplete()){
        shuffleCards();
        playOneRound();
    }

    if(player1.empty()) {
        cout << "The winner is Player 1\n";
    } else if (player2.empty()){
        cout << "The winner is Player 2\n";
    } else if (player3.empty()){
        cout << "The winner is Player 3\n";
    } else {
        cout << "The winner is Player 4\n";
    }

}

int main(){
    Game newgame;
    newgame.playGame();
}
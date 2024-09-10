#include <iostream>
#include <queue>

using namespace std;

class DrunkardGame {
    /*
    Class that implement the Drunkard Game

    Rules:
    The one whose card is bigger gets both cards to the back of his deck until
    one player is left without any cards
    */
private:
    queue <int>& q1;
    queue <int>& q2;
    int numberOfTurns;

    bool compareNumbers(int& num1, int& num2) {
        //returns true if first number is greater according to the rules where 0 > 9 and 2 > 1 etc...
        if (num1 > num2) {
            if (num1 == 9 && num2 == 0) {
                return false;
            }
            return true;
        } else {
            if (num2 == 9 && num1 == 0) {
                return true;
            }
            return false;
        }
    }

    pair <string, int> getWinner() {
        /*Utility function again)*/
        pair<string, int> winner;

        if (q1.empty()) {
            winner.first = "Nursik";
            winner.second = numberOfTurns;
        } else if (q2.empty()) {
            winner.first = "Boris";
            winner.second = numberOfTurns;
        } else {
            winner.first = "blin nichya";
            winner.second = -1; //draw is -1
        }        
        return winner;
    }


public:
    DrunkardGame(queue<int>& q1, queue<int>& q2, int& numberOfTurns) : q1(q1), q2(q2), numberOfTurns(numberOfTurns) {}

    pair <string, int> gameLoop() { //main game logic
        while (!q1.empty() && !q2.empty() && numberOfTurns < 1000000) {
            if (compareNumbers(q1.front(), q2.front())) {
                q1.push(q1.front()); //q1 i.e. Boris' card always goes first in the back of the round's winner's deck
                q1.push(q2.front());
                q1.pop();
                q2.pop();
            } else {
                q2.push(q1.front());
                q2.push(q2.front());
                q1.pop();
                q2.pop();
            }
            numberOfTurns++;
        }

        return getWinner();
    }
};


int main() {
    queue <int> q1;
    queue <int> q2;

    int number;
    int numberOfTurns = 0;

    for (int i = 0; i < 5; i++) {
        cin >> number;
        q1.push(number);
    }

    for (int i = 0; i < 5; i++) {
        cin >> number;
        q2.push(number);
    }

    DrunkardGame game(q1, q2, numberOfTurns);

    pair <string, int> winner = game.gameLoop();

    if (winner.second < 0) { //this condition check for draw 
        cout << winner.first;
    } else {
        cout << winner.first << " " << winner.second;
    }

}
#include <iostream>
#include <deque>
#include <string>

using namespace std;

class CardTrick {
    /**
     * Class to simulate the card trick backwards
     */
private:
    int numberOfCards;
    deque <int> cardDeck;

    string dequeToString() { // utility function
        string output = "";
        for (int i : cardDeck) {
            output = output + to_string(i) + " ";
        }
        return output;
    }

public:
    CardTrick(int numberOfCards) : numberOfCards(numberOfCards) {}

    string play() { 
    /*
    Main logic of the game - continuously adding numbers, shuffling them 
    by moving back to the front to finally get the correct card permutation
    */
        for (int i = numberOfCards; i > 0; i--) {
            cardDeck.push_front(i);
            for (int j = 0; j < i; j++) {
                cardDeck.push_front(cardDeck.back());
                cardDeck.pop_back();
            }
        }
        return dequeToString();
    }
};

int main() {
    int numberOfTests; cin >> numberOfTests;
    int n;
    for (int i = 0; i < numberOfTests; i++) {
        cin >> n;
        CardTrick trick = CardTrick(n);
        cout << trick.play() << endl;
    }

    return 0;
}
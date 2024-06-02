#include <bits/stdc++.h>

using namespace std;
const char rock = 'r';
const char paper = 'p';
const char scissor = 's';

int play = 0;
int compu = 0;

class RPS
{
private:
    char pl;
    char num;

public:
    void player();
    void computer();
    void winner();
    void final_winner();
};

void RPS::player()
{
    cout << "\nplayer: ";
    cin >> pl;
    while (pl != rock && pl != paper && pl != scissor)
    {
        cout << "invalid choice!!!" << endl;
        cout << "select a valid choice(r/p/s): ";
        cin >> pl;
    }
}

void RPS ::computer()
{
    srand(time(0));
    num = rand() % 3 + 1;
    if (num == 1)
    {
        num = rock;
    }
    if (num == 2)
    {
        num = paper;
    }
    if (num == 3)
    {
        num = scissor;
    }

    cout << "computer: " << num << endl;
}

void RPS ::winner()
{
    if (num == rock && pl == rock)
    {
        cout << "\n no one gets point!!" << endl;
    }
    else if (num == paper && pl == paper)
    {
        cout << "\n no one gets point!!" << endl;
    }
    else if (num == scissor && pl == scissor)
    {
        cout << "\n no one gets point!!" << endl;
    }

    else if (num == paper && pl == rock)
    {
        cout << "\n paper wraps your rock" << endl;
        cout << "\n computer gets 1 point!!" << endl;
        compu++;
    }
    else if (num == scissor && pl == paper)
    {
        cout << "\n scissors cut your paper" << endl;
        cout << "\n computer gets 1 point!!" << endl;
        compu++;
    }
    else if (num == rock && pl == scissor)
    {
        cout << "\n rock breaks your scissors" << endl;
        cout << "\n computer gets 1 point!!" << endl;
        compu++;
    }
    else if (num == rock && pl == paper)
    {
        cout << "\n paper wraps rock" << endl;
        cout << "\n player gets 1 point!!" << endl;
        play++;
    }
    else if (num == paper && pl == scissor)
    {
        cout << "\n scissors cut paper" << endl;
        cout << "\n player gets 1 point" << endl;
        play++;
    }
    else if (num == scissor && pl == rock)
    {
        cout << "\n rock break scissors" << endl;
        cout << "\n player gets 1 point!!" << endl;
        play++;
    }
}

void RPS ::final_winner()
{
    cout << "\n"
         << setw(40) << "final winner:";
    if (play > compu)
        cout << " player wins the game (" << play << ":" << compu << ")" << endl;
    else if (compu > play)
        cout << " computer wins the game (" << compu << ":" << play << ")" << endl;
    else
        cout << "draw match" << endl;
}

int main()
{

    RPS r;
    int pt;
    cout << setw(60) << "..ROCK PAPER SCISSORS..\n " << endl;
    cout << "(Rock = r "
         << " Paper = p "
         << " Scissor = s" << endl;
    cout << "Enter total game points:";
    cin >> pt;

    for (int i = 1; i <= pt; i++)
    {
        cout << setw(60) << "ROUND " << i << endl;
        r.player();
        r.computer();
        r.winner();
    }
    r.final_winner();
    cout << "\n"
         << setw(50) << "GAME ENDS!!!" << endl;
    return 0;
}
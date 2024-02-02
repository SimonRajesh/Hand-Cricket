#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int batting(int overs, int wickets, int first, int target, char team[50]);
int bowling(int overs, int wickets, int first, int target, char team[50]);

int batting(int overs, int wickets, int first, int target, char team[50]) {
    int over = 0, balls = 0, wicket = 0, runs = 0, shot;
    int run;
    cout << "start batting (0-6)" << endl;
    cout << "EXIT : enter \"123\"\n" << endl;

    while (wicket < wickets && over < overs && target > runs) {
        run = rand() % 7;
        balls++;
        if (balls == 6) {
            balls = 0;
            over++;
        }
        cout << "----> ";
        cin >> shot;
        if (shot == 123) {
            cout << "Thank you for playing!" << endl;
            return 0;
        }
        if (shot != run && shot >= 0 && shot <= 6) {
            runs += shot;
        }
        else if (shot == run) {
            wicket++;
        }
        else {
            cout << "Invalid run " << endl;
            balls--;
        }
        cout << "\tScore   : " << runs << endl;
        cout << "\tOver    : " << over << "." << balls << "/" << overs << endl;
        cout << "\tWickets : " << wicket << "/" << wickets << "\n" << endl;
    }

    if (first == 1) {
        cout << "Your team has scored " << runs << "/" << wicket << " in " << over << "." << balls << endl;
        cout << "Opponent's target : " << runs + 1 << endl;
        cout << "---------------------------------------------" << endl;
        first = 2;
        bowling(overs, wickets, first, runs + 1, team);
    }
    else if (first == 2) {
        if (target <= runs + 1) {
            cout << team << " won the match by " << wickets - wicket << " wickets.. " << endl;
        }
        else {
            cout << "BOT THUNDERS won the match by " << target - runs - 1 << " runs.." << endl;
        }
    }
}

int bowling(int overs, int wickets, int first, int target, char team[50]) {
    int over = 0, balls = 0, wicket = 0, runs = 0, ball;
    int run;

    cout << "start bowling (0-6)" << endl;
    cout << "EXIT : enter \"123\"\n" << endl;

    while (wicket < wickets && over < overs && target > runs) {
        run = rand() % 7;
        balls++;
        if (balls == 6) {
            balls = 0;
            over++;
        }
        cout << "----> ";
        cin >> ball;
        if (ball == 123) {
            cout << "Thank you for playing!" << endl;
            return 0;
        }
        if (ball != run && ball >= 0 && ball <= 6) {
            runs += run;
        }
        else if (ball == run) {
            wicket++;
        }
        else {
            cout << "Invalid ball " << endl;
            balls--;
        }
        cout << "\tScore   : " << runs << endl;
        cout << "\tOver    : " << over << "." << balls << "/" << overs << endl;
        cout << "\tWickets : " << wicket << "/" << wickets << "\n" << endl;
    }

    if (first == 1) {
        cout << "Opponent's team have scored " << runs << "/" << wicket << " in " << over << "." << balls << endl;
        cout << "Your target : " << runs + 1 << endl;
        cout << "---------------------------------------------" << endl;
        first = 2;
        batting(overs, wickets, first, runs + 1, team);
    }
    else if (first == 2) {
        if (target <= runs) {
            cout << "BOT THUNDERS won the match by " << wickets - wicket << " wickets.. " << endl;
        }
        else {
            cout << team << " won the match by " << target - runs - 1 << " runs.." << endl;
        }
    }
}

int main() {
    srand(time(0));
    cout << "--------------Hand cricket game--------------\n" << endl;
    cout << "Hand Cricket is a game in which two players" << endl;
    cout << "score on their respective fingers. If the" << endl;
    cout << "scores are equal, the batsman is declared out." << endl;
    cout << "Else, the score of the batsman is added to the" << endl;
    cout << "total runs of the batting team. In this game," << endl;
    cout << "you are playing against the computer." << endl;
    cout << "-----------------------------------------------\n" << endl;

    char team[50], playerName[50], tossWish, toss, wishPlay;
    int a, bOB = 1, overs, wickets, first = 1, target, oppToss;
    a = rand() % 2;
    toss = a ? 'H' : 'T';

    cout << "TEAM NAME : ";
    cin >> team;
    cout << "Player Name : ";
    cin >> playerName;
    cout << "\n\"OVERS\" : ";
    cin >> overs;
    cout << "\n\"WICKETS\" : ";
    cin >> wickets;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "OPPONENT TEAM : BOT THUNDERS" << endl;
    cout << "Player Name : ×BOT× " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\t\t\t- TOSS -\t\t\n" << endl;
    cout << " Head (H)  |  Tail (T) " << endl;
    cin >> tossWish;

    if (tossWish == toss || tossWish - 32 == toss) {
        cout << "You won the toss" << endl;
        cout << "-----------------------------------------------\n" << endl;
        cout << " BAT (B)  |   BOWL (b) " << endl;
        cin >> wishPlay;

        while (bOB) {
            bOB = 0;
            if (wishPlay == 'B') {
                cout << "\n-----You chose to Bat first-----" << endl;
                cout << "-----------------------------------------------\n" << endl;
                batting(overs, wickets, first, target, team);
            }
            else if (wishPlay == 'b') {
                cout << "\n-----You chose to bowl first-----" << endl;
                cout << "-----------------------------------------------\n" << endl;
                bowling(overs, wickets, first, target, team);
            }
            else
                bOB = 1;
        }
    }
    else {
        oppToss = rand() % 2;
        cout << "\"Opponent won the toss\"" << endl;
        if (oppToss == 0) {
            cout << "\n-----Opponent chose to bat first-----" << endl;
            cout << "-----------------------------------------------\n" << endl;
            bowling(overs, wickets, first, target, team);
        }
        else if (oppToss == 1) {
            cout << "\n-----Opponent chose to bowl first-----" << endl;
            cout << "-----------------------------------------------\n" << endl;
            batting(overs, wickets, first, target, team);
        }
    }

    return 0;
}

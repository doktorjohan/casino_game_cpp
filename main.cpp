#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void rules()
{
    system("clear");
    cout << "\t=====KASIINO NUMBRIMÄNGU REEGLID!======\n";
    cout << "\t1. Vali number 1 ja 10 vahel\n";
    cout << "\t2. Võitja saab raha 10 kordselt tagas\n";
    cout << "\t3. Kaotaja kaotab panustatud raha\n";
    cout << "\t======MÄNGIME!!!======";
}

int main()
{
    int dice;
    string playerName;
    int balance;
    int guess;
    int bettingAmount;
    char choice;
    srand(time(0));

    cout << "\n\t\t======TERE TULEMAST KASIINOSSE!======\n\n";
    cout << "Mis on sinu nimi? ";
    getline(cin, playerName);
    cout << "\nSisesta oma alustussumma et mängu alustada: "; cin >> balance;
    // mainloop while choice == yes
    do {
        system("clear");
        rules();
        cout << "\n\nSinu hetkene saldo on €" << balance << endl;

        // get player's betting balance
        do {
            cout << "Tere, " << playerName << ", palju täna panustad? €"; cin >> bettingAmount;
            if (bettingAmount > balance) {
                cout << "Tundub et sul pole enam nii palju raha alles :C\nAga äkki mängime natuke vähemaga?";
            }
        }while(bettingAmount > balance);

        // get player's numbers
        do {
            cout << "Paku mõni number 1 ja 10 vahel\n"; cin >> guess;
            if(guess <= 0 || guess > 10) {
                cout << "\nNumber peaks olema 1 ja 10 vahel sina loll\n\nSisesta uus number:\n ";
            }
        }while(guess <= 0 || guess > 10);

        // dice roll
        dice = rand()%10 + 1;
        if (dice==guess){
            cout << "\n\nÕnn on sinu poolel! Sa võitsid €" << bettingAmount * 10 << endl;
            balance = balance + bettingAmount * 10;
        } else {
            cout << "\n Oih! järgmine kord ehk veab rohkem! Sa kaotasid €" << bettingAmount << endl;
            balance -= bettingAmount;
        }

        cout << "\n Võidunumber oli " << dice << endl;
        cout << "\n" << playerName << " sul on alles veel €" << balance << endl;

        if (balance == 0) {
            cout << "Sul pole enam raha alles :C. Aeg koju minna ja patja nutta";
            break;
        }

        cout << "\n\nKas sa tahad uuesti mängida? (y/n) "; cin >> choice;
    }while(choice == 'y' || choice == 'Y');

    cout << "\n\n\n";
    cout <<"Täname et mängid meiega! Sinu arvel on €" << balance << endl;

    return 0;
}

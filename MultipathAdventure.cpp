#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string BeginQuest();
void WakeDragonHide(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human);
void WakeDragonStay(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human);
void Adventure(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human);
void FrostAttackFallout(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human);
void DragonAttacksWithTail();

int main() {
//these bools are for checking the character's race and for determining if they have frost/fire resistances
//the user doesn't know about race or resistances (or the lack thereof), but these things impact what happens in the adventure
//thus, to the user, the adventure will be unpredicatable
    srand(time(0));
    while (true) {
        bool isHalfDragon = false;
        bool isHuman = false;
        bool frostResist = false;
        bool fireResist = false;
        cout << BeginQuest();
        // race

        short int userRace = rand() % 2;
        short int resistRoll = rand() % 2;
        if (userRace == 0) {
            isHalfDragon = true;
        }
        else if (userRace == 1) {
            isHuman = true;
        }
        if (isHalfDragon) {
            if (resistRoll == 0) {
                frostResist = true;
            }
            else if (resistRoll == 1) {
                fireResist = true;
            }
        }

        string playAgain;
        Adventure(isHalfDragon, frostResist, fireResist, isHuman); // calling the main adventure function
        cout << "Play again? y/n";
        cin >> playAgain;
        if (playAgain == "y") {
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}

string BeginQuest(){ //the quest begins
    for(int i = 0; i < 76; ++i){
        cout << 0;
    }
    cout << endl;
    string beginQuest = "You're an adventurer, about to enter the main area in a dungeon.\nIf ever faced with a decision, simply type the corresponding letter\n\n";
    return beginQuest;
}
void DragonAttacksWithTail(){ // for when the dragon attacks with its tail
    cout << "Unfortunately, the dragon is in melee range." << endl;
    cout << "You are thrown against a wall by the dragon's lightning-quick tail whip." << endl;
    cout << "You are knocked unconscious. The dragon kills you." << endl;
    cout << "THE END" << endl;
    cout << "***END SCENARIO***" << endl;
}
void FrostAttackFallout(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human){ //when you are hit by the dragon's frost breath
    if(halfDragon){
        if(frostResist){
            cout << "You stand tall, your frost resistance rendering the beast's attack useless." << endl;
            cout << "To be continued..." << endl;
            cout << "***END SCENARIO***" << endl;
        }
        else if(fireResist){
            cout << "You stand your ground. Although the frost breath didn't hurt you, it" << endl;
            cout << "lowered your body temperature, weakening your fire capabilities." << endl;
            cout << "To be continued..." << endl;
            cout << "***END SCENARIO***"<< endl;
        }
    }
    else if(human){
        cout << "Like a fool, you stand your ground. The dragon's icy breath turns you" << endl;
        cout << "into a frozen statue. You're dead, nice work genius." << endl;
        cout << "THE END" << endl;
        cout << "***END SCENARIO***" << endl;
    }
}
void WakeDragonHide(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human){ //when you decide to hide after waking up the dragon
    string userResponse;
    cout << "You rush towards a large boulder for cover. The dragon" << endl;
    cout << "hears you running and instinctively breaths chilling frost at you." << endl << endl;
    cout << "a) Stand your ground?" << endl << "b) Dive behind the boulder?" << endl;

    cin >> userResponse;

    if (userResponse == "a"){
        FrostAttackFallout(halfDragon, frostResist, fireResist, human );
    }
    else if (userResponse == "b"){
        cout << "A deadly trap triggers as you land on your belly." << endl;
        if(halfDragon){ //checking to see what impact the character's race will have on the outcome
            if(frostResist){
                cout << "A poison dart bounces off your frozen scales. You're unaffected by the trap." << endl;
                cout << "To be continued..." << endl;
                cout << "***END SCENARIO***"<< endl;
            }
            else if(fireResist){
                cout << "You feel the sting of a poison dart, and are significantly weakened." << endl;
                cout << "Fortunately, half-dragons are half resistant to poison." << endl;
                cout << "To be continued..." << endl;
                cout << "***END SCENARIO***" << endl;
            }
        }
        else if(human){
            cout << "A poison dart hits you, and you die." << endl;
            cout << "THE END" << endl;
            cout << "***END SCENARIO***"<< endl;
        }
    }
}
void WakeDragonStay(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human){ //when you decide to stay put, after waking up the dragon
    //your character's race will impact the Dragon's response
    if(halfDragon){
        string responseToDragon;
        cout << "The frost dragon speaks: 'Give me one good reason" << endl;
        cout << "why I should not add you to my ice statuette collection.'" << endl;
        cout << "a) Tell the dragon: 'We are kindred. I mean you no harm.'" << endl;
        cout << "b) Tell the dragon: 'Give me one good reason why I shouldn't kill you'" << endl;

        cin >> responseToDragon;

        if (responseToDragon == "a") {
            cout << "The dragon grins: 'You could not harm me anyhow. What brings you here?'" << endl;
            cout << "To be continued..." << endl;
            cout << "***END SCENARIO***" << endl;
        }
        else if (responseToDragon == "b"){
            cout << "Enraged, the dragon roars, and issues forth his blizzard breath." << endl;
            cout << "His blizzard breath covered such a large area so as to render fleeing impossible." << endl;
            FrostAttackFallout(halfDragon, frostResist, fireResist, human );
        }
    }
    else if(human){
        string userResponse;

        cout << "The dragon rises with stunning speed and moves in your direction." << endl;
        cout << "a) Stand your ground?" << endl;
        cout << "b) Run to the nearest boulder for cover?" << endl;

        cin >> userResponse;

        if(userResponse == "a"){
            cout << "The dragon stops only inches away from you. He speaks: 'Well, then. I have" << endl;
            cout << "never known anyone -- let alone a delicate human -- to not run for their life at my" << endl;
            cout << "hasty approach. I have need of someone with your courage. Upon completion, you will" << endl;
            cout << "be rewarded beyond your wildest dreams.'" << endl;
            cout << "To be continued..." << endl;
            cout << "***END SCENARIO***" << endl;
        }
        else if(userResponse == "b"){
            DragonAttacksWithTail();
        }
    }
}
void Adventure(bool &halfDragon, bool &frostResist, bool &fireResist, bool &human){ //main adventure function. Generates the story according to user responses.
    //Calls other functions as needed.
    string userResponse;
    cout << "You enter the main cavern of the dungeon." << endl;
    cout << "At the end of the spacious room you see a massive frost dragon." << endl << endl;
    cout << "a) Wake the beast up?" << endl << "b) Try to sneak closer to it, maybe you'll get a better look" << endl;

    cin >> userResponse;

    if (userResponse == "a"){
        string stayOrHide;

        cout << "'Hello there!' You shouted, your voice booming." << endl;
        cout << "The dragon is slow to stir, but stir it did. Before it opened its eyes, the" << endl;
        cout << "thought occured to you that you could hide." << endl << endl;
        cout << "a) Hide?" << endl << "b) Stand your ground?" << endl;

        cin >> stayOrHide;
        if (stayOrHide == "a") {
            WakeDragonHide(halfDragon, frostResist, fireResist, human);
        }
        else if (stayOrHide == "b") {
            WakeDragonStay(halfDragon, frostResist, fireResist, human);
        }
    }
    else if (userResponse == "b"){
        string attackOrSpeak;

        cout << "You had scarcely crept one step forward, when the" << endl;
        cout << "frost dragon suddenly spoke, his eyes still closed: 'I can" << endl;
        cout << "sense you, sneak-thief. Come for my riches, have you? Kill me, and they're yours.'" << endl;
        cout << "a) Attack?" << endl << "b) Tell the dragon: 'No.'" << endl;

        cin >> attackOrSpeak;

        if (attackOrSpeak == "a"){
            cout << "You charge the dragon!" << endl;
            DragonAttacksWithTail();
        }
        else if(attackOrSpeak == "b"){
            string truthOrDeceit;

            cout << "Surprised, the dragon says: 'Interesting. Why are you here then?'" << endl;
            cout << "a) Tell the dragon: 'I was going to sneak closer, and either kill you or steal your wealth.'" << endl;
            cout << "b) Lie: 'I'm the curious sort, and was all the more intrigued" << endl;
            cout << "when I laid eyes on your excellence." << endl;

            cin >> truthOrDeceit;

            if(truthOrDeceit == "a"){
                cout << "The dragon speaks: 'As terrible as that sounds, I find your honesty both rare and fascinating. I could" << endl;
                cout << "use your help with something. If you are successful, I will reward you handsomely.'" << endl;
                cout << "To be continued..." << endl;
                cout << "***END SCENARIO***" << endl;
            }
            else if(truthOrDeceit == "b"){
                cout << "Without warning, the dragon breaths frost at you." << endl;
                cout << "I guess he sensed your deceit." << endl;
                FrostAttackFallout(halfDragon, frostResist, fireResist, human );
            }
        }
    }
}

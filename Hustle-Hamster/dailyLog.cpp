#include "includes/all_includes.h"

void dailyRating(Journal &dailyEntry){
    int temp; 
    bool validResponse = false; 

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif

    string line = dailyRatingQ[randomNumber(3)];
    TYPE(line);
    TYPE(ratingSystem);
    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
            dailyEntry.setDayRating(temp);
            validResponse = true;
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }

}

void sleepRating(Journal &dailyEntry){
    int temp; 
    bool validResponse = false; 

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif

    string line = sleepRatingQ[randomNumber(2)];
    TYPE(line);
    TYPE(ratingSystem);
    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
            dailyEntry.setSleepRating(temp);
            validResponse = true;
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }


}

void moodRating(Journal &dailyEntry){
    string temp; 
    bool validResponse = false;

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif
    
    string line = moodQ[randomNumber(3)];
    TYPE(line);
    while(!validResponse){
        cin >> temp;
        if(!cin.fail()){
                dailyEntry.setMood(temp);
                validResponse = true;
                break;
        }else{
            TYPE("Please enter a word");
            cin.clear();
            std::cin.ignore(10000, '\n');
            }
    }
}

void longAnswer(Journal &dailyEntry) {
    string textInput; 

    getline(cin, textInput);
    if (!textInput.empty()) {
        dailyEntry.setTextEntry(textInput);
    } else {
        cout << "No input provided." << endl;
    }
}


void didActivity(const string &activity, Journal &dailyEntry){
    char response;
    stringstream message;
    bool validResponse = false;

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif
    
    message << "Did you " << activity << " today? (y/n)";
    while(!validResponse){
        TYPE(message.str());
        cin >> response; 
        char lower = tolower(response); 
        if(lower == 'y'){
            dailyEntry.addActivity(activity);
            validResponse = true;
            break;
        } if(lower == 'n') {
            validResponse = true;
            break;
        }else{
            TYPE("Please Enter a Valid input");
            TYPE("y or Y for Yes");
            TYPE("n or N for No");
        }
    }

}

void exportEntry(Journal &dailyEntry){
    char response;
    stringstream message;
    bool validResponse = false;
    message << "Do you want to export today's entry? (y/n)";
    while(!validResponse){
        TYPE(message.str());
        cin >> response; 
        char lower = tolower(response); 
        if(lower == 'y'){
            exportJournal(dailyEntry);
            validResponse = true;
            break;
        } if(lower == 'n') {
            validResponse = true;
            break;
        }else{
            TYPE("Please Enter a Valid input");
            TYPE("y or Y for Yes");
            TYPE("n or N for No");
        }
    }
    TYPE("");
    TYPE("I'll return you to the main menu now and you can decide to keep hanging out, or leave whenever you want!\n");
    
    #ifndef TEST_RUNNING
        menu();
    #endif
}

int dailyLog(){
    Journal dailyEntry = Journal(); 

    delay(stdDelay);
    dailyRating(dailyEntry); 
    sleepRating(dailyEntry);
    moodRating(dailyEntry);

    for (const string& activity : defaultActivities) {
        didActivity(activity, dailyEntry);
    }

    hammyEvaluation(dailyEntry);

    /*put in the Hammy derivations from the activity and mood ratings*/


    std::cin.ignore(10000000, '\n');
    longAnswer(dailyEntry);

    printHammy();
    printReport(dailyEntry);
    confirm(dailyEntry);

    return 0;
}

void confirm(Journal &dailyEntry){
    int temp;
    bool validResponse = false;
    TYPE("Did you want to go back and change any inputs?");
    TYPE("[1] Daily Rating");
    TYPE("[2] Sleep Rating");
    TYPE("[3] Mood Input");
    TYPE("[4] Activities");
    TYPE("[5] Daily Reflection");
    TYPE("[6] Save and Continue");

    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>=0 && temp<7)){
            if (temp == 1){
                dailyRating(dailyEntry);
                confirm(dailyEntry);
            }
            if (temp == 2){
                sleepRating(dailyEntry);
                confirm(dailyEntry);
            }
            if(temp == 3){
                moodRating(dailyEntry);
                confirm(dailyEntry);
            }
            if (temp == 4){
                dailyEntry.removeAllActivities(); 
                for (const string& activity : defaultActivities) {
                    didActivity(activity, dailyEntry);
                }
                confirm(dailyEntry);
            }
            if (temp == 5){
                std::cin.ignore(10000000, '\n');
                TYPE("New Reflection of the day:");
                longAnswer(dailyEntry);
                confirm(dailyEntry);
            }
            if(temp == 6){
                exportEntry(dailyEntry);
            }
        
        }else{
            TYPE("Please enter a valid number between 1 and 6");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }
}
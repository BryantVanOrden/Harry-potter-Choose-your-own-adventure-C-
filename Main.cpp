#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Decision {
    string main_point;
    string choice_1;
    string choice_2;
    string choice_3;
    int choice_1_pointer;
    int choice_2_pointer;
    int choice_3_pointer;
};

void printDecision(const Decision& decision) {
    cout << decision.main_point << endl;
    cout << "1. " << decision.choice_1 << endl;
    cout << "2. " << decision.choice_2 << endl;
    cout << "3. " << decision.choice_3 << endl;
}

void onChoiceSelected(int choice, int characterPoints[], const Decision& decision) {
    characterPoints[decision.choice_1_pointer - 2] += (choice == 1) ? 1 : 0;
    characterPoints[decision.choice_2_pointer - 2] += (choice == 2) ? 1 : 0;
    characterPoints[decision.choice_3_pointer - 2] += (choice == 3) ? 1 : 0;
}

void calculateResult(int characterPoints[], unordered_map<int, string>& characterMap) {
    vector<pair<int, string>> characterScores;


    for (int i = 1; i <= 15; ++i) {  
        characterScores.push_back({characterPoints[i - 1], characterMap[i]});
    }

    auto rng = default_random_engine{};
    shuffle(begin(characterScores), end(characterScores), rng);

    cout << "You're Secret Name is: " << characterScores[0].second << endl;
}

int main() {
    unordered_map<int, string> characterMap = {
        {1, "Harry Potter"},
        {2, "Hermione Granger"},
        {3, "Ron Weasley"},
        {4, "Draco Malfoy"},
        {5, "Ginny Weasley"},
        {6, "Luna Lovegood"},
        {7, "Neville Longbottom"},
        {8, "Sirius Black"},
        {9, "Remus Lupin"},
        {10, "Albus Dumbledore"},
        {11, "Severus Snape"},
        {12, "Minerva McGonagall"},
        {13, "Hagrid"},
        {14, "Dobby"},
        {15, "Voldemort"}
    };
    Decision decisions[] = {
        
        { "Arrival at Hogwarts", "Visit Diagon Alley", "Attend Sorting Hat Ceremony", "Explore the Forbidden Forest", 2, 3, 3 },
        
        { "Diagon Alley Adventure", "Purchase Wand", "Buy Magical Creatures", "Learn Potion Making", 4, 4, 4 },
        
        { "Sorting Hat Dilemma", "Join Gryffindor", "Become a Slytherin", "Embrace Hufflepuff", 5, 5, 5 },
        
        { "First Day of Classes", "Excel in Charms", "Master Defense Against the Dark Arts", "Ace Herbology", 6, 6, 6 },
        
        { "Friendship Brewing", "Befriend Ron Weasley", "Connect with Hermione Granger", "Team up with Draco Malfoy", 7, 7, 7 },
        
        { "Quidditch Triumph", "Join Gryffindor Quidditch Team", "Start a Quidditch Club", "Become the Quidditch Commentator", 8, 8, 8 },
        
        { "Dark Arts Encounter", "Investigate the Forbidden Corridor", "Brew Polyjuice Potion", "Discover the Room of Requirement", 9, 9, 9 },
        
        { "Triwizard Tournament", "Participate as a Champion", "Help Harry in the Tasks", "Spectate from the Stands", 10, 10, 10 },
        
        { "Battle at the Ministry", "Join the Battle", "Seek Dumbledore's Guidance", "Explore the Department of Mysteries", 11, 11, 11 },
        
        { "Final Confrontation", "Face Voldemort Head-On", "Unite with Hogwarts Allies", "Convince Voldemort to Change", 12, 12, 12 },
        
        { "Victorious Outcome", "Celebrate at the Great Hall", "Reflect at Dumbledore's Office", "Explore the Forbidden Forest", 13, 13, 13 }
    };

    int characterPoints[15] = {0};  

    for (const auto& decision : decisions) {
        printDecision(decision);

        int choice;
        do {
            cout << "Enter your choice (1, 2, or 3): ";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        onChoiceSelected(choice, characterPoints, decision);
    }

    calculateResult(characterPoints, characterMap);

    return 0;
}

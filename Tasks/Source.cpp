#include <iostream>
#include <cstdlib>
#include <string>

int guessMin = 1;
int guessMax = 0;
int correctNumber = 5;
int guess;
bool wonTheGame = false;
int attempts = 0;
std::string username[11];
int highscore[11];
int activeUser = 0;
bool donePlaying = false;
int goAgainChoice;


int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
} 

void getNumberFromUser() {
    std::cin >> guess;
    while (guess < guessMin || guess > guessMax) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid number.\n";
        std::cin >> guess;
    }
}

void getUserName() {
    bool newName = true;
    std::string temp = "";
    if (username[activeUser] == "") {
        std::cout << "Please write your first name:\n";
        std::cin >> temp;
        for (int i = 1; i <= 10; i++) {
            if (temp == username[i]) {
                activeUser = i;
                std::cout << "Your name is saved already, switching to profile " << i << ".\n";
                system("pause");
                newName = false;
                break;
            }
        }
        if (newName == true) {
            username[activeUser] = temp;
        }
    }
}

void userSelection() {
    int userinput;
    std::cout << "Please select one of the following saves:\n";
    for (int i = 1; i <= 10; i++) {
        if (username[i] == "") {
            std::cout << i << ". Empty...";
        }
        else {
            std::cout << i << ". " << username[i] << ", top score: " << highscore[i];
        }
        std::cout << "\n";
    }
    std::cin >> userinput;
    while (userinput < 1 || userinput > 10) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid selection.\n";
        std::cin >> userinput;
    }
    activeUser = userinput;
    system("cls");
}
void guessingProcess() {
    while (wonTheGame == false) {
        if (guess < correctNumber) {
            std::cout << "The correct number is bigger. Try again:\n";
            attempts++;
            getNumberFromUser();
        }
        else if (guess > correctNumber) {
            std::cout << "The correct number is smaller. Try again:\n";
            attempts++;
            getNumberFromUser();
        }
        else if (guess == correctNumber) {
            attempts++;
            std::cout << "That was it! In only " << attempts << " attempts, Congratulations!\n";
            wonTheGame = true;
        }
    }
    system("pause");
}
int goAgainMenu() {
    int userinput;
    system("cls");
    std::cout << "Would you like to: \n1. Try again?\n2. Change user.\n3. Change difficulty.\n4. Exit program.\n";
    std::cin >> userinput;
    while (userinput < 1 || userinput > 4) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid selection.\n";
        std::cin >> userinput;
    }
    return userinput;
    system("cls");
}
void changeDifficulty() {
    std::cout << "Please select how many possible numbers you would like. From 2 to 1000.\n";
    int userinput;
    std::cin >> userinput;
    while (userinput < 2 || userinput > 1000) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid selection.\n";
        std::cin >> userinput;
    }
    guessMax = userinput;
}

void difficultySetting() {
    char userinputyesno;
    bool highscoresExistAlready = false;
    for (int i = 1; i <= 10; i++) {
        if (highscore[i] > 0) {
            highscoresExistAlready = true;
        }
    }
    if (highscoresExistAlready == true) {
        std::cout << "Warning, changing the difficulty will erase the highscores. Proceed? (Y/N)\n";
        std::cin >> userinputyesno;
        while (!(userinputyesno == 'y' || userinputyesno == 'Y' || userinputyesno == 'N' || userinputyesno == 'n')) {
            std::cout << "Please enter a valid answer. Y or N.\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cin >> userinputyesno;
        }
        if (userinputyesno == 'y' || userinputyesno == 'Y') {
            for (int i = 1; i <= 10; i++) {
                highscore[i] = 0;
                username[i] = "";
            }
            changeDifficulty();
        }
        
    }
    else {
        changeDifficulty();
    }
    
    system("cls");
    activeUser = 0;
}



int main() {
    changeDifficulty();
    while (donePlaying == false) {
        if (goAgainChoice == 3) {
            difficultySetting();
        }
        if (goAgainChoice == 2 || activeUser == 0) {
            userSelection();
            getUserName();
        }
        correctNumber = getRandomNumber(guessMin, guessMax);
        system("cls");
        std::cout << "--- Welcome to the great guessing game, " << username[activeUser] << "! ---\n";
        std::cout << "Please enter a number between " << guessMin << " and " << guessMax << " PS: It's " << correctNumber << "\n";
        getNumberFromUser();
        wonTheGame = false;
        attempts = 0;
        guessingProcess();
        if (attempts < highscore[activeUser] || highscore[activeUser] == 0) {
            std::cout << "You beat your previous score by " << (highscore[activeUser] - attempts) << " attempts!";
            highscore[activeUser] = attempts;
        }
        goAgainChoice = goAgainMenu();
        if (goAgainChoice == 4) {
            donePlaying = true;
        }
    }
}
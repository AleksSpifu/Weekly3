#include <iostream>
#include <cstdlib>
int guessMin = 0;
int guessMax = 10;
int correctNumber;
int guess;

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
} 

int main()
{
    correctNumber = getRandomNumber(guessMin, guessMax);
    std::cout << "--- Welcome to the great guessing game! ---\n";
    std::cout << "Please enter a number between " << guessMin << " and " << guessMax << "\n";

}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    while (true) { // Continuously allow the user to start over

        int numSets;
        system("color 3");
        std::cout << "(Hoosier lotto and Powerball mega millions Quickpick Generator): " << std::endl;
        std::cout << "Enter the number of sets to generate: ";
        std::cin >> numSets;

        int option;
        std::cout << "Select an option:\n";
        std::cout << "1 - Hoosier\n";
        std::cout << "2 - Powerball\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if (option != 1 && option != 2) {
            std::cerr << "Invalid option. Exiting." << std::endl;
            return 1;
        }

        for (int setNum = 1; setNum <= numSets; setNum++) {
            int numbers[5]; // Changed to 5 for Powerball

            for (int i = 0; i < 5; i++) {
                // Generate a random number between 1 and 69 for Powerball
                if (option == 2) {
                    // Ensure at least one number is in single digits
                    if (i == 0) {
                        numbers[i] = getRandomNumber(1, 9);
                    }
                    // Ensure at least one number is in the 60s
                    else if (i == 1) {
                        numbers[i] = getRandomNumber(60, 69);
                    }
                    // Generate other random numbers
                    else {
                        numbers[i] = getRandomNumber(1, 69);
                    }
                }
                // Generate a random number between 1 and 48 for Hoosier
                else {
                    // Ensure at least one number is in the 40s
                    if (i == 0) {
                        numbers[i] = getRandomNumber(40, 49);
                    }
                    // Generate other random numbers
                    else {
                        numbers[i] = getRandomNumber(1, 48);
                    }
                }
            }

            // Sort the numbers in ascending order
            std::sort(numbers, numbers + 5);

            // Output the selected numbers
            if (option == 1) {
                std::cout << "Hoosier Set " << setNum << ": ";
                for (int i = 0; i < 5; i++) {
                    std::cout << numbers[i] << " ";
                }
                std::cout << std::endl;
            }
            else {
                std::cout << "Powerball Set " << setNum << ": ";
                for (int i = 0; i < 5; i++) {
                    std::cout << numbers[i] << " ";
                }
                // Generate the second number between 1 and 25 for Powerball
                int secondNumber = getRandomNumber(1, 25);
                std::cout << "Powerball Number (1-25): " << secondNumber << std::endl;
            }
        }

        // Ask if the user wants to start over
        std::cout << "Do you want to start over (1 for Yes, 0 for No): ";
        int startOver;
        std::cin >> startOver;

        if (startOver == 0) {
            break; // Exit the loop if the user doesn't want to start over
        }
    }

    // Sleep for 1 minute (60000 milliseconds)
    Sleep(60000);

    return 0;
}

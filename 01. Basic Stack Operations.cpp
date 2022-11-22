#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <array>
#include <limits>



std::stack<int> readInput(int& numbersToRemove, int& targetNumber) {
    std::stack<int > numbers;
    int input = 0;
    std::cin >> input;
    std::cin >> numbersToRemove;
    std::cin >> targetNumber;
    int currNumber = 0;
    for (int i = 0; i < input; i++)
    {

        std::cin >> currNumber;
        numbers.push(currNumber);
    }

    return numbers;
}

void removeNumbers(std::stack <int>& stackNumbers, int numbersToPop) {
    if (stackNumbers.size() < (size_t)numbersToPop) {
        std::cerr << "invalid" << std::endl;
        return;
    }
    for (int i = 0; i < numbersToPop; i++)
    {

        stackNumbers.pop();
    }
}


std::string findSolution(std::stack <int>& stackNumbers, int targetNumber) {
    if (stackNumbers.empty()) {
        return "0";
    }

    int currNumber = 0;
    int smallestNumber = std::numeric_limits<int>::max();
    while (!stackNumbers.empty())
    {
        currNumber = stackNumbers.top();
        if (targetNumber == currNumber)
        {
            return "true";
        }
        if (smallestNumber > currNumber)
        {
            smallestNumber = currNumber;
        }
        stackNumbers.pop();
    }
    return std::to_string(smallestNumber);
}

void printSolution(const std::string& answer) {

    std::cout << answer << std::endl;
}




int main()
{
    int numbersToRemove = 0;
    int targetNumber = 0;
    std::stack<int> stackNumbers = readInput(numbersToRemove, targetNumber);
    removeNumbers(stackNumbers, numbersToRemove);
    const std::string answer = findSolution(stackNumbers, targetNumber);
    printSolution(answer);






    return 0;
}

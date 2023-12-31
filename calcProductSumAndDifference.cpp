// Copyright (c) 2023 Zak Goneau All rights reserved.
//
// Created by: Zak Goneau
// Date Created: Dec. 28, 2023
// This program calculates the product, sum, and difference
// using a list of numbers from the user.

#include <iomanip>
#include <iostream>
#include <list>
#include <string>

// function definition to calculate product
float CalcProduct(std::list<float> listOfNum) {

    // initialize product
    float product = 1;

    // calculate product
    for (float aNum : listOfNum) {
        product = product * aNum;
    }

    // return product
    return product;
}

// function definition to calculate sum
float CalcSum(std::list<float> listOfNum) {

    // initialize sum
    float sum = 0;

    // calculate sum
    for (float aNum : listOfNum) {
        sum = sum + aNum;
    }

    // return sum
    return sum;
}

// function definition to calculate difference
float CalcDifference(std::list<float> listOfNum) {

    // initialize variables
    float difference = 0;

    // declare iterator and point to first element of list
    std::list<float>::iterator itr = listOfNum.begin();  // Learnt from: https://www.programiz.com/cpp-programming/list

    // declare variable holding first value of list
    float firstValue = *itr;

    // increment iterator
    ++itr;

    // declare variable holding second value of list
    float secondValue = *itr;

    // check if strictly only two numbers
    if (listOfNum.size() == 2) {

        // calculate difference with first two numbers
        difference = listOfNum.front() - listOfNum.back();

        // return difference
        return difference;
    } else {

        // subtract first two numbers
        difference = firstValue - secondValue;

        // for...each loop to subtract all numbers in list
        for (float aNum : listOfNum){
            difference = difference - aNum;
        }

        // add back the first two numbers of list to difference due to being subtracted a second time
        difference = difference + firstValue + secondValue;
        }

        // return difference
        return difference;
    }

int main() {
    // declare variables
    std::string userNum;
    float userNumFloat;
    std::list<float> numList;

    // introduce program to user
    std::cout << "Hello, this program is going to take a list of";
    std::cout << "numbers and calculate the product, sum, and the difference." << std::endl;
    std::cout << "\n";

    // do...while loop to keep asking user for inputs
    do {
        // get user input
        std::cout << "Please enter a number (Type 'EXIT' to exit): ";
        std::cin >> userNum;

        // try converting input to float
        try {
            userNumFloat = std::stof(userNum);

            // push back user number to list
            numList.push_back(userNumFloat);

        // catch invalid inputs
        } catch (std::invalid_argument) {
            // check if user inputted EXIT to exit loop
            if (userNum == "EXIT") {

                // break out of loop
                break;
            }

            // tell user invalid input
            std::cout << "Please enter a valid number. " << userNum << " is not a valid number." << std::endl;
        }
    }
    // check if user inputted EXIT to exit loop
    while (userNum != "EXIT");

    // check if user inputted two or more numbers
    if (numList.size() >= 2) {

        // call function to calculate product
        float calculatedProduct = CalcProduct(numList);

        // call function to calculate sum
        float calculatedSum = CalcSum(numList);

        // call function to calculate difference
        float calculatedDifference = CalcDifference(numList);

        // declare iterator and point to first element of list
        std::list<float>::iterator itr = numList.begin();

        // display all inputted numbers
        std::cout << "\n";
        for (int counter = 0; counter < numList.size(); counter++) {
            std::cout << "your numbers are: " << std::fixed << std::setprecision(2) << *itr << std::endl;

            // increment iterator to display all numbers
            ++itr;
        }

        // if user inputs zero with negatives make sure it becomes zero for multiplication
        if (calculatedProduct == -0) {
            calculatedProduct = 0;
        }

        // display product
        std::cout << "\n";
        std::cout << "The product is: " << std::fixed << std::setprecision(2) << calculatedProduct << std::endl;
        std::cout << "\n";

        // display sum
        std::cout << "The sum is: " << std::fixed << std::setprecision(2) << calculatedSum << std::endl;
        std::cout << "\n";

        // display difference
        std::cout << "The difference is: " << std::fixed << std::setprecision(2) << calculatedDifference << std::endl;

    // tell user they need at least two numbers
    } else {
        std::cout << "\n";
        std::cout << "You need at least two numbers to preform any calculations." << std::endl;
    }
}

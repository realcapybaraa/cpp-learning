#include <iostream>

int main(){

    std::cout << "<-----UNIT CONVERSION CALCULATOR----->" << '\n';

    //code to convert temperature units
    std::cout << "...Temperature Unit Converter..." << '\n';
    float tempCel, tempFah;
    std::cout << "Enter the temperature in Celsius degree: ";
    std::cin >> tempCel;
    tempFah = (tempCel * 9 / 5) + 32;
    std::cout << "Temperature in Fahrenheit degree: " << tempFah << '\n';

    std::cout << "Enter the temperature in Fahrenheit degree: ";
    std::cin >> tempFah;
    tempCel = (tempFah - 32) * 5 / 9;
    std::cout << "Temperature in Celsius degree: " << tempCel << '\n';

    //code to convert distance units
    std::cout << "...Distance Unit Converter..." << '\n';
    float disKm, disM;
    std::cout << "Enter the distance in Kilometer: ";
    std::cin >> disKm;
    disM = disKm * 1000;
    std::cout << "Distance in meter: " << disM << '\n';

    std::cout << "Enter the distance in meter: ";
    std::cin >> disM;
    disKm = disM / 1000;
    std::cout << "Distance in Kilometer: " << disKm << '\n';

    //code to convert time units
    std::cout << "...Time Unit Converter..." << '\n';
    int hour, min, sec;
    std::cout << "Enter the time in hour: ";
    std::cin >> hour;
    min = hour * 60;
    sec = hour * 3600;
    std::cout << "Time in minutes: " << min << '\n';
    std::cout << "Time in seconds: " << sec << '\n';

    std::cout << "Enter the time in minutes: ";
    std::cin >> min;
    sec = min * 60;
    hour = min / 60;
    std::cout << "Time in seconds: " << sec << '\n';
    std::cout << "Time in hour: " << hour << '\n';

   
    std::cout << "Enter the time in seconds: ";
    std::cin >> sec;
    hour = sec / 3600;
    min = sec / 60;
    std::cout << "Time in hour: " << hour << '\n';
    std::cout << "Time in minutes: " << min << '\n';

    //code to convert weight units
    std::cout << "...Weight Unit Converter..." << '\n';
    float kg, gram;
    std::cout << "Enter the weight in kg: ";
    std::cin >> kg;
    gram = kg * 1000;
    std::cout << "Weight in grams: " << gram << '\n';

    std::cout << "Enter the weight in grams: ";
    std::cin >> gram;
    kg = gram / 1000;
    std::cout << "Weight in kg: " << kg << '\n';    

    return 0;
}
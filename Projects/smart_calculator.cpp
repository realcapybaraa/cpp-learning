#include <iostream>

int main(){

    std::cout << '\n' << "<-----SMART CALCULATOR----->" << '\n';

    //code to do basic calculations
    std::cout << "...Basic Calculations..." << '\n';
    double a, b, c, sum, product, subtract, division;
    std::cout <<"Enter any two numbers: ";
    std::cin >> a >> b;

    sum = a + b;
    subtract = a - b;
    product = a * b;
    division = a / b;

    std::cout << "Sum = " << sum << '\n';
    std::cout << "Difference = " << subtract << '\n';
    std::cout << "Product = " << product << '\n';
    std::cout << "Division = " << division << '\n';

    //code to find remainder
    int x, y, modulus;
    std::cout << "Enter any two integral numbers for remainder: ";
    std::cin >> x >> y;
    modulus = x % y;
    std::cout << "Remainder = " << modulus << '\n';

    //code to find percentage value
    std::cout << "...Percentage Calculations..." << '\n';
    double num1, num2, percentValue;
    std::cout << "Enter X percent of Y that you want: ";
    std::cin >> num1 >> num2;
    percentValue = (num1 * num2) / 100;
    std::cout << num1 <<" percent of " << num2 << " is: " << percentValue << '\n';

    //code to find average
    std::cout << "...Average Calculations..." << '\n';
    double average;
    std::cout << "Enter any three numbers for average: ";
    std::cin >> a >> b >> c;
    average = (a + b + c) / 3;
    std::cout << "Average = " << average << '\n';

    //code to calculate discount
    std::cout << "...Discount Calculations..." << '\n';
    double originalPrice, finalPrice, discPercent, discAmount;
    std::cout << "Enter the original price and discount percent: ";
    std::cin >> originalPrice >> discPercent;
    discAmount = (discPercent * originalPrice) / 100;
    finalPrice = originalPrice - discAmount;
    std::cout << "Discout amount : " << discAmount << '\t' << "Final price: " << finalPrice << '\n'; 

    //code to calculate simple interest and total amount
    std::cout << "...Simple Interest Calculations..." << '\n';
    double p, r, t, simpleInterest, totalAmount;
    std::cout << "Enter the principal, rate and time in years: ";
    std::cin >> p >> r >> t;
    simpleInterest = (p * t * r) / 100;
    totalAmount = p + simpleInterest;
    std::cout << "Simple Interest: " << simpleInterest << '\t' << "Total Amount: " << totalAmount << '\n';

    //code to calculate profit
    std::cout << "...Profit Calculations..." << '\n';
    double buyingPrice, sellingPrice, profitAmount, profitPercent;
    std::cout << "Enter buying price and selling price of a product: ";
    std::cin >> buyingPrice >> sellingPrice;
    profitAmount = sellingPrice - buyingPrice;
    profitPercent = (profitAmount / buyingPrice) * 100;
    std::cout << "Profit amount = " << profitAmount << '\t' << "Profit percent = " << profitPercent << "%" << '\n';

    //code to calculate tax
    std::cout << "...Tax Calculations..." << '\n';
    double price, taxPercent, taxAmount;
    std::cout << "Enter the price and tax percentage: ";
    std::cin >> price >> taxPercent;
    taxAmount = (price * taxPercent) / 100;
    finalPrice = price + taxAmount;
    std::cout << "Tax amount = " << taxAmount << '\t' << "Final price = " << finalPrice << '\n';

    return 0;
}
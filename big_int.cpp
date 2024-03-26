#include <iostream>
#include <string>

std::string SUM(std::string first_num, std::string second_num);
std::string SUB(std::string first_num, std::string second_num);

int main() {
    std::string first_num;
    std::string second_num;

    std::cout << "First number >> ";
    std::getline(std::cin, first_num);
    std::cout << "Second number >> ";
    std::getline(std::cin, second_num);

    std::cout << "SUM >> " << SUM(first_num, second_num) << std::endl;
    std::cout << "SUB >> " << SUB(first_num, second_num) << std::endl;

    return 0;
}

std::string SUM(std::string first_num, std::string second_num) {
    std::string sum_res;

    while (first_num.length() != second_num.length()) {
        if (first_num.length() < second_num.length())
            first_num = '0' + first_num;
        else if (second_num.length() < first_num.length())
            second_num = '0' + second_num;
    }

    int carry = 0;

    for (int i = first_num.length() - 1; i >= 0; i--) {
        int sum = (first_num[i] - '0') + (second_num[i] - '0') + carry;
        carry = sum / 10;
        sum %= 10;
        sum_res = std::to_string(sum) + sum_res;
    }

    if (carry)
        sum_res = '1' + sum_res;

    return sum_res;
}

std::string SUB(std::string first_num, std::string second_num) {
    std::string sub_res;


    bool neg_res = false;    
    if (first_num.length() < second_num.length() ||
        (first_num.length() == second_num.length() && first_num < second_num)) {
        
        //
        std::swap(first_num, second_num);
        neg_res = true;
    }


    while (first_num.length() != second_num.length()) {
        second_num = '0' + second_num;
    }

    int borrow = 0;

    for (int i = first_num.length() - 1; i >= 0; i--) {
        int first = first_num[i] - '0';
        int second = second_num[i] - '0';


        first -= borrow;

        if (first < second) {
            first += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }


        int sub = first - second;
        sub_res = std::to_string(sub) + sub_res;
    }


    /////
    sub_res.erase(0, std::min(sub_res.find_first_not_of('0'), sub_res.size() - 1));

    if (neg_res && sub_res != "0") {
        sub_res = "-" + sub_res;
    }

    return sub_res;
}

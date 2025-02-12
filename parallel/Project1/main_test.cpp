#include <iostream>
#include <string>
#include <vector>
#include <future>
#include <cmath>


int calculate_mod(const std::string& number_part) {
    int remainder = 0;
    for (char digit : number_part) {
        remainder = (remainder * 10 + (digit - '0')) % 17;
    }
    return remainder;
}


int parallel_mod(const std::string& number, int num_threads) {
    int length = number.size();
    int part_length = (length + num_threads - 1) / num_threads; 

    std::vector<std::future<int>> futures;
    std::vector<int> remainders(num_threads, 0);
    std::vector<int> part_lengths(num_threads, 0);

    
    for (int i = 0; i < num_threads; ++i) {
        int start = i * part_length;
        if (start >= length) break; 
        int end = std::min(start + part_length, length);
        std::string part = number.substr(start, end - start);

       
        futures.push_back(std::async(std::launch::async, calculate_mod, part));
        part_lengths[i] = end - start; 
    }


    int result = 0;
    int current_power_of_ten = 1;

    for (int i = num_threads - 1; i >= 0; --i) {
        if (i < futures.size()) {
            int part_remainder = futures[i].get();
            result = (result + part_remainder * current_power_of_ten) % 17;

           
            for (int j = 0; j < part_lengths[i]; ++j) {
                current_power_of_ten = (current_power_of_ten * 10) % 17;
            }
        }
    }

    return result;
}

int main() {
   
    std::string number = "1234567890";
    int num_threads = 4; 

    int result = parallel_mod(number, num_threads);
    std::cout << "Mod 17 (test1): " << result << std::endl;

    
    number += "0000"; 
    result = parallel_mod(number, num_threads);
    std::cout << "Mod 17 (test2): " << result << std::endl;

    return 0;
}

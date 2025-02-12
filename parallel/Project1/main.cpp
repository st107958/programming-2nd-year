#include <iostream>
#include <string>
#include <vector>
#include <future>
#include <numeric>

//#define LEN 10000


int calculate_mod(const std::string& number_part) 
{
    int remainder = 0;
    std::string numbs = "1234567890";

    for (int i = 0; i < number_part.size(); ++i)
    {
        char symb = number_part[i];
        bool found = false;
        for (char c : numbs) {
            if (c == symb) {
                found = true;
                break;
            }
        }

        if (found == false) throw "INCORRECT STRING";

        int digit = symb - '0';
        remainder = (remainder * 10 + digit);
        remainder = remainder % 17;

    }

   /* for (char symb : number_part) 
    {
        if (!(numbs.find(symb))) continue;
        int digit = symb - '0';
        remainder = (remainder * 10 + (digit)) % 17;
    }*/
    return remainder;
}


int mod(const std::string& number, int num_threads) 
{
   /* int len = 10000;
    int part_length = len / num_threads;*/

    int len = number.size();
    int part_length = (len + num_threads - 1) / num_threads;

    std::vector<std::future<int>> futures;
    std::vector<int> powers_of_ten(num_threads, 1);
    std::vector<int> starts;

   
    for (int i = 0; i < num_threads; ++i) 
    {
        int start = i * part_length;

        if (start >= len) break;
        
        int end = std::min(start + part_length, len);

        std::string part = number.substr(start, end - start);

        futures.push_back(std::async(std::launch::async, calculate_mod, part));
        
        for (int j = 0; j < end - start; ++j) 
        {
            powers_of_ten[i] = (powers_of_ten[i] * 10) % 17;
        }
    }

    
    int result = 0;
    int power_of_ten = 1;

    /*std::vector<int> results;

    for (int i = 0; i < futures.size(); ++i) 
    {
        results.push_back(futures[i].get());
    }


    for (int i = 0; i < results.size(); ++i)
    {
        power_of_ten = len - i * part_length;
        result = result + results[i] * power_of_ten;
    }

    result = result % 17;*/

    /*for (int i = num_threads - 1; i >= 0; --i) {
        int part_remainder = futures[i].get();
        for (int j = 0; j < part_length; ++j) {
            power_of_ten = (power_of_ten * 10) % 17;
        }
        result = (result * power_of_ten + part_remainder) % 17;
    }*/


 
    for (int i = num_threads - 1; i >= 0; --i) {
        if (i < futures.size()) {
            int part_remainder = futures[i].get();
            result = (result * powers_of_ten[i] + part_remainder) % 17;
        }
    }

    return result;
}

int main() {
    std::string number = "123456789000"; 
    int num_threads = 4;

    int result = mod(number, num_threads);
    std::cout << "Mod: " << result << std::endl;


    /*std::string numbs = "1234567890";
    for (char symb : number)
    {
        bool found = false;
        for (char c : numbs) {
            if (c == symb) {
                found = true;
                break;
            }
        }

        if (found == false) throw;

        int digit = symb - '0';
      
    }*/


    return 0;
}

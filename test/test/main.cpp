#include <iostream>
#include <random>
using namespace std;

//long int preprocess() 
//{
//    const int max_power = 60;
//    long int flower_prices[max_power];
//
//    for (int i = 0; i < max_power; i++) 
//    {
//        flower_prices[i] = (1LL << i);
//    }
//
//    int* three_sums{new int[1]};
//    int l = 0;
//
//    for (int i = 0; i < max_power; i++)
//    {
//        for (int j = i + 1; j < max_power; j++) 
//        {
//            for (int k = j + 1; k < max_power; k++) 
//            {
//                three_sums[l] = flower_prices[i] + flower_prices[j] + flower_prices[k];
//                l++;
//            }
//        }
//    }
//
//    return *three_sums, l;
//}

int* preprocess() {
    const int max_power = 60;
    const int max_size = max_power * (max_power - 1) * (max_power - 2) / 6; // Комбинации C(60,3)

    long long* flower_prices = new long long[max_power];
    for (int i = 0; i < max_power; i++) {
        flower_prices[i] = 1LL << i;
    }

    int* three_sums = new int[max_size];
    int index = 0;

    for (int i = 0; i < max_power; i++) {
        for (int j = i + 1; j < max_power; j++) {
            for (int k = j + 1; k < max_power; k++) {
                three_sums[index++] = flower_prices[i] + flower_prices[j] + flower_prices[k];
            }
        }
    }

    delete[] flower_prices;
    return  three_sums;
}

long int can_buy_bouquet(long int money, int three_sums, int length) 
{
    int* sums = &three_sums;
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        max = sums[i] < money ? sums[i] : -1;
    }

    return max;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    const int days = 100000;

    int length;
    int* three_sums;
    &three_sums = preprocess();

    long int money[days];

    for (int i = 0; i < days; i++)
    {
        money[i] = rand() % 10000000000;
    }


    for (int i = 0; i < days; i++) {
        cout << can_buy_bouquet(money[i], three_sums, length) << "\n";
    }

    return 0;
}

# pragma once
#include <vector>
#include <limits>

class Statistic {
private:
    std::vector<int> sales;
public:
    Statistic(std::vector<int> const & a) : sales(a.begin(), a.end()) {
    }

    ~Statistic() {
        sales.clear();
    }

    long long sum_sales(const std::vector<int> & vec);

    int average_sales(const std::vector<int> & vec);

    int months_sales_below_average(const std::vector<int> & vec);

    int months_sales_above_average(const std::vector<int> &vec);

    std::vector<int> max_sales(const std::vector<int> & vec);

    std::vector<int> min_sales(const std::vector<int> & vec);
};

void printMenu();

std::vector<int> inp_rand();

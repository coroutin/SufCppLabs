#include <vector>
#include <limits>
#include <string>
#include <sstream>

class Statistic {
private:
    std::vector<int> sales;

public:

    Statistic(std::vector<int> const & a) : sales(a.begin(), a.end()) {}

    Statistic(int * a, size_t n) : sales(a, a + n) {}

    Statistic(std::string a) {
        std::istringstream ss(a);
        int val;
        while (ss >> val) {
            sales.push_back(val);
        }
    }

    Statistic(Statistic const & other) : sales(other.sales.begin(), other.sales.end()) {}

    Statistic & operator=(Statistic const & other) {
        if (this != &other) {
            sales.assign(other.sales.begin(), other.sales.end());
        }
        return *this;
    }

    ~Statistic() { sales.clear(); }

    long long sum_sales() const {
        long long sum = 0;
        for (int i : sales) sum += i;
        return sum;
    }

    int average_sales() const {
        if (sales.empty()) return 0;
        return sum_sales() / sales.size();
    }

    int months_sales_below_average() const {
        int avg = average_sales(), count = 0;
        for (int i : sales) if (i < avg) count++;
        return count;
    }

    int months_sales_above_average() const {
        int avg = average_sales(), count = 0;
        for (int i : sales) if (i > avg) count++;
        return count;
    }

    std::vector<int> max_sales() const {
        std::vector<int> indices;
        if (sales.empty()) return indices;
        int max_val = std::numeric_limits<int>::min();
        for (int i : sales) if (i > max_val) max_val = i;
        for (int i = 0; i < (int)sales.size(); i++)
            if (sales[i] == max_val) indices.push_back(i);
        return indices;
    }

    std::vector<int> min_sales() const {
        std::vector<int> indices;
        if (sales.empty()) return indices;
        int min_val = std::numeric_limits<int>::max();
        for (int i : sales) if (i < min_val) min_val = i;
        for (int i = 0; i < (int)sales.size(); i++)
            if (sales[i] == min_val) indices.push_back(i);
        return indices;
    }
};
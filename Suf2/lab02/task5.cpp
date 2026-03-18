#include <limits>

class Statistic {
private:
    std::pmr::vector<int> sales;
public:
    Statistic(std::vector<int> const & a) : sales(a.begin(), a.end()) {
    }

    ~Statistic() {
        sales.clear();
    }

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
        int count = 0;
        for (int i : sales) if (i < average_sales()) count++;
        return count;
    }

    int months_sales_above_average() const {
        int count = 0;
        for (int i : sales) if (i > average_sales()) count++;
        return count;
    }

    std::vector<int> max_sales() const {
        std::vector<int> indices;
        if (sales.empty()) return indices;
        int max_sales = -std::numeric_limits<double>::infinity();
        for (int i : sales) if (i > max_sales) max_sales = i;
        for (int i = 0; i < (int)sales.size(); i++)
            if (sales[i] == max_sales) indices.push_back(i);
        return indices;
    }

    std::vector<int> min_sales() const {
        std::vector<int> indices;
        if (sales.empty()) return indices;
        int min_sales = std::numeric_limits<double>::infinity();
        for (int i : sales) if (i < min_sales) min_sales = i;
        for (int i = 0; i < (int)sales.size(); i++)
            if (sales[i] == min_sales) indices.push_back(i);
        return indices;
    }
};

#include <iostream>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

class AccountingSystem {
public:
    void addRecord(const std::string& date, const std::string& category, int amount) {
        records[date][category] += amount;
    }

    int queryTotal(const std::string& date) {
        if (records.find(date) == records.end()) {
            return 0;
        }
        int total = 0;
        for (const auto& pair : records[date]) {
            total += pair.second;
        }
        return total;
    }

    int categoryTotal(const std::string& category) {
        int total = 0;
        for (const auto& dateMap : records) {
            if (dateMap.second.find(category)!= dateMap.second.end()) {
                total += dateMap.second.at(category);
            }
        }
        return total;
    }

private:
    std::unordered_map<std::string, std::map<std::string, int>> records;
};

int main() {
    AccountingSystem system;
    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream iss(input);
        std::string command;
        iss >> command;
        if (command == "ADD_RECORD") {
            std::string date, category;
            int amount;
            iss >> date >> category >> amount;
            system.addRecord(date, category, amount);
        } else if (command == "QUERY_TOTAL") {
            std::string date;
            iss >> date;
            int total = system.queryTotal(date);
            if (total == 0) {
                std::cout << "NO RECORD" << std::endl;
            } else {
                std::cout << total << std::endl;
            }
        } else if (command == "CATEGORY_TOTAL") {
            std::string category;
            iss >> category;
            int total = system.categoryTotal(category);
            if (total == 0) {
                std::cout << "NO RECORD" << std::endl;
            } else {
                std::cout << total << std::endl;
            }
        }
    }
    return 0;
}
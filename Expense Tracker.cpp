

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Expense {
public:
    std::string category;
    std::string description;
    double amount;
    
    Expense(std::string cat, std::string desc, double amt) 
        : category(cat), description(desc), amount(amt) {}
    
    void display() {
        std::cout << std::left << std::setw(15) << category 
                  << std::setw(25) << description 
                  << "$" << std::fixed << std::setprecision(2) << amount << "\n";
    }
};

class ExpenseTracker {
    std::vector<Expense> expenses;
    double total = 0;
public:
    void addExpense(std::string cat, std::string desc, double amt) {
        expenses.push_back(Expense(cat, desc, amt));
        total += amt;
        std::cout << "Expense recorded!\n";
    }
    
    void showSummary() {
        std::cout << "\n=== Expense Summary ===\n";
        std::cout << std::left << std::setw(15) << "Category" 
                  << std::setw(25) << "Description" << "Amount\n";
        std::cout << std::string(50, '-') << "\n";
        
        for(auto& exp : expenses) exp.display();
        
        std::cout << std::string(50, '-') << "\n";
        std::cout << "Total: $" << std::fixed << std::setprecision(2) << total << "\n";
    }
    
    void showByCategory(std::string cat) {
        double catTotal = 0;
        std::cout << "\nExpenses in category: " << cat << "\n";
        for(auto& exp : expenses) {
            if(exp.category == cat) {
                exp.display();
                catTotal += exp.amount;
            }
        }
        std::cout << "Category total: $" << catTotal << "\n";
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.addExpense("Food", "Groceries", 45.50);
    tracker.addExpense("Transport", "Gas", 35.00);
    tracker.addExpense("Food", "Restaurant", 28.75);
    tracker.showSummary();
    tracker.showByCategory("Food");
    return 0;
}

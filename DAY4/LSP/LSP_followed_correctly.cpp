#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;


class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        CurrentAccount() { 
            balance = 0; 
        }
    
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
    
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
    };

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient( vector<WithdrawableAccount*> withdrawableAccounts, 
        vector<DepositOnlyAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts = withdrawableAccounts; 
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        for (WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};

// int main() {
//     vector<WithdrawableAccount*> withdrawableAccounts;
//     withdrawableAccounts.push_back(new SavingAccount());
//     withdrawableAccounts.push_back(new CurrentAccount());

//     vector<DepositOnlyAccount*> depositOnlyAccounts;
//     depositOnlyAccounts.push_back(new FixedTermAccount());

//     BankClient* client = new BankClient (withdrawableAccounts, depositOnlyAccounts);
//     client->processTransactions();

//     return 0;
// }

int main() {
    // Creating subclass instances but referring to them using base class pointers
    // to demonstrate proper LSP usage — these types guarantee substitutability.

    // SEE BELOW REF TYPE IS OF PARENT BUT WHEN USING NEW, CALLING THE ACTUAL NEEDED FUNC THAT IS BASICALLY WHAT LSP WANTS TO SAY

    // WithdrawableAccount includes both deposit() and withdraw()
    WithdrawableAccount* savings = new SavingAccount();       // LSP: SavingAccount IS-A WithdrawableAccount
    WithdrawableAccount* current = new CurrentAccount();      // LSP: CurrentAccount IS-A WithdrawableAccount

    // DepositOnlyAccount includes only deposit()
    DepositOnlyAccount* fixed = new FixedTermAccount();       // LSP: FixedTermAccount IS-A DepositOnlyAccount

    // Group accounts by capability — avoids type checking and respects interface contracts
    vector<WithdrawableAccount*> withdrawableAccounts = { savings, current };
    vector<DepositOnlyAccount*> depositOnlyAccounts = { fixed };

    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}


// 🧠 Why This Follows LSP
// ✅ WithdrawableAccount* savings = new SavingAccount();
// You are relying only on the behavior guaranteed by the interface, not on internal details.

// ✅ BankClient doesn’t care what kind of account it’s dealing with — as long as the contract (deposit() or withdraw()) is respected.

// ❌ No need for typeid, dynamic_cast, or branching — so no LSP violation.
    
    

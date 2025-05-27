# ✅ Open/Closed Principle (OCP) – Combined Theory + C++ Code

## 📘 What is OCP?

> The **O** in **SOLID** stands for the **Open/Closed Principle**.

### **Definition**

> **Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.**

This means you should be able to **add new functionality** without **changing existing, tested code**.

---

## 🔌 Real-Life Analogy — Travel Adapter

Imagine you travel from **India to the UK**. Your Indian charger doesn’t fit UK sockets. Do you:

* ❌ Modify the charger? (risky!)
* ✅ Use an adapter?

**The adapter adds functionality without changing the charger.**
This is the essence of OCP: **add via extension, don’t modify the core**.

---

## 🧾 Real-World Use Case — Invoicing System (Tax Calculation)

Let’s assume you’re building an invoicing system that must support **region-based tax rules**:

* India → GST: 18%
* US → Sales Tax: 8%
* UK → VAT: 12%

Over time, new regions (e.g., Germany) will be added.

---

## ❌ Bad Design — Violates OCP (Hardcoded Logic)

```cpp
class Invoice {
public:
    double calculateTotal(const std::string& region, double amount) {
        if (region == "India") return amount + amount * 0.18;
        else if (region == "US") return amount + amount * 0.08;
        else if (region == "UK") return amount + amount * 0.12;
        else return amount; // No tax for unknown regions
    }
};

```

### ❌ Problems:

* Each time a new region is added, this method **must be modified**.
* Risk of **breaking existing functionality**.
* Violates **OCP**.
* Not easily **testable** or **scalable**.

---

## ✅ Good Design — Follows OCP (Extensible via Polymorphism)

### 1️⃣ Create a Tax Strategy Interface

```cpp
#include <iostream>
using namespace std;

// Tax strategy interface
class TaxCalculator {
public:
    virtual double calculateTax(double amount) = 0;
};
```

---

### 2️⃣ Create Region-Specific Implementations

```cpp
// Region-specific tax calculators
class IndiaTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.18;
    }
};

class USTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.08;
    }
};

class UKTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.12;
    }
};
// New region — added without modifying existing classes
class GermanyTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.15;
    }
};
```

---

### 3️⃣ Invoice Class (Uses Dependency Injection)

```cpp
// Invoice class using dependency injection
class Invoice {
private:
    double amount;
    TaxCalculator* taxCalculator;

public:
    Invoice(double amount, TaxCalculator* taxCalculator) {
        this->amount = amount;
        this->taxCalculator = taxCalculator;
    }

    double getTotalAmount() {
        return amount + taxCalculator->calculateTax(amount);
    }
};

```

---

### 4️⃣ Main Function (Client Code)

```cpp
int main() {
    double amount = 1000.0;

    // Create IndiaTaxCalculator object on the heap
    TaxCalculator* indiaTax = new IndiaTaxCalculator();

    // Invoice composes/uses a TaxCalculator (here IndiaTaxCalculator)
    Invoice indiaInvoice(amount, indiaTax);
    cout << "Total (India): ₹" << indiaInvoice.getTotalAmount() << endl;

    // Clean up dynamically allocated object
    delete indiaTax;

    TaxCalculator* usTax = new USTaxCalculator();
    Invoice usInvoice(amount, usTax);
    cout << "Total (US): $" << usInvoice.getTotalAmount() << endl;
    delete usTax;

    TaxCalculator* ukTax = new UKTaxCalculator();
    Invoice ukInvoice(amount, ukTax);
    cout << "Total (UK): £" << ukInvoice.getTotalAmount() << endl;
    delete ukTax;

    TaxCalculator* germanyTax = new GermanyTaxCalculator();
    Invoice germanyInvoice(amount, germanyTax);
    cout << "Total (GERMANY): £" << germanyInvoice.getTotalAmount() << endl;
    delete germanyTax;
    return 0;
}
```

---

## 💡 How This Follows OCP

* You can **extend** the system by adding a new `TaxCalculator` subclass.
* No changes are needed in the existing `Invoice` or other tax classes.
* Maintains stability, testability, and scalability.

---

## 🛠 When to Apply OCP

Apply OCP when:

* A module **is likely to change** (e.g., business rules, regions, formats).
* You need to avoid **touching tested code** when adding new functionality.
* You're building **plugins**, **frameworks**, or **policy-based systems**.
* A class starts becoming a **God Object** (doing too much).

---

## ❌ Common Misconceptions about OCP

| Misconception                               | Reality                                                            |
| ------------------------------------------- | ------------------------------------------------------------------ |
| "OCP means code should never change again." | OCP means **core logic shouldn't be touched** unnecessarily.       |
| "OCP creates too many classes."             | Yes, but it's a **trade-off for clean design** and testability.    |
| "OCP makes code hard to read."              | Only in small projects — in large systems, it improves clarity.    |
| "OCP should be applied upfront."            | Not always — apply when **extension becomes necessary**.           |
| "Refactoring violates OCP."                 | Refactoring is often the **first step to achieve OCP compliance**. |

---

## 🧠 Final Interview Notes

* OCP promotes **extensibility without modification**.
* Use **interfaces + polymorphism** to implement.
* Supports **clean architecture** and **plugin-like behavior**.
* **C++ Strategy Pattern** is a common way to apply OCP.
* Best when you observe **repeating conditions** or **switch logic**.



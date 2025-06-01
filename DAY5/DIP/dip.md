
# 📌 Dependency Inversion Principle (DIP) – Notes


## 📖 **Pre-requisites**

To understand DIP better, you should know:

* **High-Level Modules**
  These are classes that contain core logic or decision-making.
  *Example: CEO (plans strategies)*

* **Low-Level Modules**
  These handle implementation details — databases, APIs, etc.
  *Example: Employees (do the actual work)*

* **Abstraction**
  A layer (like an interface or abstract class) that hides the implementation details.

---

## 🧠 **Definition**

> “High-level modules should not depend on low-level modules.
> Both should depend on **abstractions**.
> Abstractions should not depend on details.
> Details should depend on abstractions.”

In short: Both high- and low-level components should communicate through **interfaces**, not direct dependencies.

---

## 🍕 **Real-life Analogy: Food Delivery App**

* You (user): high-level module
* Food delivery app: abstraction
* Restaurant or chef: low-level module

You're not contacting the chef directly — you're using an abstraction (app) that **hides the details**.

---

## 📺 **Example: Netflix Recommendation Engine**

Netflix has multiple strategies to recommend content:

* Recently Added
* Trending Now
* Genre-Based

---

## ❌ Without DIP – Tightly Coupled Code

```cpp
// Low-level module
class RecentlyAdded {
public:
    void getRecommendations() {
        std::cout << "Showing recently added content...\n";
    }
};

// High-level module (depends directly on low-level one)
class RecommendationEngine {
    RecentlyAdded recommender; // tightly coupled

public:
    void recommend() {
        recommender.getRecommendations();
    }
};
```

### 🔴 Issues:

* Can't switch to other strategies (Trending, Genre) without **modifying** `RecommendationEngine`.

---

## ✅ With DIP – Using Abstraction

### Step 1: Define abstraction (interface)

```cpp
class RecommendationStrategy {
public:
    virtual void getRecommendations() = 0;
    virtual ~RecommendationStrategy() = default;
};
```

### Step 2: Implement different strategies

```cpp
class RecentlyAdded : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing recently added content...\n";
    }
};

class TrendingNow : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing trending content...\n";
    }
};

class GenreBased : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing content based on your favorite genres...\n";
    }
};
```

### Step 3: High-level module depends on abstraction

```cpp
class RecommendationEngine {
    RecommendationStrategy* strategy; // pointer to abstraction

public:
    RecommendationEngine(RecommendationStrategy* s) : strategy(s) {}

    void recommend() {
        strategy->getRecommendations();
    }
};
```

### Step 4: Driver code

```cpp
int main() {
    RecommendationStrategy* strategy = new TrendingNow();
    RecommendationEngine engine(strategy);
    engine.recommend();  // Output: Showing trending content...

    // Switching strategy at runtime
    strategy = new GenreBased();
    RecommendationEngine engine2(strategy);
    engine2.recommend();  // Output: Showing content based on your favorite genres...

    delete strategy; // Don't forget to clean up if using raw pointers
    return 0;
}
```

---

## 🧠 Key Benefits of DIP

* **Flexibility**: Easily switch or upgrade implementations without touching the main logic.
* **Testability**: Abstractions can be mocked for unit testing.
* **Reusability**: Strategies can be reused in different parts of the app.
* **Maintainability**: Changing one part doesn’t affect others.
* **Scalability**: Easily add new features (e.g., AI-based recommendation) without rewriting core logic.

---

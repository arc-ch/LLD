
# Interface Segregation Principle (ISP) — SOLID Principles

## 📘 Introduction

The **Interface Segregation Principle (ISP)** is one of the five **SOLID** principles of object-oriented programming. These principles help us write **clean**, **scalable**, and **maintainable** code.

---

## 🧠 Definition

> **"Don't force a class to depend on methods it does not use."**

---

## 🚕 Understanding ISP (with an Uber Example)

Imagine you're using **Uber** as a **rider**. You care about:

* Booking a ride
* Tracking the driver
* Making payments

You **do not** care about:

* Accepting ride requests
* Tracking earnings
* Verifying licenses

### ❌ Bad Design: Violates ISP

Imagine if Uber had one large interface for both **riders** and **drivers**:

```cpp
// Bad interface violating ISP
class IUser {
public:
    virtual void bookRide() = 0;
    virtual void trackDriver() = 0;
    virtual void pay() = 0;
    virtual void acceptRide() = 0;
    virtual void trackEarnings() = 0;
    virtual void verifyLicense() = 0;
    virtual ~IUser() {}
};

class Rider : public IUser {
public:
    void bookRide() override { /*...*/ }
    void trackDriver() override { /*...*/ }
    void pay() override { /*...*/ }

    // Forced to implement irrelevant methods
    void acceptRide() override {}  // ❌ Not needed!
    void trackEarnings() override {} // ❌ Not needed!
    void verifyLicense() override {} // ❌ Not needed!
};
```

### 🧹 What's wrong?

* **Rider** is forced to implement methods it will never use.
* Code is harder to read, test, and maintain.
* Violation of ISP!

---

### ✅ Good Design: Follows ISP

Instead, separate responsibilities into **smaller, focused interfaces**:

```cpp
// Good interface design using ISP
class IRider {
public:
    virtual void bookRide() = 0;
    virtual void trackDriver() = 0;
    virtual void pay() = 0;
    virtual ~IRider() {}
};

class IDriver {
public:
    virtual void acceptRide() = 0;
    virtual void trackEarnings() = 0;
    virtual void verifyLicense() = 0;
    virtual ~IDriver() {}
};

class Rider : public IRider {
public:
    void bookRide() override { /*...*/ }
    void trackDriver() override { /*...*/ }
    void pay() override { /*...*/ }
};

class Driver : public IDriver {
public:
    void acceptRide() override { /*...*/ }
    void trackEarnings() override { /*...*/ }
    void verifyLicense() override { /*...*/ }
};
```

### 🎯 Result

* **Rider** implements only what it needs.
* **Driver** implements only what it needs.
* Interfaces are **slim** and **purpose-specific**.

---

## ✅ Benefits of Applying ISP

* **Cleaner Codebase**: No unnecessary method implementations.
* **Better Flexibility**: Easy to change parts independently.
* **High Maintainability**: Focused interfaces are easier to test and understand.
* **Fewer Bugs**: No accidental method usage or overrides.
* **Scalability**: Adding new roles (e.g., delivery partner) becomes easier.

---

## 🔍 When to Apply ISP

Apply the Interface Segregation Principle when:

* A class implements methods it **doesn't use**.
* An interface grows **too large** and serves multiple unrelated clients.
* Adding a new feature means modifying **many unrelated classes**.
* You're designing **APIs or plugins**, and exposing only relevant methods improves usability.

---

## 🧾 Conclusion

The **Interface Segregation Principle** is about giving **each class only what it needs**. Don’t overload classes with irrelevant methods. Like Uber doesn’t show driver options to passengers — **only show what's needed**.

### 💡 Remember:

> ❌ Fat interfaces are bad.
> ✅ Slim, purpose-specific interfaces are good.

cts.

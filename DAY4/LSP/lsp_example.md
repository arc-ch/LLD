### Consider the example of a Notification system:


Assume we wish to introduce some new type of notifications, say Email Notification or Text Notification.
In such a case, we can create a new class for each type of notification, and we can easily extend the system without breaking existing code using the Liskov Substitution Principle.
```cpp
#include <iostream>
using namespace std;

class Notification {
public:
    virtual void sendNotification() {
        cout << "Notification sent" << endl;
    }
    virtual ~Notification() = default;  // virtual destructor for safety
};

class EmailNotification : public Notification {
public:
    void sendNotification() override {
        cout << "Email Notification sent" << endl;
    }
};

class TextNotification : public Notification {
public:
    void sendNotification() override {
        cout << "Text Notification sent" << endl;
    }
};

int main() {
    Notification* notification = new EmailNotification();

    notification->sendNotification();

    delete notification;
    return 0;
}
```

Great! This example perfectly demonstrates **Liskov Substitution Principle (LSP)** in a simple and clear way. Let me break it down for you:

---

## What’s going on here?

* You have a base class: `Notification` with a method `sendNotification()`.
* Two subclasses: `EmailNotification` and `TextNotification`, both **override** `sendNotification()`.
* In `main()`, instead of creating a `Notification` object, you create an `EmailNotification` object **but assign it to a `Notification` reference**.

```cpp
Notification notification = new EmailNotification();
notification.sendNotification();  // Calls EmailNotification's version
```

---

## Why is this a great example of **LSP**?

1. **Substitution:**
   Anywhere a `Notification` is expected, you can substitute **any subclass** (`EmailNotification` or `TextNotification`) without breaking the code.

2. **Polymorphism:**
   The correct `sendNotification()` method is called based on the **actual object type** (`EmailNotification`), not the reference type (`Notification`).

3. **Behavior preserved:**
   The `sendNotification()` method works as expected for any subclass, no surprises or errors.

---


## Summary (for notes)

* **LSP says:** Objects of a superclass shall be replaceable with objects of subclasses without affecting correctness.
* Here, `Notification notification = new EmailNotification();` shows **LSP in action**.
* Calling `notification.sendNotification()` behaves correctly regardless of which subclass instance it points to.


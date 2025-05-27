### Why Does LSP Matter?

When LSP is violated, the code becomes:

*   **Unpredictable:** Code relying on base class assumptions will break with certain subclasses.
    
*   **Hard to Maintain:** Adding new subclasses requires rechecking all usages.
    
*   **Bug-Prone:** Runtime errors, wrong outputs, or inconsistent behavior.
    
*   **Less Reusable:** Substituting child objects becomes dangerous.
    
*   **Tight Coupling:** Client code ends up getting tightly coupled to specific types, making it less maintainable.
    

Hence, to avoid these problems while working on a huge codebase, it is recommended to follow the Liskov Substitution Principle (LSP) (wherever possible).

### How to Spot LSP Violations?

To spot LSP violations, ask yourself these questions:

*   Does the subclass **override** methods in a way that **changes meaning or assumptions**?
    
*   Can I replace the base class with the subclass **everywhere** without side effects?
    
*   Does the subclass throw **unexpected exceptions** or return **wrong values**?
    
*   Does the subclass **weaken** any preconditions or **strengthen** postconditions?
    

If the answer to any of these questions is "yes", there might be a LSP violation in the code.

### Key Principles to Follow

There are some key principles to follow to avoid LSP violations. These are:

*   Subclasses should **honor the contract (expectations)** of the parent class.
    
*   Avoid **overriding methods** in a way that changes behavior drastically.
    
*   Prefer **composition** over inheritance when possible.
    
*   Think in terms of **interfaces** and behavioral compatibility.
    
*   Subclass should only **extend**, not **restrict** behavior.

# 🏁 Introduction

## 📖 Formal Definition:

### 📘 UML Class Diagram – Introduction

A **UML Class Diagram** provides a high-level overview of the **system architecture**. It captures the system's:

* ✅ **Classes**
* ✅ **Interfaces**
* ✅ **Enumerations**
* ✅ Their **attributes** and **operations** (methods)
* ✅ And the **relationships** among them

   It plays a key role in both **forward** and **reverse engineering** processes, and is widely used in modeling **object-oriented systems**.

Class diagrams support various design activities such as:
* 🧠 **Domain modeling**
* 🗃️ **Data modeling**
* 🏗️ **Architectural representation** of systems

These diagrams are often created during the **early stages of the software development lifecycle** and are refined as the project progresses.
Looking at a class diagram, you should be able to **quickly grasp the system's structure** and understand **how different components interact** with each other.
This is especially helpful for:
* 🧑‍💻 New developers joining a project
* 👥 Stakeholders who need to understand the system's design **without reading code**




# 🏷️ UML Class Notations

### 1. 🏛️ Class Representation

A class in UML is depicted as a rectangle divided into three compartments:

* **Top compartment:** Contains the class name (**bold** and centered).
* **Middle compartment:** Lists the attributes.
* **Bottom compartment:** Lists the operations (methods).
  
![image](https://github.com/user-attachments/assets/8b0194b5-175a-4e9a-aeda-de28313ad3df)

Each attribute or method is listed with its visibility marker, name, and type (for attributes) or return type (for methods). Parameters for methods are also specified in parentheses.

---

### 2. 🔐 Visibility Markers

Visibility markers define access levels for attributes and operations:

| Marker | Meaning                                          |
| ------ | ------------------------------------------------ |
| +      | **Public** (accessible from anywhere)            |
| -      | **Private** (accessible only within class)       |
| #      | **Protected** (accessible in class & subclasses) |
| \~     | **Package** (accessible within the same package) |

These markers help enforce **encapsulation**, a core principle in object-oriented design.

---

### 3. 📋 Attributes and Methods Syntax

* **Attributes:**
  `visibility name: Type [multiplicity] = DefaultValue`

  * **visibility:** Access level (+, -, #, \~)
  * **name:** Attribute name
  * **Type:** Data type (e.g., int, String)
  * **multiplicity:** Optional (e.g., 0..1, 1..\*)
  * **DefaultValue:** Optional default value

Example:
`+ age: int = 21` means public attribute `age` of type int with default 21

![image](https://github.com/user-attachments/assets/f4a0cfcf-66be-4b85-91bc-c3b44674d922)

* **Methods (Operations):**
  `visibility name(parameterName1: Type1, ...): ReturnType`

  * **visibility:** Access level (+, -, #, \~)
  * **name:** Method name
  * **parameterName:** Parameter name(s)
  * **Type:** Parameter type(s)
  * **ReturnType:** Method return type

Example:
`- isAdult(age:int): boolean` means private method `isAdult` with int parameter `age` returning boolean.

![image](https://github.com/user-attachments/assets/cc59a840-d095-4162-b85e-8a954664cb32)

Optional elements like multiplicity, default values, and stereotypes (e.g., `<<constructor>>`, `<<static>>`) can be included to enrich the diagram.

---

### 4. 🛠️ Interface

An interface defines a contract that other classes must follow. It contains only abstract methods (no implementation).

UML notation for interfaces:

* Stereotype `<<interface>>` above the name
* Methods listed without implementations

By default, interfaces don’t include attributes except constants, which may be shown in a separate compartment.

---

### 5. 📐 Abstract Class

An abstract class cannot be instantiated and may contain both implemented and unimplemented (abstract) methods.

UML representation:

* Stereotype `<<abstract>>` above class name
* Class name italicized

---
🆚 Summary: Abstract Class vs Interface in C++

| Feature              | Abstract Class                | Interface (Simulated via Abstract Class)  |
| -------------------- | ----------------------------- | ----------------------------------------- |
| Pure virtual methods | ✅ Must have at least one      | ✅ All methods are pure virtual            |
| Regular methods      | ✅ Allowed                     | ❌ Not allowed (in interface-style)        |
| Data members         | ✅ Allowed                     | ❌ Not allowed (except constants)          |
| Inheritance          | Single or multiple            | Multiple via base abstract classes        |
| Usage                | Base for real implementations | Define strict contracts for other classes |

### If your abstract class has only pure virtual functions, it's effectively** an interface.** If it has some implemented and some pure virtual, it's a** true abstract base class.**
### Usually we always call it an abstract interface coz mostly we are not providing any implementation in initial class. Only in the concrete(derived) class.

### 6. 📚 Enumeration (Enum)

An enumeration is a data type with a fixed set of named values (literals).

UML representation:

* Stereotype `<<enumeration>>` above the name
* List of literals in a compartment below

---

# 🔍 Perspectives of Class Diagrams

| Perspective           | Purpose                                                     | Diagram Style                                                                                           | Target Audience                       |
| --------------------- | ----------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | ------------------------------------- |
| **Conceptual** 🧠     | High-level view focusing on main concepts and relationships | Classes as real-world concepts; minimal attributes/operations; business associations                    | Business Analysts, Domain Experts     |
| **Specification** 📋  | Define structure and behavior without code-level details    | Abstract classes, interfaces, key public methods, inheritance, associations                             | System Architects, Software Designers |
| **Implementation** 💻 | Detailed, code-level view                                   | Full class definitions, visibility markers, data types, default values, constructors, all relationships | Developers, Software Engineers        |

---

# 🔗 Relationship Between Classes

| Relationship                     | Description                                                                 | Example                                                                   | UML Notation                                  |
| -------------------------------- | --------------------------------------------------------------------------- | ------------------------------------------------------------------------- | --------------------------------------------- |
| **Association** (USE-A)          | General relationship; one class uses or interacts with another              | Teacher teaches multiple Students (many-to-many)                          | Solid line between classes                    |
| **Aggregation** (HAS-A)          | Whole-part where parts can exist independently of the whole                 | Department has Professors; Professors exist even if Department is removed | Hollow diamond at the whole side              |
| **Composition** (Strong HAS-A)   | Strong whole-part; parts cannot exist without whole                         | House has Rooms; destroying House destroys Rooms                          | Filled diamond at the whole side              |
| **Inheritance**                  | IS-A relationship; subclass inherits from superclass                        | Dog is an Animal                                                          | Solid line with filled triangle to parent     |
| **Realization** (Implementation) | Class implements an interface contract                                      | Circle class implements Shape interface                                   | Dashed line with filled triangle to interface |
| **Dependency**                   | Temporary "uses" relationship; changes in used class affect dependent class | OrderService depends on PaymentService                                    | Dashed line with open arrow to used class     |

![image](https://github.com/user-attachments/assets/0032754a-cacc-4dfa-8a66-7ab0faa7c5b8)


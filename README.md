# 🏠 Real Estate Property Management System

### A Console-Based Property Management Application Using C

A simple, interactive, and menu-driven **Real Estate Property Management System** developed using the C programming language. This project helps users register properties, calculate property prices, view available properties, manage property sales, search property details, and generate system reports through a colorful console interface.

---

## 📌 Table of Contents

* [About the Project](#-about-the-project)
* [Project Objectives](#-project-objectives)
* [Features](#-features)
* [Technology Stack](#-technology-stack)
* [Property Price Calculation](#-property-price-calculation)
* [Project Structure](#-project-structure)
* [Installation and Setup](#-installation-and-setup)
* [How to Run](#-how-to-run)
* [Sample Output](#-sample-output)
* [Screenshots](#-screenshots)
* [System Limitations](#-system-limitations)
* [Future Enhancements](#-future-enhancements)
* [Author](#-author)
* [License](#-license)

---

## 📖 About the Project

The Real Estate Property Management System is a C-based application designed to simplify basic property management operations.

The system provides a menu-driven interface that allows users to add new properties, view available properties, mark properties as sold, search for properties using their unique IDs, and generate a summary report.

It also calculates property prices based on the property area, number of bedrooms, and location type. A 5% additional charge is included in the calculated price.

The application uses structures, arrays, functions, conditional statements, loops, and input validation to demonstrate important concepts in C programming.

**Project Type:** Console-Based Application
**Programming Language:** C
**Application Domain:** Real Estate and Property Management
**Interface:** Colorful Console User Interface

---

## 🎯 Project Objectives

* Simplify basic property registration and management.
* Calculate property prices automatically.
* Maintain property availability and sales status during a session.
* Search for registered properties using unique property IDs.
* Validate mobile numbers and location selections.
* Generate reports showing registered, available, and sold properties.
* Apply fundamental C programming concepts to a practical application.

---

## ✨ Features

### 1. 🏡 Add New Property

* Register a new property.
* Enter the owner's name and mobile number.
* Enter the property area in square feet.
* Specify the number of bedrooms.
* Select the location type.
* Calculate the final property price automatically.
* Generate a unique property ID starting from `1001`.

### 2. 📋 View All Properties

* Display properties that are currently available.
* Show property IDs, owner names, mobile numbers, and prices.
* Exclude properties already marked as sold.

### 3. 💰 Sell Property

* Search for a property using its ID.
* Mark an available property as sold.
* Prevent an already-sold property from being sold again.
* Display an error if the property ID does not exist.

### 4. ✅ View All Sold Properties

* Display properties marked as sold.
* Show their IDs, owner names, mobile numbers, and prices.
* Display a message when no properties have been sold.

### 5. 🔍 Search Property

* Search using a unique property ID.
* Display owner details and property information.
* Show the property area, number of bedrooms, and calculated price.
* Identify whether the property is available or sold.

### 6. 📊 Generate Property Report

* Display the total number of registered properties.
* Count available properties.
* Count sold properties.
* Display the next property ID.

### 7. 🧮 Automatic Price Calculation

* Calculate the base property price using the location type and area.
* Add a charge based on the number of bedrooms.
* Apply an additional 5% charge.

### 8. 🎨 Colorful Console Interface

* Display a formatted application header.
* Use bordered menus and information panels.
* Apply different colors to messages and results.
* Support Windows console colors and ANSI colors on other supported platforms.

### 9. 🛡️ Input Validation

* Validate mobile numbers as 10-digit numeric values.
* Validate location selections.
* Reject invalid menu choices.
* Check whether the property ID exists before updating or searching for a property.

---

## 🛠️ Technology Stack

| Technology          | Purpose                                           |
| ------------------- | ------------------------------------------------- |
| C Programming       | Application development                           |
| GCC Compiler        | Compiling the C source code                       |
| Code::Blocks        | Development environment                           |
| Standard C Library  | Input, output, string handling, and formatting    |
| Windows Console API | Console text colors on Windows                    |
| ANSI Escape Codes   | Console colors on supported non-Windows terminals |

---

## 🧮 Property Price Calculation

The application calculates property prices using the following formula.

**Step 1: Determine the price per square foot**

| Location Type | Price per Sq. Ft. |
| ------------- | ----------------: |
| City          |            ₹8,000 |
| Suburb        |            ₹5,000 |
| Village       |            ₹2,500 |

**Step 2: Calculate the base price**

`Base Price = (Area × Price per Sq. Ft.) + (Bedrooms × ₹200,000)`

**Step 3: Add the additional 5% charge**

`Final Price = Base Price + (Base Price × 5%)`

### Example Calculation

Suppose a property has the following details:

* Area: 1,000 sq. ft.
* Bedrooms: 2
* Location: City
* Price per sq. ft.: ₹8,000

Base price:

`(1,000 × 8,000) + (2 × 200,000)`

`= ₹8,400,000`

Additional 5% charge:

`₹8,400,000 × 5% = ₹420,000`

**Final Property Price = ₹8,820,000**

*Note: This is the application's programmed pricing formula for demonstration purposes, not an estimate of actual market value.*

---

## 📂 Project Structure

```text
REAL-ESTATE-PROPERTY-MANAGEMENT-SYSTEM/
│
├── Real Estate Property Management system/
│   └── [C source code]
│
├── Screenshot/
│   ├── main_menu.png
│   ├── add_property.png
│   ├── property_list.png
│   ├── sold_properties.png
│   ├── search_property.png
│   └── system_report.png
│
└── README.md
```

**Note:** The screenshot filenames above are suggested names. Rename your actual screenshot files to match them, or update the Markdown image paths to match the filenames already in your repository. The C source code location shown above is a folder-level guide; use the actual `.c` filename present in your repository.

---

## ⚙️ Installation and Setup

### Prerequisites

Install one of the following development environments:

* [Code::Blocks](https://www.codeblocks.org/downloads/)
* [GCC Compiler](https://gcc.gnu.org/)

On Windows, make sure GCC is installed and available through your terminal if you want to compile the program using the command line.

### Step 1: Clone the Repository

Open Command Prompt, PowerShell, or the VS Code terminal.

```bash
git clone https://github.com/saravananbass12-tech/REAL-ESTATE-PROPERTY-MANAGEMENT-SYSTEM.git
```

### Step 2: Navigate to the Project Folder

```bash
cd REAL-ESTATE-PROPERTY-MANAGEMENT-SYSTEM
```

Open the repository and locate the C source file inside the project folder.

### Step 3: Compile the C Program

Replace `main.c` with the actual name of your C source file.

Using GCC:

```bash
gcc main.c -o real_estate
```

### Step 4: Run the Application

**Windows:**

```bash
real_estate.exe
```

**Linux/macOS:**

```bash
./real_estate
```

The application will display the main menu. Enter a menu option to perform the required operation.

### Alternative: Run Using Code::Blocks

1. Open Code::Blocks.
2. Open the existing project or create a C console project.
3. Add or open the project's C source file.
4. Build the program using **Build → Build and Run**.
5. Enter your choice in the console.
6. Follow the displayed instructions.

---

## 💻 How to Use the Application

After launching the program, select one of the following menu options.

| Option | Operation                |
| -----: | ------------------------ |
|      1 | Add New Property         |
|      2 | View All Properties      |
|      3 | Sell Property            |
|      4 | View All Sold Properties |
|      5 | Search Property          |
|      6 | Exit                     |
|      7 | Generate Property Report |

### Example Workflow

1. Select `1` to register a property.
2. Enter the owner's details.
3. Enter the area and number of bedrooms.
4. Select the location type.
5. View the generated property ID and final price.
6. Select `2` to view available properties.
7. Select `5` to search for a property.
8. Select `3` to mark a property as sold.
9. Select `4` to view sold properties.
10. Select `7` to generate the system report.
11. Select `6` to exit the application.

---

## 🖥️ Sample Output

The following is an illustrative example of the console output. Actual spacing and colors may vary by terminal.

### 1. Main Menu

```text
+-----------------------------------------------------------------+
|              REAL ESTATE PROPERTY MANAGEMENT SYSTEM             |
|                 --------------------- o000 ---------------------|
+-----------------------------------------------------------------+

+------------------------------ MAIN MENU -------------------------+
|                                                                 |
|   1. Add New Property                                            |
|   2. View All Properties                                         |
|   3. Sell Property                                               |
|   4. View All Sold Properties                                    |
|   5. Search Property                                             |
|   6. Exit                                                        |
|   7. Generate Property Report                                    |
|                                                                 |
+-----------------------------------------------------------------+

 -> Enter your choice:
```

### 2. Add New Property

```text
+------------------------- ADD NEW PROPERTY -----------------------+

  Enter Owner Name     : Arun Kumar
  Enter Mobile Number  : 9876543210
  Enter Area (sq.ft)   : 1000
  Enter Bedrooms       : 2
  Enter Location (1=City, 2=Suburb, 3=Village) : 1

+-----------------------------------------------------------------+
| [OK] Property added successfully!                               |
| Property ID : 1001                                              |
| Mobile No   : 9876543210                                        |
| Total Price : Rs. 8820000.00                                    |
+-----------------------------------------------------------------+
```

### 3. View Properties

```text
+--------------------------- PROPERTY LIST ------------------------+
| ID:1001 | Arun Kumar   | 9876543210 | Rs. 8820000.00            |
+-----------------------------------------------------------------+
```

### 4. Sell Property

```text
+--------------------------- SELL PROPERTY ------------------------+

  Enter Property ID to Sell: 1001

| [OK] Success! Property ID 1001 marked as SOLD.                  |
```

### 5. Generate Property Report

```text
+--------------------------- SYSTEM REPORT ------------------------+
| Total Properties Registered : 1                                 |
| Available Properties        : 0                                 |
| Sold Properties             : 1                                 |
| Next Available ID           : 1002                              |
+-----------------------------------------------------------------+
```

### 6. Exit Summary

```text
+------------------------ SYSTEM EXIT SUMMARY ---------------------+
| Last Added ID : 1001                                            |
| Owner Name    : Arun Kumar                                       |
| Mobile Number : 9876543210                                      |
| Total Price   : Rs. 8820000.00                                  |
+-----------------------------------------------------------------+

~~~~~~~~~~~~~ Thank You for Using Real Estate System! ~~~~~~~~~~~~~
```

---

## 📸 Screenshots

Screenshots help users understand the application before downloading or running the source code.

Add your actual console screenshots to the `Screenshot` folder in your repository.

### 1. Main Menu

![Real Estate Property Management System Main Menu](Screenshot/main_menu.png)

### 2. Add New Property

![Add New Property](Screenshot/add_property.png)

### 3. Property List

![Available Property List](Screenshot/property_list.png)

### 4. Sold Properties

![Sold Properties](Screenshot/sold_properties.png)

### 5. Search Property

![Search Property](Screenshot/search_property.png)

### 6. System Report

![Property Management System Report](Screenshot/system_report.png)

**Important:** The image links will work only after the corresponding image files have been uploaded to the `Screenshot` folder. Use the exact filenames and capitalization from your repository.

---

## ⚠️ System Limitations

* The application stores property records in an in-memory array.
* Property information is not saved to a database or file.
* All registered property information is lost when the program terminates.
* The system supports up to 100 properties per session.
* Property pricing uses a predefined formula rather than real-time market data.
* The application is a console-based demonstration, not a complete web-based real estate platform.

---

## 🚀 Future Enhancements

The following features could be added in future versions:

* Integrate a MySQL or SQLite database.
* Save property records permanently using file handling.
* Add property update and deletion features.
* Introduce owner and administrator login functionality.
* Add advanced property search by location, price, and area.
* Generate downloadable property reports.
* Add property images and detailed descriptions.
* Develop a graphical user interface or web application.
* Add transaction history and sales reports.

---

## 👨‍💻 Author

**Saravanan D**

BCA Graduate | Aspiring Software Developer

**GitHub:** [saravananbass12-tech](https://github.com/saravananbass12-tech)

**Project Repository:** [Real Estate Property Management System](https://github.com/saravananbass12-tech/REAL-ESTATE-PROPERTY-MANAGEMENT-SYSTEM)

---

## 📄 License

This project is intended for educational purposes, programming practice, and portfolio demonstration.

If you plan to distribute the project, consider adding a `LICENSE` file that clearly defines the terms of use.

---

⭐ If you find this project useful, consider giving the repository a star!

**Thank you for visiting the Real Estate Property Management System project.**
# REAL-ESTATE-PROPERTY-MANAGEMENT-SYSTEM

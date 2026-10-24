# Car-Parking-Management-System-in-C++

# 🚗 Car Parking Management System

A console-based **Car Parking Management System** developed in **C++** using Object-Oriented Programming (OOP) concepts.

The system manages vehicle arrivals and departures, parking slots, parking tickets, billing, and parking-space information. It also saves vehicle and ticket information to text files using C++ file handling.

## 🔐 Login

The program has a simple password-based login system.

### Password

```text
0000
```

After entering the correct password, the main parking management menu is displayed.

> **Note:** This is a basic educational project. The password is not encrypted or securely stored.

## 🚘 Features

- 🔐 Password-protected login
- 🚗 Car arrival management
- 🎫 Parking ticket generation
- 🅿️ Automatic parking-slot assignment
- 🚙 Car departure management
- 🧾 Parking bill generation
- 💰 Automatic parking-charge calculation
- 📊 Parking lot information
- 🟢 Display empty parking spaces
- 🔴 Display occupied parking spaces
- 📁 File handling using `fstream`
- ⏰ Entry and exit time tracking
- 📈 Total parking count

The parking lot is configured with a capacity of **125 vehicles**.

## 🛠️ Technologies Used

- **C++**
- **Object-Oriented Programming (OOP)**
- `iostream`
- `cstring`
- `ctime`
- `vector`
- `fstream`

The project uses C++ `fstream` for saving information to text files.

## 📋 Main Menu

After successful login, the program provides the following options:

```text
1. Arrival of a Car
2. Departure of a Car
3. Display Details
4. Exit Program
```



## 🚗 Car Arrival

When a vehicle arrives, the program:

1. Checks whether a parking space is available.
2. Assigns the next available parking slot.
3. Collects the owner's information.
4. Collects vehicle information.
5. Generates a parking ticket.
6. Records the vehicle entry time.
7. Saves information to text files.

The parking system automatically searches for a free slot and marks it as occupied.

## 🎫 Parking Ticket

The parking ticket contains information such as:

- Owner name
- Car number
- Car model
- Car type
- Ticket number
- Entry time
- Parking spot
- Current payment status

The initial ticket status is:

```text
UNPAID
```



## 🚙 Car Departure

To process a vehicle departure, the user enters the vehicle's ticket number.

The program then:

1. Finds the vehicle.
2. Frees its parking slot.
3. Records the exit time.
4. Calculates the parking charges.
5. Generates a paid parking bill.



## 💰 Parking Charges

The system calculates charges according to the parking duration.

Current charging logic:

| Parking Duration | Charge |
|---|---:|
| Up to 30 minutes | Rs. 30 |
| Up to 2 hours | Rs. 55 |
| Up to 7 hours | Rs. 55 + Rs. 10/hour after 2 hours |
| More than 7 hours | Rs. 165 |

The charge calculation is implemented in the `calculateCharges()` function.

## 📊 Parking Details

The **Display Details** section provides:

1. Total parking capacity
2. Number of occupied parking spaces
3. Number of empty parking spaces
4. List of empty parking spaces
5. List of occupied parking spaces
6. Total number of parkings
7. Exit



## 📁 File Handling

The project uses C++ file handling to save parking information into `.txt` files.

The program currently creates/uses files such as:

```text
Personinfo.txt
Carinfo.txt
unpaidticket.txt
paidticket.txt
```

The source code uses `ofstream` to write information to these files.

### ⚠️ Important: Change the File Path

Before running the program on another computer, you **must change the hard-coded file paths**.

The current source contains paths similar to:

```cpp
E:\Superior\2 semster\OOP\Theory\Project\Personinfo.txt
```

and:

```cpp
E:\Superior\2 semster\OOP\Theory\Project\Carinfo.txt
```

The project also uses paths for:

```text
unpaidticket.txt
paidticket.txt
```

These paths are specific to the original developer's computer and will not automatically work on another computer. 

### How to Change the Path

Search the source code for:

```cpp
E:\\Superior\\2 semster\\OOP\\Theory\\Project\\
```

Replace it with the path where you want the files to be saved.

For example:

```cpp
ofstream file;
file.open("C:\\Users\\YourName\\Desktop\\CarParking\\Personinfo.txt");
```

Or:

```cpp
ofstream file;
file.open("C:\\CarParking\\Personinfo.txt");
```

Do the same for:

```text
Personinfo.txt
Carinfo.txt
unpaidticket.txt
paidticket.txt
```

### Recommended Approach

For easier portability, create a folder for the output files:

```text
CarParking/
│
├── main.cpp
│
└── data/
    ├── Personinfo.txt
    ├── Carinfo.txt
    ├── unpaidticket.txt
    └── paidticket.txt
```

Then update the paths in the source code to point to the `data` folder.

## ▶️ How to Run

### 1. Download/Clone the Project

Clone the repository or download the source code.

### 2. Open the Project

Open the `.cpp` file in a C++ IDE such as:

- Code::Blocks
- Dev-C++
- Visual Studio
- Visual Studio Code with a C++ compiler

### 3. Change File Paths

Before compiling, update the hard-coded file paths as explained in the **File Handling** section.

### 4. Compile

Compile the C++ source code using a C++ compiler.

Example:

```bash
g++ main.cpp -o CarParking
```

### 5. Run

On Windows:

```bash
CarParking.exe
```

### 6. Login

When prompted for the password, enter:

```text
0000
```

## 🗂️ Project Structure

A basic project structure can be:

```text
Car-Parking-Management-System/
│
├── main.cpp
├── README.md
│
└── data/
    ├── Personinfo.txt
    ├── Carinfo.txt
    ├── unpaidticket.txt
    └── paidticket.txt
```

## 🧱 OOP Concepts Used

The project demonstrates several Object-Oriented Programming concepts.

### Classes

The project contains classes including:

```cpp
class Customer
class Vehicle
class ParkingLot
```

### Inheritance

`Vehicle` inherits from `Customer`:

```cpp
class Vehicle : public Customer
```

This allows the vehicle object to access customer information such as the owner's name and phone number. 

### Encapsulation

Class data members are kept private and accessed through public functions such as:

```cpp
getName()
getPhone()
getCar()
getColor()
getModel()
getTypes()
getTicketNo()
getSlot()
```

### Vector

The project uses:

```cpp
vector<bool>
vector<Vehicle>
```

to manage parking spaces and vehicles.

### Inheritance

The `Vehicle` class extends the functionality of the `Customer` class.

### File Handling

The program uses:

```cpp
ofstream
```

to write parking and vehicle information to text files.

## ⚠️ Important Notes

1. The login password is currently hard-coded as `0000`.
2. The password is not encrypted.
3. File locations are hard-coded and must be changed before running the project on another computer.
4. The application is designed primarily as an educational OOP project.
5. Make sure the destination folder exists before running the program.
6. The project currently uses Windows-style file paths.
7. The parking capacity is set to 125 vehicles.

## 🔮 Possible Improvements

Future versions could include:

- Secure password handling
- Database integration
- GUI interface
- Dynamic file paths
- Automatic directory creation
- Search functionality
- Vehicle history
- Admin/user accounts
- Better error handling
- Multiple parking rates
- Receipt printing
- Persistent parking data
- Cross-platform path handling

## 📄 License

This project is intended for educational and learning purposes. You may modify and extend it for your own projects.

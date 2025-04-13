============================================================
         AIRLINE RESERVATION MANAGEMENT SYSTEM
============================================================

📌 DESCRIPTION:
------------------------------------------------------------
This is a simple yet fully functional **Airline Reservation System** developed in the **C programming language**. It allows users to book, cancel, modify, and view flight tickets, check seat availability, and store all data persistently using file handling.

The program uses a structured approach with `struct Passenger`, and file I/O operations to retain user data even after the program exits. All user input is done via console interaction (without graphical UI or CLI libraries).

------------------------------------------------------------
📁 PROJECT STRUCTURE:
------------------------------------------------------------
1. airline_reservation.c      --> Main C source code
2. reservations.txt           --> Data file for storing bookings
3. README.txt                 --> This readme file

The file `reservations.txt` is automatically created (if not already present) and contains details of all bookings made during the program usage.

------------------------------------------------------------
💡 FEATURES:
------------------------------------------------------------
✅ Book a Flight Ticket  
✅ Cancel an Existing Booking  
✅ Modify Passenger Details  
✅ Display Ticket by PNR  
✅ Check Seat Availability  
✅ Show All Bookings  
✅ Persistent Data Storage (via File Handling)  

Each reservation is assigned a unique PNR number and contains:
- Passenger Name
- Age
- Gender
- Source & Destination
- Seat Number

------------------------------------------------------------
🧪 SAMPLE OUTPUT:
------------------------------------------------------------
====== Airline Reservation Management System ======
1. Book Ticket
2. Display Ticket
3. Cancel Ticket
4. Modify Ticket
5. Show All Bookings
6. Check Seat Availability
7. Exit
Enter your choice: 1

Enter Name: Aditya Sajwan
Enter Age: 19
Enter Gender (M/F): M
Enter Source: Delhi
Enter Destination: Mumbai
Enter Seat No (1-50): 12

Ticket Booked Successfully!
Your PNR: PNR0421

...

------------------------------------------------------------
⚙️ HOW TO COMPILE AND RUN:
------------------------------------------------------------
🔸 **Using GCC:**

1. Open terminal/command prompt.
2. Navigate to project folder.
3. Compile:
4. Run:

✅ Windows Users: You can use Code::Blocks or Dev C++ as well.

------------------------------------------------------------
📁 FILE FORMAT - reservations.txt:
------------------------------------------------------------
Each line in `reservations.txt` represents a booking:
Format:

Example:

------------------------------------------------------------
🔒 LIMITATIONS & SCOPE FOR IMPROVEMENT:
------------------------------------------------------------
❌ No graphical interface (pure console-based)  
❌ No Admin/User login system  
❌ No real-time flight timings, pricing, or availability

🛠️ FUTURE ENHANCEMENTS:
- Add flight schedule system
- Add fare and pricing model
- Add date and time selection
- Admin/User access roles
- Linked list-based dynamic booking

------------------------------------------------------------
👨‍💻 DEVELOPED BY:
------------------------------------------------------------
👤 Name: Aditya Sajwan  
🎓 Role: Student / Freelance Developer  
🛠️ Skills: C, Python, Frontend Development, Video Editing , Graphics Designing
📧 Email : adityasajwan18@gmail.com

For queries, collaborations, or project enhancements, feel free to reach out!

------------------------------------------------------------
📌 DISCLAIMER:
------------------------------------------------------------
This project is for educational and academic purposes only.  
All data used here is static and not connected to any real airline API or system.

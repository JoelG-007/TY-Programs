# Advanced Java Programming — TYBSc CS Sem VI
**Course:** CSMJ363 | **College:** Nowrosjee Wadia College, Pune

---

## Structure

```
AdvJava/
├── Assignment1/        Collections Framework
│   ├── SetA/
│   │   ├── ArrayListDemo.java       Q1 - ArrayList with iterator, insert, remove, search
│   │   ├── SetDemo.java             Q2 - HashSet and TreeSet with foreach and iterator
│   │   ├── MapDemo.java             Q3 - HashMap with Map.Entry iterator and for-each
│   │   ├── StackDemo.java           Q4 - Stack push and pop operations
│   │   ├── RemoveDuplicates.java    Q5 - Remove duplicates using HashSet
│   │   └── SortNumbers.java         Q6 - Sort numbers (duplicates allowed) using ArrayList
│   ├── SetB/
│   │   ├── ListIteratorOps.java     Q1 - Iterator ops, count <=20 />20, remove, max/min
│   │   ├── EmployeeSort.java        Q2 - Employee TreeSet sorted by name (Comparable)
│   │   ├── EmployeeMapSort.java     Q3 - Employee IDs/names in TreeMap sorted by ID
│   │   └── CollectionsMenu.java     Q4 - Menu-driven Collections program
│   └── SetC/
│       └── CharFrequency.java       Q1 - Character frequency using HashMap
│
├── Assignment2/        Multithreading
│   ├── SetA/
│   │   ├── NumberThread.java        Q1 - Thread extending Thread class, prints 1-10
│   │   ├── RunnableThread.java      Q2 - Thread using Runnable, prints message n times
│   │   ├── EvenOddRunnable.java     Q3 - Two Runnable threads, even and odd 1-20
│   │   └── SleepDemo.java           Q4 - Thread.sleep demo, main and child concurrent
│   ├── SetB/
│   │   ├── YieldDemo.java           Q1 - Thread.yield demo
│   │   ├── PriorityDemo.java        Q2 - Thread priority and sleep
│   │   ├── ProducerConsumer.java    Q3 - Producer-Consumer using wait/notify
│   │   └── TicketBooking.java       Q4 - Synchronized ticket booking system
│   └── SetC/
│       ├── BankAccountSync.java     Q1 - Bank account with synchronized deposit/withdraw
│       └── PrintPoolDemo.java       Q2 - Office print system using fixed thread pool (3)
│
├── Assignment3/        JDBC (PostgreSQL)
│   ├── SetA/
│   │   ├── DBConnection.java        Q1 - Connect to DB, display success message
│   │   ├── CreateInsert.java        Q2 - Create student table and insert records
│   │   └── DisplayRecords.java      Q3 - Display all student records using ResultSet
│   └── SetB/
│       ├── PreparedInsert.java      Q4 - PreparedStatement insert with user input
│       ├── DBMetaData.java          Q5 - DatabaseMetaData info display
│       └── StudentCRUD.java         Q6 - Menu-driven Insert/Display/Search/Update/Delete
│
└── Assignment4/        Servlet & JSP
    ├── SetA/
    │   ├── HelloServlet.java        Q1 - Simple servlet printing "Welcome to Java Servlet"
    │   ├── hello.jsp                Q2 - JSP with scriptlet and expression tag
    │   ├── GreetServlet.java        Q3 - Servlet reading name from URL parameter
    │   └── index.html               Form for GreetServlet
    ├── SetB/
    │   ├── form.html                HTML form for UserInfoServlet
    │   ├── UserInfoServlet.java     Q1 - Accept name/age via GET, display it
    │   ├── sum.jsp                  Q2 - JSP sum calculator using scripting elements
    │   ├── DispatchServlet.java     Q3 - RequestDispatcher forward demo
    │   ├── TargetServlet.java       Q3 - Target of forwarded request
    │   ├── CookieServlet.java       Q4 - Create and read cookies
    │   └── LifeCycleServlet.java    Servlet lifecycle (init, service, destroy)
    └── SetC/
        ├── login.html               Login form
        ├── LoginServlet.java        Q1 - Session tracking login
        ├── WelcomeServlet.java      Q1 - Session tracking welcome page
        ├── LogoutServlet.java       Q1 - Session invalidate logout
        ├── addStudent.html          Add student form
        ├── StudentServlet.java      Q2 - Student CRUD with JDBC via Servlet
        └── register.jsp             Q3 - Student registration using JSP + JDBC

```

## Notes
- All JDBC programs use **PostgreSQL** (`jdbc:postgresql://192.168.0.102:5432/tycsdb52`)
- Assignment 4 requires **Apache Tomcat** and the `javax.servlet` API JAR
- Compile with `javac` (Java 8+), run with `java`

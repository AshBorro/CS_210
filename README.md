# CS_210
Summarize the project and what problem it was solving.
This project is a C++ application designed to help a grocery store analyze how often items are purchased. The program reads item names from an input file, tracks how frequently each item appears, and allows the user to view the data through a simple menu interface. The output can be displayed as a full frequency list, a single item lookup, or a histogram. The program also writes the results to a backup file (frequency.dat) for record-keeping.

What did you do particularly well?
One of my strengths in this project was organizing the program using a dedicated ItemTracker class. Storing item frequencies in a map<string, int> made the data easy to manage and efficient to search. I also separated responsibilities into clear functions, such as loading items from a file, printing frequencies, searching for an item, displaying a histogram, and writing output to a file. This structure made the program easier to read, test, and maintain.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
There are a few areas where the code could be improved. I could add stronger input validation to better handle unexpected user input at the menu. Another improvement would be allowing the user to specify the input file name instead of hardcoding it. I could also add error handling for cases like empty input files or invalid item searches. These improvements would make the program more secure, flexible, and user-friendly.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging part of this project was working with file input/output and making sure item frequencies were counted correctly. I overcame this by testing the program in small steps and verifying the contents of the map as data was read in. Using console output to debug and reviewing C++ file handling documentation helped me understand where issues were occurring and how to fix them.
Tools and resources I relied on include:
-C++ documentation (map, file streams)
-Incremental testing and debugging
-Course examples and project guidelines

What skills from this project will be particularly transferable to other projects or course work?
This project helped me build skills that are transferable to many other programming projects, including:
-File input and output handling
-Using data structures like maps for efficient data storage
-Object-oriented programming and class design
-Writing modular, well-structured code
-Debugging and validating program logic
These skills are directly applicable to future coursework and real-world software development tasks.

How did you make this program maintainable, readable, and adaptable?
I focused on maintainability by using clear function names, meaningful variable names, and consistent formatting throughout the code. Breaking the logic into separate methods inside the ItemTracker class makes the program easier to update or extend in the future. For example, additional menu options or new output formats could be added without rewriting the entire program.

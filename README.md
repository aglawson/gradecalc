# gradecalc
To Calculate Class Grade

User is presented with menu containing various options
Menu has letters that correspond to program capbilities
ex. A: Add Assignment

Program uses a vector of structs to store data for each assignment

addAssignment function takes in assignment name, overall weight, and percentage earned and stores that information into the struct, then the struct is added to the vector

calcGrade function calculates the total amount of points earned in the course by adding up each assignment's grade. returns total grade.

printGrades function prints out information for each assignment and calculates and prints overall class grade

whatif function calculates what the student needs to earn on the final exam in order to earn their desired overall course grade. Also lets the student know if that overall grade is out of reach.

deleteLastAssignment function removes the last member of the vector.

future work: add a deleteCustomAssignment function to remove any assignment in the vector the user desires

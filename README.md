# OSSL_mini_project

## Subject : Basketball Team Management Program

## Owner : Junsang Yoo

---
* **Overview**
This program is a menu driven interface.  
This is how the menu looks like:  
>    1. Add new player
>    2. List out players information
>    3. Update player detail
>    4. Delete player
>    5. Search
>    6. Load a new data file
>    7. Add records from an outside data file
>    8. Save to a data file
>    9. Make a report file
>    10. Optimize the records
>    11. Sort
    
* **Functions**  
The functions consists mainly of CRUD type functions.  
These basic functions are written in base.c  
The extra credit functions are defragmentation and sorting function.  
These extra functions are written in extras.c  

* **About the records**
The datas are saved in a single array that cam hold up to 1000 records which is made in the main function. 
There are 7 members in the record:  
1. name (The player's name)
2. number (The back number of the player)
3. pos (The position of the player)
4. points (The total points)
5. assists (The total assists)
6. games (The total games played)
7. empty (This is explained in the paragraph below)  

* **The member 'empty'**  
I used a integer member called 'empty' to distinguish different types of records. 
When empty is 0, it means the record element in the array is not used. 
When empty is 1, it means the record element in the array is being used. 
When empty is 2, it means the record element in the array has been deleted. 
The deleted record element is left in the middle of the other data that are used. 
Defragement is needed for normal output options to be done smoothly. 
I could have done the defragmentation while executing the other functions,
but I thought it is better this way to show the effect of defragmentation for the project rubric.

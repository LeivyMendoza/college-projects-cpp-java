/*--------------------------------------------------------------------

 Name:  Leivy Mendoza

 Student ID: 1001100556

 COP 2800 - Java Programming 

 Spring 2018 - T Th 6:15PM - 9:30PM

 Project # 1

 Plagiarism Statement

 I certify that this assignment is my own work and that I
 have not copied in part or whole or otherwise plagiarized 
 the work of other students and/or persons.

1234567890123456789012345678901234567890123456789012345678901234567890
--------------------------------------------------------------------*/

package calorietracker;

import java.util.Scanner;

public class CalorieTracker {

    public static void main(String[] args) {
        final int NUMBEROFDAYS = 7;
        final int NUMBEROFMEALS = 4;
        int[][] calorieTrackerArray = new int[NUMBEROFDAYS][NUMBEROFMEALS];

        userInput(calorieTrackerArray, NUMBEROFDAYS, NUMBEROFMEALS);
        System.out.println();
        System.out.println("CalorieTracker Report");
        System.out.println("---------------------");
        totalCalorie(calorieTrackerArray, NUMBEROFDAYS, NUMBEROFMEALS);
        averageCalorie(calorieTrackerArray, NUMBEROFDAYS, NUMBEROFMEALS);
        lowCalorieMeal(calorieTrackerArray, NUMBEROFDAYS, NUMBEROFMEALS);
        highCalorieMeal(calorieTrackerArray, NUMBEROFDAYS, NUMBEROFMEALS);
    }

    public static void userInput(int array[][], int row, int col) {
        Scanner input = new Scanner(System.in);

        for (int rowCount = 0; rowCount < row; rowCount++) {
            switch (rowCount) {
                case 0:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Monday");
                    break;
                case 1:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Tuesday");
                    break;
                case 2:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Wednesday");
                    break;
                case 3:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Thursday");
                    break;
                case 4:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Friday");
                    break;
                case 5:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Saturday");
                    break;
                case 6:
                    System.out.print("Please enter your ");
                    System.out.println("calorie intake for Sunday");
                    break;
            }
            for (int colCount = 0; colCount < col; colCount++) {
                switch (colCount) {
                    case 0:
                        System.out.print("Breakfast: ");
                        break;
                    case 1:
                        System.out.print("Lunch: ");
                        break;
                    case 2:
                        System.out.print("Snack: ");
                        break;
                    case 3:
                        System.out.print("Dinner: ");
                        break;
                }
                array[rowCount][colCount] = input.nextInt();
                while (array[rowCount][colCount] < 0) {
                    System.out.println("Please enter a positive value");
                    switch (colCount) {
                        case 0:
                            System.out.print("Breakfast: ");
                            break;
                        case 1:
                            System.out.print("Lunch: ");
                            break;
                        case 2:
                            System.out.print("Snack: ");
                            break;
                        case 3:
                            System.out.print("Dinner: ");
                            break;
                    }
                    array[rowCount][colCount] = input.nextInt();
                }
            }
        }
    }

    public static void totalCalorie(final int array[][], int row, int col) {
        for (int rowCount = 0; rowCount < row; rowCount++) {
            int total = 0;
            switch (rowCount) {
                case 0:
                    System.out.print("Total calories for Monday is ");
                    break;
                case 1:
                    System.out.print("Total calories for Tuesday is ");
                    break;
                case 2:
                    System.out.print("Total calories for Wednesday is ");
                    break;
                case 3:
                    System.out.print("Total calories for Thursday is ");
                    break;
                case 4:
                    System.out.print("Total calories for Friday is ");
                    break;
                case 5:
                    System.out.print("Total calories for Saturday is ");
                    break;
                case 6:
                    System.out.print("Total calories for Sunday is ");
                    break;
            }
            for (int colCount = 0; colCount < col; colCount++) {
                total += array[rowCount][colCount];
            }
            System.out.println(total);
        }
    }

    public static void averageCalorie(final int array[][], int row, int col) {
        int total = 0;
        int average = 0;
        System.out.print("The average daily consumption for this week is ");
        for (int rowCount = 0; rowCount < row; rowCount++) {
            for (int colCount = 0; colCount < col; colCount++) {
                total += array[rowCount][colCount];
            }
        }
        average = total / row;
        System.out.println(average);
    }

    public static void lowCalorieMeal(final int array[][], int row, int col) {
        int lowest = array[0][0];
        int day = 0;
        int meal = 0;
        for (int rowCount = 0; rowCount < row; rowCount++) {
            for (int colCount = 0; colCount < col; colCount++) {
                if (array[rowCount][colCount] < lowest) {
                    lowest = array[rowCount][colCount];
                    day = rowCount;
                    meal = colCount;
                }
            }
        }
        System.out.print("The meal with the lowest calorie this week was on ");

        switch (day) {
            case 0:
                System.out.print("Monday's ");
                break;
            case 1:
                System.out.print("Tuesday's ");
                break;
            case 2:
                System.out.print("Wednesday's ");
                break;
            case 3:
                System.out.print("Thursday's ");
                break;
            case 4:
                System.out.print("Friday's ");
                break;
            case 5:
                System.out.print("Saturday's ");
                break;
            case 6:
                System.out.print("Sunday's ");
                break;
        }

        switch (meal) {
            case 0:
                System.out.print("breakfast ");
                break;
            case 1:
                System.out.print("lunch ");
                break;
            case 2:
                System.out.print("snack ");
                break;
            case 3:
                System.out.print("dinner ");
                break;
        }
        System.out.print("which was ");
        System.out.print(lowest);
        System.out.println(" calories.");
    }

    public static void highCalorieMeal(final int array[][], int row, int col) {
        int highest = 0;
        int day = 0;
        int meal = 0;
        for (int rowCount = 0; rowCount < row; rowCount++) {
            for (int colCount = 0; colCount < col; colCount++) {
                if (array[rowCount][colCount] > highest) {
                    highest = array[rowCount][colCount];
                    day = rowCount;
                    meal = colCount;
                }
            }
        }
        System.out.print("The meal with the highest calorie this week was on ");

        switch (day) {
            case 0:
                System.out.print("Monday's ");
                break;
            case 1:
                System.out.print("Tuesday's ");
                break;
            case 2:
                System.out.print("Wednesday's ");
                break;
            case 3:
                System.out.print("Thursday's ");
                break;
            case 4:
                System.out.print("Friday's ");
                break;
            case 5:
                System.out.print("Saturday's ");
                break;
            case 6:
                System.out.print("Sunday's ");
                break;
        }

        switch (meal) {
            case 0:
                System.out.print("breakfast ");
                break;
            case 1:
                System.out.print("lunch ");
                break;
            case 2:
                System.out.print("snack ");
                break;
            case 3:
                System.out.print("dinner ");
                break;
        }
        System.out.print("which was ");
        System.out.print(highest);
        System.out.println(" calories.");
    }
}

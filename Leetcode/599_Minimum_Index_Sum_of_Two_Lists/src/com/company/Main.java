package com.company;

public class Main {

    public static void main(String[] args) {
	    Solution solution = new Solution();

	    String[] str1 = {"Shogun","Tapioca Express", "KFC", "Burger King"};
	    String[] str2 = {"KFC","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

	    String[] str3 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	    String[] str4 = {"KFC","Burger King","Tapioca Express","Shogun"};

        for (String item:
                solution.findRestaurant(str1, str2)) {
            System.out.print(item + " ");
        }

        for (String item:
                solution.findRestaurant(str3, str4)) {
            System.out.print(item + " ");
        }

        System.out.println("\nUse findRestaurant2 func: ");
        for (String item:
                solution.findRestaurant2(str1, str2)) {
            System.out.print(item + " ");
        }

        for (String item:
                solution.findRestaurant2(str3, str4)) {
            System.out.print(item + " " + "\n");
        }
    }
}

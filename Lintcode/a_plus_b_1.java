

public class a_plus_b_1 {
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b
     */
    public int aplusb(int a, int b) {
        while (b != 0) {
            int sum_val = a ^ b;
            int carry = (a & b) << 1;
            a = sum_val;
            b = carry;
        }
        return a;
    }

    public static void main(String[] args) {
        a_plus_b_1 test = new a_plus_b_1();
        System.out.print(test.aplusb(Integer.parseInt(args[0]),Integer.parseInt(args[1])));
    }
}